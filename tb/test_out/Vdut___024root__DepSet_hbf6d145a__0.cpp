// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

void Vdut___024root___act_sequent__TOP__0(Vdut___024root* vlSelf);

void Vdut___024root___eval_act(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_act\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vdut___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vdut___024root___act_sequent__TOP__0(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___act_sequent__TOP__0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regOp 
        = vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [(0x1fU & (vlSelfRef.__VdfgRegularize_h7cd686f0_0_1 
                   >> 0xfU))];
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regOp2 
        = vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [(0x1fU & (vlSelfRef.top__DOT__instr >> 0x14U))];
    vlSelfRef.a0 = vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0xaU];
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0U] = 0U;
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1 
        = ((IData)(vlSelfRef.top__DOT__ALUsrc2) ? ((IData)(4U) 
                                                   + vlSelfRef.top__DOT__pc_block__DOT__internal_pc)
            : vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regOp);
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2 
        = ((IData)(vlSelfRef.top__DOT__ALUSrc) ? vlSelfRef.top__DOT__ImmOp
            : vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regOp2);
    vlSelfRef.top__DOT__EQ = (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                              == vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2);
    vlSelfRef.top__DOT__LT = VL_LTS_III(32, vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1, vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2);
    vlSelfRef.top__DOT__LTU = (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                               < vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2);
    vlSelfRef.top__DOT__ALU_OUT = ((4U & (IData)(vlSelfRef.top__DOT____Vcellout__control__ALUCtrl))
                                    ? ((2U & (IData)(vlSelfRef.top__DOT____Vcellout__control__ALUCtrl))
                                        ? ((1U & (IData)(vlSelfRef.top__DOT____Vcellout__control__ALUCtrl))
                                            ? VL_SHIFTRS_III(32,32,32, vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1, 
                                                             (0x1fU 
                                                              & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2))
                                            : VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1, 
                                                            (0x1fU 
                                                             & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2)))
                                        : ((1U & (IData)(vlSelfRef.top__DOT____Vcellout__control__ALUCtrl))
                                            ? VL_SHIFTL_III(32,32,32, vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1, 
                                                            (0x1fU 
                                                             & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2))
                                            : (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                                               ^ vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2)))
                                    : ((2U & (IData)(vlSelfRef.top__DOT____Vcellout__control__ALUCtrl))
                                        ? ((1U & (IData)(vlSelfRef.top__DOT____Vcellout__control__ALUCtrl))
                                            ? (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                                               | vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2)
                                            : (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                                               & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2))
                                        : ((1U & (IData)(vlSelfRef.top__DOT____Vcellout__control__ALUCtrl))
                                            ? (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                                               - vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2)
                                            : (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                                               + vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2))));
    vlSelfRef.top__DOT__PCSrc = 0U;
    if (((((((((0x37U == (IData)(vlSelfRef.top__DOT__control__DOT__op)) 
               | (0x17U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
              | (0x6fU == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
             | (0x67U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
            | (0x63U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
           | (3U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
          | (0x23U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
         | (0x13U == (IData)(vlSelfRef.top__DOT__control__DOT__op)))) {
        if ((0x37U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            vlSelfRef.top__DOT__PCSrc = 0U;
        } else if ((0x17U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            vlSelfRef.top__DOT__PCSrc = 0U;
        } else if ((0x6fU == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            vlSelfRef.top__DOT__PCSrc = 1U;
        } else if ((0x67U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            vlSelfRef.top__DOT__PCSrc = 2U;
        } else if ((0x63U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            vlSelfRef.top__DOT__PCSrc = ((4U & (IData)(vlSelfRef.top__DOT__control__DOT__funct3))
                                          ? ((2U & (IData)(vlSelfRef.top__DOT__control__DOT__funct3))
                                              ? ((1U 
                                                  & (IData)(vlSelfRef.top__DOT__control__DOT__funct3))
                                                  ? 
                                                 ((IData)(vlSelfRef.top__DOT__LTU)
                                                   ? 0U
                                                   : 1U)
                                                  : 
                                                 ((IData)(vlSelfRef.top__DOT__LTU)
                                                   ? 1U
                                                   : 0U))
                                              : ((1U 
                                                  & (IData)(vlSelfRef.top__DOT__control__DOT__funct3))
                                                  ? 
                                                 ((IData)(vlSelfRef.top__DOT__LT)
                                                   ? 0U
                                                   : 1U)
                                                  : 
                                                 ((IData)(vlSelfRef.top__DOT__LT)
                                                   ? 1U
                                                   : 0U)))
                                          : ((2U & (IData)(vlSelfRef.top__DOT__control__DOT__funct3))
                                              ? 0U : 
                                             ((1U & (IData)(vlSelfRef.top__DOT__control__DOT__funct3))
                                               ? ((IData)(vlSelfRef.top__DOT__EQ)
                                                   ? 0U
                                                   : 1U)
                                               : ((IData)(vlSelfRef.top__DOT__EQ)
                                                   ? 1U
                                                   : 0U))));
        } else if ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            vlSelfRef.top__DOT__PCSrc = 0U;
        } else if ((0x23U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            } else if ((1U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            } else if ((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            }
        } else if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            vlSelfRef.top__DOT__PCSrc = 0U;
        } else if ((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            vlSelfRef.top__DOT__PCSrc = 0U;
        } else if ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            vlSelfRef.top__DOT__PCSrc = 0U;
        } else if ((4U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            vlSelfRef.top__DOT__PCSrc = 0U;
        } else if ((6U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            vlSelfRef.top__DOT__PCSrc = 0U;
        } else if ((7U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            vlSelfRef.top__DOT__PCSrc = 0U;
        } else if ((1U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            }
        } else if ((5U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            } else if ((0x20U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            }
        }
    } else if ((0x33U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
        if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            } else if ((0x20U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            }
        } else if ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            }
        } else if ((4U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            }
        } else if ((5U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            } else if ((0x20U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            }
        } else if ((6U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            }
        } else if ((7U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__PCSrc = 0U;
            }
        }
    }
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffffff00U & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
           [(0x1ffffU & vlSelfRef.top__DOT__ALU_OUT)]);
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffff00ffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__ALU_OUT))] 
              << 8U));
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xff00ffffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(2U) + vlSelfRef.top__DOT__ALU_OUT))] 
              << 0x10U));
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffffffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(3U) + vlSelfRef.top__DOT__ALU_OUT))] 
              << 0x18U));
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem 
        = ((0U == (IData)(vlSelfRef.top__DOT__LoadSize))
            ? ((IData)(vlSelfRef.top__DOT__LoadUnsigned)
                ? (0xffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data)
                : (((- (IData)((1U & (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data 
                                      >> 7U)))) << 8U) 
                   | (0xffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data)))
            : ((1U == (IData)(vlSelfRef.top__DOT__LoadSize))
                ? ((IData)(vlSelfRef.top__DOT__LoadUnsigned)
                    ? (0xffffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data)
                    : (((- (IData)((1U & (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data 
                                          >> 0xfU)))) 
                        << 0x10U) | (0xffffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data)))
                : vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__unnamedblk1__DOT__data));
}

void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf);

void Vdut___024root___eval_nba(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_nba\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VdfgRegularize_h0dff6736_0_4;
    __VdfgRegularize_h0dff6736_0_4 = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    __VdlySet__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0;
    __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0;
    __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0;
    __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1;
    __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1;
    __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1;
    __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v2;
    __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v2 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v2;
    __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v2 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3;
    __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3;
    __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3;
    __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v4;
    __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v4 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v4;
    __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v4 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v5;
    __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v5 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v5;
    __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v5 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v6;
    __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v6 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v6;
    __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v6 = 0;
    // Body
    __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0 = 0U;
    __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1 = 0U;
    __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3 = 0U;
    __VdlySet__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 0U;
    if (vlSelfRef.top__DOT__MemWrite) {
        if ((0U == (IData)(vlSelfRef.top__DOT__SizeWrite))) {
            __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0 
                = (0xffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regOp2);
            __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0 
                = (0x1ffffU & vlSelfRef.top__DOT__ALU_OUT);
            __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0 = 1U;
        } else if ((1U == (IData)(vlSelfRef.top__DOT__SizeWrite))) {
            __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1 
                = (0xffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regOp2);
            __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1 
                = (0x1ffffU & vlSelfRef.top__DOT__ALU_OUT);
            __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1 = 1U;
            __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v2 
                = (0xffU & (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regOp2 
                            >> 8U));
            __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v2 
                = (0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__ALU_OUT));
        } else if ((2U == (IData)(vlSelfRef.top__DOT__SizeWrite))) {
            __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3 
                = (0xffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regOp2);
            __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3 
                = (0x1ffffU & vlSelfRef.top__DOT__ALU_OUT);
            __VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3 = 1U;
            __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v4 
                = (0xffU & (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regOp2 
                            >> 8U));
            __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v4 
                = (0x1ffffU & ((IData)(1U) + vlSelfRef.top__DOT__ALU_OUT));
            __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v5 
                = (0xffU & (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regOp2 
                            >> 0x10U));
            __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v5 
                = (0x1ffffU & ((IData)(2U) + vlSelfRef.top__DOT__ALU_OUT));
            __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v6 
                = (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regOp2 
                   >> 0x18U);
            __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v6 
                = (0x1ffffU & ((IData)(3U) + vlSelfRef.top__DOT__ALU_OUT));
        }
    }
    if (vlSelfRef.top__DOT__RegWrite) {
        __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 
            = ((0U == (IData)(vlSelfRef.top__DOT__ResultSrc))
                ? vlSelfRef.top__DOT__ALU_OUT : ((1U 
                                                  == (IData)(vlSelfRef.top__DOT__ResultSrc))
                                                  ? vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelfRef.top__DOT__ResultSrc))
                                                   ? 
                                                  ((IData)(4U) 
                                                   + vlSelfRef.top__DOT__pc_block__DOT__internal_pc)
                                                   : 0U)));
        __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 
            = (0x1fU & ((IData)(vlSelfRef.__VdfgRegularize_h7cd686f0_0_0) 
                        >> 7U));
        __VdlySet__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 1U;
    }
    if (__VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0) {
        vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0] 
            = __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v0;
    }
    if (__VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1) {
        vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1] 
            = __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v1;
        vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v2] 
            = __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v2;
    }
    if (__VdlySet__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3) {
        vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3] 
            = __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v3;
        vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v4] 
            = __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v4;
        vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v5] 
            = __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v5;
        vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array[__VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v6] 
            = __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array__v6;
    }
    if (__VdlySet__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0) {
        vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[__VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0] 
            = __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    }
    vlSelfRef.top__DOT__pc_block__DOT__internal_pc 
        = ((IData)(vlSelfRef.rst) ? 0U : ((0U == (IData)(vlSelfRef.top__DOT__PCSrc))
                                           ? vlSelfRef.top__DOT__pc_block__DOT__inc_pc
                                           : ((1U == (IData)(vlSelfRef.top__DOT__PCSrc))
                                               ? vlSelfRef.top__DOT__pc_block__DOT__branch_pc
                                               : ((2U 
                                                   == (IData)(vlSelfRef.top__DOT__PCSrc))
                                                   ? vlSelfRef.top__DOT__ALU_OUT
                                                   : vlSelfRef.top__DOT__pc_block__DOT__inc_pc))));
    vlSelfRef.top__DOT__pc_block__DOT__inc_pc = ((IData)(4U) 
                                                 + vlSelfRef.top__DOT__pc_block__DOT__internal_pc);
    __VdfgRegularize_h0dff6736_0_4 = (1U & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                            [(0x1ffffU 
                                              & ((IData)(3U) 
                                                 + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                            >> 7U));
    vlSelfRef.top__DOT__control__DOT__op = (0x7fU & 
                                            vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                            [(0x1ffffU 
                                              & vlSelfRef.top__DOT__pc_block__DOT__internal_pc)]);
    vlSelfRef.top__DOT__control__DOT__funct3 = (7U 
                                                & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                   [
                                                   (0x1ffffU 
                                                    & ((IData)(1U) 
                                                       + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                   >> 4U));
    vlSelfRef.top__DOT__control__DOT__funct7 = (0x7fU 
                                                & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                   [
                                                   (0x1ffffU 
                                                    & ((IData)(3U) 
                                                       + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                   >> 1U));
    vlSelfRef.__VdfgRegularize_h7cd686f0_0_0 = ((vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                 [(0x1ffffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                 << 8U) 
                                                | vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                [(0x1ffffU 
                                                  & vlSelfRef.top__DOT__pc_block__DOT__internal_pc)]);
    vlSelfRef.top__DOT__SizeWrite = 0U;
    vlSelfRef.top__DOT__LoadSize = 2U;
    vlSelfRef.top__DOT__LoadUnsigned = 0U;
    vlSelfRef.top__DOT__RegWrite = 0U;
    vlSelfRef.top__DOT__ResultSrc = 0U;
    vlSelfRef.top__DOT__MemWrite = 0U;
    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0U;
    vlSelfRef.top__DOT__ALUSrc = 0U;
    vlSelfRef.top__DOT__ALUsrc2 = 0U;
    vlSelfRef.top__DOT__ImmSrc = 0U;
    if (((((((((0x37U == (IData)(vlSelfRef.top__DOT__control__DOT__op)) 
               | (0x17U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
              | (0x6fU == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
             | (0x67U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
            | (0x63U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
           | (3U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
          | (0x23U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) 
         | (0x13U == (IData)(vlSelfRef.top__DOT__control__DOT__op)))) {
        if ((0x37U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            vlSelfRef.top__DOT__SizeWrite = 0U;
            vlSelfRef.top__DOT__RegWrite = 1U;
            vlSelfRef.top__DOT__ResultSrc = 0U;
            vlSelfRef.top__DOT__MemWrite = 0U;
            vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0xaU;
            vlSelfRef.top__DOT__ALUSrc = 1U;
            vlSelfRef.top__DOT__ALUsrc2 = 0U;
            vlSelfRef.top__DOT__ImmSrc = 4U;
        } else if ((0x17U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            vlSelfRef.top__DOT__SizeWrite = 0U;
            vlSelfRef.top__DOT__RegWrite = 1U;
            vlSelfRef.top__DOT__ResultSrc = 0U;
            vlSelfRef.top__DOT__MemWrite = 0U;
            vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0xbU;
            vlSelfRef.top__DOT__ALUSrc = 1U;
            vlSelfRef.top__DOT__ALUsrc2 = 1U;
            vlSelfRef.top__DOT__ImmSrc = 4U;
        } else {
            if ((0x6fU == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__SizeWrite = 0U;
                vlSelfRef.top__DOT__RegWrite = 1U;
                vlSelfRef.top__DOT__ResultSrc = 2U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0U;
                vlSelfRef.top__DOT__ALUSrc = 0U;
                vlSelfRef.top__DOT__ImmSrc = 3U;
            } else if ((0x67U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__SizeWrite = 0U;
                vlSelfRef.top__DOT__RegWrite = 1U;
                vlSelfRef.top__DOT__ResultSrc = 2U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0U;
                vlSelfRef.top__DOT__ALUSrc = 1U;
                vlSelfRef.top__DOT__ImmSrc = 0U;
            } else if ((0x63U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__SizeWrite = 0U;
                vlSelfRef.top__DOT__RegWrite = 0U;
                vlSelfRef.top__DOT__ResultSrc = 0U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                if ((4U & (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 1U;
                    vlSelfRef.top__DOT__ImmSrc = 2U;
                } else if ((2U & (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0U;
                    vlSelfRef.top__DOT__ImmSrc = 0U;
                } else {
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 1U;
                    vlSelfRef.top__DOT__ImmSrc = 2U;
                }
                vlSelfRef.top__DOT__ALUSrc = 0U;
            } else if ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                vlSelfRef.top__DOT__SizeWrite = 0U;
                vlSelfRef.top__DOT__RegWrite = 1U;
                vlSelfRef.top__DOT__ResultSrc = 1U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0U;
                vlSelfRef.top__DOT__ALUSrc = 1U;
                vlSelfRef.top__DOT__ImmSrc = 0U;
            } else if ((0x23U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__SizeWrite = 0U;
                    vlSelfRef.top__DOT__RegWrite = 0U;
                    vlSelfRef.top__DOT__ResultSrc = 0U;
                    vlSelfRef.top__DOT__MemWrite = 1U;
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0U;
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                    vlSelfRef.top__DOT__ImmSrc = 1U;
                } else if ((1U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__SizeWrite = 1U;
                    vlSelfRef.top__DOT__RegWrite = 0U;
                    vlSelfRef.top__DOT__ResultSrc = 0U;
                    vlSelfRef.top__DOT__MemWrite = 1U;
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0U;
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                    vlSelfRef.top__DOT__ImmSrc = 1U;
                } else if ((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__SizeWrite = 2U;
                    vlSelfRef.top__DOT__RegWrite = 0U;
                    vlSelfRef.top__DOT__ResultSrc = 0U;
                    vlSelfRef.top__DOT__MemWrite = 1U;
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0U;
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                    vlSelfRef.top__DOT__ImmSrc = 1U;
                }
            } else {
                vlSelfRef.top__DOT__RegWrite = ((0U 
                                                 == (IData)(vlSelfRef.top__DOT__control__DOT__funct3)) 
                                                || ((2U 
                                                     == (IData)(vlSelfRef.top__DOT__control__DOT__funct3)) 
                                                    || ((3U 
                                                         == (IData)(vlSelfRef.top__DOT__control__DOT__funct3)) 
                                                        || ((4U 
                                                             == (IData)(vlSelfRef.top__DOT__control__DOT__funct3)) 
                                                            || ((6U 
                                                                 == (IData)(vlSelfRef.top__DOT__control__DOT__funct3)) 
                                                                || ((7U 
                                                                     == (IData)(vlSelfRef.top__DOT__control__DOT__funct3)) 
                                                                    || ((1U 
                                                                         == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))
                                                                         ? 
                                                                        (0U 
                                                                         == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))
                                                                         : 
                                                                        ((5U 
                                                                          == (IData)(vlSelfRef.top__DOT__control__DOT__funct3)) 
                                                                         && ((0U 
                                                                              == (IData)(vlSelfRef.top__DOT__control__DOT__funct7)) 
                                                                             || (0x20U 
                                                                                == (IData)(vlSelfRef.top__DOT__control__DOT__funct7)))))))))));
                if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__ResultSrc = 0U;
                    vlSelfRef.top__DOT__MemWrite = 0U;
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0U;
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                    vlSelfRef.top__DOT__ImmSrc = 0U;
                } else if ((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__ResultSrc = 0U;
                    vlSelfRef.top__DOT__MemWrite = 0U;
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 8U;
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                    vlSelfRef.top__DOT__ImmSrc = 0U;
                } else if ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__ResultSrc = 0U;
                    vlSelfRef.top__DOT__MemWrite = 0U;
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 9U;
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                    vlSelfRef.top__DOT__ImmSrc = 0U;
                } else if ((4U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__ResultSrc = 0U;
                    vlSelfRef.top__DOT__MemWrite = 0U;
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 4U;
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                    vlSelfRef.top__DOT__ImmSrc = 0U;
                } else if ((6U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__ResultSrc = 0U;
                    vlSelfRef.top__DOT__MemWrite = 0U;
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 3U;
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                    vlSelfRef.top__DOT__ImmSrc = 0U;
                } else if ((7U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    vlSelfRef.top__DOT__ResultSrc = 0U;
                    vlSelfRef.top__DOT__MemWrite = 0U;
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 2U;
                    vlSelfRef.top__DOT__ALUSrc = 1U;
                    vlSelfRef.top__DOT__ImmSrc = 0U;
                } else if ((1U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                        vlSelfRef.top__DOT__ResultSrc = 0U;
                        vlSelfRef.top__DOT__MemWrite = 0U;
                        vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 5U;
                        vlSelfRef.top__DOT__ALUSrc = 1U;
                        vlSelfRef.top__DOT__ImmSrc = 0U;
                    }
                } else if ((5U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                    if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                        vlSelfRef.top__DOT__ResultSrc = 0U;
                        vlSelfRef.top__DOT__MemWrite = 0U;
                        vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 6U;
                        vlSelfRef.top__DOT__ALUSrc = 1U;
                        vlSelfRef.top__DOT__ImmSrc = 0U;
                    } else if ((0x20U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                        vlSelfRef.top__DOT__ResultSrc = 0U;
                        vlSelfRef.top__DOT__MemWrite = 0U;
                        vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 7U;
                        vlSelfRef.top__DOT__ALUSrc = 1U;
                        vlSelfRef.top__DOT__ImmSrc = 0U;
                    }
                }
            }
            if ((0x6fU != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                if ((0x67U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                    if ((0x63U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__control__DOT__funct3) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                            }
                        }
                    } else if ((3U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                        if ((0x23U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                            } else if ((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                            } else if ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                            } else if ((4U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                            } else if ((6U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                            } else if ((7U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                            } else if ((1U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                                    vlSelfRef.top__DOT__ALUsrc2 = 0U;
                                }
                            } else if ((5U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                                    vlSelfRef.top__DOT__ALUsrc2 = 0U;
                                } else if ((0x20U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                                    vlSelfRef.top__DOT__ALUsrc2 = 0U;
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((0x37U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
            if ((0x17U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                if ((0x6fU != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                    if ((0x67U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                        if ((0x63U != (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                            if ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
                                if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                    vlSelfRef.top__DOT__LoadSize = 0U;
                                    vlSelfRef.top__DOT__LoadUnsigned = 0U;
                                } else if ((1U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                    vlSelfRef.top__DOT__LoadSize = 1U;
                                    vlSelfRef.top__DOT__LoadUnsigned = 0U;
                                } else if ((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                    vlSelfRef.top__DOT__LoadSize = 2U;
                                    vlSelfRef.top__DOT__LoadUnsigned = 0U;
                                } else if ((4U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                    vlSelfRef.top__DOT__LoadSize = 0U;
                                    vlSelfRef.top__DOT__LoadUnsigned = 1U;
                                } else if ((5U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                                    vlSelfRef.top__DOT__LoadSize = 1U;
                                    vlSelfRef.top__DOT__LoadUnsigned = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x33U == (IData)(vlSelfRef.top__DOT__control__DOT__op))) {
        if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            vlSelfRef.top__DOT__RegWrite = ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7)) 
                                            || (0x20U 
                                                == (IData)(vlSelfRef.top__DOT__control__DOT__funct7)));
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__ResultSrc = 0U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 0U;
                vlSelfRef.top__DOT__ALUSrc = 0U;
                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                vlSelfRef.top__DOT__ImmSrc = 0U;
            } else if ((0x20U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__ResultSrc = 0U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 1U;
                vlSelfRef.top__DOT__ALUSrc = 0U;
                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                vlSelfRef.top__DOT__ImmSrc = 0U;
            }
        } else if ((1U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__RegWrite = 1U;
                vlSelfRef.top__DOT__ResultSrc = 0U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 5U;
                vlSelfRef.top__DOT__ALUSrc = 0U;
                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                vlSelfRef.top__DOT__ImmSrc = 0U;
            } else {
                vlSelfRef.top__DOT__RegWrite = 0U;
            }
        } else if ((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__RegWrite = 1U;
                vlSelfRef.top__DOT__ResultSrc = 0U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 8U;
                vlSelfRef.top__DOT__ALUSrc = 0U;
                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                vlSelfRef.top__DOT__ImmSrc = 0U;
            } else {
                vlSelfRef.top__DOT__RegWrite = 0U;
            }
        } else if ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__RegWrite = 1U;
                vlSelfRef.top__DOT__ResultSrc = 0U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 9U;
                vlSelfRef.top__DOT__ALUSrc = 0U;
                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                vlSelfRef.top__DOT__ImmSrc = 0U;
            } else {
                vlSelfRef.top__DOT__RegWrite = 0U;
            }
        } else if ((4U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__RegWrite = 1U;
                vlSelfRef.top__DOT__ResultSrc = 0U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 4U;
                vlSelfRef.top__DOT__ALUSrc = 0U;
                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                vlSelfRef.top__DOT__ImmSrc = 0U;
            } else {
                vlSelfRef.top__DOT__RegWrite = 0U;
            }
        } else if ((5U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            vlSelfRef.top__DOT__RegWrite = ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7)) 
                                            || (0x20U 
                                                == (IData)(vlSelfRef.top__DOT__control__DOT__funct7)));
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__ResultSrc = 0U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 6U;
                vlSelfRef.top__DOT__ALUSrc = 0U;
                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                vlSelfRef.top__DOT__ImmSrc = 0U;
            } else if ((0x20U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__ResultSrc = 0U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 7U;
                vlSelfRef.top__DOT__ALUSrc = 0U;
                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                vlSelfRef.top__DOT__ImmSrc = 0U;
            }
        } else if ((6U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
            if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                vlSelfRef.top__DOT__RegWrite = 1U;
                vlSelfRef.top__DOT__ResultSrc = 0U;
                vlSelfRef.top__DOT__MemWrite = 0U;
                vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 3U;
                vlSelfRef.top__DOT__ALUSrc = 0U;
                vlSelfRef.top__DOT__ALUsrc2 = 0U;
                vlSelfRef.top__DOT__ImmSrc = 0U;
            } else {
                vlSelfRef.top__DOT__RegWrite = 0U;
            }
        } else {
            vlSelfRef.top__DOT__RegWrite = ((7U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3)) 
                                            && (0U 
                                                == (IData)(vlSelfRef.top__DOT__control__DOT__funct7)));
            if ((7U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3))) {
                if ((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct7))) {
                    vlSelfRef.top__DOT__ResultSrc = 0U;
                    vlSelfRef.top__DOT__MemWrite = 0U;
                    vlSelfRef.top__DOT____Vcellout__control__ALUCtrl = 2U;
                    vlSelfRef.top__DOT__ALUSrc = 0U;
                    vlSelfRef.top__DOT__ALUsrc2 = 0U;
                    vlSelfRef.top__DOT__ImmSrc = 0U;
                }
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

void Vdut___024root___eval_triggers__act(Vdut___024root* vlSelf);

bool Vdut___024root___eval_phase__act(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__act\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdut___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdut___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdut___024root___eval_phase__nba(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__nba\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdut___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__nba(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf);
#endif  // VL_DEBUG

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/Users/cyrilabdelnour/Desktop/Team5/rtl/top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vdut___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/Users/cyrilabdelnour/Desktop/Team5/rtl/top.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdut___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdut___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
