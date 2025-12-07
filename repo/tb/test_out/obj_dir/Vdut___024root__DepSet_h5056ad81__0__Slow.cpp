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
    vlSelf->l2_cache__DOT__req_valid = ((IData)(vlSelf->fetch_d) 
                                        | (IData)(vlSelf->fetch_i));
    vlSelf->l2_cache__DOT__req_is_i = ((~ (IData)(vlSelf->fetch_d)) 
                                       & (IData)(vlSelf->fetch_i));
    vlSelf->l2_cache__DOT__req_addr = ((IData)(vlSelf->fetch_d)
                                        ? vlSelf->addr_d
                                        : ((IData)(vlSelf->fetch_i)
                                            ? vlSelf->addr_i
                                            : 0U));
    vlSelf->l2_cache__DOT__l1_wb_set = (0xffU & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                 >> 5U));
    vlSelf->l2_cache__DOT__l1_wb_off = (7U & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                              >> 2U));
}

extern const VlWide<8>/*255:0*/ Vdut__ConstPool__CONST_h9e67c271_0;

VL_ATTR_COLD void Vdut___024root___initial__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___initial__TOP__0\n"); );
    // Body
    vlSelf->l2_cache__DOT__i = 0U;
    while (VL_GTS_III(32, 0x100U, vlSelf->l2_cache__DOT__i)) {
        vlSelf->l2_cache__DOT__rr_ptr[(0xffU & vlSelf->l2_cache__DOT__i)] = 0U;
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][0U][8U] 
            = (0xfffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [0U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][0U][8U] 
            = (0x17ffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [0U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][0U][8U] 
            = (0x180000U & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [0U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][0U][0U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[0U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][0U][1U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[1U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][0U][2U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[2U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][0U][3U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[3U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][0U][4U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[4U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][0U][5U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[5U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][0U][6U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[6U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][0U][7U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[7U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][1U][8U] 
            = (0xfffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [1U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][1U][8U] 
            = (0x17ffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [1U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][1U][8U] 
            = (0x180000U & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [1U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][1U][0U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[0U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][1U][1U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[1U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][1U][2U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[2U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][1U][3U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[3U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][1U][4U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[4U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][1U][5U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[5U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][1U][6U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[6U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][1U][7U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[7U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][2U][8U] 
            = (0xfffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [2U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][2U][8U] 
            = (0x17ffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [2U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][2U][8U] 
            = (0x180000U & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [2U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][2U][0U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[0U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][2U][1U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[1U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][2U][2U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[2U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][2U][3U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[3U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][2U][4U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[4U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][2U][5U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[5U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][2U][6U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[6U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][2U][7U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[7U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][3U][8U] 
            = (0xfffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [3U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][3U][8U] 
            = (0x17ffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [3U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][3U][8U] 
            = (0x180000U & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__i)]
               [3U][8U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][3U][0U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[0U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][3U][1U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[1U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][3U][2U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[2U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][3U][3U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[3U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][3U][4U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[4U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][3U][5U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[5U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][3U][6U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[6U];
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__i)][3U][7U] 
            = Vdut__ConstPool__CONST_h9e67c271_0[7U];
        vlSelf->l2_cache__DOT__j = 4U;
        vlSelf->l2_cache__DOT__i = ((IData)(1U) + vlSelf->l2_cache__DOT__i);
    }
    vlSelf->l2_cache__DOT__miss_pending = 0U;
    vlSelf->l2_cache__DOT__l1_wb_pending = 0U;
    vlSelf->l2_cache__DOT__evict_wb_pending = 0U;
}

VL_ATTR_COLD void Vdut___024root___settle__TOP__1(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___settle__TOP__1\n"); );
    // Body
    vlSelf->l2_cache__DOT__l1_wb_hit_vec = ((0xeU & (IData)(vlSelf->l2_cache__DOT__l1_wb_hit_vec)) 
                                            | ((vlSelf->l2_cache__DOT__cache
                                                [(0xffU 
                                                  & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                     >> 5U))]
                                                [0U][8U] 
                                                >> 0x14U) 
                                               & ((0x7ffffU 
                                                   & vlSelf->l2_cache__DOT__cache
                                                   [
                                                   (0xffU 
                                                    & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                       >> 5U))]
                                                   [0U][8U]) 
                                                  == 
                                                  (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                   >> 0xdU))));
    vlSelf->l2_cache__DOT__l1_wb_hit_vec = ((0xdU & (IData)(vlSelf->l2_cache__DOT__l1_wb_hit_vec)) 
                                            | (0x1ffeU 
                                               & ((vlSelf->l2_cache__DOT__cache
                                                   [
                                                   (0xffU 
                                                    & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                       >> 5U))]
                                                   [1U][8U] 
                                                   >> 0x13U) 
                                                  & (((0x7ffffU 
                                                       & vlSelf->l2_cache__DOT__cache
                                                       [
                                                       (0xffU 
                                                        & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                           >> 5U))]
                                                       [1U][8U]) 
                                                      == 
                                                      (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                       >> 0xdU)) 
                                                     << 1U))));
    vlSelf->l2_cache__DOT__l1_wb_hit_vec = ((0xbU & (IData)(vlSelf->l2_cache__DOT__l1_wb_hit_vec)) 
                                            | (0x3ffcU 
                                               & ((vlSelf->l2_cache__DOT__cache
                                                   [
                                                   (0xffU 
                                                    & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                       >> 5U))]
                                                   [2U][8U] 
                                                   >> 0x12U) 
                                                  & (((0x7ffffU 
                                                       & vlSelf->l2_cache__DOT__cache
                                                       [
                                                       (0xffU 
                                                        & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                           >> 5U))]
                                                       [2U][8U]) 
                                                      == 
                                                      (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                       >> 0xdU)) 
                                                     << 2U))));
    vlSelf->l2_cache__DOT__l1_wb_hit_vec = ((7U & (IData)(vlSelf->l2_cache__DOT__l1_wb_hit_vec)) 
                                            | (0x7ff8U 
                                               & ((vlSelf->l2_cache__DOT__cache
                                                   [
                                                   (0xffU 
                                                    & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                       >> 5U))]
                                                   [3U][8U] 
                                                   >> 0x11U) 
                                                  & (((0x7ffffU 
                                                       & vlSelf->l2_cache__DOT__cache
                                                       [
                                                       (0xffU 
                                                        & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                           >> 5U))]
                                                       [3U][8U]) 
                                                      == 
                                                      (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                       >> 0xdU)) 
                                                     << 3U))));
    vlSelf->l2_cache__DOT__l1_wb_hit = 0U;
    vlSelf->l2_cache__DOT__l1_wb_hit_way = 0U;
    if ((1U & (IData)(vlSelf->l2_cache__DOT__l1_wb_hit_vec))) {
        vlSelf->l2_cache__DOT__l1_wb_hit = 1U;
        vlSelf->l2_cache__DOT__l1_wb_hit_way = 0U;
    }
    if ((2U & (IData)(vlSelf->l2_cache__DOT__l1_wb_hit_vec))) {
        vlSelf->l2_cache__DOT__l1_wb_hit = 1U;
        vlSelf->l2_cache__DOT__l1_wb_hit_way = 1U;
    }
    if ((4U & (IData)(vlSelf->l2_cache__DOT__l1_wb_hit_vec))) {
        vlSelf->l2_cache__DOT__l1_wb_hit = 1U;
        vlSelf->l2_cache__DOT__l1_wb_hit_way = 2U;
    }
    if ((8U & (IData)(vlSelf->l2_cache__DOT__l1_wb_hit_vec))) {
        vlSelf->l2_cache__DOT__l1_wb_hit = 1U;
        vlSelf->l2_cache__DOT__l1_wb_hit_way = 3U;
    }
    vlSelf->l2_cache__DOT__hit_vec = ((0xeU & (IData)(vlSelf->l2_cache__DOT__hit_vec)) 
                                      | ((vlSelf->l2_cache__DOT__cache
                                          [(0xffU & 
                                            (vlSelf->l2_cache__DOT__req_addr 
                                             >> 5U))]
                                          [0U][8U] 
                                          >> 0x14U) 
                                         & ((0x7ffffU 
                                             & vlSelf->l2_cache__DOT__cache
                                             [(0xffU 
                                               & (vlSelf->l2_cache__DOT__req_addr 
                                                  >> 5U))]
                                             [0U][8U]) 
                                            == (vlSelf->l2_cache__DOT__req_addr 
                                                >> 0xdU))));
    vlSelf->l2_cache__DOT__hit_vec = ((0xdU & (IData)(vlSelf->l2_cache__DOT__hit_vec)) 
                                      | (0x1ffeU & 
                                         ((vlSelf->l2_cache__DOT__cache
                                           [(0xffU 
                                             & (vlSelf->l2_cache__DOT__req_addr 
                                                >> 5U))]
                                           [1U][8U] 
                                           >> 0x13U) 
                                          & (((0x7ffffU 
                                               & vlSelf->l2_cache__DOT__cache
                                               [(0xffU 
                                                 & (vlSelf->l2_cache__DOT__req_addr 
                                                    >> 5U))]
                                               [1U][8U]) 
                                              == (vlSelf->l2_cache__DOT__req_addr 
                                                  >> 0xdU)) 
                                             << 1U))));
    vlSelf->l2_cache__DOT__hit_vec = ((0xbU & (IData)(vlSelf->l2_cache__DOT__hit_vec)) 
                                      | (0x3ffcU & 
                                         ((vlSelf->l2_cache__DOT__cache
                                           [(0xffU 
                                             & (vlSelf->l2_cache__DOT__req_addr 
                                                >> 5U))]
                                           [2U][8U] 
                                           >> 0x12U) 
                                          & (((0x7ffffU 
                                               & vlSelf->l2_cache__DOT__cache
                                               [(0xffU 
                                                 & (vlSelf->l2_cache__DOT__req_addr 
                                                    >> 5U))]
                                               [2U][8U]) 
                                              == (vlSelf->l2_cache__DOT__req_addr 
                                                  >> 0xdU)) 
                                             << 2U))));
    vlSelf->l2_cache__DOT__hit_vec = ((7U & (IData)(vlSelf->l2_cache__DOT__hit_vec)) 
                                      | (0x7ff8U & 
                                         ((vlSelf->l2_cache__DOT__cache
                                           [(0xffU 
                                             & (vlSelf->l2_cache__DOT__req_addr 
                                                >> 5U))]
                                           [3U][8U] 
                                           >> 0x11U) 
                                          & (((0x7ffffU 
                                               & vlSelf->l2_cache__DOT__cache
                                               [(0xffU 
                                                 & (vlSelf->l2_cache__DOT__req_addr 
                                                    >> 5U))]
                                               [3U][8U]) 
                                              == (vlSelf->l2_cache__DOT__req_addr 
                                                  >> 0xdU)) 
                                             << 3U))));
    vlSelf->l2_cache__DOT__req_hit = 0U;
    vlSelf->l2_cache__DOT__hit_way = 0U;
    if ((1U & (IData)(vlSelf->l2_cache__DOT__hit_vec))) {
        vlSelf->l2_cache__DOT__req_hit = 1U;
        vlSelf->l2_cache__DOT__hit_way = 0U;
    }
    if ((2U & (IData)(vlSelf->l2_cache__DOT__hit_vec))) {
        vlSelf->l2_cache__DOT__req_hit = 1U;
        vlSelf->l2_cache__DOT__hit_way = 1U;
    }
    if ((4U & (IData)(vlSelf->l2_cache__DOT__hit_vec))) {
        vlSelf->l2_cache__DOT__req_hit = 1U;
        vlSelf->l2_cache__DOT__hit_way = 2U;
    }
    if ((8U & (IData)(vlSelf->l2_cache__DOT__hit_vec))) {
        vlSelf->l2_cache__DOT__req_hit = 1U;
        vlSelf->l2_cache__DOT__hit_way = 3U;
    }
    vlSelf->l2_cache__DOT__hit_line[0U] = 0U;
    vlSelf->l2_cache__DOT__hit_line[1U] = 0U;
    vlSelf->l2_cache__DOT__hit_line[2U] = 0U;
    vlSelf->l2_cache__DOT__hit_line[3U] = 0U;
    vlSelf->l2_cache__DOT__hit_line[4U] = 0U;
    vlSelf->l2_cache__DOT__hit_line[5U] = 0U;
    vlSelf->l2_cache__DOT__hit_line[6U] = 0U;
    vlSelf->l2_cache__DOT__hit_line[7U] = 0U;
    if (vlSelf->l2_cache__DOT__req_hit) {
        vlSelf->l2_cache__DOT__hit_line[0U] = vlSelf->l2_cache__DOT__cache
            [(0xffU & (vlSelf->l2_cache__DOT__req_addr 
                       >> 5U))][vlSelf->l2_cache__DOT__hit_way][0U];
        vlSelf->l2_cache__DOT__hit_line[1U] = vlSelf->l2_cache__DOT__cache
            [(0xffU & (vlSelf->l2_cache__DOT__req_addr 
                       >> 5U))][vlSelf->l2_cache__DOT__hit_way][1U];
        vlSelf->l2_cache__DOT__hit_line[2U] = vlSelf->l2_cache__DOT__cache
            [(0xffU & (vlSelf->l2_cache__DOT__req_addr 
                       >> 5U))][vlSelf->l2_cache__DOT__hit_way][2U];
        vlSelf->l2_cache__DOT__hit_line[3U] = vlSelf->l2_cache__DOT__cache
            [(0xffU & (vlSelf->l2_cache__DOT__req_addr 
                       >> 5U))][vlSelf->l2_cache__DOT__hit_way][3U];
        vlSelf->l2_cache__DOT__hit_line[4U] = vlSelf->l2_cache__DOT__cache
            [(0xffU & (vlSelf->l2_cache__DOT__req_addr 
                       >> 5U))][vlSelf->l2_cache__DOT__hit_way][4U];
        vlSelf->l2_cache__DOT__hit_line[5U] = vlSelf->l2_cache__DOT__cache
            [(0xffU & (vlSelf->l2_cache__DOT__req_addr 
                       >> 5U))][vlSelf->l2_cache__DOT__hit_way][5U];
        vlSelf->l2_cache__DOT__hit_line[6U] = vlSelf->l2_cache__DOT__cache
            [(0xffU & (vlSelf->l2_cache__DOT__req_addr 
                       >> 5U))][vlSelf->l2_cache__DOT__hit_way][6U];
        vlSelf->l2_cache__DOT__hit_line[7U] = vlSelf->l2_cache__DOT__cache
            [(0xffU & (vlSelf->l2_cache__DOT__req_addr 
                       >> 5U))][vlSelf->l2_cache__DOT__hit_way][7U];
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
    Vdut___024root___settle__TOP__1(vlSelf);
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
    vlSelf->ready = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->l1write_back_data);
    vlSelf->l1write_back_en = VL_RAND_RESET_I(1);
    vlSelf->l1write_back_addr = VL_RAND_RESET_I(32);
    vlSelf->wb_ready = VL_RAND_RESET_I(1);
    vlSelf->ready_i = VL_RAND_RESET_I(1);
    vlSelf->ready_d = VL_RAND_RESET_I(1);
    vlSelf->wb_ready_d = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->data_out);
    VL_RAND_RESET_W(128, vlSelf->write_back_data);
    vlSelf->write_back_addr = VL_RAND_RESET_I(32);
    vlSelf->write_back_en = VL_RAND_RESET_I(1);
    vlSelf->main_mem_addr = VL_RAND_RESET_I(32);
    vlSelf->main_mem_fetch = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        for (int __Vi1=0; __Vi1<4; ++__Vi1) {
            VL_RAND_RESET_W(277, vlSelf->l2_cache__DOT__cache[__Vi0][__Vi1]);
        }
    }
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->l2_cache__DOT__rr_ptr[__Vi0] = VL_RAND_RESET_I(2);
    }
    vlSelf->l2_cache__DOT__req_valid = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__req_is_i = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__req_addr = VL_RAND_RESET_I(32);
    vlSelf->l2_cache__DOT__hit_vec = VL_RAND_RESET_I(4);
    vlSelf->l2_cache__DOT__req_hit = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__hit_way = VL_RAND_RESET_I(2);
    vlSelf->l2_cache__DOT__miss_pending = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__miss_is_i = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__miss_addr = VL_RAND_RESET_I(32);
    vlSelf->l2_cache__DOT__miss_tag = VL_RAND_RESET_I(19);
    vlSelf->l2_cache__DOT__miss_set = VL_RAND_RESET_I(8);
    vlSelf->l2_cache__DOT__miss_way = VL_RAND_RESET_I(2);
    vlSelf->l2_cache__DOT__l1_wb_pending = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__l1_wb_addr = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->l2_cache__DOT__l1_wb_data);
    vlSelf->l2_cache__DOT__l1_wb_set = VL_RAND_RESET_I(8);
    vlSelf->l2_cache__DOT__l1_wb_off = VL_RAND_RESET_I(3);
    vlSelf->l2_cache__DOT__l1_wb_hit_vec = VL_RAND_RESET_I(4);
    vlSelf->l2_cache__DOT__l1_wb_hit = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__l1_wb_hit_way = VL_RAND_RESET_I(2);
    vlSelf->l2_cache__DOT__evict_wb_pending = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__evict_wb_addr = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, vlSelf->l2_cache__DOT__evict_wb_data);
    VL_RAND_RESET_W(256, vlSelf->l2_cache__DOT__hit_line);
    vlSelf->l2_cache__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->l2_cache__DOT__j = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
