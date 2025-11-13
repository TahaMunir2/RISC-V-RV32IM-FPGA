// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpc_block__Syms.h"


VL_ATTR_COLD void Vpc_block___024root__trace_init_sub__TOP__0(Vpc_block___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBus(c+2,"Imm_op", false,-1, 31,0);
    tracep->declBit(c+3,"rst", false,-1);
    tracep->declBit(c+4,"pc_src", false,-1);
    tracep->declBus(c+5,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("pc_block ");
    tracep->declBus(c+9,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBus(c+2,"Imm_op", false,-1, 31,0);
    tracep->declBit(c+3,"rst", false,-1);
    tracep->declBit(c+4,"pc_src", false,-1);
    tracep->declBus(c+5,"pc", false,-1, 31,0);
    tracep->declBus(c+6,"branch_pc", false,-1, 31,0);
    tracep->declBus(c+7,"inc_pc", false,-1, 31,0);
    tracep->declBus(c+8,"internal_pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vpc_block___024root__trace_init_top(Vpc_block___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root__trace_init_top\n"); );
    // Body
    Vpc_block___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vpc_block___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpc_block___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpc_block___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vpc_block___024root__trace_register(Vpc_block___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vpc_block___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vpc_block___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vpc_block___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vpc_block___024root__trace_full_sub_0(Vpc_block___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpc_block___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root__trace_full_top_0\n"); );
    // Init
    Vpc_block___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpc_block___024root*>(voidSelf);
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vpc_block___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpc_block___024root__trace_full_sub_0(Vpc_block___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullIData(oldp+2,(vlSelf->Imm_op),32);
    bufp->fullBit(oldp+3,(vlSelf->rst));
    bufp->fullBit(oldp+4,(vlSelf->pc_src));
    bufp->fullIData(oldp+5,(vlSelf->pc),32);
    bufp->fullIData(oldp+6,((vlSelf->pc_block__DOT__internal_pc 
                             + vlSelf->Imm_op)),32);
    bufp->fullIData(oldp+7,(((IData)(4U) + vlSelf->pc_block__DOT__internal_pc)),32);
    bufp->fullIData(oldp+8,(vlSelf->pc_block__DOT__internal_pc),32);
    bufp->fullIData(oldp+9,(0x20U),32);
}
