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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*4:0*/ top__DOT__Rs1E;
        CData/*4:0*/ top__DOT__Rs2E;
        CData/*4:0*/ top__DOT__RdE;
        CData/*1:0*/ top__DOT__ResultSrcD;
        CData/*1:0*/ top__DOT__ResultSrcM;
        CData/*1:0*/ top__DOT__PCSrcD;
        CData/*0:0*/ top__DOT__RegWriteD;
        CData/*0:0*/ top__DOT__EQ;
        CData/*2:0*/ top__DOT__ImmSrcD;
        CData/*0:0*/ top__DOT__LT;
        CData/*0:0*/ top__DOT__LTU;
        CData/*0:0*/ top__DOT__MemWriteD;
        CData/*1:0*/ top__DOT__SizeWriteD;
        CData/*1:0*/ top__DOT__LoadSizeD;
        CData/*0:0*/ top__DOT__LoadUnsignedD;
        CData/*0:0*/ top__DOT__flush_d_exec;
        CData/*0:0*/ top__DOT__flush_f_d;
        CData/*0:0*/ top__DOT__F_Write;
        CData/*0:0*/ top__DOT__PCWrite;
        CData/*3:0*/ top__DOT__ALUCtrlD;
        CData/*0:0*/ top__DOT__ALUSrcD;
        CData/*0:0*/ top__DOT__ALUSrc2D;
        CData/*0:0*/ top__DOT__RegWriteE;
        CData/*1:0*/ top__DOT__ResultSrcE;
        CData/*0:0*/ top__DOT__MemWriteE;
        CData/*3:0*/ top__DOT__ALUCtrlE;
        CData/*0:0*/ top__DOT__ALUSrcE;
        CData/*1:0*/ top__DOT__SizeWriteE;
        CData/*1:0*/ top__DOT__LoadSizeE;
        CData/*0:0*/ top__DOT__LoadUnsignedE;
        CData/*0:0*/ top__DOT__ALUSrc2E;
        CData/*1:0*/ top__DOT__PCSrcE;
        CData/*4:0*/ top__DOT__RdM;
        CData/*0:0*/ top__DOT__RegWriteM;
        CData/*0:0*/ top__DOT__MemWriteM;
        CData/*1:0*/ top__DOT__SizeWriteM;
        CData/*1:0*/ top__DOT__LoadSizeM;
        CData/*0:0*/ top__DOT__LoadUnsignedM;
        CData/*0:0*/ top__DOT__RegWriteW;
        CData/*1:0*/ top__DOT__ResultSrcW;
        CData/*4:0*/ top__DOT__RdW;
        CData/*1:0*/ top__DOT__ForwardAE;
        CData/*1:0*/ top__DOT__ForwardBE;
        CData/*0:0*/ top__DOT__hazard_unit__DOT__wStall;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT(a0,31,0);
        IData/*31:0*/ top__DOT__RD1E;
        IData/*31:0*/ top__DOT__RD2E;
        IData/*31:0*/ top__DOT__ExtImmE;
        IData/*31:0*/ top__DOT__ReadDataM;
        IData/*31:0*/ top__DOT__WriteDataE;
        IData/*31:0*/ top__DOT__InstrD;
        IData/*31:0*/ top__DOT__PCF;
        IData/*31:0*/ top__DOT__PCD;
        IData/*31:0*/ top__DOT__PCE;
        IData/*31:0*/ top__DOT__PCPlus4D;
        IData/*31:0*/ top__DOT__PCPlus4E;
        IData/*31:0*/ top__DOT__ALUResultE;
        IData/*31:0*/ top__DOT__ALUop1;
        IData/*31:0*/ top__DOT__PCPlus4M;
    };
    struct {
        IData/*31:0*/ top__DOT__ALUResultM;
        IData/*31:0*/ top__DOT__WriteDataM;
        IData/*31:0*/ top__DOT__ALUResultW;
        IData/*31:0*/ top__DOT__ReadDataW;
        IData/*31:0*/ top__DOT__PCPlus4W;
        IData/*31:0*/ top__DOT__ResultW;
        IData/*31:0*/ top__DOT__SrcBE;
        IData/*31:0*/ top__DOT__pc_block__DOT__branch_pc;
        IData/*31:0*/ top__DOT__pc_block__DOT__inc_pc;
        IData/*31:0*/ top__DOT__pc_block__DOT__internal_pc;
        IData/*31:0*/ top__DOT__datamem__DOT__unnamedblk1__DOT__data;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*7:0*/, 131072> top__DOT__Instr_Mem__DOT__rom_array;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile__DOT__regfile_array;
        VlUnpacked<CData/*7:0*/, 131072> top__DOT__datamem__DOT__ram_array;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

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
