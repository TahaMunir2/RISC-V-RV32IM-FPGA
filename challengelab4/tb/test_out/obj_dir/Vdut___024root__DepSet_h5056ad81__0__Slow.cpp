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
    VlWide<5>/*159:0*/ __Vtemp_hbdd2015e__0;
    // Body
    VL_WRITEF("Loading ram.\n");
    __Vtemp_h6814dc49__0[0U] = 0x2e6d656dU;
    __Vtemp_h6814dc49__0[1U] = 0x7369616eU;
    __Vtemp_h6814dc49__0[2U] = 0x67617573U;
    __Vtemp_h6814dc49__0[3U] = 0x6e63652fU;
    __Vtemp_h6814dc49__0[4U] = 0x66657265U;
    __Vtemp_h6814dc49__0[5U] = 0x7265U;
    VL_READMEM_N(true, 8, 131072, 0, VL_CVT_PACK_STR_NW(6, __Vtemp_h6814dc49__0)
                 ,  &(vlSelf->top__DOT__datamem__DOT__ram_array)
                 , 0x10000U, ~0ULL);
    VL_WRITEF("Loading rom. \n");
    __Vtemp_hbdd2015e__0[0U] = 0x2e686578U;
    __Vtemp_hbdd2015e__0[1U] = 0x6772616dU;
    __Vtemp_hbdd2015e__0[2U] = 0x2f70726fU;
    __Vtemp_hbdd2015e__0[3U] = 0x2f72746cU;
    __Vtemp_hbdd2015e__0[4U] = 0x2e2eU;
    VL_READMEM_N(true, 8, 131073, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_hbdd2015e__0)
                 ,  &(vlSelf->top__DOT__Instr_Mem__DOT__rom_array)
                 , 0, ~0ULL);
}

extern const VlUnpacked<CData/*0:0*/, 256> Vdut__ConstPool__TABLE_h382018d6_0;

VL_ATTR_COLD void Vdut___024root___settle__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___settle__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vtableidx1;
    // Body
    vlSelf->a0 = vlSelf->top__DOT__regfile__DOT__regfile_array
        [0xaU];
    vlSelf->top__DOT__regOp2 = vlSelf->top__DOT__regfile__DOT__regfile_array
        [vlSelf->top__DOT__AD2];
    vlSelf->top__DOT__ResultW = ((0U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                  ? vlSelf->top__DOT__ALUResultW
                                  : ((1U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                      ? vlSelf->top__DOT__ReadDataW
                                      : ((2U == (IData)(vlSelf->top__DOT__ResultSrcW))
                                          ? vlSelf->top__DOT__PCPlus4W
                                          : 0U)));
    vlSelf->top__DOT__ForwardBE = 0U;
    if ((((IData)(vlSelf->top__DOT__RegWriteM) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__RdM))) 
         & ((0x1fU & vlSelf->top__DOT__RdM) == (0x1fU 
                                                & vlSelf->top__DOT__RD2_e)))) {
        vlSelf->top__DOT__ForwardBE = 2U;
    } else if ((((IData)(vlSelf->top__DOT__RegWriteW) 
                 & (0U != (0x1fU & vlSelf->top__DOT__RdW))) 
                & ((0x1fU & vlSelf->top__DOT__RdW) 
                   == (0x1fU & vlSelf->top__DOT__RD2_e)))) {
        vlSelf->top__DOT__ForwardBE = 1U;
    }
    vlSelf->top__DOT__ForwardAE = 0U;
    if ((((IData)(vlSelf->top__DOT__RegWriteM) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__RdM))) 
         & ((0x1fU & vlSelf->top__DOT__RdM) == (0x1fU 
                                                & vlSelf->top__DOT__RD1_e)))) {
        vlSelf->top__DOT__ForwardAE = 2U;
    } else if ((((IData)(vlSelf->top__DOT__RegWriteW) 
                 & (0U != (0x1fU & vlSelf->top__DOT__RdW))) 
                & ((0x1fU & vlSelf->top__DOT__RdW) 
                   == (0x1fU & vlSelf->top__DOT__RD1_e)))) {
        vlSelf->top__DOT__ForwardAE = 1U;
    }
    vlSelf->top__DOT__hazard_unit__DOT__wStall = ((1U 
                                                   == (IData)(vlSelf->top__DOT__ResultSrcE)) 
                                                  & ((0U 
                                                      != 
                                                      (0x1fU 
                                                       & vlSelf->top__DOT__RdE)) 
                                                     & (((0x1fU 
                                                          & vlSelf->top__DOT__RdE) 
                                                         == 
                                                         (0x1fU 
                                                          & vlSelf->top__DOT__RD1_d)) 
                                                        | ((0x1fU 
                                                            & vlSelf->top__DOT__RdE) 
                                                           == 
                                                           (0x1fU 
                                                            & vlSelf->top__DOT__RD2_d)))));
    vlSelf->top__DOT__ResultSrc = 0U;
    vlSelf->top__DOT__SizeWrite = 0U;
    vlSelf->top__DOT__ALUSrc_d = 0U;
    vlSelf->top__DOT__ALUCtrl_d = 0U;
    vlSelf->top__DOT__RegWrite_d = 0U;
    vlSelf->top__DOT__MemWrite = 0U;
    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
    vlSelf->top__DOT__LoadUnsigned = 0U;
    vlSelf->top__DOT__LoadSize = 2U;
    vlSelf->top__DOT__ALUsrc2 = 0U;
    vlSelf->top__DOT__pc_block__DOT__inc_pc = ((IData)(4U) 
                                               + vlSelf->top__DOT__pc_block__DOT__internal_pc);
    vlSelf->top__DOT__PC = vlSelf->top__DOT__pc_block__DOT__internal_pc;
    vlSelf->top__DOT__pc_block__DOT__branch_pc = (vlSelf->top__DOT__pc_block__DOT__internal_pc 
                                                  + vlSelf->top__DOT__ImmOp);
    vlSelf->top__DOT__SrcBE = ((2U & (IData)(vlSelf->top__DOT__ForwardBE))
                                ? vlSelf->top__DOT__output_ALU
                                : vlSelf->top__DOT__ALUResultM);
    vlSelf->top__DOT__SrcAE = ((2U & (IData)(vlSelf->top__DOT__ForwardAE))
                                ? vlSelf->top__DOT__output_ALU
                                : vlSelf->top__DOT__ALUResultM);
    vlSelf->top__DOT__F_Write = 1U;
    vlSelf->top__DOT__PCWrite = 1U;
    if (((((((((0x37U == (0x7fU & vlSelf->top__DOT__instr_d)) 
               | (0x17U == (0x7fU & vlSelf->top__DOT__instr_d))) 
              | (0x6fU == (0x7fU & vlSelf->top__DOT__instr_d))) 
             | (0x67U == (0x7fU & vlSelf->top__DOT__instr_d))) 
            | (0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) 
           | (3U == (0x7fU & vlSelf->top__DOT__instr_d))) 
          | (0x23U == (0x7fU & vlSelf->top__DOT__instr_d))) 
         | (0x13U == (0x7fU & vlSelf->top__DOT__instr_d)))) {
        if ((0x37U != (0x7fU & vlSelf->top__DOT__instr_d))) {
            if ((0x17U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                if ((0x6fU != (0x7fU & vlSelf->top__DOT__instr_d))) {
                    if ((0x67U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                        if ((0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) {
                            vlSelf->top__DOT__Branch_d = 1U;
                        }
                    }
                }
            }
        }
        if ((0x37U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT__ResultSrc = 0U;
            vlSelf->top__DOT__SizeWrite = 0U;
            vlSelf->top__DOT__ALUSrc_d = 1U;
            vlSelf->top__DOT__ALUCtrl_d = 0xaU;
            vlSelf->top__DOT__RegWrite_d = 1U;
            vlSelf->top__DOT__MemWrite = 0U;
            vlSelf->top__DOT____Vcellout__control__ImmSrc = 4U;
        } else if ((0x17U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT__ResultSrc = 0U;
            vlSelf->top__DOT__SizeWrite = 0U;
            vlSelf->top__DOT__ALUSrc_d = 1U;
            vlSelf->top__DOT__ALUCtrl_d = 0xbU;
            vlSelf->top__DOT__RegWrite_d = 1U;
            vlSelf->top__DOT__MemWrite = 0U;
            vlSelf->top__DOT____Vcellout__control__ImmSrc = 4U;
        } else if ((0x6fU == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT__ResultSrc = 2U;
            vlSelf->top__DOT__SizeWrite = 0U;
            vlSelf->top__DOT__ALUSrc_d = 0U;
            vlSelf->top__DOT__ALUCtrl_d = 0U;
            vlSelf->top__DOT__RegWrite_d = 1U;
            vlSelf->top__DOT__MemWrite = 0U;
            vlSelf->top__DOT____Vcellout__control__ImmSrc = 3U;
        } else if ((0x67U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT__ResultSrc = 2U;
            vlSelf->top__DOT__SizeWrite = 0U;
            vlSelf->top__DOT__ALUSrc_d = 1U;
            vlSelf->top__DOT__ALUCtrl_d = 0U;
            vlSelf->top__DOT__RegWrite_d = 1U;
            vlSelf->top__DOT__MemWrite = 0U;
            vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
        } else if ((0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT__ResultSrc = 0U;
            vlSelf->top__DOT__SizeWrite = 0U;
            vlSelf->top__DOT__ALUSrc_d = 0U;
            if ((0x4000U & vlSelf->top__DOT__instr_d)) {
                vlSelf->top__DOT__ALUCtrl_d = 1U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 2U;
            } else if ((0x2000U & vlSelf->top__DOT__instr_d)) {
                vlSelf->top__DOT__ALUCtrl_d = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            } else {
                vlSelf->top__DOT__ALUCtrl_d = 1U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 2U;
            }
            vlSelf->top__DOT__RegWrite_d = 0U;
            vlSelf->top__DOT__MemWrite = 0U;
        } else if ((3U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT__ResultSrc = 1U;
            vlSelf->top__DOT__SizeWrite = 0U;
            vlSelf->top__DOT__ALUSrc_d = 1U;
            vlSelf->top__DOT__ALUCtrl_d = 0U;
            vlSelf->top__DOT__RegWrite_d = 1U;
            vlSelf->top__DOT__MemWrite = 0U;
            vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
        } else if ((0x23U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                              >> 0xcU)))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__SizeWrite = 0U;
                vlSelf->top__DOT__ALUSrc_d = 1U;
                vlSelf->top__DOT__ALUCtrl_d = 0U;
                vlSelf->top__DOT__RegWrite_d = 0U;
                vlSelf->top__DOT__MemWrite = 1U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 1U;
            } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__SizeWrite = 1U;
                vlSelf->top__DOT__ALUSrc_d = 1U;
                vlSelf->top__DOT__ALUCtrl_d = 0U;
                vlSelf->top__DOT__RegWrite_d = 0U;
                vlSelf->top__DOT__MemWrite = 1U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 1U;
            } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__SizeWrite = 2U;
                vlSelf->top__DOT__ALUSrc_d = 1U;
                vlSelf->top__DOT__ALUCtrl_d = 0U;
                vlSelf->top__DOT__RegWrite_d = 0U;
                vlSelf->top__DOT__MemWrite = 1U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 1U;
            }
        } else {
            if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                              >> 0xcU)))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 1U;
                vlSelf->top__DOT__ALUCtrl_d = 0U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 1U;
                vlSelf->top__DOT__ALUCtrl_d = 8U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            } else if ((3U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 1U;
                vlSelf->top__DOT__ALUCtrl_d = 9U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            } else if ((4U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 1U;
                vlSelf->top__DOT__ALUCtrl_d = 4U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            } else if ((6U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 1U;
                vlSelf->top__DOT__ALUCtrl_d = 3U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            } else if ((7U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 1U;
                vlSelf->top__DOT__ALUCtrl_d = 2U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                if ((0U == (vlSelf->top__DOT__instr_d 
                            >> 0x19U))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 5U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                }
            } else if ((5U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                if ((0U == (vlSelf->top__DOT__instr_d 
                            >> 0x19U))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 6U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                      >> 0x19U))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 1U;
                    vlSelf->top__DOT__ALUCtrl_d = 7U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                }
            }
            vlSelf->top__DOT__RegWrite_d = ((0U == 
                                             (7U & 
                                              (vlSelf->top__DOT__instr_d 
                                               >> 0xcU))) 
                                            | ((2U 
                                                == 
                                                (7U 
                                                 & (vlSelf->top__DOT__instr_d 
                                                    >> 0xcU))) 
                                               | ((3U 
                                                   == 
                                                   (7U 
                                                    & (vlSelf->top__DOT__instr_d 
                                                       >> 0xcU))) 
                                                  | ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlSelf->top__DOT__instr_d 
                                                          >> 0xcU))) 
                                                     | ((6U 
                                                         == 
                                                         (7U 
                                                          & (vlSelf->top__DOT__instr_d 
                                                             >> 0xcU))) 
                                                        | ((7U 
                                                            == 
                                                            (7U 
                                                             & (vlSelf->top__DOT__instr_d 
                                                                >> 0xcU))) 
                                                           | ((1U 
                                                               == 
                                                               (7U 
                                                                & (vlSelf->top__DOT__instr_d 
                                                                   >> 0xcU)))
                                                               ? 
                                                              (0U 
                                                               == 
                                                               (vlSelf->top__DOT__instr_d 
                                                                >> 0x19U))
                                                               : (IData)(
                                                                         ((0x5000U 
                                                                           == 
                                                                           (0x7000U 
                                                                            & vlSelf->top__DOT__instr_d)) 
                                                                          & ((0U 
                                                                              == 
                                                                              (vlSelf->top__DOT__instr_d 
                                                                               >> 0x19U)) 
                                                                             | (0x20U 
                                                                                == 
                                                                                (vlSelf->top__DOT__instr_d 
                                                                                >> 0x19U))))))))))));
        }
    } else if ((0x33U == (0x7fU & vlSelf->top__DOT__instr_d))) {
        if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                          >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 0U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 1U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            }
            vlSelf->top__DOT__RegWrite_d = ((0U == 
                                             (vlSelf->top__DOT__instr_d 
                                              >> 0x19U)) 
                                            | (0x20U 
                                               == (vlSelf->top__DOT__instr_d 
                                                   >> 0x19U)));
        } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 5U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
            } else {
                vlSelf->top__DOT__RegWrite_d = 0U;
            }
        } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 8U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
            } else {
                vlSelf->top__DOT__RegWrite_d = 0U;
            }
        } else if ((3U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 9U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
            } else {
                vlSelf->top__DOT__RegWrite_d = 0U;
            }
        } else if ((4U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 4U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
            } else {
                vlSelf->top__DOT__RegWrite_d = 0U;
            }
        } else if ((5U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 6U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 7U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
            }
            vlSelf->top__DOT__RegWrite_d = ((0U == 
                                             (vlSelf->top__DOT__instr_d 
                                              >> 0x19U)) 
                                            | (0x20U 
                                               == (vlSelf->top__DOT__instr_d 
                                                   >> 0x19U)));
        } else if ((6U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ResultSrc = 0U;
                vlSelf->top__DOT__ALUSrc_d = 0U;
                vlSelf->top__DOT__ALUCtrl_d = 3U;
                vlSelf->top__DOT__MemWrite = 0U;
                vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                vlSelf->top__DOT__RegWrite_d = 1U;
            } else {
                vlSelf->top__DOT__RegWrite_d = 0U;
            }
        } else {
            if ((7U == (7U & (vlSelf->top__DOT__instr_d 
                              >> 0xcU)))) {
                if ((0U == (vlSelf->top__DOT__instr_d 
                            >> 0x19U))) {
                    vlSelf->top__DOT__ResultSrc = 0U;
                    vlSelf->top__DOT__ALUSrc_d = 0U;
                    vlSelf->top__DOT__ALUCtrl_d = 2U;
                    vlSelf->top__DOT__MemWrite = 0U;
                    vlSelf->top__DOT____Vcellout__control__ImmSrc = 0U;
                }
            }
            vlSelf->top__DOT__RegWrite_d = (IData)(
                                                   (0x7000U 
                                                    == 
                                                    (0xfe007000U 
                                                     & vlSelf->top__DOT__instr_d)));
        }
    }
    if ((0U == (3U & (IData)(vlSelf->top__DOT____Vcellout__control__ImmSrc)))) {
        vlSelf->top__DOT__ImmExt_d = (((- (IData)((vlSelf->top__DOT__instr_d 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (vlSelf->top__DOT__instr_d 
                                                   >> 0x14U));
    } else if ((1U == (3U & (IData)(vlSelf->top__DOT____Vcellout__control__ImmSrc)))) {
        vlSelf->top__DOT__ImmExt_d = (((- (IData)((vlSelf->top__DOT__instr_d 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (
                                                   (0xfe0U 
                                                    & (vlSelf->top__DOT__instr_d 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlSelf->top__DOT__instr_d 
                                                         >> 7U))));
    } else if ((2U == (3U & (IData)(vlSelf->top__DOT____Vcellout__control__ImmSrc)))) {
        vlSelf->top__DOT__ImmExt_d = (((- (IData)((vlSelf->top__DOT__instr_d 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (
                                                   (0x800U 
                                                    & (vlSelf->top__DOT__instr_d 
                                                       << 4U)) 
                                                   | ((0x7e0U 
                                                       & (vlSelf->top__DOT__instr_d 
                                                          >> 0x14U)) 
                                                      | (0x1eU 
                                                         & (vlSelf->top__DOT__instr_d 
                                                            >> 7U)))));
    }
    vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffffff00U & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | vlSelf->top__DOT__datamem__DOT__ram_array
           [(0x1ffffU & vlSelf->top__DOT__ALUResultM)]);
    vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffff00ffU & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelf->top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__ALUResultM))] 
              << 8U));
    vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xff00ffffU & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelf->top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(2U) + vlSelf->top__DOT__ALUResultM))] 
              << 0x10U));
    vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
        = ((0xffffffU & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data) 
           | (vlSelf->top__DOT__datamem__DOT__ram_array
              [(0x1ffffU & ((IData)(3U) + vlSelf->top__DOT__ALUResultM))] 
              << 0x18U));
    if (((((((((0x37U == (0x7fU & vlSelf->top__DOT__instr_d)) 
               | (0x17U == (0x7fU & vlSelf->top__DOT__instr_d))) 
              | (0x6fU == (0x7fU & vlSelf->top__DOT__instr_d))) 
             | (0x67U == (0x7fU & vlSelf->top__DOT__instr_d))) 
            | (0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) 
           | (3U == (0x7fU & vlSelf->top__DOT__instr_d))) 
          | (0x23U == (0x7fU & vlSelf->top__DOT__instr_d))) 
         | (0x13U == (0x7fU & vlSelf->top__DOT__instr_d)))) {
        if ((0x37U != (0x7fU & vlSelf->top__DOT__instr_d))) {
            if ((0x17U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                if ((0x6fU != (0x7fU & vlSelf->top__DOT__instr_d))) {
                    if ((0x67U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                        if ((0x63U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                            if ((3U == (0x7fU & vlSelf->top__DOT__instr_d))) {
                                if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                                                  >> 0xcU)))) {
                                    vlSelf->top__DOT__LoadUnsigned = 0U;
                                    vlSelf->top__DOT__LoadSize = 0U;
                                } else if ((1U == (7U 
                                                   & (vlSelf->top__DOT__instr_d 
                                                      >> 0xcU)))) {
                                    vlSelf->top__DOT__LoadUnsigned = 0U;
                                    vlSelf->top__DOT__LoadSize = 1U;
                                } else if ((2U == (7U 
                                                   & (vlSelf->top__DOT__instr_d 
                                                      >> 0xcU)))) {
                                    vlSelf->top__DOT__LoadUnsigned = 0U;
                                    vlSelf->top__DOT__LoadSize = 2U;
                                } else if ((4U == (7U 
                                                   & (vlSelf->top__DOT__instr_d 
                                                      >> 0xcU)))) {
                                    vlSelf->top__DOT__LoadUnsigned = 1U;
                                    vlSelf->top__DOT__LoadSize = 0U;
                                } else if ((5U == (7U 
                                                   & (vlSelf->top__DOT__instr_d 
                                                      >> 0xcU)))) {
                                    vlSelf->top__DOT__LoadUnsigned = 1U;
                                    vlSelf->top__DOT__LoadSize = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->top__DOT__output_DataMem = ((0U == (IData)(vlSelf->top__DOT__LoadSize))
                                         ? ((IData)(vlSelf->top__DOT__LoadUnsigned)
                                             ? (0xffU 
                                                & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data)
                                             : (((- (IData)(
                                                            (1U 
                                                             & (vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
                                                                >> 7U)))) 
                                                 << 8U) 
                                                | (0xffU 
                                                   & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data)))
                                         : ((1U == (IData)(vlSelf->top__DOT__LoadSize))
                                             ? ((IData)(vlSelf->top__DOT__LoadUnsigned)
                                                 ? 
                                                (0xffffU 
                                                 & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data)
                                                 : 
                                                (((- (IData)(
                                                             (1U 
                                                              & (vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data 
                                                                 >> 0xfU)))) 
                                                  << 0x10U) 
                                                 | (0xffffU 
                                                    & vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data)))
                                             : vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data));
    vlSelf->top__DOT__ALUop2 = ((IData)(vlSelf->top__DOT__ALUSrc_e)
                                 ? vlSelf->top__DOT__ImmOp
                                 : vlSelf->top__DOT__SrcBE);
    if (((((((((0x37U == (0x7fU & vlSelf->top__DOT__instr_d)) 
               | (0x17U == (0x7fU & vlSelf->top__DOT__instr_d))) 
              | (0x6fU == (0x7fU & vlSelf->top__DOT__instr_d))) 
             | (0x67U == (0x7fU & vlSelf->top__DOT__instr_d))) 
            | (0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) 
           | (3U == (0x7fU & vlSelf->top__DOT__instr_d))) 
          | (0x23U == (0x7fU & vlSelf->top__DOT__instr_d))) 
         | (0x13U == (0x7fU & vlSelf->top__DOT__instr_d)))) {
        if ((0x37U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT__ALUsrc2 = 0U;
        } else if ((0x17U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT__ALUsrc2 = 1U;
        } else if ((0x6fU != (0x7fU & vlSelf->top__DOT__instr_d))) {
            if ((0x67U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                if ((0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) {
                    if ((1U & (~ (vlSelf->top__DOT__instr_d 
                                  >> 0xeU)))) {
                        if ((0x2000U & vlSelf->top__DOT__instr_d)) {
                            vlSelf->top__DOT__ALUsrc2 = 0U;
                        }
                    }
                } else if ((3U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                    if ((0x23U != (0x7fU & vlSelf->top__DOT__instr_d))) {
                        if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                                          >> 0xcU)))) {
                            vlSelf->top__DOT__ALUsrc2 = 0U;
                        } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                                 >> 0xcU)))) {
                            vlSelf->top__DOT__ALUsrc2 = 0U;
                        } else if ((3U == (7U & (vlSelf->top__DOT__instr_d 
                                                 >> 0xcU)))) {
                            vlSelf->top__DOT__ALUsrc2 = 0U;
                        } else if ((4U == (7U & (vlSelf->top__DOT__instr_d 
                                                 >> 0xcU)))) {
                            vlSelf->top__DOT__ALUsrc2 = 0U;
                        } else if ((6U == (7U & (vlSelf->top__DOT__instr_d 
                                                 >> 0xcU)))) {
                            vlSelf->top__DOT__ALUsrc2 = 0U;
                        } else if ((7U == (7U & (vlSelf->top__DOT__instr_d 
                                                 >> 0xcU)))) {
                            vlSelf->top__DOT__ALUsrc2 = 0U;
                        } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                                 >> 0xcU)))) {
                            if ((0U == (vlSelf->top__DOT__instr_d 
                                        >> 0x19U))) {
                                vlSelf->top__DOT__ALUsrc2 = 0U;
                            }
                        } else if ((5U == (7U & (vlSelf->top__DOT__instr_d 
                                                 >> 0xcU)))) {
                            if ((0U == (vlSelf->top__DOT__instr_d 
                                        >> 0x19U))) {
                                vlSelf->top__DOT__ALUsrc2 = 0U;
                            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                                  >> 0x19U))) {
                                vlSelf->top__DOT__ALUsrc2 = 0U;
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x33U == (0x7fU & vlSelf->top__DOT__instr_d))) {
        if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                          >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ALUsrc2 = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT__ALUsrc2 = 0U;
            }
        } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ALUsrc2 = 0U;
            }
        } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ALUsrc2 = 0U;
            }
        } else if ((3U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ALUsrc2 = 0U;
            }
        } else if ((4U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ALUsrc2 = 0U;
            }
        } else if ((5U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ALUsrc2 = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT__ALUsrc2 = 0U;
            }
        } else if ((6U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ALUsrc2 = 0U;
            }
        } else if ((7U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT__ALUsrc2 = 0U;
            }
        }
    }
    vlSelf->top__DOT__ALUop1 = ((IData)(vlSelf->top__DOT__ALUsrc2)
                                 ? (IData)(vlSelf->top__DOT__pc_save_e)
                                 : vlSelf->top__DOT__SrcAE);
    vlSelf->top__DOT__output_ALU = ((8U & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                     ? ((4U & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                         ? 0U : ((2U 
                                                  & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                   ? 
                                                  ((vlSelf->top__DOT__ALUop1 
                                                    + vlSelf->top__DOT__ALUop2) 
                                                   - (IData)(4U))
                                                   : vlSelf->top__DOT__ALUop2)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                   ? 
                                                  ((vlSelf->top__DOT__ALUop1 
                                                    < vlSelf->top__DOT__ALUop2)
                                                    ? 1U
                                                    : 0U)
                                                   : 
                                                  (VL_LTS_III(32, vlSelf->top__DOT__ALUop1, vlSelf->top__DOT__ALUop2)
                                                    ? 1U
                                                    : 0U))))
                                     : ((4U & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                         ? ((2U & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                 ? 
                                                ((0x1fU 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__ALUop2))
                                                  ? 
                                                 VL_SHIFTRS_III(32,32,32, vlSelf->top__DOT__ALUop1, 
                                                                (0x1fU 
                                                                 & vlSelf->top__DOT__ALUop2))
                                                  : 
                                                 (- 
                                                  (vlSelf->top__DOT__ALUop1 
                                                   >> 0x1fU)))
                                                 : 
                                                ((0x1fU 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__ALUop2))
                                                  ? 
                                                 (vlSelf->top__DOT__ALUop1 
                                                  >> 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__ALUop2))
                                                  : 0U))
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                 ? 
                                                ((0x1fU 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__ALUop2))
                                                  ? 
                                                 (vlSelf->top__DOT__ALUop1 
                                                  << 
                                                  (0x1fU 
                                                   & vlSelf->top__DOT__ALUop2))
                                                  : 0U)
                                                 : 
                                                (vlSelf->top__DOT__ALUop1 
                                                 ^ vlSelf->top__DOT__ALUop2)))
                                         : ((2U & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                 ? 
                                                (vlSelf->top__DOT__ALUop1 
                                                 | vlSelf->top__DOT__ALUop2)
                                                 : 
                                                (vlSelf->top__DOT__ALUop1 
                                                 & vlSelf->top__DOT__ALUop2))
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__ALUCtrl_e))
                                                 ? 
                                                (vlSelf->top__DOT__ALUop1 
                                                 - vlSelf->top__DOT__ALUop2)
                                                 : 
                                                (vlSelf->top__DOT__ALUop1 
                                                 + vlSelf->top__DOT__ALUop2)))));
    vlSelf->top__DOT__EQ = (vlSelf->top__DOT__ALUop1 
                            == vlSelf->top__DOT__ALUop2);
    vlSelf->top__DOT__LT = VL_LTS_III(32, vlSelf->top__DOT__ALUop1, vlSelf->top__DOT__ALUop2);
    vlSelf->top__DOT__LTU = (vlSelf->top__DOT__ALUop1 
                             < vlSelf->top__DOT__ALUop2);
    vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
    if (((((((((0x37U == (0x7fU & vlSelf->top__DOT__instr_d)) 
               | (0x17U == (0x7fU & vlSelf->top__DOT__instr_d))) 
              | (0x6fU == (0x7fU & vlSelf->top__DOT__instr_d))) 
             | (0x67U == (0x7fU & vlSelf->top__DOT__instr_d))) 
            | (0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) 
           | (3U == (0x7fU & vlSelf->top__DOT__instr_d))) 
          | (0x23U == (0x7fU & vlSelf->top__DOT__instr_d))) 
         | (0x13U == (0x7fU & vlSelf->top__DOT__instr_d)))) {
        if ((0x37U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((0x17U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((0x6fU == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 1U;
        } else if ((0x67U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 2U;
        } else if ((0x63U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc 
                = ((0x4000U & vlSelf->top__DOT__instr_d)
                    ? ((0x2000U & vlSelf->top__DOT__instr_d)
                        ? ((0x1000U & vlSelf->top__DOT__instr_d)
                            ? ((IData)(vlSelf->top__DOT__LTU)
                                ? 0U : 1U) : ((IData)(vlSelf->top__DOT__LTU)
                                               ? 1U
                                               : 0U))
                        : ((0x1000U & vlSelf->top__DOT__instr_d)
                            ? ((IData)(vlSelf->top__DOT__LT)
                                ? 0U : 1U) : ((IData)(vlSelf->top__DOT__LT)
                                               ? 1U
                                               : 0U)))
                    : ((0x2000U & vlSelf->top__DOT__instr_d)
                        ? 0U : ((0x1000U & vlSelf->top__DOT__instr_d)
                                 ? ((IData)(vlSelf->top__DOT__EQ)
                                     ? 0U : 1U) : ((IData)(vlSelf->top__DOT__EQ)
                                                    ? 1U
                                                    : 0U))));
        } else if ((3U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((0x23U == (0x7fU & vlSelf->top__DOT__instr_d))) {
            if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                              >> 0xcU)))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                     >> 0xcU)))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((3U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((4U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((6U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((7U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
        } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((5U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        }
    } else if ((0x33U == (0x7fU & vlSelf->top__DOT__instr_d))) {
        if ((0U == (7U & (vlSelf->top__DOT__instr_d 
                          >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((1U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((2U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((3U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((4U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((5U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            } else if ((0x20U == (vlSelf->top__DOT__instr_d 
                                  >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((6U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        } else if ((7U == (7U & (vlSelf->top__DOT__instr_d 
                                 >> 0xcU)))) {
            if ((0U == (vlSelf->top__DOT__instr_d >> 0x19U))) {
                vlSelf->top__DOT____Vcellout__control__PCSrc = 0U;
            }
        }
    }
    __Vtableidx1 = (((IData)(vlSelf->top__DOT__Jump_e) 
                     << 7U) | (((IData)(vlSelf->top__DOT__EQ) 
                                << 6U) | (((IData)(vlSelf->top__DOT__LT) 
                                           << 5U) | 
                                          (((IData)(vlSelf->top__DOT__LTU) 
                                            << 4U) 
                                           | (((IData)(vlSelf->top__DOT__function3_e) 
                                               << 1U) 
                                              | (IData)(vlSelf->top__DOT__Branch_e))))));
    vlSelf->top__DOT__PCSrcE = Vdut__ConstPool__TABLE_h382018d6_0
        [__Vtableidx1];
    vlSelf->top__DOT__flush_f_d = 0U;
    vlSelf->top__DOT__flush_d_exec = 0U;
    if (vlSelf->top__DOT__PCSrcE) {
        vlSelf->top__DOT__flush_f_d = 1U;
        vlSelf->top__DOT__flush_d_exec = 1U;
    }
    if (vlSelf->top__DOT__hazard_unit__DOT__wStall) {
        vlSelf->top__DOT__F_Write = 0U;
        vlSelf->top__DOT__PCWrite = 0U;
        vlSelf->top__DOT__flush_d_exec = 1U;
    }
}

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    // Body
    Vdut___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
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
    vlSelf->top__DOT__EQ = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__RegWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUCtrl = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ALUSrc = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ImmOp = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__reg_entry = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__instr_d = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__output_ALU = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUop1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUop2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__regOp2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__output_DataMem = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__write_to_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__LT = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__LTU = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ResultSrc = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__MemWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__SizeWrite = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ALUsrc2 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__LoadSize = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__LoadUnsigned = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__selectline1 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__selectline2 = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__flush_d_exec = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__flush_f_d = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__F_Write = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__PCWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__PCD = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__PCD_save = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RD1_d = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RD2_d = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc_d = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__Rd_d = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ImmExt_d = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__PCPlus4dE = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RD1_e = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RD2_e = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc_e = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RdE = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ImmExt_e = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RegWrite_d = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ResultSrc_d = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__MemWrite_d = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Jump_d = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Branch_d = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUCtrl_d = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__ALUSrc_d = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__SizeWrite_d = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__LoadSize_d = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__LoadUnsigned_d = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUSrc2_d = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__RegWriteE = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ResultSrcE = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__MemWriteE = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Jump_e = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Branch_e = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUCtrl_e = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__ALUSrc_e = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__SizeWriteE = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__LoadSizeE = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__LoadUnsignedE = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUSrc2_e = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__function3_e = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__PCSrcE = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__PCPlus4M = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RdM = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUResultM = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__WriteDataM = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RegWriteM = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ResultSrCM = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__MemWriteM = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__SizeWriteM = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__LoadSizeM = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__LoadUnsignedm = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__RegWriteW = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ResultSrcW = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__datamem_output = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUResultW = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ReadDataW = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RdW = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__PCPlus4W = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ResultW = VL_RAND_RESET_I(32);
    vlSelf->top__DOT____Vcellout__control__PCSrc = VL_RAND_RESET_I(2);
    vlSelf->top__DOT____Vcellout__control__ImmSrc = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ALU = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__WD3 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__WE3 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__AD3 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__AD2 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__AD1 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__ForwardAE = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ForwardBE = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__SrcAE = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__SrcBE = VL_RAND_RESET_I(32);
    vlSelf->top__DOT____Vcellout__em_pipeline__ResultSrc_m = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__pc_save_e = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__hazard_unit__DOT__wStall = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<131073; ++__Vi0) {
        vlSelf->top__DOT__Instr_Mem__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__pc_block__DOT__branch_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc_block__DOT__inc_pc = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__pc_block__DOT__internal_pc = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__regfile__DOT__regfile_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->top__DOT__datamem__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__datamem__DOT__unnamedblk1__DOT__data = VL_RAND_RESET_I(32);
    vlSelf->__Vchglast__TOP__top__DOT__output_ALU = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
