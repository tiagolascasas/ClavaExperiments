"use strict";

laraImport("weaver.Query");
laraImport("clava.ClavaJoinPoints");
laraImport("clava.ClavaType");

class Outliner {
    static #GLOBAL_OUTLINE_FUN_ID = 1;
    static #GLOBAL_OUTLINE_VAR_ID = 1;
    #verbose;

    constructor() {
        this.#verbose = true;
    }

    setVerbosity(verbose) {
        this.#verbose = verbose;
    }

    outline(begin, end) {
        return this.outlineWithName(begin, end, this.#generateFunctionName())
    }

    outlineWithName(begin, end, functionName) {
        this.#printMsg("Attempting to outline a region into a function named \"" + functionName + "\"");

        //------------------------------------------------------------------------------
        if (!this.checkOutline(begin, end)) {
            this.#printMsg("Provided code region is not outlinable! Aborting...");
            return;
        }
        this.#printMsg("Provided code region is outlinable");

        //------------------------------------------------------------------------------
        const wrappers = this.#wrapBeginAndEnd(begin, end);
        begin = wrappers[0];
        end = wrappers[1];
        this.#printMsg("Wrapped outline region with begin and ending comments");

        //------------------------------------------------------------------------------
        const parentFun = this.#findParentFunction(begin);
        const split = this.#splitRegions(parentFun, begin, end);

        let region = split[1];
        const prologue = split[0];
        const epilogue = split[2];
        this.#printMsg("Found " + region.length + " statements for the outline region");
        this.#printMsg("Prologue has " + prologue.length + " statements, and epilogue has " + epilogue.length);

        //------------------------------------------------------------------------------
        const globals = this.#findGlobalVars();
        this.#printMsg("Found " + globals.length + " global variable(s)");

        //------------------------------------------------------------------------------
        const callPlaceholder = ClavaJoinPoints.stmtLiteral("//placeholder for the call to " + functionName);
        begin.insertBefore(callPlaceholder);
        this.#printMsg("Created a placeholder call to the new function");

        //------------------------------------------------------------------------------
        const declareBefore = this.#findDeclsWithDependency(region, epilogue);
        region = region.filter((stmt) => !declareBefore.includes(stmt));
        for (var i = declareBefore.length - 1; i >= 0; i--) {
            const decl = declareBefore[i];
            decl.detach();
            begin.insertBefore(decl);
            prologue.push(decl);
        }
        this.#printMsg("Moved declarations from outline region to immediately before the region");

        //------------------------------------------------------------------------------
        const referencedInRegion = this.#findRefsInRegion(region);
        const funParams = this.#createParams(referencedInRegion);
        const fun = this.#createFunction(functionName, region, funParams);
        this.#printMsg("Successfully created function \"" + functionName + "\"");

        //------------------------------------------------------------------------------
        const callArgs = this.#createArgs(fun, prologue, parentFun);
        let call = this.#createCall(callPlaceholder, fun, callArgs);
        this.#printMsg("Successfully created call to \"" + functionName + "\"");

        //------------------------------------------------------------------------------
        // At this point, if the function has a premature return, it will be returning a value
        // of that type instead of void. We change the function to return void now at this point,
        // by doing a) adding a new parameter for the return value of the premature return; b) a new
        // boolean parameter that is set to true if the function returns prematurely; c) we declare these
        // two variables before the function call and d) if the boolean is set to 1 after the call, we
        // return from the caller with the value returned by the callee.
        const newCall = this.#ensureVoidReturn(fun, call);
        if (newCall != null) {
            this.#printMsg("Ensured that the outlined function returns void by parameterizing the early return(s)");
            call = newCall;
        }
        else {
            this.#printMsg("No need to ensure that the outlined function returns void, as it has no early returns");
        }

        //------------------------------------------------------------------------------
        begin.detach();
        end.detach();
        this.#printMsg("Outliner cleanup finished");

        return [fun, call];
    }

    checkOutline(begin, end) {
        var outlinable = true;
        if (this.#findParentFunction(begin) == null) {
            this.#printMsg("Requirement not met: outlinable region must be inside a function");
            outlinable = false;
        }
        if (begin.parent.astId != end.parent.astId) {
            this.#printMsg("Requirement not met: begin and end joinpoints are not at the same scope level");
            outlinable = false;
        }
        return outlinable;
    }

    #ensureVoidReturn(fun, call) {
        const returnStmts = [];
        for (const ret of Query.searchFrom(fun, "returnStmt")) {
            returnStmts.push(ret);
        }

        if (returnStmts.length == 0) {
            return false;
        }

        // actions before the function call
        const type = returnStmts[0].children[0].type;
        const id = Outliner.#getUniqueVarID();
        const resVar = ClavaJoinPoints.varDeclNoInit("__return_val_" + id, type);
        const boolVar = ClavaJoinPoints.varDecl("__return_flag_" + id, ClavaJoinPoints.integerLiteral(0));
        const resVarRef = resVar.varref();
        const boolVarRef = boolVar.varref();

        call.insertBefore(resVar);
        call.insertBefore(boolVar);

        // actions in the function itself
        const params = this.#createParams([resVarRef, boolVarRef]);
        fun.addParam(params[0]);
        fun.addParam(params[1]);

        for (const ret of returnStmts) {
            const resVarParam = fun.params[fun.params.length - 2];
            const derefResVarParam = ClavaJoinPoints.unaryOp("*", resVarParam.varref());
            const retVal = ret.children[0];
            retVal.detach();
            const op1 = ClavaJoinPoints.binaryOp("=", derefResVarParam, retVal, resVarParam.type);
            ret.insertBefore(ClavaJoinPoints.exprStmt(op1));

            const boolVarParam = fun.params[fun.params.length - 1];
            const newVarref = ClavaJoinPoints.varRef(boolVarParam);
            const derefBoolVarParam = ClavaJoinPoints.unaryOp("*", newVarref);
            const trueVal = ClavaJoinPoints.integerLiteral(1);
            const op2 = ClavaJoinPoints.binaryOp("=", derefBoolVarParam, trueVal, boolVarParam.type);
            ret.insertBefore(op2);
        }
        fun.setType(ClavaType.asType("void"));


        // actions on the function call
        const resVarAddr = ClavaJoinPoints.unaryOp("&", resVarRef);
        const boolVarAddr = ClavaJoinPoints.unaryOp("&", boolVarRef);
        const allArgs = call.argList.concat([resVarAddr, boolVarAddr]);
        call = this.#createCall(call, fun, allArgs);

        // actions after the function call
        const returnStmt = ClavaJoinPoints.returnStmt(resVarRef);
        const scope = ClavaJoinPoints.scope();
        scope.setFirstChild(returnStmt);
        const ifStmt = ClavaJoinPoints.ifStmt(boolVarRef, scope);
        call.insertAfter(ifStmt);

        return call;
    }

    #wrapBeginAndEnd(begin, end) {
        const beginWrapper = ClavaJoinPoints.stmtLiteral("//begin of the outline region");
        const endWrapper = ClavaJoinPoints.stmtLiteral("//end of the outline region");
        begin.insertBefore(beginWrapper);
        end.insertAfter(endWrapper);
        return [beginWrapper, endWrapper];
    }

    #findParentFunction(jp) {
        while (jp.joinPointType != "function") {
            if (jp.joinPointType == "file") {
                return null;
            }
            jp = jp.parent;
        }
        return jp;
    }

    #findGlobalVars() {
        const globals = [];
        for (const decl of Query.search("vardecl")) {
            if (decl.isGlobal) {
                globals.push(decl);
            }
        }
        return globals;
    }

    #createCall(placeholder, fun, args) {
        const call = ClavaJoinPoints.call(fun, args);
        placeholder.replaceWith(call);
        return call;
    }

    #createArgs(fun, prologue, parentFun) {
        const decls = [];
        // get decls from the prologue
        for (const stmt of prologue) {
            for (const decl of Query.searchFrom(stmt, "vardecl")) {
                decls.push(decl);
            }
        }
        // get decls from the parent function params
        for (const param of Query.searchFrom(parentFun, "param")) {
            decls.push(param.definition);
        }
        // no need to handle global vars - they are not parameters

        const args = [];
        for (const param of fun.params) {
            for (const decl of decls) {
                if (decl.name === param.name) {
                    const ref = ClavaJoinPoints.varRef(decl);

                    if (param.type.joinPointType === "pointerType" && ref.type.joinPointType === "builtinType") {
                        const addressOfScalar = ClavaJoinPoints.unaryOp("&", ref);
                        args.push(addressOfScalar);
                    }
                    else {
                        args.push(ref);
                    }
                    break;
                }
            }
        }

        return args;
    }

    #createFunction(name, region, params) {
        var oldFun = region[0];
        while (oldFun.joinPointType != "function") {
            oldFun = oldFun.parent;
        }

        const returnStmts = [];
        for (const stmt of region) {
            for (const ret of Query.searchFrom(stmt, "returnStmt")) {
                returnStmts.push(ret);
            }
        }
        let retType = ClavaType.asType("void");
        if (returnStmts.length > 0) {
            retType = returnStmts[0].children[0].type;
            this.#printMsg("Found " + returnStmts.length + " return statement(s) in the outline region");
        }

        const fun = ClavaJoinPoints.functionDecl(name, retType, params);
        oldFun.insertBefore(fun);
        const scope = ClavaJoinPoints.scope();
        fun.setBody(scope);

        for (const stmt of region) {
            stmt.detach();
            scope.insertEnd(stmt);
        }

        // make sure scalar refs are now dereferenced pointers to params
        this.#scalarsToPointers(region, params);
        return fun;
    }

    #scalarsToPointers(region, params) {
        for (const stmt of region) {
            for (const varref of Query.searchFrom(stmt, "varref")) {
                for (const param of params) {
                    if (param.name === varref.name && varref.type.joinPointType === "builtinType") {
                        const newVarref = ClavaJoinPoints.varRef(param);
                        const op = ClavaJoinPoints.unaryOp("*", newVarref);
                        varref.replaceWith(op);
                    }
                }
            }
        }
    }

    #createParams(varrefs) {
        const params = [];

        for (const ref of varrefs) {
            const name = ref.name;
            const varType = ref.type;

            // not sure if adjustedType handling here is correct
            if (varType.joinPointType == "arrayType" || varType.joinPointType == "adjustedType") {
                const param = ClavaJoinPoints.param(name, varType);
                params.push(param);
            }
            else if (varType.joinPointType == "builtinType") {
                const newType = ClavaJoinPoints.pointer(varType);
                const param = ClavaJoinPoints.param(name, newType);
                params.push(param);
            }
            else {
                println("Unsuported param type: " + varType.joinPointType);
            }
            // and if varType is a pointer, do the same as the array?
        }
        this.#printMsg("Created " + params.length + " param(s) for the outlined function");
        return params;
    }

    #findRefsInRegion(region) {
        const decls = [];
        const declsNames = [];
        for (const stmt of region) {
            for (const decl of Query.searchFrom(stmt, "decl")) {
                decls.push(decl);
                declsNames.push(decl.name);
            }
        }

        const varrefs = [];
        const varrefsNames = [];
        for (const stmt of region) {
            for (const varref of Query.searchFrom(stmt, "varref")) {
                // may need to filter for other types, like macros, etc
                // select all varrefs with no matching decl in the region, except globals
                if (!varrefsNames.includes(varref.name) && !varref.isFunctionCall
                    && !declsNames.contains(varref.name) && !varref.decl.isGlobal) {
                    varrefs.push(varref);
                    varrefsNames.push(varref.name);
                }
            }
        }
        this.#printMsg("Found " + varrefsNames.length + " external variable references inside outline region");
        return varrefs;
    }

    #findDeclsWithDependency(region, epilogue) {
        const regionDecls = [];
        const regionDeclsNames = [];
        for (const stmt of region) {
            if (stmt.joinPointType == "declStmt") {
                regionDecls.push(stmt);
                regionDeclsNames.push(stmt.children[0].name);
            }
        }

        const epilogueVarrefsNames = [];
        for (const stmt of epilogue) {
            // also gets function names... could it cause an issue?
            for (const varref of Query.searchFrom(stmt, "varref")) {
                epilogueVarrefsNames.push(varref.name);
            }
        }

        const declsWithDependency = [];
        for (var i = 0; i < regionDecls.length; i++) {
            const varName = regionDeclsNames[i];
            if (epilogueVarrefsNames.includes(varName)) {
                declsWithDependency.push(regionDecls[i]);
            }
        }
        this.#printMsg("Found " + declsWithDependency.length + " declaration(s) referenced after the outline region");
        return declsWithDependency;
    }

    #splitRegions(fun, begin, end) {
        const prologue = []
        const region = [];
        const epilogue = [];

        var inPrologue = true;
        var inRegion = false;
        for (const stmt of Query.searchFrom(fun, "statement")) {
            if (inPrologue) {
                if (stmt.astId == begin.astId) {
                    region.push(stmt);
                    inPrologue = false;
                    inRegion = true;
                }
                else {
                    prologue.push(stmt);
                }
            }
            if (inRegion) {
                // we only want statements at the scope level, we can get the children later
                if (stmt.parent.astId == begin.parent.astId) {
                    region.push(stmt);
                    if (stmt.astId == end.astId) {
                        inRegion = false;
                    }
                }
            }
            if (!inPrologue && !inRegion) {
                epilogue.push(stmt);
            }
        }
        return [prologue, region, epilogue];
    }

    #printMsg(msg) {
        if (this.#verbose)
            println("[Outliner] " + msg);
    }

    #generateFunctionName() {
        var name = "__outlined_function_" + Outliner.#getUniqueFunctionID();
        return name;
    }

    static #getUniqueVarID() {
        const id = Outliner.#GLOBAL_OUTLINE_VAR_ID;
        Outliner.#GLOBAL_OUTLINE_VAR_ID++;
        return id;
    }

    static #getUniqueFunctionID() {
        const id = Outliner.#GLOBAL_OUTLINE_FUN_ID;
        Outliner.#GLOBAL_OUTLINE_FUN_ID++;
        return id;
    }

}