// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->l2_cache__DOT__i),32);
        bufp->chgIData(oldp+1,(vlSelf->l2_cache__DOT__j),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+2,(vlSelf->l2_cache__DOT__miss_pending));
        bufp->chgBit(oldp+3,(vlSelf->l2_cache__DOT__miss_is_i));
        bufp->chgIData(oldp+4,(vlSelf->l2_cache__DOT__miss_addr),32);
        bufp->chgIData(oldp+5,(vlSelf->l2_cache__DOT__miss_tag),19);
        bufp->chgCData(oldp+6,(vlSelf->l2_cache__DOT__miss_set),8);
        bufp->chgCData(oldp+7,(vlSelf->l2_cache__DOT__miss_way),2);
        bufp->chgBit(oldp+8,(vlSelf->l2_cache__DOT__l1_wb_pending));
        bufp->chgIData(oldp+9,(vlSelf->l2_cache__DOT__l1_wb_addr),32);
        bufp->chgWData(oldp+10,(vlSelf->l2_cache__DOT__l1_wb_data),128);
        bufp->chgIData(oldp+14,((vlSelf->l2_cache__DOT__l1_wb_addr 
                                 >> 0xdU)),19);
        bufp->chgCData(oldp+15,((0xffU & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                          >> 5U))),8);
        bufp->chgCData(oldp+16,((7U & (vlSelf->l2_cache__DOT__l1_wb_addr 
                                       >> 2U))),3);
        bufp->chgCData(oldp+17,(vlSelf->l2_cache__DOT__l1_wb_hit_vec),4);
        bufp->chgBit(oldp+18,(vlSelf->l2_cache__DOT__l1_wb_hit));
        bufp->chgCData(oldp+19,(vlSelf->l2_cache__DOT__l1_wb_hit_way),2);
        bufp->chgBit(oldp+20,(vlSelf->l2_cache__DOT__evict_wb_pending));
        bufp->chgIData(oldp+21,(vlSelf->l2_cache__DOT__evict_wb_addr),32);
        bufp->chgWData(oldp+22,(vlSelf->l2_cache__DOT__evict_wb_data),128);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+26,(vlSelf->l2_cache__DOT__req_valid));
        bufp->chgBit(oldp+27,(vlSelf->l2_cache__DOT__req_is_i));
        bufp->chgIData(oldp+28,(vlSelf->l2_cache__DOT__req_addr),32);
        bufp->chgIData(oldp+29,((vlSelf->l2_cache__DOT__req_addr 
                                 >> 0xdU)),19);
        bufp->chgCData(oldp+30,((0xffU & (vlSelf->l2_cache__DOT__req_addr 
                                          >> 5U))),8);
        bufp->chgCData(oldp+31,((7U & (vlSelf->l2_cache__DOT__req_addr 
                                       >> 2U))),3);
        bufp->chgCData(oldp+32,(vlSelf->l2_cache__DOT__hit_vec),4);
        bufp->chgBit(oldp+33,(vlSelf->l2_cache__DOT__req_hit));
        bufp->chgCData(oldp+34,(vlSelf->l2_cache__DOT__hit_way),2);
        bufp->chgWData(oldp+35,(vlSelf->l2_cache__DOT__hit_line),256);
    }
    bufp->chgBit(oldp+43,(vlSelf->clk));
    bufp->chgBit(oldp+44,(vlSelf->fetch_i));
    bufp->chgBit(oldp+45,(vlSelf->fetch_d));
    bufp->chgIData(oldp+46,(vlSelf->addr_i),32);
    bufp->chgIData(oldp+47,(vlSelf->addr_d),32);
    bufp->chgWData(oldp+48,(vlSelf->line_from_mem),256);
    bufp->chgBit(oldp+56,(vlSelf->ready));
    bufp->chgWData(oldp+57,(vlSelf->l1write_back_data),128);
    bufp->chgBit(oldp+61,(vlSelf->l1write_back_en));
    bufp->chgIData(oldp+62,(vlSelf->l1write_back_addr),32);
    bufp->chgBit(oldp+63,(vlSelf->wb_ready));
    bufp->chgBit(oldp+64,(vlSelf->ready_i));
    bufp->chgBit(oldp+65,(vlSelf->ready_d));
    bufp->chgBit(oldp+66,(vlSelf->wb_ready_d));
    bufp->chgWData(oldp+67,(vlSelf->data_out),128);
    bufp->chgWData(oldp+71,(vlSelf->write_back_data),128);
    bufp->chgIData(oldp+75,(vlSelf->write_back_addr),32);
    bufp->chgBit(oldp+76,(vlSelf->write_back_en));
    bufp->chgIData(oldp+77,(vlSelf->main_mem_addr),32);
    bufp->chgBit(oldp+78,(vlSelf->main_mem_fetch));
}

void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_cleanup\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
