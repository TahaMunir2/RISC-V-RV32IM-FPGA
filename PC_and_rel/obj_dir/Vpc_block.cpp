// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpc_block.h"
#include "Vpc_block__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vpc_block::Vpc_block(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpc_block__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , pc_src{vlSymsp->TOP.pc_src}
    , Imm_op{vlSymsp->TOP.Imm_op}
    , pc{vlSymsp->TOP.pc}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vpc_block::Vpc_block(const char* _vcname__)
    : Vpc_block(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpc_block::~Vpc_block() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vpc_block___024root___eval_initial(Vpc_block___024root* vlSelf);
void Vpc_block___024root___eval_settle(Vpc_block___024root* vlSelf);
void Vpc_block___024root___eval(Vpc_block___024root* vlSelf);
#ifdef VL_DEBUG
void Vpc_block___024root___eval_debug_assertions(Vpc_block___024root* vlSelf);
#endif  // VL_DEBUG
void Vpc_block___024root___final(Vpc_block___024root* vlSelf);

static void _eval_initial_loop(Vpc_block__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vpc_block___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vpc_block___024root___eval_settle(&(vlSymsp->TOP));
        Vpc_block___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vpc_block::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpc_block::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpc_block___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vpc_block___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vpc_block::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vpc_block::final() {
    Vpc_block___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpc_block::hierName() const { return vlSymsp->name(); }
const char* Vpc_block::modelName() const { return "Vpc_block"; }
unsigned Vpc_block::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vpc_block::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vpc_block___024root__trace_init_top(Vpc_block___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vpc_block___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpc_block___024root*>(voidSelf);
    Vpc_block__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vpc_block___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vpc_block___024root__trace_register(Vpc_block___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpc_block::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vpc_block___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
