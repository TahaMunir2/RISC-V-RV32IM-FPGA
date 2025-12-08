# RV32M Extension (Multiply / Divide Instructions)

## Table of Contents
- [1. Overview](#overview)
- [2. Implementation](#implementation)
  - [2.1 Instruction Set Coverage](#instruction-set-coverage)
  - [2.2 ALU Datapath Extensions](#alu-datapath-extensions)
  - [2.3 Control Unit Integration](#control-unit-integration)
- [3. Testing](#testing)
  - [3.1 ALU M-Extension Unit Tests](#alu-m-extension-unit-tests)
    - [3.1.1 ALU Test: MUL (Low 32-bit Product)](#alu-test-mul-low-32-bit-product)
    - [3.1.2 ALU Test: MULH (High 32-bit Signed×Signed Product)](#alu-test-mulh-high-32-bit-signedsigned-product)
    - [3.1.3 ALU Test: MULH (Negative Operand Case)](#alu-test-mulh-negative-operand-case)
    - [3.1.4 ALU Test: DIV (Signed Division)](#alu-test-div-signed-division)
    - [3.1.5 ALU Test: REM (Signed Remainder)](#alu-test-rem-signed-remainder)
    - [3.1.6 ALU Test: REMU (Unsigned Remainder)](#alu-test-remu-unsigned-remainder)
    - [3.1.7 ALU Test: MULHSU (High 32-bit Signed×Unsigned Product)](#alu-test-mulhsu-high-32-bit-signedunsigned-product)
    - [3.1.8 ALU Test: MULHU (High 32-bit Unsigned×Unsigned Product)](#alu-test-mulhu-high-32-bit-unsignedunsigned-product)
    - [3.1.9 ALU Test: DIV (Division by Zero)](#alu-test-div-division-by-zero)
    - [3.1.10 ALU Test: DIV (Signed Overflow Case)](#alu-test-div-signed-overflow-case)
    - [3.1.11 ALU Test: DIVU (Unsigned Division by Zero)](#alu-test-divu-unsigned-division-by-zero)
    - [3.1.12 ALU Test: REM (Remainder with Divisor Zero)](#alu-test-rem-remainder-with-divisor-zero)
    - [3.1.13 ALU Test: REMU (Unsigned Remainder with Divisor Zero)](#alu-test-remu-unsigned-remainder-with-divisor-zero)

---

## Overview

This section describes how we extended our core from **RV32I** to **RV32IM** by adding the standard **RV32M multiply/divide extension**. The base 37-instruction RV32I datapath, pipeline, forwarding network, and memory system are left unchanged.

We only modified:

- the **ALU**, to implement 64-bit products and division/remainder semantics, and  
- the **Control Unit**, to decode the `M` instructions and drive a wider `ALUCtrl` bus.

All eight M-extension instructions (`MUL`, `MULH`, `MULHSU`, `MULHU`, `DIV`, `DIVU`, `REM`, `REMU`) are now fully supported as single-cycle operations in our design.

---

## Implementation

### 2.1 Instruction Set Coverage

We implement the full **RV32M** base extension as defined in the RISC-V spec. These are eight additional **R-type** operations under the existing `OPC_OP = 0110011` opcode:

- **MUL** – Low 32 bits of `rs1 * rs2`, treating both operands as signed 32-bit integers.  
  Mathematically, if `P = signed(rs1) × signed(rs2)` (64-bit), then `rd = P mod 2³²` (i.e. `P[31:0]`).

- **MULH** – High 32 bits of the signed 64-bit product of `rs1 * rs2`.  
  If `P = signed(rs1) × signed(rs2)` (64-bit), then `rd = P[63:32]`.

- **MULHSU** – High 32 bits of the 64-bit product where `rs1` is treated as **signed** and `rs2` as **unsigned**.  
  If `P = signed(rs1) × unsigned(rs2)` (64-bit), then `rd = P[63:32]`.

- **MULHU** – High 32 bits of the 64-bit product with both operands treated as **unsigned**.  
  If `P = unsigned(rs1) × unsigned(rs2)` (64-bit), then `rd = P[63:32]`.

- **DIV** – **Signed division** of `rs1 / rs2`.  
  For non-zero divisor and non-overflow case, this is truncating integer division towards zero on signed 32-bit values (`int32_t` semantics).

- **DIVU** – **Unsigned division** of `rs1 / rs2`.  
  Both operands are interpreted modulo `2³²`, and the result is the floor of the usual integer division on `uint32_t`.

- **REM** – **Signed remainder** of `rs1 % rs2`.  
  The result satisfies `rs1 = rs2 × q + r` with `q = DIV(rs1, rs2)` and the remainder `r` has the **same sign as rs1** or is zero (RISC-V rule).

- **REMU** – **Unsigned remainder** of `rs1 % rs2`.  
  Both operands are interpreted as unsigned, and the result is the standard non-negative modulo in the range `[0, rs2)` when `rs2 ≠ 0`.

All eight instructions share the normal R-type format (`rd`, `rs1`, `rs2`) and behave like any other arithmetic instruction with respect to write-back and forwarding.

---

### 2.2 ALU Datapath Extensions

The ALU was extended with new cases on the 5-bit `ALUCtrl` signal. For the multiply instructions, we compute a **single 64-bit product** inside the relevant case branch with the appropriate signedness, and then select either the low or high 32-bit word.

Conceptually:

```systemverilog
case (ALUCtrl)
  5'b1100: begin
    // MUL: unsigned × unsigned, low 32 bits
    logic [63:0] product;
    product = $unsigned(ALUop1) * $unsigned(ALUop2);
    ALUout = product[31:0];
  end

  5'b1101: begin
    // MULH: signed × signed, high 32 bits
    logic [63:0] product;
    product = $signed(ALUop1) * $signed(ALUop2);
    ALUout = product[63:32];
  end

  5'b1110: begin
    // MULHSU: signed × unsigned, high 32 bits
    logic [63:0] product;
    logic [63:0] ALUop1_ext;
    logic [63:0] ALUop2_ext;
    ALUop1_ext = $signed(ALUop1);    // sign-extend rs1
    ALUop2_ext = $unsigned(ALUop2);  // zero-extend rs2
    product    = ALUop1_ext * ALUop2_ext;
    ALUout     = product[63:32];
  end

  5'b1111: begin
    // MULHU: unsigned × unsigned, high 32 bits
    logic [63:0] product;
    product = $unsigned(ALUop1) * $unsigned(ALUop2);
    ALUout = product[63:32];
  end
endcase
