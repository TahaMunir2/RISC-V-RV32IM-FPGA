// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpc_block.h for the primary calling header

#include "verilated.h"

#include "Vpc_block___024root.h"

VL_INLINE_OPT void Vpc_block___024root___sequent__TOP__0(Vpc_block___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->pc_block__DOT__internal_pc = ((IData)(vlSelf->rst)
                                           ? 0U : ((IData)(vlSelf->pc_src)
                                                    ? vlSelf->pc_block__DOT__branch_pc
                                                    : vlSelf->pc_block__DOT__inc_pc));
    vlSelf->pc_block__DOT__inc_pc = ((IData)(4U) + vlSelf->pc_block__DOT__internal_pc);
    vlSelf->pc = vlSelf->pc_block__DOT__internal_pc;
}

VL_INLINE_OPT void Vpc_block___024root___combo__TOP__0(Vpc_block___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->pc_block__DOT__branch_pc = (vlSelf->pc_block__DOT__internal_pc 
                                        + vlSelf->Imm_op);
}

void Vpc_block___024root___eval(Vpc_block___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vpc_block___024root___sequent__TOP__0(vlSelf);
    }
    Vpc_block___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vpc_block___024root___eval_debug_assertions(Vpc_block___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->pc_src & 0xfeU))) {
        Verilated::overWidthError("pc_src");}
}
#endif  // VL_DEBUG
