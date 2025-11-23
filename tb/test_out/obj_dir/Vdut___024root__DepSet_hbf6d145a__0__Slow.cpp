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
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__0 
        = vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array;
    vlSelfRef.__Vtrigprevexpr___TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__1 
        = vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vdut___024root___eval_initial__TOP(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdut___024root___eval_initial__TOP(vlSelf);
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
                 , 0, ~0ULL);
    VL_WRITEF_NX("Loading ram.\n",0);
    __Vtemp_2[0U] = 0x2e6d656dU;
    __Vtemp_2[1U] = 0x7369616eU;
    __Vtemp_2[2U] = 0x67617573U;
    __Vtemp_2[3U] = 0x6e63652fU;
    __Vtemp_2[4U] = 0x66657265U;
    __Vtemp_2[5U] = 0x7265U;
    VL_READMEM_N(true, 8, 131072, 0, VL_CVT_PACK_STR_NW(6, __Vtemp_2)
                 ,  &(vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array)
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
            VL_FATAL_MT("/Users/tahamunir/Downloads/Team5-single-cycle-cpu/rtl/top.sv", 1, "", "Settle region did not converge.");
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
    if ((2ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] top.Reg_and_ALU_block.regfile.regfile_array)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdut___024root___stl_sequent__TOP__0(Vdut___024root* vlSelf);
VL_ATTR_COLD void Vdut___024root____Vm_traceActivitySetAll(Vdut___024root* vlSelf);
void Vdut___024root___act_sequent__TOP__0(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_stl(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_stl\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vdut___024root___stl_sequent__TOP__0(vlSelf);
        Vdut___024root____Vm_traceActivitySetAll(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vdut___024root___act_sequent__TOP__0(vlSelf);
        Vdut___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vdut___024root___stl_sequent__TOP__0(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___stl_sequent__TOP__0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VdfgRegularize_h0dff6736_0_4;
    __VdfgRegularize_h0dff6736_0_4 = 0;
    // Body
    vlSelfRef.top__DOT__pc_block__DOT__inc_pc = ((IData)(4U) 
                                                 + vlSelfRef.top__DOT__pc_block__DOT__internal_pc);
    __VdfgRegularize_h0dff6736_0_4 = (1U & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                            [(0x1ffffU 
                                              & ((IData)(3U) 
                                                 + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                            >> 7U));
    vlSelfRef.top__DOT__control__DOT__funct7 = (0x7fU 
                                                & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                   [
                                                   (0x1ffffU 
                                                    & ((IData)(3U) 
                                                       + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                   >> 1U));
    vlSelfRef.top__DOT__control__DOT__funct3 = (7U 
                                                & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                   [
                                                   (0x1ffffU 
                                                    & ((IData)(1U) 
                                                       + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                   >> 4U));
    vlSelfRef.top__DOT__control__DOT__op = (0x7fU & 
                                            vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                            [(0x1ffffU 
                                              & vlSelfRef.top__DOT__pc_block__DOT__internal_pc)]);
    vlSelfRef.__VdfgRegularize_h7cd686f0_0_0 = ((vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                 [(0x1ffffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                 << 8U) 
                                                | vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                [(0x1ffffU 
                                                  & vlSelfRef.top__DOT__pc_block__DOT__internal_pc)]);
    vlSelfRef.top__DOT__MemWrite = 0U;
    vlSelfRef.top__DOT__ResultSrc = 0U;
    vlSelfRef.top__DOT__RegWrite = 0U;
    vlSelfRef.top__DOT__ByteWrite = 0U;
    vlSelfRef.top__DOT__ALUCtrl = 0U;
    vlSelfRef.top__DOT__ALUSrc = 0U;
    if ((0x13U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
        if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            vlSelfRef.top__DOT__RegWrite = 1U;
            vlSelfRef.top__DOT__ALUCtrl = 0U;
            vlSelfRef.top__DOT__ALUSrc = 1U;
        }
    } else {
        if ((0x63U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            if ((0x33U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                        vlSelfRef.top__DOT__RegWrite = 1U;
                        vlSelfRef.top__DOT__ALUSrc = 0U;
                    }
                }
            } else if ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                if ((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__RegWrite = 1U;
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                } else if ((4U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__RegWrite = 1U;
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                }
            } else if ((0x67U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__RegWrite = 1U;
                vlSelfRef.top__DOT__ALUSrc = 1U;
            } else {
                if ((0x23U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                    if ((0x6fU == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                        vlSelfRef.top__DOT__RegWrite = 1U;
                    } else if ((0x37U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                        vlSelfRef.top__DOT__RegWrite = 1U;
                    }
                }
                if ((0x23U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                } else if ((0x6fU == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                    vlSelfRef.top__DOT__ALUSrc = 0U;
                } else if ((0x37U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                }
            }
        }
        if ((0x63U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            if ((1U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                vlSelfRef.top__DOT__ALUCtrl = 1U;
            }
        } else if ((0x33U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                    vlSelfRef.top__DOT__ALUCtrl = 0U;
                }
            }
        } else if ((3U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            if ((0x67U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__ALUCtrl = 0U;
            } else if ((0x23U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__ALUCtrl = 0U;
            } else if ((0x6fU == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__ALUCtrl = 0U;
            } else if ((0x37U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__ALUCtrl = 4U;
            }
        }
    }
    vlSelfRef.top__DOT__ImmSrc = 0U;
    if ((0x13U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
        if ((0x63U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            if ((0x33U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                if ((3U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                    if ((0x67U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                        if ((0x23U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                            vlSelfRef.top__DOT__MemWrite = 1U;
                        }
                    }
                }
                if ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                    if ((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                        vlSelfRef.top__DOT__ResultSrc = 1U;
                    } else if ((4U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                        vlSelfRef.top__DOT__ResultSrc = 1U;
                    }
                    if ((2U != (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                        if ((4U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                            vlSelfRef.top__DOT__ByteWrite = 1U;
                        }
                    }
                } else {
                    if ((0x67U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                        vlSelfRef.top__DOT__ResultSrc = 2U;
                    } else if ((0x23U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                        if ((0x6fU == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                            vlSelfRef.top__DOT__ResultSrc = 2U;
                        }
                    }
                    if ((0x67U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                        if ((0x23U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                            vlSelfRef.top__DOT__ByteWrite = 1U;
                        }
                    }
                }
            }
        }
        if ((0x63U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            if ((1U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                vlSelfRef.top__DOT__ImmSrc = 2U;
            }
        } else if ((0x33U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            if ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                if ((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__ImmSrc = 0U;
                } else if ((4U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__ImmSrc = 0U;
                }
            } else if ((0x67U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__ImmSrc = 0U;
            } else if ((0x23U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__ImmSrc = 1U;
            } else if ((0x6fU == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__ImmSrc = 3U;
            } else if ((0x37U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__ImmSrc = 4U;
            }
        }
    }
    vlSelfRef.__VdfgRegularize_h7cd686f0_0_1 = ((vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                 [(0x1ffffU 
                                                   & ((IData)(2U) 
                                                      + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                 << 0x10U) 
                                                | (IData)(vlSelfRef.__VdfgRegularize_h7cd686f0_0_0));
    vlSelfRef.top__DOT__instr = ((vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                  [(0x1ffffU & ((IData)(3U) 
                                                + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                  << 0x18U) | vlSelfRef.__VdfgRegularize_h7cd686f0_0_1);
    vlSelfRef.top__DOT__ImmOp = ((0U == (IData)(vlSelfRef.top__DOT__ImmSrc))
                                  ? (((- (IData)((IData)(__VdfgRegularize_h0dff6736_0_4))) 
                                      << 0xcU) | (vlSelfRef.top__DOT__instr 
                                                  >> 0x14U))
                                  : ((1U == (IData)(vlSelfRef.top__DOT__ImmSrc))
                                      ? (((- (IData)((IData)(__VdfgRegularize_h0dff6736_0_4))) 
                                          << 0xcU) 
                                         | (((IData)(vlSelfRef.top__DOT__control__DOT__funct7) 
                                             << 5U) 
                                            | (0x1fU 
                                               & ((IData)(vlSelfRef.__VdfgRegularize_h7cd686f0_0_0) 
                                                  >> 7U))))
                                      : ((2U == (IData)(vlSelfRef.top__DOT__ImmSrc))
                                          ? (((- (IData)((IData)(__VdfgRegularize_h0dff6736_0_4))) 
                                              << 0xcU) 
                                             | ((0x800U 
                                                 & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                    [
                                                    (0x1ffffU 
                                                     & vlSelfRef.top__DOT__pc_block__DOT__internal_pc)] 
                                                    << 4U)) 
                                                | ((0x7e0U 
                                                    & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                       [
                                                       (0x1ffffU 
                                                        & ((IData)(3U) 
                                                           + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                       << 4U)) 
                                                   | (0x1eU 
                                                      & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                         [
                                                         (0x1ffffU 
                                                          & ((IData)(1U) 
                                                             + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                         << 1U)))))
                                          : ((4U == (IData)(vlSelfRef.top__DOT__ImmSrc))
                                              ? (0xfffff000U 
                                                 & vlSelfRef.top__DOT__instr)
                                              : ((3U 
                                                  == (IData)(vlSelfRef.top__DOT__ImmSrc))
                                                  ? 
                                                 (((- (IData)((IData)(__VdfgRegularize_h0dff6736_0_4))) 
                                                   << 0x14U) 
                                                  | (((0xff000U 
                                                       & vlSelfRef.__VdfgRegularize_h7cd686f0_0_1) 
                                                      | (0x800U 
                                                         & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                            [
                                                            (0x1ffffU 
                                                             & ((IData)(2U) 
                                                                + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                            << 7U))) 
                                                     | (0x7feU 
                                                        & (vlSelfRef.top__DOT__instr 
                                                           >> 0x14U))))
                                                  : 0U)))));
    vlSelfRef.top__DOT__pc_block__DOT__branch_pc = 
        (vlSelfRef.top__DOT__ImmOp + vlSelfRef.top__DOT__pc_block__DOT__internal_pc);
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
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] top.Reg_and_ALU_block.regfile.regfile_array)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] top.Reg_and_ALU_block.regfile.regfile_array)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
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
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
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
    vlSelf->__pinNumber4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10603382051978132956ull);
    vlSelf->top__DOT__instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3126867797622976717ull);
    vlSelf->top__DOT__RegWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7158566308477739165ull);
    vlSelf->top__DOT__ALUCtrl = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7430030758785238460ull);
    vlSelf->top__DOT__ALUSrc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8440975430747751651ull);
    vlSelf->top__DOT__ImmSrc = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13437082825012647493ull);
    vlSelf->top__DOT__PCSrc = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16393859846596586319ull);
    vlSelf->top__DOT__ImmOp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5544505552582705990ull);
    vlSelf->top__DOT__MemWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10293806070728862887ull);
    vlSelf->top__DOT__ByteWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10670461586470413ull);
    vlSelf->top__DOT__ALU_OUT = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 863020417667182986ull);
    vlSelf->top__DOT__ResultSrc = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2157269559853023023ull);
    vlSelf->top__DOT__control__DOT__op = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 8119225025422592504ull);
    vlSelf->top__DOT__control__DOT__funct3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6760023891245820589ull);
    vlSelf->top__DOT__control__DOT__funct7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 14294703430172103263ull);
    for (int __Vi0 = 0; __Vi0 < 131072; ++__Vi0) {
        vlSelf->top__DOT__Instr_Mem__DOT__rom_array[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12021493300266853136ull);
    }
    vlSelf->top__DOT__pc_block__DOT__branch_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16680957803800858285ull);
    vlSelf->top__DOT__pc_block__DOT__inc_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10877981526100293718ull);
    vlSelf->top__DOT__pc_block__DOT__internal_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8756650703667310241ull);
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9559669336106318254ull);
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1565707993100267517ull);
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__regOp2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3393366445619265979ull);
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3611643628581580651ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11061210215577431743ull);
    }
    for (int __Vi0 = 0; __Vi0 < 131072; ++__Vi0) {
        vlSelf->top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10079149111981843563ull);
    }
    vlSelf->__VdfgRegularize_h7cd686f0_0_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6622935034393947247ull);
    vlSelf->__VdfgRegularize_h7cd686f0_0_1 = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14428114705003910083ull);
    vlSelf->__VdfgRegularize_h0dff6736_0_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3742074415316355320ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__Vtrigprevexpr___TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__0[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11680558557669906918ull);
    }
    vlSelf->__VstlDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->__Vtrigprevexpr___TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__1[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10949846300981903194ull);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
