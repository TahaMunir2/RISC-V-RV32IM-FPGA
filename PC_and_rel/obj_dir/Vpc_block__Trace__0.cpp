// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpc_block__Syms.h"


void Vpc_block___024root__trace_chg_sub_0(Vpc_block___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vpc_block___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root__trace_chg_top_0\n"); );
    // Init
    Vpc_block___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpc_block___024root*>(voidSelf);
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vpc_block___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vpc_block___024root__trace_chg_sub_0(Vpc_block___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgIData(oldp+1,(vlSelf->Imm_op),32);
    bufp->chgBit(oldp+2,(vlSelf->rst));
    bufp->chgBit(oldp+3,(vlSelf->pc_src));
    bufp->chgIData(oldp+4,(vlSelf->pc),32);
    bufp->chgIData(oldp+5,((vlSelf->pc_block__DOT__internal_pc 
                            + vlSelf->Imm_op)),32);
    bufp->chgIData(oldp+6,(((IData)(4U) + vlSelf->pc_block__DOT__internal_pc)),32);
    bufp->chgIData(oldp+7,(vlSelf->pc_block__DOT__internal_pc),32);
}

void Vpc_block___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root__trace_cleanup\n"); );
    // Init
    Vpc_block___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpc_block___024root*>(voidSelf);
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
