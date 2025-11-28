// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

void Vdut___024root___ico_sequent__TOP__0(Vdut___024root* vlSelf);

void Vdut___024root___eval_ico(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_ico\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vdut___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vdut___024root___ico_sequent__TOP__0(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ico_sequent__TOP__0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    vlSelfRef.l1d_cache__DOT____VdfgExtracted_h18ae9b83__0 
        = (0x7fU & (VL_SHIFTL_III(7,7,32, (3U & (vlSelfRef.addr 
                                                 >> 2U)), 5U) 
                    + VL_SHIFTL_III(7,7,32, (3U & vlSelfRef.addr), 3U)));
    vlSelfRef.l1d_cache__DOT__hit0 = ((((0x1fffffU 
                                         & vlSelfRef.l1d_cache__DOT__cache
                                         [(0x7fU & 
                                           (vlSelfRef.addr 
                                            >> 4U))][4U]) 
                                        == (vlSelfRef.addr 
                                            >> 0xbU)) 
                                       & (vlSelfRef.l1d_cache__DOT__cache
                                          [(0x7fU & 
                                            (vlSelfRef.addr 
                                             >> 4U))][4U] 
                                          >> 0x16U)) 
                                      & (IData)(vlSelfRef.fetch));
    vlSelfRef.l1d_cache__DOT__hit1 = ((((0x1fffffU 
                                         & ((vlSelfRef.l1d_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelfRef.addr 
                                                  >> 4U))][9U] 
                                             << 9U) 
                                            | (vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][8U] 
                                               >> 0x17U))) 
                                        == (vlSelfRef.addr 
                                            >> 0xbU)) 
                                       & (vlSelfRef.l1d_cache__DOT__cache
                                          [(0x7fU & 
                                            (vlSelfRef.addr 
                                             >> 4U))][9U] 
                                          >> 0xdU)) 
                                      & (IData)(vlSelfRef.fetch));
    vlSelfRef.l1d_cache__DOT__miss = ((~ ((IData)(vlSelfRef.l1d_cache__DOT__hit0) 
                                          | (IData)(vlSelfRef.l1d_cache__DOT__hit1))) 
                                      & (IData)(vlSelfRef.fetch));
    vlSelfRef.l1d_cache__DOT__valid0 = (1U & (vlSelfRef.l1d_cache__DOT__cache
                                              [(0x7fU 
                                                & (vlSelfRef.addr 
                                                   >> 4U))][4U] 
                                              >> 0x16U));
    vlSelfRef.l1d_cache__DOT__valid1 = (1U & (vlSelfRef.l1d_cache__DOT__cache
                                              [(0x7fU 
                                                & (vlSelfRef.addr 
                                                   >> 4U))][9U] 
                                              >> 0xdU));
    vlSelfRef.l1d_cache__DOT__wmask[0U] = 0U;
    vlSelfRef.l1d_cache__DOT__wmask[1U] = 0U;
    vlSelfRef.l1d_cache__DOT__wmask[2U] = 0U;
    vlSelfRef.l1d_cache__DOT__wmask[3U] = 0U;
    vlSelfRef.stall = 0U;
    vlSelfRef.l1d_cache__DOT__wr_en = 0U;
    vlSelfRef.l1d_cache__DOT__rd_en = 0U;
    vlSelfRef.l1d_cache__DOT__write_data[0U] = 0U;
    vlSelfRef.l1d_cache__DOT__write_data[1U] = 0U;
    vlSelfRef.l1d_cache__DOT__write_data[2U] = 0U;
    vlSelfRef.l1d_cache__DOT__write_data[3U] = 0U;
    vlSelfRef.data_out = 0U;
    if (vlSelfRef.l1d_cache__DOT__miss) {
        vlSelfRef.stall = 1U;
        vlSelfRef.l1d_cache__DOT__wmask[0U] = 0xffffffffU;
        vlSelfRef.l1d_cache__DOT__wmask[1U] = 0xffffffffU;
        vlSelfRef.l1d_cache__DOT__wmask[2U] = 0xffffffffU;
        vlSelfRef.l1d_cache__DOT__wmask[3U] = 0xffffffffU;
        vlSelfRef.l1d_cache__DOT__way = ((~ ((~ (IData)(vlSelfRef.l1d_cache__DOT__valid0)) 
                                             & (~ (IData)(vlSelfRef.l1d_cache__DOT__valid1)))) 
                                         & ((IData)(vlSelfRef.l1d_cache__DOT__valid0) 
                                            & ((~ (IData)(vlSelfRef.l1d_cache__DOT__valid1)) 
                                               | (~ 
                                                  (vlSelfRef.l1d_cache__DOT__cache
                                                   [
                                                   (0x7fU 
                                                    & (vlSelfRef.addr 
                                                       >> 4U))][9U] 
                                                   >> 0xeU)))));
    } else {
        vlSelfRef.l1d_cache__DOT__way = vlSelfRef.l1d_cache__DOT__hit1;
        if (((IData)(vlSelfRef.MemWrite_m) & (IData)(vlSelfRef.fetch))) {
            vlSelfRef.l1d_cache__DOT__wr_en = 1U;
            vlSelfRef.l1d_cache__DOT__wmask[0U] = 0xffffffffU;
            vlSelfRef.l1d_cache__DOT__wmask[1U] = 0xffffffffU;
            vlSelfRef.l1d_cache__DOT__wmask[2U] = 0xffffffffU;
            vlSelfRef.l1d_cache__DOT__wmask[3U] = 0xffffffffU;
            if ((0U == (IData)(vlSelfRef.SizeWrite_m))) {
                vlSelfRef.l1d_cache__DOT__bottom_bit 
                    = vlSelfRef.l1d_cache__DOT____VdfgExtracted_h18ae9b83__0;
                VL_ASSIGNSEL_WI(128,8,(IData)(vlSelfRef.l1d_cache__DOT__bottom_bit), vlSelfRef.l1d_cache__DOT__wmask, 0U);
            } else if ((1U == (IData)(vlSelfRef.SizeWrite_m))) {
                vlSelfRef.l1d_cache__DOT__bottom_bit 
                    = vlSelfRef.l1d_cache__DOT____VdfgExtracted_h18ae9b83__0;
                VL_ASSIGNSEL_WI(128,16,(IData)(vlSelfRef.l1d_cache__DOT__bottom_bit), vlSelfRef.l1d_cache__DOT__wmask, 0U);
            } else if ((2U == (IData)(vlSelfRef.SizeWrite_m))) {
                vlSelfRef.l1d_cache__DOT__bottom_bit 
                    = (0x7fU & VL_SHIFTL_III(7,7,32, 
                                             (3U & 
                                              (vlSelfRef.addr 
                                               >> 2U)), 5U));
                VL_ASSIGNSEL_WI(128,32,(IData)(vlSelfRef.l1d_cache__DOT__bottom_bit), vlSelfRef.l1d_cache__DOT__wmask, 0U);
            }
            __Vtemp_1[1U] = (~ vlSelfRef.l1d_cache__DOT__wmask[1U]);
            __Vtemp_1[2U] = (~ vlSelfRef.l1d_cache__DOT__wmask[2U]);
            __Vtemp_1[3U] = (~ vlSelfRef.l1d_cache__DOT__wmask[3U]);
            vlSelfRef.l1d_cache__DOT__wmask[0U] = (~ 
                                                   vlSelfRef.l1d_cache__DOT__wmask[0U]);
            vlSelfRef.l1d_cache__DOT__wmask[1U] = __Vtemp_1[1U];
            vlSelfRef.l1d_cache__DOT__wmask[2U] = __Vtemp_1[2U];
            vlSelfRef.l1d_cache__DOT__wmask[3U] = __Vtemp_1[3U];
        }
    }
    if (vlSelfRef.fetch) {
        if (vlSelfRef.l1d_cache__DOT__miss) {
            vlSelfRef.l1d_cache__DOT__rd_en = 0U;
            vlSelfRef.l1d_cache__DOT__wr_en = 1U;
            vlSelfRef.l1d_cache__DOT__write_data[0U] 
                = vlSelfRef.line_from_mem[0U];
            vlSelfRef.l1d_cache__DOT__write_data[1U] 
                = vlSelfRef.line_from_mem[1U];
            vlSelfRef.l1d_cache__DOT__write_data[2U] 
                = vlSelfRef.line_from_mem[2U];
            vlSelfRef.l1d_cache__DOT__write_data[3U] 
                = vlSelfRef.line_from_mem[3U];
        } else {
            vlSelfRef.l1d_cache__DOT__rd_en = 1U;
            if (vlSelfRef.MemWrite_m) {
                vlSelfRef.l1d_cache__DOT__wr_en = 1U;
                vlSelfRef.l1d_cache__DOT__write_data[0U] 
                    = vlSelfRef.wd;
                vlSelfRef.l1d_cache__DOT__write_data[1U] 
                    = vlSelfRef.wd;
                vlSelfRef.l1d_cache__DOT__write_data[2U] 
                    = vlSelfRef.wd;
                vlSelfRef.l1d_cache__DOT__write_data[3U] 
                    = vlSelfRef.wd;
            }
        }
    }
    if (vlSelfRef.l1d_cache__DOT__rd_en) {
        if (vlSelfRef.l1d_cache__DOT__way) {
            if (vlSelfRef.l1d_cache__DOT__way) {
                vlSelfRef.data_out = ((8U & vlSelfRef.addr)
                                       ? ((4U & vlSelfRef.addr)
                                           ? ((vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][8U] 
                                               << 9U) 
                                              | (vlSelfRef.l1d_cache__DOT__cache
                                                 [(0x7fU 
                                                   & (vlSelfRef.addr 
                                                      >> 4U))][7U] 
                                                 >> 0x17U))
                                           : ((vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][7U] 
                                               << 9U) 
                                              | (vlSelfRef.l1d_cache__DOT__cache
                                                 [(0x7fU 
                                                   & (vlSelfRef.addr 
                                                      >> 4U))][6U] 
                                                 >> 0x17U)))
                                       : ((4U & vlSelfRef.addr)
                                           ? ((vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][6U] 
                                               << 9U) 
                                              | (vlSelfRef.l1d_cache__DOT__cache
                                                 [(0x7fU 
                                                   & (vlSelfRef.addr 
                                                      >> 4U))][5U] 
                                                 >> 0x17U))
                                           : ((vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][5U] 
                                               << 9U) 
                                              | (vlSelfRef.l1d_cache__DOT__cache
                                                 [(0x7fU 
                                                   & (vlSelfRef.addr 
                                                      >> 4U))][4U] 
                                                 >> 0x17U))));
            }
        } else {
            vlSelfRef.data_out = ((8U & vlSelfRef.addr)
                                   ? ((4U & vlSelfRef.addr)
                                       ? vlSelfRef.l1d_cache__DOT__cache
                                      [(0x7fU & (vlSelfRef.addr 
                                                 >> 4U))][3U]
                                       : vlSelfRef.l1d_cache__DOT__cache
                                      [(0x7fU & (vlSelfRef.addr 
                                                 >> 4U))][2U])
                                   : ((4U & vlSelfRef.addr)
                                       ? vlSelfRef.l1d_cache__DOT__cache
                                      [(0x7fU & (vlSelfRef.addr 
                                                 >> 4U))][1U]
                                       : vlSelfRef.l1d_cache__DOT__cache
                                      [(0x7fU & (vlSelfRef.addr 
                                                 >> 4U))][0U]));
        }
        if ((0U == (IData)(vlSelfRef.LoadSize))) {
            vlSelfRef.l1d_cache__DOT__bottom_bit = 
                (0x7fU & VL_SHIFTL_III(7,7,32, (3U 
                                                & vlSelfRef.addr), 3U));
            vlSelfRef.data_out = ((IData)(vlSelfRef.LoadUnsigned)
                                   ? (0xffU & (vlSelfRef.data_out 
                                               >> (0x1fU 
                                                   & (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))
                                   : (((- (IData)((1U 
                                                   & (vlSelfRef.data_out 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          + (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))))) 
                                       << 8U) | (0xffU 
                                                 & (vlSelfRef.data_out 
                                                    >> 
                                                    (0x1fU 
                                                     & (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))));
        } else if ((1U == (IData)(vlSelfRef.LoadSize))) {
            vlSelfRef.l1d_cache__DOT__bottom_bit = 
                (0x7fU & VL_SHIFTL_III(7,7,32, (3U 
                                                & vlSelfRef.addr), 4U));
            vlSelfRef.data_out = ((IData)(vlSelfRef.LoadUnsigned)
                                   ? (0xffffU & (vlSelfRef.data_out 
                                                 >> 
                                                 (0x1fU 
                                                  & (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))
                                   : (((- (IData)((1U 
                                                   & (vlSelfRef.data_out 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(0xfU) 
                                                          + (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))))) 
                                       << 0x10U) | 
                                      (0xffffU & (vlSelfRef.data_out 
                                                  >> 
                                                  (0x1fU 
                                                   & (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))));
        }
    }
}

void Vdut___024root___eval_triggers__ico(Vdut___024root* vlSelf);

bool Vdut___024root___eval_phase__ico(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__ico\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vdut___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vdut___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

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
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VdlyVal__l1d_cache__DOT__cache__v0;
    __VdlyVal__l1d_cache__DOT__cache__v0 = 0;
    CData/*6:0*/ __VdlyDim0__l1d_cache__DOT__cache__v0;
    __VdlyDim0__l1d_cache__DOT__cache__v0 = 0;
    CData/*0:0*/ __VdlyVal__l1d_cache__DOT__cache__v1;
    __VdlyVal__l1d_cache__DOT__cache__v1 = 0;
    CData/*6:0*/ __VdlyDim0__l1d_cache__DOT__cache__v1;
    __VdlyDim0__l1d_cache__DOT__cache__v1 = 0;
    CData/*0:0*/ __VdlySet__l1d_cache__DOT__cache__v1;
    __VdlySet__l1d_cache__DOT__cache__v1 = 0;
    CData/*0:0*/ __VdlyVal__l1d_cache__DOT__cache__v2;
    __VdlyVal__l1d_cache__DOT__cache__v2 = 0;
    CData/*6:0*/ __VdlyDim0__l1d_cache__DOT__cache__v2;
    __VdlyDim0__l1d_cache__DOT__cache__v2 = 0;
    CData/*0:0*/ __VdlySet__l1d_cache__DOT__cache__v2;
    __VdlySet__l1d_cache__DOT__cache__v2 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__l1d_cache__DOT__cache__v3;
    VL_ZERO_W(128, __VdlyVal__l1d_cache__DOT__cache__v3);
    CData/*6:0*/ __VdlyDim0__l1d_cache__DOT__cache__v3;
    __VdlyDim0__l1d_cache__DOT__cache__v3 = 0;
    IData/*20:0*/ __VdlyVal__l1d_cache__DOT__cache__v4;
    __VdlyVal__l1d_cache__DOT__cache__v4 = 0;
    CData/*6:0*/ __VdlyDim0__l1d_cache__DOT__cache__v4;
    __VdlyDim0__l1d_cache__DOT__cache__v4 = 0;
    CData/*6:0*/ __VdlyDim0__l1d_cache__DOT__cache__v5;
    __VdlyDim0__l1d_cache__DOT__cache__v5 = 0;
    CData/*0:0*/ __VdlyVal__l1d_cache__DOT__cache__v6;
    __VdlyVal__l1d_cache__DOT__cache__v6 = 0;
    CData/*6:0*/ __VdlyDim0__l1d_cache__DOT__cache__v6;
    __VdlyDim0__l1d_cache__DOT__cache__v6 = 0;
    CData/*0:0*/ __VdlySet__l1d_cache__DOT__cache__v6;
    __VdlySet__l1d_cache__DOT__cache__v6 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__l1d_cache__DOT__cache__v7;
    VL_ZERO_W(128, __VdlyVal__l1d_cache__DOT__cache__v7);
    CData/*6:0*/ __VdlyDim0__l1d_cache__DOT__cache__v7;
    __VdlyDim0__l1d_cache__DOT__cache__v7 = 0;
    IData/*20:0*/ __VdlyVal__l1d_cache__DOT__cache__v8;
    __VdlyVal__l1d_cache__DOT__cache__v8 = 0;
    CData/*6:0*/ __VdlyDim0__l1d_cache__DOT__cache__v8;
    __VdlyDim0__l1d_cache__DOT__cache__v8 = 0;
    CData/*6:0*/ __VdlyDim0__l1d_cache__DOT__cache__v9;
    __VdlyDim0__l1d_cache__DOT__cache__v9 = 0;
    VlWide<4>/*127:0*/ __Vtemp_9;
    // Body
    __VdlySet__l1d_cache__DOT__cache__v1 = 0U;
    __VdlySet__l1d_cache__DOT__cache__v2 = 0U;
    __VdlySet__l1d_cache__DOT__cache__v6 = 0U;
    vlSelfRef.write_back_en = 0U;
    __VdlyVal__l1d_cache__DOT__cache__v0 = vlSelfRef.l1d_cache__DOT__way;
    __VdlyDim0__l1d_cache__DOT__cache__v0 = (0x7fU 
                                             & (vlSelfRef.addr 
                                                >> 4U));
    if (vlSelfRef.l1d_cache__DOT__wr_en) {
        __VdlyVal__l1d_cache__DOT__cache__v1 = vlSelfRef.l1d_cache__DOT__way;
        __VdlyDim0__l1d_cache__DOT__cache__v1 = (0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U));
        __VdlySet__l1d_cache__DOT__cache__v1 = 1U;
        if (vlSelfRef.l1d_cache__DOT__way) {
            if (((vlSelfRef.l1d_cache__DOT__cache[(0x7fU 
                                                   & (vlSelfRef.addr 
                                                      >> 4U))][9U] 
                  >> 0xcU) & (IData)(vlSelfRef.l1d_cache__DOT__miss))) {
                vlSelfRef.write_back[0U] = ((vlSelfRef.l1d_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelfRef.addr 
                                                  >> 4U))][5U] 
                                             << 9U) 
                                            | (vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][4U] 
                                               >> 0x17U));
                vlSelfRef.write_back[1U] = ((vlSelfRef.l1d_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelfRef.addr 
                                                  >> 4U))][6U] 
                                             << 9U) 
                                            | (vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][5U] 
                                               >> 0x17U));
                vlSelfRef.write_back[2U] = ((vlSelfRef.l1d_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelfRef.addr 
                                                  >> 4U))][7U] 
                                             << 9U) 
                                            | (vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][6U] 
                                               >> 0x17U));
                vlSelfRef.write_back[3U] = ((vlSelfRef.l1d_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelfRef.addr 
                                                  >> 4U))][8U] 
                                             << 9U) 
                                            | (vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][7U] 
                                               >> 0x17U));
                vlSelfRef.write_back_en = 1U;
            }
            __VdlyVal__l1d_cache__DOT__cache__v2 = vlSelfRef.MemWrite_m;
            __VdlyDim0__l1d_cache__DOT__cache__v2 = 
                (0x7fU & (vlSelfRef.addr >> 4U));
            __VdlySet__l1d_cache__DOT__cache__v2 = 1U;
            __VdlyVal__l1d_cache__DOT__cache__v3[0U] 
                = ((((vlSelfRef.l1d_cache__DOT__cache
                      [(0x7fU & (vlSelfRef.addr >> 4U))][5U] 
                      << 9U) | (vlSelfRef.l1d_cache__DOT__cache
                                [(0x7fU & (vlSelfRef.addr 
                                           >> 4U))][4U] 
                                >> 0x17U)) & (~ vlSelfRef.l1d_cache__DOT__wmask[0U])) 
                   | (vlSelfRef.l1d_cache__DOT__write_data[0U] 
                      & vlSelfRef.l1d_cache__DOT__wmask[0U]));
            __VdlyVal__l1d_cache__DOT__cache__v3[1U] 
                = ((((vlSelfRef.l1d_cache__DOT__cache
                      [(0x7fU & (vlSelfRef.addr >> 4U))][6U] 
                      << 9U) | (vlSelfRef.l1d_cache__DOT__cache
                                [(0x7fU & (vlSelfRef.addr 
                                           >> 4U))][5U] 
                                >> 0x17U)) & (~ vlSelfRef.l1d_cache__DOT__wmask[1U])) 
                   | (vlSelfRef.l1d_cache__DOT__write_data[1U] 
                      & vlSelfRef.l1d_cache__DOT__wmask[1U]));
            __VdlyVal__l1d_cache__DOT__cache__v3[2U] 
                = ((((vlSelfRef.l1d_cache__DOT__cache
                      [(0x7fU & (vlSelfRef.addr >> 4U))][7U] 
                      << 9U) | (vlSelfRef.l1d_cache__DOT__cache
                                [(0x7fU & (vlSelfRef.addr 
                                           >> 4U))][6U] 
                                >> 0x17U)) & (~ vlSelfRef.l1d_cache__DOT__wmask[2U])) 
                   | (vlSelfRef.l1d_cache__DOT__write_data[2U] 
                      & vlSelfRef.l1d_cache__DOT__wmask[2U]));
            __VdlyVal__l1d_cache__DOT__cache__v3[3U] 
                = ((((vlSelfRef.l1d_cache__DOT__cache
                      [(0x7fU & (vlSelfRef.addr >> 4U))][8U] 
                      << 9U) | (vlSelfRef.l1d_cache__DOT__cache
                                [(0x7fU & (vlSelfRef.addr 
                                           >> 4U))][7U] 
                                >> 0x17U)) & (~ vlSelfRef.l1d_cache__DOT__wmask[3U])) 
                   | (vlSelfRef.l1d_cache__DOT__write_data[3U] 
                      & vlSelfRef.l1d_cache__DOT__wmask[3U]));
            __VdlyDim0__l1d_cache__DOT__cache__v3 = 
                (0x7fU & (vlSelfRef.addr >> 4U));
            __VdlyVal__l1d_cache__DOT__cache__v4 = 
                (vlSelfRef.addr >> 0xbU);
            __VdlyDim0__l1d_cache__DOT__cache__v4 = 
                (0x7fU & (vlSelfRef.addr >> 4U));
            __VdlyDim0__l1d_cache__DOT__cache__v5 = 
                (0x7fU & (vlSelfRef.addr >> 4U));
        } else {
            if (((vlSelfRef.l1d_cache__DOT__cache[(0x7fU 
                                                   & (vlSelfRef.addr 
                                                      >> 4U))][4U] 
                  >> 0x15U) & (IData)(vlSelfRef.l1d_cache__DOT__miss))) {
                vlSelfRef.write_back[0U] = vlSelfRef.l1d_cache__DOT__cache
                    [(0x7fU & (vlSelfRef.addr >> 4U))][0U];
                vlSelfRef.write_back[1U] = vlSelfRef.l1d_cache__DOT__cache
                    [(0x7fU & (vlSelfRef.addr >> 4U))][1U];
                vlSelfRef.write_back[2U] = vlSelfRef.l1d_cache__DOT__cache
                    [(0x7fU & (vlSelfRef.addr >> 4U))][2U];
                vlSelfRef.write_back[3U] = vlSelfRef.l1d_cache__DOT__cache
                    [(0x7fU & (vlSelfRef.addr >> 4U))][3U];
                vlSelfRef.write_back_en = 1U;
            }
            __VdlyVal__l1d_cache__DOT__cache__v6 = vlSelfRef.MemWrite_m;
            __VdlyDim0__l1d_cache__DOT__cache__v6 = 
                (0x7fU & (vlSelfRef.addr >> 4U));
            __VdlySet__l1d_cache__DOT__cache__v6 = 1U;
            __VdlyVal__l1d_cache__DOT__cache__v7[0U] 
                = ((vlSelfRef.l1d_cache__DOT__cache
                    [(0x7fU & (vlSelfRef.addr >> 4U))][0U] 
                    & (~ vlSelfRef.l1d_cache__DOT__wmask[0U])) 
                   | (vlSelfRef.l1d_cache__DOT__write_data[0U] 
                      & vlSelfRef.l1d_cache__DOT__wmask[0U]));
            __VdlyVal__l1d_cache__DOT__cache__v7[1U] 
                = ((vlSelfRef.l1d_cache__DOT__cache
                    [(0x7fU & (vlSelfRef.addr >> 4U))][1U] 
                    & (~ vlSelfRef.l1d_cache__DOT__wmask[1U])) 
                   | (vlSelfRef.l1d_cache__DOT__write_data[1U] 
                      & vlSelfRef.l1d_cache__DOT__wmask[1U]));
            __VdlyVal__l1d_cache__DOT__cache__v7[2U] 
                = ((vlSelfRef.l1d_cache__DOT__cache
                    [(0x7fU & (vlSelfRef.addr >> 4U))][2U] 
                    & (~ vlSelfRef.l1d_cache__DOT__wmask[2U])) 
                   | (vlSelfRef.l1d_cache__DOT__write_data[2U] 
                      & vlSelfRef.l1d_cache__DOT__wmask[2U]));
            __VdlyVal__l1d_cache__DOT__cache__v7[3U] 
                = ((vlSelfRef.l1d_cache__DOT__cache
                    [(0x7fU & (vlSelfRef.addr >> 4U))][3U] 
                    & (~ vlSelfRef.l1d_cache__DOT__wmask[3U])) 
                   | (vlSelfRef.l1d_cache__DOT__write_data[3U] 
                      & vlSelfRef.l1d_cache__DOT__wmask[3U]));
            __VdlyDim0__l1d_cache__DOT__cache__v7 = 
                (0x7fU & (vlSelfRef.addr >> 4U));
            __VdlyVal__l1d_cache__DOT__cache__v8 = 
                (vlSelfRef.addr >> 0xbU);
            __VdlyDim0__l1d_cache__DOT__cache__v8 = 
                (0x7fU & (vlSelfRef.addr >> 4U));
            __VdlyDim0__l1d_cache__DOT__cache__v9 = 
                (0x7fU & (vlSelfRef.addr >> 4U));
        }
    }
    vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v0][9U] 
        = ((0x3fffU & vlSelfRef.l1d_cache__DOT__cache
            [__VdlyDim0__l1d_cache__DOT__cache__v0][9U]) 
           | (0x7fffU & ((IData)(__VdlyVal__l1d_cache__DOT__cache__v0) 
                         << 0xeU)));
    if (__VdlySet__l1d_cache__DOT__cache__v1) {
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v1][9U] 
            = ((0x3fffU & vlSelfRef.l1d_cache__DOT__cache
                [__VdlyDim0__l1d_cache__DOT__cache__v1][9U]) 
               | (0x7fffU & ((IData)(__VdlyVal__l1d_cache__DOT__cache__v1) 
                             << 0xeU)));
    }
    if (__VdlySet__l1d_cache__DOT__cache__v2) {
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v2][9U] 
            = ((0x6fffU & vlSelfRef.l1d_cache__DOT__cache
                [__VdlyDim0__l1d_cache__DOT__cache__v2][9U]) 
               | (0x7fffU & ((IData)(__VdlyVal__l1d_cache__DOT__cache__v2) 
                             << 0xcU)));
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v3][4U] 
            = ((0x7fffffU & vlSelfRef.l1d_cache__DOT__cache
                [__VdlyDim0__l1d_cache__DOT__cache__v3][4U]) 
               | (__VdlyVal__l1d_cache__DOT__cache__v3[0U] 
                  << 0x17U));
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v3][5U] 
            = ((__VdlyVal__l1d_cache__DOT__cache__v3[0U] 
                >> 9U) | (__VdlyVal__l1d_cache__DOT__cache__v3[1U] 
                          << 0x17U));
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v3][6U] 
            = ((__VdlyVal__l1d_cache__DOT__cache__v3[1U] 
                >> 9U) | (__VdlyVal__l1d_cache__DOT__cache__v3[2U] 
                          << 0x17U));
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v3][7U] 
            = ((__VdlyVal__l1d_cache__DOT__cache__v3[2U] 
                >> 9U) | (__VdlyVal__l1d_cache__DOT__cache__v3[3U] 
                          << 0x17U));
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v3][8U] 
            = ((0xff800000U & vlSelfRef.l1d_cache__DOT__cache
                [__VdlyDim0__l1d_cache__DOT__cache__v3][8U]) 
               | (__VdlyVal__l1d_cache__DOT__cache__v3[3U] 
                  >> 9U));
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v4][8U] 
            = ((0x7fffffU & vlSelfRef.l1d_cache__DOT__cache
                [__VdlyDim0__l1d_cache__DOT__cache__v4][8U]) 
               | (__VdlyVal__l1d_cache__DOT__cache__v4 
                  << 0x17U));
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v4][9U] 
            = ((0x7000U & vlSelfRef.l1d_cache__DOT__cache
                [__VdlyDim0__l1d_cache__DOT__cache__v4][9U]) 
               | (0x7fffU & (__VdlyVal__l1d_cache__DOT__cache__v4 
                             >> 9U)));
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v5][9U] 
            = (0x2000U | vlSelfRef.l1d_cache__DOT__cache
               [__VdlyDim0__l1d_cache__DOT__cache__v5][9U]);
    }
    if (__VdlySet__l1d_cache__DOT__cache__v6) {
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v6][4U] 
            = ((0xffdfffffU & vlSelfRef.l1d_cache__DOT__cache
                [__VdlyDim0__l1d_cache__DOT__cache__v6][4U]) 
               | ((IData)(__VdlyVal__l1d_cache__DOT__cache__v6) 
                  << 0x15U));
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v7][0U] 
            = __VdlyVal__l1d_cache__DOT__cache__v7[0U];
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v7][1U] 
            = __VdlyVal__l1d_cache__DOT__cache__v7[1U];
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v7][2U] 
            = __VdlyVal__l1d_cache__DOT__cache__v7[2U];
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v7][3U] 
            = __VdlyVal__l1d_cache__DOT__cache__v7[3U];
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v8][4U] 
            = ((0xffe00000U & vlSelfRef.l1d_cache__DOT__cache
                [__VdlyDim0__l1d_cache__DOT__cache__v8][4U]) 
               | __VdlyVal__l1d_cache__DOT__cache__v8);
        vlSelfRef.l1d_cache__DOT__cache[__VdlyDim0__l1d_cache__DOT__cache__v9][4U] 
            = (0x400000U | vlSelfRef.l1d_cache__DOT__cache
               [__VdlyDim0__l1d_cache__DOT__cache__v9][4U]);
    }
    vlSelfRef.l1d_cache__DOT__hit0 = ((((0x1fffffU 
                                         & vlSelfRef.l1d_cache__DOT__cache
                                         [(0x7fU & 
                                           (vlSelfRef.addr 
                                            >> 4U))][4U]) 
                                        == (vlSelfRef.addr 
                                            >> 0xbU)) 
                                       & (vlSelfRef.l1d_cache__DOT__cache
                                          [(0x7fU & 
                                            (vlSelfRef.addr 
                                             >> 4U))][4U] 
                                          >> 0x16U)) 
                                      & (IData)(vlSelfRef.fetch));
    vlSelfRef.l1d_cache__DOT__hit1 = ((((0x1fffffU 
                                         & ((vlSelfRef.l1d_cache__DOT__cache
                                             [(0x7fU 
                                               & (vlSelfRef.addr 
                                                  >> 4U))][9U] 
                                             << 9U) 
                                            | (vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][8U] 
                                               >> 0x17U))) 
                                        == (vlSelfRef.addr 
                                            >> 0xbU)) 
                                       & (vlSelfRef.l1d_cache__DOT__cache
                                          [(0x7fU & 
                                            (vlSelfRef.addr 
                                             >> 4U))][9U] 
                                          >> 0xdU)) 
                                      & (IData)(vlSelfRef.fetch));
    vlSelfRef.l1d_cache__DOT__miss = ((~ ((IData)(vlSelfRef.l1d_cache__DOT__hit0) 
                                          | (IData)(vlSelfRef.l1d_cache__DOT__hit1))) 
                                      & (IData)(vlSelfRef.fetch));
    vlSelfRef.l1d_cache__DOT__valid0 = (1U & (vlSelfRef.l1d_cache__DOT__cache
                                              [(0x7fU 
                                                & (vlSelfRef.addr 
                                                   >> 4U))][4U] 
                                              >> 0x16U));
    vlSelfRef.l1d_cache__DOT__valid1 = (1U & (vlSelfRef.l1d_cache__DOT__cache
                                              [(0x7fU 
                                                & (vlSelfRef.addr 
                                                   >> 4U))][9U] 
                                              >> 0xdU));
    vlSelfRef.l1d_cache__DOT__wmask[0U] = 0U;
    vlSelfRef.l1d_cache__DOT__wmask[1U] = 0U;
    vlSelfRef.l1d_cache__DOT__wmask[2U] = 0U;
    vlSelfRef.l1d_cache__DOT__wmask[3U] = 0U;
    vlSelfRef.stall = 0U;
    vlSelfRef.l1d_cache__DOT__wr_en = 0U;
    vlSelfRef.l1d_cache__DOT__rd_en = 0U;
    vlSelfRef.l1d_cache__DOT__write_data[0U] = 0U;
    vlSelfRef.l1d_cache__DOT__write_data[1U] = 0U;
    vlSelfRef.l1d_cache__DOT__write_data[2U] = 0U;
    vlSelfRef.l1d_cache__DOT__write_data[3U] = 0U;
    vlSelfRef.data_out = 0U;
    if (vlSelfRef.l1d_cache__DOT__miss) {
        vlSelfRef.stall = 1U;
        vlSelfRef.l1d_cache__DOT__wmask[0U] = 0xffffffffU;
        vlSelfRef.l1d_cache__DOT__wmask[1U] = 0xffffffffU;
        vlSelfRef.l1d_cache__DOT__wmask[2U] = 0xffffffffU;
        vlSelfRef.l1d_cache__DOT__wmask[3U] = 0xffffffffU;
        vlSelfRef.l1d_cache__DOT__way = ((~ ((~ (IData)(vlSelfRef.l1d_cache__DOT__valid0)) 
                                             & (~ (IData)(vlSelfRef.l1d_cache__DOT__valid1)))) 
                                         & ((IData)(vlSelfRef.l1d_cache__DOT__valid0) 
                                            & ((~ (IData)(vlSelfRef.l1d_cache__DOT__valid1)) 
                                               | (~ 
                                                  (vlSelfRef.l1d_cache__DOT__cache
                                                   [
                                                   (0x7fU 
                                                    & (vlSelfRef.addr 
                                                       >> 4U))][9U] 
                                                   >> 0xeU)))));
    } else {
        vlSelfRef.l1d_cache__DOT__way = vlSelfRef.l1d_cache__DOT__hit1;
        if (((IData)(vlSelfRef.MemWrite_m) & (IData)(vlSelfRef.fetch))) {
            vlSelfRef.l1d_cache__DOT__wr_en = 1U;
            vlSelfRef.l1d_cache__DOT__wmask[0U] = 0xffffffffU;
            vlSelfRef.l1d_cache__DOT__wmask[1U] = 0xffffffffU;
            vlSelfRef.l1d_cache__DOT__wmask[2U] = 0xffffffffU;
            vlSelfRef.l1d_cache__DOT__wmask[3U] = 0xffffffffU;
            if ((0U == (IData)(vlSelfRef.SizeWrite_m))) {
                vlSelfRef.l1d_cache__DOT__bottom_bit 
                    = vlSelfRef.l1d_cache__DOT____VdfgExtracted_h18ae9b83__0;
                VL_ASSIGNSEL_WI(128,8,(IData)(vlSelfRef.l1d_cache__DOT__bottom_bit), vlSelfRef.l1d_cache__DOT__wmask, 0U);
            } else if ((1U == (IData)(vlSelfRef.SizeWrite_m))) {
                vlSelfRef.l1d_cache__DOT__bottom_bit 
                    = vlSelfRef.l1d_cache__DOT____VdfgExtracted_h18ae9b83__0;
                VL_ASSIGNSEL_WI(128,16,(IData)(vlSelfRef.l1d_cache__DOT__bottom_bit), vlSelfRef.l1d_cache__DOT__wmask, 0U);
            } else if ((2U == (IData)(vlSelfRef.SizeWrite_m))) {
                vlSelfRef.l1d_cache__DOT__bottom_bit 
                    = (0x7fU & VL_SHIFTL_III(7,7,32, 
                                             (3U & 
                                              (vlSelfRef.addr 
                                               >> 2U)), 5U));
                VL_ASSIGNSEL_WI(128,32,(IData)(vlSelfRef.l1d_cache__DOT__bottom_bit), vlSelfRef.l1d_cache__DOT__wmask, 0U);
            }
            __Vtemp_9[1U] = (~ vlSelfRef.l1d_cache__DOT__wmask[1U]);
            __Vtemp_9[2U] = (~ vlSelfRef.l1d_cache__DOT__wmask[2U]);
            __Vtemp_9[3U] = (~ vlSelfRef.l1d_cache__DOT__wmask[3U]);
            vlSelfRef.l1d_cache__DOT__wmask[0U] = (~ 
                                                   vlSelfRef.l1d_cache__DOT__wmask[0U]);
            vlSelfRef.l1d_cache__DOT__wmask[1U] = __Vtemp_9[1U];
            vlSelfRef.l1d_cache__DOT__wmask[2U] = __Vtemp_9[2U];
            vlSelfRef.l1d_cache__DOT__wmask[3U] = __Vtemp_9[3U];
        }
    }
    if (vlSelfRef.fetch) {
        if (vlSelfRef.l1d_cache__DOT__miss) {
            vlSelfRef.l1d_cache__DOT__rd_en = 0U;
            vlSelfRef.l1d_cache__DOT__wr_en = 1U;
            vlSelfRef.l1d_cache__DOT__write_data[0U] 
                = vlSelfRef.line_from_mem[0U];
            vlSelfRef.l1d_cache__DOT__write_data[1U] 
                = vlSelfRef.line_from_mem[1U];
            vlSelfRef.l1d_cache__DOT__write_data[2U] 
                = vlSelfRef.line_from_mem[2U];
            vlSelfRef.l1d_cache__DOT__write_data[3U] 
                = vlSelfRef.line_from_mem[3U];
        } else {
            vlSelfRef.l1d_cache__DOT__rd_en = 1U;
            if (vlSelfRef.MemWrite_m) {
                vlSelfRef.l1d_cache__DOT__wr_en = 1U;
                vlSelfRef.l1d_cache__DOT__write_data[0U] 
                    = vlSelfRef.wd;
                vlSelfRef.l1d_cache__DOT__write_data[1U] 
                    = vlSelfRef.wd;
                vlSelfRef.l1d_cache__DOT__write_data[2U] 
                    = vlSelfRef.wd;
                vlSelfRef.l1d_cache__DOT__write_data[3U] 
                    = vlSelfRef.wd;
            }
        }
    }
    if (vlSelfRef.l1d_cache__DOT__rd_en) {
        if (vlSelfRef.l1d_cache__DOT__way) {
            if (vlSelfRef.l1d_cache__DOT__way) {
                vlSelfRef.data_out = ((8U & vlSelfRef.addr)
                                       ? ((4U & vlSelfRef.addr)
                                           ? ((vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][8U] 
                                               << 9U) 
                                              | (vlSelfRef.l1d_cache__DOT__cache
                                                 [(0x7fU 
                                                   & (vlSelfRef.addr 
                                                      >> 4U))][7U] 
                                                 >> 0x17U))
                                           : ((vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][7U] 
                                               << 9U) 
                                              | (vlSelfRef.l1d_cache__DOT__cache
                                                 [(0x7fU 
                                                   & (vlSelfRef.addr 
                                                      >> 4U))][6U] 
                                                 >> 0x17U)))
                                       : ((4U & vlSelfRef.addr)
                                           ? ((vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][6U] 
                                               << 9U) 
                                              | (vlSelfRef.l1d_cache__DOT__cache
                                                 [(0x7fU 
                                                   & (vlSelfRef.addr 
                                                      >> 4U))][5U] 
                                                 >> 0x17U))
                                           : ((vlSelfRef.l1d_cache__DOT__cache
                                               [(0x7fU 
                                                 & (vlSelfRef.addr 
                                                    >> 4U))][5U] 
                                               << 9U) 
                                              | (vlSelfRef.l1d_cache__DOT__cache
                                                 [(0x7fU 
                                                   & (vlSelfRef.addr 
                                                      >> 4U))][4U] 
                                                 >> 0x17U))));
            }
        } else {
            vlSelfRef.data_out = ((8U & vlSelfRef.addr)
                                   ? ((4U & vlSelfRef.addr)
                                       ? vlSelfRef.l1d_cache__DOT__cache
                                      [(0x7fU & (vlSelfRef.addr 
                                                 >> 4U))][3U]
                                       : vlSelfRef.l1d_cache__DOT__cache
                                      [(0x7fU & (vlSelfRef.addr 
                                                 >> 4U))][2U])
                                   : ((4U & vlSelfRef.addr)
                                       ? vlSelfRef.l1d_cache__DOT__cache
                                      [(0x7fU & (vlSelfRef.addr 
                                                 >> 4U))][1U]
                                       : vlSelfRef.l1d_cache__DOT__cache
                                      [(0x7fU & (vlSelfRef.addr 
                                                 >> 4U))][0U]));
        }
        if ((0U == (IData)(vlSelfRef.LoadSize))) {
            vlSelfRef.l1d_cache__DOT__bottom_bit = 
                (0x7fU & VL_SHIFTL_III(7,7,32, (3U 
                                                & vlSelfRef.addr), 3U));
            vlSelfRef.data_out = ((IData)(vlSelfRef.LoadUnsigned)
                                   ? (0xffU & (vlSelfRef.data_out 
                                               >> (0x1fU 
                                                   & (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))
                                   : (((- (IData)((1U 
                                                   & (vlSelfRef.data_out 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(7U) 
                                                          + (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))))) 
                                       << 8U) | (0xffU 
                                                 & (vlSelfRef.data_out 
                                                    >> 
                                                    (0x1fU 
                                                     & (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))));
        } else if ((1U == (IData)(vlSelfRef.LoadSize))) {
            vlSelfRef.l1d_cache__DOT__bottom_bit = 
                (0x7fU & VL_SHIFTL_III(7,7,32, (3U 
                                                & vlSelfRef.addr), 4U));
            vlSelfRef.data_out = ((IData)(vlSelfRef.LoadUnsigned)
                                   ? (0xffffU & (vlSelfRef.data_out 
                                                 >> 
                                                 (0x1fU 
                                                  & (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))
                                   : (((- (IData)((1U 
                                                   & (vlSelfRef.data_out 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(0xfU) 
                                                          + (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))))) 
                                       << 0x10U) | 
                                      (0xffffU & (vlSelfRef.data_out 
                                                  >> 
                                                  (0x1fU 
                                                   & (IData)(vlSelfRef.l1d_cache__DOT__bottom_bit))))));
        }
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
VL_ATTR_COLD void Vdut___024root___dump_triggers__ico(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
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
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/Users/tahamunir/Downloads/Team5-cache_leo/repo/rtl/l1d_cache.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vdut___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/tahamunir/Downloads/Team5-cache_leo/repo/rtl/l1d_cache.sv", 1, "", "NBA region did not converge.");
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
                VL_FATAL_MT("/Users/tahamunir/Downloads/Team5-cache_leo/repo/rtl/l1d_cache.sv", 1, "", "Active region did not converge.");
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
    if (VL_UNLIKELY(((vlSelfRef.fetch & 0xfeU)))) {
        Verilated::overWidthError("fetch");}
    if (VL_UNLIKELY(((vlSelfRef.SizeWrite_m & 0xfcU)))) {
        Verilated::overWidthError("SizeWrite_m");}
    if (VL_UNLIKELY(((vlSelfRef.MemWrite_m & 0xfeU)))) {
        Verilated::overWidthError("MemWrite_m");}
    if (VL_UNLIKELY(((vlSelfRef.LoadSize & 0xfcU)))) {
        Verilated::overWidthError("LoadSize");}
    if (VL_UNLIKELY(((vlSelfRef.LoadUnsigned & 0xfeU)))) {
        Verilated::overWidthError("LoadUnsigned");}
}
#endif  // VL_DEBUG
