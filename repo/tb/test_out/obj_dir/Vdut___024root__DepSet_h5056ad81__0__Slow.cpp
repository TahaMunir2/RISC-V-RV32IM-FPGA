// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___initial__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___initial__TOP__0\n"); );
    // Body
    vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x80U, vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i)) {
        vlSelf->l1i_cache__DOT__cache[(0x7fU & vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i)][9U] 
            = (0xfffU & vlSelf->l1i_cache__DOT__cache
               [(0x7fU & vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i)][9U]);
        vlSelf->l1i_cache__DOT__cache[(0x7fU & vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i)][4U] 
            = (0xffdfffffU & vlSelf->l1i_cache__DOT__cache
               [(0x7fU & vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i)][4U]);
        vlSelf->l1i_cache__DOT__cache[(0x7fU & vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i)][9U] 
            = (0x17ffU & vlSelf->l1i_cache__DOT__cache
               [(0x7fU & vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i)][9U]);
        vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i);
    }
}

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    // Body
    Vdut___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    // Body
    Vdut___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vdut___024root___final(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___final\n"); );
}

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->fetch = VL_RAND_RESET_I(1);
    vlSelf->addr = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->line_from_mem);
    vlSelf->LoadSize = VL_RAND_RESET_I(2);
    vlSelf->LoadUnsigned = VL_RAND_RESET_I(1);
    vlSelf->wake = VL_RAND_RESET_I(1);
    vlSelf->data_out = VL_RAND_RESET_I(32);
    vlSelf->stall = VL_RAND_RESET_I(1);
    vlSelf->l1i_cache__DOT__wr_en = VL_RAND_RESET_I(1);
    vlSelf->l1i_cache__DOT__rd_en = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->l1i_cache__DOT__write_data);
    vlSelf->l1i_cache__DOT__way = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<128; ++__Vi0) {
        VL_RAND_RESET_W(301, vlSelf->l1i_cache__DOT__cache[__Vi0]);
    }
    vlSelf->l1i_cache__DOT__hit0 = VL_RAND_RESET_I(1);
    vlSelf->l1i_cache__DOT__hit1 = VL_RAND_RESET_I(1);
    vlSelf->l1i_cache__DOT__valid0 = VL_RAND_RESET_I(1);
    vlSelf->l1i_cache__DOT__valid1 = VL_RAND_RESET_I(1);
    vlSelf->l1i_cache__DOT__miss = VL_RAND_RESET_I(1);
    vlSelf->l1i_cache__DOT__bottom_bit = VL_RAND_RESET_I(7);
    vlSelf->l1i_cache__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0=0; __Vi0<128; ++__Vi0) {
        VL_RAND_RESET_W(301, vlSelf->__Vchglast__TOP__l1i_cache__DOT__cache[__Vi0]);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
