// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb_H__
#define __rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 52;
  static const unsigned AddressRange = 64;
  static const unsigned AddressWidth = 6;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb_ram) {
        ram[0] = "0b0111111111111111111111111111111111111111111111111111";
        ram[1] = "0b0011111111111111111111111111111111111111111111111111";
        ram[2] = "0b0001111111111111111111111111111111111111111111111111";
        ram[3] = "0b0000111111111111111111111111111111111111111111111111";
        ram[4] = "0b0000011111111111111111111111111111111111111111111111";
        ram[5] = "0b0000001111111111111111111111111111111111111111111111";
        ram[6] = "0b0000000111111111111111111111111111111111111111111111";
        ram[7] = "0b0000000011111111111111111111111111111111111111111111";
        ram[8] = "0b0000000001111111111111111111111111111111111111111111";
        ram[9] = "0b0000000000111111111111111111111111111111111111111111";
        ram[10] = "0b0000000000011111111111111111111111111111111111111111";
        ram[11] = "0b0000000000001111111111111111111111111111111111111111";
        ram[12] = "0b0000000000000111111111111111111111111111111111111111";
        ram[13] = "0b0000000000000011111111111111111111111111111111111111";
        ram[14] = "0b0000000000000001111111111111111111111111111111111111";
        ram[15] = "0b0000000000000000111111111111111111111111111111111111";
        ram[16] = "0b0000000000000000011111111111111111111111111111111111";
        ram[17] = "0b0000000000000000001111111111111111111111111111111111";
        ram[18] = "0b0000000000000000000111111111111111111111111111111111";
        ram[19] = "0b0000000000000000000011111111111111111111111111111111";
        ram[20] = "0b0000000000000000000001111111111111111111111111111111";
        ram[21] = "0b0000000000000000000000111111111111111111111111111111";
        ram[22] = "0b0000000000000000000000011111111111111111111111111111";
        ram[23] = "0b0000000000000000000000001111111111111111111111111111";
        ram[24] = "0b0000000000000000000000000111111111111111111111111111";
        ram[25] = "0b0000000000000000000000000011111111111111111111111111";
        ram[26] = "0b0000000000000000000000000001111111111111111111111111";
        ram[27] = "0b0000000000000000000000000000111111111111111111111111";
        ram[28] = "0b0000000000000000000000000000011111111111111111111111";
        ram[29] = "0b0000000000000000000000000000001111111111111111111111";
        ram[30] = "0b0000000000000000000000000000000111111111111111111111";
        ram[31] = "0b0000000000000000000000000000000011111111111111111111";
        ram[32] = "0b0000000000000000000000000000000001111111111111111111";
        ram[33] = "0b0000000000000000000000000000000000111111111111111111";
        ram[34] = "0b0000000000000000000000000000000000011111111111111111";
        ram[35] = "0b0000000000000000000000000000000000001111111111111111";
        ram[36] = "0b0000000000000000000000000000000000000111111111111111";
        ram[37] = "0b0000000000000000000000000000000000000011111111111111";
        ram[38] = "0b0000000000000000000000000000000000000001111111111111";
        ram[39] = "0b0000000000000000000000000000000000000000111111111111";
        ram[40] = "0b0000000000000000000000000000000000000000011111111111";
        ram[41] = "0b0000000000000000000000000000000000000000001111111111";
        ram[42] = "0b0000000000000000000000000000000000000000000111111111";
        ram[43] = "0b0000000000000000000000000000000000000000000011111111";
        ram[44] = "0b0000000000000000000000000000000000000000000001111111";
        ram[45] = "0b0000000000000000000000000000000000000000000000111111";
        ram[46] = "0b0000000000000000000000000000000000000000000000011111";
        ram[47] = "0b0000000000000000000000000000000000000000000000001111";
        ram[48] = "0b0000000000000000000000000000000000000000000000000111";
        ram[49] = "0b0000000000000000000000000000000000000000000000000011";
        ram[50] = "0b0000000000000000000000000000000000000000000000000001";
        for (unsigned i = 51; i < 62 ; i = i + 1) {
            ram[i] = "0b0000000000000000000000000000000000000000000000000000";
        }
        ram[62] = "0b1111111111111111111111111111111111111111111111111111";
        ram[63] = "0b1111111111111111111111111111111111111111111111111111";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb) {


static const unsigned DataWidth = 52;
static const unsigned AddressRange = 64;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb_ram* meminst;


SC_CTOR(rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb) {
meminst = new rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb_ram("rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~rgbToGrayscale_rgbToGrayscale_Pipeline_VITIS_LOOP_165_1_VITIS_LOOP_167_2_mask_table_ROM_AUTObkb() {
    delete meminst;
}


};//endmodule
#endif
