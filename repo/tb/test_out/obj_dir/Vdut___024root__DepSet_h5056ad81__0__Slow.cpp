// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___settle__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->l2_cache__DOT__fetch = 0U;
    vlSelf->l2_cache__DOT__req_i = 0U;
    vlSelf->l2_cache__DOT__req_d = 0U;
    vlSelf->l2_cache__DOT__l1write = 0U;
    if ((1U & ((~ (IData)(vlSelf->fetch_i)) & (~ (IData)(vlSelf->fetch_d))))) {
        vlSelf->l2_cache__DOT__fetch = 0U;
        vlSelf->l2_cache__DOT__l1write = 0U;
    } else if (((IData)(vlSelf->fetch_i) & (~ (IData)(vlSelf->fetch_d)))) {
        vlSelf->l2_cache__DOT__fetch = 1U;
        vlSelf->l2_cache__DOT__l1write = 0U;
    } else if (((~ (IData)(vlSelf->fetch_i)) & (IData)(vlSelf->fetch_d))) {
        vlSelf->l2_cache__DOT__fetch = 1U;
        vlSelf->l2_cache__DOT__l1write = vlSelf->l1write_back_en;
    } else if (((IData)(vlSelf->fetch_i) & (IData)(vlSelf->fetch_d))) {
        vlSelf->l2_cache__DOT__fetch = 1U;
        vlSelf->l2_cache__DOT__l1write = vlSelf->l1write_back_en;
    }
    vlSelf->l2_cache__DOT__addr = 0U;
    if ((1U & (~ ((~ (IData)(vlSelf->fetch_i)) & (~ (IData)(vlSelf->fetch_d)))))) {
        if (((IData)(vlSelf->fetch_i) & (~ (IData)(vlSelf->fetch_d)))) {
            vlSelf->l2_cache__DOT__req_i = 1U;
            vlSelf->l2_cache__DOT__addr = vlSelf->addr_i;
        } else if (((~ (IData)(vlSelf->fetch_i)) & (IData)(vlSelf->fetch_d))) {
            vlSelf->l2_cache__DOT__addr = vlSelf->addr_d;
        } else if (((IData)(vlSelf->fetch_i) & (IData)(vlSelf->fetch_d))) {
            vlSelf->l2_cache__DOT__addr = vlSelf->addr_d;
        }
        if ((1U & (~ ((IData)(vlSelf->fetch_i) & (~ (IData)(vlSelf->fetch_d)))))) {
            if (((~ (IData)(vlSelf->fetch_i)) & (IData)(vlSelf->fetch_d))) {
                vlSelf->l2_cache__DOT__req_d = 1U;
            } else if (((IData)(vlSelf->fetch_i) & (IData)(vlSelf->fetch_d))) {
                vlSelf->l2_cache__DOT__req_d = 1U;
            }
        }
    }
    vlSelf->l2_cache__DOT__tag_bits_wb = (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                          >> 0xdU);
    vlSelf->l2_cache__DOT__set_wb = (0xffU & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                              >> 5U));
    vlSelf->l2_cache__DOT__block_offset_wb = (7U & 
                                              (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                               >> 2U));
}

VL_ATTR_COLD void Vdut___024root___initial__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___initial__TOP__0\n"); );
    // Body
    vlSelf->l2_cache__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x80U, vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)) {
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][8U] 
            = (0xffefffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][8U] 
            = (0xfff7ffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x11U] 
            = (0xfffffdffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x11U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x11U] 
            = (0xfffffeffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x11U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x19U] 
            = (0xbfffffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x19U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x19U] 
            = (0xdfffffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x19U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U] 
            = (0x3f7ffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U] 
            = (0x3fbffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U]);
        vlSelf->l2_cache__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelf->l2_cache__DOT__unnamedblk1__DOT__i);
    }
}

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    Vdut___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    // Body
    Vdut___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
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
    vlSelf->fetch_i = VL_RAND_RESET_I(1);
    vlSelf->fetch_d = VL_RAND_RESET_I(1);
    vlSelf->addr_i = VL_RAND_RESET_I(32);
    vlSelf->addr_d = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(256, vlSelf->line_from_mem);
    VL_RAND_RESET_W(128, vlSelf->l1write_back_data);
    vlSelf->l1write_back_en = VL_RAND_RESET_I(1);
    vlSelf->l1write_back_addr = VL_RAND_RESET_I(32);
    vlSelf->ready = VL_RAND_RESET_I(1);
    vlSelf->wb_ready = VL_RAND_RESET_I(1);
    vlSelf->ready_i = VL_RAND_RESET_I(1);
    vlSelf->ready_d = VL_RAND_RESET_I(1);
    vlSelf->wb_ready_d = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->data_out);
    VL_RAND_RESET_W(128, vlSelf->write_back_data);
    vlSelf->write_back_addr = VL_RAND_RESET_I(32);
    vlSelf->write_back_en = VL_RAND_RESET_I(1);
    vlSelf->main_mem_addr = VL_RAND_RESET_I(1);
    vlSelf->main_mem_fetch = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        VL_RAND_RESET_W(1114, vlSelf->l2_cache__DOT__cache[__Vi0]);
    }
    vlSelf->l2_cache__DOT__wr_en = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__rd_en = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__wr_wb = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(256, vlSelf->l2_cache__DOT__write_data);
    vlSelf->l2_cache__DOT__way_rd = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(256, vlSelf->l2_cache__DOT__wmask);
    vlSelf->l2_cache__DOT__fetch = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__req_d = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__req_i = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__addr = VL_RAND_RESET_I(32);
    vlSelf->l2_cache__DOT__l1write = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__hit0 = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__hit1 = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__hit2 = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__hit3 = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__valid0 = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__valid1 = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__valid2 = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__valid3 = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__miss = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__evict = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->l2_cache__DOT__l1write_back_data_buffer);
    vlSelf->l2_cache__DOT__l1write_buffer = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__l1write_back_addr_buffer = VL_RAND_RESET_I(32);
    vlSelf->l2_cache__DOT__tag_bits_wb = VL_RAND_RESET_I(19);
    vlSelf->l2_cache__DOT__set_wb = VL_RAND_RESET_I(8);
    vlSelf->l2_cache__DOT__block_offset_wb = VL_RAND_RESET_I(3);
    vlSelf->l2_cache__DOT__hit0_wb = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__hit1_wb = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__hit2_wb = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__hit3_wb = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__miss_wb = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__way = VL_RAND_RESET_I(2);
    vlSelf->l2_cache__DOT__tag_bits = VL_RAND_RESET_I(19);
    vlSelf->l2_cache__DOT__set = VL_RAND_RESET_I(8);
    vlSelf->l2_cache__DOT__block_offset = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(256, vlSelf->l2_cache__DOT__l2write_back_data_buffer);
    vlSelf->l2_cache__DOT__l2write_buffer = VL_RAND_RESET_I(2);
    vlSelf->l2_cache__DOT__l2write_back_addr_buffer = VL_RAND_RESET_I(32);
    vlSelf->l2_cache__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
