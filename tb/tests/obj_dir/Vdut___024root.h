// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"

class Vdut__Syms;

class Vdut___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(__pinNumber4,0,0);
    CData/*0:0*/ top__DOT__RegWrite;
    CData/*2:0*/ top__DOT__ALUCtrl;
    CData/*0:0*/ top__DOT__ALUSrc;
    CData/*2:0*/ top__DOT__ImmSrc;
    CData/*1:0*/ top__DOT__PCSrc;
    CData/*0:0*/ top__DOT__MemWrite;
    CData/*0:0*/ top__DOT__ByteWrite;
    CData/*1:0*/ top__DOT__ResultSrc;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_OUT(a0,31,0);
    IData/*31:0*/ top__DOT__instr;
    IData/*31:0*/ top__DOT__ImmOp;
    IData/*31:0*/ top__DOT__pc_block__DOT__branch_pc;
    IData/*31:0*/ top__DOT__pc_block__DOT__inc_pc;
    IData/*31:0*/ top__DOT__pc_block__DOT__internal_pc;
    IData/*31:0*/ top__DOT__Reg_and_ALU_block__DOT__output_ALU;
    IData/*31:0*/ top__DOT__Reg_and_ALU_block__DOT__ALUop1;
    IData/*31:0*/ top__DOT__Reg_and_ALU_block__DOT__ALUop2;
    IData/*31:0*/ top__DOT__Reg_and_ALU_block__DOT__regOp2;
    IData/*31:0*/ top__DOT__Reg_and_ALU_block__DOT__output_DataMem;
    VlUnpacked<CData/*7:0*/, 131072> top__DOT__Instr_Mem__DOT__rom_array;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array;
    VlUnpacked<CData/*7:0*/, 131072> top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array;
    VlUnpacked<IData/*31:0*/, 32> __Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
