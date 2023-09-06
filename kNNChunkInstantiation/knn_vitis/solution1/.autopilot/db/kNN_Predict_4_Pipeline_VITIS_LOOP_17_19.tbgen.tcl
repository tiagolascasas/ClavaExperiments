set moduleName kNN_Predict_4_Pipeline_VITIS_LOOP_17_19
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
set C_modelName {kNN_Predict_4_Pipeline_VITIS_LOOP_17_19}
set C_modelType { void 0 }
set C_modelArgList {
	{ bestDistances_2 double 64 regular  }
	{ bestDistances_2_1 double 64 regular  }
	{ bestDistances_2_2 double 64 regular  }
	{ bestDistances_2_3 double 64 regular  }
	{ bestDistances_2_4 double 64 regular  }
	{ bestDistances_2_5 double 64 regular  }
	{ bestDistances_2_6 double 64 regular  }
	{ bestDistances_2_7 double 64 regular  }
	{ bestDistances_2_8 double 64 regular  }
	{ bestDistances_2_9 double 64 regular  }
	{ bestDistances_2_10 double 64 regular  }
	{ bestDistances_2_11 double 64 regular  }
	{ bestDistances_2_12 double 64 regular  }
	{ bestDistances_2_13 double 64 regular  }
	{ bestDistances_2_14 double 64 regular  }
	{ bestDistances_2_15 double 64 regular  }
	{ bestDistances_2_16 double 64 regular  }
	{ bestDistances_2_17 double 64 regular  }
	{ bestDistances_2_18 double 64 regular  }
	{ bestDistances_2_19 double 64 regular  }
	{ secondWorstOfBest_24_out double 64 regular {pointer 1}  }
	{ worstOfBestIdx_16_out int 5 regular {pointer 1}  }
	{ worstOfBest_16_out double 64 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "bestDistances_2", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_1", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_2", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_3", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_4", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_5", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_6", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_7", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_8", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_9", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_10", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_11", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_12", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_13", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_14", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_15", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_16", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_17", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_18", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "bestDistances_2_19", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY"} , 
 	{ "Name" : "secondWorstOfBest_24_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} , 
 	{ "Name" : "worstOfBestIdx_16_out", "interface" : "wire", "bitwidth" : 5, "direction" : "WRITEONLY"} , 
 	{ "Name" : "worstOfBest_16_out", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 42
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ bestDistances_2 sc_in sc_lv 64 signal 0 } 
	{ bestDistances_2_1 sc_in sc_lv 64 signal 1 } 
	{ bestDistances_2_2 sc_in sc_lv 64 signal 2 } 
	{ bestDistances_2_3 sc_in sc_lv 64 signal 3 } 
	{ bestDistances_2_4 sc_in sc_lv 64 signal 4 } 
	{ bestDistances_2_5 sc_in sc_lv 64 signal 5 } 
	{ bestDistances_2_6 sc_in sc_lv 64 signal 6 } 
	{ bestDistances_2_7 sc_in sc_lv 64 signal 7 } 
	{ bestDistances_2_8 sc_in sc_lv 64 signal 8 } 
	{ bestDistances_2_9 sc_in sc_lv 64 signal 9 } 
	{ bestDistances_2_10 sc_in sc_lv 64 signal 10 } 
	{ bestDistances_2_11 sc_in sc_lv 64 signal 11 } 
	{ bestDistances_2_12 sc_in sc_lv 64 signal 12 } 
	{ bestDistances_2_13 sc_in sc_lv 64 signal 13 } 
	{ bestDistances_2_14 sc_in sc_lv 64 signal 14 } 
	{ bestDistances_2_15 sc_in sc_lv 64 signal 15 } 
	{ bestDistances_2_16 sc_in sc_lv 64 signal 16 } 
	{ bestDistances_2_17 sc_in sc_lv 64 signal 17 } 
	{ bestDistances_2_18 sc_in sc_lv 64 signal 18 } 
	{ bestDistances_2_19 sc_in sc_lv 64 signal 19 } 
	{ secondWorstOfBest_24_out sc_out sc_lv 64 signal 20 } 
	{ secondWorstOfBest_24_out_ap_vld sc_out sc_logic 1 outvld 20 } 
	{ worstOfBestIdx_16_out sc_out sc_lv 5 signal 21 } 
	{ worstOfBestIdx_16_out_ap_vld sc_out sc_logic 1 outvld 21 } 
	{ worstOfBest_16_out sc_out sc_lv 64 signal 22 } 
	{ worstOfBest_16_out_ap_vld sc_out sc_logic 1 outvld 22 } 
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
 	{ "name": "bestDistances_2", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2", "role": "default" }} , 
 	{ "name": "bestDistances_2_1", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_1", "role": "default" }} , 
 	{ "name": "bestDistances_2_2", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_2", "role": "default" }} , 
 	{ "name": "bestDistances_2_3", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_3", "role": "default" }} , 
 	{ "name": "bestDistances_2_4", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_4", "role": "default" }} , 
 	{ "name": "bestDistances_2_5", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_5", "role": "default" }} , 
 	{ "name": "bestDistances_2_6", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_6", "role": "default" }} , 
 	{ "name": "bestDistances_2_7", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_7", "role": "default" }} , 
 	{ "name": "bestDistances_2_8", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_8", "role": "default" }} , 
 	{ "name": "bestDistances_2_9", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_9", "role": "default" }} , 
 	{ "name": "bestDistances_2_10", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_10", "role": "default" }} , 
 	{ "name": "bestDistances_2_11", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_11", "role": "default" }} , 
 	{ "name": "bestDistances_2_12", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_12", "role": "default" }} , 
 	{ "name": "bestDistances_2_13", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_13", "role": "default" }} , 
 	{ "name": "bestDistances_2_14", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_14", "role": "default" }} , 
 	{ "name": "bestDistances_2_15", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_15", "role": "default" }} , 
 	{ "name": "bestDistances_2_16", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_16", "role": "default" }} , 
 	{ "name": "bestDistances_2_17", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_17", "role": "default" }} , 
 	{ "name": "bestDistances_2_18", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_18", "role": "default" }} , 
 	{ "name": "bestDistances_2_19", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "bestDistances_2_19", "role": "default" }} , 
 	{ "name": "secondWorstOfBest_24_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "secondWorstOfBest_24_out", "role": "default" }} , 
 	{ "name": "secondWorstOfBest_24_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "secondWorstOfBest_24_out", "role": "ap_vld" }} , 
 	{ "name": "worstOfBestIdx_16_out", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "worstOfBestIdx_16_out", "role": "default" }} , 
 	{ "name": "worstOfBestIdx_16_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "worstOfBestIdx_16_out", "role": "ap_vld" }} , 
 	{ "name": "worstOfBest_16_out", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "worstOfBest_16_out", "role": "default" }} , 
 	{ "name": "worstOfBest_16_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "worstOfBest_16_out", "role": "ap_vld" }} , 
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
		"CDFG" : "kNN_Predict_4_Pipeline_VITIS_LOOP_17_19",
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
			{"Name" : "bestDistances_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_3", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_4", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_5", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_6", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_7", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_8", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_9", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_10", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_11", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_12", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_13", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_14", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_15", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_16", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_17", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_18", "Type" : "None", "Direction" : "I"},
			{"Name" : "bestDistances_2_19", "Type" : "None", "Direction" : "I"},
			{"Name" : "secondWorstOfBest_24_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "worstOfBestIdx_16_out", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "worstOfBest_16_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_17_1", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter1", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter2", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter2", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mux_205_64_1_1_U261", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	kNN_Predict_4_Pipeline_VITIS_LOOP_17_19 {
		bestDistances_2 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_1 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_2 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_3 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_4 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_5 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_6 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_7 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_8 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_9 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_10 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_11 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_12 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_13 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_14 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_15 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_16 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_17 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_18 {Type I LastRead 0 FirstWrite -1}
		bestDistances_2_19 {Type I LastRead 0 FirstWrite -1}
		secondWorstOfBest_24_out {Type O LastRead -1 FirstWrite 2}
		worstOfBestIdx_16_out {Type O LastRead -1 FirstWrite 2}
		worstOfBest_16_out {Type O LastRead -1 FirstWrite 2}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "23", "Max" : "23"}
	, {"Name" : "Interval", "Min" : "23", "Max" : "23"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	bestDistances_2 { ap_none {  { bestDistances_2 in_data 0 64 } } }
	bestDistances_2_1 { ap_none {  { bestDistances_2_1 in_data 0 64 } } }
	bestDistances_2_2 { ap_none {  { bestDistances_2_2 in_data 0 64 } } }
	bestDistances_2_3 { ap_none {  { bestDistances_2_3 in_data 0 64 } } }
	bestDistances_2_4 { ap_none {  { bestDistances_2_4 in_data 0 64 } } }
	bestDistances_2_5 { ap_none {  { bestDistances_2_5 in_data 0 64 } } }
	bestDistances_2_6 { ap_none {  { bestDistances_2_6 in_data 0 64 } } }
	bestDistances_2_7 { ap_none {  { bestDistances_2_7 in_data 0 64 } } }
	bestDistances_2_8 { ap_none {  { bestDistances_2_8 in_data 0 64 } } }
	bestDistances_2_9 { ap_none {  { bestDistances_2_9 in_data 0 64 } } }
	bestDistances_2_10 { ap_none {  { bestDistances_2_10 in_data 0 64 } } }
	bestDistances_2_11 { ap_none {  { bestDistances_2_11 in_data 0 64 } } }
	bestDistances_2_12 { ap_none {  { bestDistances_2_12 in_data 0 64 } } }
	bestDistances_2_13 { ap_none {  { bestDistances_2_13 in_data 0 64 } } }
	bestDistances_2_14 { ap_none {  { bestDistances_2_14 in_data 0 64 } } }
	bestDistances_2_15 { ap_none {  { bestDistances_2_15 in_data 0 64 } } }
	bestDistances_2_16 { ap_none {  { bestDistances_2_16 in_data 0 64 } } }
	bestDistances_2_17 { ap_none {  { bestDistances_2_17 in_data 0 64 } } }
	bestDistances_2_18 { ap_none {  { bestDistances_2_18 in_data 0 64 } } }
	bestDistances_2_19 { ap_none {  { bestDistances_2_19 in_data 0 64 } } }
	secondWorstOfBest_24_out { ap_vld {  { secondWorstOfBest_24_out out_data 1 64 }  { secondWorstOfBest_24_out_ap_vld out_vld 1 1 } } }
	worstOfBestIdx_16_out { ap_vld {  { worstOfBestIdx_16_out out_data 1 5 }  { worstOfBestIdx_16_out_ap_vld out_vld 1 1 } } }
	worstOfBest_16_out { ap_vld {  { worstOfBest_16_out out_data 1 64 }  { worstOfBest_16_out_ap_vld out_vld 1 1 } } }
}
