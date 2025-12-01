// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->fetch & 0xfeU))) {
        Verilated::overWidthError("fetch");}
    if (VL_UNLIKELY((vlSelf->SizeWrite_m & 0xfcU))) {
        Verilated::overWidthError("SizeWrite_m");}
    if (VL_UNLIKELY((vlSelf->MemWrite_m & 0xfeU))) {
        Verilated::overWidthError("MemWrite_m");}
    if (VL_UNLIKELY((vlSelf->LoadSize & 0xfcU))) {
        Verilated::overWidthError("LoadSize");}
    if (VL_UNLIKELY((vlSelf->LoadUnsigned & 0xfeU))) {
        Verilated::overWidthError("LoadUnsigned");}
    if (VL_UNLIKELY((vlSelf->ready & 0xfeU))) {
        Verilated::overWidthError("ready");}
}
#endif  // VL_DEBUG
