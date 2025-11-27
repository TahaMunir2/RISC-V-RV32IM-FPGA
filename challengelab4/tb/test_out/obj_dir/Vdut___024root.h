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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*0:0*/ top__DOT__EQ;
        CData/*0:0*/ top__DOT__RegWrite;
        CData/*2:0*/ top__DOT__ALUCtrl;
        CData/*0:0*/ top__DOT__ALUSrc;
        CData/*0:0*/ top__DOT__reg_entry;
        CData/*0:0*/ top__DOT__LT;
        CData/*0:0*/ top__DOT__LTU;
        CData/*1:0*/ top__DOT__ResultSrc;
        CData/*0:0*/ top__DOT__MemWrite;
        CData/*1:0*/ top__DOT__SizeWrite;
        CData/*0:0*/ top__DOT__ALUsrc2;
        CData/*1:0*/ top__DOT__LoadSize;
        CData/*0:0*/ top__DOT__LoadUnsigned;
        CData/*1:0*/ top__DOT__selectline1;
        CData/*1:0*/ top__DOT__selectline2;
        CData/*0:0*/ top__DOT__flush_d_exec;
        CData/*0:0*/ top__DOT__flush_f_d;
        CData/*0:0*/ top__DOT__F_Write;
        CData/*0:0*/ top__DOT__PCWrite;
        CData/*0:0*/ top__DOT__RegWrite_d;
        CData/*1:0*/ top__DOT__ResultSrc_d;
        CData/*0:0*/ top__DOT__MemWrite_d;
        CData/*0:0*/ top__DOT__Jump_d;
        CData/*0:0*/ top__DOT__Branch_d;
        CData/*3:0*/ top__DOT__ALUCtrl_d;
        CData/*0:0*/ top__DOT__ALUSrc_d;
        CData/*1:0*/ top__DOT__SizeWrite_d;
        CData/*1:0*/ top__DOT__LoadSize_d;
        CData/*0:0*/ top__DOT__LoadUnsigned_d;
        CData/*0:0*/ top__DOT__ALUSrc2_d;
        CData/*0:0*/ top__DOT__RegWriteE;
        CData/*1:0*/ top__DOT__ResultSrcE;
        CData/*0:0*/ top__DOT__MemWriteE;
        CData/*0:0*/ top__DOT__Jump_e;
        CData/*0:0*/ top__DOT__Branch_e;
        CData/*3:0*/ top__DOT__ALUCtrl_e;
        CData/*0:0*/ top__DOT__ALUSrc_e;
        CData/*1:0*/ top__DOT__SizeWriteE;
        CData/*1:0*/ top__DOT__LoadSizeE;
        CData/*0:0*/ top__DOT__LoadUnsignedE;
        CData/*0:0*/ top__DOT__ALUSrc2_e;
        CData/*2:0*/ top__DOT__function3_e;
        CData/*0:0*/ top__DOT__PCSrcE;
        CData/*0:0*/ top__DOT__RegWriteM;
        CData/*1:0*/ top__DOT__ResultSrCM;
        CData/*0:0*/ top__DOT__MemWriteM;
        CData/*1:0*/ top__DOT__SizeWriteM;
        CData/*1:0*/ top__DOT__LoadSizeM;
        CData/*0:0*/ top__DOT__LoadUnsignedm;
        CData/*0:0*/ top__DOT__RegWriteW;
        CData/*1:0*/ top__DOT__ResultSrcW;
        CData/*1:0*/ top__DOT____Vcellout__control__PCSrc;
        CData/*2:0*/ top__DOT____Vcellout__control__ImmSrc;
        CData/*0:0*/ top__DOT__WE3;
        CData/*4:0*/ top__DOT__AD3;
        CData/*4:0*/ top__DOT__AD2;
        CData/*4:0*/ top__DOT__AD1;
        CData/*1:0*/ top__DOT__ForwardAE;
        CData/*1:0*/ top__DOT__ForwardBE;
        CData/*1:0*/ top__DOT____Vcellout__em_pipeline__ResultSrc_m;
        CData/*0:0*/ top__DOT__pc_save_e;
        CData/*0:0*/ top__DOT__hazard_unit__DOT__wStall;
    };
    struct {
        CData/*0:0*/ __Vclklast__TOP__clk;
        VL_OUT(a0,31,0);
        IData/*31:0*/ top__DOT__ImmOp;
        IData/*31:0*/ top__DOT__PC;
        IData/*31:0*/ top__DOT__instr_d;
        IData/*31:0*/ top__DOT__output_ALU;
        IData/*31:0*/ top__DOT__ALUop1;
        IData/*31:0*/ top__DOT__ALUop2;
        IData/*31:0*/ top__DOT__regOp2;
        IData/*31:0*/ top__DOT__output_DataMem;
        IData/*31:0*/ top__DOT__write_to_reg;
        IData/*31:0*/ top__DOT__PCD;
        IData/*31:0*/ top__DOT__PCD_save;
        IData/*31:0*/ top__DOT__RD1_d;
        IData/*31:0*/ top__DOT__RD2_d;
        IData/*31:0*/ top__DOT__pc_d;
        IData/*31:0*/ top__DOT__Rd_d;
        IData/*31:0*/ top__DOT__ImmExt_d;
        IData/*31:0*/ top__DOT__PCPlus4dE;
        IData/*31:0*/ top__DOT__RD1_e;
        IData/*31:0*/ top__DOT__RD2_e;
        IData/*31:0*/ top__DOT__pc_e;
        IData/*31:0*/ top__DOT__RdE;
        IData/*31:0*/ top__DOT__ImmExt_e;
        IData/*31:0*/ top__DOT__PCPlus4M;
        IData/*31:0*/ top__DOT__RdM;
        IData/*31:0*/ top__DOT__ALUResultM;
        IData/*31:0*/ top__DOT__WriteDataM;
        IData/*31:0*/ top__DOT__datamem_output;
        IData/*31:0*/ top__DOT__ALUResultW;
        IData/*31:0*/ top__DOT__ReadDataW;
        IData/*31:0*/ top__DOT__RdW;
        IData/*31:0*/ top__DOT__PCPlus4W;
        IData/*31:0*/ top__DOT__ResultW;
        IData/*31:0*/ top__DOT__ALU;
        IData/*31:0*/ top__DOT__WD3;
        IData/*31:0*/ top__DOT__SrcAE;
        IData/*31:0*/ top__DOT__SrcBE;
        IData/*31:0*/ top__DOT__pc_block__DOT__branch_pc;
        IData/*31:0*/ top__DOT__pc_block__DOT__inc_pc;
        IData/*31:0*/ top__DOT__pc_block__DOT__internal_pc;
        IData/*31:0*/ top__DOT__datamem__DOT__unnamedblk1__DOT__data;
        IData/*31:0*/ __Vchglast__TOP__top__DOT__output_ALU;
        VlUnpacked<CData/*7:0*/, 131073> top__DOT__Instr_Mem__DOT__rom_array;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile__DOT__regfile_array;
        VlUnpacked<CData/*7:0*/, 131072> top__DOT__datamem__DOT__ram_array;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };

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
