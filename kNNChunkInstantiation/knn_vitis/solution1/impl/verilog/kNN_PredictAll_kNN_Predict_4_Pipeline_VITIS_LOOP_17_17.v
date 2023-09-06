// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Version: 2022.1
// Copyright (C) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module kNN_PredictAll_kNN_Predict_4_Pipeline_VITIS_LOOP_17_17 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        bestDistances_1_82,
        bestDistances_1_83,
        bestDistances_1_84,
        bestDistances_1_85,
        bestDistances_1_86,
        bestDistances_1_87,
        bestDistances_1_88,
        bestDistances_1_89,
        bestDistances_1_90,
        bestDistances_1_91,
        bestDistances_1_92,
        bestDistances_1_93,
        bestDistances_1_94,
        bestDistances_1_95,
        bestDistances_1_96,
        bestDistances_1_97,
        bestDistances_1_98,
        bestDistances_1_99,
        bestDistances_1_100,
        bestDistances_1_101,
        secondWorstOfBest_18_out,
        secondWorstOfBest_18_out_ap_vld,
        worstOfBestIdx_12_out,
        worstOfBestIdx_12_out_ap_vld,
        worstOfBest_12_out,
        worstOfBest_12_out_ap_vld,
        grp_fu_75624_p_din0,
        grp_fu_75624_p_din1,
        grp_fu_75624_p_opcode,
        grp_fu_75624_p_dout0,
        grp_fu_75624_p_ce,
        grp_fu_75628_p_din0,
        grp_fu_75628_p_din1,
        grp_fu_75628_p_opcode,
        grp_fu_75628_p_dout0,
        grp_fu_75628_p_ce
);

parameter    ap_ST_fsm_pp0_stage0 = 1'd1;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [63:0] bestDistances_1_82;
input  [63:0] bestDistances_1_83;
input  [63:0] bestDistances_1_84;
input  [63:0] bestDistances_1_85;
input  [63:0] bestDistances_1_86;
input  [63:0] bestDistances_1_87;
input  [63:0] bestDistances_1_88;
input  [63:0] bestDistances_1_89;
input  [63:0] bestDistances_1_90;
input  [63:0] bestDistances_1_91;
input  [63:0] bestDistances_1_92;
input  [63:0] bestDistances_1_93;
input  [63:0] bestDistances_1_94;
input  [63:0] bestDistances_1_95;
input  [63:0] bestDistances_1_96;
input  [63:0] bestDistances_1_97;
input  [63:0] bestDistances_1_98;
input  [63:0] bestDistances_1_99;
input  [63:0] bestDistances_1_100;
input  [63:0] bestDistances_1_101;
output  [63:0] secondWorstOfBest_18_out;
output   secondWorstOfBest_18_out_ap_vld;
output  [4:0] worstOfBestIdx_12_out;
output   worstOfBestIdx_12_out_ap_vld;
output  [63:0] worstOfBest_12_out;
output   worstOfBest_12_out_ap_vld;
output  [63:0] grp_fu_75624_p_din0;
output  [63:0] grp_fu_75624_p_din1;
output  [4:0] grp_fu_75624_p_opcode;
input  [0:0] grp_fu_75624_p_dout0;
output   grp_fu_75624_p_ce;
output  [63:0] grp_fu_75628_p_din0;
output  [63:0] grp_fu_75628_p_din1;
output  [4:0] grp_fu_75628_p_opcode;
input  [0:0] grp_fu_75628_p_dout0;
output   grp_fu_75628_p_ce;

reg ap_idle;
reg secondWorstOfBest_18_out_ap_vld;
reg worstOfBestIdx_12_out_ap_vld;
reg worstOfBest_12_out_ap_vld;

(* fsm_encoding = "none" *) reg   [0:0] ap_CS_fsm;
wire    ap_CS_fsm_pp0_stage0;
wire    ap_enable_reg_pp0_iter0;
reg    ap_enable_reg_pp0_iter1;
reg    ap_enable_reg_pp0_iter2;
reg    ap_idle_pp0;
wire    ap_block_state1_pp0_stage0_iter0;
wire    ap_block_state2_pp0_stage0_iter1;
wire    ap_block_state3_pp0_stage0_iter2;
wire    ap_block_pp0_stage0_subdone;
wire   [0:0] icmp_ln17_fu_280_p2;
reg    ap_condition_exit_pp0_iter1_stage0;
wire    ap_loop_exit_ready;
reg    ap_ready_int;
wire    ap_block_pp0_stage0_11001;
reg   [4:0] i_reg_665;
reg   [0:0] icmp_ln17_reg_670;
reg   [63:0] worstOfBest_load_3_reg_674;
reg   [63:0] secondWorstOfBest_load_3_reg_682;
wire   [63:0] secondWorstOfBest_11_fu_300_p22;
reg   [63:0] secondWorstOfBest_11_reg_689;
reg   [63:0] worstOfBest_fu_92;
wire   [63:0] secondWorstOfBest_15_fu_473_p3;
reg   [63:0] ap_sig_allocacmp_worstOfBest_load_3;
wire    ap_block_pp0_stage0;
wire    ap_loop_init;
reg   [31:0] worstOfBestIdx_fu_96;
wire   [31:0] worstOfBestIdx_6_fu_479_p3;
reg   [63:0] secondWorstOfBest_fu_100;
wire   [63:0] secondWorstOfBest_14_fu_505_p3;
reg   [63:0] ap_sig_allocacmp_secondWorstOfBest_load_3;
reg   [4:0] secondWorstOfBestIdx_fu_104;
wire   [4:0] add_ln17_fu_286_p2;
wire    ap_block_pp0_stage0_01001;
wire   [63:0] bitcast_ln21_fu_341_p1;
wire   [63:0] bitcast_ln21_3_fu_358_p1;
wire   [10:0] tmp_s_fu_344_p4;
wire   [51:0] trunc_ln21_fu_354_p1;
wire   [0:0] icmp_ln21_7_fu_381_p2;
wire   [0:0] icmp_ln21_fu_375_p2;
wire   [10:0] tmp_9_fu_361_p4;
wire   [51:0] trunc_ln21_3_fu_371_p1;
wire   [0:0] icmp_ln21_9_fu_399_p2;
wire   [0:0] icmp_ln21_8_fu_393_p2;
wire   [0:0] or_ln21_3_fu_405_p2;
wire   [0:0] and_ln21_fu_411_p2;
wire   [0:0] or_ln21_fu_387_p2;
wire   [63:0] bitcast_ln29_fu_426_p1;
wire   [10:0] tmp_11_fu_429_p4;
wire   [51:0] trunc_ln29_fu_439_p1;
wire   [0:0] icmp_ln29_3_fu_449_p2;
wire   [0:0] icmp_ln29_fu_443_p2;
wire   [0:0] or_ln29_fu_455_p2;
wire   [0:0] and_ln29_fu_461_p2;
wire   [0:0] and_ln21_3_fu_417_p2;
wire   [31:0] zext_ln21_fu_423_p1;
wire   [0:0] and_ln29_5_fu_467_p2;
wire   [0:0] xor_ln21_fu_487_p2;
wire   [0:0] and_ln29_6_fu_493_p2;
wire   [63:0] secondWorstOfBest_13_fu_499_p3;
wire    ap_block_pp0_stage0_00001;
reg    ap_done_reg;
wire    ap_continue_int;
reg    ap_done_int;
reg    ap_loop_exit_ready_pp0_iter2_reg;
reg   [0:0] ap_NS_fsm;
wire    ap_enable_pp0;
wire    ap_start_int;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 1'd1;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
#0 ap_done_reg = 1'b0;
end

kNN_PredictAll_mux_205_64_1_1 #(
    .ID( 1 ),
    .NUM_STAGE( 1 ),
    .din0_WIDTH( 64 ),
    .din1_WIDTH( 64 ),
    .din2_WIDTH( 64 ),
    .din3_WIDTH( 64 ),
    .din4_WIDTH( 64 ),
    .din5_WIDTH( 64 ),
    .din6_WIDTH( 64 ),
    .din7_WIDTH( 64 ),
    .din8_WIDTH( 64 ),
    .din9_WIDTH( 64 ),
    .din10_WIDTH( 64 ),
    .din11_WIDTH( 64 ),
    .din12_WIDTH( 64 ),
    .din13_WIDTH( 64 ),
    .din14_WIDTH( 64 ),
    .din15_WIDTH( 64 ),
    .din16_WIDTH( 64 ),
    .din17_WIDTH( 64 ),
    .din18_WIDTH( 64 ),
    .din19_WIDTH( 64 ),
    .din20_WIDTH( 5 ),
    .dout_WIDTH( 64 ))
mux_205_64_1_1_U209(
    .din0(bestDistances_1_82),
    .din1(bestDistances_1_83),
    .din2(bestDistances_1_84),
    .din3(bestDistances_1_85),
    .din4(bestDistances_1_86),
    .din5(bestDistances_1_87),
    .din6(bestDistances_1_88),
    .din7(bestDistances_1_89),
    .din8(bestDistances_1_90),
    .din9(bestDistances_1_91),
    .din10(bestDistances_1_92),
    .din11(bestDistances_1_93),
    .din12(bestDistances_1_94),
    .din13(bestDistances_1_95),
    .din14(bestDistances_1_96),
    .din15(bestDistances_1_97),
    .din16(bestDistances_1_98),
    .din17(bestDistances_1_99),
    .din18(bestDistances_1_100),
    .din19(bestDistances_1_101),
    .din20(secondWorstOfBestIdx_fu_104),
    .dout(secondWorstOfBest_11_fu_300_p22)
);

kNN_PredictAll_flow_control_loop_pipe_sequential_init flow_control_loop_pipe_sequential_init_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(ap_start),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_start_int(ap_start_int),
    .ap_loop_init(ap_loop_init),
    .ap_ready_int(ap_ready_int),
    .ap_loop_exit_ready(ap_condition_exit_pp0_iter1_stage0),
    .ap_loop_exit_done(ap_done_int),
    .ap_continue_int(ap_continue_int),
    .ap_done_int(ap_done_int)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_pp0_stage0;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue_int == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_loop_exit_ready_pp0_iter2_reg == 1'b1))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if ((1'b1 == ap_condition_exit_pp0_iter1_stage0)) begin
            ap_enable_reg_pp0_iter1 <= 1'b0;
        end else if (((1'b0 == ap_block_pp0_stage0_subdone) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            ap_enable_reg_pp0_iter1 <= ap_start_int;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((ap_loop_exit_ready == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
        ap_loop_exit_ready_pp0_iter2_reg <= 1'b0;
    end else if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_loop_exit_ready_pp0_iter2_reg <= ap_loop_exit_ready;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        if ((ap_loop_init == 1'b1)) begin
            secondWorstOfBestIdx_fu_104 <= 5'd0;
        end else if (((icmp_ln17_fu_280_p2 == 1'd0) & (ap_enable_reg_pp0_iter1 == 1'b1))) begin
            secondWorstOfBestIdx_fu_104 <= add_ln17_fu_286_p2;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((1'b0 == ap_block_pp0_stage0_11001)) begin
        if (((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
            secondWorstOfBest_fu_100 <= 64'd0;
        end else if (((ap_enable_reg_pp0_iter2 == 1'b1) & (icmp_ln17_reg_670 == 1'd0))) begin
            secondWorstOfBest_fu_100 <= secondWorstOfBest_14_fu_505_p3;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((1'b0 == ap_block_pp0_stage0_11001)) begin
        if (((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
            worstOfBestIdx_fu_96 <= 32'd4294967295;
        end else if (((ap_enable_reg_pp0_iter2 == 1'b1) & (icmp_ln17_reg_670 == 1'd0))) begin
            worstOfBestIdx_fu_96 <= worstOfBestIdx_6_fu_479_p3;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((1'b0 == ap_block_pp0_stage0_11001)) begin
        if (((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
            worstOfBest_fu_92 <= 64'd0;
        end else if (((ap_enable_reg_pp0_iter2 == 1'b1) & (icmp_ln17_reg_670 == 1'd0))) begin
            worstOfBest_fu_92 <= secondWorstOfBest_15_fu_473_p3;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        i_reg_665 <= secondWorstOfBestIdx_fu_104;
        icmp_ln17_reg_670 <= icmp_ln17_fu_280_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln17_fu_280_p2 == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        secondWorstOfBest_11_reg_689 <= secondWorstOfBest_11_fu_300_p22;
        secondWorstOfBest_load_3_reg_682 <= ap_sig_allocacmp_secondWorstOfBest_load_3;
        worstOfBest_load_3_reg_674 <= ap_sig_allocacmp_worstOfBest_load_3;
    end
end

always @ (*) begin
    if (((icmp_ln17_fu_280_p2 == 1'd1) & (1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_condition_exit_pp0_iter1_stage0 = 1'b1;
    end else begin
        ap_condition_exit_pp0_iter1_stage0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_loop_exit_ready_pp0_iter2_reg == 1'b1))) begin
        ap_done_int = 1'b1;
    end else begin
        ap_done_int = ap_done_reg;
    end
end

always @ (*) begin
    if (((ap_start_int == 1'b0) & (ap_idle_pp0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_ready_int = 1'b1;
    end else begin
        ap_ready_int = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter2 == 1'b1) & (icmp_ln17_reg_670 == 1'd0))) begin
        ap_sig_allocacmp_secondWorstOfBest_load_3 = secondWorstOfBest_14_fu_505_p3;
    end else begin
        ap_sig_allocacmp_secondWorstOfBest_load_3 = secondWorstOfBest_fu_100;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter2 == 1'b1) & (icmp_ln17_reg_670 == 1'd0))) begin
        ap_sig_allocacmp_worstOfBest_load_3 = secondWorstOfBest_15_fu_473_p3;
    end else begin
        ap_sig_allocacmp_worstOfBest_load_3 = worstOfBest_fu_92;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln17_reg_670 == 1'd1))) begin
        secondWorstOfBest_18_out_ap_vld = 1'b1;
    end else begin
        secondWorstOfBest_18_out_ap_vld = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln17_reg_670 == 1'd1))) begin
        worstOfBestIdx_12_out_ap_vld = 1'b1;
    end else begin
        worstOfBestIdx_12_out_ap_vld = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln17_reg_670 == 1'd1))) begin
        worstOfBest_12_out_ap_vld = 1'b1;
    end else begin
        worstOfBest_12_out_ap_vld = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_pp0_stage0 : begin
            ap_NS_fsm = ap_ST_fsm_pp0_stage0;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln17_fu_286_p2 = (secondWorstOfBestIdx_fu_104 + 5'd1);

assign and_ln21_3_fu_417_p2 = (or_ln21_fu_387_p2 & and_ln21_fu_411_p2);

assign and_ln21_fu_411_p2 = (or_ln21_3_fu_405_p2 & grp_fu_75624_p_dout0);

assign and_ln29_5_fu_467_p2 = (grp_fu_75628_p_dout0 & and_ln29_fu_461_p2);

assign and_ln29_6_fu_493_p2 = (xor_ln21_fu_487_p2 & and_ln29_5_fu_467_p2);

assign and_ln29_fu_461_p2 = (or_ln29_fu_455_p2 & or_ln21_3_fu_405_p2);

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd0];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_00001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_01001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_subdone = ~(1'b1 == 1'b1);

assign ap_block_state1_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state2_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state3_pp0_stage0_iter2 = ~(1'b1 == 1'b1);

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign ap_enable_reg_pp0_iter0 = ap_start_int;

assign ap_loop_exit_ready = ap_condition_exit_pp0_iter1_stage0;

assign bitcast_ln21_3_fu_358_p1 = secondWorstOfBest_11_reg_689;

assign bitcast_ln21_fu_341_p1 = worstOfBest_load_3_reg_674;

assign bitcast_ln29_fu_426_p1 = secondWorstOfBest_load_3_reg_682;

assign grp_fu_75624_p_ce = 1'b1;

assign grp_fu_75624_p_din0 = ap_sig_allocacmp_worstOfBest_load_3;

assign grp_fu_75624_p_din1 = secondWorstOfBest_11_fu_300_p22;

assign grp_fu_75624_p_opcode = 5'd4;

assign grp_fu_75628_p_ce = 1'b1;

assign grp_fu_75628_p_din0 = ap_sig_allocacmp_secondWorstOfBest_load_3;

assign grp_fu_75628_p_din1 = secondWorstOfBest_11_fu_300_p22;

assign grp_fu_75628_p_opcode = 5'd4;

assign icmp_ln17_fu_280_p2 = ((secondWorstOfBestIdx_fu_104 == 5'd20) ? 1'b1 : 1'b0);

assign icmp_ln21_7_fu_381_p2 = ((trunc_ln21_fu_354_p1 == 52'd0) ? 1'b1 : 1'b0);

assign icmp_ln21_8_fu_393_p2 = ((tmp_9_fu_361_p4 != 11'd2047) ? 1'b1 : 1'b0);

assign icmp_ln21_9_fu_399_p2 = ((trunc_ln21_3_fu_371_p1 == 52'd0) ? 1'b1 : 1'b0);

assign icmp_ln21_fu_375_p2 = ((tmp_s_fu_344_p4 != 11'd2047) ? 1'b1 : 1'b0);

assign icmp_ln29_3_fu_449_p2 = ((trunc_ln29_fu_439_p1 == 52'd0) ? 1'b1 : 1'b0);

assign icmp_ln29_fu_443_p2 = ((tmp_11_fu_429_p4 != 11'd2047) ? 1'b1 : 1'b0);

assign or_ln21_3_fu_405_p2 = (icmp_ln21_9_fu_399_p2 | icmp_ln21_8_fu_393_p2);

assign or_ln21_fu_387_p2 = (icmp_ln21_fu_375_p2 | icmp_ln21_7_fu_381_p2);

assign or_ln29_fu_455_p2 = (icmp_ln29_fu_443_p2 | icmp_ln29_3_fu_449_p2);

assign secondWorstOfBest_13_fu_499_p3 = ((and_ln29_6_fu_493_p2[0:0] == 1'b1) ? secondWorstOfBest_11_reg_689 : secondWorstOfBest_load_3_reg_682);

assign secondWorstOfBest_14_fu_505_p3 = ((and_ln21_3_fu_417_p2[0:0] == 1'b1) ? worstOfBest_load_3_reg_674 : secondWorstOfBest_13_fu_499_p3);

assign secondWorstOfBest_15_fu_473_p3 = ((and_ln21_3_fu_417_p2[0:0] == 1'b1) ? secondWorstOfBest_11_reg_689 : worstOfBest_load_3_reg_674);

assign secondWorstOfBest_18_out = secondWorstOfBest_fu_100;

assign tmp_11_fu_429_p4 = {{bitcast_ln29_fu_426_p1[62:52]}};

assign tmp_9_fu_361_p4 = {{bitcast_ln21_3_fu_358_p1[62:52]}};

assign tmp_s_fu_344_p4 = {{bitcast_ln21_fu_341_p1[62:52]}};

assign trunc_ln21_3_fu_371_p1 = bitcast_ln21_3_fu_358_p1[51:0];

assign trunc_ln21_fu_354_p1 = bitcast_ln21_fu_341_p1[51:0];

assign trunc_ln29_fu_439_p1 = bitcast_ln29_fu_426_p1[51:0];

assign worstOfBestIdx_12_out = worstOfBestIdx_fu_96[4:0];

assign worstOfBestIdx_6_fu_479_p3 = ((and_ln21_3_fu_417_p2[0:0] == 1'b1) ? zext_ln21_fu_423_p1 : worstOfBestIdx_fu_96);

assign worstOfBest_12_out = worstOfBest_fu_92;

assign xor_ln21_fu_487_p2 = (1'd1 ^ and_ln21_3_fu_417_p2);

assign zext_ln21_fu_423_p1 = i_reg_665;

endmodule //kNN_PredictAll_kNN_Predict_4_Pipeline_VITIS_LOOP_17_17
