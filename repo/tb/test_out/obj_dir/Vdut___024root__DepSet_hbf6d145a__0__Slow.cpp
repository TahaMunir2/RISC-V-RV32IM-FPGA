// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___eval_static(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_static\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vdut___024root___eval_initial__TOP(Vdut___024root* vlSelf);
VL_ATTR_COLD void Vdut___024root____Vm_traceActivitySetAll(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdut___024root___eval_initial__TOP(vlSelf);
    Vdut___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vdut___024root___eval_initial__TOP(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial__TOP\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x80U, vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i)) {
        vlSelfRef.l1d_cache__DOT__cache[(0x7fU & vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i)][9U] 
            = (0x3fffU & vlSelfRef.l1d_cache__DOT__cache
               [(0x7fU & vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i)][9U]);
        vlSelfRef.l1d_cache__DOT__cache[(0x7fU & vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i)][4U] 
            = (0xffbfffffU & vlSelfRef.l1d_cache__DOT__cache
               [(0x7fU & vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i)][4U]);
        vlSelfRef.l1d_cache__DOT__cache[(0x7fU & vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i)][4U] 
            = (0xffdfffffU & vlSelfRef.l1d_cache__DOT__cache
               [(0x7fU & vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i)][4U]);
        vlSelfRef.l1d_cache__DOT__cache[(0x7fU & vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i)][9U] 
            = (0x5fffU & vlSelfRef.l1d_cache__DOT__cache
               [(0x7fU & vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i)][9U]);
        vlSelfRef.l1d_cache__DOT__cache[(0x7fU & vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i)][9U] 
            = (0x6fffU & vlSelfRef.l1d_cache__DOT__cache
               [(0x7fU & vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i)][9U]);
        vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + vlSelfRef.l1d_cache__DOT__unnamedblk1__DOT__i);
    }
}

VL_ATTR_COLD void Vdut___024root___eval_final(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_final\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__stl(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vdut___024root___eval_phase__stl(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/Users/tahamunir/Downloads/Team5-cache_leo/repo/rtl/l1d_cache.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vdut___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__stl(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__stl\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vdut___024root___ico_sequent__TOP__0(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_stl(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_stl\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vdut___024root___ico_sequent__TOP__0(vlSelf);
        Vdut___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vdut___024root___eval_triggers__stl(Vdut___024root* vlSelf);

VL_ATTR_COLD bool Vdut___024root___eval_phase__stl(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__stl\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vdut___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vdut___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__ico(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__ico\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__act\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__nba(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__nba\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdut___024root____Vm_traceActivitySetAll(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root____Vm_traceActivitySetAll\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->fetch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14022223855178902746ull);
    vlSelf->addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14934084843038794831ull);
    vlSelf->wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18210509495843279068ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->line_from_mem, __VscopeHash, 13349949889117228958ull);
    vlSelf->SizeWrite_m = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10115364517493633461ull);
    vlSelf->MemWrite_m = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3145252148885974435ull);
    vlSelf->LoadSize = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15967606904086656157ull);
    vlSelf->LoadUnsigned = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14077627769744320201ull);
    vlSelf->data_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11675680895196038875ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->write_back, __VscopeHash, 15897179809610538262ull);
    vlSelf->write_back_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15960194620730598255ull);
    vlSelf->stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7179230919112499263ull);
    vlSelf->l1d_cache__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8604143049684075905ull);
    vlSelf->l1d_cache__DOT__rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16334268454494043096ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->l1d_cache__DOT__write_data, __VscopeHash, 6490202247043529359ull);
    vlSelf->l1d_cache__DOT__way = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2474448215331760854ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->l1d_cache__DOT__wmask, __VscopeHash, 7237862116247714992ull);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(303, vlSelf->l1d_cache__DOT__cache[__Vi0], __VscopeHash, 10758687750905515735ull);
    }
    vlSelf->l1d_cache__DOT__hit0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4035696530436746951ull);
    vlSelf->l1d_cache__DOT__hit1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6877118183511643699ull);
    vlSelf->l1d_cache__DOT__valid0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4767653236926429500ull);
    vlSelf->l1d_cache__DOT__valid1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10486228368917097261ull);
    vlSelf->l1d_cache__DOT__miss = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9111686781779366453ull);
    vlSelf->l1d_cache__DOT__bottom_bit = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 4266238921798775273ull);
    vlSelf->l1d_cache__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->l1d_cache__DOT____VdfgExtracted_h18ae9b83__0 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 7912977524151672580ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
