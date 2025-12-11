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
- [5. Branch Prediction](#5-branch-prediction)
  - [5.1 Branch Predictor](#51-branch-predictor)
  - [5.2 PCSrcF Assertion Logic](#52-pcsrcf-assertion-logic)
  - [5.3 Top-Level Integration](#53-top-level-integration)
  - [5.4 Testing](#54-testing)
- [6. Cache Implementation](#6-cache-implementation)
  - [6.1 L1 Cache Design](#61-l1-cache-design)
  - [6.2 Top-Level Integration](#62-top-level-integration)
  - [6.3 Testing](#63-testing)
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

My passion for digital electronics and computer architecture drove my engagement throughout this project and the extensive research I undertook in order to implement more advanced concepts. In this statement, I present my work spanning multiple processor architectures, covering not only design and implementation but also the verification strategies I developed and the reasoning behind critical architectural decisions. I contributed to the development of several processor implementations, beginning with the single-cycle design and progressing through pipelining, cache integration, and branch prediction. The most substantial portion of my work focused on designing and implementing an out-of-order superscalar execution engine, which required thorough research beyond the scope of the course material. This involved understanding and building components such as the Register Aliasing Table, Re-Order Buffer, and Register Update Unit, culminating in a fully functional Out-of Order superscalar processor capable of handling both arithmetic and load instructions. Additionally, this document covers the strategies I used to address technical challenges, mistakes encountered along the way and their subsequent resolution, as well as the insights and lessons I gained from this experience.

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

I noticed something useful about RISC-V: the PC is never paired with a register operand, it's always paired with an immediate. This meant I could safely add this mux without affecting other instructions.

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

![diagram](../images/verifyfullriscv.jpg)

All 37 instructions pass verification.

---

## 4. Pipelined Processor

For the full documentation of this section, see the [GitHub README](https://github.com/TahaMunir2/Team5/blob/PIPELINING/README.md#2-implementation).

Pipelining lets different parts of multiple instructions run at the same time. Instead of finishing one instruction before starting the next, we divide the processor into 5 stages (Fetch, Decode, Execute, Memory, Writeback) with registers between them. This increases throughput significantly.

### 4.1 Forwarding Logic

Data hazards happen when an instruction needs a result that's still in the pipeline. Instead of stalling, I added forwarding paths to send data directly from where it's available to where it's needed.

The key insight is that a result computed by the ALU is available at the end of the Execute stage, before it gets written back to the register file. I added two 4-to-1 multiplexers at the ALU inputs to select between three sources:

```systemverilog
mux4 forwardingRS1(
    .in0(RD1E),           // 00: Normal path from register file
    .in1(ResultW),        // 01: Forward from Writeback stage
    .in2(ALUResultM),     // 10: Forward from Memory stage
    .in3(RD1E),           // 11: Unused (default to register file)
    .select_line(ForwardAE),
    .out(SrcAE)    
);

mux4 forwardingRS2(
    .in0(RD2E),           // 00: Normal path from register file
    .in1(ResultW),        // 01: Forward from Writeback stage
    .in2(ALUResultM),     // 10: Forward from Memory stage
    .in3(RD2E),           // 11: Unused (default to register file)
    .select_line(ForwardBE),
    .out(WriteDataE)    
);
```

The Hazard Unit monitors register addresses across pipeline stages and generates `ForwardAE` and `ForwardBE` to control these muxes.

### 4.2 Top-Level Integration

Integrating the pipeline required careful attention to signal naming and control signal propagation.

**Signal Naming Convention:** With pipeline registers, the same signal exists in multiple stages for different instructions. I used suffixes to distinguish them:

| Suffix | Stage | Example |
|--------|-------|---------|
| `F` | Fetch | `PCF`, `InstrF` |
| `D` | Decode | `PCD`, `RD1D`, `RD2D` |
| `E` | Execute | `PCE`, `ALUResultE` |
| `M` | Memory | `PCM`, `ALUResultM` |
| `W` | Writeback | `ResultW`, `RdW` |

**Control Signal Propagation:** The control unit itself stays the same as the single-cycle version. The difference is that all control signals must travel through the pipeline registers alongside the data. For example, `MemWrite` generated in Decode must arrive at the Memory stage exactly when the corresponding instruction gets there.

**Register File Timing:** A key design strategie, implemented in the Register File, was to write on the falling edge of the clock instead of the rising edge. This lets:
- First half of cycle: Write to register file (Writeback stage)
- Second half of cycle: Read from register file (Decode stage)

### 4.3 Testing

#### 1) Pipelined Overlapping (No Hazards)
This test demonstrates correct instruction overlapping in the pipeline when no data or control hazards are present, confirming that multiple instructions execute simultaneously across different pipeline stages.
Here is the assembly code run by the processor and the results are shown in the waveform below:
This assembly code can be found in the `asm` folder and was created for testing the instruction overlapping characteristic introduced by pipelining.
```
.text
.globl main
main:
    addi    t0, zero, 10        # t0 = 10 
    addi    t1, zero, 20        # t1 = 20 
    addi    t2, zero, 30        # t2 = 30 
    addi    t3, zero, 40        # t3 = 40
    addi    a0, t3, 0           # a0 = t3 = 40
```
**Waveform:**
![diagram](../images/pipeliningparrallelism.jpg)

---

#### 2) Data Hazards: Read After Write (RAW)
This test verifies the forwarding unit by demonstrating how RAW hazards are resolved through the forwarding muxes, showing the change in the forward select lines when a dependent instruction requires data from a previous instruction still in the pipeline.
Here is the assembly code run by the processor and the results are shown in the waveform below:
I modified the assembly code provided in the `asm` folder `2_li_add` such that `li` is replaced with `addi`.
`li` is broken down into `lui` and `addi`, thus when `add a0, t1, t2` is in the execute stage of the original program `2_li_add` only one of the operand depends on a previous instruction still in the pipeline.
With this modification I have both `addi t1, zero, -900` and `addi t2, 10000` still in the pipeline when `add a0, t1, t2` is in the execute stage.
Note that since `addi` is an I-type instruction -9000 and 10000 are outside the range allowed for the immediate operand. Thus I changed the immediates to 1000 and -900 to adapt to my previous modifications.
Note that I also removed the branch instructions here because they don't provide any insights in demonstrating how RAW hazards are resolved through the forwarding muxes.
```
.text
.globl main
main:
    # li is broken into lui and addi for >12-bit values
    # don't forget that addi sign-extends
    addi t1, zero, -9000    # t1 = -900
    addi t2, zero, 10000    # t2 = 1000
    add a0, t1, t2  # a0 = t1 + t2      (=1000)
```
The `add a0, t1, t2` instruction depends on the values of t1 and t2, which are written by the immediately preceding `addi` instructions still in the pipeline. 
Since these values have not yet been written back to the register file, the forwarding unit detects the RAW hazard and routes the results directly from the Memory and Writeback pipeline registers to the ALU inputs. 
This allows the add instruction to execute correctly without stalling, demonstrating the effectiveness of my forwarding mechanism.
**Waveform:**
![diagram](../images/pipeliningverifyforwarding.jpg)

---

#### 3) Load-Use Hazards
This test demonstrates the 1-cycle stall required when a load instruction is immediately followed by a dependent instruction. The stall is achieved by:
- Disabling (freezing) the FD pipeline register for 1 cycle
- Preventing the program counter from incrementing for 1 cycle
- Flushing the DE pipeline register

To illustrate these points on GTKWave I use the assembly test: `3_lbu_sb`, where I am only interested in the following part:
```
    lbu t3, 0(s0)   # t3 = *(0x00010000)    (=100)
    lbu t4, 1(s0)   # t4 = *(0x00010001)    (=200)
    add a0, t3, t4  # a0 = t3 + t4          (=300)
```
In the following waveform, I can track the cycle in which the `add a0, t3, t4` reaches the Decode stage through the signal `InstrD` and the cycle in which it reaches the Execute stage through the ALU operands value (0xC8 corresponds to 200 and 0x64 corresponds to 100).
An important observation is that the Decode stage and the Execute stage are separated by 1 cycle caused by the stall.
The signals causing the stall are also shown in the waveform.
**Waveform:**
![diagram](../images/pipeliningverifyload.jpg)

---

#### 4) Control Hazards: Branch Misprediction
Branches are predicted as not taken by default (see [Branch Prediction Enhancement](https://github.com/TahaMunir2/Team5/tree/branchprediction) for improved prediction). When a branch reaches the execute stage and is determined to be taken, a flush occurs to discard the incorrectly fetched instructions.
I used the assembly code `6_beq` with a small modification consisting of adding 2 instructions after the branch to illustrate how a flush occurs to discard the incorrectly fetched instructions.
```
.text
.globl main
main:
    addi t1, zero, 1
    li a0, 0
iloop:
    addi a0, a0, 1
    beq t1, a0, iloop
    addi a0, a0, 0
    addi a0, a0, 0
```
In the following waveform, I observe the flush signals high when `beq t1, a0, iloop` is in the Execute stage. 
We identify that `beq t1, a0, iloop` is in the Execute stage using the `PCE` signal. 
Crucially, we observe the value of the program counter being redirected correctly to the address of `iloop` corresponding to the value of `(program counter at beq t1, a0, iloop) - 4`:

Value of PCE for `beq t1, a0, iloop` in the Execute stage: **0xBFC0000C**

At the next cycle the value of PCF is: **0xBFC00008** (`PCE - 4`)

**Waveform:**
![diagram](../images/pipeliningverifybranches.jpg)

All test cases pass.

**Performance Analysis:**

I calculated the performance improvement from pipelining using the formula:

```
Execution Time = (# Instructions) × CPI × Tc
```

For a single-cycle processor, the clock period must accommodate the entire critical path:
```
Tc_single = 750 ps
```

For the pipelined processor, the clock period is determined by the slowest stage (Execute):
```
Tc_pipelined = 350 ps
```

Even accounting for stalls (CPI ≈ 1.23 instead of ideal 1.0), the pipelined processor achieves a **1.74× speedup** over the single-cycle design for a 300 billion instruction program:

| Processor | Clock Period | CPI | Execution Time |
|-----------|--------------|-----|----------------|
| Single-cycle | 750 ps | 1.0 | 225 s |
| Pipelined | 350 ps | 1.23 | 129 s |

This demonstrates the fundamental advantage of pipelining: higher throughput through instruction-level parallelism, even at the cost of slightly reduced efficiency per instruction.

---

## 5. Branch Prediction

For the full documentation of this section, see the [GitHub README](https://github.com/TahaMunir2/Team5/blob/branchprediction/README.md).

In the pipelined processor, instructions are fetched assuming `PC + 4`. Branch decisions are only resolved in the Execute stage, meaning incorrect instructions may already be in the pipeline. This causes control hazards that require flushes, wasting cycles.

The baseline approach predicts all branches as not taken, but this performs poorly for loops where backward branches are typically taken repeatedly. I implemented a two-bit dynamic branch predictor to reduce these penalties and integrated in the 5 stage pipelined processor.

### 5.1 Branch Predictor

#### Two Bits Instead of One

A one-bit predictor remembers only the last outcome. The problem is it mispredicts twice per loop: once at the first iteration (no history yet) and once at the last iteration (pattern breaks).

A two-bit predictor requires two consecutive mispredictions before changing its prediction. This means it only mispredicts once per loop instead of twice. 

The four states are: Strongly Taken, Weakly Taken, Weakly Not Taken, and Strongly Not Taken.

#### State Encoding

I intentionally encoded the states so that the MSB directly gives the prediction:

```systemverilog
typedef enum logic [1:0] {
    STRONGLY_NOT_TAKEN = 2'b00,
    WEAKLY_NOT_TAKEN   = 2'b01,
    WEAKLY_TAKEN       = 2'b10,
    STRONGLY_TAKEN     = 2'b11
} my_state;
```

- `0x` → Predict not taken
- `1x` → Predict taken

This means extracting the prediction is just reading a single bit:

```systemverilog
pred_taken = array[predict_index][1];
```

This is a Moore machine: the output depends only on the current state, not the inputs.

The FSM diagram is taken from Harris and Harris book :

![diagram](../images/branchpfsm.jpg)


#### Initialization Choice

```systemverilog
if (rst) begin
    for (int i = 0; i < TARGET_BUFFER_SIZE; i++)
        array[i] <= WEAKLY_NOT_TAKEN;
end
```

On reset, all entries initialize to `WEAKLY_NOT_TAKEN`. I could have also picked `WEAKLY_TAKEN`. However, I intentionally avoided `STRONGLY_TAKEN` or `STRONGLY_NOT_TAKEN` because these extreme states would bias the predictor before any branch history is available.

#### State Transitions

The FSM implements a saturating counter: the state moves toward "strongly taken" when branches are taken, and toward "strongly not taken" when they aren't, but never wraps around.

```systemverilog
case (array[update_index])
    STRONGLY_NOT_TAKEN: next = actual_taken ? WEAKLY_NOT_TAKEN : STRONGLY_NOT_TAKEN;
    WEAKLY_NOT_TAKEN:   next = actual_taken ? WEAKLY_TAKEN     : STRONGLY_NOT_TAKEN;
    WEAKLY_TAKEN:       next = actual_taken ? STRONGLY_TAKEN   : WEAKLY_NOT_TAKEN;
    STRONGLY_TAKEN:     next = actual_taken ? STRONGLY_TAKEN   : WEAKLY_TAKEN;
endcase
```

#### Timing: Negative Edge

```systemverilog
always_ff @(negedge clk)
```

The state update occurs on the falling edge of the clock. This ensures that:
1. The prediction is read during the first half of the cycle (Fetch stage)
2. The state update from Execute happens during the second half, avoiding read-write conflicts

This follows the same strategy used for the register file in the pipelined processor.

### 5.2 PCSrcF Assertion Logic

The main challenge with branch prediction is that two stages compete to control the PC:
- **Fetch stage**: Makes speculative predictions for newly fetched branches
- **Execute stage**: Resolves actual branch outcomes and may need to correct mispredictions

I created the `PCSrcF_assertion` module to arbitrate between them using a priority-based approach.

![diagram](../images/branchppcsrcf.jpg)

#### Priority Logic

**Priority 1 (Highest): Jump Instructions**
```systemverilog
if (JumpE) begin
    PCSrcF = PCSrcE;
    FinalTarget = targetE;
end
```
Jumps (`JAL`/`JALR`) in Execute always take precedence since they are unconditional.

**Priority 2: Misprediction Recovery**
```systemverilog
else if (BranchE && false_prediction) begin
    if (predictionE) begin
        PCSrcF = 2'b11;  // Predicted taken, actually not taken
    end
    else begin
        PCSrcF = 2'b01;  // Predicted not taken, actually taken
        FinalTarget = targetE;
    end
end
```

When Execute detects a misprediction, I correct the PC:

| Prediction | Actual | Recovery Action |
|------------|--------|-----------------|
| Taken | Not Taken | `PCSrcF = 2'b11` : Resume at `PC + 4` (wrong path taken) |
| Not Taken | Taken | `PCSrcF = 2'b01` : Jump to `targetE` (should have branched) |

**Priority 3 (Lowest): New Branch Prediction**
```systemverilog
else begin
    if (BranchF) begin
        if (predictionF) begin
            PCSrcF = 2'b01;
            FinalTarget = targetF;
        end
        else begin
            PCSrcF = 2'b00;
        end
    end
end
```

If no Execute-stage corrections are needed and Fetch contains a branch, I follow the prediction.

#### Output Encoding

| PCSrcF | Next PC Source | Condition |
|--------|----------------|-----------|
| `2'b00` | `PC + 4` (Fetch) | Sequential execution |
| `2'b01` | `FinalTarget` | Branch predicted/confirmed taken |
| `2'b11` | `PCPlus4E` (Execute) | Misprediction recovery |

Note that `2'b00` and `2'b11` both select a `PC + 4` value, but from different stages. When recovering from a "predicted taken, actually not taken" misprediction, I must return to the `PC + 4` of the mispredicted branch, which has propagated to Execute as `PCPlus4E`.

### 5.3 Top-Level Integration

#### Misprediction Detection

I created the `evalprediction` module to compare what I predicted against what actually happened:

```systemverilog
always_comb begin
    false_prediction = 0;
    if (BranchE == 1) begin
        case (PCSrcE)
            2'b00: if (pred_taken)  false_prediction = 1;
            2'b01: if (!pred_taken) false_prediction = 1;
            default: false_prediction = 0;
        endcase
    end
end
```

Defaulting to `0` prevents unnecessary pipeline flushes when no branch is in Execute.

#### Prediction Propagation

The prediction made in Fetch must travel with the instruction to Execute for comparison. I added `predictionE` to the pipeline registers so that when a branch reaches Execute, I still know what prediction was made for it.

#### Hazard Unit Modifications

I modified the hazard unit to only flush on mispredictions or jumps, not on every taken branch:

```systemverilog
if (false_prediction || JumpE) begin
    flush_f_d    = 1;
    flush_d_exec = 1;
end
```

Thus, I achieve the key improvement: when the predictor guesses correctly, I avoid the flush penalty entirely.


### 5.4 Testing

#### Branch Predictor Unit Testing

I created a C++ testbench (`predictor_tb.cpp`) that isolates the branch predictor module and verifies:
- **Initial State**: All entries initialize to `WEAKLY_NOT_TAKEN` after reset
- **State Transitions**: Correct transitions on taken/not-taken outcomes
- **Saturation**: Counter stays at `STRONGLY_TAKEN` or `STRONGLY_NOT_TAKEN` when saturated
- **Misprediction Tolerance**: Two consecutive mispredictions required to flip prediction

#### Full Circuit Testing

I tested using a loop program (`1_addi_bne`) that counts from 0 to 255.

```assembly
.text
.globl main
# this is a modified version of the Lab4 test program
# which doesn't run in an infinite loop
main:
    addi    t1, zero, 0xff      # t1 = 255
    addi    a0, zero, 0x0       # output = 0
mloop:
    addi    a1, zero, 0x0       # i = 0
iloop:
    addi    a0, a1, 0           # output = i
    addi    a1, a1, 1           # i++
    bne     a1, t1, iloop       # if i != 255, goto iloop
    bne     a0, zero, finish    # enter finish state

finish:      # expected result is 254
    bne     a0, zero, finish     # loop forever
```

When the branch predictor correctly predicts the branch outcome, no pipeline flush occurs and execution continues without penalty.

Since the branch predictor's initial state is `WEAKLY_NOT_TAKEN`, it will start prediciting correctly at the second iteration of the loop. 

In the following waveform, we observe that the value of `PCF` ( PC at the fetch stage) decreases by 8 (jumps back by 2 to `iloop`) automaticaly when the branch instruction is fetched.

Thus, we avoid the penalty of waiting 2 extra cycles (until the branch instruction reaches the Execute stage) to jump back to the correct address. 

Note that:
- `0xFE659CE3` corresponds to the instruction : ` bne     a1, t1, iloop `
- `0x00058513` corresponds to the instruction : ` bne     a0, a1, 0 `


**Waveform:**

![diagram](../images/branchpverifyingcorrectpred.jpg)


All test cases pass.

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
