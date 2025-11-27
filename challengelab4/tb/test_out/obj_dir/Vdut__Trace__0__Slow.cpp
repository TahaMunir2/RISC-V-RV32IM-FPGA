// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


VL_ATTR_COLD void Vdut___024root__trace_init_sub__TOP__0(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+125,"clk", false,-1);
    tracep->declBit(c+126,"rst", false,-1);
    tracep->declBus(c+127,"a0", false,-1, 31,0);
    tracep->pushNamePrefix("top ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+125,"clk", false,-1);
    tracep->declBit(c+126,"rst", false,-1);
    tracep->declBus(c+127,"a0", false,-1, 31,0);
    tracep->declBus(c+1,"instr", false,-1, 31,0);
    tracep->declBit(c+112,"EQ", false,-1);
    tracep->declBit(c+130,"RegWrite", false,-1);
    tracep->declBus(c+131,"ALUCtrl", false,-1, 2,0);
    tracep->declBit(c+132,"ALUSrc", false,-1);
    tracep->declBus(c+2,"ImmSrc", false,-1, 1,0);
    tracep->declBit(c+113,"PCSrc", false,-1);
    tracep->declBus(c+133,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+3,"PC", false,-1, 31,0);
    tracep->declBus(c+4,"PC_save", false,-1, 31,0);
    tracep->declBit(c+134,"reg_entry", false,-1);
    tracep->declBus(c+5,"instr_d", false,-1, 31,0);
    tracep->declBus(c+114,"output_ALU", false,-1, 31,0);
    tracep->declBus(c+128,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+115,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+6,"regOp2", false,-1, 31,0);
    tracep->declBus(c+7,"output_DataMem", false,-1, 31,0);
    tracep->declBus(c+135,"write_to_reg", false,-1, 31,0);
    tracep->declBit(c+116,"LT", false,-1);
    tracep->declBit(c+117,"LTU", false,-1);
    tracep->declBus(c+8,"ResultSrc", false,-1, 1,0);
    tracep->declBit(c+9,"MemWrite", false,-1);
    tracep->declBus(c+10,"SizeWrite", false,-1, 1,0);
    tracep->declBit(c+11,"ALUsrc2", false,-1);
    tracep->declBus(c+12,"LoadSize", false,-1, 1,0);
    tracep->declBit(c+13,"LoadUnsigned", false,-1);
    tracep->declBus(c+136,"selectline1", false,-1, 1,0);
    tracep->declBus(c+137,"selectline2", false,-1, 1,0);
    tracep->declBit(c+118,"flush_d_exec", false,-1);
    tracep->declBit(c+119,"flush_f_d", false,-1);
    tracep->declBit(c+14,"F_Write", false,-1);
    tracep->declBit(c+15,"PCWrite", false,-1);
    tracep->declBus(c+16,"PCD", false,-1, 31,0);
    tracep->declBus(c+17,"PCD_save", false,-1, 31,0);
    tracep->declBus(c+138,"RD1_d", false,-1, 31,0);
    tracep->declBus(c+139,"RD2_d", false,-1, 31,0);
    tracep->declBus(c+140,"pc_d", false,-1, 31,0);
    tracep->declBus(c+141,"Rd_d", false,-1, 31,0);
    tracep->declBus(c+18,"ImmExt_d", false,-1, 31,0);
    tracep->declBus(c+19,"PCPlus4dE", false,-1, 31,0);
    tracep->declBus(c+20,"RD1_e", false,-1, 31,0);
    tracep->declBus(c+21,"RD2_e", false,-1, 31,0);
    tracep->declBus(c+22,"pc_e", false,-1, 31,0);
    tracep->declBus(c+23,"RdE", false,-1, 31,0);
    tracep->declBus(c+24,"ImmExt_e", false,-1, 31,0);
    tracep->declBit(c+25,"RegWrite_d", false,-1);
    tracep->declBus(c+142,"ResultSrc_d", false,-1, 1,0);
    tracep->declBit(c+143,"MemWrite_d", false,-1);
    tracep->declBit(c+144,"Jump_d", false,-1);
    tracep->declBit(c+26,"Branch_d", false,-1);
    tracep->declBus(c+27,"ALUCtrl_d", false,-1, 3,0);
    tracep->declBit(c+28,"ALUSrc_d", false,-1);
    tracep->declBus(c+145,"SizeWrite_d", false,-1, 1,0);
    tracep->declBus(c+146,"LoadSize_d", false,-1, 1,0);
    tracep->declBit(c+147,"LoadUnsigned_d", false,-1);
    tracep->declBit(c+148,"ALUSrc2_d", false,-1);
    tracep->declBit(c+29,"RegWriteE", false,-1);
    tracep->declBus(c+30,"ResultSrcE", false,-1, 1,0);
    tracep->declBit(c+31,"MemWriteE", false,-1);
    tracep->declBit(c+32,"Jump_e", false,-1);
    tracep->declBit(c+33,"Branch_e", false,-1);
    tracep->declBus(c+34,"ALUCtrl_e", false,-1, 3,0);
    tracep->declBit(c+35,"ALUSrc_e", false,-1);
    tracep->declBus(c+36,"SizeWriteE", false,-1, 1,0);
    tracep->declBus(c+37,"LoadSizeE", false,-1, 1,0);
    tracep->declBit(c+38,"LoadUnsignedE", false,-1);
    tracep->declBit(c+39,"ALUSrc2_e", false,-1);
    tracep->declBit(c+149,"enable_de", false,-1);
    tracep->declBus(c+40,"function3_d", false,-1, 2,0);
    tracep->declBus(c+150,"function3_e", false,-1, 2,0);
    tracep->declBit(c+120,"PCSrcE", false,-1);
    tracep->declBus(c+41,"PCPlus4M", false,-1, 31,0);
    tracep->declBus(c+42,"RdM", false,-1, 31,0);
    tracep->declBus(c+43,"ALUResultM", false,-1, 31,0);
    tracep->declBus(c+44,"WriteDataM", false,-1, 31,0);
    tracep->declBit(c+45,"RegWriteM", false,-1);
    tracep->declBus(c+151,"ResultSrCM", false,-1, 1,0);
    tracep->declBit(c+46,"MemWriteM", false,-1);
    tracep->declBus(c+47,"SizeWriteM", false,-1, 1,0);
    tracep->declBus(c+48,"LoadSizeM", false,-1, 1,0);
    tracep->declBit(c+49,"LoadUnsignedm", false,-1);
    tracep->declBit(c+50,"RegWriteW", false,-1);
    tracep->declBus(c+51,"ResultSrcW", false,-1, 1,0);
    tracep->declBus(c+152,"datamem_output", false,-1, 31,0);
    tracep->declBus(c+52,"ALUResultW", false,-1, 31,0);
    tracep->declBus(c+53,"ReadDataW", false,-1, 31,0);
    tracep->declBus(c+54,"RdW", false,-1, 31,0);
    tracep->declBus(c+55,"PCPlus4W", false,-1, 31,0);
    tracep->declBus(c+56,"ResultW", false,-1, 31,0);
    tracep->declBit(c+57,"ResultSrcM", false,-1);
    tracep->declBus(c+153,"ALU", false,-1, 31,0);
    tracep->declBus(c+154,"WD3", false,-1, 31,0);
    tracep->declBit(c+155,"WE3", false,-1);
    tracep->declBus(c+156,"AD3", false,-1, 4,0);
    tracep->declBus(c+157,"AD2", false,-1, 4,0);
    tracep->declBus(c+158,"AD1", false,-1, 4,0);
    tracep->declBus(c+58,"ForwardAE", false,-1, 1,0);
    tracep->declBus(c+59,"ForwardBE", false,-1, 1,0);
    tracep->declBus(c+121,"SrcAE", false,-1, 31,0);
    tracep->declBus(c+122,"SrcBE", false,-1, 31,0);
    tracep->declBit(c+159,"pc_save_e", false,-1);
    tracep->pushNamePrefix("Instr_Mem ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+3,"addr", false,-1, 31,0);
    tracep->declBus(c+1,"instr", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("PCSource ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+32,"Jump_e", false,-1);
    tracep->declBus(c+150,"funct3", false,-1, 2,0);
    tracep->declBit(c+33,"Branch_e", false,-1);
    tracep->declBit(c+112,"EQ", false,-1);
    tracep->declBit(c+116,"LT", false,-1);
    tracep->declBit(c+117,"LTU", false,-1);
    tracep->declBit(c+120,"PCSrcE", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+128,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+115,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+34,"ALUCtrl", false,-1, 3,0);
    tracep->declBus(c+114,"ALUout", false,-1, 31,0);
    tracep->declBit(c+112,"EQ", false,-1);
    tracep->declBit(c+116,"LT", false,-1);
    tracep->declBit(c+117,"LTU", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("control ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+5,"instr", false,-1, 31,0);
    tracep->declBit(c+112,"EQ", false,-1);
    tracep->declBit(c+116,"LT", false,-1);
    tracep->declBit(c+117,"LTU", false,-1);
    tracep->declBit(c+25,"RegWrite", false,-1);
    tracep->declBus(c+27,"ALUCtrl", false,-1, 3,0);
    tracep->declBit(c+28,"ALUSrc", false,-1);
    tracep->declBus(c+60,"ImmSrc", false,-1, 2,0);
    tracep->declBus(c+123,"PCSrc", false,-1, 1,0);
    tracep->declBus(c+8,"ResultSrc", false,-1, 1,0);
    tracep->declBit(c+9,"MemWrite", false,-1);
    tracep->declBus(c+10,"SizeWrite", false,-1, 1,0);
    tracep->declBit(c+11,"ALUsrc2", false,-1);
    tracep->declBus(c+12,"LoadSize", false,-1, 1,0);
    tracep->declBit(c+13,"LoadUnsigned", false,-1);
    tracep->declBit(c+26,"Branch", false,-1);
    tracep->declBus(c+40,"function3", false,-1, 2,0);
    tracep->declBus(c+61,"op", false,-1, 6,0);
    tracep->declBus(c+40,"funct3", false,-1, 2,0);
    tracep->declBus(c+62,"funct7", false,-1, 6,0);
    tracep->declBus(c+62,"imm_11_5", false,-1, 6,0);
    tracep->declBus(c+160,"OPC_LUI", false,-1, 6,0);
    tracep->declBus(c+161,"OPC_AUIPC", false,-1, 6,0);
    tracep->declBus(c+162,"OPC_JAL", false,-1, 6,0);
    tracep->declBus(c+163,"OPC_JALR", false,-1, 6,0);
    tracep->declBus(c+164,"OPC_BRANCH", false,-1, 6,0);
    tracep->declBus(c+165,"OPC_LOAD", false,-1, 6,0);
    tracep->declBus(c+166,"OPC_STORE", false,-1, 6,0);
    tracep->declBus(c+167,"OPC_OPIMM", false,-1, 6,0);
    tracep->declBus(c+168,"OPC_OP", false,-1, 6,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("datamem ");
    tracep->declBus(c+129,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+9,"MemWrite", false,-1);
    tracep->declBus(c+6,"WD", false,-1, 31,0);
    tracep->declBus(c+10,"SizeWrite", false,-1, 1,0);
    tracep->declBus(c+43,"A", false,-1, 31,0);
    tracep->declBus(c+12,"LoadSize", false,-1, 1,0);
    tracep->declBit(c+13,"LoadUnsigned", false,-1);
    tracep->declBit(c+125,"clk", false,-1);
    tracep->declBus(c+7,"dout", false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+63,"data", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("de_pip ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+125,"clk", false,-1);
    tracep->declBit(c+118,"flush", false,-1);
    tracep->declBit(c+149,"enable", false,-1);
    tracep->declBit(c+126,"rst", false,-1);
    tracep->declBus(c+17,"pc_save_d", false,-1, 31,0);
    tracep->declBus(c+64,"RD1_d", false,-1, 31,0);
    tracep->declBus(c+65,"RD2_d", false,-1, 31,0);
    tracep->declBus(c+16,"pc_d", false,-1, 31,0);
    tracep->declBus(c+66,"Rd_d", false,-1, 31,0);
    tracep->declBus(c+18,"ImmExt_d", false,-1, 31,0);
    tracep->declBus(c+19,"pc_save_e", false,-1, 31,0);
    tracep->declBus(c+20,"RD1_e", false,-1, 31,0);
    tracep->declBus(c+21,"RD2_e", false,-1, 31,0);
    tracep->declBus(c+22,"pc_e", false,-1, 31,0);
    tracep->declBus(c+23,"Rd_e", false,-1, 31,0);
    tracep->declBus(c+24,"ImmExt_e", false,-1, 31,0);
    tracep->declBit(c+25,"RegWrite_d", false,-1);
    tracep->declBus(c+142,"ResultSrc_d", false,-1, 1,0);
    tracep->declBit(c+143,"MemWrite_d", false,-1);
    tracep->declBit(c+144,"Jump_d", false,-1);
    tracep->declBit(c+26,"Branch_d", false,-1);
    tracep->declBus(c+27,"ALUCtrl_d", false,-1, 3,0);
    tracep->declBit(c+28,"ALUSrc_d", false,-1);
    tracep->declBus(c+145,"SizeWrite_d", false,-1, 1,0);
    tracep->declBus(c+146,"LoadSize_d", false,-1, 1,0);
    tracep->declBit(c+147,"LoadUnsigned_d", false,-1);
    tracep->declBit(c+148,"ALUSrc2_d", false,-1);
    tracep->declBit(c+29,"RegWrite_e", false,-1);
    tracep->declBus(c+30,"ResultSrc_e", false,-1, 1,0);
    tracep->declBit(c+31,"MemWrite_e", false,-1);
    tracep->declBit(c+32,"Jump_e", false,-1);
    tracep->declBit(c+33,"Branch_e", false,-1);
    tracep->declBus(c+34,"ALUCtrl_e", false,-1, 3,0);
    tracep->declBit(c+35,"ALUSrc_e", false,-1);
    tracep->declBus(c+36,"SizeWrite_e", false,-1, 1,0);
    tracep->declBus(c+37,"LoadSize_e", false,-1, 1,0);
    tracep->declBit(c+38,"LoadUnsigned_e", false,-1);
    tracep->declBit(c+39,"ALUSrc2_e", false,-1);
    tracep->declBus(c+40,"funct3_d", false,-1, 2,0);
    tracep->declBus(c+150,"funct3_e", false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("em_pipeline ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+125,"clk", false,-1);
    tracep->declBit(c+126,"rst", false,-1);
    tracep->declBus(c+19,"pc_save_e", false,-1, 31,0);
    tracep->declBus(c+23,"Rd_e", false,-1, 31,0);
    tracep->declBus(c+114,"ALU_Result_e", false,-1, 31,0);
    tracep->declBus(c+122,"Write_Data_e", false,-1, 31,0);
    tracep->declBus(c+41,"pc_save_m", false,-1, 31,0);
    tracep->declBus(c+42,"Rd_m", false,-1, 31,0);
    tracep->declBus(c+43,"ALU_Result_m", false,-1, 31,0);
    tracep->declBus(c+44,"Write_Data_m", false,-1, 31,0);
    tracep->declBit(c+29,"RegWrite_e", false,-1);
    tracep->declBus(c+30,"ResultSrc_e", false,-1, 1,0);
    tracep->declBit(c+31,"MemWrite_e", false,-1);
    tracep->declBus(c+36,"SizeWrite_e", false,-1, 1,0);
    tracep->declBus(c+37,"LoadSize_e", false,-1, 1,0);
    tracep->declBit(c+38,"LoadUnsigned_e", false,-1);
    tracep->declBit(c+45,"RegWrite_m", false,-1);
    tracep->declBus(c+67,"ResultSrc_m", false,-1, 1,0);
    tracep->declBit(c+46,"MemWrite_m", false,-1);
    tracep->declBus(c+47,"SizeWrite_m", false,-1, 1,0);
    tracep->declBus(c+48,"LoadSize_m", false,-1, 1,0);
    tracep->declBit(c+49,"LoadUnsigned_m", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("fd_pip ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+125,"clk", false,-1);
    tracep->declBit(c+119,"flush", false,-1);
    tracep->declBit(c+14,"enable", false,-1);
    tracep->declBit(c+126,"rst", false,-1);
    tracep->declBus(c+1,"instr_f", false,-1, 31,0);
    tracep->declBus(c+3,"pc_f", false,-1, 31,0);
    tracep->declBus(c+4,"pc_save_f", false,-1, 31,0);
    tracep->declBus(c+5,"instr_d", false,-1, 31,0);
    tracep->declBus(c+16,"pc_d", false,-1, 31,0);
    tracep->declBus(c+17,"pc_save_d", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("forwardingRS1 ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+114,"in0", false,-1, 31,0);
    tracep->declBus(c+56,"in1", false,-1, 31,0);
    tracep->declBus(c+43,"in2", false,-1, 31,0);
    tracep->declBus(c+114,"in3", false,-1, 31,0);
    tracep->declBus(c+58,"select_line", false,-1, 1,0);
    tracep->declBus(c+121,"out", false,-1, 31,0);
    tracep->pushNamePrefix("muxA ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+114,"in0", false,-1, 31,0);
    tracep->declBus(c+56,"in1", false,-1, 31,0);
    tracep->declBit(c+68,"sel", false,-1);
    tracep->declBus(c+121,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("muxB ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+43,"in0", false,-1, 31,0);
    tracep->declBus(c+114,"in1", false,-1, 31,0);
    tracep->declBit(c+69,"sel", false,-1);
    tracep->declBus(c+121,"out", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("forwardingRS2 ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+114,"in0", false,-1, 31,0);
    tracep->declBus(c+56,"in1", false,-1, 31,0);
    tracep->declBus(c+43,"in2", false,-1, 31,0);
    tracep->declBus(c+114,"in3", false,-1, 31,0);
    tracep->declBus(c+59,"select_line", false,-1, 1,0);
    tracep->declBus(c+122,"out", false,-1, 31,0);
    tracep->pushNamePrefix("muxA ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+114,"in0", false,-1, 31,0);
    tracep->declBus(c+56,"in1", false,-1, 31,0);
    tracep->declBit(c+70,"sel", false,-1);
    tracep->declBus(c+122,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("muxB ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+43,"in0", false,-1, 31,0);
    tracep->declBus(c+114,"in1", false,-1, 31,0);
    tracep->declBit(c+71,"sel", false,-1);
    tracep->declBus(c+122,"out", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("hazard_unit ");
    tracep->declBus(c+169,"reg_addressing_width", false,-1, 31,0);
    tracep->declBus(c+170,"rs1D", false,-1, 4,0);
    tracep->declBus(c+171,"rs2D", false,-1, 4,0);
    tracep->declBus(c+72,"rs1E", false,-1, 4,0);
    tracep->declBus(c+73,"rs2E", false,-1, 4,0);
    tracep->declBus(c+74,"rdM", false,-1, 4,0);
    tracep->declBus(c+75,"rdE", false,-1, 4,0);
    tracep->declBus(c+76,"rdWB", false,-1, 4,0);
    tracep->declBit(c+45,"regWriteM", false,-1);
    tracep->declBus(c+30,"resultSrCE", false,-1, 1,0);
    tracep->declBus(c+77,"resultSrCM", false,-1, 1,0);
    tracep->declBit(c+50,"WriteBack_Regfile", false,-1);
    tracep->declBus(c+58,"selectline1", false,-1, 1,0);
    tracep->declBus(c+59,"selectline2", false,-1, 1,0);
    tracep->declBit(c+118,"flush_d_exec", false,-1);
    tracep->declBit(c+119,"flush_f_d", false,-1);
    tracep->declBit(c+14,"F_Write", false,-1);
    tracep->declBit(c+15,"PCWrite", false,-1);
    tracep->declBit(c+120,"PCSrcE", false,-1);
    tracep->declBit(c+78,"wStall", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mux_immVSreg ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+122,"in0", false,-1, 31,0);
    tracep->declBus(c+133,"in1", false,-1, 31,0);
    tracep->declBit(c+35,"sel", false,-1);
    tracep->declBus(c+115,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mux_pcVSreg ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+121,"in0", false,-1, 31,0);
    tracep->declBus(c+172,"in1", false,-1, 31,0);
    tracep->declBit(c+11,"sel", false,-1);
    tracep->declBus(c+128,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mw_pipeline ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+125,"clk", false,-1);
    tracep->declBit(c+126,"rst", false,-1);
    tracep->declBus(c+41,"pc_save_m", false,-1, 31,0);
    tracep->declBus(c+42,"Rd_m", false,-1, 31,0);
    tracep->declBus(c+43,"ALU_Result_m", false,-1, 31,0);
    tracep->declBus(c+152,"dout_m", false,-1, 31,0);
    tracep->declBus(c+55,"pc_save_w", false,-1, 31,0);
    tracep->declBus(c+54,"Rd_w", false,-1, 31,0);
    tracep->declBus(c+52,"ALU_Result_w", false,-1, 31,0);
    tracep->declBus(c+53,"dout_w", false,-1, 31,0);
    tracep->declBit(c+45,"RegWrite_m", false,-1);
    tracep->declBus(c+77,"ResultSrc_m", false,-1, 1,0);
    tracep->declBit(c+50,"RegWrite_w", false,-1);
    tracep->declBus(c+51,"ResultSrc_w", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_block ");
    tracep->declBus(c+129,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+125,"clk", false,-1);
    tracep->declBit(c+15,"enable", false,-1);
    tracep->declBus(c+133,"Imm_op", false,-1, 31,0);
    tracep->declBus(c+153,"ALU", false,-1, 31,0);
    tracep->declBit(c+126,"rst", false,-1);
    tracep->declBus(c+124,"pc_src", false,-1, 1,0);
    tracep->declBus(c+3,"pc", false,-1, 31,0);
    tracep->declBus(c+4,"pc_save", false,-1, 31,0);
    tracep->declBus(c+79,"branch_pc", false,-1, 31,0);
    tracep->declBus(c+4,"inc_pc", false,-1, 31,0);
    tracep->declBus(c+3,"internal_pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regfile ");
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+129,"REG_FILE_WIDTH", false,-1, 31,0);
    tracep->declBit(c+125,"clk", false,-1);
    tracep->declBus(c+56,"WD3", false,-1, 31,0);
    tracep->declBit(c+155,"WE3", false,-1);
    tracep->declBus(c+156,"AD3", false,-1, 4,0);
    tracep->declBus(c+157,"AD2", false,-1, 4,0);
    tracep->declBus(c+158,"AD1", false,-1, 4,0);
    tracep->declBus(c+128,"RD1", false,-1, 31,0);
    tracep->declBus(c+6,"RD2", false,-1, 31,0);
    tracep->declBus(c+127,"A0", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+80+i*1,"regfile_array", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sign_extension ");
    tracep->declBus(c+173,"IMM_LENGTH", false,-1, 31,0);
    tracep->declBus(c+129,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+5,"instr", false,-1, 31,0);
    tracep->declBus(c+2,"ImmSrc", false,-1, 1,0);
    tracep->declBus(c+18,"immext", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vdut___024root__trace_init_top(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_top\n"); );
    // Body
    Vdut___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdut___024root__trace_register(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vdut___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vdut___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vdut___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdut___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(((((0x20000U >= (0x3ffffU 
                                             & ((IData)(3U) 
                                                + vlSelf->top__DOT__pc_block__DOT__internal_pc)))
                                ? vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                               [(0x3ffffU & ((IData)(3U) 
                                             + vlSelf->top__DOT__pc_block__DOT__internal_pc))]
                                : 0U) << 0x18U) | (
                                                   (((0x20000U 
                                                      >= 
                                                      (0x3ffffU 
                                                       & ((IData)(2U) 
                                                          + vlSelf->top__DOT__pc_block__DOT__internal_pc)))
                                                      ? 
                                                     vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                                     [
                                                     (0x3ffffU 
                                                      & ((IData)(2U) 
                                                         + vlSelf->top__DOT__pc_block__DOT__internal_pc))]
                                                      : 0U) 
                                                    << 0x10U) 
                                                   | ((((0x20000U 
                                                         >= 
                                                         (0x3ffffU 
                                                          & ((IData)(1U) 
                                                             + vlSelf->top__DOT__pc_block__DOT__internal_pc)))
                                                         ? 
                                                        vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                                        [
                                                        (0x3ffffU 
                                                         & ((IData)(1U) 
                                                            + vlSelf->top__DOT__pc_block__DOT__internal_pc))]
                                                         : 0U) 
                                                       << 8U) 
                                                      | ((0x20000U 
                                                          >= 
                                                          (0x3ffffU 
                                                           & vlSelf->top__DOT__pc_block__DOT__internal_pc))
                                                          ? 
                                                         vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                                         [
                                                         (0x3ffffU 
                                                          & vlSelf->top__DOT__pc_block__DOT__internal_pc)]
                                                          : 0U))))),32);
    bufp->fullCData(oldp+2,((3U & (IData)(vlSelf->top__DOT____Vcellout__control__ImmSrc))),2);
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__pc_block__DOT__internal_pc),32);
    bufp->fullIData(oldp+4,(((IData)(4U) + vlSelf->top__DOT__pc_block__DOT__internal_pc)),32);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__instr_d),32);
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__regOp2),32);
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__output_DataMem),32);
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__ResultSrc),2);
    bufp->fullBit(oldp+9,(vlSelf->top__DOT__MemWrite));
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__SizeWrite),2);
    bufp->fullBit(oldp+11,(vlSelf->top__DOT__ALUsrc2));
    bufp->fullCData(oldp+12,(vlSelf->top__DOT__LoadSize),2);
    bufp->fullBit(oldp+13,(vlSelf->top__DOT__LoadUnsigned));
    bufp->fullBit(oldp+14,(vlSelf->top__DOT__F_Write));
    bufp->fullBit(oldp+15,(vlSelf->top__DOT__PCWrite));
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__PCD),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__PCD_save),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__ImmExt_d),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__PCPlus4dE),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__RD1_e),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__RD2_e),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__pc_e),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__RdE),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__ImmExt_e),32);
    bufp->fullBit(oldp+25,(vlSelf->top__DOT__RegWrite_d));
    bufp->fullBit(oldp+26,(vlSelf->top__DOT__Branch_d));
    bufp->fullCData(oldp+27,(vlSelf->top__DOT__ALUCtrl_d),4);
    bufp->fullBit(oldp+28,(vlSelf->top__DOT__ALUSrc_d));
    bufp->fullBit(oldp+29,(vlSelf->top__DOT__RegWriteE));
    bufp->fullCData(oldp+30,(vlSelf->top__DOT__ResultSrcE),2);
    bufp->fullBit(oldp+31,(vlSelf->top__DOT__MemWriteE));
    bufp->fullBit(oldp+32,(vlSelf->top__DOT__Jump_e));
    bufp->fullBit(oldp+33,(vlSelf->top__DOT__Branch_e));
    bufp->fullCData(oldp+34,(vlSelf->top__DOT__ALUCtrl_e),4);
    bufp->fullBit(oldp+35,(vlSelf->top__DOT__ALUSrc_e));
    bufp->fullCData(oldp+36,(vlSelf->top__DOT__SizeWriteE),2);
    bufp->fullCData(oldp+37,(vlSelf->top__DOT__LoadSizeE),2);
    bufp->fullBit(oldp+38,(vlSelf->top__DOT__LoadUnsignedE));
    bufp->fullBit(oldp+39,(vlSelf->top__DOT__ALUSrc2_e));
    bufp->fullCData(oldp+40,((7U & (vlSelf->top__DOT__instr_d 
                                    >> 0xcU))),3);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__PCPlus4M),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__RdM),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__ALUResultM),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__WriteDataM),32);
    bufp->fullBit(oldp+45,(vlSelf->top__DOT__RegWriteM));
    bufp->fullBit(oldp+46,(vlSelf->top__DOT__MemWriteM));
    bufp->fullCData(oldp+47,(vlSelf->top__DOT__SizeWriteM),2);
    bufp->fullCData(oldp+48,(vlSelf->top__DOT__LoadSizeM),2);
    bufp->fullBit(oldp+49,(vlSelf->top__DOT__LoadUnsignedm));
    bufp->fullBit(oldp+50,(vlSelf->top__DOT__RegWriteW));
    bufp->fullCData(oldp+51,(vlSelf->top__DOT__ResultSrcW),2);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__ALUResultW),32);
    bufp->fullIData(oldp+53,(vlSelf->top__DOT__ReadDataW),32);
    bufp->fullIData(oldp+54,(vlSelf->top__DOT__RdW),32);
    bufp->fullIData(oldp+55,(vlSelf->top__DOT__PCPlus4W),32);
    bufp->fullIData(oldp+56,(vlSelf->top__DOT__ResultW),32);
    bufp->fullBit(oldp+57,((1U & (IData)(vlSelf->top__DOT____Vcellout__em_pipeline__ResultSrc_m))));
    bufp->fullCData(oldp+58,(vlSelf->top__DOT__ForwardAE),2);
    bufp->fullCData(oldp+59,(vlSelf->top__DOT__ForwardBE),2);
    bufp->fullCData(oldp+60,(vlSelf->top__DOT____Vcellout__control__ImmSrc),3);
    bufp->fullCData(oldp+61,((0x7fU & vlSelf->top__DOT__instr_d)),7);
    bufp->fullCData(oldp+62,((vlSelf->top__DOT__instr_d 
                              >> 0x19U)),7);
    bufp->fullIData(oldp+63,(vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data),32);
    bufp->fullIData(oldp+64,((0x1fU & (vlSelf->top__DOT__instr_d 
                                       >> 0xfU))),32);
    bufp->fullIData(oldp+65,((0x1fU & (vlSelf->top__DOT__instr_d 
                                       >> 0x14U))),32);
    bufp->fullIData(oldp+66,((0x1fU & (vlSelf->top__DOT__instr_d 
                                       >> 7U))),32);
    bufp->fullCData(oldp+67,(vlSelf->top__DOT____Vcellout__em_pipeline__ResultSrc_m),2);
    bufp->fullBit(oldp+68,((1U & (IData)(vlSelf->top__DOT__ForwardAE))));
    bufp->fullBit(oldp+69,((1U & ((IData)(vlSelf->top__DOT__ForwardAE) 
                                  >> 1U))));
    bufp->fullBit(oldp+70,((1U & (IData)(vlSelf->top__DOT__ForwardBE))));
    bufp->fullBit(oldp+71,((1U & ((IData)(vlSelf->top__DOT__ForwardBE) 
                                  >> 1U))));
    bufp->fullCData(oldp+72,((0x1fU & vlSelf->top__DOT__RD1_e)),5);
    bufp->fullCData(oldp+73,((0x1fU & vlSelf->top__DOT__RD2_e)),5);
    bufp->fullCData(oldp+74,((0x1fU & vlSelf->top__DOT__RdM)),5);
    bufp->fullCData(oldp+75,((0x1fU & vlSelf->top__DOT__RdE)),5);
    bufp->fullCData(oldp+76,((0x1fU & vlSelf->top__DOT__RdW)),5);
    bufp->fullCData(oldp+77,((1U & (IData)(vlSelf->top__DOT____Vcellout__em_pipeline__ResultSrc_m))),2);
    bufp->fullBit(oldp+78,(vlSelf->top__DOT__hazard_unit__DOT__wStall));
    bufp->fullIData(oldp+79,((vlSelf->top__DOT__pc_block__DOT__internal_pc 
                              + vlSelf->top__DOT__ImmOp)),32);
    bufp->fullIData(oldp+80,(vlSelf->top__DOT__regfile__DOT__regfile_array[0]),32);
    bufp->fullIData(oldp+81,(vlSelf->top__DOT__regfile__DOT__regfile_array[1]),32);
    bufp->fullIData(oldp+82,(vlSelf->top__DOT__regfile__DOT__regfile_array[2]),32);
    bufp->fullIData(oldp+83,(vlSelf->top__DOT__regfile__DOT__regfile_array[3]),32);
    bufp->fullIData(oldp+84,(vlSelf->top__DOT__regfile__DOT__regfile_array[4]),32);
    bufp->fullIData(oldp+85,(vlSelf->top__DOT__regfile__DOT__regfile_array[5]),32);
    bufp->fullIData(oldp+86,(vlSelf->top__DOT__regfile__DOT__regfile_array[6]),32);
    bufp->fullIData(oldp+87,(vlSelf->top__DOT__regfile__DOT__regfile_array[7]),32);
    bufp->fullIData(oldp+88,(vlSelf->top__DOT__regfile__DOT__regfile_array[8]),32);
    bufp->fullIData(oldp+89,(vlSelf->top__DOT__regfile__DOT__regfile_array[9]),32);
    bufp->fullIData(oldp+90,(vlSelf->top__DOT__regfile__DOT__regfile_array[10]),32);
    bufp->fullIData(oldp+91,(vlSelf->top__DOT__regfile__DOT__regfile_array[11]),32);
    bufp->fullIData(oldp+92,(vlSelf->top__DOT__regfile__DOT__regfile_array[12]),32);
    bufp->fullIData(oldp+93,(vlSelf->top__DOT__regfile__DOT__regfile_array[13]),32);
    bufp->fullIData(oldp+94,(vlSelf->top__DOT__regfile__DOT__regfile_array[14]),32);
    bufp->fullIData(oldp+95,(vlSelf->top__DOT__regfile__DOT__regfile_array[15]),32);
    bufp->fullIData(oldp+96,(vlSelf->top__DOT__regfile__DOT__regfile_array[16]),32);
    bufp->fullIData(oldp+97,(vlSelf->top__DOT__regfile__DOT__regfile_array[17]),32);
    bufp->fullIData(oldp+98,(vlSelf->top__DOT__regfile__DOT__regfile_array[18]),32);
    bufp->fullIData(oldp+99,(vlSelf->top__DOT__regfile__DOT__regfile_array[19]),32);
    bufp->fullIData(oldp+100,(vlSelf->top__DOT__regfile__DOT__regfile_array[20]),32);
    bufp->fullIData(oldp+101,(vlSelf->top__DOT__regfile__DOT__regfile_array[21]),32);
    bufp->fullIData(oldp+102,(vlSelf->top__DOT__regfile__DOT__regfile_array[22]),32);
    bufp->fullIData(oldp+103,(vlSelf->top__DOT__regfile__DOT__regfile_array[23]),32);
    bufp->fullIData(oldp+104,(vlSelf->top__DOT__regfile__DOT__regfile_array[24]),32);
    bufp->fullIData(oldp+105,(vlSelf->top__DOT__regfile__DOT__regfile_array[25]),32);
    bufp->fullIData(oldp+106,(vlSelf->top__DOT__regfile__DOT__regfile_array[26]),32);
    bufp->fullIData(oldp+107,(vlSelf->top__DOT__regfile__DOT__regfile_array[27]),32);
    bufp->fullIData(oldp+108,(vlSelf->top__DOT__regfile__DOT__regfile_array[28]),32);
    bufp->fullIData(oldp+109,(vlSelf->top__DOT__regfile__DOT__regfile_array[29]),32);
    bufp->fullIData(oldp+110,(vlSelf->top__DOT__regfile__DOT__regfile_array[30]),32);
    bufp->fullIData(oldp+111,(vlSelf->top__DOT__regfile__DOT__regfile_array[31]),32);
    bufp->fullBit(oldp+112,(vlSelf->top__DOT__EQ));
    bufp->fullBit(oldp+113,((1U & (IData)(vlSelf->top__DOT____Vcellout__control__PCSrc))));
    bufp->fullIData(oldp+114,(vlSelf->top__DOT__output_ALU),32);
    bufp->fullIData(oldp+115,(vlSelf->top__DOT__ALUop2),32);
    bufp->fullBit(oldp+116,(vlSelf->top__DOT__LT));
    bufp->fullBit(oldp+117,(vlSelf->top__DOT__LTU));
    bufp->fullBit(oldp+118,(vlSelf->top__DOT__flush_d_exec));
    bufp->fullBit(oldp+119,(vlSelf->top__DOT__flush_f_d));
    bufp->fullBit(oldp+120,(vlSelf->top__DOT__PCSrcE));
    bufp->fullIData(oldp+121,(vlSelf->top__DOT__SrcAE),32);
    bufp->fullIData(oldp+122,(vlSelf->top__DOT__SrcBE),32);
    bufp->fullCData(oldp+123,(vlSelf->top__DOT____Vcellout__control__PCSrc),2);
    bufp->fullCData(oldp+124,(vlSelf->top__DOT__PCSrcE),2);
    bufp->fullBit(oldp+125,(vlSelf->clk));
    bufp->fullBit(oldp+126,(vlSelf->rst));
    bufp->fullIData(oldp+127,(vlSelf->a0),32);
    bufp->fullIData(oldp+128,(vlSelf->top__DOT__ALUop1),32);
    bufp->fullIData(oldp+129,(0x20U),32);
    bufp->fullBit(oldp+130,(vlSelf->top__DOT__RegWrite));
    bufp->fullCData(oldp+131,(vlSelf->top__DOT__ALUCtrl),3);
    bufp->fullBit(oldp+132,(vlSelf->top__DOT__ALUSrc));
    bufp->fullIData(oldp+133,(vlSelf->top__DOT__ImmOp),32);
    bufp->fullBit(oldp+134,(vlSelf->top__DOT__reg_entry));
    bufp->fullIData(oldp+135,(vlSelf->top__DOT__write_to_reg),32);
    bufp->fullCData(oldp+136,(vlSelf->top__DOT__selectline1),2);
    bufp->fullCData(oldp+137,(vlSelf->top__DOT__selectline2),2);
    bufp->fullIData(oldp+138,(vlSelf->top__DOT__RD1_d),32);
    bufp->fullIData(oldp+139,(vlSelf->top__DOT__RD2_d),32);
    bufp->fullIData(oldp+140,(vlSelf->top__DOT__pc_d),32);
    bufp->fullIData(oldp+141,(vlSelf->top__DOT__Rd_d),32);
    bufp->fullCData(oldp+142,(vlSelf->top__DOT__ResultSrc_d),2);
    bufp->fullBit(oldp+143,(vlSelf->top__DOT__MemWrite_d));
    bufp->fullBit(oldp+144,(vlSelf->top__DOT__Jump_d));
    bufp->fullCData(oldp+145,(vlSelf->top__DOT__SizeWrite_d),2);
    bufp->fullCData(oldp+146,(vlSelf->top__DOT__LoadSize_d),2);
    bufp->fullBit(oldp+147,(vlSelf->top__DOT__LoadUnsigned_d));
    bufp->fullBit(oldp+148,(vlSelf->top__DOT__ALUSrc2_d));
    bufp->fullBit(oldp+149,(1U));
    bufp->fullCData(oldp+150,(vlSelf->top__DOT__function3_e),3);
    bufp->fullCData(oldp+151,(vlSelf->top__DOT__ResultSrCM),2);
    bufp->fullIData(oldp+152,(vlSelf->top__DOT__datamem_output),32);
    bufp->fullIData(oldp+153,(vlSelf->top__DOT__ALU),32);
    bufp->fullIData(oldp+154,(vlSelf->top__DOT__WD3),32);
    bufp->fullBit(oldp+155,(vlSelf->top__DOT__WE3));
    bufp->fullCData(oldp+156,(vlSelf->top__DOT__AD3),5);
    bufp->fullCData(oldp+157,(vlSelf->top__DOT__AD2),5);
    bufp->fullCData(oldp+158,(vlSelf->top__DOT__AD1),5);
    bufp->fullBit(oldp+159,(vlSelf->top__DOT__pc_save_e));
    bufp->fullCData(oldp+160,(0x37U),7);
    bufp->fullCData(oldp+161,(0x17U),7);
    bufp->fullCData(oldp+162,(0x6fU),7);
    bufp->fullCData(oldp+163,(0x67U),7);
    bufp->fullCData(oldp+164,(0x63U),7);
    bufp->fullCData(oldp+165,(3U),7);
    bufp->fullCData(oldp+166,(0x23U),7);
    bufp->fullCData(oldp+167,(0x13U),7);
    bufp->fullCData(oldp+168,(0x33U),7);
    bufp->fullIData(oldp+169,(5U),32);
    bufp->fullCData(oldp+170,((0x1fU & vlSelf->top__DOT__RD1_d)),5);
    bufp->fullCData(oldp+171,((0x1fU & vlSelf->top__DOT__RD2_d)),5);
    bufp->fullIData(oldp+172,(vlSelf->top__DOT__pc_save_e),32);
    bufp->fullIData(oldp+173,(0xcU),32);
}
