-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
-- Version: 2022.1
-- Copyright (C) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity kNN_PredictAll_kNN_Predict_4_Pipeline_VITIS_LOOP_17_116 is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    bestDistances_3_123 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_124 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_125 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_126 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_127 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_128 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_129 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_130 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_131 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_132 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_133 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_134 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_135 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_136 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_137 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_138 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_139 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_140 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_141 : IN STD_LOGIC_VECTOR (63 downto 0);
    bestDistances_3_142 : IN STD_LOGIC_VECTOR (63 downto 0);
    secondWorstOfBest_45_out : OUT STD_LOGIC_VECTOR (63 downto 0);
    secondWorstOfBest_45_out_ap_vld : OUT STD_LOGIC;
    worstOfBestIdx_30_out : OUT STD_LOGIC_VECTOR (4 downto 0);
    worstOfBestIdx_30_out_ap_vld : OUT STD_LOGIC;
    worstOfBest_30_out : OUT STD_LOGIC_VECTOR (63 downto 0);
    worstOfBest_30_out_ap_vld : OUT STD_LOGIC;
    grp_fu_75624_p_din0 : OUT STD_LOGIC_VECTOR (63 downto 0);
    grp_fu_75624_p_din1 : OUT STD_LOGIC_VECTOR (63 downto 0);
    grp_fu_75624_p_opcode : OUT STD_LOGIC_VECTOR (4 downto 0);
    grp_fu_75624_p_dout0 : IN STD_LOGIC_VECTOR (0 downto 0);
    grp_fu_75624_p_ce : OUT STD_LOGIC;
    grp_fu_75628_p_din0 : OUT STD_LOGIC_VECTOR (63 downto 0);
    grp_fu_75628_p_din1 : OUT STD_LOGIC_VECTOR (63 downto 0);
    grp_fu_75628_p_opcode : OUT STD_LOGIC_VECTOR (4 downto 0);
    grp_fu_75628_p_dout0 : IN STD_LOGIC_VECTOR (0 downto 0);
    grp_fu_75628_p_ce : OUT STD_LOGIC );
end;


architecture behav of kNN_PredictAll_kNN_Predict_4_Pipeline_VITIS_LOOP_17_116 is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_pp0_stage0 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_boolean_0 : BOOLEAN := false;
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv64_0 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000";
    constant ap_const_lv32_FFFFFFFF : STD_LOGIC_VECTOR (31 downto 0) := "11111111111111111111111111111111";
    constant ap_const_lv5_0 : STD_LOGIC_VECTOR (4 downto 0) := "00000";
    constant ap_const_lv5_14 : STD_LOGIC_VECTOR (4 downto 0) := "10100";
    constant ap_const_lv5_1 : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    constant ap_const_lv32_34 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000110100";
    constant ap_const_lv32_3E : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000111110";
    constant ap_const_lv11_7FF : STD_LOGIC_VECTOR (10 downto 0) := "11111111111";
    constant ap_const_lv52_0 : STD_LOGIC_VECTOR (51 downto 0) := "0000000000000000000000000000000000000000000000000000";
    constant ap_const_lv5_4 : STD_LOGIC_VECTOR (4 downto 0) := "00100";

attribute shreg_extract : string;
    signal ap_CS_fsm : STD_LOGIC_VECTOR (0 downto 0) := "1";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_pp0_stage0 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp0_stage0 : signal is "none";
    signal ap_enable_reg_pp0_iter0 : STD_LOGIC;
    signal ap_enable_reg_pp0_iter1 : STD_LOGIC := '0';
    signal ap_enable_reg_pp0_iter2 : STD_LOGIC := '0';
    signal ap_idle_pp0 : STD_LOGIC;
    signal ap_block_state1_pp0_stage0_iter0 : BOOLEAN;
    signal ap_block_state2_pp0_stage0_iter1 : BOOLEAN;
    signal ap_block_state3_pp0_stage0_iter2 : BOOLEAN;
    signal ap_block_pp0_stage0_subdone : BOOLEAN;
    signal icmp_ln17_fu_280_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_condition_exit_pp0_iter1_stage0 : STD_LOGIC;
    signal ap_loop_exit_ready : STD_LOGIC;
    signal ap_ready_int : STD_LOGIC;
    signal ap_block_pp0_stage0_11001 : BOOLEAN;
    signal i_reg_665 : STD_LOGIC_VECTOR (4 downto 0);
    signal icmp_ln17_reg_670 : STD_LOGIC_VECTOR (0 downto 0);
    signal worstOfBest_load_7_reg_674 : STD_LOGIC_VECTOR (63 downto 0);
    signal secondWorstOfBest_load_4_reg_682 : STD_LOGIC_VECTOR (63 downto 0);
    signal secondWorstOfBest_32_fu_300_p22 : STD_LOGIC_VECTOR (63 downto 0);
    signal secondWorstOfBest_32_reg_689 : STD_LOGIC_VECTOR (63 downto 0);
    signal worstOfBest_fu_92 : STD_LOGIC_VECTOR (63 downto 0);
    signal secondWorstOfBest_36_fu_473_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_sig_allocacmp_worstOfBest_load_7 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_block_pp0_stage0 : BOOLEAN;
    signal ap_loop_init : STD_LOGIC;
    signal worstOfBestIdx_fu_96 : STD_LOGIC_VECTOR (31 downto 0);
    signal worstOfBestIdx_14_fu_479_p3 : STD_LOGIC_VECTOR (31 downto 0);
    signal secondWorstOfBest_fu_100 : STD_LOGIC_VECTOR (63 downto 0);
    signal secondWorstOfBest_35_fu_505_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_sig_allocacmp_secondWorstOfBest_load_4 : STD_LOGIC_VECTOR (63 downto 0);
    signal secondWorstOfBestIdx_fu_104 : STD_LOGIC_VECTOR (4 downto 0);
    signal add_ln17_fu_286_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal ap_block_pp0_stage0_01001 : BOOLEAN;
    signal bitcast_ln21_fu_341_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal bitcast_ln21_7_fu_358_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_s_fu_344_p4 : STD_LOGIC_VECTOR (10 downto 0);
    signal trunc_ln21_fu_354_p1 : STD_LOGIC_VECTOR (51 downto 0);
    signal icmp_ln21_16_fu_381_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln21_fu_375_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_33_fu_361_p4 : STD_LOGIC_VECTOR (10 downto 0);
    signal trunc_ln21_9_fu_371_p1 : STD_LOGIC_VECTOR (51 downto 0);
    signal icmp_ln21_18_fu_399_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln21_17_fu_393_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal or_ln21_7_fu_405_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal and_ln21_fu_411_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal or_ln21_fu_387_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal bitcast_ln29_fu_426_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_35_fu_429_p4 : STD_LOGIC_VECTOR (10 downto 0);
    signal trunc_ln29_fu_439_p1 : STD_LOGIC_VECTOR (51 downto 0);
    signal icmp_ln29_7_fu_449_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln29_fu_443_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal or_ln29_fu_455_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal and_ln29_fu_461_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal and_ln21_7_fu_417_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal zext_ln21_fu_423_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal and_ln29_11_fu_467_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal xor_ln21_fu_487_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal and_ln29_12_fu_493_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal secondWorstOfBest_34_fu_499_p3 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_block_pp0_stage0_00001 : BOOLEAN;
    signal ap_done_reg : STD_LOGIC := '0';
    signal ap_continue_int : STD_LOGIC;
    signal ap_done_int : STD_LOGIC;
    signal ap_loop_exit_ready_pp0_iter2_reg : STD_LOGIC;
    signal ap_NS_fsm : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_enable_pp0 : STD_LOGIC;
    signal ap_start_int : STD_LOGIC;
    signal ap_ce_reg : STD_LOGIC;

    component kNN_PredictAll_dcmp_64ns_64ns_1_2_no_dsp_1 IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (63 downto 0);
        din1 : IN STD_LOGIC_VECTOR (63 downto 0);
        ce : IN STD_LOGIC;
        opcode : IN STD_LOGIC_VECTOR (4 downto 0);
        dout : OUT STD_LOGIC_VECTOR (0 downto 0) );
    end component;


    component kNN_PredictAll_mux_205_64_1_1 IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        din2_WIDTH : INTEGER;
        din3_WIDTH : INTEGER;
        din4_WIDTH : INTEGER;
        din5_WIDTH : INTEGER;
        din6_WIDTH : INTEGER;
        din7_WIDTH : INTEGER;
        din8_WIDTH : INTEGER;
        din9_WIDTH : INTEGER;
        din10_WIDTH : INTEGER;
        din11_WIDTH : INTEGER;
        din12_WIDTH : INTEGER;
        din13_WIDTH : INTEGER;
        din14_WIDTH : INTEGER;
        din15_WIDTH : INTEGER;
        din16_WIDTH : INTEGER;
        din17_WIDTH : INTEGER;
        din18_WIDTH : INTEGER;
        din19_WIDTH : INTEGER;
        din20_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        din0 : IN STD_LOGIC_VECTOR (63 downto 0);
        din1 : IN STD_LOGIC_VECTOR (63 downto 0);
        din2 : IN STD_LOGIC_VECTOR (63 downto 0);
        din3 : IN STD_LOGIC_VECTOR (63 downto 0);
        din4 : IN STD_LOGIC_VECTOR (63 downto 0);
        din5 : IN STD_LOGIC_VECTOR (63 downto 0);
        din6 : IN STD_LOGIC_VECTOR (63 downto 0);
        din7 : IN STD_LOGIC_VECTOR (63 downto 0);
        din8 : IN STD_LOGIC_VECTOR (63 downto 0);
        din9 : IN STD_LOGIC_VECTOR (63 downto 0);
        din10 : IN STD_LOGIC_VECTOR (63 downto 0);
        din11 : IN STD_LOGIC_VECTOR (63 downto 0);
        din12 : IN STD_LOGIC_VECTOR (63 downto 0);
        din13 : IN STD_LOGIC_VECTOR (63 downto 0);
        din14 : IN STD_LOGIC_VECTOR (63 downto 0);
        din15 : IN STD_LOGIC_VECTOR (63 downto 0);
        din16 : IN STD_LOGIC_VECTOR (63 downto 0);
        din17 : IN STD_LOGIC_VECTOR (63 downto 0);
        din18 : IN STD_LOGIC_VECTOR (63 downto 0);
        din19 : IN STD_LOGIC_VECTOR (63 downto 0);
        din20 : IN STD_LOGIC_VECTOR (4 downto 0);
        dout : OUT STD_LOGIC_VECTOR (63 downto 0) );
    end component;


    component kNN_PredictAll_flow_control_loop_pipe_sequential_init IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_start_int : OUT STD_LOGIC;
        ap_loop_init : OUT STD_LOGIC;
        ap_ready_int : IN STD_LOGIC;
        ap_loop_exit_ready : IN STD_LOGIC;
        ap_loop_exit_done : IN STD_LOGIC;
        ap_continue_int : OUT STD_LOGIC;
        ap_done_int : IN STD_LOGIC );
    end component;



begin
    mux_205_64_1_1_U443 : component kNN_PredictAll_mux_205_64_1_1
    generic map (
        ID => 1,
        NUM_STAGE => 1,
        din0_WIDTH => 64,
        din1_WIDTH => 64,
        din2_WIDTH => 64,
        din3_WIDTH => 64,
        din4_WIDTH => 64,
        din5_WIDTH => 64,
        din6_WIDTH => 64,
        din7_WIDTH => 64,
        din8_WIDTH => 64,
        din9_WIDTH => 64,
        din10_WIDTH => 64,
        din11_WIDTH => 64,
        din12_WIDTH => 64,
        din13_WIDTH => 64,
        din14_WIDTH => 64,
        din15_WIDTH => 64,
        din16_WIDTH => 64,
        din17_WIDTH => 64,
        din18_WIDTH => 64,
        din19_WIDTH => 64,
        din20_WIDTH => 5,
        dout_WIDTH => 64)
    port map (
        din0 => bestDistances_3_123,
        din1 => bestDistances_3_124,
        din2 => bestDistances_3_125,
        din3 => bestDistances_3_126,
        din4 => bestDistances_3_127,
        din5 => bestDistances_3_128,
        din6 => bestDistances_3_129,
        din7 => bestDistances_3_130,
        din8 => bestDistances_3_131,
        din9 => bestDistances_3_132,
        din10 => bestDistances_3_133,
        din11 => bestDistances_3_134,
        din12 => bestDistances_3_135,
        din13 => bestDistances_3_136,
        din14 => bestDistances_3_137,
        din15 => bestDistances_3_138,
        din16 => bestDistances_3_139,
        din17 => bestDistances_3_140,
        din18 => bestDistances_3_141,
        din19 => bestDistances_3_142,
        din20 => secondWorstOfBestIdx_fu_104,
        dout => secondWorstOfBest_32_fu_300_p22);

    flow_control_loop_pipe_sequential_init_U : component kNN_PredictAll_flow_control_loop_pipe_sequential_init
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => ap_start,
        ap_ready => ap_ready,
        ap_done => ap_done,
        ap_start_int => ap_start_int,
        ap_loop_init => ap_loop_init,
        ap_ready_int => ap_ready_int,
        ap_loop_exit_ready => ap_condition_exit_pp0_iter1_stage0,
        ap_loop_exit_done => ap_done_int,
        ap_continue_int => ap_continue_int,
        ap_done_int => ap_done_int);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_pp0_stage0;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    ap_done_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_done_reg <= ap_const_logic_0;
            else
                if ((ap_continue_int = ap_const_logic_1)) then 
                    ap_done_reg <= ap_const_logic_0;
                elsif (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_loop_exit_ready_pp0_iter2_reg = ap_const_logic_1))) then 
                    ap_done_reg <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter1_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter1 <= ap_const_logic_0;
            else
                if ((ap_const_logic_1 = ap_condition_exit_pp0_iter1_stage0)) then 
                    ap_enable_reg_pp0_iter1 <= ap_const_logic_0;
                elsif (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
                    ap_enable_reg_pp0_iter1 <= ap_start_int;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter2_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter2 <= ap_const_logic_0;
            else
                if ((ap_const_boolean_0 = ap_block_pp0_stage0_subdone)) then 
                    ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
                end if; 
            end if;
        end if;
    end process;


    ap_loop_exit_ready_pp0_iter2_reg_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_loop_exit_ready = ap_const_logic_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone))) then 
                ap_loop_exit_ready_pp0_iter2_reg <= ap_const_logic_0;
            elsif (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
                ap_loop_exit_ready_pp0_iter2_reg <= ap_loop_exit_ready;
            end if; 
        end if;
    end process;

    secondWorstOfBestIdx_fu_104_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                if ((ap_loop_init = ap_const_logic_1)) then 
                    secondWorstOfBestIdx_fu_104 <= ap_const_lv5_0;
                elsif (((icmp_ln17_fu_280_p2 = ap_const_lv1_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then 
                    secondWorstOfBestIdx_fu_104 <= add_ln17_fu_286_p2;
                end if;
            end if; 
        end if;
    end process;

    secondWorstOfBest_fu_100_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_boolean_0 = ap_block_pp0_stage0_11001)) then
                if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
                    secondWorstOfBest_fu_100 <= ap_const_lv64_0;
                elsif (((ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (icmp_ln17_reg_670 = ap_const_lv1_0))) then 
                    secondWorstOfBest_fu_100 <= secondWorstOfBest_35_fu_505_p3;
                end if;
            end if; 
        end if;
    end process;

    worstOfBestIdx_fu_96_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_boolean_0 = ap_block_pp0_stage0_11001)) then
                if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
                    worstOfBestIdx_fu_96 <= ap_const_lv32_FFFFFFFF;
                elsif (((ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (icmp_ln17_reg_670 = ap_const_lv1_0))) then 
                    worstOfBestIdx_fu_96 <= worstOfBestIdx_14_fu_479_p3;
                end if;
            end if; 
        end if;
    end process;

    worstOfBest_fu_92_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_boolean_0 = ap_block_pp0_stage0_11001)) then
                if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_loop_init = ap_const_logic_1))) then 
                    worstOfBest_fu_92 <= ap_const_lv64_0;
                elsif (((ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (icmp_ln17_reg_670 = ap_const_lv1_0))) then 
                    worstOfBest_fu_92 <= secondWorstOfBest_36_fu_473_p3;
                end if;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                i_reg_665 <= secondWorstOfBestIdx_fu_104;
                icmp_ln17_reg_670 <= icmp_ln17_fu_280_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln17_fu_280_p2 = ap_const_lv1_0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then
                secondWorstOfBest_32_reg_689 <= secondWorstOfBest_32_fu_300_p22;
                secondWorstOfBest_load_4_reg_682 <= ap_sig_allocacmp_secondWorstOfBest_load_4;
                worstOfBest_load_7_reg_674 <= ap_sig_allocacmp_worstOfBest_load_7;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_CS_fsm)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_pp0_stage0 => 
                ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
            when others =>  
                ap_NS_fsm <= "X";
        end case;
    end process;
    add_ln17_fu_286_p2 <= std_logic_vector(unsigned(secondWorstOfBestIdx_fu_104) + unsigned(ap_const_lv5_1));
    and_ln21_7_fu_417_p2 <= (or_ln21_fu_387_p2 and and_ln21_fu_411_p2);
    and_ln21_fu_411_p2 <= (or_ln21_7_fu_405_p2 and grp_fu_75624_p_dout0);
    and_ln29_11_fu_467_p2 <= (grp_fu_75628_p_dout0 and and_ln29_fu_461_p2);
    and_ln29_12_fu_493_p2 <= (xor_ln21_fu_487_p2 and and_ln29_11_fu_467_p2);
    and_ln29_fu_461_p2 <= (or_ln29_fu_455_p2 and or_ln21_7_fu_405_p2);
    ap_CS_fsm_pp0_stage0 <= ap_CS_fsm(0);
        ap_block_pp0_stage0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_00001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_01001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_11001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_subdone <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state1_pp0_stage0_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state2_pp0_stage0_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state3_pp0_stage0_iter2 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_condition_exit_pp0_iter1_stage0_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter1, ap_block_pp0_stage0_subdone, icmp_ln17_fu_280_p2)
    begin
        if (((icmp_ln17_fu_280_p2 = ap_const_lv1_1) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            ap_condition_exit_pp0_iter1_stage0 <= ap_const_logic_1;
        else 
            ap_condition_exit_pp0_iter1_stage0 <= ap_const_logic_0;
        end if; 
    end process;


    ap_done_int_assign_proc : process(ap_block_pp0_stage0_subdone, ap_done_reg, ap_loop_exit_ready_pp0_iter2_reg)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_loop_exit_ready_pp0_iter2_reg = ap_const_logic_1))) then 
            ap_done_int <= ap_const_logic_1;
        else 
            ap_done_int <= ap_done_reg;
        end if; 
    end process;

    ap_enable_pp0 <= (ap_idle_pp0 xor ap_const_logic_1);
    ap_enable_reg_pp0_iter0 <= ap_start_int;

    ap_idle_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_idle_pp0, ap_start_int)
    begin
        if (((ap_start_int = ap_const_logic_0) and (ap_idle_pp0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_pp0_assign_proc : process(ap_enable_reg_pp0_iter0, ap_enable_reg_pp0_iter1, ap_enable_reg_pp0_iter2)
    begin
        if (((ap_enable_reg_pp0_iter2 = ap_const_logic_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0) and (ap_enable_reg_pp0_iter0 = ap_const_logic_0))) then 
            ap_idle_pp0 <= ap_const_logic_1;
        else 
            ap_idle_pp0 <= ap_const_logic_0;
        end if; 
    end process;

    ap_loop_exit_ready <= ap_condition_exit_pp0_iter1_stage0;

    ap_ready_int_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0, ap_block_pp0_stage0_subdone)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0))) then 
            ap_ready_int <= ap_const_logic_1;
        else 
            ap_ready_int <= ap_const_logic_0;
        end if; 
    end process;


    ap_sig_allocacmp_secondWorstOfBest_load_4_assign_proc : process(ap_enable_reg_pp0_iter2, icmp_ln17_reg_670, ap_block_pp0_stage0, secondWorstOfBest_fu_100, secondWorstOfBest_35_fu_505_p3)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (icmp_ln17_reg_670 = ap_const_lv1_0))) then 
            ap_sig_allocacmp_secondWorstOfBest_load_4 <= secondWorstOfBest_35_fu_505_p3;
        else 
            ap_sig_allocacmp_secondWorstOfBest_load_4 <= secondWorstOfBest_fu_100;
        end if; 
    end process;


    ap_sig_allocacmp_worstOfBest_load_7_assign_proc : process(ap_enable_reg_pp0_iter2, icmp_ln17_reg_670, worstOfBest_fu_92, secondWorstOfBest_36_fu_473_p3, ap_block_pp0_stage0)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_1) and (icmp_ln17_reg_670 = ap_const_lv1_0))) then 
            ap_sig_allocacmp_worstOfBest_load_7 <= secondWorstOfBest_36_fu_473_p3;
        else 
            ap_sig_allocacmp_worstOfBest_load_7 <= worstOfBest_fu_92;
        end if; 
    end process;

    bitcast_ln21_7_fu_358_p1 <= secondWorstOfBest_32_reg_689;
    bitcast_ln21_fu_341_p1 <= worstOfBest_load_7_reg_674;
    bitcast_ln29_fu_426_p1 <= secondWorstOfBest_load_4_reg_682;
    grp_fu_75624_p_ce <= ap_const_logic_1;
    grp_fu_75624_p_din0 <= ap_sig_allocacmp_worstOfBest_load_7;
    grp_fu_75624_p_din1 <= secondWorstOfBest_32_fu_300_p22;
    grp_fu_75624_p_opcode <= ap_const_lv5_4;
    grp_fu_75628_p_ce <= ap_const_logic_1;
    grp_fu_75628_p_din0 <= ap_sig_allocacmp_secondWorstOfBest_load_4;
    grp_fu_75628_p_din1 <= secondWorstOfBest_32_fu_300_p22;
    grp_fu_75628_p_opcode <= ap_const_lv5_4;
    icmp_ln17_fu_280_p2 <= "1" when (secondWorstOfBestIdx_fu_104 = ap_const_lv5_14) else "0";
    icmp_ln21_16_fu_381_p2 <= "1" when (trunc_ln21_fu_354_p1 = ap_const_lv52_0) else "0";
    icmp_ln21_17_fu_393_p2 <= "0" when (tmp_33_fu_361_p4 = ap_const_lv11_7FF) else "1";
    icmp_ln21_18_fu_399_p2 <= "1" when (trunc_ln21_9_fu_371_p1 = ap_const_lv52_0) else "0";
    icmp_ln21_fu_375_p2 <= "0" when (tmp_s_fu_344_p4 = ap_const_lv11_7FF) else "1";
    icmp_ln29_7_fu_449_p2 <= "1" when (trunc_ln29_fu_439_p1 = ap_const_lv52_0) else "0";
    icmp_ln29_fu_443_p2 <= "0" when (tmp_35_fu_429_p4 = ap_const_lv11_7FF) else "1";
    or_ln21_7_fu_405_p2 <= (icmp_ln21_18_fu_399_p2 or icmp_ln21_17_fu_393_p2);
    or_ln21_fu_387_p2 <= (icmp_ln21_fu_375_p2 or icmp_ln21_16_fu_381_p2);
    or_ln29_fu_455_p2 <= (icmp_ln29_fu_443_p2 or icmp_ln29_7_fu_449_p2);
    secondWorstOfBest_34_fu_499_p3 <= 
        secondWorstOfBest_32_reg_689 when (and_ln29_12_fu_493_p2(0) = '1') else 
        secondWorstOfBest_load_4_reg_682;
    secondWorstOfBest_35_fu_505_p3 <= 
        worstOfBest_load_7_reg_674 when (and_ln21_7_fu_417_p2(0) = '1') else 
        secondWorstOfBest_34_fu_499_p3;
    secondWorstOfBest_36_fu_473_p3 <= 
        secondWorstOfBest_32_reg_689 when (and_ln21_7_fu_417_p2(0) = '1') else 
        worstOfBest_load_7_reg_674;
    secondWorstOfBest_45_out <= secondWorstOfBest_fu_100;

    secondWorstOfBest_45_out_ap_vld_assign_proc : process(ap_block_pp0_stage0_11001, icmp_ln17_reg_670)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (icmp_ln17_reg_670 = ap_const_lv1_1))) then 
            secondWorstOfBest_45_out_ap_vld <= ap_const_logic_1;
        else 
            secondWorstOfBest_45_out_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    tmp_33_fu_361_p4 <= bitcast_ln21_7_fu_358_p1(62 downto 52);
    tmp_35_fu_429_p4 <= bitcast_ln29_fu_426_p1(62 downto 52);
    tmp_s_fu_344_p4 <= bitcast_ln21_fu_341_p1(62 downto 52);
    trunc_ln21_9_fu_371_p1 <= bitcast_ln21_7_fu_358_p1(52 - 1 downto 0);
    trunc_ln21_fu_354_p1 <= bitcast_ln21_fu_341_p1(52 - 1 downto 0);
    trunc_ln29_fu_439_p1 <= bitcast_ln29_fu_426_p1(52 - 1 downto 0);
    worstOfBestIdx_14_fu_479_p3 <= 
        zext_ln21_fu_423_p1 when (and_ln21_7_fu_417_p2(0) = '1') else 
        worstOfBestIdx_fu_96;
    worstOfBestIdx_30_out <= worstOfBestIdx_fu_96(5 - 1 downto 0);

    worstOfBestIdx_30_out_ap_vld_assign_proc : process(ap_block_pp0_stage0_11001, icmp_ln17_reg_670)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (icmp_ln17_reg_670 = ap_const_lv1_1))) then 
            worstOfBestIdx_30_out_ap_vld <= ap_const_logic_1;
        else 
            worstOfBestIdx_30_out_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    worstOfBest_30_out <= worstOfBest_fu_92;

    worstOfBest_30_out_ap_vld_assign_proc : process(ap_block_pp0_stage0_11001, icmp_ln17_reg_670)
    begin
        if (((ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (icmp_ln17_reg_670 = ap_const_lv1_1))) then 
            worstOfBest_30_out_ap_vld <= ap_const_logic_1;
        else 
            worstOfBest_30_out_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    xor_ln21_fu_487_p2 <= (ap_const_lv1_1 xor and_ln21_7_fu_417_p2);
    zext_ln21_fu_423_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i_reg_665),32));
end behav;
