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
    vlSelf->l2_cache__DOT__tag_bits_rd = (vlSelf->l2_cache__DOT__addr 
                                          >> 0xdU);
    vlSelf->l2_cache__DOT__set_rd = (0xffU & (vlSelf->l2_cache__DOT__addr 
                                              >> 5U));
    vlSelf->l2_cache__DOT__block_offset_rd = (7U & 
                                              (vlSelf->l2_cache__DOT__addr 
                                               >> 2U));
    vlSelf->l2_cache__DOT__req_i = 0U;
    vlSelf->l2_cache__DOT__req_d = 0U;
    if ((1U & (~ ((~ (IData)(vlSelf->fetch_i)) & (~ (IData)(vlSelf->fetch_d)))))) {
        if (((IData)(vlSelf->fetch_i) & (~ (IData)(vlSelf->fetch_d)))) {
            vlSelf->l2_cache__DOT__req_i = 1U;
        }
        if ((1U & (~ ((IData)(vlSelf->fetch_i) & (~ (IData)(vlSelf->fetch_d)))))) {
            if (((~ (IData)(vlSelf->fetch_i)) & (IData)(vlSelf->fetch_d))) {
                vlSelf->l2_cache__DOT__req_d = 1U;
            } else if (((IData)(vlSelf->fetch_i) & (IData)(vlSelf->fetch_d))) {
                vlSelf->l2_cache__DOT__req_d = 1U;
            }
        }
    }
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
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U] 
            = (0x1ffffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U] 
            = (0x2ffffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U] 
            = (0x37fffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U] 
            = (0x3bfffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U] 
            = (0x3dfffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U]);
        vlSelf->l2_cache__DOT__cache[(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U] 
            = (0x3efffffU & vlSelf->l2_cache__DOT__cache
               [(0xffU & vlSelf->l2_cache__DOT__unnamedblk1__DOT__i)][0x22U]);
        vlSelf->l2_cache__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelf->l2_cache__DOT__unnamedblk1__DOT__i);
    }
    vlSelf->l2_cache__DOT__l1write_buffer = 0U;
    vlSelf->l2_cache__DOT__l2write_buffer = 0U;
}

VL_ATTR_COLD void Vdut___024root___settle__TOP__1(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___settle__TOP__1\n"); );
    // Body
    vlSelf->l2_cache__DOT__fetch = 0U;
    vlSelf->l2_cache__DOT__addr = 0U;
    vlSelf->l2_cache__DOT__l1write = 0U;
    vlSelf->l2_cache__DOT__wmask[0U] = 0U;
    vlSelf->l2_cache__DOT__wmask[1U] = 0U;
    vlSelf->l2_cache__DOT__wmask[2U] = 0U;
    vlSelf->l2_cache__DOT__wmask[3U] = 0U;
    vlSelf->l2_cache__DOT__wmask[4U] = 0U;
    vlSelf->l2_cache__DOT__wmask[5U] = 0U;
    vlSelf->l2_cache__DOT__wmask[6U] = 0U;
    vlSelf->l2_cache__DOT__wmask[7U] = 0U;
    vlSelf->l2_cache__DOT__wr_en = 0U;
    vlSelf->l2_cache__DOT__rd_en = 0U;
    vlSelf->l2_cache__DOT__wr_wb = 0U;
    vlSelf->l2_cache__DOT__write_data[0U] = 0U;
    vlSelf->l2_cache__DOT__write_data[1U] = 0U;
    vlSelf->l2_cache__DOT__write_data[2U] = 0U;
    vlSelf->l2_cache__DOT__write_data[3U] = 0U;
    vlSelf->l2_cache__DOT__write_data[4U] = 0U;
    vlSelf->l2_cache__DOT__write_data[5U] = 0U;
    vlSelf->l2_cache__DOT__write_data[6U] = 0U;
    vlSelf->l2_cache__DOT__write_data[7U] = 0U;
    vlSelf->l2_cache__DOT__evict = 0U;
    vlSelf->main_mem_addr = 0U;
    vlSelf->main_mem_fetch = 0U;
    vlSelf->l2_cache__DOT__wb_ready_d_next = 0U;
    vlSelf->l2_cache__DOT__l1write_buffer_next = vlSelf->l2_cache__DOT__l1write_buffer;
    vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[0U] 
        = vlSelf->l2_cache__DOT__l1write_back_data_buffer[0U];
    vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[1U] 
        = vlSelf->l2_cache__DOT__l1write_back_data_buffer[1U];
    vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[2U] 
        = vlSelf->l2_cache__DOT__l1write_back_data_buffer[2U];
    vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[3U] 
        = vlSelf->l2_cache__DOT__l1write_back_data_buffer[3U];
    vlSelf->l2_cache__DOT__l1write_back_addr_buffer_next 
        = vlSelf->l2_cache__DOT__l1write_back_addr_buffer;
    vlSelf->l2_cache__DOT__l2write_buffer_next = vlSelf->l2_cache__DOT__l2write_buffer;
    vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[0U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer[0U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[1U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer[1U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[2U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer[2U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[3U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer[3U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[4U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer[4U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[5U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer[5U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[6U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer[6U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[7U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer[7U];
    vlSelf->l2_cache__DOT__l2write_back_addr_buffer_next 
        = vlSelf->l2_cache__DOT__l2write_back_addr_buffer;
    vlSelf->l2_cache__DOT__write_back_en_next = 0U;
    vlSelf->write_back_addr = 0U;
    vlSelf->l2_cache__DOT__write_back_data_next[0U] = 0U;
    vlSelf->l2_cache__DOT__write_back_data_next[1U] = 0U;
    vlSelf->l2_cache__DOT__write_back_data_next[2U] = 0U;
    vlSelf->l2_cache__DOT__write_back_data_next[3U] = 0U;
    vlSelf->l2_cache__DOT__way = 0U;
    vlSelf->l2_cache__DOT__way_rd = 0U;
    vlSelf->l2_cache__DOT__clean = 0U;
    vlSelf->l2_cache__DOT__tag_bits = 0U;
    vlSelf->l2_cache__DOT__set = 0U;
    vlSelf->l2_cache__DOT__block_offset = 0U;
    if ((1U & ((~ (IData)(vlSelf->fetch_i)) & (~ (IData)(vlSelf->fetch_d))))) {
        vlSelf->l2_cache__DOT__fetch = 0U;
        vlSelf->l2_cache__DOT__l1write = 0U;
    } else if (((IData)(vlSelf->fetch_i) & (~ (IData)(vlSelf->fetch_d)))) {
        vlSelf->l2_cache__DOT__fetch = 1U;
        vlSelf->l2_cache__DOT__addr = vlSelf->addr_i;
        vlSelf->l2_cache__DOT__l1write = 0U;
    } else if (((~ (IData)(vlSelf->fetch_i)) & (IData)(vlSelf->fetch_d))) {
        vlSelf->l2_cache__DOT__fetch = 1U;
        vlSelf->l2_cache__DOT__addr = vlSelf->addr_d;
        vlSelf->l2_cache__DOT__l1write = vlSelf->l1write_back_en;
    } else if (((IData)(vlSelf->fetch_i) & (IData)(vlSelf->fetch_d))) {
        vlSelf->l2_cache__DOT__fetch = 1U;
        vlSelf->l2_cache__DOT__addr = vlSelf->addr_d;
        vlSelf->l2_cache__DOT__l1write = vlSelf->l1write_back_en;
    }
    vlSelf->l2_cache__DOT__hit0 = (((0x7ffffU & vlSelf->l2_cache__DOT__cache
                                     [vlSelf->l2_cache__DOT__set_rd][8U]) 
                                    == vlSelf->l2_cache__DOT__tag_bits_rd) 
                                   & (vlSelf->l2_cache__DOT__cache
                                      [vlSelf->l2_cache__DOT__set_rd][8U] 
                                      >> 0x14U));
    vlSelf->l2_cache__DOT__hit1 = (((0x7ffffU & ((vlSelf->l2_cache__DOT__cache
                                                  [vlSelf->l2_cache__DOT__set_rd][0x11U] 
                                                  << 0xbU) 
                                                 | (vlSelf->l2_cache__DOT__cache
                                                    [vlSelf->l2_cache__DOT__set_rd][0x10U] 
                                                    >> 0x15U))) 
                                    == vlSelf->l2_cache__DOT__tag_bits_rd) 
                                   & (vlSelf->l2_cache__DOT__cache
                                      [vlSelf->l2_cache__DOT__set_rd][0x11U] 
                                      >> 9U));
    vlSelf->l2_cache__DOT__hit2 = (((0x7ffffU & (vlSelf->l2_cache__DOT__cache
                                                 [vlSelf->l2_cache__DOT__set_rd][0x19U] 
                                                 >> 0xaU)) 
                                    == vlSelf->l2_cache__DOT__tag_bits_rd) 
                                   & (vlSelf->l2_cache__DOT__cache
                                      [vlSelf->l2_cache__DOT__set_rd][0x19U] 
                                      >> 0x1eU));
    vlSelf->l2_cache__DOT__hit3 = (((0x7ffffU & ((vlSelf->l2_cache__DOT__cache
                                                  [vlSelf->l2_cache__DOT__set_rd][0x22U] 
                                                  << 1U) 
                                                 | (vlSelf->l2_cache__DOT__cache
                                                    [vlSelf->l2_cache__DOT__set_rd][0x21U] 
                                                    >> 0x1fU))) 
                                    == vlSelf->l2_cache__DOT__tag_bits_rd) 
                                   & (vlSelf->l2_cache__DOT__cache
                                      [vlSelf->l2_cache__DOT__set_rd][0x22U] 
                                      >> 0x13U));
    vlSelf->l2_cache__DOT__miss = (1U & (~ ((((IData)(vlSelf->l2_cache__DOT__hit0) 
                                              | (IData)(vlSelf->l2_cache__DOT__hit1)) 
                                             | (IData)(vlSelf->l2_cache__DOT__hit2)) 
                                            | (IData)(vlSelf->l2_cache__DOT__hit3))));
    vlSelf->l2_cache__DOT__valid0 = (1U & (vlSelf->l2_cache__DOT__cache
                                           [vlSelf->l2_cache__DOT__set_rd][8U] 
                                           >> 0x14U));
    vlSelf->l2_cache__DOT__valid1 = (1U & (vlSelf->l2_cache__DOT__cache
                                           [vlSelf->l2_cache__DOT__set_rd][0x11U] 
                                           >> 9U));
    vlSelf->l2_cache__DOT__valid2 = (1U & (vlSelf->l2_cache__DOT__cache
                                           [vlSelf->l2_cache__DOT__set_rd][0x19U] 
                                           >> 0x1eU));
    vlSelf->l2_cache__DOT__valid3 = (1U & (vlSelf->l2_cache__DOT__cache
                                           [vlSelf->l2_cache__DOT__set_rd][0x22U] 
                                           >> 0x13U));
    vlSelf->l2_cache__DOT__hit0_wb = (((0x7ffffU & 
                                        vlSelf->l2_cache__DOT__cache
                                        [(0xffU & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                                   >> 5U))][8U]) 
                                       == (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                           >> 0xdU)) 
                                      & (vlSelf->l2_cache__DOT__cache
                                         [(0xffU & 
                                           (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                            >> 5U))][8U] 
                                         >> 0x14U));
    vlSelf->l2_cache__DOT__hit1_wb = (((0x7ffffU & 
                                        ((vlSelf->l2_cache__DOT__cache
                                          [(0xffU & 
                                            (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                             >> 5U))][0x11U] 
                                          << 0xbU) 
                                         | (vlSelf->l2_cache__DOT__cache
                                            [(0xffU 
                                              & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                                 >> 5U))][0x10U] 
                                            >> 0x15U))) 
                                       == (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                           >> 0xdU)) 
                                      & (vlSelf->l2_cache__DOT__cache
                                         [(0xffU & 
                                           (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                            >> 5U))][0x11U] 
                                         >> 9U));
    vlSelf->l2_cache__DOT__hit2_wb = (((0x7ffffU & 
                                        (vlSelf->l2_cache__DOT__cache
                                         [(0xffU & 
                                           (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                            >> 5U))][0x19U] 
                                         >> 0xaU)) 
                                       == (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                           >> 0xdU)) 
                                      & (vlSelf->l2_cache__DOT__cache
                                         [(0xffU & 
                                           (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                            >> 5U))][0x19U] 
                                         >> 0x1eU));
    vlSelf->l2_cache__DOT__hit3_wb = (((0x7ffffU & 
                                        ((vlSelf->l2_cache__DOT__cache
                                          [(0xffU & 
                                            (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                             >> 5U))][0x22U] 
                                          << 1U) | 
                                         (vlSelf->l2_cache__DOT__cache
                                          [(0xffU & 
                                            (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                             >> 5U))][0x21U] 
                                          >> 0x1fU))) 
                                       == (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                           >> 0xdU)) 
                                      & (vlSelf->l2_cache__DOT__cache
                                         [(0xffU & 
                                           (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                            >> 5U))][0x22U] 
                                         >> 0x13U));
    vlSelf->l2_cache__DOT__miss_wb = (1U & (~ ((((IData)(vlSelf->l2_cache__DOT__hit0_wb) 
                                                 | (IData)(vlSelf->l2_cache__DOT__hit1_wb)) 
                                                | (IData)(vlSelf->l2_cache__DOT__hit2_wb)) 
                                               | (IData)(vlSelf->l2_cache__DOT__hit3_wb))));
    if (((IData)(vlSelf->l2_cache__DOT__l1write) & 
         (~ (IData)(vlSelf->l2_cache__DOT__l1write_buffer)))) {
        vlSelf->l2_cache__DOT__wb_ready_d_next = 1U;
        vlSelf->l2_cache__DOT__l1write_buffer_next 
            = vlSelf->l2_cache__DOT__l1write;
        vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[0U] 
            = vlSelf->l1write_back_data[0U];
        vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[1U] 
            = vlSelf->l1write_back_data[1U];
        vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[2U] 
            = vlSelf->l1write_back_data[2U];
        vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[3U] 
            = vlSelf->l1write_back_data[3U];
        vlSelf->l2_cache__DOT__l1write_back_addr_buffer_next 
            = vlSelf->l1write_back_addr;
    }
    if (vlSelf->l2_cache__DOT__fetch) {
        if (vlSelf->l2_cache__DOT__miss) {
            vlSelf->main_mem_addr = vlSelf->l2_cache__DOT__addr;
            vlSelf->main_mem_fetch = 1U;
            if (vlSelf->l2_cache__DOT__valid0) {
                if (vlSelf->l2_cache__DOT__valid1) {
                    if (vlSelf->l2_cache__DOT__valid2) {
                        if (vlSelf->l2_cache__DOT__valid3) {
                            vlSelf->l2_cache__DOT__evict = 1U;
                            vlSelf->l2_cache__DOT__way_rd 
                                = ((0x2000000U & vlSelf->l2_cache__DOT__cache
                                    [vlSelf->l2_cache__DOT__set_rd][0x22U])
                                    ? ((0x400000U & 
                                        vlSelf->l2_cache__DOT__cache
                                        [vlSelf->l2_cache__DOT__set_rd][0x22U])
                                        ? ((0x100000U 
                                            & vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][0x22U])
                                            ? 3U : 2U)
                                        : ((0x200000U 
                                            & vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][0x22U])
                                            ? 3U : 1U))
                                    : ((0x1000000U 
                                        & vlSelf->l2_cache__DOT__cache
                                        [vlSelf->l2_cache__DOT__set_rd][0x22U])
                                        ? ((0x100000U 
                                            & vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][0x22U])
                                            ? 3U : 2U)
                                        : ((0x800000U 
                                            & vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][0x22U])
                                            ? 3U : 0U)));
                        } else {
                            vlSelf->l2_cache__DOT__way_rd = 3U;
                        }
                    } else {
                        vlSelf->l2_cache__DOT__way_rd = 2U;
                    }
                } else {
                    vlSelf->l2_cache__DOT__way_rd = 1U;
                }
            } else {
                vlSelf->l2_cache__DOT__way_rd = 0U;
            }
            if (vlSelf->l2_cache__DOT__evict) {
                if ((0U == (IData)(vlSelf->l2_cache__DOT__way_rd))) {
                    if (((vlSelf->l2_cache__DOT__cache
                          [vlSelf->l2_cache__DOT__set_rd][8U] 
                          >> 0x13U) & (0U == (IData)(vlSelf->l2_cache__DOT__l2write_buffer)))) {
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[0U] 
                            = vlSelf->l2_cache__DOT__cache
                            [vlSelf->l2_cache__DOT__set_rd][0U];
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[1U] 
                            = vlSelf->l2_cache__DOT__cache
                            [vlSelf->l2_cache__DOT__set_rd][1U];
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[2U] 
                            = vlSelf->l2_cache__DOT__cache
                            [vlSelf->l2_cache__DOT__set_rd][2U];
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[3U] 
                            = vlSelf->l2_cache__DOT__cache
                            [vlSelf->l2_cache__DOT__set_rd][3U];
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[4U] 
                            = vlSelf->l2_cache__DOT__cache
                            [vlSelf->l2_cache__DOT__set_rd][4U];
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[5U] 
                            = vlSelf->l2_cache__DOT__cache
                            [vlSelf->l2_cache__DOT__set_rd][5U];
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[6U] 
                            = vlSelf->l2_cache__DOT__cache
                            [vlSelf->l2_cache__DOT__set_rd][6U];
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[7U] 
                            = vlSelf->l2_cache__DOT__cache
                            [vlSelf->l2_cache__DOT__set_rd][7U];
                        vlSelf->l2_cache__DOT__l2write_back_addr_buffer_next 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][8U] 
                                << 0xdU) | ((IData)(vlSelf->l2_cache__DOT__set_rd) 
                                            << 5U));
                        vlSelf->l2_cache__DOT__clean = 1U;
                        vlSelf->l2_cache__DOT__l2write_buffer_next = 2U;
                    } else if (((~ (vlSelf->l2_cache__DOT__cache
                                    [vlSelf->l2_cache__DOT__set_rd][8U] 
                                    >> 0x13U)) & (IData)(vlSelf->ready))) {
                        vlSelf->l2_cache__DOT__wr_en = 1U;
                        vlSelf->l2_cache__DOT__write_data[0U] 
                            = vlSelf->line_from_mem[0U];
                        vlSelf->l2_cache__DOT__write_data[1U] 
                            = vlSelf->line_from_mem[1U];
                        vlSelf->l2_cache__DOT__write_data[2U] 
                            = vlSelf->line_from_mem[2U];
                        vlSelf->l2_cache__DOT__write_data[3U] 
                            = vlSelf->line_from_mem[3U];
                        vlSelf->l2_cache__DOT__write_data[4U] 
                            = vlSelf->line_from_mem[4U];
                        vlSelf->l2_cache__DOT__write_data[5U] 
                            = vlSelf->line_from_mem[5U];
                        vlSelf->l2_cache__DOT__write_data[6U] 
                            = vlSelf->line_from_mem[6U];
                        vlSelf->l2_cache__DOT__write_data[7U] 
                            = vlSelf->line_from_mem[7U];
                        vlSelf->l2_cache__DOT__wmask[0U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[1U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[2U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[3U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[4U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[5U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[6U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[7U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__way 
                            = vlSelf->l2_cache__DOT__way_rd;
                        vlSelf->l2_cache__DOT__tag_bits 
                            = vlSelf->l2_cache__DOT__tag_bits_rd;
                        vlSelf->l2_cache__DOT__set 
                            = vlSelf->l2_cache__DOT__set_rd;
                        vlSelf->l2_cache__DOT__block_offset 
                            = vlSelf->l2_cache__DOT__block_offset_rd;
                    }
                } else if ((1U == (IData)(vlSelf->l2_cache__DOT__way_rd))) {
                    if (((vlSelf->l2_cache__DOT__cache
                          [vlSelf->l2_cache__DOT__set_rd][0x11U] 
                          >> 8U) & (0U == (IData)(vlSelf->l2_cache__DOT__l2write_buffer)))) {
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[0U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][9U] 
                                << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][8U] 
                                            >> 0x15U));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[1U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0xaU] 
                                << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][9U] 
                                            >> 0x15U));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[2U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0xbU] 
                                << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][0xaU] 
                                            >> 0x15U));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[3U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0xcU] 
                                << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][0xbU] 
                                            >> 0x15U));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[4U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0xdU] 
                                << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][0xcU] 
                                            >> 0x15U));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[5U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0xeU] 
                                << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][0xdU] 
                                            >> 0x15U));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[6U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0xfU] 
                                << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][0xeU] 
                                            >> 0x15U));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[7U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x10U] 
                                << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                            [vlSelf->l2_cache__DOT__set_rd][0xfU] 
                                            >> 0x15U));
                        vlSelf->l2_cache__DOT__l2write_back_addr_buffer_next 
                            = ((0xffffe000U & ((vlSelf->l2_cache__DOT__cache
                                                [vlSelf->l2_cache__DOT__set_rd][0x11U] 
                                                << 0x18U) 
                                               | (0xffe000U 
                                                  & (vlSelf->l2_cache__DOT__cache
                                                     [vlSelf->l2_cache__DOT__set_rd][0x10U] 
                                                     >> 8U)))) 
                               | ((IData)(vlSelf->l2_cache__DOT__set_rd) 
                                  << 5U));
                        vlSelf->l2_cache__DOT__clean = 1U;
                        vlSelf->l2_cache__DOT__l2write_buffer_next = 2U;
                    } else if (((~ (vlSelf->l2_cache__DOT__cache
                                    [vlSelf->l2_cache__DOT__set_rd][0x11U] 
                                    >> 8U)) & (IData)(vlSelf->ready))) {
                        vlSelf->l2_cache__DOT__wr_en = 1U;
                        vlSelf->l2_cache__DOT__write_data[0U] 
                            = vlSelf->line_from_mem[0U];
                        vlSelf->l2_cache__DOT__write_data[1U] 
                            = vlSelf->line_from_mem[1U];
                        vlSelf->l2_cache__DOT__write_data[2U] 
                            = vlSelf->line_from_mem[2U];
                        vlSelf->l2_cache__DOT__write_data[3U] 
                            = vlSelf->line_from_mem[3U];
                        vlSelf->l2_cache__DOT__write_data[4U] 
                            = vlSelf->line_from_mem[4U];
                        vlSelf->l2_cache__DOT__write_data[5U] 
                            = vlSelf->line_from_mem[5U];
                        vlSelf->l2_cache__DOT__write_data[6U] 
                            = vlSelf->line_from_mem[6U];
                        vlSelf->l2_cache__DOT__write_data[7U] 
                            = vlSelf->line_from_mem[7U];
                        vlSelf->l2_cache__DOT__wmask[0U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[1U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[2U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[3U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[4U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[5U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[6U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[7U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__tag_bits 
                            = vlSelf->l2_cache__DOT__tag_bits_rd;
                        vlSelf->l2_cache__DOT__set 
                            = vlSelf->l2_cache__DOT__set_rd;
                        vlSelf->l2_cache__DOT__block_offset 
                            = vlSelf->l2_cache__DOT__block_offset_rd;
                        vlSelf->l2_cache__DOT__way 
                            = vlSelf->l2_cache__DOT__way_rd;
                    }
                } else if ((2U == (IData)(vlSelf->l2_cache__DOT__way_rd))) {
                    if (((vlSelf->l2_cache__DOT__cache
                          [vlSelf->l2_cache__DOT__set_rd][0x19U] 
                          >> 0x1dU) & (0U == (IData)(vlSelf->l2_cache__DOT__l2write_buffer)))) {
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[0U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x12U] 
                                << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set_rd][0x11U] 
                                             >> 0xaU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[1U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x13U] 
                                << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set_rd][0x12U] 
                                             >> 0xaU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[2U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x14U] 
                                << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set_rd][0x13U] 
                                             >> 0xaU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[3U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x15U] 
                                << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set_rd][0x14U] 
                                             >> 0xaU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[4U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x16U] 
                                << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set_rd][0x15U] 
                                             >> 0xaU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[5U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x17U] 
                                << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set_rd][0x16U] 
                                             >> 0xaU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[6U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x18U] 
                                << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set_rd][0x17U] 
                                             >> 0xaU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[7U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x19U] 
                                << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set_rd][0x18U] 
                                             >> 0xaU));
                        vlSelf->l2_cache__DOT__l2write_back_addr_buffer_next 
                            = ((0xffffe000U & (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set_rd][0x19U] 
                                               << 3U)) 
                               | ((IData)(vlSelf->l2_cache__DOT__set_rd) 
                                  << 5U));
                        vlSelf->l2_cache__DOT__clean = 1U;
                        vlSelf->l2_cache__DOT__l2write_buffer_next = 2U;
                    } else if (((~ (vlSelf->l2_cache__DOT__cache
                                    [vlSelf->l2_cache__DOT__set_rd][0x19U] 
                                    >> 0x1dU)) & (IData)(vlSelf->ready))) {
                        vlSelf->l2_cache__DOT__wr_en = 1U;
                        vlSelf->l2_cache__DOT__write_data[0U] 
                            = vlSelf->line_from_mem[0U];
                        vlSelf->l2_cache__DOT__write_data[1U] 
                            = vlSelf->line_from_mem[1U];
                        vlSelf->l2_cache__DOT__write_data[2U] 
                            = vlSelf->line_from_mem[2U];
                        vlSelf->l2_cache__DOT__write_data[3U] 
                            = vlSelf->line_from_mem[3U];
                        vlSelf->l2_cache__DOT__write_data[4U] 
                            = vlSelf->line_from_mem[4U];
                        vlSelf->l2_cache__DOT__write_data[5U] 
                            = vlSelf->line_from_mem[5U];
                        vlSelf->l2_cache__DOT__write_data[6U] 
                            = vlSelf->line_from_mem[6U];
                        vlSelf->l2_cache__DOT__write_data[7U] 
                            = vlSelf->line_from_mem[7U];
                        vlSelf->l2_cache__DOT__wmask[0U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[1U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[2U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[3U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[4U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[5U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[6U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[7U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__tag_bits 
                            = vlSelf->l2_cache__DOT__tag_bits_rd;
                        vlSelf->l2_cache__DOT__set 
                            = vlSelf->l2_cache__DOT__set_rd;
                        vlSelf->l2_cache__DOT__block_offset 
                            = vlSelf->l2_cache__DOT__block_offset_rd;
                        vlSelf->l2_cache__DOT__way 
                            = vlSelf->l2_cache__DOT__way_rd;
                    }
                } else if ((3U == (IData)(vlSelf->l2_cache__DOT__way_rd))) {
                    if (((vlSelf->l2_cache__DOT__cache
                          [vlSelf->l2_cache__DOT__set_rd][0x22U] 
                          >> 0x12U) & (0U == (IData)(vlSelf->l2_cache__DOT__l2write_buffer)))) {
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[0U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x1aU] 
                                << 1U) | (vlSelf->l2_cache__DOT__cache
                                          [vlSelf->l2_cache__DOT__set_rd][0x19U] 
                                          >> 0x1fU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[1U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x1bU] 
                                << 1U) | (vlSelf->l2_cache__DOT__cache
                                          [vlSelf->l2_cache__DOT__set_rd][0x1aU] 
                                          >> 0x1fU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[2U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x1cU] 
                                << 1U) | (vlSelf->l2_cache__DOT__cache
                                          [vlSelf->l2_cache__DOT__set_rd][0x1bU] 
                                          >> 0x1fU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[3U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x1dU] 
                                << 1U) | (vlSelf->l2_cache__DOT__cache
                                          [vlSelf->l2_cache__DOT__set_rd][0x1cU] 
                                          >> 0x1fU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[4U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x1eU] 
                                << 1U) | (vlSelf->l2_cache__DOT__cache
                                          [vlSelf->l2_cache__DOT__set_rd][0x1dU] 
                                          >> 0x1fU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[5U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x1fU] 
                                << 1U) | (vlSelf->l2_cache__DOT__cache
                                          [vlSelf->l2_cache__DOT__set_rd][0x1eU] 
                                          >> 0x1fU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[6U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x20U] 
                                << 1U) | (vlSelf->l2_cache__DOT__cache
                                          [vlSelf->l2_cache__DOT__set_rd][0x1fU] 
                                          >> 0x1fU));
                        vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[7U] 
                            = ((vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set_rd][0x21U] 
                                << 1U) | (vlSelf->l2_cache__DOT__cache
                                          [vlSelf->l2_cache__DOT__set_rd][0x20U] 
                                          >> 0x1fU));
                        vlSelf->l2_cache__DOT__l2write_back_addr_buffer_next 
                            = ((0xffffe000U & ((vlSelf->l2_cache__DOT__cache
                                                [vlSelf->l2_cache__DOT__set_rd][0x22U] 
                                                << 0xeU) 
                                               | (0x2000U 
                                                  & (vlSelf->l2_cache__DOT__cache
                                                     [vlSelf->l2_cache__DOT__set_rd][0x21U] 
                                                     >> 0x12U)))) 
                               | ((IData)(vlSelf->l2_cache__DOT__set_rd) 
                                  << 5U));
                        vlSelf->l2_cache__DOT__clean = 1U;
                        vlSelf->l2_cache__DOT__l2write_buffer_next = 2U;
                    } else if (((~ (vlSelf->l2_cache__DOT__cache
                                    [vlSelf->l2_cache__DOT__set_rd][0x22U] 
                                    >> 0x12U)) & (IData)(vlSelf->ready))) {
                        vlSelf->l2_cache__DOT__wr_en = 1U;
                        vlSelf->l2_cache__DOT__write_data[0U] 
                            = vlSelf->line_from_mem[0U];
                        vlSelf->l2_cache__DOT__write_data[1U] 
                            = vlSelf->line_from_mem[1U];
                        vlSelf->l2_cache__DOT__write_data[2U] 
                            = vlSelf->line_from_mem[2U];
                        vlSelf->l2_cache__DOT__write_data[3U] 
                            = vlSelf->line_from_mem[3U];
                        vlSelf->l2_cache__DOT__write_data[4U] 
                            = vlSelf->line_from_mem[4U];
                        vlSelf->l2_cache__DOT__write_data[5U] 
                            = vlSelf->line_from_mem[5U];
                        vlSelf->l2_cache__DOT__write_data[6U] 
                            = vlSelf->line_from_mem[6U];
                        vlSelf->l2_cache__DOT__write_data[7U] 
                            = vlSelf->line_from_mem[7U];
                        vlSelf->l2_cache__DOT__wmask[0U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[1U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[2U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[3U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[4U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[5U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[6U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__wmask[7U] = 0xffffffffU;
                        vlSelf->l2_cache__DOT__tag_bits 
                            = vlSelf->l2_cache__DOT__tag_bits_rd;
                        vlSelf->l2_cache__DOT__set 
                            = vlSelf->l2_cache__DOT__set_rd;
                        vlSelf->l2_cache__DOT__block_offset 
                            = vlSelf->l2_cache__DOT__block_offset_rd;
                        vlSelf->l2_cache__DOT__way 
                            = vlSelf->l2_cache__DOT__way_rd;
                    }
                }
            } else if (vlSelf->ready) {
                vlSelf->l2_cache__DOT__wr_en = 1U;
                vlSelf->l2_cache__DOT__write_data[0U] 
                    = vlSelf->line_from_mem[0U];
                vlSelf->l2_cache__DOT__write_data[1U] 
                    = vlSelf->line_from_mem[1U];
                vlSelf->l2_cache__DOT__write_data[2U] 
                    = vlSelf->line_from_mem[2U];
                vlSelf->l2_cache__DOT__write_data[3U] 
                    = vlSelf->line_from_mem[3U];
                vlSelf->l2_cache__DOT__write_data[4U] 
                    = vlSelf->line_from_mem[4U];
                vlSelf->l2_cache__DOT__write_data[5U] 
                    = vlSelf->line_from_mem[5U];
                vlSelf->l2_cache__DOT__write_data[6U] 
                    = vlSelf->line_from_mem[6U];
                vlSelf->l2_cache__DOT__write_data[7U] 
                    = vlSelf->line_from_mem[7U];
                vlSelf->l2_cache__DOT__wmask[0U] = 0xffffffffU;
                vlSelf->l2_cache__DOT__wmask[1U] = 0xffffffffU;
                vlSelf->l2_cache__DOT__wmask[2U] = 0xffffffffU;
                vlSelf->l2_cache__DOT__wmask[3U] = 0xffffffffU;
                vlSelf->l2_cache__DOT__wmask[4U] = 0xffffffffU;
                vlSelf->l2_cache__DOT__wmask[5U] = 0xffffffffU;
                vlSelf->l2_cache__DOT__wmask[6U] = 0xffffffffU;
                vlSelf->l2_cache__DOT__wmask[7U] = 0xffffffffU;
                vlSelf->l2_cache__DOT__tag_bits = vlSelf->l2_cache__DOT__tag_bits_rd;
                vlSelf->l2_cache__DOT__set = vlSelf->l2_cache__DOT__set_rd;
                vlSelf->l2_cache__DOT__block_offset 
                    = vlSelf->l2_cache__DOT__block_offset_rd;
                vlSelf->l2_cache__DOT__way = vlSelf->l2_cache__DOT__way_rd;
                vlSelf->main_mem_fetch = 0U;
            }
        } else if ((1U & (~ (IData)(vlSelf->l2_cache__DOT__miss)))) {
            if (vlSelf->l2_cache__DOT__hit0) {
                vlSelf->l2_cache__DOT__way = 0U;
            } else if (vlSelf->l2_cache__DOT__hit1) {
                vlSelf->l2_cache__DOT__way = 1U;
            } else if (vlSelf->l2_cache__DOT__hit2) {
                vlSelf->l2_cache__DOT__way = 2U;
            } else if (vlSelf->l2_cache__DOT__hit3) {
                vlSelf->l2_cache__DOT__way = 3U;
            }
            if ((1U & ((~ (IData)(vlSelf->l2_cache__DOT__l1write)) 
                       | (IData)(vlSelf->l2_cache__DOT__wb_ready_d_next)))) {
                vlSelf->l2_cache__DOT__rd_en = 1U;
                vlSelf->l2_cache__DOT__tag_bits = vlSelf->l2_cache__DOT__tag_bits_rd;
                vlSelf->l2_cache__DOT__set = vlSelf->l2_cache__DOT__set_rd;
                vlSelf->l2_cache__DOT__block_offset 
                    = vlSelf->l2_cache__DOT__block_offset_rd;
            }
        }
    }
    if ((((IData)(vlSelf->l2_cache__DOT__wr_en) & (IData)(vlSelf->l2_cache__DOT__l1write_buffer)) 
         & ((vlSelf->l2_cache__DOT__addr >> 4U) == 
            (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
             >> 4U)))) {
        vlSelf->l2_cache__DOT__wr_wb = 1U;
        vlSelf->l2_cache__DOT__l1write_buffer_next 
            = (1U & ((IData)(vlSelf->l2_cache__DOT__l1write_buffer) 
                     - (IData)(1U)));
        if ((0U == (7U & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                          >> 2U)))) {
            vlSelf->l2_cache__DOT__write_data[0U] = 
                vlSelf->l2_cache__DOT__l1write_back_data_buffer[0U];
            vlSelf->l2_cache__DOT__write_data[1U] = 
                vlSelf->l2_cache__DOT__l1write_back_data_buffer[1U];
            vlSelf->l2_cache__DOT__write_data[2U] = 
                vlSelf->l2_cache__DOT__l1write_back_data_buffer[2U];
            vlSelf->l2_cache__DOT__write_data[3U] = 
                vlSelf->l2_cache__DOT__l1write_back_data_buffer[3U];
        } else if ((4U == (7U & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                 >> 2U)))) {
            vlSelf->l2_cache__DOT__write_data[4U] = 
                vlSelf->l2_cache__DOT__l1write_back_data_buffer[0U];
            vlSelf->l2_cache__DOT__write_data[5U] = 
                vlSelf->l2_cache__DOT__l1write_back_data_buffer[1U];
            vlSelf->l2_cache__DOT__write_data[6U] = 
                vlSelf->l2_cache__DOT__l1write_back_data_buffer[2U];
            vlSelf->l2_cache__DOT__write_data[7U] = 
                vlSelf->l2_cache__DOT__l1write_back_data_buffer[3U];
        }
    }
    if (((2U == (IData)(vlSelf->l2_cache__DOT__l2write_buffer)) 
         & (IData)(vlSelf->wb_ready))) {
        vlSelf->l2_cache__DOT__write_back_en_next = 1U;
        vlSelf->l2_cache__DOT__write_back_data_next[0U] 
            = vlSelf->l2_cache__DOT__l2write_back_data_buffer[0U];
        vlSelf->l2_cache__DOT__write_back_data_next[1U] 
            = vlSelf->l2_cache__DOT__l2write_back_data_buffer[1U];
        vlSelf->l2_cache__DOT__write_back_data_next[2U] 
            = vlSelf->l2_cache__DOT__l2write_back_data_buffer[2U];
        vlSelf->l2_cache__DOT__write_back_data_next[3U] 
            = vlSelf->l2_cache__DOT__l2write_back_data_buffer[3U];
        vlSelf->write_back_addr = vlSelf->l2_cache__DOT__l2write_back_addr_buffer;
        vlSelf->l2_cache__DOT__l2write_buffer_next 
            = (3U & ((IData)(vlSelf->l2_cache__DOT__l2write_buffer) 
                     - (IData)(1U)));
    } else if (((1U == (IData)(vlSelf->l2_cache__DOT__l2write_buffer)) 
                & (IData)(vlSelf->wb_ready))) {
        vlSelf->l2_cache__DOT__write_back_en_next = 1U;
        vlSelf->l2_cache__DOT__write_back_data_next[0U] 
            = vlSelf->l2_cache__DOT__l2write_back_data_buffer[4U];
        vlSelf->l2_cache__DOT__write_back_data_next[1U] 
            = vlSelf->l2_cache__DOT__l2write_back_data_buffer[5U];
        vlSelf->l2_cache__DOT__write_back_data_next[2U] 
            = vlSelf->l2_cache__DOT__l2write_back_data_buffer[6U];
        vlSelf->l2_cache__DOT__write_back_data_next[3U] 
            = vlSelf->l2_cache__DOT__l2write_back_data_buffer[7U];
        vlSelf->write_back_addr = (0x10U | (0xffffffefU 
                                            & vlSelf->l2_cache__DOT__l2write_back_addr_buffer));
        vlSelf->l2_cache__DOT__l2write_buffer_next 
            = (3U & ((IData)(vlSelf->l2_cache__DOT__l2write_buffer) 
                     - (IData)(1U)));
    } else if ((((IData)(vlSelf->l2_cache__DOT__l1write_buffer) 
                 & (IData)(vlSelf->l2_cache__DOT__miss_wb)) 
                & (IData)(vlSelf->wb_ready))) {
        vlSelf->l2_cache__DOT__write_back_en_next = 1U;
        vlSelf->l2_cache__DOT__write_back_data_next[0U] 
            = vlSelf->l2_cache__DOT__l1write_back_data_buffer[0U];
        vlSelf->l2_cache__DOT__write_back_data_next[1U] 
            = vlSelf->l2_cache__DOT__l1write_back_data_buffer[1U];
        vlSelf->l2_cache__DOT__write_back_data_next[2U] 
            = vlSelf->l2_cache__DOT__l1write_back_data_buffer[2U];
        vlSelf->l2_cache__DOT__write_back_data_next[3U] 
            = vlSelf->l2_cache__DOT__l1write_back_data_buffer[3U];
        vlSelf->write_back_addr = vlSelf->l2_cache__DOT__l1write_back_addr_buffer;
        vlSelf->l2_cache__DOT__l1write_buffer_next 
            = (1U & ((IData)(vlSelf->l2_cache__DOT__l1write_buffer) 
                     - (IData)(1U)));
    }
    if (((((IData)(vlSelf->l2_cache__DOT__l1write_buffer) 
           & (~ (IData)(vlSelf->l2_cache__DOT__rd_en))) 
          & (~ (IData)(vlSelf->l2_cache__DOT__wr_en))) 
         & (~ (IData)(vlSelf->l2_cache__DOT__miss_wb)))) {
        vlSelf->l2_cache__DOT__wr_en = 1U;
        vlSelf->l2_cache__DOT__wr_wb = 1U;
        vlSelf->l2_cache__DOT__write_data[0U] = vlSelf->l2_cache__DOT__l1write_back_data_buffer[0U];
        vlSelf->l2_cache__DOT__write_data[1U] = vlSelf->l2_cache__DOT__l1write_back_data_buffer[1U];
        vlSelf->l2_cache__DOT__write_data[2U] = vlSelf->l2_cache__DOT__l1write_back_data_buffer[2U];
        vlSelf->l2_cache__DOT__write_data[3U] = vlSelf->l2_cache__DOT__l1write_back_data_buffer[3U];
        vlSelf->l2_cache__DOT__write_data[4U] = vlSelf->l2_cache__DOT__l1write_back_data_buffer[0U];
        vlSelf->l2_cache__DOT__write_data[5U] = vlSelf->l2_cache__DOT__l1write_back_data_buffer[1U];
        vlSelf->l2_cache__DOT__write_data[6U] = vlSelf->l2_cache__DOT__l1write_back_data_buffer[2U];
        vlSelf->l2_cache__DOT__write_data[7U] = vlSelf->l2_cache__DOT__l1write_back_data_buffer[3U];
        vlSelf->l2_cache__DOT__l1write_buffer_next 
            = (1U & ((IData)(vlSelf->l2_cache__DOT__l1write_buffer) 
                     - (IData)(1U)));
        if (vlSelf->l2_cache__DOT__hit0_wb) {
            vlSelf->l2_cache__DOT__way = 0U;
        } else if (vlSelf->l2_cache__DOT__hit1_wb) {
            vlSelf->l2_cache__DOT__way = 1U;
        } else if (vlSelf->l2_cache__DOT__hit2_wb) {
            vlSelf->l2_cache__DOT__way = 2U;
        } else if (vlSelf->l2_cache__DOT__hit3_wb) {
            vlSelf->l2_cache__DOT__way = 3U;
        }
        vlSelf->l2_cache__DOT__tag_bits = (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                           >> 0xdU);
        vlSelf->l2_cache__DOT__set = (0xffU & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                               >> 5U));
        vlSelf->l2_cache__DOT__block_offset = (7U & 
                                               (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                                >> 2U));
        if ((0U == (7U & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                          >> 2U)))) {
            vlSelf->l2_cache__DOT__wmask[0U] = 0xffffffffU;
            vlSelf->l2_cache__DOT__wmask[1U] = 0xffffffffU;
            vlSelf->l2_cache__DOT__wmask[2U] = 0xffffffffU;
            vlSelf->l2_cache__DOT__wmask[3U] = 0xffffffffU;
            vlSelf->l2_cache__DOT__wmask[4U] = 0U;
            vlSelf->l2_cache__DOT__wmask[5U] = 0U;
            vlSelf->l2_cache__DOT__wmask[6U] = 0U;
            vlSelf->l2_cache__DOT__wmask[7U] = 0U;
        } else if ((4U == (7U & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                 >> 2U)))) {
            vlSelf->l2_cache__DOT__wmask[0U] = 0U;
            vlSelf->l2_cache__DOT__wmask[1U] = 0U;
            vlSelf->l2_cache__DOT__wmask[2U] = 0U;
            vlSelf->l2_cache__DOT__wmask[3U] = 0U;
            vlSelf->l2_cache__DOT__wmask[4U] = 0xffffffffU;
            vlSelf->l2_cache__DOT__wmask[5U] = 0xffffffffU;
            vlSelf->l2_cache__DOT__wmask[6U] = 0xffffffffU;
            vlSelf->l2_cache__DOT__wmask[7U] = 0xffffffffU;
        }
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
    vlSelf->main_mem_addr = VL_RAND_RESET_I(32);
    vlSelf->main_mem_fetch = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        VL_RAND_RESET_W(1114, vlSelf->l2_cache__DOT__cache[__Vi0]);
    }
    vlSelf->l2_cache__DOT__wr_en = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__rd_en = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__wr_wb = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(256, vlSelf->l2_cache__DOT__write_data);
    vlSelf->l2_cache__DOT__clean = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__way_rd = VL_RAND_RESET_I(2);
    vlSelf->l2_cache__DOT__tag_bits_rd = VL_RAND_RESET_I(19);
    vlSelf->l2_cache__DOT__set_rd = VL_RAND_RESET_I(8);
    vlSelf->l2_cache__DOT__block_offset_rd = VL_RAND_RESET_I(3);
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
    vlSelf->l2_cache__DOT__wb_ready_d_next = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__write_back_en_next = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->l2_cache__DOT__write_back_data_next);
    VL_RAND_RESET_W(128, vlSelf->l2_cache__DOT__l1write_back_data_buffer);
    VL_RAND_RESET_W(128, vlSelf->l2_cache__DOT__l1write_back_data_buffer_next);
    vlSelf->l2_cache__DOT__l1write_buffer = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__l1write_buffer_next = VL_RAND_RESET_I(1);
    vlSelf->l2_cache__DOT__l1write_back_addr_buffer = VL_RAND_RESET_I(32);
    vlSelf->l2_cache__DOT__l1write_back_addr_buffer_next = VL_RAND_RESET_I(32);
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
    VL_RAND_RESET_W(256, vlSelf->l2_cache__DOT__l2write_back_data_buffer_next);
    vlSelf->l2_cache__DOT__l2write_buffer = VL_RAND_RESET_I(2);
    vlSelf->l2_cache__DOT__l2write_buffer_next = VL_RAND_RESET_I(2);
    vlSelf->l2_cache__DOT__l2write_back_addr_buffer = VL_RAND_RESET_I(32);
    vlSelf->l2_cache__DOT__l2write_back_addr_buffer_next = VL_RAND_RESET_I(32);
    vlSelf->l2_cache__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->__Vchglast__TOP__l2_cache__DOT__addr = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
