// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpc_block.h for the primary calling header

#include "verilated.h"

#include "Vpc_block___024root.h"

VL_ATTR_COLD void Vpc_block___024root___settle__TOP__0(Vpc_block___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->pc_block__DOT__inc_pc = ((IData)(4U) + vlSelf->pc_block__DOT__internal_pc);
    vlSelf->pc = vlSelf->pc_block__DOT__internal_pc;
    vlSelf->pc_block__DOT__branch_pc = (vlSelf->pc_block__DOT__internal_pc 
                                        + vlSelf->Imm_op);
}

VL_ATTR_COLD void Vpc_block___024root___eval_initial(Vpc_block___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vpc_block___024root___eval_settle(Vpc_block___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root___eval_settle\n"); );
    // Body
    Vpc_block___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vpc_block___024root___final(Vpc_block___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root___final\n"); );
}

VL_ATTR_COLD void Vpc_block___024root___ctor_var_reset(Vpc_block___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_block___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->Imm_op = VL_RAND_RESET_I(32);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->pc_src = VL_RAND_RESET_I(1);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->pc_block__DOT__branch_pc = VL_RAND_RESET_I(32);
    vlSelf->pc_block__DOT__inc_pc = VL_RAND_RESET_I(32);
    vlSelf->pc_block__DOT__internal_pc = VL_RAND_RESET_I(32);
}
