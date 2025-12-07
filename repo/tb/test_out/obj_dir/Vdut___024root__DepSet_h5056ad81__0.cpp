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
    VlWide<4>/*127:0*/ __Vfunc_l2_cache__DOT__select_4words__0__Vfuncout;
    VlWide<8>/*255:0*/ __Vfunc_l2_cache__DOT__select_4words__0__line;
    CData/*2:0*/ __Vfunc_l2_cache__DOT__select_4words__0__off;
    VlWide<4>/*127:0*/ __Vfunc_l2_cache__DOT__select_4words__0__lower;
    VlWide<4>/*127:0*/ __Vfunc_l2_cache__DOT__select_4words__0__upper;
    CData/*1:0*/ __Vfunc_l2_cache__DOT__choose_victim__1__Vfuncout;
    CData/*7:0*/ __Vfunc_l2_cache__DOT__choose_victim__1__set;
    CData/*0:0*/ __Vdly__l2_cache__DOT__l1_wb_pending;
    IData/*31:0*/ __Vdly__l2_cache__DOT__l1_wb_addr;
    VlWide<4>/*127:0*/ __Vdly__l2_cache__DOT__l1_wb_data;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v0;
    CData/*1:0*/ __Vdlyvdim1__l2_cache__DOT__cache__v0;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v0;
    VlWide<4>/*127:0*/ __Vdlyvval__l2_cache__DOT__cache__v0;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v0;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v1;
    CData/*1:0*/ __Vdlyvdim1__l2_cache__DOT__cache__v1;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v1;
    VlWide<4>/*127:0*/ __Vdlyvval__l2_cache__DOT__cache__v1;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v1;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v2;
    CData/*1:0*/ __Vdlyvdim1__l2_cache__DOT__cache__v2;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v2;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v2;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v3;
    CData/*1:0*/ __Vdlyvdim1__l2_cache__DOT__cache__v3;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v3;
    VlWide<8>/*255:0*/ __Vdlyvval__l2_cache__DOT__cache__v3;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v3;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__rr_ptr__v0;
    CData/*1:0*/ __Vdlyvval__l2_cache__DOT__rr_ptr__v0;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v4;
    CData/*1:0*/ __Vdlyvdim1__l2_cache__DOT__cache__v4;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v4;
    IData/*18:0*/ __Vdlyvval__l2_cache__DOT__cache__v4;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v4;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v5;
    CData/*1:0*/ __Vdlyvdim1__l2_cache__DOT__cache__v5;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v5;
    CData/*0:0*/ __Vdly__l2_cache__DOT__evict_wb_pending;
    IData/*31:0*/ __Vdly__l2_cache__DOT__evict_wb_addr;
    VlWide<4>/*127:0*/ __Vdly__l2_cache__DOT__evict_wb_data;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v6;
    CData/*1:0*/ __Vdlyvdim1__l2_cache__DOT__cache__v6;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v6;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v6;
    // Body
    __Vdly__l2_cache__DOT__evict_wb_data[0U] = vlSelf->l2_cache__DOT__evict_wb_data[0U];
    __Vdly__l2_cache__DOT__evict_wb_data[1U] = vlSelf->l2_cache__DOT__evict_wb_data[1U];
    __Vdly__l2_cache__DOT__evict_wb_data[2U] = vlSelf->l2_cache__DOT__evict_wb_data[2U];
    __Vdly__l2_cache__DOT__evict_wb_data[3U] = vlSelf->l2_cache__DOT__evict_wb_data[3U];
    __Vdly__l2_cache__DOT__evict_wb_addr = vlSelf->l2_cache__DOT__evict_wb_addr;
    __Vdly__l2_cache__DOT__l1_wb_data[0U] = vlSelf->l2_cache__DOT__l1_wb_data[0U];
    __Vdly__l2_cache__DOT__l1_wb_data[1U] = vlSelf->l2_cache__DOT__l1_wb_data[1U];
    __Vdly__l2_cache__DOT__l1_wb_data[2U] = vlSelf->l2_cache__DOT__l1_wb_data[2U];
    __Vdly__l2_cache__DOT__l1_wb_data[3U] = vlSelf->l2_cache__DOT__l1_wb_data[3U];
    __Vdly__l2_cache__DOT__evict_wb_pending = vlSelf->l2_cache__DOT__evict_wb_pending;
    __Vdly__l2_cache__DOT__l1_wb_pending = vlSelf->l2_cache__DOT__l1_wb_pending;
    __Vdly__l2_cache__DOT__l1_wb_addr = vlSelf->l2_cache__DOT__l1_wb_addr;
    __Vdlyvset__l2_cache__DOT__cache__v0 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v1 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v2 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v4 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v6 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v3 = 0U;
    vlSelf->ready_i = 0U;
    vlSelf->ready_d = 0U;
    vlSelf->wb_ready_d = 0U;
    vlSelf->write_back_en = 0U;
    vlSelf->main_mem_fetch = 0U;
    vlSelf->main_mem_addr = vlSelf->main_mem_addr;
    if (((IData)(vlSelf->l1write_back_en) & (~ (IData)(vlSelf->l2_cache__DOT__l1_wb_pending)))) {
        vlSelf->wb_ready_d = 1U;
        __Vdly__l2_cache__DOT__l1_wb_pending = 1U;
        __Vdly__l2_cache__DOT__l1_wb_addr = vlSelf->l1write_back_addr;
        __Vdly__l2_cache__DOT__l1_wb_data[0U] = vlSelf->l1write_back_data[0U];
        __Vdly__l2_cache__DOT__l1_wb_data[1U] = vlSelf->l1write_back_data[1U];
        __Vdly__l2_cache__DOT__l1_wb_data[2U] = vlSelf->l1write_back_data[2U];
        __Vdly__l2_cache__DOT__l1_wb_data[3U] = vlSelf->l1write_back_data[3U];
        if (vlSelf->l2_cache__DOT__l1_wb_hit) {
            if ((4U & (IData)(vlSelf->l2_cache__DOT__l1_wb_off))) {
                __Vdlyvval__l2_cache__DOT__cache__v0[0U] 
                    = vlSelf->l1write_back_data[0U];
                __Vdlyvval__l2_cache__DOT__cache__v0[1U] 
                    = vlSelf->l1write_back_data[1U];
                __Vdlyvval__l2_cache__DOT__cache__v0[2U] 
                    = vlSelf->l1write_back_data[2U];
                __Vdlyvval__l2_cache__DOT__cache__v0[3U] 
                    = vlSelf->l1write_back_data[3U];
                __Vdlyvset__l2_cache__DOT__cache__v0 = 1U;
                __Vdlyvlsb__l2_cache__DOT__cache__v0 = 0x80U;
                __Vdlyvdim1__l2_cache__DOT__cache__v0 
                    = vlSelf->l2_cache__DOT__l1_wb_hit_way;
                __Vdlyvdim0__l2_cache__DOT__cache__v0 
                    = vlSelf->l2_cache__DOT__l1_wb_set;
            } else {
                __Vdlyvval__l2_cache__DOT__cache__v1[0U] 
                    = vlSelf->l1write_back_data[0U];
                __Vdlyvval__l2_cache__DOT__cache__v1[1U] 
                    = vlSelf->l1write_back_data[1U];
                __Vdlyvval__l2_cache__DOT__cache__v1[2U] 
                    = vlSelf->l1write_back_data[2U];
                __Vdlyvval__l2_cache__DOT__cache__v1[3U] 
                    = vlSelf->l1write_back_data[3U];
                __Vdlyvset__l2_cache__DOT__cache__v1 = 1U;
                __Vdlyvlsb__l2_cache__DOT__cache__v1 = 0U;
                __Vdlyvdim1__l2_cache__DOT__cache__v1 
                    = vlSelf->l2_cache__DOT__l1_wb_hit_way;
                __Vdlyvdim0__l2_cache__DOT__cache__v1 
                    = vlSelf->l2_cache__DOT__l1_wb_set;
            }
            __Vdlyvset__l2_cache__DOT__cache__v2 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v2 = 0x113U;
            __Vdlyvdim1__l2_cache__DOT__cache__v2 = vlSelf->l2_cache__DOT__l1_wb_hit_way;
            __Vdlyvdim0__l2_cache__DOT__cache__v2 = vlSelf->l2_cache__DOT__l1_wb_set;
        }
    }
    if (((IData)(vlSelf->l2_cache__DOT__l1_wb_pending) 
         & (IData)(vlSelf->wb_ready))) {
        vlSelf->write_back_en = 1U;
        vlSelf->write_back_addr = vlSelf->l2_cache__DOT__l1_wb_addr;
        vlSelf->write_back_data[0U] = vlSelf->l2_cache__DOT__l1_wb_data[0U];
        vlSelf->write_back_data[1U] = vlSelf->l2_cache__DOT__l1_wb_data[1U];
        vlSelf->write_back_data[2U] = vlSelf->l2_cache__DOT__l1_wb_data[2U];
        vlSelf->write_back_data[3U] = vlSelf->l2_cache__DOT__l1_wb_data[3U];
        __Vdly__l2_cache__DOT__l1_wb_pending = 0U;
    }
    if (vlSelf->l2_cache__DOT__miss_pending) {
        if (vlSelf->ready) {
            __Vdlyvval__l2_cache__DOT__cache__v3[0U] 
                = vlSelf->line_from_mem[0U];
            __Vdlyvval__l2_cache__DOT__cache__v3[1U] 
                = vlSelf->line_from_mem[1U];
            __Vdlyvval__l2_cache__DOT__cache__v3[2U] 
                = vlSelf->line_from_mem[2U];
            __Vdlyvval__l2_cache__DOT__cache__v3[3U] 
                = vlSelf->line_from_mem[3U];
            __Vdlyvval__l2_cache__DOT__cache__v3[4U] 
                = vlSelf->line_from_mem[4U];
            __Vdlyvval__l2_cache__DOT__cache__v3[5U] 
                = vlSelf->line_from_mem[5U];
            __Vdlyvval__l2_cache__DOT__cache__v3[6U] 
                = vlSelf->line_from_mem[6U];
            __Vdlyvval__l2_cache__DOT__cache__v3[7U] 
                = vlSelf->line_from_mem[7U];
            __Vdlyvset__l2_cache__DOT__cache__v3 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v3 = 0U;
            __Vdlyvdim1__l2_cache__DOT__cache__v3 = vlSelf->l2_cache__DOT__miss_way;
            __Vdlyvdim0__l2_cache__DOT__cache__v3 = vlSelf->l2_cache__DOT__miss_set;
            __Vdlyvval__l2_cache__DOT__rr_ptr__v0 = 
                (3U & ((IData)(1U) + (IData)(vlSelf->l2_cache__DOT__miss_way)));
            __Vdlyvdim0__l2_cache__DOT__rr_ptr__v0 
                = vlSelf->l2_cache__DOT__miss_set;
            vlSelf->l2_cache__DOT__miss_pending = 0U;
            __Vdlyvval__l2_cache__DOT__cache__v4 = vlSelf->l2_cache__DOT__miss_tag;
            __Vdlyvset__l2_cache__DOT__cache__v4 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v4 = 0x100U;
            __Vdlyvdim1__l2_cache__DOT__cache__v4 = vlSelf->l2_cache__DOT__miss_way;
            __Vdlyvdim0__l2_cache__DOT__cache__v4 = vlSelf->l2_cache__DOT__miss_set;
            __Vdlyvlsb__l2_cache__DOT__cache__v5 = 0x114U;
            __Vdlyvdim1__l2_cache__DOT__cache__v5 = vlSelf->l2_cache__DOT__miss_way;
            __Vdlyvdim0__l2_cache__DOT__cache__v5 = vlSelf->l2_cache__DOT__miss_set;
        }
    } else if (vlSelf->l2_cache__DOT__req_valid) {
        if (vlSelf->l2_cache__DOT__req_hit) {
            __Vfunc_l2_cache__DOT__select_4words__0__off 
                = (7U & (vlSelf->l2_cache__DOT__req_addr 
                         >> 2U));
            __Vfunc_l2_cache__DOT__select_4words__0__line[0U] 
                = vlSelf->l2_cache__DOT__hit_line[0U];
            __Vfunc_l2_cache__DOT__select_4words__0__line[1U] 
                = vlSelf->l2_cache__DOT__hit_line[1U];
            __Vfunc_l2_cache__DOT__select_4words__0__line[2U] 
                = vlSelf->l2_cache__DOT__hit_line[2U];
            __Vfunc_l2_cache__DOT__select_4words__0__line[3U] 
                = vlSelf->l2_cache__DOT__hit_line[3U];
            __Vfunc_l2_cache__DOT__select_4words__0__line[4U] 
                = vlSelf->l2_cache__DOT__hit_line[4U];
            __Vfunc_l2_cache__DOT__select_4words__0__line[5U] 
                = vlSelf->l2_cache__DOT__hit_line[5U];
            __Vfunc_l2_cache__DOT__select_4words__0__line[6U] 
                = vlSelf->l2_cache__DOT__hit_line[6U];
            __Vfunc_l2_cache__DOT__select_4words__0__line[7U] 
                = vlSelf->l2_cache__DOT__hit_line[7U];
            __Vfunc_l2_cache__DOT__select_4words__0__lower[0U] 
                = __Vfunc_l2_cache__DOT__select_4words__0__line[0U];
            __Vfunc_l2_cache__DOT__select_4words__0__lower[1U] 
                = __Vfunc_l2_cache__DOT__select_4words__0__line[1U];
            __Vfunc_l2_cache__DOT__select_4words__0__lower[2U] 
                = __Vfunc_l2_cache__DOT__select_4words__0__line[2U];
            __Vfunc_l2_cache__DOT__select_4words__0__lower[3U] 
                = __Vfunc_l2_cache__DOT__select_4words__0__line[3U];
            if (vlSelf->l2_cache__DOT__req_is_i) {
                vlSelf->ready_i = 1U;
            } else {
                vlSelf->ready_d = 1U;
            }
            __Vfunc_l2_cache__DOT__select_4words__0__upper[0U] 
                = __Vfunc_l2_cache__DOT__select_4words__0__line[4U];
            __Vfunc_l2_cache__DOT__select_4words__0__upper[1U] 
                = __Vfunc_l2_cache__DOT__select_4words__0__line[5U];
            __Vfunc_l2_cache__DOT__select_4words__0__upper[2U] 
                = __Vfunc_l2_cache__DOT__select_4words__0__line[6U];
            __Vfunc_l2_cache__DOT__select_4words__0__upper[3U] 
                = __Vfunc_l2_cache__DOT__select_4words__0__line[7U];
            __Vfunc_l2_cache__DOT__select_4words__0__Vfuncout[0U] 
                = ((4U & (IData)(__Vfunc_l2_cache__DOT__select_4words__0__off))
                    ? __Vfunc_l2_cache__DOT__select_4words__0__upper[0U]
                    : __Vfunc_l2_cache__DOT__select_4words__0__lower[0U]);
            __Vfunc_l2_cache__DOT__select_4words__0__Vfuncout[1U] 
                = ((4U & (IData)(__Vfunc_l2_cache__DOT__select_4words__0__off))
                    ? __Vfunc_l2_cache__DOT__select_4words__0__upper[1U]
                    : __Vfunc_l2_cache__DOT__select_4words__0__lower[1U]);
            __Vfunc_l2_cache__DOT__select_4words__0__Vfuncout[2U] 
                = ((4U & (IData)(__Vfunc_l2_cache__DOT__select_4words__0__off))
                    ? __Vfunc_l2_cache__DOT__select_4words__0__upper[2U]
                    : __Vfunc_l2_cache__DOT__select_4words__0__lower[2U]);
            __Vfunc_l2_cache__DOT__select_4words__0__Vfuncout[3U] 
                = ((4U & (IData)(__Vfunc_l2_cache__DOT__select_4words__0__off))
                    ? __Vfunc_l2_cache__DOT__select_4words__0__upper[3U]
                    : __Vfunc_l2_cache__DOT__select_4words__0__lower[3U]);
            vlSelf->data_out[0U] = __Vfunc_l2_cache__DOT__select_4words__0__Vfuncout[0U];
            vlSelf->data_out[1U] = __Vfunc_l2_cache__DOT__select_4words__0__Vfuncout[1U];
            vlSelf->data_out[2U] = __Vfunc_l2_cache__DOT__select_4words__0__Vfuncout[2U];
            vlSelf->data_out[3U] = __Vfunc_l2_cache__DOT__select_4words__0__Vfuncout[3U];
        } else {
            vlSelf->l2_cache__DOT__miss_pending = 1U;
            vlSelf->l2_cache__DOT__miss_is_i = vlSelf->l2_cache__DOT__req_is_i;
            vlSelf->l2_cache__DOT__miss_addr = vlSelf->l2_cache__DOT__req_addr;
            vlSelf->l2_cache__DOT__miss_tag = (vlSelf->l2_cache__DOT__req_addr 
                                               >> 0xdU);
            vlSelf->l2_cache__DOT__miss_set = (0xffU 
                                               & (vlSelf->l2_cache__DOT__req_addr 
                                                  >> 5U));
            __Vfunc_l2_cache__DOT__choose_victim__1__set 
                = (0xffU & (vlSelf->l2_cache__DOT__req_addr 
                            >> 5U));
            {
                {
                    if ((1U & (~ (vlSelf->l2_cache__DOT__cache
                                  [__Vfunc_l2_cache__DOT__choose_victim__1__set]
                                  [0U][8U] >> 0x14U)))) {
                        __Vfunc_l2_cache__DOT__choose_victim__1__Vfuncout = 0U;
                        goto __Vlabel2;
                    }
                    if ((1U & (~ (vlSelf->l2_cache__DOT__cache
                                  [__Vfunc_l2_cache__DOT__choose_victim__1__set]
                                  [1U][8U] >> 0x14U)))) {
                        __Vfunc_l2_cache__DOT__choose_victim__1__Vfuncout = 1U;
                        goto __Vlabel2;
                    }
                    if ((1U & (~ (vlSelf->l2_cache__DOT__cache
                                  [__Vfunc_l2_cache__DOT__choose_victim__1__set]
                                  [2U][8U] >> 0x14U)))) {
                        __Vfunc_l2_cache__DOT__choose_victim__1__Vfuncout = 2U;
                        goto __Vlabel2;
                    }
                    if ((1U & (~ (vlSelf->l2_cache__DOT__cache
                                  [__Vfunc_l2_cache__DOT__choose_victim__1__set]
                                  [3U][8U] >> 0x14U)))) {
                        __Vfunc_l2_cache__DOT__choose_victim__1__Vfuncout = 3U;
                        goto __Vlabel2;
                    }
                    __Vfunc_l2_cache__DOT__choose_victim__1__Vfuncout 
                        = vlSelf->l2_cache__DOT__rr_ptr
                        [__Vfunc_l2_cache__DOT__choose_victim__1__set];
                    goto __Vlabel1;
                    __Vlabel2: ;
                }
                __Vlabel1: ;
            }
            vlSelf->l2_cache__DOT__miss_way = __Vfunc_l2_cache__DOT__choose_victim__1__Vfuncout;
            if ((IData)(((vlSelf->l2_cache__DOT__cache
                          [(0xffU & (vlSelf->l2_cache__DOT__req_addr 
                                     >> 5U))][vlSelf->l2_cache__DOT__miss_way][8U] 
                          >> 0x14U) & (vlSelf->l2_cache__DOT__cache
                                       [(0xffU & (vlSelf->l2_cache__DOT__req_addr 
                                                  >> 5U))]
                                       [vlSelf->l2_cache__DOT__miss_way][8U] 
                                       >> 0x13U)))) {
                __Vdly__l2_cache__DOT__evict_wb_pending = 1U;
                __Vdly__l2_cache__DOT__evict_wb_addr 
                    = ((vlSelf->l2_cache__DOT__cache
                        [(0xffU & (vlSelf->l2_cache__DOT__req_addr 
                                   >> 5U))][vlSelf->l2_cache__DOT__miss_way][8U] 
                        << 0xdU) | (0x1fe0U & vlSelf->l2_cache__DOT__req_addr));
                __Vdly__l2_cache__DOT__evict_wb_data[0U] 
                    = vlSelf->l2_cache__DOT__cache[
                    (0xffU & (vlSelf->l2_cache__DOT__req_addr 
                              >> 5U))][vlSelf->l2_cache__DOT__miss_way][0U];
                __Vdly__l2_cache__DOT__evict_wb_data[1U] 
                    = vlSelf->l2_cache__DOT__cache[
                    (0xffU & (vlSelf->l2_cache__DOT__req_addr 
                              >> 5U))][vlSelf->l2_cache__DOT__miss_way][1U];
                __Vdly__l2_cache__DOT__evict_wb_data[2U] 
                    = vlSelf->l2_cache__DOT__cache[
                    (0xffU & (vlSelf->l2_cache__DOT__req_addr 
                              >> 5U))][vlSelf->l2_cache__DOT__miss_way][2U];
                __Vdly__l2_cache__DOT__evict_wb_data[3U] 
                    = vlSelf->l2_cache__DOT__cache[
                    (0xffU & (vlSelf->l2_cache__DOT__req_addr 
                              >> 5U))][vlSelf->l2_cache__DOT__miss_way][3U];
                __Vdlyvset__l2_cache__DOT__cache__v6 = 1U;
                __Vdlyvlsb__l2_cache__DOT__cache__v6 = 0x113U;
                __Vdlyvdim1__l2_cache__DOT__cache__v6 
                    = vlSelf->l2_cache__DOT__miss_way;
                __Vdlyvdim0__l2_cache__DOT__cache__v6 
                    = (0xffU & (vlSelf->l2_cache__DOT__req_addr 
                                >> 5U));
            }
            vlSelf->main_mem_addr = vlSelf->l2_cache__DOT__req_addr;
            vlSelf->main_mem_fetch = 1U;
        }
    }
    if (vlSelf->l2_cache__DOT__evict_wb_pending) {
        vlSelf->write_back_en = 1U;
        vlSelf->write_back_addr = vlSelf->l2_cache__DOT__evict_wb_addr;
        vlSelf->write_back_data[0U] = vlSelf->l2_cache__DOT__evict_wb_data[0U];
        vlSelf->write_back_data[1U] = vlSelf->l2_cache__DOT__evict_wb_data[1U];
        vlSelf->write_back_data[2U] = vlSelf->l2_cache__DOT__evict_wb_data[2U];
        vlSelf->write_back_data[3U] = vlSelf->l2_cache__DOT__evict_wb_data[3U];
        __Vdly__l2_cache__DOT__evict_wb_pending = 0U;
    }
    vlSelf->l2_cache__DOT__l1_wb_data[0U] = __Vdly__l2_cache__DOT__l1_wb_data[0U];
    vlSelf->l2_cache__DOT__l1_wb_data[1U] = __Vdly__l2_cache__DOT__l1_wb_data[1U];
    vlSelf->l2_cache__DOT__l1_wb_data[2U] = __Vdly__l2_cache__DOT__l1_wb_data[2U];
    vlSelf->l2_cache__DOT__l1_wb_data[3U] = __Vdly__l2_cache__DOT__l1_wb_data[3U];
    vlSelf->l2_cache__DOT__evict_wb_addr = __Vdly__l2_cache__DOT__evict_wb_addr;
    vlSelf->l2_cache__DOT__evict_wb_data[0U] = __Vdly__l2_cache__DOT__evict_wb_data[0U];
    vlSelf->l2_cache__DOT__evict_wb_data[1U] = __Vdly__l2_cache__DOT__evict_wb_data[1U];
    vlSelf->l2_cache__DOT__evict_wb_data[2U] = __Vdly__l2_cache__DOT__evict_wb_data[2U];
    vlSelf->l2_cache__DOT__evict_wb_data[3U] = __Vdly__l2_cache__DOT__evict_wb_data[3U];
    vlSelf->l2_cache__DOT__l1_wb_addr = __Vdly__l2_cache__DOT__l1_wb_addr;
    vlSelf->l2_cache__DOT__l1_wb_pending = __Vdly__l2_cache__DOT__l1_wb_pending;
    vlSelf->l2_cache__DOT__evict_wb_pending = __Vdly__l2_cache__DOT__evict_wb_pending;
    if (__Vdlyvset__l2_cache__DOT__cache__v0) {
        VL_ASSIGNSEL_WW(277,128,__Vdlyvlsb__l2_cache__DOT__cache__v0, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v0]
                        [__Vdlyvdim1__l2_cache__DOT__cache__v0], __Vdlyvval__l2_cache__DOT__cache__v0);
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v1) {
        VL_ASSIGNSEL_WW(277,128,__Vdlyvlsb__l2_cache__DOT__cache__v1, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v1]
                        [__Vdlyvdim1__l2_cache__DOT__cache__v1], __Vdlyvval__l2_cache__DOT__cache__v1);
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v2) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v2][__Vdlyvdim1__l2_cache__DOT__cache__v2][(__Vdlyvlsb__l2_cache__DOT__cache__v2 
                                                                                >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v2]
               [__Vdlyvdim1__l2_cache__DOT__cache__v2][
               (__Vdlyvlsb__l2_cache__DOT__cache__v2 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v2)));
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v3) {
        vlSelf->l2_cache__DOT__rr_ptr[__Vdlyvdim0__l2_cache__DOT__rr_ptr__v0] 
            = __Vdlyvval__l2_cache__DOT__rr_ptr__v0;
        VL_ASSIGNSEL_WW(277,256,__Vdlyvlsb__l2_cache__DOT__cache__v3, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v3]
                        [__Vdlyvdim1__l2_cache__DOT__cache__v3], __Vdlyvval__l2_cache__DOT__cache__v3);
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v4) {
        VL_ASSIGNSEL_WI(277,19,__Vdlyvlsb__l2_cache__DOT__cache__v4, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v4]
                        [__Vdlyvdim1__l2_cache__DOT__cache__v4], __Vdlyvval__l2_cache__DOT__cache__v4);
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v5][__Vdlyvdim1__l2_cache__DOT__cache__v5][(__Vdlyvlsb__l2_cache__DOT__cache__v5 
                                                                                >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v5]
               [__Vdlyvdim1__l2_cache__DOT__cache__v5][
               (__Vdlyvlsb__l2_cache__DOT__cache__v5 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v5)));
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v6) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v6][__Vdlyvdim1__l2_cache__DOT__cache__v6][(__Vdlyvlsb__l2_cache__DOT__cache__v6 
                                                                                >> 5U)] 
            = ((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v6))) 
               & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v6]
               [__Vdlyvdim1__l2_cache__DOT__cache__v6][
               (__Vdlyvlsb__l2_cache__DOT__cache__v6 
                >> 5U)]);
    }
    vlSelf->l2_cache__DOT__l1_wb_set = (0xffU & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                                 >> 5U));
    vlSelf->l2_cache__DOT__l1_wb_off = (7U & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                              >> 2U));
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
}

VL_INLINE_OPT void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__0\n"); );
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

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->fetch_i & 0xfeU))) {
        Verilated::overWidthError("fetch_i");}
    if (VL_UNLIKELY((vlSelf->fetch_d & 0xfeU))) {
        Verilated::overWidthError("fetch_d");}
    if (VL_UNLIKELY((vlSelf->ready & 0xfeU))) {
        Verilated::overWidthError("ready");}
    if (VL_UNLIKELY((vlSelf->l1write_back_en & 0xfeU))) {
        Verilated::overWidthError("l1write_back_en");}
    if (VL_UNLIKELY((vlSelf->wb_ready & 0xfeU))) {
        Verilated::overWidthError("wb_ready");}
}
#endif  // VL_DEBUG
