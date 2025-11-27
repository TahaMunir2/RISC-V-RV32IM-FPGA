// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_INLINE_OPT void Vdut___024root___sequent__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__regfile__DOT__regfile_array__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__regfile__DOT__regfile_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__regfile__DOT__regfile_array__v0;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__datamem__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__datamem__DOT__ram_array__v0;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__datamem__DOT__ram_array__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__datamem__DOT__ram_array__v1;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__datamem__DOT__ram_array__v2;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__datamem__DOT__ram_array__v3;
    CData/*0:0*/ __Vdlyvset__top__DOT__datamem__DOT__ram_array__v3;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v4;
    CData/*7:0*/ __Vdlyvval__top__DOT__datamem__DOT__ram_array__v4;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v5;
    CData/*7:0*/ __Vdlyvval__top__DOT__datamem__DOT__ram_array__v5;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v6;
    CData/*7:0*/ __Vdlyvval__top__DOT__datamem__DOT__ram_array__v6;
    // Body
    __Vdlyvset__top__DOT__regfile__DOT__regfile_array__v0 = 0U;
    __Vdlyvset__top__DOT__datamem__DOT__ram_array__v0 = 0U;
    __Vdlyvset__top__DOT__datamem__DOT__ram_array__v1 = 0U;
    __Vdlyvset__top__DOT__datamem__DOT__ram_array__v3 = 0U;
    vlSelf->top__DOT__LoadUnsignedm = ((~ (IData)(vlSelf->rst)) 
                                       & (IData)(vlSelf->top__DOT__LoadUnsignedE));
    vlSelf->top__DOT__MemWriteM = ((~ (IData)(vlSelf->rst)) 
                                   & (IData)(vlSelf->top__DOT__MemWriteE));
    vlSelf->top__DOT__Jump_e = ((~ (IData)(vlSelf->rst)) 
                                & ((~ (IData)(vlSelf->top__DOT__flush_d_exec)) 
                                   & (IData)(vlSelf->top__DOT__Jump_d)));
    vlSelf->top__DOT__Branch_e = ((~ (IData)(vlSelf->rst)) 
                                  & ((~ (IData)(vlSelf->top__DOT__flush_d_exec)) 
                                     & (IData)(vlSelf->top__DOT__Branch_d)));
    if (vlSelf->top__DOT__WE3) {
        __Vdlyvval__top__DOT__regfile__DOT__regfile_array__v0 
            = vlSelf->top__DOT__ResultW;
        __Vdlyvset__top__DOT__regfile__DOT__regfile_array__v0 = 1U;
        __Vdlyvdim0__top__DOT__regfile__DOT__regfile_array__v0 
            = vlSelf->top__DOT__AD3;
    }
    if (vlSelf->top__DOT__MemWrite) {
        if ((0U == (IData)(vlSelf->top__DOT__SizeWrite))) {
            __Vdlyvval__top__DOT__datamem__DOT__ram_array__v0 
                = (0xffU & vlSelf->top__DOT__regOp2);
            __Vdlyvset__top__DOT__datamem__DOT__ram_array__v0 = 1U;
            __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v0 
                = (0x1ffffU & vlSelf->top__DOT__ALUResultM);
        } else if ((1U == (IData)(vlSelf->top__DOT__SizeWrite))) {
            __Vdlyvval__top__DOT__datamem__DOT__ram_array__v1 
                = (0xffU & vlSelf->top__DOT__regOp2);
            __Vdlyvset__top__DOT__datamem__DOT__ram_array__v1 = 1U;
            __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v1 
                = (0x1ffffU & vlSelf->top__DOT__ALUResultM);
            __Vdlyvval__top__DOT__datamem__DOT__ram_array__v2 
                = (0xffU & (vlSelf->top__DOT__regOp2 
                            >> 8U));
            __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v2 
                = (0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__ALUResultM));
        } else if ((2U == (IData)(vlSelf->top__DOT__SizeWrite))) {
            __Vdlyvval__top__DOT__datamem__DOT__ram_array__v3 
                = (0xffU & vlSelf->top__DOT__regOp2);
            __Vdlyvset__top__DOT__datamem__DOT__ram_array__v3 = 1U;
            __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v3 
                = (0x1ffffU & vlSelf->top__DOT__ALUResultM);
            __Vdlyvval__top__DOT__datamem__DOT__ram_array__v4 
                = (0xffU & (vlSelf->top__DOT__regOp2 
                            >> 8U));
            __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v4 
                = (0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__ALUResultM));
            __Vdlyvval__top__DOT__datamem__DOT__ram_array__v5 
                = (0xffU & (vlSelf->top__DOT__regOp2 
                            >> 0x10U));
            __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v5 
                = (0x1ffffU & ((IData)(2U) + vlSelf->top__DOT__ALUResultM));
            __Vdlyvval__top__DOT__datamem__DOT__ram_array__v6 
                = (vlSelf->top__DOT__regOp2 >> 0x18U);
            __Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v6 
                = (0x1ffffU & ((IData)(3U) + vlSelf->top__DOT__ALUResultM));
        }
    }
    if (vlSelf->rst) {
        vlSelf->top__DOT__ALUSrc2_e = 0U;
        vlSelf->top__DOT__ImmExt_e = 0U;
        vlSelf->top__DOT__ALUCtrl_e = 0U;
        vlSelf->top__DOT__SizeWriteM = 0U;
        vlSelf->top__DOT__LoadSizeM = 0U;
        vlSelf->top__DOT__pc_e = 0U;
        vlSelf->top__DOT__ALUSrc_e = 0U;
        vlSelf->top__DOT__WriteDataM = 0U;
        vlSelf->top__DOT__ReadDataW = 0U;
        vlSelf->top__DOT__ResultSrcW = 0U;
        vlSelf->top__DOT__PCPlus4W = 0U;
        vlSelf->top__DOT__RD2_e = 0U;
        vlSelf->top__DOT__RD1_e = 0U;
        vlSelf->top__DOT__ALUResultW = 0U;
        vlSelf->top__DOT__RdW = 0U;
        vlSelf->top__DOT__LoadUnsignedE = 0U;
        vlSelf->top__DOT__SizeWriteE = 0U;
        vlSelf->top__DOT__LoadSizeE = 0U;
        vlSelf->top__DOT__PCD = 0U;
        vlSelf->top__DOT____Vcellout__em_pipeline__ResultSrc_m = 0U;
        vlSelf->top__DOT__PCPlus4M = 0U;
        vlSelf->top__DOT__ALUResultM = 0U;
        vlSelf->top__DOT__RdM = 0U;
        vlSelf->top__DOT__ResultSrcE = 0U;
        vlSelf->top__DOT__PCPlus4dE = 0U;
        vlSelf->top__DOT__RdE = 0U;
        vlSelf->top__DOT__PCD_save = 0U;
        vlSelf->top__DOT__instr_d = 0U;
    } else {
        vlSelf->top__DOT__SizeWriteM = vlSelf->top__DOT__SizeWriteE;
        vlSelf->top__DOT__LoadSizeM = vlSelf->top__DOT__LoadSizeE;
        vlSelf->top__DOT__WriteDataM = vlSelf->top__DOT__SrcBE;
        vlSelf->top__DOT__ReadDataW = vlSelf->top__DOT__datamem_output;
        vlSelf->top__DOT__ResultSrcW = (1U & (IData)(vlSelf->top__DOT____Vcellout__em_pipeline__ResultSrc_m));
        vlSelf->top__DOT__PCPlus4W = vlSelf->top__DOT__PCPlus4M;
        vlSelf->top__DOT__ALUResultW = vlSelf->top__DOT__ALUResultM;
        vlSelf->top__DOT__RdW = vlSelf->top__DOT__RdM;
        if ((1U & (~ (IData)(vlSelf->top__DOT__flush_d_exec)))) {
            vlSelf->top__DOT__ALUSrc2_e = vlSelf->top__DOT__ALUSrc2_d;
            vlSelf->top__DOT__ImmExt_e = vlSelf->top__DOT__ImmExt_d;
            vlSelf->top__DOT__ALUCtrl_e = vlSelf->top__DOT__ALUCtrl_d;
            vlSelf->top__DOT__pc_e = vlSelf->top__DOT__PCD;
            vlSelf->top__DOT____Vcellout__em_pipeline__ResultSrc_m 
                = vlSelf->top__DOT__ResultSrcE;
            vlSelf->top__DOT__PCPlus4M = vlSelf->top__DOT__PCPlus4dE;
            vlSelf->top__DOT__ALUResultM = vlSelf->top__DOT__output_ALU;
            vlSelf->top__DOT__RdM = vlSelf->top__DOT__RdE;
            vlSelf->top__DOT__ALUSrc_e = vlSelf->top__DOT__ALUSrc_d;
            vlSelf->top__DOT__RD2_e = (0x1fU & (vlSelf->top__DOT__instr_d 
                                                >> 0x14U));
            vlSelf->top__DOT__RD1_e = (0x1fU & (vlSelf->top__DOT__instr_d 
                                                >> 0xfU));
            vlSelf->top__DOT__LoadUnsignedE = vlSelf->top__DOT__LoadUnsigned_d;
            vlSelf->top__DOT__SizeWriteE = vlSelf->top__DOT__SizeWrite_d;
            vlSelf->top__DOT__LoadSizeE = vlSelf->top__DOT__LoadSize_d;
            vlSelf->top__DOT__ResultSrcE = vlSelf->top__DOT__ResultSrc_d;
            vlSelf->top__DOT__PCPlus4dE = vlSelf->top__DOT__PCD_save;
        } else {
            vlSelf->top__DOT____Vcellout__em_pipeline__ResultSrc_m 
                = vlSelf->top__DOT__ResultSrcE;
            vlSelf->top__DOT__PCPlus4M = vlSelf->top__DOT__PCPlus4dE;
            vlSelf->top__DOT__ALUResultM = vlSelf->top__DOT__output_ALU;
            vlSelf->top__DOT__RdM = vlSelf->top__DOT__RdE;
        }
        if ((1U & (~ (IData)(vlSelf->top__DOT__flush_f_d)))) {
            if (vlSelf->top__DOT__F_Write) {
                vlSelf->top__DOT__PCD = vlSelf->top__DOT__pc_block__DOT__internal_pc;
                vlSelf->top__DOT__PCD_save = vlSelf->top__DOT__pc_block__DOT__internal_pc;
            }
        }
        if ((1U & (~ (IData)(vlSelf->top__DOT__flush_d_exec)))) {
            vlSelf->top__DOT__RdE = (0x1fU & (vlSelf->top__DOT__instr_d 
                                              >> 7U));
        }
        if (vlSelf->top__DOT__flush_f_d) {
            vlSelf->top__DOT__instr_d = 0x33U;
        } else if (vlSelf->top__DOT__F_Write) {
            vlSelf->top__DOT__instr_d = ((((0x20000U 
                                            >= (0x3ffffU 
                                                & ((IData)(3U) 
                                                   + vlSelf->top__DOT__pc_block__DOT__internal_pc)))
                                            ? vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                           [(0x3ffffU 
                                             & ((IData)(3U) 
                                                + vlSelf->top__DOT__pc_block__DOT__internal_pc))]
                                            : 0U) << 0x18U) 
                                         | ((((0x20000U 
                                               >= (0x3ffffU 
                                                   & ((IData)(2U) 
                                                      + vlSelf->top__DOT__pc_block__DOT__internal_pc)))
                                               ? vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                              [(0x3ffffU 
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
                                                 [(0x3ffffU 
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
                                                   : 0U))));
        }
    }
    vlSelf->top__DOT__RegWriteW = ((~ (IData)(vlSelf->rst)) 
                                   & (IData)(vlSelf->top__DOT__RegWriteM));
    if (__Vdlyvset__top__DOT__regfile__DOT__regfile_array__v0) {
        vlSelf->top__DOT__regfile__DOT__regfile_array[__Vdlyvdim0__top__DOT__regfile__DOT__regfile_array__v0] 
            = __Vdlyvval__top__DOT__regfile__DOT__regfile_array__v0;
    }
    if (__Vdlyvset__top__DOT__datamem__DOT__ram_array__v0) {
        vlSelf->top__DOT__datamem__DOT__ram_array[__Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v0] 
            = __Vdlyvval__top__DOT__datamem__DOT__ram_array__v0;
    }
    if (__Vdlyvset__top__DOT__datamem__DOT__ram_array__v1) {
        vlSelf->top__DOT__datamem__DOT__ram_array[__Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v1] 
            = __Vdlyvval__top__DOT__datamem__DOT__ram_array__v1;
        vlSelf->top__DOT__datamem__DOT__ram_array[__Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v2] 
            = __Vdlyvval__top__DOT__datamem__DOT__ram_array__v2;
    }
    if (__Vdlyvset__top__DOT__datamem__DOT__ram_array__v3) {
        vlSelf->top__DOT__datamem__DOT__ram_array[__Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v3] 
            = __Vdlyvval__top__DOT__datamem__DOT__ram_array__v3;
        vlSelf->top__DOT__datamem__DOT__ram_array[__Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v4] 
            = __Vdlyvval__top__DOT__datamem__DOT__ram_array__v4;
        vlSelf->top__DOT__datamem__DOT__ram_array[__Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v5] 
            = __Vdlyvval__top__DOT__datamem__DOT__ram_array__v5;
        vlSelf->top__DOT__datamem__DOT__ram_array[__Vdlyvdim0__top__DOT__datamem__DOT__ram_array__v6] 
            = __Vdlyvval__top__DOT__datamem__DOT__ram_array__v6;
    }
    vlSelf->top__DOT__MemWriteE = ((~ (IData)(vlSelf->rst)) 
                                   & ((~ (IData)(vlSelf->top__DOT__flush_d_exec)) 
                                      & (IData)(vlSelf->top__DOT__MemWrite_d)));
    vlSelf->a0 = vlSelf->top__DOT__regfile__DOT__regfile_array
        [0xaU];
    vlSelf->top__DOT__regOp2 = vlSelf->top__DOT__regfile__DOT__regfile_array
        [vlSelf->top__DOT__AD2];
    vlSelf->top__DOT__ALUop1 = vlSelf->top__DOT__regfile__DOT__regfile_array
        [vlSelf->top__DOT__AD1];
    vlSelf->top__DOT__ResultW = ((0U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                  ? vlSelf->top__DOT__ALUResultW
                                  : ((1U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                      ? vlSelf->top__DOT__ReadDataW
                                      : ((2U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                          ? vlSelf->top__DOT__PCPlus4W
                                          : 0U)));
    vlSelf->top__DOT__RegWriteM = ((~ (IData)(vlSelf->rst)) 
                                   & (IData)(vlSelf->top__DOT__RegWriteE));
    vlSelf->top__DOT__RegWriteE = ((~ (IData)(vlSelf->rst)) 
                                   & ((~ (IData)(vlSelf->top__DOT__flush_d_exec)) 
                                      & (IData)(vlSelf->top__DOT__RegWrite_d)));
    vlSelf->top__DOT__ForwardBE = 0U;
    if ((((IData)(vlSelf->top__DOT__RegWriteM) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__RdM))) 
         & ((0x1fU & vlSelf->top__DOT__RdM) == (0x1fU 
                                                & vlSelf->top__DOT__RD2_e)))) {
        vlSelf->top__DOT__ForwardBE = 2U;
    } else if ((((IData)(vlSelf->top__DOT__RegWriteW) 
                 & (0U != (0x1fU & vlSelf->top__DOT__RdW))) 
                & ((0x1fU & vlSelf->top__DOT__RdW) 
                   == (0x1fU & vlSelf->top__DOT__RD2_e)))) {
        vlSelf->top__DOT__ForwardBE = 1U;
    }
    vlSelf->top__DOT__ForwardAE = 0U;
    if ((((IData)(vlSelf->top__DOT__RegWriteM) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__RdM))) 
         & ((0x1fU & vlSelf->top__DOT__RdM) == (0x1fU 
                                                & vlSelf->top__DOT__RD1_e)))) {
        vlSelf->top__DOT__ForwardAE = 2U;
    } else if ((((IData)(vlSelf->top__DOT__RegWriteW) 
                 & (0U != (0x1fU & vlSelf->top__DOT__RdW))) 
                & ((0x1fU & vlSelf->top__DOT__RdW) 
                   == (0x1fU & vlSelf->top__DOT__RD1_e)))) {
        vlSelf->top__DOT__ForwardAE = 1U;
    }
    vlSelf->top__DOT__hazard_unit__DOT__wStall = ((1U 
                                                   == (IData)(vlSelf->top__DOT__ResultSrcE)) 
                                                  & ((0U 
                                                      != 
                                                      (0x1fU 
                                                       & vlSelf->top__DOT__RdE)) 
                                                     & (((0x1fU 
                                                          & vlSelf->top__DOT__RdE) 
                                                         == 
                                                         (0x1fU 
                                                          & vlSelf->top__DOT__RD1_d)) 
                                                        | ((0x1fU 
                                                            & vlSelf->top__DOT__RdE) 
                                                           == 
                                                           (0x1fU 
                                                            & vlSelf->top__DOT__RD2_d)))));
    vlSelf->top__DOT__F_Write = 1U;
    vlSelf->top__DOT__pc_block__DOT__internal_pc = 
        ((IData)(vlSelf->top__DOT__PCWrite) ? ((IData)(vlSelf->rst)
                                                ? 0U
                                                : ((IData)(vlSelf->top__DOT__PCSrcE)
                                                    ? 
                                                   ((IData)(vlSelf->top__DOT__PCSrcE)
                                                     ? vlSelf->top__DOT__pc_block__DOT__branch_pc
                                                     : vlSelf->top__DOT__pc_block__DOT__inc_pc)
                                                    : vlSelf->top__DOT__pc_block__DOT__inc_pc))
          : vlSelf->top__DOT__PC);
    vlSelf->top__DOT__ResultSrc = 0U;
    vlSelf->top__DOT__SizeWrite = 0U;
    vlSelf->top__DOT__ALUSrc_d = 0U;
    vlSelf->top__DOT__ALUCtrl_d = 0U;
    vlSelf->top__DOT__RegWrite_d = 0U;
    vlSelf->top__DOT__MemWrite = 0U;
    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
    vlSelf->top__DOT__LoadUnsigned = 0U;
    vlSelf->top__DOT__LoadSize = 2U;
    vlSelf->top__DOT__ALUsrc2 = 0U;
    if (((((((((0x37U == (0x7fU & vlSelf->top__DOT__instr_d)) 
               | (0x17U == (0x7fU & vlSelf->top__DOT__instr_d))) 
              | (0x6fU == (0x7fU & vlSelf->top__DOT__instr_d))) 
             | (0x67U == (0x7fU & vlSelf->top__DOT__instr_d))) 
            | (0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) 
           | (3U == (0x7fU & vlSelf->top__DOT__instr_d))) 
          | (0x23U == (0x7fU & vlSelf->top__DOT__instr_d))) 
         | (0x13U == (0x7fU & vlSelf->top__DOT__instr_d)))) {
        if ((0x37U != (0x7fU & vlSelf->top__DOT__instr_d))) {
            if ((0x17U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                if ((0x6fU != (0x7fU & vlSelf->top__DOT__instr_d))) {
                    if ((0x67U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                        if ((0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) {
                            vlSelf->top__DOT__Branch_d = 1U;
                        }
                        if ((0x63U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                            if ((3U == (0x7fU & vlSelf->top__DOT__instr_d))) {
                                if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                                                  >> 0xcU)))) {
                                    vlSelf->top__DOT__LoadUnsigned = 0U;
                                    vlSelf->top__DOT__LoadSize = 0U;
                                } else if ((1U == (7U 
                                                   & (vlSelf->top__DOT__instr_d 
                                                      >> 0xcU)))) {
                                    vlSelf->top__DOT__LoadUnsigned = 0U;
                                    vlSelf->top__DOT__LoadSize = 1U;
                                } else if ((2U == (7U 
                                                   & (vlSelf->top__DOT__instr_d 
                                                      >> 0xcU)))) {
                                    vlSelf->top__DOT__LoadUnsigned = 0U;
                                    vlSelf->top__DOT__LoadSize = 2U;
                                } else if ((4U == (7U 
                                                   & (vlSelf->top__DOT__instr_d 
                                                      >> 0xcU)))) {
                                    vlSelf->top__DOT__LoadUnsigned = 1U;
                                    vlSelf->top__DOT__LoadSize = 0U;
                                } else if ((5U == (7U 
                                                   & (vlSelf->top__DOT__instr_d 
                                                      >> 0xcU)))) {
                                    vlSelf->top__DOT__LoadUnsigned = 1U;
                                    vlSelf->top__DOT__LoadSize = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((0x37U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT__ResultSrc = 0U;
            vlSelf->top__DOT__SizeWrite = 0U;
            vlSelf->top__DOT__ALUSrc_d = 1U;
            vlSelf->top__DOT__ALUCtrl_d = 0xaU;
            vlSelf->top__DOT__RegWrite_d = 1U;
            vlSelf->top__DOT__MemWrite = 0U;
            vlSelf->top__DOT____Vcellout__control__ImmSrc = 4U;
            vlSelf->top__DOT__ALUsrc2 = 0U;
        } else if ((0x17U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT__ResultSrc = 0U;
            vlSelf->top__DOT__SizeWrite = 0U;
            vlSelf->top__DOT__ALUSrc_d = 1U;
            vlSelf->top__DOT__ALUCtrl_d = 0xbU;
            vlSelf->top__DOT__RegWrite_d = 1U;
            vlSelf->top__DOT__MemWrite = 0U;
            vlSelf->top__DOT____Vcellout__control__ImmSrc = 4U;
            vlSelf->top__DOT__ALUsrc2 = 1U;
        } else {
            if ((0x6fU == (0x7fU & vlSelf->top__DOT__instr_d))) {
                vlSelf->top__DOT__ResultSrc = 2U;
                vlSelf->top__DOT__SizeWrite = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 3U;
            } else if ((0x67U == (0x7fU & vlSelf->top__DOT__instr_d))) {
                vlSelf->top__DOT__ResultSrc = 2U;
                vlSelf->top__DOT__SizeWrite = 0U;
                vlSelf->top__DOT__ALUSrc_d = 1U;
                vlSelf->top__DOT__ALUCtrl_d = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            } else if ((0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__SizeWrite = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                if ((0x4000U & vlSelf->top__DOT__instr_d)) {
                    vlSelf->top__DOT__ALUCtrl_d = 1U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 2U;
                } else if ((0x2000U & vlSelf->top__DOT__instr_d)) {
                    vlSelf->top__DOT__ALUCtrl_d = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                } else {
                    vlSelf->top__DOT__ALUCtrl_d = 1U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 2U;
                }
                vlSelf->top__DOT__RegWrite_d = 0U;
                vlSelf->top__DOT__MemWrite = 0U;
            } else if ((3U == (0x7fU & vlSelf->top__DOT__instr_d))) {
                vlSelf->top__DOT__ResultSrc = 1U;
                vlSelf->top__DOT__SizeWrite = 0U;
                vlSelf->top__DOT__ALUSrc_d = 1U;
                vlSelf->top__DOT__ALUCtrl_d = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            } else if ((0x23U == (0x7fU & vlSelf->top__DOT__instr_d))) {
                if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                                  >> 0xcU)))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__SizeWrite = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 0U;
                    vlSelf->top__DOT__RegWrite_d = 0U;
                    vlSelf->top__DOT__MemWrite = 1U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 1U;
                } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                         >> 0xcU)))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__SizeWrite = 1U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 0U;
                    vlSelf->top__DOT__RegWrite_d = 0U;
                    vlSelf->top__DOT__MemWrite = 1U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 1U;
                } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                         >> 0xcU)))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__SizeWrite = 2U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 0U;
                    vlSelf->top__DOT__RegWrite_d = 0U;
                    vlSelf->top__DOT__MemWrite = 1U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 1U;
                }
            } else {
                if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                                  >> 0xcU)))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 0U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                         >> 0xcU)))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 8U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                } else if ((3U == (7U & (vlSelf->top__DOT__instr_d 
                                         >> 0xcU)))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 9U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                } else if ((4U == (7U & (vlSelf->top__DOT__instr_d 
                                         >> 0xcU)))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 4U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                } else if ((6U == (7U & (vlSelf->top__DOT__instr_d 
                                         >> 0xcU)))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 3U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                } else if ((7U == (7U & (vlSelf->top__DOT__instr_d 
                                         >> 0xcU)))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 2U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                         >> 0xcU)))) {
                    if ((0U == (vlSelf->top__DOT__instr_d 
                                >> 0x19U))) {
                        vlSelf->top__DOT__ResultSrc = 0U;
                        vlSelf->top__DOT__ALUSrc_d = 1U;
                        vlSelf->top__DOT__ALUCtrl_d = 5U;
                        vlSelf->top__DOT__MemWrite = 0U;
                        vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                    }
                } else if ((5U == (7U & (vlSelf->top__DOT__instr_d 
                                         >> 0xcU)))) {
                    if ((0U == (vlSelf->top__DOT__instr_d 
                                >> 0x19U))) {
                        vlSelf->top__DOT__ResultSrc = 0U;
                        vlSelf->top__DOT__ALUSrc_d = 1U;
                        vlSelf->top__DOT__ALUCtrl_d = 6U;
                        vlSelf->top__DOT__MemWrite = 0U;
                        vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                    } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                          >> 0x19U))) {
                        vlSelf->top__DOT__ResultSrc = 0U;
                        vlSelf->top__DOT__ALUSrc_d = 1U;
                        vlSelf->top__DOT__ALUCtrl_d = 7U;
                        vlSelf->top__DOT__MemWrite = 0U;
                        vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                    }
                }
                vlSelf->top__DOT__RegWrite_d = ((0U 
                                                 == 
                                                 (7U 
                                                  & (vlSelf->top__DOT__instr_d 
                                                     >> 0xcU))) 
                                                | ((2U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->top__DOT__instr_d 
                                                        >> 0xcU))) 
                                                   | ((3U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->top__DOT__instr_d 
                                                           >> 0xcU))) 
                                                      | ((4U 
                                                          == 
                                                          (7U 
                                                           & (vlSelf->top__DOT__instr_d 
                                                              >> 0xcU))) 
                                                         | ((6U 
                                                             == 
                                                             (7U 
                                                              & (vlSelf->top__DOT__instr_d 
                                                                 >> 0xcU))) 
                                                            | ((7U 
                                                                == 
                                                                (7U 
                                                                 & (vlSelf->top__DOT__instr_d 
                                                                    >> 0xcU))) 
                                                               | ((1U 
                                                                   == 
                                                                   (7U 
                                                                    & (vlSelf->top__DOT__instr_d 
                                                                       >> 0xcU)))
                                                                   ? 
                                                                  (0U 
                                                                   == 
                                                                   (vlSelf->top__DOT__instr_d 
                                                                    >> 0x19U))
                                                                   : (IData)(
                                                                             ((0x5000U 
                                                                               == 
                                                                               (0x7000U 
                                                                                & vlSelf->top__DOT__instr_d)) 
                                                                              & ((0U 
                                                                                == 
                                                                                (vlSelf->top__DOT__instr_d 
                                                                                >> 0x19U)) 
                                                                                | (0x20U 
                                                                                == 
                                                                                (vlSelf->top__DOT__instr_d 
                                                                                >> 0x19U))))))))))));
            }
            if ((0x6fU != (0x7fU & vlSelf->top__DOT__instr_d))) {
                if ((0x67U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                    if ((0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) {
                        if ((1U & (~ (vlSelf->top__DOT__instr_d 
                                      >> 0xeU)))) {
                            if ((0x2000U & vlSelf->top__DOT__instr_d)) {
                                vlSelf->top__DOT__ALUsrc2 = 0U;
                            }
                        }
                    } else if ((3U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                        if ((0x23U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                            if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                                              >> 0xcU)))) {
                                vlSelf->top__DOT__ALUsrc2 = 0U;
                            } else if ((2U == (7U & 
                                               (vlSelf->top__DOT__instr_d 
                                                >> 0xcU)))) {
                                vlSelf->top__DOT__ALUsrc2 = 0U;
                            } else if ((3U == (7U & 
                                               (vlSelf->top__DOT__instr_d 
                                                >> 0xcU)))) {
                                vlSelf->top__DOT__ALUsrc2 = 0U;
                            } else if ((4U == (7U & 
                                               (vlSelf->top__DOT__instr_d 
                                                >> 0xcU)))) {
                                vlSelf->top__DOT__ALUsrc2 = 0U;
                            } else if ((6U == (7U & 
                                               (vlSelf->top__DOT__instr_d 
                                                >> 0xcU)))) {
                                vlSelf->top__DOT__ALUsrc2 = 0U;
                            } else if ((7U == (7U & 
                                               (vlSelf->top__DOT__instr_d 
                                                >> 0xcU)))) {
                                vlSelf->top__DOT__ALUsrc2 = 0U;
                            } else if ((1U == (7U & 
                                               (vlSelf->top__DOT__instr_d 
                                                >> 0xcU)))) {
                                if ((0U == (vlSelf->top__DOT__instr_d 
                                            >> 0x19U))) {
                                    vlSelf->top__DOT__ALUsrc2 = 0U;
                                }
                            } else if ((5U == (7U & 
                                               (vlSelf->top__DOT__instr_d 
                                                >> 0xcU)))) {
                                if ((0U == (vlSelf->top__DOT__instr_d 
                                            >> 0x19U))) {
                                    vlSelf->top__DOT__ALUsrc2 = 0U;
                                } else if ((0x20U == 
                                            (vlSelf->top__DOT__instr_d 
                                             >> 0x19U))) {
                                    vlSelf->top__DOT__ALUsrc2 = 0U;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x33U == (0x7fU & vlSelf->top__DOT__instr_d))) {
        if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                          >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 0U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__ALUsrc2 = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 1U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__ALUsrc2 = 0U;
            }
            vlSelf->top__DOT__RegWrite_d = ((0U == 
                                             (vlSelf->top__DOT__instr_d 
                                              >> 0x19U)) 
                                            | (0x20U 
                                               == (vlSelf->top__DOT__instr_d 
                                                   >> 0x19U)));
        } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 5U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__ALUsrc2 = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
            } else {
                vlSelf->top__DOT__RegWrite_d = 0U;
            }
        } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 8U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__ALUsrc2 = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
            } else {
                vlSelf->top__DOT__RegWrite_d = 0U;
            }
        } else if ((3U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 9U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__ALUsrc2 = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
            } else {
                vlSelf->top__DOT__RegWrite_d = 0U;
            }
        } else if ((4U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 4U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__ALUsrc2 = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
            } else {
                vlSelf->top__DOT__RegWrite_d = 0U;
            }
        } else if ((5U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 6U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__ALUsrc2 = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 7U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__ALUsrc2 = 0U;
            }
            vlSelf->top__DOT__RegWrite_d = ((0U == 
                                             (vlSelf->top__DOT__instr_d 
                                              >> 0x19U)) 
                                            | (0x20U 
                                               == (vlSelf->top__DOT__instr_d 
                                                   >> 0x19U)));
        } else if ((6U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 3U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__ALUsrc2 = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
            } else {
                vlSelf->top__DOT__RegWrite_d = 0U;
            }
        } else {
            if ((7U == (7U & (vlSelf->top__DOT__instr_d 
                              >> 0xcU)))) {
                if ((0U == (vlSelf->top__DOT__instr_d 
                            >> 0x19U))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 0U;
                    vlSelf->top__DOT__ALUCtrl_d = 2U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                    vlSelf->top__DOT__ALUsrc2 = 0U;
                }
            }
            vlSelf->top__DOT__RegWrite_d = (IData)(
                                                   (0x7000U 
                                                    == 
                                                    (0xfe007000U 
                                                     & vlSelf->top__DOT__instr_d)));
        }
    }
    vlSelf->top__DOT__PCWrite = 1U;
    if (vlSelf->top__DOT__hazard_unit__DOT__wStall) {
        vlSelf->top__DOT__F_Write = 0U;
        vlSelf->top__DOT__PCWrite = 0U;
    }
    if ((0U == (3U & (IData)(vlSelf->top__DOT____Vcellout__control__ImmSrc)))) {
        vlSelf->top__DOT__ImmExt_d = (((- (IData)((vlSelf->top__DOT__instr_d 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (vlSelf->top__DOT__instr_d 
                                                   >> 0x14U));
    } else if ((1U == (3U & (IData)(vlSelf->top__DOT____Vcellout__control__ImmSrc)))) {
        vlSelf->top__DOT__ImmExt_d = (((- (IData)((vlSelf->top__DOT__instr_d 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (
                                                   (0xfe0U 
                                                    & (vlSelf->top__DOT__instr_d 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlSelf->top__DOT__instr_d 
                                                         >> 7U))));
    } else if ((2U == (3U & (IData)(vlSelf->top__DOT____Vcellout__control__ImmSrc)))) {
        vlSelf->top__DOT__ImmExt_d = (((- (IData)((vlSelf->top__DOT__instr_d 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (
                                                   (0x800U 
                                                    & (vlSelf->top__DOT__instr_d 
                                                       << 4U)) 
                                                   | ((0x7e0U 
                                                       & (vlSelf->top__DOT__instr_d 
                                                          >> 0x14U)) 
                                                      | (0x1eU 
                                                         & (vlSelf->top__DOT__instr_d 
                                                            >> 7U)))));
    }
    vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffffff00U & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | vlSelf->top__DOT__datamem__DOT__ram_array
           [(0x1ffffU & vlSelf->top__DOT__ALUResultM)]);
    vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffff00ffU & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelf->top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__ALUResultM))] 
              << 8U));
    vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xff00ffffU & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelf->top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(2U) + vlSelf->top__DOT__ALUResultM))] 
              << 0x10U));
    vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffffffU & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelf->top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(3U) + vlSelf->top__DOT__ALUResultM))] 
              << 0x18U));
    vlSelf->top__DOT__output_DataMem = ((0U == (IData)(vlSelf->top__DOT__LoadSize))
                                         ? ((IData)(vlSelf->top__DOT__LoadUnsigned)
                                             ? (0xffU 
                                                & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data)
                                             : (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
                                                                >> 7U)))) 
                                                 << 8U) 
                                                | (0xffU 
                                                   & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data)))
                                         : ((1U == (IData)(vlSelf->top__DOT__LoadSize))
                                             ? ((IData)(vlSelf->top__DOT__LoadUnsigned)
                                                 ? 
                                                (0xffffU 
                                                 & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data)
                                                 : 
                                                (((- (IData)(
                                                             (1U 
                                                              & (vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
                                                                 >> 0xfU)))) 
                                                  << 0x10U) 
                                                 | (0xffffU 
                                                    & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data)))
                                             : vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data));
    vlSelf->top__DOT__pc_block__DOT__inc_pc = ((IData)(4U) 
                                               + vlSelf->top__DOT__pc_block__DOT__internal_pc);
    vlSelf->top__DOT__PC = vlSelf->top__DOT__pc_block__DOT__internal_pc;
    vlSelf->top__DOT__pc_block__DOT__branch_pc = (vlSelf->top__DOT__pc_block__DOT__internal_pc 
                                                  + vlSelf->top__DOT__ImmOp);
}

extern const VlUnpacked<CData/*0:0*/, 256> Vdut__ConstPool__TABLE_h382018d6_0;

VL_INLINE_OPT void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vtableidx1;
    // Body
    vlSelf->top__DOT__SrcBE = ((2U & (IData)(vlSelf->top__DOT__ForwardBE))
                                ? vlSelf->top__DOT__output_ALU
                                : vlSelf->top__DOT__ALUResultM);
    vlSelf->top__DOT__SrcAE = ((2U & (IData)(vlSelf->top__DOT__ForwardAE))
                                ? vlSelf->top__DOT__output_ALU
                                : vlSelf->top__DOT__ALUResultM);
    vlSelf->top__DOT__ALUop2 = ((IData)(vlSelf->top__DOT__ALUSrc_e)
                                 ? vlSelf->top__DOT__ImmOp
                                 : vlSelf->top__DOT__SrcBE);
    vlSelf->top__DOT__ALUop1 = ((IData)(vlSelf->top__DOT__ALUsrc2)
                                 ? (IData)(vlSelf->top__DOT__pc_save_e)
                                 : vlSelf->top__DOT__SrcAE);
    vlSelf->top__DOT__output_ALU = ((8U & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                     ? ((4U & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                         ? 0U : ((2U 
                                                  & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                   ? 
                                                  ((vlSelf->top__DOT__ALUop1 
                                                    + vlSelf->top__DOT__ALUop2) 
                                                   - (IData)(4U))
                                                   : vlSelf->top__DOT__ALUop2)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                   ? 
                                                  ((vlSelf->top__DOT__ALUop1 
                                                    < vlSelf->top__DOT__ALUop2)
                                                    ? 1U
                                                    : 0U)
                                                   : 
                                                  (VL_LTS_III(32, vlSelf->top__DOT__ALUop1, vlSelf->top__DOT__ALUop2)
                                                    ? 1U
                                                    : 0U))))
                                     : ((4U & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                         ? ((2U & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                 ? 
                                                ((0x1fU 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__ALUop2))
                                                  ? 
                                                 VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__ALUop1, 
                                                                (0x1fU 
                                                                 & vlSelf->top__DOT__ALUop2))
                                                  : 
                                                 (- 
                                                  (vlSelf->top__DOT__ALUop1 
                                                   >> 0x1fU)))
                                                 : 
                                                ((0x1fU 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__ALUop2))
                                                  ? 
                                                 (vlSelf->top__DOT__ALUop1 
                                                  >> 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__ALUop2))
                                                  : 0U))
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                 ? 
                                                ((0x1fU 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__ALUop2))
                                                  ? 
                                                 (vlSelf->top__DOT__ALUop1 
                                                  << 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__ALUop2))
                                                  : 0U)
                                                 : 
                                                (vlSelf->top__DOT__ALUop1 
                                                 ^ vlSelf->top__DOT__ALUop2)))
                                         : ((2U & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                 ? 
                                                (vlSelf->top__DOT__ALUop1 
                                                 | vlSelf->top__DOT__ALUop2)
                                                 : 
                                                (vlSelf->top__DOT__ALUop1 
                                                 & vlSelf->top__DOT__ALUop2))
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                 ? 
                                                (vlSelf->top__DOT__ALUop1 
                                                 - vlSelf->top__DOT__ALUop2)
                                                 : 
                                                (vlSelf->top__DOT__ALUop1 
                                                 + vlSelf->top__DOT__ALUop2)))));
    vlSelf->top__DOT__EQ = (vlSelf->top__DOT__ALUop1 
                            == vlSelf->top__DOT__ALUop2);
    vlSelf->top__DOT__LT = VL_LTS_III(32, vlSelf->top__DOT__ALUop1, vlSelf->top__DOT__ALUop2);
    vlSelf->top__DOT__LTU = (vlSelf->top__DOT__ALUop1 
                             < vlSelf->top__DOT__ALUop2);
    vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
    if (((((((((0x37U == (0x7fU & vlSelf->top__DOT__instr_d)) 
               | (0x17U == (0x7fU & vlSelf->top__DOT__instr_d))) 
              | (0x6fU == (0x7fU & vlSelf->top__DOT__instr_d))) 
             | (0x67U == (0x7fU & vlSelf->top__DOT__instr_d))) 
            | (0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) 
           | (3U == (0x7fU & vlSelf->top__DOT__instr_d))) 
          | (0x23U == (0x7fU & vlSelf->top__DOT__instr_d))) 
         | (0x13U == (0x7fU & vlSelf->top__DOT__instr_d)))) {
        if ((0x37U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((0x17U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((0x6fU == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 1U;
        } else if ((0x67U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 2U;
        } else if ((0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc 
                = ((0x4000U & vlSelf->top__DOT__instr_d)
                    ? ((0x2000U & vlSelf->top__DOT__instr_d)
                        ? ((0x1000U & vlSelf->top__DOT__instr_d)
                            ? ((IData)(vlSelf->top__DOT__LTU)
                                ? 0U : 1U) : ((IData)(vlSelf->top__DOT__LTU)
                                               ? 1U
                                               : 0U))
                        : ((0x1000U & vlSelf->top__DOT__instr_d)
                            ? ((IData)(vlSelf->top__DOT__LT)
                                ? 0U : 1U) : ((IData)(vlSelf->top__DOT__LT)
                                               ? 1U
                                               : 0U)))
                    : ((0x2000U & vlSelf->top__DOT__instr_d)
                        ? 0U : ((0x1000U & vlSelf->top__DOT__instr_d)
                                 ? ((IData)(vlSelf->top__DOT__EQ)
                                     ? 0U : 1U) : ((IData)(vlSelf->top__DOT__EQ)
                                                    ? 1U
                                                    : 0U))));
        } else if ((3U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((0x23U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                              >> 0xcU)))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((3U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((4U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((6U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((7U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((5U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        }
    } else if ((0x33U == (0x7fU & vlSelf->top__DOT__instr_d))) {
        if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                          >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((3U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((4U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((5U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((6U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((7U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        }
    }
    __Vtableidx1 = (((IData)(vlSelf->top__DOT__Jump_e) 
                     << 7U) | (((IData)(vlSelf->top__DOT__EQ) 
                                << 6U) | (((IData)(vlSelf->top__DOT__LT) 
                                           << 5U) | 
                                          (((IData)(vlSelf->top__DOT__LTU) 
                                            << 4U) 
                                           | (((IData)(vlSelf->top__DOT__function3_e) 
                                               << 1U) 
                                              | (IData)(vlSelf->top__DOT__Branch_e))))));
    vlSelf->top__DOT__PCSrcE = Vdut__ConstPool__TABLE_h382018d6_0
        [__Vtableidx1];
    vlSelf->top__DOT__flush_f_d = 0U;
    vlSelf->top__DOT__flush_d_exec = 0U;
    if (vlSelf->top__DOT__PCSrcE) {
        vlSelf->top__DOT__flush_f_d = 1U;
        vlSelf->top__DOT__flush_d_exec = 1U;
    }
    if (vlSelf->top__DOT__hazard_unit__DOT__wStall) {
        vlSelf->top__DOT__flush_d_exec = 1U;
    }
}

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vdut___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vdut___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData Vdut___024root___change_request_1(Vdut___024root* vlSelf);

VL_INLINE_OPT QData Vdut___024root___change_request(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___change_request\n"); );
    // Body
    return (Vdut___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vdut___024root___change_request_1(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSelf->top__DOT__output_ALU ^ vlSelf->__Vchglast__TOP__top__DOT__output_ALU));
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__output_ALU ^ vlSelf->__Vchglast__TOP__top__DOT__output_ALU))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/challengelab4/rtl/top.sv:24: top.output_ALU\n"); );
    // Final
    vlSelf->__Vchglast__TOP__top__DOT__output_ALU = vlSelf->top__DOT__output_ALU;
    return __req;
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
