"use strict";

class Voidifier {
    constructor() { }

    voidify(fun, returnVarName = "rtr_value") {
        const returnStmts = this.#findNonvoidReturnStmts([fun]);
        if (returnStmts.length == 0) {
            return false;
        }

        this.#voidifyFunction(fun, returnStmts, returnVarName);

        for (const call of Query.search("call", { "signature": fun.signature })) {
            this.#handleCall(call, fun);
        }
        return true;
    }


    #handleCall(call, fun) {
        const assign = call.parent;
        if (!assign.instanceOf("binaryOp")) {
            // in theory it should never happen if the statement decomposer is run before
            throw new Error("[Voidifier] Cannot handle call to function " + fun.name + " because it is not the rhs of an assignment");
        }

        const newVarref = ClavaJoinPoints.varRef(assign.left.declaration);
        const op = ClavaJoinPoints.unaryOp("&", newVarref);

        const args = [...call.argList, op];
        const newCall = ClavaJoinPoints.call(fun, args);
        assign.replaceWith(newCall);

    }

    #voidifyFunction(fun, returnStmts, returnVarName) {
        const retType = returnStmts[0].children[0].type;
        const pointerType = ClavaJoinPoints.pointer(retType);
        const retParam = ClavaJoinPoints.param(returnVarName, pointerType);
        fun.addParam(retParam);

        for (const ret of returnStmts) {
            const derefRet = ClavaJoinPoints.unaryOp("*", retParam.varref());
            const retVal = ret.children[0];
            retVal.detach();
            const op = ClavaJoinPoints.binaryOp("=", derefRet, retVal, retType);
            ret.insertBefore(ClavaJoinPoints.exprStmt(op));

        }
        fun.setType(ClavaType.asType("void"));
    }

    #findNonvoidReturnStmts(startingPoints) {
        const returnStmts = [];
        for (const stmt of startingPoints) {
            for (const ret of Query.searchFrom(stmt, "returnStmt")) {
                if (ret.numChildren > 0) {
                    returnStmts.push(ret);
                }
            }
        }
        return returnStmts;
    }
}