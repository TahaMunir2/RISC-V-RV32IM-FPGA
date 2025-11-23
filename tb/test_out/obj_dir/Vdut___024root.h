// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"


class Vdut__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdut___024root final : public VerilatedModule {
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
    CData/*6:0*/ top__DOT__control__DOT__op;
    CData/*2:0*/ top__DOT__control__DOT__funct3;
    CData/*6:0*/ top__DOT__control__DOT__funct7;
    CData/*0:0*/ __VstlDidInit;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ __VdfgRegularize_h7cd686f0_0_0;
    VL_OUT(a0,31,0);
    IData/*31:0*/ top__DOT__instr;
    IData/*31:0*/ top__DOT__ImmOp;
    IData/*31:0*/ top__DOT__ALU_OUT;
    IData/*31:0*/ top__DOT__pc_block__DOT__branch_pc;
    IData/*31:0*/ top__DOT__pc_block__DOT__inc_pc;
    IData/*31:0*/ top__DOT__pc_block__DOT__internal_pc;
    IData/*31:0*/ top__DOT__Reg_and_ALU_block__DOT__ALUop1;
    IData/*31:0*/ top__DOT__Reg_and_ALU_block__DOT__ALUop2;
    IData/*31:0*/ top__DOT__Reg_and_ALU_block__DOT__regOp2;
    IData/*31:0*/ top__DOT__Reg_and_ALU_block__DOT__output_DataMem;
    IData/*23:0*/ __VdfgRegularize_h7cd686f0_0_1;
    IData/*31:0*/ __VdfgRegularize_h0dff6736_0_1;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 131072> top__DOT__Instr_Mem__DOT__rom_array;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array;
    VlUnpacked<CData/*7:0*/, 131072> top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array;
    VlUnpacked<IData/*31:0*/, 32> __Vtrigprevexpr___TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__0;
    VlUnpacked<IData/*31:0*/, 32> __Vtrigprevexpr___TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__1;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlTriggerVec<2> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* v__name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
