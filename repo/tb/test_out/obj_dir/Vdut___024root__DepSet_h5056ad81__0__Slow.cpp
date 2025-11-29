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

VL_ATTR_COLD void Vdut___024root___settle__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->l2_addr = vlSelf->addr;
    vlSelf->l1i_cache__DOT__hit0 = ((((0x1fffffU & 
                                       vlSelf->l1i_cache__DOT__cache
                                       [(0x7fU & (vlSelf->addr 
                                                  >> 4U))][4U]) 
                                      == (vlSelf->addr 
                                          >> 0xbU)) 
                                     & (vlSelf->l1i_cache__DOT__cache
                                        [(0x7fU & (vlSelf->addr 
                                                   >> 4U))][4U] 
                                        >> 0x15U)) 
                                    & (IData)(vlSelf->fetch));
    vlSelf->l1i_cache__DOT__hit1 = ((((0x1fffffU & 
                                       ((vlSelf->l1i_cache__DOT__cache
                                         [(0x7fU & 
                                           (vlSelf->addr 
                                            >> 4U))][9U] 
                                         << 0xaU) | 
                                        (vlSelf->l1i_cache__DOT__cache
                                         [(0x7fU & 
                                           (vlSelf->addr 
                                            >> 4U))][8U] 
                                         >> 0x16U))) 
                                      == (vlSelf->addr 
                                          >> 0xbU)) 
                                     & (vlSelf->l1i_cache__DOT__cache
                                        [(0x7fU & (vlSelf->addr 
                                                   >> 4U))][9U] 
                                        >> 0xbU)) & (IData)(vlSelf->fetch));
    vlSelf->l1i_cache__DOT__miss = ((~ ((IData)(vlSelf->l1i_cache__DOT__hit0) 
                                        | (IData)(vlSelf->l1i_cache__DOT__hit1))) 
                                    & (IData)(vlSelf->fetch));
    vlSelf->l1i_cache__DOT__valid0 = (1U & (vlSelf->l1i_cache__DOT__cache
                                            [(0x7fU 
                                              & (vlSelf->addr 
                                                 >> 4U))][4U] 
                                            >> 0x15U));
    vlSelf->l1i_cache__DOT__valid1 = (1U & (vlSelf->l1i_cache__DOT__cache
                                            [(0x7fU 
                                              & (vlSelf->addr 
                                                 >> 4U))][9U] 
                                            >> 0xbU));
    vlSelf->stall = 0U;
    vlSelf->l1i_cache__DOT__wr_en = 0U;
    vlSelf->l1i_cache__DOT__rd_en = 0U;
    vlSelf->l1i_cache__DOT__write_data[0U] = 0U;
    vlSelf->l1i_cache__DOT__write_data[1U] = 0U;
    vlSelf->l1i_cache__DOT__write_data[2U] = 0U;
    vlSelf->l1i_cache__DOT__write_data[3U] = 0U;
    vlSelf->data_out = 0U;
    vlSelf->l2_fetch = 0U;
    if (vlSelf->fetch) {
        if (vlSelf->l1i_cache__DOT__miss) {
            vlSelf->l1i_cache__DOT__way = ((~ ((~ (IData)(vlSelf->l1i_cache__DOT__valid0)) 
                                               & (~ (IData)(vlSelf->l1i_cache__DOT__valid1)))) 
                                           & ((IData)(vlSelf->l1i_cache__DOT__valid0) 
                                              & ((~ (IData)(vlSelf->l1i_cache__DOT__valid1)) 
                                                 | (~ 
                                                    (vlSelf->l1i_cache__DOT__cache
                                                     [
                                                     (0x7fU 
                                                      & (vlSelf->addr 
                                                         >> 4U))][9U] 
                                                     >> 0xcU)))));
            if (vlSelf->wake) {
                vlSelf->l1i_cache__DOT__rd_en = 0U;
                vlSelf->l1i_cache__DOT__wr_en = 1U;
                vlSelf->stall = 0U;
                vlSelf->l1i_cache__DOT__write_data[0U] 
                    = vlSelf->line_from_mem[0U];
                vlSelf->l1i_cache__DOT__write_data[1U] 
                    = vlSelf->line_from_mem[1U];
                vlSelf->l1i_cache__DOT__write_data[2U] 
                    = vlSelf->line_from_mem[2U];
                vlSelf->l1i_cache__DOT__write_data[3U] 
                    = vlSelf->line_from_mem[3U];
            } else {
                vlSelf->l1i_cache__DOT__rd_en = 0U;
                vlSelf->l1i_cache__DOT__wr_en = 0U;
                vlSelf->stall = 1U;
                vlSelf->l2_fetch = 1U;
            }
        } else {
            vlSelf->l1i_cache__DOT__way = vlSelf->l1i_cache__DOT__hit1;
            vlSelf->l1i_cache__DOT__rd_en = 1U;
        }
    }
    if (vlSelf->l1i_cache__DOT__rd_en) {
        vlSelf->l1i_cache__DOT__cache[(0x7fU & (vlSelf->addr 
                                                >> 4U))][9U] 
            = ((0xfffU & vlSelf->l1i_cache__DOT__cache
                [(0x7fU & (vlSelf->addr >> 4U))][9U]) 
               | (0x1fffU & ((IData)(vlSelf->l1i_cache__DOT__way) 
                             << 0xcU)));
        if (vlSelf->l1i_cache__DOT__way) {
            if (vlSelf->l1i_cache__DOT__way) {
                vlSelf->data_out = ((8U & vlSelf->addr)
                                     ? ((4U & vlSelf->addr)
                                         ? ((vlSelf->l1i_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelf->addr 
                                                  >> 4U))][8U] 
                                             << 0xaU) 
                                            | (vlSelf->l1i_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelf->addr 
                                                    >> 4U))][7U] 
                                               >> 0x16U))
                                         : ((vlSelf->l1i_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelf->addr 
                                                  >> 4U))][7U] 
                                             << 0xaU) 
                                            | (vlSelf->l1i_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelf->addr 
                                                    >> 4U))][6U] 
                                               >> 0x16U)))
                                     : ((4U & vlSelf->addr)
                                         ? ((vlSelf->l1i_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelf->addr 
                                                  >> 4U))][6U] 
                                             << 0xaU) 
                                            | (vlSelf->l1i_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelf->addr 
                                                    >> 4U))][5U] 
                                               >> 0x16U))
                                         : ((vlSelf->l1i_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelf->addr 
                                                  >> 4U))][5U] 
                                             << 0xaU) 
                                            | (vlSelf->l1i_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelf->addr 
                                                    >> 4U))][4U] 
                                               >> 0x16U))));
            }
        } else {
            vlSelf->data_out = ((8U & vlSelf->addr)
                                 ? ((4U & vlSelf->addr)
                                     ? vlSelf->l1i_cache__DOT__cache
                                    [(0x7fU & (vlSelf->addr 
                                               >> 4U))][3U]
                                     : vlSelf->l1i_cache__DOT__cache
                                    [(0x7fU & (vlSelf->addr 
                                               >> 4U))][2U])
                                 : ((4U & vlSelf->addr)
                                     ? vlSelf->l1i_cache__DOT__cache
                                    [(0x7fU & (vlSelf->addr 
                                               >> 4U))][1U]
                                     : vlSelf->l1i_cache__DOT__cache
                                    [(0x7fU & (vlSelf->addr 
                                               >> 4U))][0U]));
        }
        if ((0U == (IData)(vlSelf->LoadSize))) {
            vlSelf->l1i_cache__DOT__bottom_bit = (0x18U 
                                                  & (vlSelf->addr 
                                                     << 3U));
            vlSelf->data_out = ((IData)(vlSelf->LoadUnsigned)
                                 ? (0xffU & (vlSelf->data_out 
                                             >> (0x1fU 
                                                 & (IData)(vlSelf->l1i_cache__DOT__bottom_bit))))
                                 : (((- (IData)((1U 
                                                 & (vlSelf->data_out 
                                                    >> 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        + (IData)(vlSelf->l1i_cache__DOT__bottom_bit))))))) 
                                     << 8U) | (0xffU 
                                               & (vlSelf->data_out 
                                                  >> 
                                                  (0x1fU 
                                                   & (IData)(vlSelf->l1i_cache__DOT__bottom_bit))))));
        } else if ((1U == (IData)(vlSelf->LoadSize))) {
            vlSelf->l1i_cache__DOT__bottom_bit = (0x30U 
                                                  & (vlSelf->addr 
                                                     << 4U));
            vlSelf->data_out = ((IData)(vlSelf->LoadUnsigned)
                                 ? (0xffffU & (vlSelf->data_out 
                                               >> (0x1fU 
                                                   & (IData)(vlSelf->l1i_cache__DOT__bottom_bit))))
                                 : (((- (IData)((1U 
                                                 & (vlSelf->data_out 
                                                    >> 
                                                    (0x1fU 
                                                     & ((IData)(0xfU) 
                                                        + (IData)(vlSelf->l1i_cache__DOT__bottom_bit))))))) 
                                     << 0x10U) | (0xffffU 
                                                  & (vlSelf->data_out 
                                                     >> 
                                                     (0x1fU 
                                                      & (IData)(vlSelf->l1i_cache__DOT__bottom_bit))))));
        }
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

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    // Body
    Vdut___024root___settle__TOP__0(vlSelf);
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
    vlSelf->l2_addr = VL_RAND_RESET_I(32);
    vlSelf->l2_fetch = VL_RAND_RESET_I(1);
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
