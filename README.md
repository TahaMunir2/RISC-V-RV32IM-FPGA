# Full RV32I (37-Instruction):

## Overview

This section extends the reduced RV32I core from a 9-instruction subset to the full 37-instruction RV32I base integer ISA. The original design already implemented a working single-cycle datapath with a compact control unit targeting a minimal, but functional, subset of instructions. The work presented here **keeps the same overall datapath structure** and **systematically enriches the control logic** so that all arithmetic/logic, load/store, branch, and control-flow instructions defined in RV32I are supported.

The key idea is to move from a “special-case” control unit (hard-coding behaviour for a few instructions) to a **fully decoded, opcode-driven controller** that distinguishes instruction *types* (R, I, S, B, U, J) and handles all funct3/funct7 variants, while remaining compatible with the original modules (ALU, PC update logic, register file, sign-extension block, and memory interface).

---

## Instruction Set Coverage

### Reduced 9-Instruction Subset (Previous Section)

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

### Full 37-Instruction RV32I Subset (This Section)

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


## Control Unit Evolution: From 9 to 37 Instructions

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
