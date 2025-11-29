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
        bufp->chgIData(oldp+0,(vlSelf->l1d_cache__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+1,(vlSelf->l1d_cache__DOT__wr_en));
        bufp->chgBit(oldp+2,(vlSelf->l1d_cache__DOT__rd_en));
        bufp->chgWData(oldp+3,(vlSelf->l1d_cache__DOT__write_data),128);
        bufp->chgBit(oldp+7,(vlSelf->l1d_cache__DOT__way));
        bufp->chgWData(oldp+8,(vlSelf->l1d_cache__DOT__wmask),128);
        bufp->chgBit(oldp+12,(vlSelf->l1d_cache__DOT__hit0));
        bufp->chgBit(oldp+13,(vlSelf->l1d_cache__DOT__hit1));
        bufp->chgBit(oldp+14,(vlSelf->l1d_cache__DOT__valid0));
        bufp->chgBit(oldp+15,(vlSelf->l1d_cache__DOT__valid1));
        bufp->chgBit(oldp+16,(vlSelf->l1d_cache__DOT__miss));
        bufp->chgCData(oldp+17,(vlSelf->l1d_cache__DOT__bottom_bit),7);
    }
    bufp->chgBit(oldp+18,(vlSelf->clk));
    bufp->chgBit(oldp+19,(vlSelf->fetch));
    bufp->chgIData(oldp+20,(vlSelf->addr),32);
    bufp->chgIData(oldp+21,(vlSelf->wd),32);
    bufp->chgWData(oldp+22,(vlSelf->line_from_mem),128);
    bufp->chgCData(oldp+26,(vlSelf->SizeWrite_m),2);
    bufp->chgBit(oldp+27,(vlSelf->MemWrite_m));
    bufp->chgCData(oldp+28,(vlSelf->LoadSize),2);
    bufp->chgBit(oldp+29,(vlSelf->LoadUnsigned));
    bufp->chgBit(oldp+30,(vlSelf->wake));
    bufp->chgIData(oldp+31,(vlSelf->data_out),32);
    bufp->chgWData(oldp+32,(vlSelf->write_back),128);
    bufp->chgBit(oldp+36,(vlSelf->write_back_en));
    bufp->chgBit(oldp+37,(vlSelf->stall));
    bufp->chgIData(oldp+38,((vlSelf->addr >> 0xbU)),21);
    bufp->chgCData(oldp+39,((0x7fU & (vlSelf->addr 
                                      >> 4U))),7);
    bufp->chgCData(oldp+40,((3U & (vlSelf->addr >> 2U))),2);
    bufp->chgCData(oldp+41,((3U & vlSelf->addr)),2);
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
}
