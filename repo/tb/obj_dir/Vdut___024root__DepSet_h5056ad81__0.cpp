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
    CData/*6:0*/ __Vdlyvdim0__l1d_cache__DOT__cache__v0;
    IData/*31:0*/ __Vdlyvlsb__l1d_cache__DOT__cache__v0;
    CData/*0:0*/ __Vdlyvval__l1d_cache__DOT__cache__v0;
    CData/*6:0*/ __Vdlyvdim0__l1d_cache__DOT__cache__v1;
    IData/*31:0*/ __Vdlyvlsb__l1d_cache__DOT__cache__v1;
    CData/*0:0*/ __Vdlyvval__l1d_cache__DOT__cache__v1;
    CData/*0:0*/ __Vdlyvset__l1d_cache__DOT__cache__v1;
    CData/*6:0*/ __Vdlyvdim0__l1d_cache__DOT__cache__v2;
    IData/*31:0*/ __Vdlyvlsb__l1d_cache__DOT__cache__v2;
    CData/*0:0*/ __Vdlyvval__l1d_cache__DOT__cache__v2;
    CData/*0:0*/ __Vdlyvset__l1d_cache__DOT__cache__v2;
    CData/*6:0*/ __Vdlyvdim0__l1d_cache__DOT__cache__v3;
    IData/*31:0*/ __Vdlyvlsb__l1d_cache__DOT__cache__v3;
    VlWide<4>/*127:0*/ __Vdlyvval__l1d_cache__DOT__cache__v3;
    CData/*6:0*/ __Vdlyvdim0__l1d_cache__DOT__cache__v4;
    IData/*31:0*/ __Vdlyvlsb__l1d_cache__DOT__cache__v4;
    IData/*20:0*/ __Vdlyvval__l1d_cache__DOT__cache__v4;
    CData/*6:0*/ __Vdlyvdim0__l1d_cache__DOT__cache__v5;
    IData/*31:0*/ __Vdlyvlsb__l1d_cache__DOT__cache__v5;
    CData/*6:0*/ __Vdlyvdim0__l1d_cache__DOT__cache__v6;
    IData/*31:0*/ __Vdlyvlsb__l1d_cache__DOT__cache__v6;
    CData/*0:0*/ __Vdlyvval__l1d_cache__DOT__cache__v6;
    CData/*0:0*/ __Vdlyvset__l1d_cache__DOT__cache__v6;
    CData/*6:0*/ __Vdlyvdim0__l1d_cache__DOT__cache__v7;
    IData/*31:0*/ __Vdlyvlsb__l1d_cache__DOT__cache__v7;
    VlWide<4>/*127:0*/ __Vdlyvval__l1d_cache__DOT__cache__v7;
    CData/*6:0*/ __Vdlyvdim0__l1d_cache__DOT__cache__v8;
    IData/*31:0*/ __Vdlyvlsb__l1d_cache__DOT__cache__v8;
    IData/*20:0*/ __Vdlyvval__l1d_cache__DOT__cache__v8;
    CData/*6:0*/ __Vdlyvdim0__l1d_cache__DOT__cache__v9;
    IData/*31:0*/ __Vdlyvlsb__l1d_cache__DOT__cache__v9;
    // Body
    __Vdlyvset__l1d_cache__DOT__cache__v1 = 0U;
    __Vdlyvset__l1d_cache__DOT__cache__v2 = 0U;
    __Vdlyvset__l1d_cache__DOT__cache__v6 = 0U;
    vlSelf->write_back_en = 0U;
    __Vdlyvval__l1d_cache__DOT__cache__v0 = vlSelf->l1d_cache__DOT__way;
    __Vdlyvlsb__l1d_cache__DOT__cache__v0 = 0x12eU;
    __Vdlyvdim0__l1d_cache__DOT__cache__v0 = (0x7fU 
                                              & (vlSelf->addr 
                                                 >> 4U));
    if (vlSelf->l1d_cache__DOT__wr_en) {
        __Vdlyvval__l1d_cache__DOT__cache__v1 = vlSelf->l1d_cache__DOT__way;
        __Vdlyvset__l1d_cache__DOT__cache__v1 = 1U;
        __Vdlyvlsb__l1d_cache__DOT__cache__v1 = 0x12eU;
        __Vdlyvdim0__l1d_cache__DOT__cache__v1 = (0x7fU 
                                                  & (vlSelf->addr 
                                                     >> 4U));
        if (vlSelf->l1d_cache__DOT__way) {
            if (((vlSelf->l1d_cache__DOT__cache[(0x7fU 
                                                 & (vlSelf->addr 
                                                    >> 4U))][9U] 
                  >> 0xcU) & (IData)(vlSelf->l1d_cache__DOT__miss))) {
                vlSelf->write_back[0U] = ((vlSelf->l1d_cache__DOT__cache
                                           [(0x7fU 
                                             & (vlSelf->addr 
                                                >> 4U))][5U] 
                                           << 9U) | 
                                          (vlSelf->l1d_cache__DOT__cache
                                           [(0x7fU 
                                             & (vlSelf->addr 
                                                >> 4U))][4U] 
                                           >> 0x17U));
                vlSelf->write_back[1U] = ((vlSelf->l1d_cache__DOT__cache
                                           [(0x7fU 
                                             & (vlSelf->addr 
                                                >> 4U))][6U] 
                                           << 9U) | 
                                          (vlSelf->l1d_cache__DOT__cache
                                           [(0x7fU 
                                             & (vlSelf->addr 
                                                >> 4U))][5U] 
                                           >> 0x17U));
                vlSelf->write_back[2U] = ((vlSelf->l1d_cache__DOT__cache
                                           [(0x7fU 
                                             & (vlSelf->addr 
                                                >> 4U))][7U] 
                                           << 9U) | 
                                          (vlSelf->l1d_cache__DOT__cache
                                           [(0x7fU 
                                             & (vlSelf->addr 
                                                >> 4U))][6U] 
                                           >> 0x17U));
                vlSelf->write_back[3U] = ((vlSelf->l1d_cache__DOT__cache
                                           [(0x7fU 
                                             & (vlSelf->addr 
                                                >> 4U))][8U] 
                                           << 9U) | 
                                          (vlSelf->l1d_cache__DOT__cache
                                           [(0x7fU 
                                             & (vlSelf->addr 
                                                >> 4U))][7U] 
                                           >> 0x17U));
                vlSelf->write_back_en = 1U;
            }
            __Vdlyvval__l1d_cache__DOT__cache__v2 = vlSelf->MemWrite_m;
            __Vdlyvset__l1d_cache__DOT__cache__v2 = 1U;
            __Vdlyvlsb__l1d_cache__DOT__cache__v2 = 0x12cU;
            __Vdlyvdim0__l1d_cache__DOT__cache__v2 
                = (0x7fU & (vlSelf->addr >> 4U));
            __Vdlyvval__l1d_cache__DOT__cache__v3[0U] 
                = ((((vlSelf->l1d_cache__DOT__cache
                      [(0x7fU & (vlSelf->addr >> 4U))][5U] 
                      << 9U) | (vlSelf->l1d_cache__DOT__cache
                                [(0x7fU & (vlSelf->addr 
                                           >> 4U))][4U] 
                                >> 0x17U)) & (~ vlSelf->l1d_cache__DOT__wmask[0U])) 
                   | (vlSelf->l1d_cache__DOT__write_data[0U] 
                      & vlSelf->l1d_cache__DOT__wmask[0U]));
            __Vdlyvval__l1d_cache__DOT__cache__v3[1U] 
                = ((((vlSelf->l1d_cache__DOT__cache
                      [(0x7fU & (vlSelf->addr >> 4U))][6U] 
                      << 9U) | (vlSelf->l1d_cache__DOT__cache
                                [(0x7fU & (vlSelf->addr 
                                           >> 4U))][5U] 
                                >> 0x17U)) & (~ vlSelf->l1d_cache__DOT__wmask[1U])) 
                   | (vlSelf->l1d_cache__DOT__write_data[1U] 
                      & vlSelf->l1d_cache__DOT__wmask[1U]));
            __Vdlyvval__l1d_cache__DOT__cache__v3[2U] 
                = ((((vlSelf->l1d_cache__DOT__cache
                      [(0x7fU & (vlSelf->addr >> 4U))][7U] 
                      << 9U) | (vlSelf->l1d_cache__DOT__cache
                                [(0x7fU & (vlSelf->addr 
                                           >> 4U))][6U] 
                                >> 0x17U)) & (~ vlSelf->l1d_cache__DOT__wmask[2U])) 
                   | (vlSelf->l1d_cache__DOT__write_data[2U] 
                      & vlSelf->l1d_cache__DOT__wmask[2U]));
            __Vdlyvval__l1d_cache__DOT__cache__v3[3U] 
                = ((((vlSelf->l1d_cache__DOT__cache
                      [(0x7fU & (vlSelf->addr >> 4U))][8U] 
                      << 9U) | (vlSelf->l1d_cache__DOT__cache
                                [(0x7fU & (vlSelf->addr 
                                           >> 4U))][7U] 
                                >> 0x17U)) & (~ vlSelf->l1d_cache__DOT__wmask[3U])) 
                   | (vlSelf->l1d_cache__DOT__write_data[3U] 
                      & vlSelf->l1d_cache__DOT__wmask[3U]));
            __Vdlyvlsb__l1d_cache__DOT__cache__v3 = 0x97U;
            __Vdlyvdim0__l1d_cache__DOT__cache__v3 
                = (0x7fU & (vlSelf->addr >> 4U));
            __Vdlyvval__l1d_cache__DOT__cache__v4 = 
                (vlSelf->addr >> 0xbU);
            __Vdlyvlsb__l1d_cache__DOT__cache__v4 = 0x117U;
            __Vdlyvdim0__l1d_cache__DOT__cache__v4 
                = (0x7fU & (vlSelf->addr >> 4U));
            __Vdlyvlsb__l1d_cache__DOT__cache__v5 = 0x12dU;
            __Vdlyvdim0__l1d_cache__DOT__cache__v5 
                = (0x7fU & (vlSelf->addr >> 4U));
        } else {
            if (((vlSelf->l1d_cache__DOT__cache[(0x7fU 
                                                 & (vlSelf->addr 
                                                    >> 4U))][4U] 
                  >> 0x15U) & (IData)(vlSelf->l1d_cache__DOT__miss))) {
                vlSelf->write_back[0U] = vlSelf->l1d_cache__DOT__cache
                    [(0x7fU & (vlSelf->addr >> 4U))][0U];
                vlSelf->write_back[1U] = vlSelf->l1d_cache__DOT__cache
                    [(0x7fU & (vlSelf->addr >> 4U))][1U];
                vlSelf->write_back[2U] = vlSelf->l1d_cache__DOT__cache
                    [(0x7fU & (vlSelf->addr >> 4U))][2U];
                vlSelf->write_back[3U] = vlSelf->l1d_cache__DOT__cache
                    [(0x7fU & (vlSelf->addr >> 4U))][3U];
                vlSelf->write_back_en = 1U;
            }
            __Vdlyvval__l1d_cache__DOT__cache__v6 = vlSelf->MemWrite_m;
            __Vdlyvset__l1d_cache__DOT__cache__v6 = 1U;
            __Vdlyvlsb__l1d_cache__DOT__cache__v6 = 0x95U;
            __Vdlyvdim0__l1d_cache__DOT__cache__v6 
                = (0x7fU & (vlSelf->addr >> 4U));
            __Vdlyvval__l1d_cache__DOT__cache__v7[0U] 
                = ((vlSelf->l1d_cache__DOT__cache[(0x7fU 
                                                   & (vlSelf->addr 
                                                      >> 4U))][0U] 
                    & (~ vlSelf->l1d_cache__DOT__wmask[0U])) 
                   | (vlSelf->l1d_cache__DOT__write_data[0U] 
                      & vlSelf->l1d_cache__DOT__wmask[0U]));
            __Vdlyvval__l1d_cache__DOT__cache__v7[1U] 
                = ((vlSelf->l1d_cache__DOT__cache[(0x7fU 
                                                   & (vlSelf->addr 
                                                      >> 4U))][1U] 
                    & (~ vlSelf->l1d_cache__DOT__wmask[1U])) 
                   | (vlSelf->l1d_cache__DOT__write_data[1U] 
                      & vlSelf->l1d_cache__DOT__wmask[1U]));
            __Vdlyvval__l1d_cache__DOT__cache__v7[2U] 
                = ((vlSelf->l1d_cache__DOT__cache[(0x7fU 
                                                   & (vlSelf->addr 
                                                      >> 4U))][2U] 
                    & (~ vlSelf->l1d_cache__DOT__wmask[2U])) 
                   | (vlSelf->l1d_cache__DOT__write_data[2U] 
                      & vlSelf->l1d_cache__DOT__wmask[2U]));
            __Vdlyvval__l1d_cache__DOT__cache__v7[3U] 
                = ((vlSelf->l1d_cache__DOT__cache[(0x7fU 
                                                   & (vlSelf->addr 
                                                      >> 4U))][3U] 
                    & (~ vlSelf->l1d_cache__DOT__wmask[3U])) 
                   | (vlSelf->l1d_cache__DOT__write_data[3U] 
                      & vlSelf->l1d_cache__DOT__wmask[3U]));
            __Vdlyvlsb__l1d_cache__DOT__cache__v7 = 0U;
            __Vdlyvdim0__l1d_cache__DOT__cache__v7 
                = (0x7fU & (vlSelf->addr >> 4U));
            __Vdlyvval__l1d_cache__DOT__cache__v8 = 
                (vlSelf->addr >> 0xbU);
            __Vdlyvlsb__l1d_cache__DOT__cache__v8 = 0x80U;
            __Vdlyvdim0__l1d_cache__DOT__cache__v8 
                = (0x7fU & (vlSelf->addr >> 4U));
            __Vdlyvlsb__l1d_cache__DOT__cache__v9 = 0x96U;
            __Vdlyvdim0__l1d_cache__DOT__cache__v9 
                = (0x7fU & (vlSelf->addr >> 4U));
        }
    }
    vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v0][(__Vdlyvlsb__l1d_cache__DOT__cache__v0 
                                                                           >> 5U)] 
        = (((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l1d_cache__DOT__cache__v0))) 
            & vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v0][
            (__Vdlyvlsb__l1d_cache__DOT__cache__v0 
             >> 5U)]) | ((IData)(__Vdlyvval__l1d_cache__DOT__cache__v0) 
                         << (0x1fU & __Vdlyvlsb__l1d_cache__DOT__cache__v0)));
    if (__Vdlyvset__l1d_cache__DOT__cache__v1) {
        vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v1][(__Vdlyvlsb__l1d_cache__DOT__cache__v1 
                                                                               >> 5U)] 
            = (((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l1d_cache__DOT__cache__v1))) 
                & vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v1][
                (__Vdlyvlsb__l1d_cache__DOT__cache__v1 
                 >> 5U)]) | ((IData)(__Vdlyvval__l1d_cache__DOT__cache__v1) 
                             << (0x1fU & __Vdlyvlsb__l1d_cache__DOT__cache__v1)));
    }
    if (__Vdlyvset__l1d_cache__DOT__cache__v2) {
        vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v2][(__Vdlyvlsb__l1d_cache__DOT__cache__v2 
                                                                               >> 5U)] 
            = (((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l1d_cache__DOT__cache__v2))) 
                & vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v2][
                (__Vdlyvlsb__l1d_cache__DOT__cache__v2 
                 >> 5U)]) | ((IData)(__Vdlyvval__l1d_cache__DOT__cache__v2) 
                             << (0x1fU & __Vdlyvlsb__l1d_cache__DOT__cache__v2)));
        VL_ASSIGNSEL_WW(303,128,__Vdlyvlsb__l1d_cache__DOT__cache__v3, 
                        vlSelf->l1d_cache__DOT__cache
                        [__Vdlyvdim0__l1d_cache__DOT__cache__v3], __Vdlyvval__l1d_cache__DOT__cache__v3);
        VL_ASSIGNSEL_WI(303,21,__Vdlyvlsb__l1d_cache__DOT__cache__v4, 
                        vlSelf->l1d_cache__DOT__cache
                        [__Vdlyvdim0__l1d_cache__DOT__cache__v4], __Vdlyvval__l1d_cache__DOT__cache__v4);
        vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v5][(__Vdlyvlsb__l1d_cache__DOT__cache__v5 
                                                                               >> 5U)] 
            = (vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v5][
               (__Vdlyvlsb__l1d_cache__DOT__cache__v5 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l1d_cache__DOT__cache__v5)));
    }
    if (__Vdlyvset__l1d_cache__DOT__cache__v6) {
        vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v6][(__Vdlyvlsb__l1d_cache__DOT__cache__v6 
                                                                               >> 5U)] 
            = (((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l1d_cache__DOT__cache__v6))) 
                & vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v6][
                (__Vdlyvlsb__l1d_cache__DOT__cache__v6 
                 >> 5U)]) | ((IData)(__Vdlyvval__l1d_cache__DOT__cache__v6) 
                             << (0x1fU & __Vdlyvlsb__l1d_cache__DOT__cache__v6)));
        VL_ASSIGNSEL_WW(303,128,__Vdlyvlsb__l1d_cache__DOT__cache__v7, 
                        vlSelf->l1d_cache__DOT__cache
                        [__Vdlyvdim0__l1d_cache__DOT__cache__v7], __Vdlyvval__l1d_cache__DOT__cache__v7);
        VL_ASSIGNSEL_WI(303,21,__Vdlyvlsb__l1d_cache__DOT__cache__v8, 
                        vlSelf->l1d_cache__DOT__cache
                        [__Vdlyvdim0__l1d_cache__DOT__cache__v8], __Vdlyvval__l1d_cache__DOT__cache__v8);
        vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v9][(__Vdlyvlsb__l1d_cache__DOT__cache__v9 
                                                                               >> 5U)] 
            = (vlSelf->l1d_cache__DOT__cache[__Vdlyvdim0__l1d_cache__DOT__cache__v9][
               (__Vdlyvlsb__l1d_cache__DOT__cache__v9 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l1d_cache__DOT__cache__v9)));
    }
}

VL_INLINE_OPT void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_hef34a150__0;
    // Body
    vlSelf->l1d_cache__DOT__hit0 = ((((0x1fffffU & 
                                       vlSelf->l1d_cache__DOT__cache
                                       [(0x7fU & (vlSelf->addr 
                                                  >> 4U))][4U]) 
                                      == (vlSelf->addr 
                                          >> 0xbU)) 
                                     & (vlSelf->l1d_cache__DOT__cache
                                        [(0x7fU & (vlSelf->addr 
                                                   >> 4U))][4U] 
                                        >> 0x16U)) 
                                    & (IData)(vlSelf->fetch));
    vlSelf->l1d_cache__DOT__hit1 = ((((0x1fffffU & 
                                       ((vlSelf->l1d_cache__DOT__cache
                                         [(0x7fU & 
                                           (vlSelf->addr 
                                            >> 4U))][9U] 
                                         << 9U) | (
                                                   vlSelf->l1d_cache__DOT__cache
                                                   [
                                                   (0x7fU 
                                                    & (vlSelf->addr 
                                                       >> 4U))][8U] 
                                                   >> 0x17U))) 
                                      == (vlSelf->addr 
                                          >> 0xbU)) 
                                     & (vlSelf->l1d_cache__DOT__cache
                                        [(0x7fU & (vlSelf->addr 
                                                   >> 4U))][9U] 
                                        >> 0xdU)) & (IData)(vlSelf->fetch));
    vlSelf->l1d_cache__DOT__miss = ((~ ((IData)(vlSelf->l1d_cache__DOT__hit0) 
                                        | (IData)(vlSelf->l1d_cache__DOT__hit1))) 
                                    & (IData)(vlSelf->fetch));
    vlSelf->l1d_cache__DOT__valid0 = (1U & (vlSelf->l1d_cache__DOT__cache
                                            [(0x7fU 
                                              & (vlSelf->addr 
                                                 >> 4U))][4U] 
                                            >> 0x16U));
    vlSelf->l1d_cache__DOT__valid1 = (1U & (vlSelf->l1d_cache__DOT__cache
                                            [(0x7fU 
                                              & (vlSelf->addr 
                                                 >> 4U))][9U] 
                                            >> 0xdU));
    vlSelf->l1d_cache__DOT__wmask[0U] = 0U;
    vlSelf->l1d_cache__DOT__wmask[1U] = 0U;
    vlSelf->l1d_cache__DOT__wmask[2U] = 0U;
    vlSelf->l1d_cache__DOT__wmask[3U] = 0U;
    vlSelf->stall = 0U;
    vlSelf->l1d_cache__DOT__wr_en = 0U;
    vlSelf->l1d_cache__DOT__rd_en = 0U;
    vlSelf->l1d_cache__DOT__write_data[0U] = 0U;
    vlSelf->l1d_cache__DOT__write_data[1U] = 0U;
    vlSelf->l1d_cache__DOT__write_data[2U] = 0U;
    vlSelf->l1d_cache__DOT__write_data[3U] = 0U;
    vlSelf->data_out = 0U;
    if (vlSelf->l1d_cache__DOT__miss) {
        vlSelf->stall = 1U;
        vlSelf->l1d_cache__DOT__wmask[0U] = 0xffffffffU;
        vlSelf->l1d_cache__DOT__wmask[1U] = 0xffffffffU;
        vlSelf->l1d_cache__DOT__wmask[2U] = 0xffffffffU;
        vlSelf->l1d_cache__DOT__wmask[3U] = 0xffffffffU;
        vlSelf->l1d_cache__DOT__way = ((~ ((~ (IData)(vlSelf->l1d_cache__DOT__valid0)) 
                                           & (~ (IData)(vlSelf->l1d_cache__DOT__valid1)))) 
                                       & ((IData)(vlSelf->l1d_cache__DOT__valid0) 
                                          & ((~ (IData)(vlSelf->l1d_cache__DOT__valid1)) 
                                             | (~ (
                                                   vlSelf->l1d_cache__DOT__cache
                                                   [
                                                   (0x7fU 
                                                    & (vlSelf->addr 
                                                       >> 4U))][9U] 
                                                   >> 0xeU)))));
    } else {
        vlSelf->l1d_cache__DOT__way = vlSelf->l1d_cache__DOT__hit1;
        if (((IData)(vlSelf->MemWrite_m) & (IData)(vlSelf->fetch))) {
            vlSelf->l1d_cache__DOT__wr_en = 1U;
            vlSelf->l1d_cache__DOT__wmask[0U] = 0xffffffffU;
            vlSelf->l1d_cache__DOT__wmask[1U] = 0xffffffffU;
            vlSelf->l1d_cache__DOT__wmask[2U] = 0xffffffffU;
            vlSelf->l1d_cache__DOT__wmask[3U] = 0xffffffffU;
            if ((0U == (IData)(vlSelf->SizeWrite_m))) {
                vlSelf->l1d_cache__DOT__bottom_bit 
                    = (0x7fU & ((0x60U & (vlSelf->addr 
                                          << 3U)) + 
                                (0x18U & (vlSelf->addr 
                                          << 3U))));
                VL_ASSIGNSEL_WI(128,8,(IData)(vlSelf->l1d_cache__DOT__bottom_bit), vlSelf->l1d_cache__DOT__wmask, 0U);
            } else if ((1U == (IData)(vlSelf->SizeWrite_m))) {
                vlSelf->l1d_cache__DOT__bottom_bit 
                    = (0x7fU & ((0x60U & (vlSelf->addr 
                                          << 3U)) + 
                                (0x18U & (vlSelf->addr 
                                          << 3U))));
                VL_ASSIGNSEL_WI(128,16,(IData)(vlSelf->l1d_cache__DOT__bottom_bit), vlSelf->l1d_cache__DOT__wmask, 0U);
            } else if ((2U == (IData)(vlSelf->SizeWrite_m))) {
                vlSelf->l1d_cache__DOT__bottom_bit 
                    = (0x60U & (vlSelf->addr << 3U));
                VL_ASSIGNSEL_WI(128,32,(IData)(vlSelf->l1d_cache__DOT__bottom_bit), vlSelf->l1d_cache__DOT__wmask, 0U);
            }
            __Vtemp_hef34a150__0[1U] = (~ vlSelf->l1d_cache__DOT__wmask[1U]);
            __Vtemp_hef34a150__0[2U] = (~ vlSelf->l1d_cache__DOT__wmask[2U]);
            __Vtemp_hef34a150__0[3U] = (~ vlSelf->l1d_cache__DOT__wmask[3U]);
            vlSelf->l1d_cache__DOT__wmask[0U] = (~ 
                                                 vlSelf->l1d_cache__DOT__wmask[0U]);
            vlSelf->l1d_cache__DOT__wmask[1U] = __Vtemp_hef34a150__0[1U];
            vlSelf->l1d_cache__DOT__wmask[2U] = __Vtemp_hef34a150__0[2U];
            vlSelf->l1d_cache__DOT__wmask[3U] = __Vtemp_hef34a150__0[3U];
        }
    }
    if (vlSelf->fetch) {
        if (vlSelf->l1d_cache__DOT__miss) {
            vlSelf->l1d_cache__DOT__rd_en = 0U;
            vlSelf->l1d_cache__DOT__wr_en = 1U;
            vlSelf->l1d_cache__DOT__write_data[0U] 
                = vlSelf->line_from_mem[0U];
            vlSelf->l1d_cache__DOT__write_data[1U] 
                = vlSelf->line_from_mem[1U];
            vlSelf->l1d_cache__DOT__write_data[2U] 
                = vlSelf->line_from_mem[2U];
            vlSelf->l1d_cache__DOT__write_data[3U] 
                = vlSelf->line_from_mem[3U];
        } else {
            vlSelf->l1d_cache__DOT__rd_en = 1U;
            if (vlSelf->MemWrite_m) {
                vlSelf->l1d_cache__DOT__wr_en = 1U;
                vlSelf->l1d_cache__DOT__write_data[0U] 
                    = vlSelf->wd;
                vlSelf->l1d_cache__DOT__write_data[1U] 
                    = vlSelf->wd;
                vlSelf->l1d_cache__DOT__write_data[2U] 
                    = vlSelf->wd;
                vlSelf->l1d_cache__DOT__write_data[3U] 
                    = vlSelf->wd;
            }
        }
    }
    if (vlSelf->l1d_cache__DOT__rd_en) {
        if (vlSelf->l1d_cache__DOT__way) {
            if (vlSelf->l1d_cache__DOT__way) {
                vlSelf->data_out = ((8U & vlSelf->addr)
                                     ? ((4U & vlSelf->addr)
                                         ? ((vlSelf->l1d_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelf->addr 
                                                  >> 4U))][8U] 
                                             << 9U) 
                                            | (vlSelf->l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelf->addr 
                                                    >> 4U))][7U] 
                                               >> 0x17U))
                                         : ((vlSelf->l1d_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelf->addr 
                                                  >> 4U))][7U] 
                                             << 9U) 
                                            | (vlSelf->l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelf->addr 
                                                    >> 4U))][6U] 
                                               >> 0x17U)))
                                     : ((4U & vlSelf->addr)
                                         ? ((vlSelf->l1d_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelf->addr 
                                                  >> 4U))][6U] 
                                             << 9U) 
                                            | (vlSelf->l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelf->addr 
                                                    >> 4U))][5U] 
                                               >> 0x17U))
                                         : ((vlSelf->l1d_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelf->addr 
                                                  >> 4U))][5U] 
                                             << 9U) 
                                            | (vlSelf->l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelf->addr 
                                                    >> 4U))][4U] 
                                               >> 0x17U))));
            }
        } else {
            vlSelf->data_out = ((8U & vlSelf->addr)
                                 ? ((4U & vlSelf->addr)
                                     ? vlSelf->l1d_cache__DOT__cache
                                    [(0x7fU & (vlSelf->addr 
                                               >> 4U))][3U]
                                     : vlSelf->l1d_cache__DOT__cache
                                    [(0x7fU & (vlSelf->addr 
                                               >> 4U))][2U])
                                 : ((4U & vlSelf->addr)
                                     ? vlSelf->l1d_cache__DOT__cache
                                    [(0x7fU & (vlSelf->addr 
                                               >> 4U))][1U]
                                     : vlSelf->l1d_cache__DOT__cache
                                    [(0x7fU & (vlSelf->addr 
                                               >> 4U))][0U]));
        }
        if ((0U == (IData)(vlSelf->LoadSize))) {
            vlSelf->l1d_cache__DOT__bottom_bit = (0x18U 
                                                  & (vlSelf->addr 
                                                     << 3U));
            vlSelf->data_out = ((IData)(vlSelf->LoadUnsigned)
                                 ? (0xffU & (vlSelf->data_out 
                                             >> (0x1fU 
                                                 & (IData)(vlSelf->l1d_cache__DOT__bottom_bit))))
                                 : (((- (IData)((1U 
                                                 & (vlSelf->data_out 
                                                    >> 
                                                    (0x1fU 
                                                     & ((IData)(7U) 
                                                        + (IData)(vlSelf->l1d_cache__DOT__bottom_bit))))))) 
                                     << 8U) | (0xffU 
                                               & (vlSelf->data_out 
                                                  >> 
                                                  (0x1fU 
                                                   & (IData)(vlSelf->l1d_cache__DOT__bottom_bit))))));
        } else if ((1U == (IData)(vlSelf->LoadSize))) {
            vlSelf->l1d_cache__DOT__bottom_bit = (0x30U 
                                                  & (vlSelf->addr 
                                                     << 4U));
            vlSelf->data_out = ((IData)(vlSelf->LoadUnsigned)
                                 ? (0xffffU & (vlSelf->data_out 
                                               >> (0x1fU 
                                                   & (IData)(vlSelf->l1d_cache__DOT__bottom_bit))))
                                 : (((- (IData)((1U 
                                                 & (vlSelf->data_out 
                                                    >> 
                                                    (0x1fU 
                                                     & ((IData)(0xfU) 
                                                        + (IData)(vlSelf->l1d_cache__DOT__bottom_bit))))))) 
                                     << 0x10U) | (0xffffU 
                                                  & (vlSelf->data_out 
                                                     >> 
                                                     (0x1fU 
                                                      & (IData)(vlSelf->l1d_cache__DOT__bottom_bit))))));
        }
    }
}

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vdut___024root___sequent__TOP__0(vlSelf);
    }
    Vdut___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->fetch & 0xfeU))) {
        Verilated::overWidthError("fetch");}
    if (VL_UNLIKELY((vlSelf->SizeWrite_m & 0xfcU))) {
        Verilated::overWidthError("SizeWrite_m");}
    if (VL_UNLIKELY((vlSelf->MemWrite_m & 0xfeU))) {
        Verilated::overWidthError("MemWrite_m");}
    if (VL_UNLIKELY((vlSelf->LoadSize & 0xfcU))) {
        Verilated::overWidthError("LoadSize");}
    if (VL_UNLIKELY((vlSelf->LoadUnsigned & 0xfeU))) {
        Verilated::overWidthError("LoadUnsigned");}
}
#endif  // VL_DEBUG
