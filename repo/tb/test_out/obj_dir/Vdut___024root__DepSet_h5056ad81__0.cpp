// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_INLINE_OPT void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->l2_cache__DOT__tag_bits_rd = (vlSelf->l2_cache__DOT__addr 
                                          >> 0xdU);
    vlSelf->l2_cache__DOT__set_rd = (0xffU & (vlSelf->l2_cache__DOT__addr 
                                              >> 5U));
    vlSelf->l2_cache__DOT__block_offset_rd = (7U & 
                                              (vlSelf->l2_cache__DOT__addr 
                                               >> 2U));
}

VL_INLINE_OPT void Vdut___024root___sequent__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v0;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v0;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v0;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v1;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v1;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v1;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v2;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v2;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v2;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v3;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v3;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v3;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v4;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v4;
    CData/*0:0*/ __Vdlyvval__l2_cache__DOT__cache__v4;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v4;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v5;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v5;
    VlWide<8>/*255:0*/ __Vdlyvval__l2_cache__DOT__cache__v5;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v6;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v6;
    IData/*18:0*/ __Vdlyvval__l2_cache__DOT__cache__v6;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v7;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v7;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v8;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v8;
    CData/*0:0*/ __Vdlyvval__l2_cache__DOT__cache__v8;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v8;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v9;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v9;
    VlWide<8>/*255:0*/ __Vdlyvval__l2_cache__DOT__cache__v9;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v10;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v10;
    IData/*18:0*/ __Vdlyvval__l2_cache__DOT__cache__v10;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v11;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v11;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v12;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v12;
    CData/*0:0*/ __Vdlyvval__l2_cache__DOT__cache__v12;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v12;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v13;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v13;
    VlWide<8>/*255:0*/ __Vdlyvval__l2_cache__DOT__cache__v13;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v14;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v14;
    IData/*18:0*/ __Vdlyvval__l2_cache__DOT__cache__v14;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v15;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v15;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v16;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v16;
    CData/*0:0*/ __Vdlyvval__l2_cache__DOT__cache__v16;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v16;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v17;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v17;
    VlWide<8>/*255:0*/ __Vdlyvval__l2_cache__DOT__cache__v17;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v18;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v18;
    IData/*18:0*/ __Vdlyvval__l2_cache__DOT__cache__v18;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v19;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v19;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v20;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v20;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v20;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v21;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v21;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v21;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v22;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v22;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v23;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v23;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v23;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v24;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v24;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v24;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v25;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v25;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v26;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v26;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v26;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v27;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v27;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v27;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v28;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v28;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v29;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v29;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v29;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v30;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v30;
    CData/*0:0*/ __Vdlyvset__l2_cache__DOT__cache__v30;
    CData/*7:0*/ __Vdlyvdim0__l2_cache__DOT__cache__v31;
    IData/*31:0*/ __Vdlyvlsb__l2_cache__DOT__cache__v31;
    // Body
    __Vdlyvset__l2_cache__DOT__cache__v0 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v1 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v2 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v3 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v4 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v8 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v12 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v16 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v20 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v21 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v23 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v24 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v26 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v27 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v29 = 0U;
    __Vdlyvset__l2_cache__DOT__cache__v30 = 0U;
    vlSelf->write_back_data[0U] = vlSelf->l2_cache__DOT__write_back_data_next[0U];
    vlSelf->write_back_data[1U] = vlSelf->l2_cache__DOT__write_back_data_next[1U];
    vlSelf->write_back_data[2U] = vlSelf->l2_cache__DOT__write_back_data_next[2U];
    vlSelf->write_back_data[3U] = vlSelf->l2_cache__DOT__write_back_data_next[3U];
    vlSelf->wb_ready_d = vlSelf->l2_cache__DOT__wb_ready_d_next;
    vlSelf->write_back_en = vlSelf->l2_cache__DOT__write_back_en_next;
    vlSelf->ready_d = 0U;
    vlSelf->ready_i = 0U;
    vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
        = vlSelf->l2_cache__DOT__l1write_back_addr_buffer_next;
    vlSelf->l2_cache__DOT__l1write_back_data_buffer[0U] 
        = vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[0U];
    vlSelf->l2_cache__DOT__l1write_back_data_buffer[1U] 
        = vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[1U];
    vlSelf->l2_cache__DOT__l1write_back_data_buffer[2U] 
        = vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[2U];
    vlSelf->l2_cache__DOT__l1write_back_data_buffer[3U] 
        = vlSelf->l2_cache__DOT__l1write_back_data_buffer_next[3U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer[0U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[0U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer[1U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[1U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer[2U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[2U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer[3U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[3U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer[4U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[4U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer[5U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[5U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer[6U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[6U];
    vlSelf->l2_cache__DOT__l2write_back_data_buffer[7U] 
        = vlSelf->l2_cache__DOT__l2write_back_data_buffer_next[7U];
    vlSelf->l2_cache__DOT__l2write_back_addr_buffer 
        = vlSelf->l2_cache__DOT__l2write_back_addr_buffer_next;
    vlSelf->l2_cache__DOT__l2write_buffer = vlSelf->l2_cache__DOT__l2write_buffer_next;
    vlSelf->l2_cache__DOT__l1write_buffer = vlSelf->l2_cache__DOT__l1write_buffer_next;
    vlSelf->data_out[0U] = 0U;
    vlSelf->data_out[1U] = 0U;
    vlSelf->data_out[2U] = 0U;
    vlSelf->data_out[3U] = 0U;
    if (vlSelf->l2_cache__DOT__rd_en) {
        if (vlSelf->l2_cache__DOT__req_d) {
            vlSelf->ready_d = 1U;
        }
        if ((1U & (~ (IData)(vlSelf->l2_cache__DOT__req_d)))) {
            if (vlSelf->l2_cache__DOT__req_i) {
                vlSelf->ready_i = 1U;
            }
        }
        if ((0U == (IData)(vlSelf->l2_cache__DOT__way))) {
            __Vdlyvset__l2_cache__DOT__cache__v20 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v20 = 0x459U;
            __Vdlyvdim0__l2_cache__DOT__cache__v20 
                = vlSelf->l2_cache__DOT__set;
            if ((0x10U & vlSelf->l2_cache__DOT__addr)) {
                if ((0x10U & vlSelf->l2_cache__DOT__addr)) {
                    vlSelf->data_out[0U] = vlSelf->l2_cache__DOT__cache
                        [vlSelf->l2_cache__DOT__set][4U];
                    vlSelf->data_out[1U] = vlSelf->l2_cache__DOT__cache
                        [vlSelf->l2_cache__DOT__set][5U];
                    vlSelf->data_out[2U] = vlSelf->l2_cache__DOT__cache
                        [vlSelf->l2_cache__DOT__set][6U];
                    vlSelf->data_out[3U] = vlSelf->l2_cache__DOT__cache
                        [vlSelf->l2_cache__DOT__set][7U];
                }
            } else {
                vlSelf->data_out[0U] = vlSelf->l2_cache__DOT__cache
                    [vlSelf->l2_cache__DOT__set][0U];
                vlSelf->data_out[1U] = vlSelf->l2_cache__DOT__cache
                    [vlSelf->l2_cache__DOT__set][1U];
                vlSelf->data_out[2U] = vlSelf->l2_cache__DOT__cache
                    [vlSelf->l2_cache__DOT__set][2U];
                vlSelf->data_out[3U] = vlSelf->l2_cache__DOT__cache
                    [vlSelf->l2_cache__DOT__set][3U];
            }
            __Vdlyvset__l2_cache__DOT__cache__v21 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v21 = 0x458U;
            __Vdlyvdim0__l2_cache__DOT__cache__v21 
                = vlSelf->l2_cache__DOT__set;
            __Vdlyvlsb__l2_cache__DOT__cache__v22 = 0x457U;
            __Vdlyvdim0__l2_cache__DOT__cache__v22 
                = vlSelf->l2_cache__DOT__set;
        } else if ((1U == (IData)(vlSelf->l2_cache__DOT__way))) {
            __Vdlyvset__l2_cache__DOT__cache__v23 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v23 = 0x459U;
            __Vdlyvdim0__l2_cache__DOT__cache__v23 
                = vlSelf->l2_cache__DOT__set;
            if ((4U & (IData)(vlSelf->l2_cache__DOT__block_offset))) {
                if ((4U & (IData)(vlSelf->l2_cache__DOT__block_offset))) {
                    vlSelf->data_out[0U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0xdU] 
                                             << 0xbU) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0xcU] 
                                               >> 0x15U));
                    vlSelf->data_out[1U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0xeU] 
                                             << 0xbU) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0xdU] 
                                               >> 0x15U));
                    vlSelf->data_out[2U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0xfU] 
                                             << 0xbU) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0xeU] 
                                               >> 0x15U));
                    vlSelf->data_out[3U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0x10U] 
                                             << 0xbU) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0xfU] 
                                               >> 0x15U));
                }
            } else {
                vlSelf->data_out[0U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][9U] 
                                         << 0xbU) | 
                                        (vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][8U] 
                                         >> 0x15U));
                vlSelf->data_out[1U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0xaU] 
                                         << 0xbU) | 
                                        (vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][9U] 
                                         >> 0x15U));
                vlSelf->data_out[2U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0xbU] 
                                         << 0xbU) | 
                                        (vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0xaU] 
                                         >> 0x15U));
                vlSelf->data_out[3U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0xcU] 
                                         << 0xbU) | 
                                        (vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0xbU] 
                                         >> 0x15U));
            }
            __Vdlyvset__l2_cache__DOT__cache__v24 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v24 = 0x456U;
            __Vdlyvdim0__l2_cache__DOT__cache__v24 
                = vlSelf->l2_cache__DOT__set;
            __Vdlyvlsb__l2_cache__DOT__cache__v25 = 0x455U;
            __Vdlyvdim0__l2_cache__DOT__cache__v25 
                = vlSelf->l2_cache__DOT__set;
        } else if ((2U == (IData)(vlSelf->l2_cache__DOT__way))) {
            __Vdlyvset__l2_cache__DOT__cache__v26 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v26 = 0x458U;
            __Vdlyvdim0__l2_cache__DOT__cache__v26 
                = vlSelf->l2_cache__DOT__set;
            if ((4U & (IData)(vlSelf->l2_cache__DOT__block_offset))) {
                if ((4U & (IData)(vlSelf->l2_cache__DOT__block_offset))) {
                    vlSelf->data_out[0U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0x16U] 
                                             << 0x16U) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0x15U] 
                                               >> 0xaU));
                    vlSelf->data_out[1U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0x17U] 
                                             << 0x16U) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0x16U] 
                                               >> 0xaU));
                    vlSelf->data_out[2U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0x18U] 
                                             << 0x16U) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0x17U] 
                                               >> 0xaU));
                    vlSelf->data_out[3U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0x19U] 
                                             << 0x16U) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0x18U] 
                                               >> 0xaU));
                }
            } else {
                vlSelf->data_out[0U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0x12U] 
                                         << 0x16U) 
                                        | (vlSelf->l2_cache__DOT__cache
                                           [vlSelf->l2_cache__DOT__set][0x11U] 
                                           >> 0xaU));
                vlSelf->data_out[1U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0x13U] 
                                         << 0x16U) 
                                        | (vlSelf->l2_cache__DOT__cache
                                           [vlSelf->l2_cache__DOT__set][0x12U] 
                                           >> 0xaU));
                vlSelf->data_out[2U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0x14U] 
                                         << 0x16U) 
                                        | (vlSelf->l2_cache__DOT__cache
                                           [vlSelf->l2_cache__DOT__set][0x13U] 
                                           >> 0xaU));
                vlSelf->data_out[3U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0x15U] 
                                         << 0x16U) 
                                        | (vlSelf->l2_cache__DOT__cache
                                           [vlSelf->l2_cache__DOT__set][0x14U] 
                                           >> 0xaU));
            }
            __Vdlyvset__l2_cache__DOT__cache__v27 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v27 = 0x456U;
            __Vdlyvdim0__l2_cache__DOT__cache__v27 
                = vlSelf->l2_cache__DOT__set;
            __Vdlyvlsb__l2_cache__DOT__cache__v28 = 0x454U;
            __Vdlyvdim0__l2_cache__DOT__cache__v28 
                = vlSelf->l2_cache__DOT__set;
        } else if ((3U == (IData)(vlSelf->l2_cache__DOT__way))) {
            __Vdlyvset__l2_cache__DOT__cache__v29 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v29 = 0x457U;
            __Vdlyvdim0__l2_cache__DOT__cache__v29 
                = vlSelf->l2_cache__DOT__set;
            if ((0x10U & vlSelf->l2_cache__DOT__addr)) {
                if ((0x10U & vlSelf->l2_cache__DOT__addr)) {
                    vlSelf->data_out[0U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0x1eU] 
                                             << 1U) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0x1dU] 
                                               >> 0x1fU));
                    vlSelf->data_out[1U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0x1fU] 
                                             << 1U) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0x1eU] 
                                               >> 0x1fU));
                    vlSelf->data_out[2U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0x20U] 
                                             << 1U) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0x1fU] 
                                               >> 0x1fU));
                    vlSelf->data_out[3U] = ((vlSelf->l2_cache__DOT__cache
                                             [vlSelf->l2_cache__DOT__set][0x21U] 
                                             << 1U) 
                                            | (vlSelf->l2_cache__DOT__cache
                                               [vlSelf->l2_cache__DOT__set][0x20U] 
                                               >> 0x1fU));
                }
            } else {
                vlSelf->data_out[0U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0x1aU] 
                                         << 1U) | (
                                                   vlSelf->l2_cache__DOT__cache
                                                   [vlSelf->l2_cache__DOT__set][0x19U] 
                                                   >> 0x1fU));
                vlSelf->data_out[1U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0x1bU] 
                                         << 1U) | (
                                                   vlSelf->l2_cache__DOT__cache
                                                   [vlSelf->l2_cache__DOT__set][0x1aU] 
                                                   >> 0x1fU));
                vlSelf->data_out[2U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0x1cU] 
                                         << 1U) | (
                                                   vlSelf->l2_cache__DOT__cache
                                                   [vlSelf->l2_cache__DOT__set][0x1bU] 
                                                   >> 0x1fU));
                vlSelf->data_out[3U] = ((vlSelf->l2_cache__DOT__cache
                                         [vlSelf->l2_cache__DOT__set][0x1dU] 
                                         << 1U) | (
                                                   vlSelf->l2_cache__DOT__cache
                                                   [vlSelf->l2_cache__DOT__set][0x1cU] 
                                                   >> 0x1fU));
            }
            __Vdlyvset__l2_cache__DOT__cache__v30 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v30 = 0x455U;
            __Vdlyvdim0__l2_cache__DOT__cache__v30 
                = vlSelf->l2_cache__DOT__set;
            __Vdlyvlsb__l2_cache__DOT__cache__v31 = 0x454U;
            __Vdlyvdim0__l2_cache__DOT__cache__v31 
                = vlSelf->l2_cache__DOT__set;
        }
    }
    if (vlSelf->l2_cache__DOT__clean) {
        if ((0U == (IData)(vlSelf->l2_cache__DOT__way_rd))) {
            __Vdlyvset__l2_cache__DOT__cache__v0 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v0 = 0x113U;
            __Vdlyvdim0__l2_cache__DOT__cache__v0 = 
                (0xffU & (vlSelf->l2_cache__DOT__addr 
                          >> 5U));
        } else if ((1U == (IData)(vlSelf->l2_cache__DOT__way_rd))) {
            __Vdlyvset__l2_cache__DOT__cache__v1 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v1 = 0x228U;
            __Vdlyvdim0__l2_cache__DOT__cache__v1 = 
                (0xffU & (vlSelf->l2_cache__DOT__addr 
                          >> 5U));
        }
        if ((2U == (IData)(vlSelf->l2_cache__DOT__way_rd))) {
            __Vdlyvset__l2_cache__DOT__cache__v2 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v2 = 0x33dU;
            __Vdlyvdim0__l2_cache__DOT__cache__v2 = 
                (0xffU & (vlSelf->l2_cache__DOT__addr 
                          >> 5U));
        } else if ((3U == (IData)(vlSelf->l2_cache__DOT__way_rd))) {
            __Vdlyvset__l2_cache__DOT__cache__v3 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v3 = 0x452U;
            __Vdlyvdim0__l2_cache__DOT__cache__v3 = 
                (0xffU & (vlSelf->l2_cache__DOT__addr 
                          >> 5U));
        }
    }
    if (vlSelf->l2_cache__DOT__wr_en) {
        if ((0U == (IData)(vlSelf->l2_cache__DOT__way))) {
            __Vdlyvval__l2_cache__DOT__cache__v4 = vlSelf->l2_cache__DOT__wr_wb;
            __Vdlyvset__l2_cache__DOT__cache__v4 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v4 = 0x113U;
            __Vdlyvdim0__l2_cache__DOT__cache__v4 = vlSelf->l2_cache__DOT__set;
            __Vdlyvval__l2_cache__DOT__cache__v5[0U] 
                = ((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0U] 
                    & (~ vlSelf->l2_cache__DOT__wmask[0U])) 
                   | (vlSelf->l2_cache__DOT__write_data[0U] 
                      & vlSelf->l2_cache__DOT__wmask[0U]));
            __Vdlyvval__l2_cache__DOT__cache__v5[1U] 
                = ((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][1U] 
                    & (~ vlSelf->l2_cache__DOT__wmask[1U])) 
                   | (vlSelf->l2_cache__DOT__write_data[1U] 
                      & vlSelf->l2_cache__DOT__wmask[1U]));
            __Vdlyvval__l2_cache__DOT__cache__v5[2U] 
                = ((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][2U] 
                    & (~ vlSelf->l2_cache__DOT__wmask[2U])) 
                   | (vlSelf->l2_cache__DOT__write_data[2U] 
                      & vlSelf->l2_cache__DOT__wmask[2U]));
            __Vdlyvval__l2_cache__DOT__cache__v5[3U] 
                = ((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][3U] 
                    & (~ vlSelf->l2_cache__DOT__wmask[3U])) 
                   | (vlSelf->l2_cache__DOT__write_data[3U] 
                      & vlSelf->l2_cache__DOT__wmask[3U]));
            __Vdlyvval__l2_cache__DOT__cache__v5[4U] 
                = ((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][4U] 
                    & (~ vlSelf->l2_cache__DOT__wmask[4U])) 
                   | (vlSelf->l2_cache__DOT__write_data[4U] 
                      & vlSelf->l2_cache__DOT__wmask[4U]));
            __Vdlyvval__l2_cache__DOT__cache__v5[5U] 
                = ((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][5U] 
                    & (~ vlSelf->l2_cache__DOT__wmask[5U])) 
                   | (vlSelf->l2_cache__DOT__write_data[5U] 
                      & vlSelf->l2_cache__DOT__wmask[5U]));
            __Vdlyvval__l2_cache__DOT__cache__v5[6U] 
                = ((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][6U] 
                    & (~ vlSelf->l2_cache__DOT__wmask[6U])) 
                   | (vlSelf->l2_cache__DOT__write_data[6U] 
                      & vlSelf->l2_cache__DOT__wmask[6U]));
            __Vdlyvval__l2_cache__DOT__cache__v5[7U] 
                = ((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][7U] 
                    & (~ vlSelf->l2_cache__DOT__wmask[7U])) 
                   | (vlSelf->l2_cache__DOT__write_data[7U] 
                      & vlSelf->l2_cache__DOT__wmask[7U]));
            __Vdlyvlsb__l2_cache__DOT__cache__v5 = 0U;
            __Vdlyvdim0__l2_cache__DOT__cache__v5 = vlSelf->l2_cache__DOT__set;
            __Vdlyvval__l2_cache__DOT__cache__v6 = vlSelf->l2_cache__DOT__tag_bits;
            __Vdlyvlsb__l2_cache__DOT__cache__v6 = 0x100U;
            __Vdlyvdim0__l2_cache__DOT__cache__v6 = vlSelf->l2_cache__DOT__set;
            __Vdlyvlsb__l2_cache__DOT__cache__v7 = 0x114U;
            __Vdlyvdim0__l2_cache__DOT__cache__v7 = vlSelf->l2_cache__DOT__set;
        } else if ((1U == (IData)(vlSelf->l2_cache__DOT__way))) {
            __Vdlyvval__l2_cache__DOT__cache__v8 = vlSelf->l2_cache__DOT__wr_wb;
            __Vdlyvset__l2_cache__DOT__cache__v8 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v8 = 0x228U;
            __Vdlyvdim0__l2_cache__DOT__cache__v8 = vlSelf->l2_cache__DOT__set;
            __Vdlyvval__l2_cache__DOT__cache__v9[0U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][9U] 
                      << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                  [vlSelf->l2_cache__DOT__set][8U] 
                                  >> 0x15U)) & (~ vlSelf->l2_cache__DOT__wmask[0U])) 
                   | (vlSelf->l2_cache__DOT__write_data[0U] 
                      & vlSelf->l2_cache__DOT__wmask[0U]));
            __Vdlyvval__l2_cache__DOT__cache__v9[1U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0xaU] 
                      << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                  [vlSelf->l2_cache__DOT__set][9U] 
                                  >> 0x15U)) & (~ vlSelf->l2_cache__DOT__wmask[1U])) 
                   | (vlSelf->l2_cache__DOT__write_data[1U] 
                      & vlSelf->l2_cache__DOT__wmask[1U]));
            __Vdlyvval__l2_cache__DOT__cache__v9[2U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0xbU] 
                      << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                  [vlSelf->l2_cache__DOT__set][0xaU] 
                                  >> 0x15U)) & (~ vlSelf->l2_cache__DOT__wmask[2U])) 
                   | (vlSelf->l2_cache__DOT__write_data[2U] 
                      & vlSelf->l2_cache__DOT__wmask[2U]));
            __Vdlyvval__l2_cache__DOT__cache__v9[3U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0xcU] 
                      << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                  [vlSelf->l2_cache__DOT__set][0xbU] 
                                  >> 0x15U)) & (~ vlSelf->l2_cache__DOT__wmask[3U])) 
                   | (vlSelf->l2_cache__DOT__write_data[3U] 
                      & vlSelf->l2_cache__DOT__wmask[3U]));
            __Vdlyvval__l2_cache__DOT__cache__v9[4U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0xdU] 
                      << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                  [vlSelf->l2_cache__DOT__set][0xcU] 
                                  >> 0x15U)) & (~ vlSelf->l2_cache__DOT__wmask[4U])) 
                   | (vlSelf->l2_cache__DOT__write_data[4U] 
                      & vlSelf->l2_cache__DOT__wmask[4U]));
            __Vdlyvval__l2_cache__DOT__cache__v9[5U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0xeU] 
                      << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                  [vlSelf->l2_cache__DOT__set][0xdU] 
                                  >> 0x15U)) & (~ vlSelf->l2_cache__DOT__wmask[5U])) 
                   | (vlSelf->l2_cache__DOT__write_data[5U] 
                      & vlSelf->l2_cache__DOT__wmask[5U]));
            __Vdlyvval__l2_cache__DOT__cache__v9[6U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0xfU] 
                      << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                  [vlSelf->l2_cache__DOT__set][0xeU] 
                                  >> 0x15U)) & (~ vlSelf->l2_cache__DOT__wmask[6U])) 
                   | (vlSelf->l2_cache__DOT__write_data[6U] 
                      & vlSelf->l2_cache__DOT__wmask[6U]));
            __Vdlyvval__l2_cache__DOT__cache__v9[7U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x10U] 
                      << 0xbU) | (vlSelf->l2_cache__DOT__cache
                                  [vlSelf->l2_cache__DOT__set][0xfU] 
                                  >> 0x15U)) & (~ vlSelf->l2_cache__DOT__wmask[7U])) 
                   | (vlSelf->l2_cache__DOT__write_data[7U] 
                      & vlSelf->l2_cache__DOT__wmask[7U]));
            __Vdlyvlsb__l2_cache__DOT__cache__v9 = 0x115U;
            __Vdlyvdim0__l2_cache__DOT__cache__v9 = vlSelf->l2_cache__DOT__set;
            __Vdlyvval__l2_cache__DOT__cache__v10 = vlSelf->l2_cache__DOT__tag_bits;
            __Vdlyvlsb__l2_cache__DOT__cache__v10 = 0x215U;
            __Vdlyvdim0__l2_cache__DOT__cache__v10 
                = vlSelf->l2_cache__DOT__set;
            __Vdlyvlsb__l2_cache__DOT__cache__v11 = 0x229U;
            __Vdlyvdim0__l2_cache__DOT__cache__v11 
                = vlSelf->l2_cache__DOT__set;
        } else if ((2U == (IData)(vlSelf->l2_cache__DOT__way))) {
            __Vdlyvval__l2_cache__DOT__cache__v12 = vlSelf->l2_cache__DOT__wr_wb;
            __Vdlyvset__l2_cache__DOT__cache__v12 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v12 = 0x33dU;
            __Vdlyvdim0__l2_cache__DOT__cache__v12 
                = vlSelf->l2_cache__DOT__set;
            __Vdlyvval__l2_cache__DOT__cache__v13[0U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x12U] 
                      << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                   [vlSelf->l2_cache__DOT__set][0x11U] 
                                   >> 0xaU)) & (~ vlSelf->l2_cache__DOT__wmask[0U])) 
                   | (vlSelf->l2_cache__DOT__write_data[0U] 
                      & vlSelf->l2_cache__DOT__wmask[0U]));
            __Vdlyvval__l2_cache__DOT__cache__v13[1U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x13U] 
                      << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                   [vlSelf->l2_cache__DOT__set][0x12U] 
                                   >> 0xaU)) & (~ vlSelf->l2_cache__DOT__wmask[1U])) 
                   | (vlSelf->l2_cache__DOT__write_data[1U] 
                      & vlSelf->l2_cache__DOT__wmask[1U]));
            __Vdlyvval__l2_cache__DOT__cache__v13[2U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x14U] 
                      << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                   [vlSelf->l2_cache__DOT__set][0x13U] 
                                   >> 0xaU)) & (~ vlSelf->l2_cache__DOT__wmask[2U])) 
                   | (vlSelf->l2_cache__DOT__write_data[2U] 
                      & vlSelf->l2_cache__DOT__wmask[2U]));
            __Vdlyvval__l2_cache__DOT__cache__v13[3U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x15U] 
                      << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                   [vlSelf->l2_cache__DOT__set][0x14U] 
                                   >> 0xaU)) & (~ vlSelf->l2_cache__DOT__wmask[3U])) 
                   | (vlSelf->l2_cache__DOT__write_data[3U] 
                      & vlSelf->l2_cache__DOT__wmask[3U]));
            __Vdlyvval__l2_cache__DOT__cache__v13[4U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x16U] 
                      << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                   [vlSelf->l2_cache__DOT__set][0x15U] 
                                   >> 0xaU)) & (~ vlSelf->l2_cache__DOT__wmask[4U])) 
                   | (vlSelf->l2_cache__DOT__write_data[4U] 
                      & vlSelf->l2_cache__DOT__wmask[4U]));
            __Vdlyvval__l2_cache__DOT__cache__v13[5U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x17U] 
                      << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                   [vlSelf->l2_cache__DOT__set][0x16U] 
                                   >> 0xaU)) & (~ vlSelf->l2_cache__DOT__wmask[5U])) 
                   | (vlSelf->l2_cache__DOT__write_data[5U] 
                      & vlSelf->l2_cache__DOT__wmask[5U]));
            __Vdlyvval__l2_cache__DOT__cache__v13[6U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x18U] 
                      << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                   [vlSelf->l2_cache__DOT__set][0x17U] 
                                   >> 0xaU)) & (~ vlSelf->l2_cache__DOT__wmask[6U])) 
                   | (vlSelf->l2_cache__DOT__write_data[6U] 
                      & vlSelf->l2_cache__DOT__wmask[6U]));
            __Vdlyvval__l2_cache__DOT__cache__v13[7U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x19U] 
                      << 0x16U) | (vlSelf->l2_cache__DOT__cache
                                   [vlSelf->l2_cache__DOT__set][0x18U] 
                                   >> 0xaU)) & (~ vlSelf->l2_cache__DOT__wmask[7U])) 
                   | (vlSelf->l2_cache__DOT__write_data[7U] 
                      & vlSelf->l2_cache__DOT__wmask[7U]));
            __Vdlyvlsb__l2_cache__DOT__cache__v13 = 0x22aU;
            __Vdlyvdim0__l2_cache__DOT__cache__v13 
                = vlSelf->l2_cache__DOT__set;
            __Vdlyvval__l2_cache__DOT__cache__v14 = vlSelf->l2_cache__DOT__tag_bits;
            __Vdlyvlsb__l2_cache__DOT__cache__v14 = 0x32aU;
            __Vdlyvdim0__l2_cache__DOT__cache__v14 
                = vlSelf->l2_cache__DOT__set;
            __Vdlyvlsb__l2_cache__DOT__cache__v15 = 0x33eU;
            __Vdlyvdim0__l2_cache__DOT__cache__v15 
                = vlSelf->l2_cache__DOT__set;
        } else if ((3U == (IData)(vlSelf->l2_cache__DOT__way))) {
            __Vdlyvval__l2_cache__DOT__cache__v16 = vlSelf->l2_cache__DOT__wr_wb;
            __Vdlyvset__l2_cache__DOT__cache__v16 = 1U;
            __Vdlyvlsb__l2_cache__DOT__cache__v16 = 0x452U;
            __Vdlyvdim0__l2_cache__DOT__cache__v16 
                = vlSelf->l2_cache__DOT__set;
            __Vdlyvval__l2_cache__DOT__cache__v17[0U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x1aU] 
                      << 1U) | (vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set][0x19U] 
                                >> 0x1fU)) & (~ vlSelf->l2_cache__DOT__wmask[0U])) 
                   | (vlSelf->l2_cache__DOT__write_data[0U] 
                      & vlSelf->l2_cache__DOT__wmask[0U]));
            __Vdlyvval__l2_cache__DOT__cache__v17[1U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x1bU] 
                      << 1U) | (vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set][0x1aU] 
                                >> 0x1fU)) & (~ vlSelf->l2_cache__DOT__wmask[1U])) 
                   | (vlSelf->l2_cache__DOT__write_data[1U] 
                      & vlSelf->l2_cache__DOT__wmask[1U]));
            __Vdlyvval__l2_cache__DOT__cache__v17[2U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x1cU] 
                      << 1U) | (vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set][0x1bU] 
                                >> 0x1fU)) & (~ vlSelf->l2_cache__DOT__wmask[2U])) 
                   | (vlSelf->l2_cache__DOT__write_data[2U] 
                      & vlSelf->l2_cache__DOT__wmask[2U]));
            __Vdlyvval__l2_cache__DOT__cache__v17[3U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x1dU] 
                      << 1U) | (vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set][0x1cU] 
                                >> 0x1fU)) & (~ vlSelf->l2_cache__DOT__wmask[3U])) 
                   | (vlSelf->l2_cache__DOT__write_data[3U] 
                      & vlSelf->l2_cache__DOT__wmask[3U]));
            __Vdlyvval__l2_cache__DOT__cache__v17[4U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x1eU] 
                      << 1U) | (vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set][0x1dU] 
                                >> 0x1fU)) & (~ vlSelf->l2_cache__DOT__wmask[4U])) 
                   | (vlSelf->l2_cache__DOT__write_data[4U] 
                      & vlSelf->l2_cache__DOT__wmask[4U]));
            __Vdlyvval__l2_cache__DOT__cache__v17[5U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x1fU] 
                      << 1U) | (vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set][0x1eU] 
                                >> 0x1fU)) & (~ vlSelf->l2_cache__DOT__wmask[5U])) 
                   | (vlSelf->l2_cache__DOT__write_data[5U] 
                      & vlSelf->l2_cache__DOT__wmask[5U]));
            __Vdlyvval__l2_cache__DOT__cache__v17[6U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x20U] 
                      << 1U) | (vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set][0x1fU] 
                                >> 0x1fU)) & (~ vlSelf->l2_cache__DOT__wmask[6U])) 
                   | (vlSelf->l2_cache__DOT__write_data[6U] 
                      & vlSelf->l2_cache__DOT__wmask[6U]));
            __Vdlyvval__l2_cache__DOT__cache__v17[7U] 
                = ((((vlSelf->l2_cache__DOT__cache[vlSelf->l2_cache__DOT__set][0x21U] 
                      << 1U) | (vlSelf->l2_cache__DOT__cache
                                [vlSelf->l2_cache__DOT__set][0x20U] 
                                >> 0x1fU)) & (~ vlSelf->l2_cache__DOT__wmask[7U])) 
                   | (vlSelf->l2_cache__DOT__write_data[7U] 
                      & vlSelf->l2_cache__DOT__wmask[7U]));
            __Vdlyvlsb__l2_cache__DOT__cache__v17 = 0x33fU;
            __Vdlyvdim0__l2_cache__DOT__cache__v17 
                = vlSelf->l2_cache__DOT__set;
            __Vdlyvval__l2_cache__DOT__cache__v18 = vlSelf->l2_cache__DOT__tag_bits;
            __Vdlyvlsb__l2_cache__DOT__cache__v18 = 0x43fU;
            __Vdlyvdim0__l2_cache__DOT__cache__v18 
                = vlSelf->l2_cache__DOT__set;
            __Vdlyvlsb__l2_cache__DOT__cache__v19 = 0x453U;
            __Vdlyvdim0__l2_cache__DOT__cache__v19 
                = vlSelf->l2_cache__DOT__set;
        }
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v0) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v0][(__Vdlyvlsb__l2_cache__DOT__cache__v0 
                                                                             >> 5U)] 
            = ((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v0))) 
               & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v0][
               (__Vdlyvlsb__l2_cache__DOT__cache__v0 
                >> 5U)]);
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v1) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v1][(__Vdlyvlsb__l2_cache__DOT__cache__v1 
                                                                             >> 5U)] 
            = ((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v1))) 
               & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v1][
               (__Vdlyvlsb__l2_cache__DOT__cache__v1 
                >> 5U)]);
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v2) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v2][(__Vdlyvlsb__l2_cache__DOT__cache__v2 
                                                                             >> 5U)] 
            = ((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v2))) 
               & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v2][
               (__Vdlyvlsb__l2_cache__DOT__cache__v2 
                >> 5U)]);
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v3) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v3][(__Vdlyvlsb__l2_cache__DOT__cache__v3 
                                                                             >> 5U)] 
            = ((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v3))) 
               & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v3][
               (__Vdlyvlsb__l2_cache__DOT__cache__v3 
                >> 5U)]);
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v4) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v4][(__Vdlyvlsb__l2_cache__DOT__cache__v4 
                                                                             >> 5U)] 
            = (((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v4))) 
                & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v4][
                (__Vdlyvlsb__l2_cache__DOT__cache__v4 
                 >> 5U)]) | ((IData)(__Vdlyvval__l2_cache__DOT__cache__v4) 
                             << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v4)));
        VL_ASSIGNSEL_WW(1114,256,__Vdlyvlsb__l2_cache__DOT__cache__v5, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v5], __Vdlyvval__l2_cache__DOT__cache__v5);
        VL_ASSIGNSEL_WI(1114,19,__Vdlyvlsb__l2_cache__DOT__cache__v6, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v6], __Vdlyvval__l2_cache__DOT__cache__v6);
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v7][(__Vdlyvlsb__l2_cache__DOT__cache__v7 
                                                                             >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v7][
               (__Vdlyvlsb__l2_cache__DOT__cache__v7 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v7)));
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v8) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v8][(__Vdlyvlsb__l2_cache__DOT__cache__v8 
                                                                             >> 5U)] 
            = (((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v8))) 
                & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v8][
                (__Vdlyvlsb__l2_cache__DOT__cache__v8 
                 >> 5U)]) | ((IData)(__Vdlyvval__l2_cache__DOT__cache__v8) 
                             << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v8)));
        VL_ASSIGNSEL_WW(1114,256,__Vdlyvlsb__l2_cache__DOT__cache__v9, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v9], __Vdlyvval__l2_cache__DOT__cache__v9);
        VL_ASSIGNSEL_WI(1114,19,__Vdlyvlsb__l2_cache__DOT__cache__v10, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v10], __Vdlyvval__l2_cache__DOT__cache__v10);
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v11][(__Vdlyvlsb__l2_cache__DOT__cache__v11 
                                                                              >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v11][
               (__Vdlyvlsb__l2_cache__DOT__cache__v11 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v11)));
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v12) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v12][(__Vdlyvlsb__l2_cache__DOT__cache__v12 
                                                                              >> 5U)] 
            = (((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v12))) 
                & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v12][
                (__Vdlyvlsb__l2_cache__DOT__cache__v12 
                 >> 5U)]) | ((IData)(__Vdlyvval__l2_cache__DOT__cache__v12) 
                             << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v12)));
        VL_ASSIGNSEL_WW(1114,256,__Vdlyvlsb__l2_cache__DOT__cache__v13, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v13], __Vdlyvval__l2_cache__DOT__cache__v13);
        VL_ASSIGNSEL_WI(1114,19,__Vdlyvlsb__l2_cache__DOT__cache__v14, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v14], __Vdlyvval__l2_cache__DOT__cache__v14);
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v15][(__Vdlyvlsb__l2_cache__DOT__cache__v15 
                                                                              >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v15][
               (__Vdlyvlsb__l2_cache__DOT__cache__v15 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v15)));
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v16) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v16][(__Vdlyvlsb__l2_cache__DOT__cache__v16 
                                                                              >> 5U)] 
            = (((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v16))) 
                & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v16][
                (__Vdlyvlsb__l2_cache__DOT__cache__v16 
                 >> 5U)]) | ((IData)(__Vdlyvval__l2_cache__DOT__cache__v16) 
                             << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v16)));
        VL_ASSIGNSEL_WW(1114,256,__Vdlyvlsb__l2_cache__DOT__cache__v17, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v17], __Vdlyvval__l2_cache__DOT__cache__v17);
        VL_ASSIGNSEL_WI(1114,19,__Vdlyvlsb__l2_cache__DOT__cache__v18, 
                        vlSelf->l2_cache__DOT__cache
                        [__Vdlyvdim0__l2_cache__DOT__cache__v18], __Vdlyvval__l2_cache__DOT__cache__v18);
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v19][(__Vdlyvlsb__l2_cache__DOT__cache__v19 
                                                                              >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v19][
               (__Vdlyvlsb__l2_cache__DOT__cache__v19 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v19)));
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v20) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v20][(__Vdlyvlsb__l2_cache__DOT__cache__v20 
                                                                              >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v20][
               (__Vdlyvlsb__l2_cache__DOT__cache__v20 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v20)));
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v21) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v21][(__Vdlyvlsb__l2_cache__DOT__cache__v21 
                                                                              >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v21][
               (__Vdlyvlsb__l2_cache__DOT__cache__v21 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v21)));
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v22][(__Vdlyvlsb__l2_cache__DOT__cache__v22 
                                                                              >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v22][
               (__Vdlyvlsb__l2_cache__DOT__cache__v22 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v22)));
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v23) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v23][(__Vdlyvlsb__l2_cache__DOT__cache__v23 
                                                                              >> 5U)] 
            = ((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v23))) 
               & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v23][
               (__Vdlyvlsb__l2_cache__DOT__cache__v23 
                >> 5U)]);
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v24) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v24][(__Vdlyvlsb__l2_cache__DOT__cache__v24 
                                                                              >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v24][
               (__Vdlyvlsb__l2_cache__DOT__cache__v24 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v24)));
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v25][(__Vdlyvlsb__l2_cache__DOT__cache__v25 
                                                                              >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v25][
               (__Vdlyvlsb__l2_cache__DOT__cache__v25 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v25)));
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v26) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v26][(__Vdlyvlsb__l2_cache__DOT__cache__v26 
                                                                              >> 5U)] 
            = ((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v26))) 
               & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v26][
               (__Vdlyvlsb__l2_cache__DOT__cache__v26 
                >> 5U)]);
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v27) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v27][(__Vdlyvlsb__l2_cache__DOT__cache__v27 
                                                                              >> 5U)] 
            = ((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v27))) 
               & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v27][
               (__Vdlyvlsb__l2_cache__DOT__cache__v27 
                >> 5U)]);
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v28][(__Vdlyvlsb__l2_cache__DOT__cache__v28 
                                                                              >> 5U)] 
            = (vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v28][
               (__Vdlyvlsb__l2_cache__DOT__cache__v28 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v28)));
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v29) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v29][(__Vdlyvlsb__l2_cache__DOT__cache__v29 
                                                                              >> 5U)] 
            = ((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v29))) 
               & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v29][
               (__Vdlyvlsb__l2_cache__DOT__cache__v29 
                >> 5U)]);
    }
    if (__Vdlyvset__l2_cache__DOT__cache__v30) {
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v30][(__Vdlyvlsb__l2_cache__DOT__cache__v30 
                                                                              >> 5U)] 
            = ((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v30))) 
               & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v30][
               (__Vdlyvlsb__l2_cache__DOT__cache__v30 
                >> 5U)]);
        vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v31][(__Vdlyvlsb__l2_cache__DOT__cache__v31 
                                                                              >> 5U)] 
            = ((~ ((IData)(1U) << (0x1fU & __Vdlyvlsb__l2_cache__DOT__cache__v31))) 
               & vlSelf->l2_cache__DOT__cache[__Vdlyvdim0__l2_cache__DOT__cache__v31][
               (__Vdlyvlsb__l2_cache__DOT__cache__v31 
                >> 5U)]);
    }
}

VL_INLINE_OPT void Vdut___024root___combo__TOP__1(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__1\n"); );
    // Body
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

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    Vdut___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vdut___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    Vdut___024root___combo__TOP__1(vlSelf);
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
    __req |= ((vlSelf->l2_cache__DOT__addr ^ vlSelf->__Vchglast__TOP__l2_cache__DOT__addr));
    VL_DEBUG_IF( if(__req && ((vlSelf->l2_cache__DOT__addr ^ vlSelf->__Vchglast__TOP__l2_cache__DOT__addr))) VL_DBG_MSGF("        CHANGE: /home/leoyin/Documents/iac/Team5/repo/rtl/l2_cache.sv:79: l2_cache.addr\n"); );
    // Final
    vlSelf->__Vchglast__TOP__l2_cache__DOT__addr = vlSelf->l2_cache__DOT__addr;
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
    if (VL_UNLIKELY((vlSelf->fetch_i & 0xfeU))) {
        Verilated::overWidthError("fetch_i");}
    if (VL_UNLIKELY((vlSelf->fetch_d & 0xfeU))) {
        Verilated::overWidthError("fetch_d");}
    if (VL_UNLIKELY((vlSelf->l1write_back_en & 0xfeU))) {
        Verilated::overWidthError("l1write_back_en");}
    if (VL_UNLIKELY((vlSelf->ready & 0xfeU))) {
        Verilated::overWidthError("ready");}
    if (VL_UNLIKELY((vlSelf->wb_ready & 0xfeU))) {
        Verilated::overWidthError("wb_ready");}
}
#endif  // VL_DEBUG
