// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_INLINE_OPT void Vdut___024root___sequent__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0;
    // Body
    __Vdlyvset__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0 = 0U;
    __Vdlyvset__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 0U;
    if (vlSelf->top__DOT__MemWrite) {
        if (vlSelf->top__DOT__ByteWrite) {
            __Vdlyvval__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0 
                = (0xffU & vlSelf->top__DOT__Reg_and_ALU_block__DOT__regOp2);
            __Vdlyvset__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0 = 1U;
            __Vdlyvdim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0 
                = (0x1ffffU & vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU);
        }
    }
    if (vlSelf->top__DOT__RegWrite) {
        __Vdlyvval__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 
            = ((0U == (IData)(vlSelf->top__DOT__ResultSrc))
                ? vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU
                : ((1U == (IData)(vlSelf->top__DOT__ResultSrc))
                    ? vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem
                    : ((2U == (IData)(vlSelf->top__DOT__ResultSrc))
                        ? ((IData)(4U) + vlSelf->top__DOT__pc_block__DOT__internal_pc)
                        : 0U)));
        __Vdlyvset__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 1U;
        __Vdlyvdim0__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 
            = (0x1fU & (vlSelf->top__DOT__instr >> 7U));
    }
    if (__Vdlyvset__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0) {
        vlSelf->top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array[__Vdlyvdim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0] 
            = __Vdlyvval__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0;
    }
    if (__Vdlyvset__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0) {
        vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[__Vdlyvdim0__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0] 
            = __Vdlyvval__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    }
    vlSelf->top__DOT__pc_block__DOT__internal_pc = 
        ((IData)(vlSelf->rst) ? 0U : ((0U == (IData)(vlSelf->top__DOT__PCSrc))
                                       ? vlSelf->top__DOT__pc_block__DOT__inc_pc
                                       : ((1U == (IData)(vlSelf->top__DOT__PCSrc))
                                           ? vlSelf->top__DOT__pc_block__DOT__branch_pc
                                           : ((2U == (IData)(vlSelf->top__DOT__PCSrc))
                                               ? vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU
                                               : vlSelf->top__DOT__pc_block__DOT__inc_pc))));
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
}

VL_INLINE_OPT void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop1 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [(0x1fU & (vlSelf->top__DOT__instr >> 0xfU))];
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__regOp2 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [(0x1fU & (vlSelf->top__DOT__instr >> 0x14U))];
    vlSelf->a0 = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0xaU];
    vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0U] = 0U;
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

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vdut___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vdut___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData Vdut___024root___change_request_1(Vdut___024root* vlSelf);

VL_INLINE_OPT QData Vdut___024root___change_request(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___change_request\n"); );
    // Body
    return (Vdut___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vdut___024root___change_request_1(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
               [0U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
               [0U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [1U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [1U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [2U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [2U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [3U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [3U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [4U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [4U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [5U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [5U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [6U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [6U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [7U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [7U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [8U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [8U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [9U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [9U])
        || (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xaU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xaU])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xbU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xbU])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xcU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xcU])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xdU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xdU])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xeU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xeU])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xfU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0xfU])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x10U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x10U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x11U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x11U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x12U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x12U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x13U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x13U])
        || (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x14U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x14U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x15U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x15U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x16U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x16U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x17U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x17U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x18U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x18U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x19U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x19U])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1aU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1aU])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1bU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1bU])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1cU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1cU])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1dU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1dU])
        || (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1eU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1eU])
         | (vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1fU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
            [0x1fU]));
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [1U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [1U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [2U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [2U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [3U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [3U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [4U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [4U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [5U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [5U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [6U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [6U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [7U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [7U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [8U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [8U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [9U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [9U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xaU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xaU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xbU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xbU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xcU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xcU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xdU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xdU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xeU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xeU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xfU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0xfU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x10U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x10U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x11U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x11U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x12U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x12U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x13U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x13U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x14U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x14U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x15U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x15U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x16U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x16U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x17U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x17U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x18U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x18U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x19U] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x19U]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1aU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1aU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1bU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1bU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1cU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1cU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1dU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1dU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1eU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1eU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1fU] ^ vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
                               [0x1fU]))) VL_DBG_MSGF("        CHANGE: /home/kkt24/Documents/iac/Team5/rtl/regfile.sv:16\n"); );
    // Final
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[1U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [1U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[2U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [2U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[3U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [3U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[4U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [4U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[5U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [5U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[6U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [6U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[7U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [7U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[8U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [8U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[9U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [9U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0xaU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0xaU];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0xbU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0xbU];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0xcU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0xcU];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0xdU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0xdU];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0xeU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0xeU];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0xfU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0xfU];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x10U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x10U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x11U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x11U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x12U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x12U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x13U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x13U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x14U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x14U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x15U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x15U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x16U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x16U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x17U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x17U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x18U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x18U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x19U] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x19U];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x1aU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x1aU];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x1bU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x1bU];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x1cU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x1cU];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x1dU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x1dU];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x1eU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x1eU];
    vlSelf->__Vchglast__TOP__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0x1fU] 
        = vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0x1fU];
    return __req;
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->__pinNumber4 & 0xfeU))) {
        Verilated::overWidthError("__pinNumber4");}
}
#endif  // VL_DEBUG
