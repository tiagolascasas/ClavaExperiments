set moduleName kNN_Predict_4_Pipeline_VITIS_LOOP_17_110
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set C_modelName {kNN_Predict_4_Pipeline_VITIS_LOOP_17_110}
set C_modelType { void 0 }
set C_modelArgList {
	{ bestDistances_2_41 double 64 regular  }
	{ bestDistances_2_42 double 64 regular  }
	{ bestDistances_2_43 double 64 regular  }
	{ bestDistances_2_44 double 64 regular  }
	{ bestDistances_2_45 double 64 regular  }
	{ bestDistances_2_46 double 64 regular  }
	{ bestDistances_2_47 double 64 regular  }
	{ bestDistances_2_48 double 64 regular  }
	{ bestDistances_2_49 double 64 regular  }
	{ bestDistances_2_50 double 64 regular  }
	{ bestDistances_2_51 double 64 regular  }
	{ bestDistances_2_52 double 64 regular  }
	{ bestDistances_2_53 double 64 regular  }
	{ bestDistances_2_54 double 64 regular  }
	{ bestDistances_2_55 double 64 regular  }
	{ bestDistances_2_56 double 64 regular  }
	{ bestDistances_2_57 double 64 regular  }
	{ bestDistances_2_58 double 64 regular  }
	{ bestDistances_2_59 double 64 regular  }
	{ bestDistances_2_60 double 64 regular  }
	{ secondWorstOfBest_27_out double 64 regular {pointer 1}  }
	{ worstOfBestIdx_18_out int 5 regular {pointer 1}  }
	{ worstOfBest_18_out double 64 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "bestDistances_2_41", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_42", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_43", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_44", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_45", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_46", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_47", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_48", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_49", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_50", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_51", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_52", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_53", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_54", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_55", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_56", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_57", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_58", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_59", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_60", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "secondWorstOfBest_27_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "worstOfBestIdx_18_out", "interface" : "wire", "bitwidth" : 5, "direction" : "WRITEONLY"} , 
 	{ "Name" : "worstOfBest_18_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 42
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ bestDistances_2_41 sc_in sc_lv 64 signal 0 } 
	{ bestDistances_2_42 sc_in sc_lv 64 signal 1 } 
	{ bestDistances_2_43 sc_in sc_lv 64 signal 2 } 
	{ bestDistances_2_44 sc_in sc_lv 64 signal 3 } 
	{ bestDistances_2_45 sc_in sc_lv 64 signal 4 } 
	{ bestDistances_2_46 sc_in sc_lv 64 signal 5 } 
	{ bestDistances_2_47 sc_in sc_lv 64 signal 6 } 
	{ bestDistances_2_48 sc_in sc_lv 64 signal 7 } 
	{ bestDistances_2_49 sc_in sc_lv 64 signal 8 } 
	{ bestDistances_2_50 sc_in sc_lv 64 signal 9 } 
	{ bestDistances_2_51 sc_in sc_lv 64 signal 10 } 
	{ bestDistances_2_52 sc_in sc_lv 64 signal 11 } 
	{ bestDistances_2_53 sc_in sc_lv 64 signal 12 } 
	{ bestDistances_2_54 sc_in sc_lv 64 signal 13 } 
	{ bestDistances_2_55 sc_in sc_lv 64 signal 14 } 
	{ bestDistances_2_56 sc_in sc_lv 64 signal 15 } 
	{ bestDistances_2_57 sc_in sc_lv 64 signal 16 } 
	{ bestDistances_2_58 sc_in sc_lv 64 signal 17 } 
	{ bestDistances_2_59 sc_in sc_lv 64 signal 18 } 
	{ bestDistances_2_60 sc_in sc_lv 64 signal 19 } 
	{ secondWorstOfBest_27_out sc_out sc_lv 64 signal 20 } 
	{ secondWorstOfBest_27_out_ap_vld sc_out sc_logic 1 outvld 20 } 
	{ worstOfBestIdx_18_out sc_out sc_lv 5 signal 21 } 
	{ worstOfBestIdx_18_out_ap_vld sc_out sc_logic 1 outvld 21 } 
	{ worstOfBest_18_out sc_out sc_lv 64 signal 22 } 
	{ worstOfBest_18_out_ap_vld sc_out sc_logic 1 outvld 22 } 
	{ grp_fu_75624_p_din0 sc_out sc_lv 64 signal -1 } 
	{ grp_fu_75624_p_din1 sc_out sc_lv 64 signal -1 } 
	{ grp_fu_75624_p_opcode sc_out sc_lv 5 signal -1 } 
	{ grp_fu_75624_p_dout0 sc_in sc_lv 1 signal -1 } 
	{ grp_fu_75624_p_ce sc_out sc_logic 1 signal -1 } 
	{ grp_fu_75628_p_din0 sc_out sc_lv 64 signal -1 } 
	{ grp_fu_75628_p_din1 sc_out sc_lv 64 signal -1 } 
	{ grp_fu_75628_p_opcode sc_out sc_lv 5 signal -1 } 
	{ grp_fu_75628_p_dout0 sc_in sc_lv 1 signal -1 } 
	{ grp_fu_75628_p_ce sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "bestDistances_2_41", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_41", "role": "default" }} , 
 	{ "name": "bestDistances_2_42", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_42", "role": "default" }} , 
 	{ "name": "bestDistances_2_43", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_43", "role": "default" }} , 
 	{ "name": "bestDistances_2_44", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_44", "role": "default" }} , 
 	{ "name": "bestDistances_2_45", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_45", "role": "default" }} , 
 	{ "name": "bestDistances_2_46", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_46", "role": "default" }} , 
 	{ "name": "bestDistances_2_47", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_47", "role": "default" }} , 
 	{ "name": "bestDistances_2_48", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_48", "role": "default" }} , 
 	{ "name": "bestDistances_2_49", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_49", "role": "default" }} , 
 	{ "name": "bestDistances_2_50", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_50", "role": "default" }} , 
 	{ "name": "bestDistances_2_51", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_51", "role": "default" }} , 
 	{ "name": "bestDistances_2_52", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_52", "role": "default" }} , 
 	{ "name": "bestDistances_2_53", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_53", "role": "default" }} , 
 	{ "name": "bestDistances_2_54", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_54", "role": "default" }} , 
 	{ "name": "bestDistances_2_55", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_55", "role": "default" }} , 
 	{ "name": "bestDistances_2_56", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_56", "role": "default" }} , 
 	{ "name": "bestDistances_2_57", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_57", "role": "default" }} , 
 	{ "name": "bestDistances_2_58", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_58", "role": "default" }} , 
 	{ "name": "bestDistances_2_59", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_59", "role": "default" }} , 
 	{ "name": "bestDistances_2_60", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_60", "role": "default" }} , 
 	{ "name": "secondWorstOfBest_27_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "secondWorstOfBest_27_out", "role": "default" }} , 
 	{ "name": "secondWorstOfBest_27_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "secondWorstOfBest_27_out", "role": "ap_vld" }} , 
 	{ "name": "worstOfBestIdx_18_out", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "worstOfBestIdx_18_out", "role": "default" }} , 
 	{ "name": "worstOfBestIdx_18_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "worstOfBestIdx_18_out", "role": "ap_vld" }} , 
 	{ "name": "worstOfBest_18_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "worstOfBest_18_out", "role": "default" }} , 
 	{ "name": "worstOfBest_18_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "worstOfBest_18_out", "role": "ap_vld" }} , 
 	{ "name": "grp_fu_75624_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "grp_fu_75624_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_75624_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "grp_fu_75624_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_75624_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "grp_fu_75624_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_75624_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_75624_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_75624_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_75624_p_ce", "role": "default" }} , 
 	{ "name": "grp_fu_75628_p_din0", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "grp_fu_75628_p_din0", "role": "default" }} , 
 	{ "name": "grp_fu_75628_p_din1", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "grp_fu_75628_p_din1", "role": "default" }} , 
 	{ "name": "grp_fu_75628_p_opcode", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "grp_fu_75628_p_opcode", "role": "default" }} , 
 	{ "name": "grp_fu_75628_p_dout0", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_75628_p_dout0", "role": "default" }} , 
 	{ "name": "grp_fu_75628_p_ce", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "grp_fu_75628_p_ce", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
		"CDFG" : "kNN_Predict_4_Pipeline_VITIS_LOOP_17_110",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "23", "EstimateLatencyMax" : "23",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "bestDistances_2_41", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_42", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_43", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_44", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_45", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_46", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_47", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_48", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_49", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_50", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_51", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_52", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_53", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_54", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_55", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_56", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_57", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_58", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_59", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_60", "Type" : "None", "Direction" : "I"},
			{"Name" : "secondWorstOfBest_27_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "worstOfBestIdx_18_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "worstOfBest_18_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_17_1", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter1", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter2", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter2", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mux_205_64_1_1_U287", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	kNN_Predict_4_Pipeline_VITIS_LOOP_17_110 {
		bestDistances_2_41 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_42 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_43 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_44 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_45 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_46 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_47 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_48 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_49 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_50 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_51 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_52 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_53 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_54 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_55 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_56 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_57 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_58 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_59 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_60 {Type I LastRead 0 FirstWrite -1}
		secondWorstOfBest_27_out {Type O LastRead -1 FirstWrite 2}
		worstOfBestIdx_18_out {Type O LastRead -1 FirstWrite 2}
		worstOfBest_18_out {Type O LastRead -1 FirstWrite 2}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "23", "Max" : "23"}
	, {"Name" : "Interval", "Min" : "23", "Max" : "23"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	bestDistances_2_41 { ap_none {  { bestDistances_2_41 in_data 0 64 } } }
	bestDistances_2_42 { ap_none {  { bestDistances_2_42 in_data 0 64 } } }
	bestDistances_2_43 { ap_none {  { bestDistances_2_43 in_data 0 64 } } }
	bestDistances_2_44 { ap_none {  { bestDistances_2_44 in_data 0 64 } } }
	bestDistances_2_45 { ap_none {  { bestDistances_2_45 in_data 0 64 } } }
	bestDistances_2_46 { ap_none {  { bestDistances_2_46 in_data 0 64 } } }
	bestDistances_2_47 { ap_none {  { bestDistances_2_47 in_data 0 64 } } }
	bestDistances_2_48 { ap_none {  { bestDistances_2_48 in_data 0 64 } } }
	bestDistances_2_49 { ap_none {  { bestDistances_2_49 in_data 0 64 } } }
	bestDistances_2_50 { ap_none {  { bestDistances_2_50 in_data 0 64 } } }
	bestDistances_2_51 { ap_none {  { bestDistances_2_51 in_data 0 64 } } }
	bestDistances_2_52 { ap_none {  { bestDistances_2_52 in_data 0 64 } } }
	bestDistances_2_53 { ap_none {  { bestDistances_2_53 in_data 0 64 } } }
	bestDistances_2_54 { ap_none {  { bestDistances_2_54 in_data 0 64 } } }
	bestDistances_2_55 { ap_none {  { bestDistances_2_55 in_data 0 64 } } }
	bestDistances_2_56 { ap_none {  { bestDistances_2_56 in_data 0 64 } } }
	bestDistances_2_57 { ap_none {  { bestDistances_2_57 in_data 0 64 } } }
	bestDistances_2_58 { ap_none {  { bestDistances_2_58 in_data 0 64 } } }
	bestDistances_2_59 { ap_none {  { bestDistances_2_59 in_data 0 64 } } }
	bestDistances_2_60 { ap_none {  { bestDistances_2_60 in_data 0 64 } } }
	secondWorstOfBest_27_out { ap_vld {  { secondWorstOfBest_27_out out_data 1 64 }  { secondWorstOfBest_27_out_ap_vld out_vld 1 1 } } }
	worstOfBestIdx_18_out { ap_vld {  { worstOfBestIdx_18_out out_data 1 5 }  { worstOfBestIdx_18_out_ap_vld out_vld 1 1 } } }
	worstOfBest_18_out { ap_vld {  { worstOfBest_18_out out_data 1 64 }  { worstOfBest_18_out_ap_vld out_vld 1 1 } } }
}
