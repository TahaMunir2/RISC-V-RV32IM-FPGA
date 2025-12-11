Personal statement · MD
Copy

# Personal Statement: Contributions to RISC-V Processor Project

## Table of Contents
- [1. Overview](#1-overview)
- [2. Single-Cycle Processor](#2-single-cycle-processor)
- [3. Full 37-Instruction Implementation](#3-full-37-instruction-implementation)
  - [3.1 Data Path Expansion](#31-data-path-expansion)
  - [3.2 Control Path Design](#32-control-path-design)
  - [3.3 Integration](#33-integration)
  - [3.4 Testing](#34-testing)
- [4. Pipelined Processor](#4-pipelined-processor)
  - [4.1 Forwarding Logic](#41-forwarding-logic)
  - [4.2 Top-Level Integration](#42-top-level-integration)
  - [4.3 Testing](#43-testing)
- [5. Cache Implementation](#5-cache-implementation)
  - [5.1 L1 Cache Design](#51-l1-cache-design)
  - [5.2 Top-Level Integration](#52-top-level-integration)
  - [5.3 Testing](#53-testing)
- [6. Branch Prediction](#6-branch-prediction)
  - [6.1 Branch Predictor](#61-branch-predictor)
  - [6.2 PCSrcF Assertion Logic](#62-pcsrcf-assertion-logic)
  - [6.3 Top-Level Integration](#63-top-level-integration)
  - [6.4 Testing](#64-testing)
- [7. Out-of-Order Superscalar (Arithmetic Instructions)](#7-out-of-order-superscalar-arithmetic-instructions)
  - [7.1 Register Alias Table (RAT)](#71-register-alias-table-rat)
  - [7.2 Re-Order Buffer (ROB)](#72-re-order-buffer-rob)
  - [7.3 Register Update Unit (RUU)](#73-register-update-unit-ruu)
  - [7.4 Pipelined Design](#74-pipelined-design)
  - [7.5 Overall Integration](#75-overall-integration)
- [8. Out-of-Order Superscalar (Full Version with Loads)](#8-out-of-order-superscalar-full-version-with-loads)
  - [8.1 Adapting Data Memory for Superscalar](#81-adapting-data-memory-for-superscalar)
  - [8.2 Doubling the Common Data Bus Width](#82-doubling-the-common-data-bus-width)
  - [8.3 Load Instruction Integration](#83-load-instruction-integration)
- [9. Mistakes Made](#9-mistakes-made)
- [10. Reflections](#10-reflections)

---

## 1. Overview

My passion for digital electronics and computer architecture drove my engagement throughout this project and the extensive research I undertook in order to implement more advanced concepts. In this statement, I present my work spanning multiple processor architectures, covering not only design and implementation but also the verification strategies I developed and the reasoning behind critical architectural decisions. I contributed to the development of several processor implementations, beginning with the single-cycle design and progressing through pipelining, cache integration, and branch prediction. The most substantial portion of my work focused on designing and implementing an out-of-order superscalar execution engine, which required thorough research beyond the scope of the course material. This involved understanding and building components such as the Register Aliasing Table, Re-Order Buffer, and Register Update Unit, culminating in a fully functional superscalar processor capable of handling both arithmetic and load instructions. Additionally, this document covers the strategies I used to address technical challenges, mistakes encountered along the way and their subsequent resolution, as well as the insights and lessons I gained from this experience.

---

## 2. Single-Cycle Processor

I worked on the core datapath components: data memory, register file, and ALU. The design choices I made here made it easier to extend the processor later.

**Data Memory:** I separated reads and writes into combinational and sequential logic. Reads don't change memory, so they can be combinational. Writes need to be clocked to avoid corrupting data:

```systemverilog
always_comb begin
    if(ByteWrite) begin
        dout[7:0] = ram_array[A];
        dout[31:8] = 24'b0;
    end
    else begin
        dout[7:0] = ram_array[A];
        dout[15:8] = ram_array[A+1];
        dout[23:16] = ram_array[A+2];
        dout[31:24] = ram_array[A+3];
    end
end

always_ff @(posedge clk) begin
    if (MemWrite && ByteWrite)
        ram_array[A] <= WD[7:0];
end
```

I used a single `ByteWrite` signal to handle both byte and word operations in the same module, so I didn't need separate memory interfaces. I used little-endian ordering to match the RISC-V spec: the least significant byte is stored at the lowest address. You can see this in the read logic where `ram_array[A]` maps to `dout[7:0]` (the lowest byte), and `ram_array[A+3]` maps to `dout[31:24]` (the highest byte).

**Register File:** I implemented two read ports and one write port, which is enough for RV32I. One important detail was hardwiring `x0` to zero in the read logic:

```systemverilog
always_comb begin
    RD1 = regfile_array[AD1];
    RD2 = regfile_array[AD2];
    A0  = regfile_array[10];
    regfile_array[0] = 0;
end
```

**ALU:** Instead of computing separate flags for each branch condition, I used a single equality flag (`EQ`) from subtraction. This kept the hardware simple and made it easy to add more branch types later:

```systemverilog
always_comb begin
    ALUout = 0;
    EQ = 1'b0;
    if (ALUop1 - ALUop2 == 0) EQ = 1'b1;
    case (ALUctrl)
        3'b000 : ALUout = ALUop1 + ALUop2;
        3'b001 : ALUout = ALUop1 - ALUop2;
        3'b010 : ALUout = ALUop1 & ALUop2;
        3'b011 : ALUout = ALUop1 | ALUop2;
        3'b100 : ALUout = ALUop2;
        default: ALUout = 32'b0;
    endcase
end
```

Setting outputs to zero at the start of the combinational block prevents latch inference. I kept this practice throughout the project.

I also created an ALU testbench during this phase, which I later improved when expanding to the full 37-instruction implementation.

---

## 3. Full 37-Instruction Implementation

For the full documentation of this section, see the [GitHub README](https://github.com/TahaMunir2/Team5/blob/FULL-RV32I/README.md).

Extending from 9 to 37 instructions required changes to both the datapath and control path. The goal was to keep the same overall structure while making it general enough to handle all RV32I instructions.

### 3.1 Data Path Expansion

**New Multiplexer for AUIPC:** I added a multiplexer (`mux_pcVSreg`) to select between `rs1` and the program counter as the first ALU operand. This was needed for `AUIPC`, which computes `PC + immediate`.

I noticed something useful about RISC-V: the PC is never paired with a register operand—it's always paired with an immediate. This meant I could safely add this mux without affecting other instructions.

```systemverilog
mux mux_pcVSreg(
    .in0(regOp),      // Register source 1
    .in1(pc_save),    // Program counter
    .sel(ALUsrc2),    // Control signal
    .out(ALUop1)      // To ALU operand 1
);
```

**Extended ALU:** I widened `ALUCtrl` from 3 bits to 4 bits to support all the new operations:

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
| `1010` | LUI passthrough |
| `1011` | AUIPC |

**Extended Branch Comparisons:** The original design only had an `EQ` flag for `BNE`. I added `LT` (signed less than) and `LTU` (unsigned less than) to support all six branch instructions: `BEQ`, `BNE`, `BLT`, `BGE`, `BLTU`, `BGEU`.

**Memory Interface Extensions:** I replaced the single-bit `ByteWrite` with a 2-bit `SizeWrite` signal to distinguish between byte, half-word, and word stores. For loads, I added `LoadSize` (2 bits) and `LoadUnsigned` so the data memory can handle `LB`, `LH`, `LW`, `LBU`, and `LHU` correctly.

### 3.2 Control Path Design

The original control unit used nested `if`/`else` blocks for 9 instructions. This wouldn't scale, so I rewrote it using a `case(op)` structure with named opcode constants:

```systemverilog
localparam OPC_LUI    = 7'b0110111;
localparam OPC_AUIPC  = 7'b0010111;
localparam OPC_JAL    = 7'b1101111;
localparam OPC_JALR   = 7'b1100111;
localparam OPC_BRANCH = 7'b1100011;
localparam OPC_LOAD   = 7'b0000011;
localparam OPC_STORE  = 7'b0100011;
localparam OPC_OPIMM  = 7'b0010011;
localparam OPC_OP     = 7'b0110011;
```

Within each opcode case, I decode `funct3` and `funct7` to select the exact instruction. This made the controller easier to read and extend.

The key signals and their roles:
- `RegWrite`, `ImmSrc`, `PCSrc`, `ResultSrc`, `MemWrite` kept the same meaning as before
- `ALUsrc2` was added for the PC vs register mux
- `SizeWrite`, `LoadSize`, `LoadUnsigned` were added for memory operations

### 3.3 Integration

I kept all the original module interfaces intact. The register file, sign-extension unit, PC logic, and data memory only needed small changes to accept the new control signals. This made integration straightforward and I could test each change in isolation before connecting everything.

### 3.4 Testing

I first verified individual blocks, such as the control unit and ALU, writing c++ testbenches: `alu_tb.cpp` and `control_tb.cpp` .

Once confident in the core modules, I proceeded to evaluate the full integration using the five reference tests originally provided with the reduced RV32I version. I additionally wrote custom assembly programs that tested the new behaviors introduced in the full 37-instruction implementation each targeting specific instruction groups

The 10 assembly programs tested are listed below and an explanation for each one of them can be found on [GitHub README](https://github.com/TahaMunir2/Team5/blob/FULL-RV32I/README.md) :

1. **Basic arithmetic** (`ADDI`, `ADD`, `SUB`)
2. **Logical operations** (`AND`, `OR`, `XOR`, `ANDI`, `ORI`, `XORI`)
3. **Comparisons** (`SLT`, `SLTU`, `SLTI`, `SLTIU`)
4. **Shifts** (`SLL`, `SRL`, `SRA`, `SLLI`, `SRLI`, `SRAI`)
5. **Loads and stores** (`LB`, `LH`, `LW`, `LBU`, `LHU`, `SB`, `SH`, `SW`)
6. **Branches** (`BEQ`, `BNE`, `BLT`, `BGE`, `BLTU`, `BGEU`)
7. **Jumps** (`JAL`, `JALR`)
8. **Upper immediates** (`LUI`, `AUIPC`)

One test I'm particularly happy with is the signed vs unsigned branch test. It uses `-5` (which is `0xFFFFFFFB` in two's complement) and compares it with `2`:
- Signed (`BLT`): -5 < 2 → **True**
- Unsigned (`BLTU`): 4,294,967,291 < 2 → **False**

This catches bugs where signed and unsigned comparisons are mixed up.

![diagram](images/verifyfullriscv.jpg)

All 37 instructions pass verification.

---

## 4. Pipelined Processor

### 4.1 Forwarding Logic

### 4.2 Top-Level Integration

### 4.3 Testing

---

## 5. Cache Implementation

### 5.1 L1 Cache Design

### 5.2 Top-Level Integration

### 5.3 Testing

---

## 6. Branch Prediction

### 6.1 Branch Predictor

### 6.2 PCSrcF Assertion Logic

### 6.3 Top-Level Integration

### 6.4 Testing

---

## 7. Out-of-Order Superscalar (Arithmetic Instructions)

### 7.1 Register Alias Table (RAT)

### 7.2 Re-Order Buffer (ROB)

### 7.3 Register Update Unit (RUU)

### 7.4 Pipelined Design

### 7.5 Overall Integration

---

## 8. Out-of-Order Superscalar (Full Version with Loads)

### 8.1 Adapting Data Memory for Superscalar

### 8.2 Doubling the Common Data Bus Width

### 8.3 Load Instruction Integration

---

## 9. Mistakes Made

---

## 10. Reflections

---
