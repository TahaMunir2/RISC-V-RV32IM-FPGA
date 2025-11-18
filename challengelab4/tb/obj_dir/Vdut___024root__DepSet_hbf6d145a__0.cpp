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

extern const VlUnpacked<CData/*5:0*/, 128> Vdut__ConstPool__TABLE_h221de8d3_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vdut__ConstPool__TABLE_h5cacfa2f_0;
extern const VlUnpacked<CData/*2:0*/, 128> Vdut__ConstPool__TABLE_h09530f4b_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vdut__ConstPool__TABLE_h3bf3471b_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vdut__ConstPool__TABLE_hce973932_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vdut__ConstPool__TABLE_hd29af267_0;

VL_INLINE_OPT void Vdut___024root___act_sequent__TOP__0(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___act_sequent__TOP__0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((((2U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3)) 
                       << 6U) | ((3U == (IData)(vlSelfRef.top__DOT__control__DOT__op)) 
                                 << 5U)) | (((IData)(vlSelfRef.top__DOT__EQ) 
                                             << 4U) 
                                            | ((1U 
                                                == (IData)(vlSelfRef.top__DOT__control__DOT__funct3)) 
                                               << 3U))) 
                    | (((0x63U == (IData)(vlSelfRef.top__DOT__control__DOT__op)) 
                        << 2U) | (((0U == (IData)(vlSelfRef.top__DOT__control__DOT__funct3)) 
                                   << 1U) | (0x13U 
                                             == (IData)(vlSelfRef.top__DOT__control__DOT__op)))));
    if ((1U & Vdut__ConstPool__TABLE_h221de8d3_0[__Vtableidx1])) {
        vlSelfRef.top__DOT__RegWrite = Vdut__ConstPool__TABLE_h5cacfa2f_0
            [__Vtableidx1];
    }
    if ((2U & Vdut__ConstPool__TABLE_h221de8d3_0[__Vtableidx1])) {
        vlSelfRef.top__DOT__ALUCtrl = Vdut__ConstPool__TABLE_h09530f4b_0
            [__Vtableidx1];
    }
    if ((4U & Vdut__ConstPool__TABLE_h221de8d3_0[__Vtableidx1])) {
        vlSelfRef.top__DOT__ALUSrc = Vdut__ConstPool__TABLE_h5cacfa2f_0
            [__Vtableidx1];
    }
    if ((8U & Vdut__ConstPool__TABLE_h221de8d3_0[__Vtableidx1])) {
        vlSelfRef.top__DOT__ImmSrc = Vdut__ConstPool__TABLE_h3bf3471b_0
            [__Vtableidx1];
    }
    if ((0x10U & Vdut__ConstPool__TABLE_h221de8d3_0
         [__Vtableidx1])) {
        vlSelfRef.top__DOT__PCSrc = Vdut__ConstPool__TABLE_hce973932_0
            [__Vtableidx1];
    }
    if ((0x20U & Vdut__ConstPool__TABLE_h221de8d3_0
         [__Vtableidx1])) {
        vlSelfRef.top__DOT__reg_entry = Vdut__ConstPool__TABLE_hd29af267_0
            [__Vtableidx1];
    }
    if ((0U == (IData)(vlSelfRef.top__DOT__ImmSrc))) {
        vlSelfRef.top__DOT__ImmOp = (((- (IData)((vlSelfRef.top__DOT__instr 
                                                  >> 0x1fU))) 
                                      << 0xcU) | (vlSelfRef.top__DOT__instr 
                                                  >> 0x14U));
    } else if ((1U == (IData)(vlSelfRef.top__DOT__ImmSrc))) {
        vlSelfRef.top__DOT__ImmOp = (((- (IData)((vlSelfRef.top__DOT__instr 
                                                  >> 0x1fU))) 
                                      << 0xcU) | ((0xfe0U 
                                                   & (vlSelfRef.top__DOT__instr 
                                                      >> 0x14U)) 
                                                  | (0x1fU 
                                                     & (vlSelfRef.top__DOT__instr 
                                                        >> 7U))));
    } else if ((2U == (IData)(vlSelfRef.top__DOT__ImmSrc))) {
        vlSelfRef.top__DOT__ImmOp = (((- (IData)((vlSelfRef.top__DOT__instr 
                                                  >> 0x1fU))) 
                                      << 0xcU) | ((0x800U 
                                                   & (vlSelfRef.top__DOT__instr 
                                                      << 4U)) 
                                                  | ((0x7e0U 
                                                      & (vlSelfRef.top__DOT__instr 
                                                         >> 0x14U)) 
                                                     | (0x1eU 
                                                        & (vlSelfRef.top__DOT__instr 
                                                           >> 7U)))));
    }
    vlSelfRef.top__DOT__pc_block__DOT__branch_pc = 
        (vlSelfRef.top__DOT__ImmOp + vlSelfRef.top__DOT__pc_block__DOT__internal_pc);
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2 
        = ((IData)(vlSelfRef.top__DOT__ALUSrc) ? vlSelfRef.top__DOT__ImmOp
            : vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
           [(0x1fU & (vlSelfRef.top__DOT__instr >> 0x14U))]);
    vlSelfRef.top__DOT__EQ = 0U;
    if ((0U != (IData)(vlSelfRef.top__DOT__ALUCtrl))) {
        vlSelfRef.top__DOT__EQ = (0U == (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                                         - vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2));
    }
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU = 0U;
    if ((0U == (IData)(vlSelfRef.top__DOT__ALUCtrl))) {
        vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU 
            = (vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1 
               + vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop2);
    }
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem 
        = ((0xffffff00U & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem) 
           | ((0x9f6U >= (0xfffU & ((IData)(3U) + vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU)))
               ? vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
              [(0xfffU & ((IData)(3U) + vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU))]
               : 0U));
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem 
        = ((0xffff00ffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem) 
           | (((0x9f6U >= (0xfffU & ((IData)(2U) + vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU)))
                ? vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
               [(0xfffU & ((IData)(2U) + vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU))]
                : 0U) << 8U));
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem 
        = ((0xff00ffffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem) 
           | (((0x9f6U >= (0xfffU & ((IData)(1U) + vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU)))
                ? vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
               [(0xfffU & ((IData)(1U) + vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU))]
                : 0U) << 0x10U));
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem 
        = ((0xffffffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem) 
           | (((0x9f6U >= (0xfffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU))
                ? vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__datamem__DOT__ram_array
               [(0xfffU & vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU)]
                : 0U) << 0x18U));
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
    IData/*31:0*/ __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 0;
    CData/*4:0*/ __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    __VdlySet__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 0;
    // Body
    __VdlySet__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 0U;
    if (vlSelfRef.top__DOT__RegWrite) {
        __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 
            = ((IData)(vlSelfRef.top__DOT__reg_entry)
                ? vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_DataMem
                : vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__output_ALU);
        __VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 
            = (0x1fU & ((IData)(vlSelfRef.__VdfgRegularize_h7cd686f0_0_0) 
                        >> 7U));
        __VdlySet__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0 = 1U;
    }
    vlSelfRef.top__DOT__pc_block__DOT__internal_pc 
        = ((IData)(vlSelfRef.rst) ? 0U : ((IData)(vlSelfRef.top__DOT__PCSrc)
                                           ? vlSelfRef.top__DOT__pc_block__DOT__branch_pc
                                           : vlSelfRef.top__DOT__pc_block__DOT__inc_pc));
    if (__VdlySet__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0) {
        vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[__VdlyDim0__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0] 
            = __VdlyVal__top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array__v0;
    }
    vlSelfRef.a0 = vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [0xaU];
    vlSelfRef.top__DOT__pc_block__DOT__inc_pc = ((IData)(4U) 
                                                 + vlSelfRef.top__DOT__pc_block__DOT__internal_pc);
    vlSelfRef.__VdfgRegularize_h7cd686f0_0_0 = ((vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                 [(0xffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                 << 8U) 
                                                | vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                [(0xffU 
                                                  & vlSelfRef.top__DOT__pc_block__DOT__internal_pc)]);
    vlSelfRef.top__DOT__control__DOT__op = (0x7fU & 
                                            vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                            [(0xffU 
                                              & vlSelfRef.top__DOT__pc_block__DOT__internal_pc)]);
    vlSelfRef.top__DOT__control__DOT__funct3 = (7U 
                                                & (vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                   [
                                                   (0xffU 
                                                    & ((IData)(1U) 
                                                       + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                   >> 4U));
    vlSelfRef.__VdfgRegularize_h7cd686f0_0_1 = ((vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                                 [(0xffU 
                                                   & ((IData)(2U) 
                                                      + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                                 << 0x10U) 
                                                | (IData)(vlSelfRef.__VdfgRegularize_h7cd686f0_0_0));
    vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__ALUop1 
        = vlSelfRef.top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array
        [(0x1fU & (vlSelfRef.__VdfgRegularize_h7cd686f0_0_1 
                   >> 0xfU))];
    vlSelfRef.top__DOT__instr = ((vlSelfRef.top__DOT__Instr_Mem__DOT__rom_array
                                  [(0xffU & ((IData)(3U) 
                                             + vlSelfRef.top__DOT__pc_block__DOT__internal_pc))] 
                                  << 0x18U) | vlSelfRef.__VdfgRegularize_h7cd686f0_0_1);
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
            VL_FATAL_MT("/Users/tahamunir/Downloads/Team5-main/repo/rtl/top.sv", 1, "", "NBA region did not converge.");
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
                VL_FATAL_MT("/Users/tahamunir/Downloads/Team5-main/repo/rtl/top.sv", 1, "", "Active region did not converge.");
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
