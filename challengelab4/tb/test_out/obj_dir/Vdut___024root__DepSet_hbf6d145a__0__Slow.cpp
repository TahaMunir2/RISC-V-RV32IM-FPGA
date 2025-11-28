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
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<6>/*191:0*/ __Vtemp_2;
    // Body
    VL_WRITEF_NX("Loading rom. \n",0);
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x6772616dU;
    __Vtemp_1[2U] = 0x70726fU;
    VL_READMEM_N(true, 8, 131072, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_1)
                 ,  &(vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array)
                 , 0x10000U, ~0ULL);
    VL_WRITEF_NX("Loading ram.\n",0);
    __Vtemp_2[0U] = 0x2e6d656dU;
    __Vtemp_2[1U] = 0x7369616eU;
    __Vtemp_2[2U] = 0x67617573U;
    __Vtemp_2[3U] = 0x6e63652fU;
    __Vtemp_2[4U] = 0x66657265U;
    __Vtemp_2[5U] = 0x7265U;
    VL_READMEM_N(true, 8, 131072, 0, VL_CVT_PACK_STR_NW(6, __Vtemp_2)
                 ,  &(vlSelfRef.top__DOT__datamem__DOT__ram_array)
                 , 0x10000U, ~0ULL);
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
            VL_FATAL_MT("/Users/tahamunir/Downloads/Team5-Full-RV32I-Design-Pipelining-4/challengelab4/rtl/top.sv", 1, "", "Settle region did not converge.");
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

VL_ATTR_COLD void Vdut___024root___stl_sequent__TOP__0(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_stl(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_stl\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vdut___024root___stl_sequent__TOP__0(vlSelf);
        Vdut___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vdut___024root___stl_sequent__TOP__0(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___stl_sequent__TOP__0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdfgRegularize_h038a369a_0_3;
    __VdfgRegularize_h038a369a_0_3 = 0;
    // Body
    vlSelfRef.top__DOT__flush_f_d = 0U;
    vlSelfRef.top__DOT__ImmSrcD = 0U;
    vlSelfRef.top__DOT__ResultSrcD = 0U;
    vlSelfRef.top__DOT__ALUSrcD = 0U;
    vlSelfRef.top__DOT__MemWriteD = 0U;
    vlSelfRef.top__DOT__LoadSizeD = 2U;
    vlSelfRef.top__DOT__ALUSrc2D = 0U;
    vlSelfRef.top__DOT__LoadUnsignedD = 0U;
    vlSelfRef.top__DOT__SizeWriteD = 0U;
    vlSelfRef.top__DOT__ALUCtrlD = 0U;
    vlSelfRef.top__DOT__RegWriteD = 0U;
    vlSelfRef.a0 = vlSelfRef.top__DOT__regfile__DOT__regfile_array
        [0xaU];
    vlSelfRef.top__DOT__PCF = vlSelfRef.top__DOT__pc_block__DOT__internal_pc;
    vlSelfRef.top__DOT__pc_block__DOT__inc_pc = ((IData)(4U) 
                                                 + vlSelfRef.top__DOT__pc_block__DOT__internal_pc);
    vlSelfRef.top__DOT__pc_block__DOT__branch_pc = 
        ((vlSelfRef.top__DOT__ExtImmE + vlSelfRef.top__DOT__PCE) 
         + vlSelfRef.top__DOT__pc_block__DOT__internal_pc);
    vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffffff00U & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | vlSelfRef.top__DOT__datamem__DOT__ram_array
           [(0x1ffffU & vlSelfRef.top__DOT__ALUResultM)]);
    vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffff00ffU & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelfRef.top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__ALUResultM))] 
              << 8U));
    vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xff00ffffU & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelfRef.top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(2U) + vlSelfRef.top__DOT__ALUResultM))] 
              << 0x10U));
    vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffffffU & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelfRef.top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(3U) + vlSelfRef.top__DOT__ALUResultM))] 
              << 0x18U));
    vlSelfRef.top__DOT__ReadDataM = ((0U == (IData)(vlSelfRef.top__DOT__LoadSizeM))
                                      ? ((IData)(vlSelfRef.top__DOT__LoadUnsignedM)
                                          ? (0xffU 
                                             & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data)
                                          : (((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
                                                             >> 7U)))) 
                                              << 8U) 
                                             | (0xffU 
                                                & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data)))
                                      : ((1U == (IData)(vlSelfRef.top__DOT__LoadSizeM))
                                          ? ((IData)(vlSelfRef.top__DOT__LoadUnsignedM)
                                              ? (0xffffU 
                                                 & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data)
                                              : (((- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data 
                                                                 >> 0xfU)))) 
                                                  << 0x10U) 
                                                 | (0xffffU 
                                                    & vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data)))
                                          : vlSelfRef.top__DOT__datamem__DOT__unnamedblk1__DOT__data));
    vlSelfRef.top__DOT__hazard_unit__DOT__wStall = 
        ((1U == (IData)(vlSelfRef.top__DOT__ResultSrcE)) 
         & ((0U != (IData)(vlSelfRef.top__DOT__RdE)) 
            & (((IData)(vlSelfRef.top__DOT__RdE) == 
                (0x1fU & (vlSelfRef.top__DOT__InstrD 
                          >> 0xfU))) | ((IData)(vlSelfRef.top__DOT__RdE) 
                                        == (0x1fU & 
                                            (vlSelfRef.top__DOT__InstrD 
                                             >> 0x14U))))));
    vlSelfRef.top__DOT__ForwardAE = 0U;
    if ((((IData)(vlSelfRef.top__DOT__RegWriteM) & 
          (0U != (IData)(vlSelfRef.top__DOT__RdM))) 
         & ((IData)(vlSelfRef.top__DOT__RdM) == (IData)(vlSelfRef.top__DOT__Rs1E)))) {
        vlSelfRef.top__DOT__ForwardAE = 2U;
    } else if ((((IData)(vlSelfRef.top__DOT__RegWriteW) 
                 & (0U != (IData)(vlSelfRef.top__DOT__RdW))) 
                & ((IData)(vlSelfRef.top__DOT__RdW) 
                   == (IData)(vlSelfRef.top__DOT__Rs1E)))) {
        vlSelfRef.top__DOT__ForwardAE = 1U;
    }
    vlSelfRef.top__DOT__ForwardBE = 0U;
    if ((((IData)(vlSelfRef.top__DOT__RegWriteM) & 
          (0U != (IData)(vlSelfRef.top__DOT__RdM))) 
         & ((IData)(vlSelfRef.top__DOT__RdM) == (IData)(vlSelfRef.top__DOT__Rs2E)))) {
        vlSelfRef.top__DOT__ForwardBE = 2U;
    } else if ((((IData)(vlSelfRef.top__DOT__RegWriteW) 
                 & (0U != (IData)(vlSelfRef.top__DOT__RdW))) 
                & ((IData)(vlSelfRef.top__DOT__RdW) 
                   == (IData)(vlSelfRef.top__DOT__Rs2E)))) {
        vlSelfRef.top__DOT__ForwardBE = 1U;
    }
    vlSelfRef.top__DOT__ResultW = ((0U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                    ? vlSelfRef.top__DOT__ALUResultW
                                    : ((1U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                        ? vlSelfRef.top__DOT__ReadDataW
                                        : ((2U == (IData)(vlSelfRef.top__DOT__ResultSrcW))
                                            ? vlSelfRef.top__DOT__PCPlus4W
                                            : 0U)));
    vlSelfRef.top__DOT__PCWrite = 1U;
    vlSelfRef.top__DOT__F_Write = 1U;
    vlSelfRef.top__DOT__flush_d_exec = 0U;
    if (((2U == (IData)(vlSelfRef.top__DOT__PCSrcE)) 
         | (1U == (IData)(vlSelfRef.top__DOT__PCSrcE)))) {
        vlSelfRef.top__DOT__flush_f_d = 1U;
        vlSelfRef.top__DOT__flush_d_exec = 1U;
    }
    if (vlSelfRef.top__DOT__hazard_unit__DOT__wStall) {
        vlSelfRef.top__DOT__PCWrite = 0U;
        vlSelfRef.top__DOT__F_Write = 0U;
        vlSelfRef.top__DOT__flush_d_exec = 1U;
    }
    vlSelfRef.top__DOT__ALUop1 = ((IData)(vlSelfRef.top__DOT__ALUSrc2E)
                                   ? vlSelfRef.top__DOT__PCPlus4E
                                   : ((1U & (IData)(vlSelfRef.top__DOT__ForwardAE))
                                       ? vlSelfRef.top__DOT__ResultW
                                       : vlSelfRef.top__DOT__RD1E));
    vlSelfRef.top__DOT__WriteDataE = ((1U & (IData)(vlSelfRef.top__DOT__ForwardBE))
                                       ? vlSelfRef.top__DOT__ResultW
                                       : vlSelfRef.top__DOT__RD2E);
    vlSelfRef.top__DOT__SrcBE = ((IData)(vlSelfRef.top__DOT__ALUSrcE)
                                  ? vlSelfRef.top__DOT__ExtImmE
                                  : vlSelfRef.top__DOT__WriteDataE);
    vlSelfRef.top__DOT__EQ = (vlSelfRef.top__DOT__ALUop1 
                              == vlSelfRef.top__DOT__SrcBE);
    __VdfgRegularize_h038a369a_0_3 = (vlSelfRef.top__DOT__ALUop1 
                                      + vlSelfRef.top__DOT__SrcBE);
    vlSelfRef.top__DOT__LT = VL_LTS_III(32, vlSelfRef.top__DOT__ALUop1, vlSelfRef.top__DOT__SrcBE);
    vlSelfRef.top__DOT__LTU = (vlSelfRef.top__DOT__ALUop1 
                               < vlSelfRef.top__DOT__SrcBE);
    vlSelfRef.top__DOT__PCSrcD = 0U;
    if (((((((((0x37U == (0x7fU & vlSelfRef.top__DOT__InstrD)) 
               | (0x17U == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
              | (0x6fU == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
             | (0x67U == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
            | (0x63U == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
           | (3U == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
          | (0x23U == (0x7fU & vlSelfRef.top__DOT__InstrD))) 
         | (0x13U == (0x7fU & vlSelfRef.top__DOT__InstrD)))) {
        if ((0x37U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
            vlSelfRef.top__DOT__ImmSrcD = 4U;
            vlSelfRef.top__DOT__ResultSrcD = 0U;
            vlSelfRef.top__DOT__ALUSrcD = 1U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__ALUSrc2D = 0U;
            vlSelfRef.top__DOT__SizeWriteD = 0U;
            vlSelfRef.top__DOT__ALUCtrlD = 0xaU;
            vlSelfRef.top__DOT__RegWriteD = 1U;
            vlSelfRef.top__DOT__PCSrcD = 0U;
        } else if ((0x17U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
            vlSelfRef.top__DOT__ImmSrcD = 4U;
            vlSelfRef.top__DOT__ResultSrcD = 0U;
            vlSelfRef.top__DOT__ALUSrcD = 1U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__ALUSrc2D = 1U;
            vlSelfRef.top__DOT__SizeWriteD = 0U;
            vlSelfRef.top__DOT__ALUCtrlD = 0xbU;
            vlSelfRef.top__DOT__RegWriteD = 1U;
            vlSelfRef.top__DOT__PCSrcD = 0U;
        } else {
            if ((0x6fU == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                vlSelfRef.top__DOT__ImmSrcD = 3U;
                vlSelfRef.top__DOT__ResultSrcD = 2U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__SizeWriteD = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
                vlSelfRef.top__DOT__PCSrcD = 1U;
            } else if ((0x67U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 2U;
                vlSelfRef.top__DOT__ALUSrcD = 1U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__SizeWriteD = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
                vlSelfRef.top__DOT__PCSrcD = 2U;
            } else if ((0x63U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                if ((0x4000U & vlSelfRef.top__DOT__InstrD)) {
                    vlSelfRef.top__DOT__ImmSrcD = 2U;
                    vlSelfRef.top__DOT__ALUCtrlD = 1U;
                    vlSelfRef.top__DOT__PCSrcD = ((0x2000U 
                                                   & vlSelfRef.top__DOT__InstrD)
                                                   ? 
                                                  ((0x1000U 
                                                    & vlSelfRef.top__DOT__InstrD)
                                                    ? 
                                                   ((IData)(vlSelfRef.top__DOT__LTU)
                                                     ? 0U
                                                     : 1U)
                                                    : 
                                                   ((IData)(vlSelfRef.top__DOT__LTU)
                                                     ? 1U
                                                     : 0U))
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelfRef.top__DOT__InstrD)
                                                    ? 
                                                   ((IData)(vlSelfRef.top__DOT__LT)
                                                     ? 0U
                                                     : 1U)
                                                    : 
                                                   ((IData)(vlSelfRef.top__DOT__LT)
                                                     ? 1U
                                                     : 0U)));
                } else if ((0x2000U & vlSelfRef.top__DOT__InstrD)) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 0U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else {
                    vlSelfRef.top__DOT__ImmSrcD = 2U;
                    vlSelfRef.top__DOT__ALUCtrlD = 1U;
                    vlSelfRef.top__DOT__PCSrcD = ((0x1000U 
                                                   & vlSelfRef.top__DOT__InstrD)
                                                   ? 
                                                  ((IData)(vlSelfRef.top__DOT__EQ)
                                                    ? 0U
                                                    : 1U)
                                                   : 
                                                  ((IData)(vlSelfRef.top__DOT__EQ)
                                                    ? 1U
                                                    : 0U));
                }
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__SizeWriteD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 0U;
            } else if ((3U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 1U;
                vlSelfRef.top__DOT__ALUSrcD = 1U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__SizeWriteD = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
            } else if ((0x23U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                if ((0U == (7U & (vlSelfRef.top__DOT__InstrD 
                                  >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 1U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 1U;
                    vlSelfRef.top__DOT__SizeWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((1U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 1U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 1U;
                    vlSelfRef.top__DOT__SizeWriteD = 1U;
                    vlSelfRef.top__DOT__ALUCtrlD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((2U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 1U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 1U;
                    vlSelfRef.top__DOT__SizeWriteD = 2U;
                    vlSelfRef.top__DOT__ALUCtrlD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                }
            } else {
                if ((0U == (7U & (vlSelfRef.top__DOT__InstrD 
                                  >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 0U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((2U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 8U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((3U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 9U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((4U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 4U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((6U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 3U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((7U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 1U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 2U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                } else if ((1U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    if ((0U == (vlSelfRef.top__DOT__InstrD 
                                >> 0x19U))) {
                        vlSelfRef.top__DOT__ImmSrcD = 0U;
                        vlSelfRef.top__DOT__ResultSrcD = 0U;
                        vlSelfRef.top__DOT__ALUSrcD = 1U;
                        vlSelfRef.top__DOT__MemWriteD = 0U;
                        vlSelfRef.top__DOT__ALUCtrlD = 5U;
                        vlSelfRef.top__DOT__PCSrcD = 0U;
                    }
                } else if ((5U == (7U & (vlSelfRef.top__DOT__InstrD 
                                         >> 0xcU)))) {
                    if ((0U == (vlSelfRef.top__DOT__InstrD 
                                >> 0x19U))) {
                        vlSelfRef.top__DOT__ImmSrcD = 0U;
                        vlSelfRef.top__DOT__ResultSrcD = 0U;
                        vlSelfRef.top__DOT__ALUSrcD = 1U;
                        vlSelfRef.top__DOT__MemWriteD = 0U;
                        vlSelfRef.top__DOT__ALUCtrlD = 6U;
                        vlSelfRef.top__DOT__PCSrcD = 0U;
                    } else if ((0x20U == (vlSelfRef.top__DOT__InstrD 
                                          >> 0x19U))) {
                        vlSelfRef.top__DOT__ImmSrcD = 0U;
                        vlSelfRef.top__DOT__ResultSrcD = 0U;
                        vlSelfRef.top__DOT__ALUSrcD = 1U;
                        vlSelfRef.top__DOT__MemWriteD = 0U;
                        vlSelfRef.top__DOT__ALUCtrlD = 7U;
                        vlSelfRef.top__DOT__PCSrcD = 0U;
                    }
                }
                vlSelfRef.top__DOT__RegWriteD = ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.top__DOT__InstrD 
                                                      >> 0xcU))) 
                                                 || ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlSelfRef.top__DOT__InstrD 
                                                          >> 0xcU))) 
                                                     || ((3U 
                                                          == 
                                                          (7U 
                                                           & (vlSelfRef.top__DOT__InstrD 
                                                              >> 0xcU))) 
                                                         || ((4U 
                                                              == 
                                                              (7U 
                                                               & (vlSelfRef.top__DOT__InstrD 
                                                                  >> 0xcU))) 
                                                             || ((6U 
                                                                  == 
                                                                  (7U 
                                                                   & (vlSelfRef.top__DOT__InstrD 
                                                                      >> 0xcU))) 
                                                                 || ((7U 
                                                                      == 
                                                                      (7U 
                                                                       & (vlSelfRef.top__DOT__InstrD 
                                                                          >> 0xcU))) 
                                                                     || ((1U 
                                                                          == 
                                                                          (7U 
                                                                           & (vlSelfRef.top__DOT__InstrD 
                                                                              >> 0xcU)))
                                                                          ? 
                                                                         (0U 
                                                                          == 
                                                                          (vlSelfRef.top__DOT__InstrD 
                                                                           >> 0x19U))
                                                                          : 
                                                                         ((5U 
                                                                           == 
                                                                           (7U 
                                                                            & (vlSelfRef.top__DOT__InstrD 
                                                                               >> 0xcU))) 
                                                                          && ((0U 
                                                                               == 
                                                                               (vlSelfRef.top__DOT__InstrD 
                                                                                >> 0x19U)) 
                                                                              || (0x20U 
                                                                                == 
                                                                                (vlSelfRef.top__DOT__InstrD 
                                                                                >> 0x19U)))))))))));
            }
            if ((0x6fU != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                if ((0x67U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                    if ((0x63U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                        if ((1U & (~ (vlSelfRef.top__DOT__InstrD 
                                      >> 0xeU)))) {
                            if ((0x2000U & vlSelfRef.top__DOT__InstrD)) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            }
                        }
                    } else if ((3U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                        if ((0x23U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                            if ((0U == (7U & (vlSelfRef.top__DOT__InstrD 
                                              >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((2U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((3U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((4U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((6U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((7U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                            } else if ((1U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                if ((0U == (vlSelfRef.top__DOT__InstrD 
                                            >> 0x19U))) {
                                    vlSelfRef.top__DOT__ALUSrc2D = 0U;
                                }
                            } else if ((5U == (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU)))) {
                                if ((0U == (vlSelfRef.top__DOT__InstrD 
                                            >> 0x19U))) {
                                    vlSelfRef.top__DOT__ALUSrc2D = 0U;
                                } else if ((0x20U == 
                                            (vlSelfRef.top__DOT__InstrD 
                                             >> 0x19U))) {
                                    vlSelfRef.top__DOT__ALUSrc2D = 0U;
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((0x37U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
            if ((0x17U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                if ((0x6fU != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                    if ((0x67U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                        if ((0x63U != (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                            if ((3U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
                                vlSelfRef.top__DOT__LoadSizeD 
                                    = ((0x4000U & vlSelfRef.top__DOT__InstrD)
                                        ? ((0x2000U 
                                            & vlSelfRef.top__DOT__InstrD)
                                            ? 2U : 
                                           ((0x1000U 
                                             & vlSelfRef.top__DOT__InstrD)
                                             ? 1U : 0U))
                                        : ((0x2000U 
                                            & vlSelfRef.top__DOT__InstrD)
                                            ? 2U : 
                                           ((0x1000U 
                                             & vlSelfRef.top__DOT__InstrD)
                                             ? 1U : 0U)));
                                vlSelfRef.top__DOT__LoadUnsignedD 
                                    = ((1U & (vlSelfRef.top__DOT__InstrD 
                                              >> 0xeU)) 
                                       && (1U & (~ 
                                                 (vlSelfRef.top__DOT__InstrD 
                                                  >> 0xdU))));
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x33U == (0x7fU & vlSelfRef.top__DOT__InstrD))) {
        if ((0U == (7U & (vlSelfRef.top__DOT__InstrD 
                          >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 0U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
            } else if ((0x20U == (vlSelfRef.top__DOT__InstrD 
                                  >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 1U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
            }
            vlSelfRef.top__DOT__RegWriteD = ((0U == 
                                              (vlSelfRef.top__DOT__InstrD 
                                               >> 0x19U)) 
                                             || (0x20U 
                                                 == 
                                                 (vlSelfRef.top__DOT__InstrD 
                                                  >> 0x19U)));
        } else if ((1U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 5U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
            } else {
                vlSelfRef.top__DOT__RegWriteD = 0U;
            }
        } else if ((2U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 8U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
            } else {
                vlSelfRef.top__DOT__RegWriteD = 0U;
            }
        } else if ((3U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 9U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
            } else {
                vlSelfRef.top__DOT__RegWriteD = 0U;
            }
        } else if ((4U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 4U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
            } else {
                vlSelfRef.top__DOT__RegWriteD = 0U;
            }
        } else if ((5U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 6U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
            } else if ((0x20U == (vlSelfRef.top__DOT__InstrD 
                                  >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 7U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
            }
            vlSelfRef.top__DOT__RegWriteD = ((0U == 
                                              (vlSelfRef.top__DOT__InstrD 
                                               >> 0x19U)) 
                                             || (0x20U 
                                                 == 
                                                 (vlSelfRef.top__DOT__InstrD 
                                                  >> 0x19U)));
        } else if ((6U == (7U & (vlSelfRef.top__DOT__InstrD 
                                 >> 0xcU)))) {
            if ((0U == (vlSelfRef.top__DOT__InstrD 
                        >> 0x19U))) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__ALUSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUSrc2D = 0U;
                vlSelfRef.top__DOT__ALUCtrlD = 3U;
                vlSelfRef.top__DOT__PCSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
            } else {
                vlSelfRef.top__DOT__RegWriteD = 0U;
            }
        } else {
            if ((7U == (7U & (vlSelfRef.top__DOT__InstrD 
                              >> 0xcU)))) {
                if ((0U == (vlSelfRef.top__DOT__InstrD 
                            >> 0x19U))) {
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__ALUSrcD = 0U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUSrc2D = 0U;
                    vlSelfRef.top__DOT__ALUCtrlD = 2U;
                    vlSelfRef.top__DOT__PCSrcD = 0U;
                }
            }
            vlSelfRef.top__DOT__RegWriteD = ((7U == 
                                              (7U & 
                                               (vlSelfRef.top__DOT__InstrD 
                                                >> 0xcU))) 
                                             && (0U 
                                                 == 
                                                 (vlSelfRef.top__DOT__InstrD 
                                                  >> 0x19U)));
        }
    }
    vlSelfRef.top__DOT__ALUResultE = ((8U & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                       ? ((4U & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                           ? 0U : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                     ? 
                                                    (__VdfgRegularize_h038a369a_0_3 
                                                     - (IData)(4U))
                                                     : vlSelfRef.top__DOT__SrcBE)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                     ? 
                                                    ((IData)(vlSelfRef.top__DOT__LTU)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    ((IData)(vlSelfRef.top__DOT__LT)
                                                      ? 1U
                                                      : 0U))))
                                       : ((4U & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                           ? ((2U & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelfRef.top__DOT__ALUop1, 
                                                                 (0x1fU 
                                                                  & vlSelfRef.top__DOT__SrcBE))
                                                   : 
                                                  VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__ALUop1, 
                                                                (0x1fU 
                                                                 & vlSelfRef.top__DOT__SrcBE)))
                                               : ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                   ? 
                                                  VL_SHIFTL_III(32,32,32, vlSelfRef.top__DOT__ALUop1, 
                                                                (0x1fU 
                                                                 & vlSelfRef.top__DOT__SrcBE))
                                                   : 
                                                  (vlSelfRef.top__DOT__ALUop1 
                                                   ^ vlSelfRef.top__DOT__SrcBE)))
                                           : ((2U & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                   ? 
                                                  (vlSelfRef.top__DOT__ALUop1 
                                                   | vlSelfRef.top__DOT__SrcBE)
                                                   : 
                                                  (vlSelfRef.top__DOT__ALUop1 
                                                   & vlSelfRef.top__DOT__SrcBE))
                                               : ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__ALUCtrlE))
                                                   ? 
                                                  (vlSelfRef.top__DOT__ALUop1 
                                                   - vlSelfRef.top__DOT__SrcBE)
                                                   : __VdfgRegularize_h038a369a_0_3))));
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
}

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->a0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17342812819118991936ull);
    vlSelf->top__DOT__Rs1E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3697728390298515355ull);
    vlSelf->top__DOT__Rs2E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17284541648944200445ull);
    vlSelf->top__DOT__RdE = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4282630310355555055ull);
    vlSelf->top__DOT__RD1E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14787147602069543749ull);
    vlSelf->top__DOT__RD2E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1475893453982170085ull);
    vlSelf->top__DOT__ExtImmE = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8088861167055280863ull);
    vlSelf->top__DOT__ResultSrcD = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11370407121894427002ull);
    vlSelf->top__DOT__ResultSrcM = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2636709109389874938ull);
    vlSelf->top__DOT__PCSrcD = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3648403547405456555ull);
    vlSelf->top__DOT__RegWriteD = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14491129747607264678ull);
    vlSelf->top__DOT__ReadDataM = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 765929051361557698ull);
    vlSelf->top__DOT__WriteDataE = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14799447559651049639ull);
    vlSelf->top__DOT__InstrD = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9620069753996929236ull);
    vlSelf->top__DOT__EQ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8741399076218739265ull);
    vlSelf->top__DOT__PCF = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1499698722079071566ull);
    vlSelf->top__DOT__PCD = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13836969876524155175ull);
    vlSelf->top__DOT__PCE = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1548021074405266431ull);
    vlSelf->top__DOT__PCPlus4D = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1689773811750263709ull);
    vlSelf->top__DOT__PCPlus4E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17919015232451903065ull);
    vlSelf->top__DOT__ImmSrcD = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2092263011208996595ull);
    vlSelf->top__DOT__ALUResultE = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16707236215018230500ull);
    vlSelf->top__DOT__ALUop1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7319523023759659375ull);
    vlSelf->top__DOT__LT = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 857115146974769278ull);
    vlSelf->top__DOT__LTU = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3521341352882834516ull);
    vlSelf->top__DOT__MemWriteD = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4169468730213000261ull);
    vlSelf->top__DOT__SizeWriteD = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14209088544942278285ull);
    vlSelf->top__DOT__LoadSizeD = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7913213204879293154ull);
    vlSelf->top__DOT__LoadUnsignedD = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15540594205404504506ull);
    vlSelf->top__DOT__flush_d_exec = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5808955309334055271ull);
    vlSelf->top__DOT__flush_f_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7722373944519545348ull);
    vlSelf->top__DOT__F_Write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4602702374761957903ull);
    vlSelf->top__DOT__PCWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4235489034077078341ull);
    vlSelf->top__DOT__ALUCtrlD = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17877842606319280293ull);
    vlSelf->top__DOT__ALUSrcD = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8778465886642546395ull);
    vlSelf->top__DOT__ALUSrc2D = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18054116623308324427ull);
    vlSelf->top__DOT__RegWriteE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9462670231346778448ull);
    vlSelf->top__DOT__ResultSrcE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11174536794639286613ull);
    vlSelf->top__DOT__MemWriteE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16716598180766499274ull);
    vlSelf->top__DOT__ALUCtrlE = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11754365982714370103ull);
    vlSelf->top__DOT__ALUSrcE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11181919478648168636ull);
    vlSelf->top__DOT__SizeWriteE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14230980481796371136ull);
    vlSelf->top__DOT__LoadSizeE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5773931076633205390ull);
    vlSelf->top__DOT__LoadUnsignedE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3120020853448195282ull);
    vlSelf->top__DOT__ALUSrc2E = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8724283863832735516ull);
    vlSelf->top__DOT__PCSrcE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16664425339223109770ull);
    vlSelf->top__DOT__PCPlus4M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1808465483755200769ull);
    vlSelf->top__DOT__RdM = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4931853501079124544ull);
    vlSelf->top__DOT__ALUResultM = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4533500146505124013ull);
    vlSelf->top__DOT__WriteDataM = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1820429550575785515ull);
    vlSelf->top__DOT__RegWriteM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17492581315858284205ull);
    vlSelf->top__DOT__MemWriteM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16950395295672946488ull);
    vlSelf->top__DOT__SizeWriteM = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3711114087573160306ull);
    vlSelf->top__DOT__LoadSizeM = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7018191531810700317ull);
    vlSelf->top__DOT__LoadUnsignedM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7504120638338792534ull);
    vlSelf->top__DOT__RegWriteW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18254132556422318689ull);
    vlSelf->top__DOT__ResultSrcW = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18067638581065618003ull);
    vlSelf->top__DOT__ALUResultW = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1899670509185847296ull);
    vlSelf->top__DOT__ReadDataW = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4499847687678764649ull);
    vlSelf->top__DOT__RdW = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6491962212237722854ull);
    vlSelf->top__DOT__PCPlus4W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14206885467538110331ull);
    vlSelf->top__DOT__ResultW = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1531711676458331592ull);
    vlSelf->top__DOT__ForwardAE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7532915122060517123ull);
    vlSelf->top__DOT__ForwardBE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11894503611216089228ull);
    vlSelf->top__DOT__SrcBE = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13501379896042939910ull);
    vlSelf->top__DOT__hazard_unit__DOT__wStall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3177852877659344714ull);
    for (int __Vi0 = 0; __Vi0 < 131072; ++__Vi0) {
        vlSelf->top__DOT__Instr_Mem__DOT__rom_array[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12021493300266853136ull);
    }
    vlSelf->top__DOT__pc_block__DOT__branch_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16680957803800858285ull);
    vlSelf->top__DOT__pc_block__DOT__inc_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10877981526100293718ull);
    vlSelf->top__DOT__pc_block__DOT__internal_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8756650703667310241ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__regfile_array[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10498205129632059563ull);
    }
    for (int __Vi0 = 0; __Vi0 < 131072; ++__Vi0) {
        vlSelf->top__DOT__datamem__DOT__ram_array[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14682252443410734681ull);
    }
    vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8105111159441969801ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
