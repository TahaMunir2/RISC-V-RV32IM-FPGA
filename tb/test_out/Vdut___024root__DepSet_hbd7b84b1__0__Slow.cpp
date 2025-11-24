// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut__Syms.h"
#include "Vdut___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__stl(Vdut___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdut___024root___eval_triggers__stl(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_triggers__stl\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
    vlSelfRef.__VstlTriggered.setBit(1U, vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__0.neq(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array));
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__0.assign(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array);
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VstlDidInit)))))) {
        vlSelfRef.__VstlDidInit = 1U;
        vlSelfRef.__VstlTriggered.setBit(1U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdut___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
