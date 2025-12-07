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
        bufp->chgIData(oldp+0,(vlSelf->l2_cache__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+1,(vlSelf->l2_cache__DOT__wr_en));
        bufp->chgBit(oldp+2,(vlSelf->l2_cache__DOT__rd_en));
        bufp->chgBit(oldp+3,(vlSelf->l2_cache__DOT__wr_wb));
        bufp->chgWData(oldp+4,(vlSelf->l2_cache__DOT__write_data),256);
        bufp->chgBit(oldp+12,(vlSelf->l2_cache__DOT__clean));
        bufp->chgCData(oldp+13,(vlSelf->l2_cache__DOT__way_rd),2);
        bufp->chgIData(oldp+14,((vlSelf->l2_cache__DOT__addr 
                                 >> 0xdU)),19);
        bufp->chgCData(oldp+15,((0xffU & (vlSelf->l2_cache__DOT__addr 
                                          >> 5U))),8);
        bufp->chgCData(oldp+16,((7U & (vlSelf->l2_cache__DOT__addr 
                                       >> 2U))),3);
        bufp->chgWData(oldp+17,(vlSelf->l2_cache__DOT__wmask),256);
        bufp->chgBit(oldp+25,(vlSelf->l2_cache__DOT__fetch));
        bufp->chgBit(oldp+26,(vlSelf->l2_cache__DOT__req_d));
        bufp->chgBit(oldp+27,(vlSelf->l2_cache__DOT__req_i));
        bufp->chgIData(oldp+28,(vlSelf->l2_cache__DOT__addr),32);
        bufp->chgBit(oldp+29,(vlSelf->l2_cache__DOT__l1write));
        bufp->chgBit(oldp+30,(vlSelf->l2_cache__DOT__hit0));
        bufp->chgBit(oldp+31,(vlSelf->l2_cache__DOT__hit1));
        bufp->chgBit(oldp+32,(vlSelf->l2_cache__DOT__hit2));
        bufp->chgBit(oldp+33,(vlSelf->l2_cache__DOT__hit3));
        bufp->chgBit(oldp+34,(vlSelf->l2_cache__DOT__valid0));
        bufp->chgBit(oldp+35,(vlSelf->l2_cache__DOT__valid1));
        bufp->chgBit(oldp+36,(vlSelf->l2_cache__DOT__valid2));
        bufp->chgBit(oldp+37,(vlSelf->l2_cache__DOT__valid3));
        bufp->chgBit(oldp+38,(vlSelf->l2_cache__DOT__miss));
        bufp->chgBit(oldp+39,(vlSelf->l2_cache__DOT__evict));
        bufp->chgBit(oldp+40,(vlSelf->l2_cache__DOT__wb_ready_d_next));
        bufp->chgBit(oldp+41,(vlSelf->l2_cache__DOT__write_back_en_next));
        bufp->chgWData(oldp+42,(vlSelf->l2_cache__DOT__l1write_back_data_buffer_next),128);
        bufp->chgBit(oldp+46,(vlSelf->l2_cache__DOT__l1write_buffer_next));
        bufp->chgIData(oldp+47,(vlSelf->l2_cache__DOT__l1write_back_addr_buffer_next),32);
        bufp->chgBit(oldp+48,(vlSelf->l2_cache__DOT__hit0_wb));
        bufp->chgBit(oldp+49,(vlSelf->l2_cache__DOT__hit1_wb));
        bufp->chgBit(oldp+50,(vlSelf->l2_cache__DOT__hit2_wb));
        bufp->chgBit(oldp+51,(vlSelf->l2_cache__DOT__hit3_wb));
        bufp->chgBit(oldp+52,(vlSelf->l2_cache__DOT__miss_wb));
        bufp->chgCData(oldp+53,(vlSelf->l2_cache__DOT__way),2);
        bufp->chgIData(oldp+54,(vlSelf->l2_cache__DOT__tag_bits),19);
        bufp->chgCData(oldp+55,(vlSelf->l2_cache__DOT__set),8);
        bufp->chgCData(oldp+56,(vlSelf->l2_cache__DOT__block_offset),3);
        bufp->chgWData(oldp+57,(vlSelf->l2_cache__DOT__l2write_back_data_buffer_next),256);
        bufp->chgCData(oldp+65,(vlSelf->l2_cache__DOT__l2write_buffer_next),2);
        bufp->chgIData(oldp+66,(vlSelf->l2_cache__DOT__l2write_back_addr_buffer_next),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgWData(oldp+67,(vlSelf->l2_cache__DOT__l1write_back_data_buffer),128);
        bufp->chgBit(oldp+71,(vlSelf->l2_cache__DOT__l1write_buffer));
        bufp->chgIData(oldp+72,(vlSelf->l2_cache__DOT__l1write_back_addr_buffer),32);
        bufp->chgIData(oldp+73,((vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                 >> 0xdU)),19);
        bufp->chgCData(oldp+74,((0xffU & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                          >> 5U))),8);
        bufp->chgCData(oldp+75,((7U & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                       >> 2U))),3);
        bufp->chgWData(oldp+76,(vlSelf->l2_cache__DOT__l2write_back_data_buffer),256);
        bufp->chgCData(oldp+84,(vlSelf->l2_cache__DOT__l2write_buffer),2);
        bufp->chgIData(oldp+85,(vlSelf->l2_cache__DOT__l2write_back_addr_buffer),32);
    }
    bufp->chgBit(oldp+86,(vlSelf->clk));
    bufp->chgBit(oldp+87,(vlSelf->fetch_i));
    bufp->chgBit(oldp+88,(vlSelf->fetch_d));
    bufp->chgIData(oldp+89,(vlSelf->addr_i),32);
    bufp->chgIData(oldp+90,(vlSelf->addr_d),32);
    bufp->chgWData(oldp+91,(vlSelf->line_from_mem),256);
    bufp->chgWData(oldp+99,(vlSelf->l1write_back_data),128);
    bufp->chgBit(oldp+103,(vlSelf->l1write_back_en));
    bufp->chgIData(oldp+104,(vlSelf->l1write_back_addr),32);
    bufp->chgBit(oldp+105,(vlSelf->ready));
    bufp->chgBit(oldp+106,(vlSelf->wb_ready));
    bufp->chgBit(oldp+107,(vlSelf->ready_i));
    bufp->chgBit(oldp+108,(vlSelf->ready_d));
    bufp->chgBit(oldp+109,(vlSelf->wb_ready_d));
    bufp->chgWData(oldp+110,(vlSelf->data_out),128);
    bufp->chgWData(oldp+114,(vlSelf->write_back_data),128);
    bufp->chgIData(oldp+118,(vlSelf->write_back_addr),32);
    bufp->chgBit(oldp+119,(vlSelf->write_back_en));
    bufp->chgIData(oldp+120,(vlSelf->main_mem_addr),32);
    bufp->chgBit(oldp+121,(vlSelf->main_mem_fetch));
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
