# Full RV32I (37-Instruction):

## Table of Contents
- [1. Overview](#overview)
- [2. Implementation](#implementation)
  - [2.1 Instruction Set Coverage](#instruction-set-coverage)
  - [2.2 Control Unit Evolution: From 9 to 37 Instructions](#control-unit-evolution-from-9-to-37-instructions)
  - [2.3 New Multiplexer: PC vs Register](#new-multiplexer-pc-vs-register-mux_pcvsreg)
  - [2.4 Extended ALU Control](#extended-alu-control)
  - [2.5 Extended Branch Comparison Signals](#extended-branch-comparison-signals)
  - [2.6 Memory Interface Extensions](#memory-interface-extensions)
- [3. Final Circuit Schematic](#final-circuit-schematic)
- [4. Testing](#testing)
- [4.1 Additional testing added to demonstrate the new features](#assembly-test-programs)
  - [4.1.1 Test 6: Branch Equal](#test-6-branch-equal-6_beqs)
  - [4.1.2 Test 7: Store Byte & Load Word](#test-7-store-byte--load-word-7_sb_lws)
  - [4.1.3 Test 8: Inequality Branching](#test-8-inequality-branching-8_inequality_branchings)
  - [4.1.4 Test 9: Add Upper Immediate to PC](#test-9-add-upper-immediate-to-pc-9_auipcs)
  [4.2 Results](#results)
    
## Overview

This section extends the reduced RV32I core from a 9-instruction subset to the full 37-instruction RV32I base integer ISA. The original design already implemented a working single-cycle datapath with a compact control unit targeting a minimal, but functional, subset of instructions. The work presented here **keeps the same overall datapath structure** and **systematically enriches the control logic** so that all arithmetic/logic, load/store, branch, and control-flow instructions defined in RV32I are supported.

The key idea is to move from a “special-case” control unit (hard-coding behaviour for a few instructions) to a **fully decoded, opcode-driven controller** that distinguishes instruction *types* (R, I, S, B, U, J) and handles all funct3/funct7 variants, while remaining compatible with the original modules (ALU, PC update logic, register file, sign-extension block, and memory interface).

---
## Implementation

### Instruction Set Coverage

#### Reduced 9-Instruction Subset (Previous Section)

The initial control unit supported the following 9 instructions:

| # | Mnemonic | Type | Opcode (binary) | funct3 | funct7   | Brief description                            |
|---|----------|------|-----------------|--------|----------|----------------------------------------------|
| 1 | `ADDI`   | I    | `0010011`       | `000`  | –        | Add sign-extended immediate to `rs1`.        |
| 2 | `BNE`    | B    | `1100011`       | `001`  | –        | Branch if `rs1 != rs2`.                      |
| 3 | `ADD`    | R    | `0110011`       | `000`  | `0000000`| Register-register add.                       |
| 4 | `LW`     | I    | `0000011`       | `010`  | –        | Load 32-bit word from memory.                |
| 5 | `LBU`    | I    | `0000011`       | `100`  | –        | Load zero-extended byte from memory.         |
| 6 | `JALR`   | I/J* | `1100111`       | `000`* | –        | Jump to `rs1 + imm`, write return PC to `rd`.|
| 7 | `SB`     | S    | `0100011`       | `000`  | –        | Store byte to memory.                        |
| 8 | `JAL`    | J    | `1101111`       | –      | –        | PC-relative jump, write return PC to `rd`.   |
| 9 | `LUI`    | U    | `0110111`       | –      | –        | Load 20-bit upper immediate into `rd`.       |

> *In the reduced version, `JALR` is treated as its own control-flow case and the funct3 field is not fully generalised.

---

#### Full 37-Instruction RV32I Subset (This Section)

The extended control unit now covers **all 37 base RV32I instructions**, grouped by type.

|# | Mnemonic | Type | Opcode (binary) | funct3 | funct7   | Brief description                            |
|---|----------|------|-----------------|--------|----------|----------------------------------------------|
| 1 | `LUI`    | U    | `0110111`       | –      | –        | Load upper 20 bits of immediate into `rd`.   |
| 2 | `AUIPC`  | U    | `0010111`       | –      | –        | `rd = PC + (imm << 12)`.                     |
| 3 | `JAL`    | J    | `1101111`       | –      | –        | PC-relative jump, write return PC to `rd`.   |
| 4 | `JALR`   | I/J* | `1100111`       | `000`* | –        | Jump to `rs1 + imm`, write return PC to `rd`.|
| 5 | `BEQ`    | B    | `1100011`       | `000`  | –        | Branch if `rs1 == rs2`.                      |
| 6 | `BNE`    | B    | `1100011`       | `001`  | –        | Branch if `rs1 != rs2`.                      |
| 7 | `BLT`    | B    | `1100011`       | `100`  | –        | Branch if `rs1 < rs2` (signed).              |
| 8 | `BGE`    | B    | `1100011`       | `101`  | –        | Branch if `rs1 >= rs2` (signed).             |
| 9 | `BLTU`   | B    | `1100011`       | `110`  | –        | Branch if `rs1 < rs2` (unsigned).            |
|10 | `BGEU`   | B    | `1100011`       | `111`  | –        | Branch if `rs1 >= rs2` (unsigned).           |
|11 | `LB`     | I    | `0000011`       | `000`  | –        | Load sign-extended byte from memory.         |
|12 | `LH`     | I    | `0000011`       | `001`  | –        | Load sign-extended half-word from memory.    |
|13 | `LW`     | I    | `0000011`       | `010`  | –        | Load 32-bit word from memory.                |
|14 | `LBU`    | I    | `0000011`       | `100`  | –        | Load zero-extended byte from memory.         |
|15 | `LHU`    | I    | `0000011`       | `101`  | –        | Load zero-extended half-word from memory.    |
|16 | `SB`     | S    | `0100011`       | `000`  | –        | Store byte to memory.                        |
|17 | `SH`     | S    | `0100011`       | `001`  | –        | Store half-word to memory.                   |
|18 | `SW`     | S    | `0100011`       | `010`  | –        | Store 32-bit word to memory.                 |
|19 | `ADDI`   | I    | `0010011`       | `000`  | –        | Add sign-extended immediate to `rs1`.        |
|20 | `SLTI`   | I    | `0010011`       | `010`  | –        | Set `rd = 1` if `rs1 < imm` (signed).        |
|21 | `SLTIU`  | I    | `0010011`       | `011`  | –        | Set `rd = 1` if `rs1 < imm` (unsigned).      |
|22 | `XORI`   | I    | `0010011`       | `100`  | –        | Bitwise XOR of `rs1` and immediate.          |
|23 | `ORI`    | I    | `0010011`       | `110`  | –        | Bitwise OR of `rs1` and immediate.           |
|24 | `ANDI`   | I    | `0010011`       | `111`  | –        | Bitwise AND of `rs1` and immediate.          |
|25 | `SLLI`   | I    | `0010011`       | `001`  | –        | Logical left shift by immediate shamt.       |
|26 | `SRLI`   | I    | `0010011`       | `101`  | –        | Logical right shift by immediate shamt.      |
|27 | `SRAI`   | I    | `0010011`       | `101`  | –        | Arithmetic right shift by immediate shamt.   |
|28 | `ADD`    | R    | `0110011`       | `000`  | `0000000`| Register-register add.                       |
|29 | `SUB`    | R    | `0110011`       | `000`  | `0100000`| Register-register subtract.                  |
|30 | `SLL`    | R    | `0110011`       | `001`  | `0000000`| Logical left shift by `rs2[4:0]`.           |
|31 | `SLT`    | R    | `0110011`       | `010`  | `0000000`| Set `rd = 1` if `rs1 < rs2` (signed).        |
|32 | `SLTU`   | R    | `0110011`       | `011`  | `0000000`| Set `rd = 1` if `rs1 < rs2` (unsigned).      |
|33 | `XOR`    | R    | `0110011`       | `100`  | `0000000`| Bitwise XOR of `rs1` and `rs2`.              |
|34 | `SRL`    | R    | `0110011`       | `101`  | `0000000`| Logical right shift by `rs2[4:0]`.          |
|35 | `SRA`    | R    | `0110011`       | `101`  | `0100000`| Arithmetic right shift by `rs2[4:0]`.       |
|36 | `OR`     | R    | `0110011`       | `110`  | `0000000`| Bitwise OR of `rs1` and `rs2`.               |
|37 | `AND`    | R    | `0110011`       | `111`  | `0000000`| Bitwise AND of `rs1` and `rs2`.              |


### Control Unit Evolution: From 9 to 37 Instructions

To go from the reduced 9-instruction core to the full 37-instruction RV32I implementation, the control unit was **generalised and extended** while keeping compatibility with the original datapath:

- **Richer ALU control**:  
  `ALUCtrl` was widened from **3 bits to 4 bits**, providing enough unique codes for all arithmetic, logical, comparison, and shift operations (`ADD`, `SUB`, {`AND`,`OR`,`XOR`}, {`SLT`,`SLTU`}, {`SLL`,`SRL`,`SRA`}, plus `LUI`/`AUIPC` behaviours).

- **Additional comparison inputs for branches**:  
  The controller now takes three status inputs (`EQ`, `LT`, `LTU`) instead of only `EQ`, allowing it to implement **all six branch instructions** (`BEQ`, `BNE`, `BLT`, `BGE`, `BLTU`, `BGEU`) by steering `PCSrc` based on signed and unsigned comparisons.

- **Load/store size and sign handling**:  
  The previous single-bit `ByteWrite` was replaced by a **2-bit `SizeWrite`** signal to distinguish byte, half-word, and word stores (`SB`, `SH`, `SW`). For loads, two new signals, **`LoadSize` (2 bits)** and **`LoadUnsigned`**, were added so that the data memory block can correctly implement `LB`, `LH`, `LW`, `LBU`, and `LHU`.

- **PC-relative operand selection (`ALUsrc2`)**:  
  A new control line **`ALUsrc2`** selects between `rs1` and a saved `PC` value as the first ALU operand. This is required for **`AUIPC`**.

- **Systematic opcode-based decoding**:  
  Instead of several nested `if`/`else` blocks, the new controller uses a `case(op)` structure with **named opcode constants** (`OPC_LUI`, `OPC_AUIPC`, `OPC_JAL`, `OPC_JALR`, `OPC_BRANCH`, `OPC_LOAD`, `OPC_STORE`, `OPC_OPIMM`, `OPC_OP`). Within each opcode, `funct3`, `funct7`, and `imm[11:5]` are decoded to select the exact instruction. This makes the controller scalable and easier to read.

- **Preserved interfaces and defaults**:  
  Signals such as `RegWrite`, `ImmSrc`, `PCSrc`, `ResultSrc`, and `MemWrite` retain the same roles as in the 9-instruction version, so the existing datapath modules (register file, sign-extension unit, PC logic, and data memory) can be reused with only minimal, local changes .

Together, these changes transform the original “minimal subset” controller into a complete **RV32I-compliant control unit**, while maintaining the same overall architectural style introduced in the previous section.

---

### New Multiplexer: PC vs Register (`mux_pcVSreg`)

A key addition is the multiplexer selecting between `rs1` (register source 1) and `pc_save` (program counter) for ALU operand 1.
This design exploits an important observation about the RISC-V ISA:

**The PC is never paired with a register operand, it is always paired with an immediate.**

Instruction that use PC as an operand in the ALU (JAL uses PC but not as an operand in the ALU) :
- `AUIPC`: Computes `PC + U-immediate`

Since these instructions always use an immediate for the second operand, we can safely multiplex between:
- `in0`: Register value (`regOp`) for R-type, I-type, S-type, B-type instructions
- `in1`: Program counter (`pc_save`) for `AUIPC`

The select signal `ALUsrc2` is set by the control unit:
- `ALUsrc2 = 0`: Use register (`rs1`)
- `ALUsrc2 = 1`: Use PC

#### Implementation

```systemverilog
mux mux_pcVSreg(
    .in0(regOp),      // Register source 1
    .in1(pc_save),    // Program counter
    .sel(ALUsrc2),    // Control signal from control unit
    .out(ALUop1)      // To ALU operand 1
);
```

---

### Extended ALU Control

The ALU control signal was expanded from 3 bits to 4 bits to support additional operations.

| Signal | 9-Instruction | 37-Instruction |
|--------|---------------|----------------|
| Width | `[2:0] ALUctrl` | `[3:0] ALUCtrl` |
| Operations | ADD, SUB, AND, OR, SLT | ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU, LUI passthrough, AUIPC |

#### ALU Control Encoding (4-bit)

| ALUCtrl | Operation |
|---------|-----------|
| `0000` | ADD |
| `0001` | SUB |
| `0010` | AND |
| `0011` | OR |
| `0100` | XOR |
| `0101` | SLL (Shift Left Logical) |
| `0110` | SRL (Shift Right Logical) |
| `0111` | SRA (Shift Right Arithmetic) |
| `1000` | SLT (Set Less Than, signed) |
| `1001` | SLTU (Set Less Than, unsigned) |
| `1010` | LUI passthrough (output operand 2) |
| `1011` | AUIPC (ADD with PC) |

---

### Extended Branch Comparison Signals

The 9-instruction version only supported `BEQ` with a single equality flag. The full implementation adds signed and unsigned comparison outputs.

```systemverilog
// 9-Instruction Version
output logic EQ

// 37-Instruction Version
output logic EQ,   // Equal (for BEQ, BNE)
output logic LT,   // Less Than, signed (for BLT, BGE)
output logic LTU   // Less Than, unsigned (for BLTU, BGEU)
```

#### Branch Instruction Support

| Branch | Condition |
|--------|-----------|
| `BEQ` | `EQ == 1` |
| `BNE` | `EQ == 0` |
| `BLT` | `LT == 1` |
| `BGE` | `LT == 0` |
| `BLTU` | `LTU == 1` |
| `BGEU` | `LTU == 0` |

---

### Memory Interface Extensions

#### Store Operations

The `ByteWrite` signal was replaced with a 2-bit `SizeWrite` signal to support all store widths.

| SizeWrite | Operation | Bytes Written |
|-----------|-----------|---------------|
| `2'b00` | `SB` (Store Byte) | 1 |
| `2'b01` | `SH` (Store Halfword) | 2 |
| `2'b10` | `SW` (Store Word) | 4 |

#### Load Operations

Two new signals were added to support variable-width loads with sign/zero extension.

| Signal | Purpose |
|--------|---------|
| `LoadSize[1:0]` | Specifies load width (byte, halfword, word) |
| `LoadUnsigned` | Selects zero-extension (1) or sign-extension (0) |

| LoadSize | LoadUnsigned | Operation |
|----------|--------------|-----------|
| `2'b00` | `0` | `LB` (Load Byte, sign-extend) |
| `2'b00` | `1` | `LBU` (Load Byte, zero-extend) |
| `2'b01` | `0` | `LH` (Load Halfword, sign-extend) |
| `2'b01` | `1` | `LHU` (Load Halfword, zero-extend) |
| `2'b10` | `X` | `LW` (Load Word) |


---
## Final Circuit Schematic:

![diagram](schematic.png)


---
## Testing:

We first verified each individual block, such as the control unit and ALU, writing c++ testbenches: `alu_tb.cpp` and `control_tb.cpp` .Once confident in the core modules, we proceeded to evaluate the full datapath integration using the five reference tests originally provided with the reduced RV32I version. We additionally wrote custom assembly programs that tested the new behaviors introduced in the full 37-instruction implementation.

### Assembly Test Programs:


#### Test 6: Branch Equal (`6_beq.s`)

##### Purpose
Tests the `BEQ` (Branch if Equal) instruction in a loop context.

##### Code
```asm
.text
.globl main
main:
    addi t1, zero, 1
    li a0, 0
iloop:
    addi a0, a0, 1
    beq t1, a0, iloop
```

##### Execution Trace

| Cycle | Instruction | a0 | t1 | Branch Taken? |
|-------|-------------|----|----|---------------|
| 1 | `addi t1, zero, 1` | 0 | 1 | - |
| 2 | `li a0, 0` | 0 | 1 | - |
| 3 | `addi a0, a0, 1` | 1 | 1 | - |
| 4 | `beq t1, a0, iloop` | 1 | 1 | Yes (1 == 1) |
| 5 | `addi a0, a0, 1` | 2 | 1 | - |
| 6 | `beq t1, a0, iloop` | 2 | 1 | No (1 ≠ 2) |

##### Expected Output
```
a0 = 2
```

##### What It Tests
-`BEQ` instruction correctly compares two registers
- Branch taken when registers are equal
- Branch not taken when registers differ
- Loop control flow with conditional branching

---

#### Test 7: Store Byte & Load Word (`7_sb_lw.s`)

##### Purpose
Tests byte-level memory operations and little-endian word construction.

##### Code
```asm
.text
.globl main
main:
    li t1, 0
    li a0, 1
    sb a0, 0(zero)
    sb a0, 1(zero)
    sb t1, 2(zero)
    sb t1, 3(zero)
    lw a0, 0(zero)
```

##### Memory Layout After Stores

| Address | Value | Source |
|---------|-------|--------|
| 0x00 | 0x01 | `sb a0, 0(zero)` |
| 0x01 | 0x01 | `sb a0, 1(zero)` |
| 0x02 | 0x00 | `sb t1, 2(zero)` |
| 0x03 | 0x00 | `sb t1, 3(zero)` |

##### Word Construction (Little-Endian)

```
Address:    0x03    0x02    0x01    0x00
Value:      0x00    0x00    0x01    0x01
            ────────────────────────────
Word:              0x00000101 = 257
```

##### Expected Output
```
a0 = 257 (0x00000101)
```

##### What It Tests
-`SB` (Store Byte) instruction
- `LW` (Load Word) instruction
- Little-endian byte ordering
- Memory addressing with zero base register
- Multi-byte value construction from individual bytes

---

#### Test 8: Inequality Branching (`8_inequality_branching.s`)

##### Purpose
Tests all inequality branch instructions, including signed vs unsigned comparison edge cases.

##### Code
```asm
.text
.globl main
main:
    addi t2, zero, 2
    li a0, -5
    bltu a0, t2, mloop      # Unsigned: -5 = 0xFFFFFFFB > 2
    blt a0, t2, iloop       # Signed: -5 < 2
mloop:
    bgeu a0, t2, endm       # Unsigned: 0xFFFFFFFB >= 2
iloop:
    addi a0, a0, 1
    blt a0, t2, iloop       # Loop while a0 < 2 (signed)
    bge a0, t2, endi        # Exit when a0 >= 2 (signed)
endm:
    li a0, 10
endi:
```

##### Key Insight: Signed vs Unsigned Comparison

| Value | Signed Interpretation | Unsigned Interpretation |
|-------|----------------------|------------------------|
| `0xFFFFFFFB` | -5 | 4,294,967,291 |

When comparing `-5` with `2`:
- **Signed (`BLT`)**: -5 < 2 → **True**
- **Unsigned (`BLTU`)**: 4,294,967,291 < 2 → **False**

##### Expected Output
```
a0 = 2
```

##### What It Tests
- `BLT` (Branch if Less Than, signed)
- `BGE` (Branch if Greater or Equal, signed)
- `BLTU` (Branch if Less Than, unsigned)
- `BGEU` (Branch if Greater or Equal, unsigned)
- Signed vs unsigned comparison semantics
- Negative number handling in comparisons
- Complex control flow with multiple branch targets

---

#### Test 9: Add Upper Immediate to PC (`9_auipc.s`)

##### Purpose
Tests the `AUIPC` instruction which adds an upper immediate to the program counter.

##### Code
```asm
.text
.globl main
main:
    auipc a0, 1
```

##### Calculation

The program is loaded at address `0xBFC00000`:

```
a0 = PC + (imm << 12)
a0 = 0xBFC00000 + (1 << 12)
a0 = 0xBFC00000 + 0x00001000
a0 = 0xBFC01000
```

##### Expected Output

```
a0 = 0xBFC01000 = 3217035264 (decimal)
```

##### What It Tests
- `AUIPC` instruction
- PC-relative address calculation
- Correct datapath:ALU input (PC) via `ALUsrc2` multiplexer

---
### Results
