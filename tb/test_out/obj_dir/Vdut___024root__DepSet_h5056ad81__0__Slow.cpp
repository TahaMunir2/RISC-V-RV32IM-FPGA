// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___initial__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___initial__TOP__0\n"); );
    // Init
    VlWide<6>/*191:0*/ __Vtemp_h6814dc49__0;
    VlWide<3>/*95:0*/ __Vtemp_h3a032bfe__0;
    // Body
    VL_WRITEF("Loading ram.\n");
    __Vtemp_h6814dc49__0[0U] = 0x2e6d656dU;
    __Vtemp_h6814dc49__0[1U] = 0x7369616eU;
    __Vtemp_h6814dc49__0[2U] = 0x67617573U;
    __Vtemp_h6814dc49__0[3U] = 0x6e63652fU;
    __Vtemp_h6814dc49__0[4U] = 0x66657265U;
    __Vtemp_h6814dc49__0[5U] = 0x7265U;
    VL_READMEM_N(true, 8, 131072, 0, VL_CVT_PACK_STR_NW(6, __Vtemp_h6814dc49__0)
                 ,  &(vlSelf->top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array)
                 , 0x10000U, ~0ULL);
    VL_WRITEF("Loading rom. \n");
    __Vtemp_h3a032bfe__0[0U] = 0x2e686578U;
    __Vtemp_h3a032bfe__0[1U] = 0x6772616dU;
    __Vtemp_h3a032bfe__0[2U] = 0x70726fU;
    VL_READMEM_N(true, 8, 131072, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h3a032bfe__0)
                 ,  &(vlSelf->top__DOT__Instr_Mem__DOT__rom_array)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vdut___024root___settle__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__pc_block__DOT__inc_pc = ((IData)(4U) 
                                               + vlSelf->top__DOT__pc_block__DOT__internal_pc);
    vlSelf->top__DOT__instr = ((vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                [(0x1ffffU & ((IData)(3U) 
                                              + vlSelf->top__DOT__pc_block__DOT__internal_pc))] 
                                << 0x18U) | ((vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                              [(0x1ffffU 
                                                & ((IData)(2U) 
                                                   + vlSelf->top__DOT__pc_block__DOT__internal_pc))] 
                                              << 0x10U) 
                                             | ((vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                                 [(0x1ffffU 
                                                   & ((IData)(1U) 
                                                      + vlSelf->top__DOT__pc_block__DOT__internal_pc))] 
                                                 << 8U) 
                                                | vlSelf->top__DOT__Instr_Mem__DOT__rom_array
                                                [(0x1ffffU 
                                                  & vlSelf->top__DOT__pc_block__DOT__internal_pc)])));
    vlSelf->top__DOT__MemWrite = 0U;
    vlSelf->top__DOT__ResultSrc = 0U;
    vlSelf->top__DOT__RegWrite = 0U;
    vlSelf->top__DOT__ByteWrite = 0U;
    vlSelf->top__DOT__ALUCtrl = 0U;
    vlSelf->top__DOT__ALUSrc = 0U;
    if ((0x13U == (0x7fU & vlSelf->top__DOT__instr))) {
        if ((0U == (7U & (vlSelf->top__DOT__instr >> 0xcU)))) {
            vlSelf->top__DOT__RegWrite = 1U;
            vlSelf->top__DOT__ALUCtrl = 0U;
            vlSelf->top__DOT__ALUSrc = 1U;
        }
    } else {
        if ((0x63U != (0x7fU & vlSelf->top__DOT__instr))) {
            if ((0x33U == (0x7fU & vlSelf->top__DOT__instr))) {
                if ((0U == (7U & (vlSelf->top__DOT__instr 
                                  >> 0xcU)))) {
                    if ((0U == (vlSelf->top__DOT__instr 
                                >> 0x19U))) {
                        vlSelf->top__DOT__RegWrite = 1U;
                        vlSelf->top__DOT__ALUSrc = 0U;
                    }
                }
            } else if ((3U == (0x7fU & vlSelf->top__DOT__instr))) {
                if ((2U == (7U & (vlSelf->top__DOT__instr 
                                  >> 0xcU)))) {
                    vlSelf->top__DOT__RegWrite = 1U;
                    vlSelf->top__DOT__ALUSrc = 1U;
                } else if ((4U == (7U & (vlSelf->top__DOT__instr 
                                         >> 0xcU)))) {
                    vlSelf->top__DOT__RegWrite = 1U;
                    vlSelf->top__DOT__ALUSrc = 1U;
                }
            } else if ((0x67U == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__RegWrite = 1U;
                vlSelf->top__DOT__ALUSrc = 1U;
            } else {
                if ((0x23U != (0x7fU & vlSelf->top__DOT__instr))) {
                    if ((0x6fU == (0x7fU & vlSelf->top__DOT__instr))) {
                        vlSelf->top__DOT__RegWrite = 1U;
                    } else if ((0x37U == (0x7fU & vlSelf->top__DOT__instr))) {
                        vlSelf->top__DOT__RegWrite = 1U;
                    }
                }
                if ((0x23U == (0x7fU & vlSelf->top__DOT__instr))) {
                    vlSelf->top__DOT__ALUSrc = 1U;
                } else if ((0x6fU == (0x7fU & vlSelf->top__DOT__instr))) {
                    vlSelf->top__DOT__ALUSrc = 0U;
                } else if ((0x37U == (0x7fU & vlSelf->top__DOT__instr))) {
                    vlSelf->top__DOT__ALUSrc = 1U;
                }
            }
        }
        if ((0x63U == (0x7fU & vlSelf->top__DOT__instr))) {
            if ((1U == (7U & (vlSelf->top__DOT__instr 
                              >> 0xcU)))) {
                vlSelf->top__DOT__ALUCtrl = 1U;
            }
        } else if ((0x33U == (0x7fU & vlSelf->top__DOT__instr))) {
            if ((0U == (7U & (vlSelf->top__DOT__instr 
                              >> 0xcU)))) {
                if ((0U == (vlSelf->top__DOT__instr 
                            >> 0x19U))) {
                    vlSelf->top__DOT__ALUCtrl = 0U;
                }
            }
        } else if ((3U != (0x7fU & vlSelf->top__DOT__instr))) {
            if ((0x67U == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__ALUCtrl = 0U;
            } else if ((0x23U == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__ALUCtrl = 0U;
            } else if ((0x6fU == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__ALUCtrl = 0U;
            } else if ((0x37U == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__ALUCtrl = 4U;
            }
        }
    }
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop1 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [(0x1fU & (vlSelf->top__DOT__instr >> 0xfU))];
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__regOp2 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [(0x1fU & (vlSelf->top__DOT__instr >> 0x14U))];
    vlSelf->a0 = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0xaU];
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0U] = 0U;
    vlSelf->top__DOT__ImmSrc = 0U;
    if ((0x13U != (0x7fU & vlSelf->top__DOT__instr))) {
        if ((0x63U != (0x7fU & vlSelf->top__DOT__instr))) {
            if ((0x33U != (0x7fU & vlSelf->top__DOT__instr))) {
                if ((3U != (0x7fU & vlSelf->top__DOT__instr))) {
                    if ((0x67U != (0x7fU & vlSelf->top__DOT__instr))) {
                        if ((0x23U == (0x7fU & vlSelf->top__DOT__instr))) {
                            vlSelf->top__DOT__MemWrite = 1U;
                        }
                    }
                }
                if ((3U == (0x7fU & vlSelf->top__DOT__instr))) {
                    if ((2U == (7U & (vlSelf->top__DOT__instr 
                                      >> 0xcU)))) {
                        vlSelf->top__DOT__ResultSrc = 1U;
                    } else if ((4U == (7U & (vlSelf->top__DOT__instr 
                                             >> 0xcU)))) {
                        vlSelf->top__DOT__ResultSrc = 1U;
                    }
                    if ((2U != (7U & (vlSelf->top__DOT__instr 
                                      >> 0xcU)))) {
                        if ((4U == (7U & (vlSelf->top__DOT__instr 
                                          >> 0xcU)))) {
                            vlSelf->top__DOT__ByteWrite = 1U;
                        }
                    }
                } else {
                    if ((0x67U == (0x7fU & vlSelf->top__DOT__instr))) {
                        vlSelf->top__DOT__ResultSrc = 2U;
                    } else if ((0x23U != (0x7fU & vlSelf->top__DOT__instr))) {
                        if ((0x6fU == (0x7fU & vlSelf->top__DOT__instr))) {
                            vlSelf->top__DOT__ResultSrc = 2U;
                        }
                    }
                    if ((0x67U != (0x7fU & vlSelf->top__DOT__instr))) {
                        if ((0x23U == (0x7fU & vlSelf->top__DOT__instr))) {
                            vlSelf->top__DOT__ByteWrite = 1U;
                        }
                    }
                }
            }
        }
        if ((0x63U == (0x7fU & vlSelf->top__DOT__instr))) {
            if ((1U == (7U & (vlSelf->top__DOT__instr 
                              >> 0xcU)))) {
                vlSelf->top__DOT__ImmSrc = 2U;
            }
        } else if ((0x33U != (0x7fU & vlSelf->top__DOT__instr))) {
            if ((3U == (0x7fU & vlSelf->top__DOT__instr))) {
                if ((2U == (7U & (vlSelf->top__DOT__instr 
                                  >> 0xcU)))) {
                    vlSelf->top__DOT__ImmSrc = 0U;
                } else if ((4U == (7U & (vlSelf->top__DOT__instr 
                                         >> 0xcU)))) {
                    vlSelf->top__DOT__ImmSrc = 0U;
                }
            } else if ((0x67U == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__ImmSrc = 0U;
            } else if ((0x23U == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__ImmSrc = 1U;
            } else if ((0x6fU == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__ImmSrc = 3U;
            } else if ((0x37U == (0x7fU & vlSelf->top__DOT__instr))) {
                vlSelf->top__DOT__ImmSrc = 4U;
            }
        }
    }
    vlSelf->top__DOT__ImmOp = ((0U == (IData)(vlSelf->top__DOT__ImmSrc))
                                ? (((- (IData)((vlSelf->top__DOT__instr 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelf->top__DOT__instr 
                                                >> 0x14U))
                                : ((1U == (IData)(vlSelf->top__DOT__ImmSrc))
                                    ? (((- (IData)(
                                                   (vlSelf->top__DOT__instr 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       ((0xfe0U & (vlSelf->top__DOT__instr 
                                                   >> 0x14U)) 
                                        | (0x1fU & 
                                           (vlSelf->top__DOT__instr 
                                            >> 7U))))
                                    : ((2U == (IData)(vlSelf->top__DOT__ImmSrc))
                                        ? (((- (IData)(
                                                       (vlSelf->top__DOT__instr 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0x800U 
                                               & (vlSelf->top__DOT__instr 
                                                  << 4U)) 
                                              | ((0x7e0U 
                                                  & (vlSelf->top__DOT__instr 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelf->top__DOT__instr 
                                                       >> 7U)))))
                                        : ((4U == (IData)(vlSelf->top__DOT__ImmSrc))
                                            ? (0xfffff000U 
                                               & vlSelf->top__DOT__instr)
                                            : ((3U 
                                                == (IData)(vlSelf->top__DOT__ImmSrc))
                                                ? (
                                                   ((- (IData)(
                                                               (vlSelf->top__DOT__instr 
                                                                >> 0x1fU))) 
                                                    << 0x14U) 
                                                   | ((0xff000U 
                                                       & vlSelf->top__DOT__instr) 
                                                      | ((0x800U 
                                                          & (vlSelf->top__DOT__instr 
                                                             >> 9U)) 
                                                         | (0x7feU 
                                                            & (vlSelf->top__DOT__instr 
                                                               >> 0x14U)))))
                                                : 0U)))));
    vlSelf->top__DOT__pc_block__DOT__branch_pc = (vlSelf->top__DOT__pc_block__DOT__internal_pc 
                                                  + vlSelf->top__DOT__ImmOp);
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop2 
        = ((IData)(vlSelf->top__DOT__ALUSrc) ? vlSelf->top__DOT__ImmOp
            : vlSelf->top__DOT__Reg_and_ALU_block__DOT__regOp2);
    vlSelf->top__DOT__PCSrc = 0U;
    if ((0x13U != (0x7fU & vlSelf->top__DOT__instr))) {
        if ((0x63U == (0x7fU & vlSelf->top__DOT__instr))) {
            if ((1U == (7U & (vlSelf->top__DOT__instr 
                              >> 0xcU)))) {
                if ((0U != (vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                            - vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop2))) {
                    vlSelf->top__DOT__PCSrc = 1U;
                }
            }
        } else if ((0x33U != (0x7fU & vlSelf->top__DOT__instr))) {
            if ((3U != (0x7fU & vlSelf->top__DOT__instr))) {
                if ((0x67U == (0x7fU & vlSelf->top__DOT__instr))) {
                    vlSelf->top__DOT__PCSrc = 2U;
                } else if ((0x23U != (0x7fU & vlSelf->top__DOT__instr))) {
                    if ((0x6fU == (0x7fU & vlSelf->top__DOT__instr))) {
                        vlSelf->top__DOT__PCSrc = 1U;
                    }
                }
            }
        }
    }
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU 
        = ((4U & (IData)(vlSelf->top__DOT__ALUCtrl))
            ? ((2U & (IData)(vlSelf->top__DOT__ALUCtrl))
                ? 0U : ((1U & (IData)(vlSelf->top__DOT__ALUCtrl))
                         ? 0U : vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop2))
            : ((2U & (IData)(vlSelf->top__DOT__ALUCtrl))
                ? ((1U & (IData)(vlSelf->top__DOT__ALUCtrl))
                    ? (vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                       | vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop2)
                    : (vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                       & vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop2))
                : ((1U & (IData)(vlSelf->top__DOT__ALUCtrl))
                    ? (vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                       - vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop2)
                    : (vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                       + vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop2))));
    if (vlSelf->top__DOT__ByteWrite) {
        vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem 
            = vlSelf->top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
            [(0x1ffffU & vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU)];
    } else {
        vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem 
            = ((0xffffff00U & vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem) 
               | vlSelf->top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
               [(0x1ffffU & vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU)]);
        vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem 
            = ((0xffff00ffU & vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem) 
               | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
                  [(0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU))] 
                  << 8U));
        vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem 
            = ((0xff00ffffU & vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem) 
               | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
                  [(0x1ffffU & ((IData)(2U) + vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU))] 
                  << 0x10U));
        vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem 
            = ((0xffffffU & vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem) 
               | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
                  [(0x1ffffU & ((IData)(3U) + vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU))] 
                  << 0x18U));
    }
}

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    // Body
    Vdut___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    // Body
    Vdut___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vdut___024root___final(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___final\n"); );
}

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->__pinNumber4 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RegWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUCtrl = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ALUSrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ImmSrc = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__PCSrc = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ImmOp = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__MemWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ByteWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ResultSrc = VL_RAND_RESET_I(2);
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->top__DOT__Instr_Mem__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__pc_block__DOT__branch_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc_block__DOT__inc_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc_block__DOT__internal_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__regOp2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
