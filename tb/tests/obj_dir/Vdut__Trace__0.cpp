// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__instr),32);
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__RegWrite));
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__ALUCtrl),3);
        bufp->chgBit(oldp+3,(vlSelf->top__DOT__ALUSrc));
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__ImmSrc),3);
        bufp->chgIData(oldp+5,(vlSelf->top__DOT__ImmOp),32);
        bufp->chgIData(oldp+6,(vlSelf->top__DOT__pc_block__DOT__internal_pc),32);
        bufp->chgBit(oldp+7,(vlSelf->top__DOT__MemWrite));
        bufp->chgIData(oldp+8,(((IData)(4U) + vlSelf->top__DOT__pc_block__DOT__internal_pc)),32);
        bufp->chgBit(oldp+9,(vlSelf->top__DOT__ByteWrite));
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__ResultSrc),2);
        bufp->chgCData(oldp+11,((0x1fU & (vlSelf->top__DOT__instr 
                                          >> 7U))),5);
        bufp->chgCData(oldp+12,((0x1fU & (vlSelf->top__DOT__instr 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+13,((0x1fU & (vlSelf->top__DOT__instr 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+14,((0x7fU & vlSelf->top__DOT__instr)),7);
        bufp->chgCData(oldp+15,((7U & (vlSelf->top__DOT__instr 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+16,((vlSelf->top__DOT__instr 
                                 >> 0x19U)),7);
        bufp->chgIData(oldp+17,((vlSelf->top__DOT__pc_block__DOT__internal_pc 
                                 + vlSelf->top__DOT__ImmOp)),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+18,(((0U == (IData)(vlSelf->top__DOT__ResultSrc))
                                  ? vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU
                                  : ((1U == (IData)(vlSelf->top__DOT__ResultSrc))
                                      ? vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem
                                      : ((2U == (IData)(vlSelf->top__DOT__ResultSrc))
                                          ? ((IData)(4U) 
                                             + vlSelf->top__DOT__pc_block__DOT__internal_pc)
                                          : 0U)))),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[0]),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[1]),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[2]),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[3]),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[4]),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[5]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[6]),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[7]),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[8]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[9]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[10]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[11]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[12]),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[13]),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[14]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[15]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[16]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[17]),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[18]),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[19]),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[20]),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[21]),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[22]),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[23]),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[24]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[25]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[26]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[27]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[28]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[29]),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[30]),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regfile__DOT__regfile_array[31]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+51,((0U == (vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop1 
                                      - vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop2))));
        bufp->chgCData(oldp+52,(vlSelf->top__DOT__PCSrc),2);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_ALU),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop1),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__ALUop2),32);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__regOp2),32);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__Reg_and_ALU_block__DOT__output_DataMem),32);
    }
    bufp->chgBit(oldp+58,(vlSelf->clk));
    bufp->chgBit(oldp+59,(vlSelf->rst));
    bufp->chgIData(oldp+60,(vlSelf->a0),32);
}

void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_cleanup\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
