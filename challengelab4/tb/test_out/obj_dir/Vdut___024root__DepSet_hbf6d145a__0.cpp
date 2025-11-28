// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

void Vdut___024root___eval_act(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_act\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf);

void Vdut___024root___eval_nba(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_nba\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdfgRegularize_h038a369a_0_3;
    __VdfgRegularize_h038a369a_0_3 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__regfile__DOT__regfile_array__v0;
    __VdlyVal__top__DOT__regfile__DOT__regfile_array__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__regfile__DOT__regfile_array__v0;
    __VdlyDim0__top__DOT__regfile__DOT__regfile_array__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__regfile__DOT__regfile_array__v0;
    __VdlySet__top__DOT__regfile__DOT__regfile_array__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__datamem__DOT__ram_array__v0;
    __VdlyVal__top__DOT__datamem__DOT__ram_array__v0 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__datamem__DOT__ram_array__v0;
    __VdlyDim0__top__DOT__datamem__DOT__ram_array__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__datamem__DOT__ram_array__v0;
    __VdlySet__top__DOT__datamem__DOT__ram_array__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__datamem__DOT__ram_array__v1;
    __VdlyVal__top__DOT__datamem__DOT__ram_array__v1 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__datamem__DOT__ram_array__v1;
    __VdlyDim0__top__DOT__datamem__DOT__ram_array__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__datamem__DOT__ram_array__v1;
    __VdlySet__top__DOT__datamem__DOT__ram_array__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__datamem__DOT__ram_array__v2;
    __VdlyVal__top__DOT__datamem__DOT__ram_array__v2 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__datamem__DOT__ram_array__v2;
    __VdlyDim0__top__DOT__datamem__DOT__ram_array__v2 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__datamem__DOT__ram_array__v3;
    __VdlyVal__top__DOT__datamem__DOT__ram_array__v3 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__datamem__DOT__ram_array__v3;
    __VdlyDim0__top__DOT__datamem__DOT__ram_array__v3 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__datamem__DOT__ram_array__v3;
    __VdlySet__top__DOT__datamem__DOT__ram_array__v3 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__datamem__DOT__ram_array__v4;
    __VdlyVal__top__DOT__datamem__DOT__ram_array__v4 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__datamem__DOT__ram_array__v4;
    __VdlyDim0__top__DOT__datamem__DOT__ram_array__v4 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__datamem__DOT__ram_array__v5;
    __VdlyVal__top__DOT__datamem__DOT__ram_array__v5 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__datamem__DOT__ram_array__v5;
    __VdlyDim0__top__DOT__datamem__DOT__ram_array__v5 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__datamem__DOT__ram_array__v6;
    __VdlyVal__top__DOT__datamem__DOT__ram_array__v6 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__datamem__DOT__ram_array__v6;
    __VdlyDim0__top__DOT__datamem__DOT__ram_array__v6 = 0;
    // Body
    __VdlySet__top__DOT__datamem__DOT__ram_array__v0 = 0U;
    __VdlySet__top__DOT__datamem__DOT__ram_array__v1 = 0U;
    __VdlySet__top__DOT__datamem__DOT__ram_array__v3 = 0U;
    __VdlySet__top__DOT__regfile__DOT__regfile_array__v0 = 0U;
    if (vlSelfRef.top__DOT__MemWriteM) {
        if ((0U == (IData)(vlSelfRef.top__DOT__SizeWriteM))) {
            __VdlyVal__top__DOT__datamem__DOT__ram_array__v0 
                = (0xffU & vlSelfRef.top__DOT__WriteDataM);
            __VdlyDim0__top__DOT__datamem__DOT__ram_array__v0 
                = (0x1ffffU & vlSelfRef.top__DOT__ALUResultM);
            __VdlySet__top__DOT__datamem__DOT__ram_array__v0 = 1U;
        } else if ((1U == (IData)(vlSelfRef.top__DOT__SizeWriteM))) {
            __VdlyVal__top__DOT__datamem__DOT__ram_array__v1 
                = (0xffU & vlSelfRef.top__DOT__WriteDataM);
            __VdlyDim0__top__DOT__datamem__DOT__ram_array__v1 
                = (0x1ffffU & vlSelfRef.top__DOT__ALUResultM);
            __VdlySet__top__DOT__datamem__DOT__ram_array__v1 = 1U;
            __VdlyVal__top__DOT__datamem__DOT__ram_array__v2 
                = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                            >> 8U));
            __VdlyDim0__top__DOT__datamem__DOT__ram_array__v2 
                = (0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__ALUResultM));
        } else if ((2U == (IData)(vlSelfRef.top__DOT__SizeWriteM))) {
            __VdlyVal__top__DOT__datamem__DOT__ram_array__v3 
                = (0xffU & vlSelfRef.top__DOT__WriteDataM);
            __VdlyDim0__top__DOT__datamem__DOT__ram_array__v3 
                = (0x1ffffU & vlSelfRef.top__DOT__ALUResultM);
            __VdlySet__top__DOT__datamem__DOT__ram_array__v3 = 1U;
            __VdlyVal__top__DOT__datamem__DOT__ram_array__v4 
                = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                            >> 8U));
            __VdlyDim0__top__DOT__datamem__DOT__ram_array__v4 
                = (0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__ALUResultM));
            __VdlyVal__top__DOT__datamem__DOT__ram_array__v5 
                = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                            >> 0x10U));
            __VdlyDim0__top__DOT__datamem__DOT__ram_array__v5 
                = (0x1ffffU & ((IData)(2U) + vlSelfRef.top__DOT__ALUResultM));
            __VdlyVal__top__DOT__datamem__DOT__ram_array__v6 
                = (vlSelfRef.top__DOT__WriteDataM >> 0x18U);
            __VdlyDim0__top__DOT__datamem__DOT__ram_array__v6 
                = (0x1ffffU & ((IData)(3U) + vlSelfRef.top__DOT__ALUResultM));
        }
    }
    if (vlSelfRef.top__DOT__RegWriteW) {
        __VdlyVal__top__DOT__regfile__DOT__regfile_array__v0 
            = vlSelfRef.top__DOT__ResultW;
        __VdlyDim0__top__DOT__regfile__DOT__regfile_array__v0 
            = vlSelfRef.top__DOT__RdW;
        __VdlySet__top__DOT__regfile__DOT__regfile_array__v0 = 1U;
    }
    vlSelfRef.top__DOT__LoadUnsignedM = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                         && (IData)(vlSelfRef.top__DOT__LoadUnsignedE));
    if (__VdlySet__top__DOT__datamem__DOT__ram_array__v0) {
        vlSelfRef.top__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__datamem__DOT__ram_array__v0] 
            = __VdlyVal__top__DOT__datamem__DOT__ram_array__v0;
    }
    if (__VdlySet__top__DOT__datamem__DOT__ram_array__v1) {
        vlSelfRef.top__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__datamem__DOT__ram_array__v1] 
            = __VdlyVal__top__DOT__datamem__DOT__ram_array__v1;
        vlSelfRef.top__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__datamem__DOT__ram_array__v2] 
            = __VdlyVal__top__DOT__datamem__DOT__ram_array__v2;
    }
    if (__VdlySet__top__DOT__datamem__DOT__ram_array__v3) {
        vlSelfRef.top__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__datamem__DOT__ram_array__v3] 
            = __VdlyVal__top__DOT__datamem__DOT__ram_array__v3;
        vlSelfRef.top__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__datamem__DOT__ram_array__v4] 
            = __VdlyVal__top__DOT__datamem__DOT__ram_array__v4;
        vlSelfRef.top__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__datamem__DOT__ram_array__v5] 
            = __VdlyVal__top__DOT__datamem__DOT__ram_array__v5;
        vlSelfRef.top__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__datamem__DOT__ram_array__v6] 
            = __VdlyVal__top__DOT__datamem__DOT__ram_array__v6;
    }
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__ALUCtrlE = 0U;
        vlSelfRef.top__DOT__LoadSizeM = 0U;
        vlSelfRef.top__DOT__ALUSrcE = 0U;
        vlSelfRef.top__DOT__ALUSrc2E = 0U;
        vlSelfRef.top__DOT__ReadDataW = 0U;
        vlSelfRef.top__DOT__ALUResultW = 0U;
        vlSelfRef.top__DOT__PCE = 0U;
        vlSelfRef.top__DOT__ResultSrcW = 0U;
        vlSelfRef.top__DOT__ExtImmE = 0U;
        vlSelfRef.top__DOT__RD1E = 0U;
        vlSelfRef.top__DOT__Rs1E = 0U;
        vlSelfRef.top__DOT__RD2E = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__flush_d_exec)))) {
            vlSelfRef.top__DOT__ALUCtrlE = vlSelfRef.top__DOT__ALUCtrlD;
            vlSelfRef.top__DOT__ALUSrcE = vlSelfRef.top__DOT__ALUSrcD;
            vlSelfRef.top__DOT__ALUSrc2E = vlSelfRef.top__DOT__ALUSrc2D;
            vlSelfRef.top__DOT__PCE = vlSelfRef.top__DOT__PCD;
            vlSelfRef.top__DOT__ExtImmE = ((0U == (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                            ? (((- (IData)(
                                                           (vlSelfRef.top__DOT__InstrD 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelfRef.top__DOT__InstrD 
                                                  >> 0x14U))
                                            : ((1U 
                                                == (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                                ? (
                                                   ((- (IData)(
                                                               (vlSelfRef.top__DOT__InstrD 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | ((0xfe0U 
                                                       & (vlSelfRef.top__DOT__InstrD 
                                                          >> 0x14U)) 
                                                      | (0x1fU 
                                                         & (vlSelfRef.top__DOT__InstrD 
                                                            >> 7U))))
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelfRef.top__DOT__InstrD 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0x800U 
                                                        & (vlSelfRef.top__DOT__InstrD 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (vlSelfRef.top__DOT__InstrD 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (vlSelfRef.top__DOT__InstrD 
                                                                >> 7U)))))
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                                     ? 
                                                    (0xfffff000U 
                                                     & vlSelfRef.top__DOT__InstrD)
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                                      ? 
                                                     (((- (IData)(
                                                                  (vlSelfRef.top__DOT__InstrD 
                                                                   >> 0x1fU))) 
                                                       << 0x14U) 
                                                      | (((0xff000U 
                                                           & vlSelfRef.top__DOT__InstrD) 
                                                          | (0x800U 
                                                             & (vlSelfRef.top__DOT__InstrD 
                                                                >> 9U))) 
                                                         | (0x7feU 
                                                            & (vlSelfRef.top__DOT__InstrD 
                                                               >> 0x14U))))
                                                      : 0U)))));
            vlSelfRef.top__DOT__RD1E = vlSelfRef.top__DOT__regfile__DOT__regfile_array
                [(0x1fU & (vlSelfRef.top__DOT__InstrD 
                           >> 0xfU))];
            vlSelfRef.top__DOT__Rs1E = (0x1fU & (vlSelfRef.top__DOT__InstrD 
                                                 >> 0xfU));
            vlSelfRef.top__DOT__RD2E = vlSelfRef.top__DOT__regfile__DOT__regfile_array
                [(0x1fU & (vlSelfRef.top__DOT__InstrD 
                           >> 0x14U))];
        }
        vlSelfRef.top__DOT__LoadSizeM = vlSelfRef.top__DOT__LoadSizeE;
        vlSelfRef.top__DOT__ReadDataW = vlSelfRef.top__DOT__ReadDataM;
        vlSelfRef.top__DOT__ALUResultW = vlSelfRef.top__DOT__ALUResultM;
        vlSelfRef.top__DOT__ResultSrcW = vlSelfRef.top__DOT__ResultSrcM;
    }
    if (__VdlySet__top__DOT__regfile__DOT__regfile_array__v0) {
        vlSelfRef.top__DOT__regfile__DOT__regfile_array[__VdlyDim0__top__DOT__regfile__DOT__regfile_array__v0] 
            = __VdlyVal__top__DOT__regfile__DOT__regfile_array__v0;
    }
    vlSelfRef.top__DOT__MemWriteM = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                     && (IData)(vlSelfRef.top__DOT__MemWriteE));
    vlSelfRef.top__DOT__RegWriteW = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                     && (IData)(vlSelfRef.top__DOT__RegWriteM));
    vlSelfRef.a0 = vlSelfRef.top__DOT__regfile__DOT__regfile_array
        [0xaU];
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__Rs2E = 0U;
        vlSelfRef.top__DOT__PCPlus4W = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__flush_d_exec)))) {
            vlSelfRef.top__DOT__Rs2E = (0x1fU & (vlSelfRef.top__DOT__InstrD 
                                                 >> 0x14U));
        }
        vlSelfRef.top__DOT__PCPlus4W = vlSelfRef.top__DOT__PCPlus4M;
    }
    vlSelfRef.top__DOT__ResultW = ((0U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                    ? vlSelfRef.top__DOT__ALUResultW
                                    : ((1U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                        ? vlSelfRef.top__DOT__ReadDataW
                                        : ((2U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                            ? vlSelfRef.top__DOT__PCPlus4W
                                            : 0U)));
    vlSelfRef.top__DOT__MemWriteE = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                     && ((1U & (~ (IData)(vlSelfRef.top__DOT__flush_d_exec))) 
                                         && (IData)(vlSelfRef.top__DOT__MemWriteD)));
    vlSelfRef.top__DOT__RegWriteM = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                     && (IData)(vlSelfRef.top__DOT__RegWriteE));
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__WriteDataM = 0U;
        vlSelfRef.top__DOT__SizeWriteM = 0U;
        vlSelfRef.top__DOT__RdW = 0U;
        vlSelfRef.top__DOT__LoadSizeE = 0U;
        vlSelfRef.top__DOT__LoadUnsignedE = 0U;
        vlSelfRef.top__DOT__ALUResultM = 0U;
    } else {
        vlSelfRef.top__DOT__WriteDataM = vlSelfRef.top__DOT__WriteDataE;
        vlSelfRef.top__DOT__SizeWriteM = vlSelfRef.top__DOT__SizeWriteE;
        vlSelfRef.top__DOT__RdW = vlSelfRef.top__DOT__RdM;
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__flush_d_exec)))) {
            vlSelfRef.top__DOT__LoadSizeE = vlSelfRef.top__DOT__LoadSizeD;
            vlSelfRef.top__DOT__LoadUnsignedE = vlSelfRef.top__DOT__LoadUnsignedD;
        }
        vlSelfRef.top__DOT__ALUResultM = vlSelfRef.top__DOT__ALUResultE;
    }
    vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffffff00U & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | vlSelfRef.top__DOT__datamem__DOT__ram_array
           [(0x1ffffU & vlSelfRef.top__DOT__ALUResultM)]);
    vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffff00ffU & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelfRef.top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__ALUResultM))] 
              << 8U));
    vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xff00ffffU & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelfRef.top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(2U) + vlSelfRef.top__DOT__ALUResultM))] 
              << 0x10U));
    vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffffffU & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelfRef.top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(3U) + vlSelfRef.top__DOT__ALUResultM))] 
              << 0x18U));
    vlSelfRef.top__DOT__ReadDataM = ((0U == (IData)(vlSelfRef.top__DOT__LoadSizeM))
                                      ? ((IData)(vlSelfRef.top__DOT__LoadUnsignedM)
                                          ? (0xffU 
                                             & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data)
                                          : (((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
                                                             >> 7U)))) 
                                              << 8U) 
                                             | (0xffU 
                                                & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data)))
                                      : ((1U == (IData)(vlSelfRef.top__DOT__LoadSizeM))
                                          ? ((IData)(vlSelfRef.top__DOT__LoadUnsignedM)
                                              ? (0xffffU 
                                                 & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data)
                                              : (((- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
                                                                 >> 0xfU)))) 
                                                  << 0x10U) 
                                                 | (0xffffU 
                                                    & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data)))
                                          : vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data));
    vlSelfRef.top__DOT__RegWriteE = ((1U & (~ (IData)(vlSelfRef.rst))) 
                                     && ((1U & (~ (IData)(vlSelfRef.top__DOT__flush_d_exec))) 
                                         && (IData)(vlSelfRef.top__DOT__RegWriteD)));
    vlSelfRef.top__DOT__ForwardAE = 0U;
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__PCD = 0U;
        vlSelfRef.top__DOT__ResultSrcM = 0U;
        vlSelfRef.top__DOT__PCPlus4M = 0U;
        vlSelfRef.top__DOT__SizeWriteE = 0U;
        vlSelfRef.top__DOT__RdM = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__flush_f_d)))) {
            if (vlSelfRef.top__DOT__F_Write) {
                vlSelfRef.top__DOT__PCD = vlSelfRef.top__DOT__pc_block__DOT__internal_pc;
            }
        }
        vlSelfRef.top__DOT__ResultSrcM = vlSelfRef.top__DOT__ResultSrcE;
        vlSelfRef.top__DOT__PCPlus4M = vlSelfRef.top__DOT__PCPlus4E;
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__flush_d_exec)))) {
            vlSelfRef.top__DOT__SizeWriteE = vlSelfRef.top__DOT__SizeWriteD;
        }
        vlSelfRef.top__DOT__RdM = vlSelfRef.top__DOT__RdE;
    }
    if ((((IData)(vlSelfRef.top__DOT__RegWriteM) & 
          (0U != (IData)(vlSelfRef.top__DOT__RdM))) 
         & ((IData)(vlSelfRef.top__DOT__RdM) == (IData)(vlSelfRef.top__DOT__Rs1E)))) {
        vlSelfRef.top__DOT__ForwardAE = 2U;
    } else if ((((IData)(vlSelfRef.top__DOT__RegWriteW) 
                 & (0U != (IData)(vlSelfRef.top__DOT__RdW))) 
                & ((IData)(vlSelfRef.top__DOT__RdW) 
                   == (IData)(vlSelfRef.top__DOT__Rs1E)))) {
        vlSelfRef.top__DOT__ForwardAE = 1U;
    }
    vlSelfRef.top__DOT__ForwardBE = 0U;
    if ((((IData)(vlSelfRef.top__DOT__RegWriteM) & 
          (0U != (IData)(vlSelfRef.top__DOT__RdM))) 
         & ((IData)(vlSelfRef.top__DOT__RdM) == (IData)(vlSelfRef.top__DOT__Rs2E)))) {
        vlSelfRef.top__DOT__ForwardBE = 2U;
    } else if ((((IData)(vlSelfRef.top__DOT__RegWriteW) 
                 & (0U != (IData)(vlSelfRef.top__DOT__RdW))) 
                & ((IData)(vlSelfRef.top__DOT__RdW) 
                   == (IData)(vlSelfRef.top__DOT__Rs2E)))) {
        vlSelfRef.top__DOT__ForwardBE = 1U;
    }
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__ResultSrcE = 0U;
        vlSelfRef.top__DOT__PCPlus4E = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__flush_d_exec)))) {
        vlSelfRef.top__DOT__ResultSrcE = vlSelfRef.top__DOT__ResultSrcD;
        vlSelfRef.top__DOT__PCPlus4E = vlSelfRef.top__DOT__PCPlus4D;
    }
    vlSelfRef.top__DOT__ALUop1 = ((IData)(vlSelfRef.top__DOT__ALUSrc2E)
                                   ? vlSelfRef.top__DOT__PCPlus4E
                                   : ((1U & (IData)(vlSelfRef.top__DOT__ForwardAE))
                                       ? vlSelfRef.top__DOT__ResultW
                                       : vlSelfRef.top__DOT__RD1E));
    vlSelfRef.top__DOT__WriteDataE = ((1U & (IData)(vlSelfRef.top__DOT__ForwardBE))
                                       ? vlSelfRef.top__DOT__ResultW
                                       : vlSelfRef.top__DOT__RD2E);
    vlSelfRef.top__DOT__SrcBE = ((IData)(vlSelfRef.top__DOT__ALUSrcE)
                                  ? vlSelfRef.top__DOT__ExtImmE
                                  : vlSelfRef.top__DOT__WriteDataE);
    vlSelfRef.top__DOT__EQ = (vlSelfRef.top__DOT__ALUop1 
                              == vlSelfRef.top__DOT__SrcBE);
    __VdfgRegularize_h038a369a_0_3 = (vlSelfRef.top__DOT__ALUop1 
                                      + vlSelfRef.top__DOT__SrcBE);
    vlSelfRef.top__DOT__LT = VL_LTS_III(32, vlSelfRef.top__DOT__ALUop1, vlSelfRef.top__DOT__SrcBE);
    vlSelfRef.top__DOT__LTU = (vlSelfRef.top__DOT__ALUop1 
                               < vlSelfRef.top__DOT__SrcBE);
    vlSelfRef.top__DOT__ImmSrcD = 0U;
    vlSelfRef.top__DOT__ResultSrcD = 0U;
    vlSelfRef.top__DOT__ALUSrcD = 0U;
    vlSelfRef.top__DOT__MemWriteD = 0U;
    vlSelfRef.top__DOT__LoadSizeD = 2U;
    vlSelfRef.top__DOT__ALUSrc2D = 0U;
    vlSelfRef.top__DOT__LoadUnsignedD = 0U;
    vlSelfRef.top__DOT__SizeWriteD = 0U;
    vlSelfRef.top__DOT__ALUCtrlD = 0U;
    vlSelfRef.top__DOT__RegWriteD = 0U;
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__RdE = 0U;
        vlSelfRef.top__DOT__PCPlus4D = 0U;
        vlSelfRef.top__DOT__InstrD = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__flush_d_exec)))) {
            vlSelfRef.top__DOT__RdE = (0x1fU & (vlSelfRef.top__DOT__InstrD 
                                                >> 7U));
        }
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__flush_f_d)))) {
            if (vlSelfRef.top__DOT__F_Write) {
                vlSelfRef.top__DOT__PCPlus4D = ((IData)(4U) 
                                                + vlSelfRef.top__DOT__pc_block__DOT__internal_pc);
            }
        }
        if (vlSelfRef.top__DOT__flush_f_d) {
            vlSelfRef.top__DOT__InstrD = 0x33U;
        } else if (vlSelfRef.top__DOT__F_Write) {
            vlSelfRef.top__DOT__InstrD = (((vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                            [(0x1ffffU 
                                              & ((IData)(3U) 
                                                 + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                            << 0x18U) 
                                           | (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                              [(0x1ffffU 
                                                & ((IData)(2U) 
                                                   + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                              << 0x10U)) 
                                          | ((vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                              [(0x1ffffU 
                                                & ((IData)(1U) 
                                                   + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                              << 8U) 
                                             | vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                             [(0x1ffffU 
                                               & vlSelfRef.top__DOT__pc_block__DOT__internal_pc)]));
        }
    }
    vlSelfRef.top__DOT__hazard_unit__DOT__wStall = 
        ((1U == (IData)(vlSelfRef.top__DOT__ResultSrcE)) 
         & ((0U != (IData)(vlSelfRef.top__DOT__RdE)) 
            & (((IData)(vlSelfRef.top__DOT__RdE) == 
                (0x1fU & (vlSelfRef.top__DOT__InstrD 
                          >> 0xfU))) | ((IData)(vlSelfRef.top__DOT__RdE) 
                                        == (0x1fU & 
                                            (vlSelfRef.top__DOT__InstrD 
                                             >> 0x14U))))));
    vlSelfRef.top__DOT__pc_block__DOT__internal_pc 
        = ((IData)(vlSelfRef.top__DOT__PCWrite) ? ((IData)(vlSelfRef.rst)
                                                    ? 0x10000U
                                                    : 
                                                   ((0U 
                                                     == (IData)(vlSelfRef.top__DOT__PCSrcE))
                                                     ? vlSelfRef.top__DOT__pc_block__DOT__inc_pc
                                                     : 
                                                    ((1U 
                                                      == (IData)(vlSelfRef.top__DOT__PCSrcE))
                                                      ? vlSelfRef.top__DOT__pc_block__DOT__branch_pc
                                                      : 
                                                     ((2U 
                                                       == (IData)(vlSelfRef.top__DOT__PCSrcE))
                                                       ? vlSelfRef.top__DOT__ALUResultE
                                                       : vlSelfRef.top__DOT__pc_block__DOT__inc_pc))))
            : vlSelfRef.top__DOT__PCF);
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__PCSrcE = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__flush_d_exec)))) {
        vlSelfRef.top__DOT__PCSrcE = vlSelfRef.top__DOT__PCSrcD;
    }
    vlSelfRef.top__DOT__F_Write = 1U;
    vlSelfRef.top__DOT__PCWrite = 1U;
    vlSelfRef.top__DOT__ALUResultE = ((8U & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                       ? ((4U & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                           ? 0U : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                     ? 
                                                    (__VdfgRegularize_h038a369a_0_3 
                                                     - (IData)(4U))
                                                     : vlSelfRef.top__DOT__SrcBE)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                     ? 
                                                    ((IData)(vlSelfRef.top__DOT__LTU)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    ((IData)(vlSelfRef.top__DOT__LT)
                                                      ? 1U
                                                      : 0U))))
                                       : ((4U & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                           ? ((2U & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelfRef.top__DOT__ALUop1, 
                                                                 (0x1fU 
                                                                  & vlSelfRef.top__DOT__SrcBE))
                                                   : 
                                                  VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__ALUop1, 
                                                                (0x1fU 
                                                                 & vlSelfRef.top__DOT__SrcBE)))
                                               : ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                   ? 
                                                  VL_SHIFTL_III(32,32,32, vlSelfRef.top__DOT__ALUop1, 
                                                                (0x1fU 
                                                                 & vlSelfRef.top__DOT__SrcBE))
                                                   : 
                                                  (vlSelfRef.top__DOT__ALUop1 
                                                   ^ vlSelfRef.top__DOT__SrcBE)))
                                           : ((2U & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                   ? 
                                                  (vlSelfRef.top__DOT__ALUop1 
                                                   | vlSelfRef.top__DOT__SrcBE)
                                                   : 
                                                  (vlSelfRef.top__DOT__ALUop1 
                                                   & vlSelfRef.top__DOT__SrcBE))
                                               : ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                   ? 
                                                  (vlSelfRef.top__DOT__ALUop1 
                                                   - vlSelfRef.top__DOT__SrcBE)
                                                   : __VdfgRegularize_h038a369a_0_3))));
    vlSelfRef.top__DOT__PCF = vlSelfRef.top__DOT__pc_block__DOT__internal_pc;
    vlSelfRef.top__DOT__pc_block__DOT__inc_pc = ((IData)(4U) 
                                                 + vlSelfRef.top__DOT__pc_block__DOT__internal_pc);
    vlSelfRef.top__DOT__pc_block__DOT__branch_pc = 
        ((vlSelfRef.top__DOT__ExtImmE + vlSelfRef.top__DOT__PCE) 
         + vlSelfRef.top__DOT__pc_block__DOT__internal_pc);
    vlSelfRef.top__DOT__PCSrcD = 0U;
    if (((((((((0x37U == (0x7fU & vlSelfRef.top__DOT__InstrD)) 
               | (0x17U == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
              | (0x6fU == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
             | (0x67U == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
            | (0x63U == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
           | (3U == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
          | (0x23U == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
         | (0x13U == (0x7fU & vlSelfRef.top__DOT__InstrD)))) {
        if ((0x37U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
            vlSelfRef.top__DOT__ImmSrcD = 4U;
            vlSelfRef.top__DOT__ResultSrcD = 0U;
            vlSelfRef.top__DOT__ALUSrcD = 1U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__ALUSrc2D = 0U;
            vlSelfRef.top__DOT__SizeWriteD = 0U;
            vlSelfRef.top__DOT__ALUCtrlD = 0xaU;
            vlSelfRef.top__DOT__RegWriteD = 1U;
            vlSelfRef.top__DOT__PCSrcD = 0U;
        } else if ((0x17U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
            vlSelfRef.top__DOT__ImmSrcD = 4U;
            vlSelfRef.top__DOT__ResultSrcD = 0U;
            vlSelfRef.top__DOT__ALUSrcD = 1U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__ALUSrc2D = 1U;
            vlSelfRef.top__DOT__SizeWriteD = 0U;
            vlSelfRef.top__DOT__ALUCtrlD = 0xbU;
            vlSelfRef.top__DOT__RegWriteD = 1U;
            vlSelfRef.top__DOT__PCSrcD = 0U;
        } else {
            if ((0x6fU == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                vlSelfRef.top__DOT__ImmSrcD = 3U;
                vlSelfRef.top__DOT__ResultSrcD = 2U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__SizeWriteD = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
                vlSelfRef.top__DOT__PCSrcD = 1U;
            } else if ((0x67U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 2U;
                vlSelfRef.top__DOT__ALUSrcD = 1U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__SizeWriteD = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
                vlSelfRef.top__DOT__PCSrcD = 2U;
            } else if ((0x63U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                if ((0x4000U & vlSelfRef.top__DOT__InstrD)) {
                    vlSelfRef.top__DOT__ImmSrcD = 2U;
                    vlSelfRef.top__DOT__ALUCtrlD = 1U;
                    vlSelfRef.top__DOT__PCSrcD = ((0x2000U 
                                                   & vlSelfRef.top__DOT__InstrD)
                                                   ? 
                                                  ((0x1000U 
                                                    & vlSelfRef.top__DOT__InstrD)
                                                    ? 
                                                   ((IData)(vlSelfRef.top__DOT__LTU)
                                                     ? 0U
                                                     : 1U)
                                                    : 
                                                   ((IData)(vlSelfRef.top__DOT__LTU)
                                                     ? 1U
                                                     : 0U))
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelfRef.top__DOT__InstrD)
                                                    ? 
                                                   ((IData)(vlSelfRef.top__DOT__LT)
                                                     ? 0U
                                                     : 1U)
                                                    : 
                                                   ((IData)(vlSelfRef.top__DOT__LT)
                                                     ? 1U
                                                     : 0U)));
                } else if ((0x2000U & vlSelfRef.top__DOT__InstrD)) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 0U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else {
                    vlSelfRef.top__DOT__ImmSrcD = 2U;
                    vlSelfRef.top__DOT__ALUCtrlD = 1U;
                    vlSelfRef.top__DOT__PCSrcD = ((0x1000U 
                                                   & vlSelfRef.top__DOT__InstrD)
                                                   ? 
                                                  ((IData)(vlSelfRef.top__DOT__EQ)
                                                    ? 0U
                                                    : 1U)
                                                   : 
                                                  ((IData)(vlSelfRef.top__DOT__EQ)
                                                    ? 1U
                                                    : 0U));
                }
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__SizeWriteD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 0U;
            } else if ((3U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 1U;
                vlSelfRef.top__DOT__ALUSrcD = 1U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__SizeWriteD = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
            } else if ((0x23U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                if ((0U == (7U & (vlSelfRef.top__DOT__InstrD 
                                  >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 1U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 1U;
                    vlSelfRef.top__DOT__SizeWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((1U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 1U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 1U;
                    vlSelfRef.top__DOT__SizeWriteD = 1U;
                    vlSelfRef.top__DOT__ALUCtrlD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((2U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 1U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 1U;
                    vlSelfRef.top__DOT__SizeWriteD = 2U;
                    vlSelfRef.top__DOT__ALUCtrlD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                }
            } else {
                if ((0U == (7U & (vlSelfRef.top__DOT__InstrD 
                                  >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 0U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((2U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 8U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((3U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 9U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((4U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 4U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((6U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 3U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((7U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 2U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((1U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    if ((0U == (vlSelfRef.top__DOT__InstrD 
                                >> 0x19U))) {
                        vlSelfRef.top__DOT__ImmSrcD = 0U;
                        vlSelfRef.top__DOT__ResultSrcD = 0U;
                        vlSelfRef.top__DOT__ALUSrcD = 1U;
                        vlSelfRef.top__DOT__MemWriteD = 0U;
                        vlSelfRef.top__DOT__ALUCtrlD = 5U;
                        vlSelfRef.top__DOT__PCSrcD = 0U;
                    }
                } else if ((5U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    if ((0U == (vlSelfRef.top__DOT__InstrD 
                                >> 0x19U))) {
                        vlSelfRef.top__DOT__ImmSrcD = 0U;
                        vlSelfRef.top__DOT__ResultSrcD = 0U;
                        vlSelfRef.top__DOT__ALUSrcD = 1U;
                        vlSelfRef.top__DOT__MemWriteD = 0U;
                        vlSelfRef.top__DOT__ALUCtrlD = 6U;
                        vlSelfRef.top__DOT__PCSrcD = 0U;
                    } else if ((0x20U == (vlSelfRef.top__DOT__InstrD 
                                          >> 0x19U))) {
                        vlSelfRef.top__DOT__ImmSrcD = 0U;
                        vlSelfRef.top__DOT__ResultSrcD = 0U;
                        vlSelfRef.top__DOT__ALUSrcD = 1U;
                        vlSelfRef.top__DOT__MemWriteD = 0U;
                        vlSelfRef.top__DOT__ALUCtrlD = 7U;
                        vlSelfRef.top__DOT__PCSrcD = 0U;
                    }
                }
                vlSelfRef.top__DOT__RegWriteD = ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.top__DOT__InstrD 
                                                      >> 0xcU))) 
                                                 || ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlSelfRef.top__DOT__InstrD 
                                                          >> 0xcU))) 
                                                     || ((3U 
                                                          == 
                                                          (7U 
                                                           & (vlSelfRef.top__DOT__InstrD 
                                                              >> 0xcU))) 
                                                         || ((4U 
                                                              == 
                                                              (7U 
                                                               & (vlSelfRef.top__DOT__InstrD 
                                                                  >> 0xcU))) 
                                                             || ((6U 
                                                                  == 
                                                                  (7U 
                                                                   & (vlSelfRef.top__DOT__InstrD 
                                                                      >> 0xcU))) 
                                                                 || ((7U 
                                                                      == 
                                                                      (7U 
                                                                       & (vlSelfRef.top__DOT__InstrD 
                                                                          >> 0xcU))) 
                                                                     || ((1U 
                                                                          == 
                                                                          (7U 
                                                                           & (vlSelfRef.top__DOT__InstrD 
                                                                              >> 0xcU)))
                                                                          ? 
                                                                         (0U 
                                                                          == 
                                                                          (vlSelfRef.top__DOT__InstrD 
                                                                           >> 0x19U))
                                                                          : 
                                                                         ((5U 
                                                                           == 
                                                                           (7U 
                                                                            & (vlSelfRef.top__DOT__InstrD 
                                                                               >> 0xcU))) 
                                                                          && ((0U 
                                                                               == 
                                                                               (vlSelfRef.top__DOT__InstrD 
                                                                                >> 0x19U)) 
                                                                              || (0x20U 
                                                                                == 
                                                                                (vlSelfRef.top__DOT__InstrD 
                                                                                >> 0x19U)))))))))));
            }
            if ((0x6fU != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                if ((0x67U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                    if ((0x63U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                        if ((1U & (~ (vlSelfRef.top__DOT__InstrD 
                                      >> 0xeU)))) {
                            if ((0x2000U & vlSelfRef.top__DOT__InstrD)) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            }
                        }
                    } else if ((3U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                        if ((0x23U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                            if ((0U == (7U & (vlSelfRef.top__DOT__InstrD 
                                              >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((2U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((3U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((4U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((6U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((7U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((1U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                if ((0U == (vlSelfRef.top__DOT__InstrD 
                                            >> 0x19U))) {
                                    vlSelfRef.top__DOT__ALUSrc2D = 0U;
                                }
                            } else if ((5U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                if ((0U == (vlSelfRef.top__DOT__InstrD 
                                            >> 0x19U))) {
                                    vlSelfRef.top__DOT__ALUSrc2D = 0U;
                                } else if ((0x20U == 
                                            (vlSelfRef.top__DOT__InstrD 
                                             >> 0x19U))) {
                                    vlSelfRef.top__DOT__ALUSrc2D = 0U;
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((0x37U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
            if ((0x17U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                if ((0x6fU != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                    if ((0x67U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                        if ((0x63U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                            if ((3U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                                vlSelfRef.top__DOT__LoadSizeD 
                                    = ((0x4000U & vlSelfRef.top__DOT__InstrD)
                                        ? ((0x2000U 
                                            & vlSelfRef.top__DOT__InstrD)
                                            ? 2U : 
                                           ((0x1000U 
                                             & vlSelfRef.top__DOT__InstrD)
                                             ? 1U : 0U))
                                        : ((0x2000U 
                                            & vlSelfRef.top__DOT__InstrD)
                                            ? 2U : 
                                           ((0x1000U 
                                             & vlSelfRef.top__DOT__InstrD)
                                             ? 1U : 0U)));
                                vlSelfRef.top__DOT__LoadUnsignedD 
                                    = ((1U & (vlSelfRef.top__DOT__InstrD 
                                              >> 0xeU)) 
                                       && (1U & (~ 
                                                 (vlSelfRef.top__DOT__InstrD 
                                                  >> 0xdU))));
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x33U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
        if ((0U == (7U & (vlSelfRef.top__DOT__InstrD 
                          >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 0U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
            } else if ((0x20U == (vlSelfRef.top__DOT__InstrD 
                                  >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 1U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
            }
            vlSelfRef.top__DOT__RegWriteD = ((0U == 
                                              (vlSelfRef.top__DOT__InstrD 
                                               >> 0x19U)) 
                                             || (0x20U 
                                                 == 
                                                 (vlSelfRef.top__DOT__InstrD 
                                                  >> 0x19U)));
        } else if ((1U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 5U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
            } else {
                vlSelfRef.top__DOT__RegWriteD = 0U;
            }
        } else if ((2U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 8U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
            } else {
                vlSelfRef.top__DOT__RegWriteD = 0U;
            }
        } else if ((3U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 9U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
            } else {
                vlSelfRef.top__DOT__RegWriteD = 0U;
            }
        } else if ((4U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 4U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
            } else {
                vlSelfRef.top__DOT__RegWriteD = 0U;
            }
        } else if ((5U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 6U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
            } else if ((0x20U == (vlSelfRef.top__DOT__InstrD 
                                  >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 7U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
            }
            vlSelfRef.top__DOT__RegWriteD = ((0U == 
                                              (vlSelfRef.top__DOT__InstrD 
                                               >> 0x19U)) 
                                             || (0x20U 
                                                 == 
                                                 (vlSelfRef.top__DOT__InstrD 
                                                  >> 0x19U)));
        } else if ((6U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 3U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
            } else {
                vlSelfRef.top__DOT__RegWriteD = 0U;
            }
        } else {
            if ((7U == (7U & (vlSelfRef.top__DOT__InstrD 
                              >> 0xcU)))) {
                if ((0U == (vlSelfRef.top__DOT__InstrD 
                            >> 0x19U))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 0U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUSrc2D = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 2U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                }
            }
            vlSelfRef.top__DOT__RegWriteD = ((7U == 
                                              (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU))) 
                                             && (0U 
                                                 == 
                                                 (vlSelfRef.top__DOT__InstrD 
                                                  >> 0x19U)));
        }
    }
    vlSelfRef.top__DOT__flush_f_d = 0U;
    vlSelfRef.top__DOT__flush_d_exec = 0U;
    if (((2U == (IData)(vlSelfRef.top__DOT__PCSrcE)) 
         | (1U == (IData)(vlSelfRef.top__DOT__PCSrcE)))) {
        vlSelfRef.top__DOT__flush_f_d = 1U;
        vlSelfRef.top__DOT__flush_d_exec = 1U;
    }
    if (vlSelfRef.top__DOT__hazard_unit__DOT__wStall) {
        vlSelfRef.top__DOT__F_Write = 0U;
        vlSelfRef.top__DOT__PCWrite = 0U;
        vlSelfRef.top__DOT__flush_d_exec = 1U;
    }
}

void Vdut___024root___eval_triggers__act(Vdut___024root* vlSelf);

bool Vdut___024root___eval_phase__act(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__act\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdut___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdut___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdut___024root___eval_phase__nba(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__nba\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdut___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__nba(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf);
#endif  // VL_DEBUG

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/tahamunir/Downloads/Team5-Full-RV32I-Design-Pipelining-4/challengelab4/rtl/top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vdut___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/tahamunir/Downloads/Team5-Full-RV32I-Design-Pipelining-4/challengelab4/rtl/top.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdut___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdut___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
