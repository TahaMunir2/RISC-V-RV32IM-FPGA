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
        bufp->chgCData(oldp+12,(vlSelf->l2_cache__DOT__way_rd),2);
        bufp->chgWData(oldp+13,(vlSelf->l2_cache__DOT__wmask),256);
        bufp->chgBit(oldp+21,(vlSelf->l2_cache__DOT__hit0));
        bufp->chgBit(oldp+22,(vlSelf->l2_cache__DOT__hit1));
        bufp->chgBit(oldp+23,(vlSelf->l2_cache__DOT__hit2));
        bufp->chgBit(oldp+24,(vlSelf->l2_cache__DOT__hit3));
        bufp->chgBit(oldp+25,(vlSelf->l2_cache__DOT__valid0));
        bufp->chgBit(oldp+26,(vlSelf->l2_cache__DOT__valid1));
        bufp->chgBit(oldp+27,(vlSelf->l2_cache__DOT__valid2));
        bufp->chgBit(oldp+28,(vlSelf->l2_cache__DOT__valid3));
        bufp->chgBit(oldp+29,(vlSelf->l2_cache__DOT__miss));
        bufp->chgBit(oldp+30,(vlSelf->l2_cache__DOT__evict));
        bufp->chgWData(oldp+31,(vlSelf->l2_cache__DOT__l1write_back_data_buffer),128);
        bufp->chgBit(oldp+35,(vlSelf->l2_cache__DOT__l1write_buffer));
        bufp->chgIData(oldp+36,(vlSelf->l2_cache__DOT__l1write_back_addr_buffer),32);
        bufp->chgIData(oldp+37,((vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                 >> 0xdU)),19);
        bufp->chgCData(oldp+38,((0xffU & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                          >> 5U))),8);
        bufp->chgCData(oldp+39,((7U & (vlSelf->l2_cache__DOT__l1write_back_addr_buffer 
                                       >> 2U))),3);
        bufp->chgBit(oldp+40,(vlSelf->l2_cache__DOT__hit0_wb));
        bufp->chgBit(oldp+41,(vlSelf->l2_cache__DOT__hit1_wb));
        bufp->chgBit(oldp+42,(vlSelf->l2_cache__DOT__hit2_wb));
        bufp->chgBit(oldp+43,(vlSelf->l2_cache__DOT__hit3_wb));
        bufp->chgBit(oldp+44,(vlSelf->l2_cache__DOT__miss_wb));
        bufp->chgCData(oldp+45,(vlSelf->l2_cache__DOT__way),2);
        bufp->chgIData(oldp+46,(vlSelf->l2_cache__DOT__tag_bits),19);
        bufp->chgCData(oldp+47,(vlSelf->l2_cache__DOT__set),8);
        bufp->chgCData(oldp+48,(vlSelf->l2_cache__DOT__block_offset),3);
        bufp->chgWData(oldp+49,(vlSelf->l2_cache__DOT__l2write_back_data_buffer),256);
        bufp->chgCData(oldp+57,(vlSelf->l2_cache__DOT__l2write_buffer),2);
        bufp->chgIData(oldp+58,(vlSelf->l2_cache__DOT__l2write_back_addr_buffer),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+59,((vlSelf->l2_cache__DOT__addr 
                                 >> 0xdU)),19);
        bufp->chgCData(oldp+60,((0xffU & (vlSelf->l2_cache__DOT__addr 
                                          >> 5U))),8);
        bufp->chgCData(oldp+61,((7U & (vlSelf->l2_cache__DOT__addr 
                                       >> 2U))),3);
        bufp->chgBit(oldp+62,(vlSelf->l2_cache__DOT__fetch));
        bufp->chgBit(oldp+63,(vlSelf->l2_cache__DOT__req_d));
        bufp->chgBit(oldp+64,(vlSelf->l2_cache__DOT__req_i));
        bufp->chgIData(oldp+65,(vlSelf->l2_cache__DOT__addr),32);
        bufp->chgBit(oldp+66,(vlSelf->l2_cache__DOT__l1write));
    }
    bufp->chgBit(oldp+67,(vlSelf->clk));
    bufp->chgBit(oldp+68,(vlSelf->fetch_i));
    bufp->chgBit(oldp+69,(vlSelf->fetch_d));
    bufp->chgIData(oldp+70,(vlSelf->addr_i),32);
    bufp->chgIData(oldp+71,(vlSelf->addr_d),32);
    bufp->chgWData(oldp+72,(vlSelf->line_from_mem),256);
    bufp->chgWData(oldp+80,(vlSelf->l1write_back_data),128);
    bufp->chgBit(oldp+84,(vlSelf->l1write_back_en));
    bufp->chgIData(oldp+85,(vlSelf->l1write_back_addr),32);
    bufp->chgBit(oldp+86,(vlSelf->ready));
    bufp->chgBit(oldp+87,(vlSelf->wb_ready));
    bufp->chgBit(oldp+88,(vlSelf->ready_i));
    bufp->chgBit(oldp+89,(vlSelf->ready_d));
    bufp->chgBit(oldp+90,(vlSelf->wb_ready_d));
    bufp->chgWData(oldp+91,(vlSelf->data_out),128);
    bufp->chgWData(oldp+95,(vlSelf->write_back_data),128);
    bufp->chgIData(oldp+99,(vlSelf->write_back_addr),32);
    bufp->chgBit(oldp+100,(vlSelf->write_back_en));
    bufp->chgBit(oldp+101,(vlSelf->main_mem_addr));
    bufp->chgBit(oldp+102,(vlSelf->main_mem_fetch));
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
