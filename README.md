# Pipelined RISC-V Processor

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
  - [2.1 Pipeline Architecture](#21-pipeline-architecture)
  - [2.2 Performance Analysis](#performance_analysis)
  - [2.3 Forwarding Multiplexers](#forwarding-multiplexers)
  - [2.4 PCSrc_assertion logic explained](#pcsrc_assertion-labeled-as-pcsource-in-the-diagram-below-logic-explained)
  - [2.5 Hazard Unit](#22-hazard-unit)
- [3. Schematic](#3-schematic)
- [4. Testing & Verification](#4-testing--verification)
  - [4.1 Hazard Unit Testing](#41-hazard-unit-testing)
  - [4.2 Full Pipeline Testing](#42-full-pipeline-testing)

---

## 1. Overview

Pipelining is a technique used to improve processor performance by letting different parts of multiple instructions run at the same time instead of completing one instruction fully before starting the next.
In a single-cycle CPU, each instruction passes sequentially through several steps: fetch, decode, execute, memory access, and writeback and this total delay defines the clock cycle. 

Pipelining divides these steps into separate hardware stages and places pipeline registers between them, so that each stage works on a different instruction every cycle. As a result, while one instruction is being executed, another is being decoded and a third is already being fetched. The processor therefore achieves higher throughput.

In our design, we extend the original single-cycle (full 37 instructions) cpu into a 5-stage pipeline processor :fetch, decode, execute, memory access, and writeback . This will require new pipeline registers, modified writeback timing, and hazard-handling logic. We will add forwarding and stalling mechanisms to resolve data dependencies, and flushing logic to handle control hazards introduced by branches.

---

## 2. Implementation

### Pipeline Architecture

#### The Five Pipeline Stages

| Stage | Name | Description |
|-------|------|-------------|
| **F** | Fetch | Retrieve instruction from instruction memory using PC |
| **D** | Decode | Read registers and decode instruction; generate control signals |
| **E** | Execute | Perform ALU operation or calculate memory address |
| **M** | Memory | Access data memory for loads and stores |
| **W** | Writeback | Write result back to register file |

##### Signal Naming Convention

Introducing pipeline registers creates multiple instances of the same signal, each belonging to a different instruction. For example, the Program Counter (PC) value propagates through the pipeline, but the PC at the Execute stage corresponds to a **different instruction** than the PC at the Fetch stage.

To distinguish signals at different pipeline stages, we append a suffix indicating the stage:

| Suffix | Stage | Example |
|--------|-------|---------|
| `F` | Fetch | `PCF`, `InstrF` |
| `D` | Decode | `PCD`, `RD1D`, `RD2D` |
| `E` | Execute | `PCE`, `ResultSrcE`, `LoadSizeE` |
| `M` | Memory | `PCM`, `LoadUnsignedM` |
| `W` | Writeback | `ResultSrcW`, `RdW` |

##### Control Signal Propagation

The control unit for a pipelined processor is essentially **identical** to that of the single-cycle processor. However, there is one critical difference: **all control signals must also be pipelined**.

Control signals must travel alongside the data through the pipeline registers, ensuring that each stage receives the correct control signal for the instruction currently occupying that stage. For instance, `MemWrite` generated during Decode must arrive at the Memory stage exactly when the corresponding instruction reaches that stage.

```
Decode Stage          Execute Stage         Memory Stage
────────────────      ────────────────      ────────────────
MemWriteD ──────────► MemWriteE ──────────► MemWriteM ─────► Data Memory
RegWriteD ──────────► RegWriteE ──────────► RegWriteM ─────► ...
ALUCtrlD ────────► ALUCtrlE ────────► (not needed)
```

##### Register File Timing

In the pipelined design, the register file writeback occurs on the **falling edge** of the clock rather than the rising edge. This design choice enables:

- **First half of cycle**: Write data to the register file (Writeback stage)
- **Second half of cycle**: Read data from the register file (Decode stage)

This allows a subsequent instruction to read a value written by a preceding instruction within the same clock cycle, reducing certain data hazards.

---

#### Performance Analysis

The performance of a processor is determined by the time required to execute a program:

```
Execution Time = (# Instructions) × CPI × Tc
```

Where:
- **# Instructions**: Total number of instructions in the program
- **CPI**: Cycles Per Instruction (average clock cycles per instruction)
- **Tc**: Clock cycle time (seconds per cycle)

##### Component Delays

The table (from Harris and Harris book) below shows typical propagation delays for processor components:

![diagram](component_delays.png)

##### Single-Cycle Processor Performance

For a single-cycle processor, the clock period must accommodate the **entire critical path** through all stages:

```
Tc_single = t_pcq + 2·t_mem + t_RFread + t_ALU + t_mux + t_RFsetup
          = 40 + 2(200) + 100 + 120 + 30 + 60
          = 750 ps
```

**Example**: Program with 300 billion instructions

```
Execution Time = (# Instructions) × CPI × Tᶜ
               = (300 × 10⁹) × (1) × (750 × 10⁻¹² s)
               = 225 seconds
```

##### Pipelined Processor Performance

For a pipelined processor, the clock period is determined by the **slowest pipeline stage**:
We note that the formula seen in the lecture accounts for the extra hardware in our circuit (implementing all of the 37 instructions).
(We count the different occurences of each component using the schematic drawn in the section below)

```
Tc_pipelined = max of:
    -Fetch:     t_pcq + t_mem + t_setup              = 290 ps
     -Decode:    2(t_RFread + t_setup)                = 300 ps
    -Execute:   t_pcq + 4·t_mux + t_ALU + t_AND-OR + t_setup = 350 ps 
    -Memory:    t_pcq + t_mem + t_setup              = 290 ps
    -Writeback: 2(t_pcq + t_mux + t_RFwrite)         = 280 ps

Tc_pipelined = 350 ps (from the execute stage)
```

The Execute stage is the **critical path**, limiting the clock frequency.

However, pipelining introduces **hazards** (data dependencies, control dependencies) that require stalls. This increases the effective CPI above the ideal value of 1.

**Example**: Program with 300 billion instructions, we assume CPI = 1.23 (idealy 1 but here higher due to stalls)

```
Execution Time = (# Instructions) × CPI × Tc
               = (300 × 10⁹) × (1.23) × (350 × 10⁻¹² s)
               = 129 seconds
```

#### Performance Comparison

Despite the increased CPI due to hazard-related stalls, the pipelined processor achieves a **1.74× speedup** over the single-cycle design by significantly reducing the clock period.

```
Speedup = 300s / 129s ≈ 1.74×
```

This demonstrates the fundamental advantage of pipelining: **higher throughput** through instruction-level parallelism, even at the cost of slightly reduced efficiency per instruction.


### Forwarding Multiplexers

Data hazards occur when an instruction depends on the result of a previous instruction still in the pipeline. Rather than stalling, we can **forward** the required data directly from where it is available to where it is needed.

##### Key Insight

A result computed by the ALU is available at the end of the Execute stage, **before** it is written back to the register file. By adding forwarding paths, we can bypass the pipeline registers and deliver this value directly to dependent instructions.

Two multiplexers are added at the ALU inputs to select between three possible sources: (see schematic below)

```systemverilog
// Forwarding multiplexers
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



##### Hazard Unit Role

The **Hazard Unit** monitors register addresses across pipeline stages (`Rs1E`, `Rs2E`, `RdM`, `RdW`) and generates the forwarding control signals (`ForwardAE`, `ForwardBE`). It determines:
This allows most data hazards to be resolved **without stalling**, maintaining pipeline throughput. (See more on the hazard unit logic below)


### PCSrc_assertion (labeled as PCSource in the diagram below) logic explained

In the single-cycle design, branch resolution happens within the control unit. In the pipelined design, however:
1. **Control signals are generated in Decode** which is before comparison flags are available
2. **Comparison flags are computed in Execute** by the ALU

Therefore, we need a dedicated module in the Execute stage that combines the pipelined control signals (`Branch_e`, `Jump_e`, `funct3`) with the ALU flags (`EQ`, `LT`, `LTU`) to produce the final `PCSrcE` decision.

#### Output

This module generates the `PCSrcE` control signal, which selects the source for the next Program Counter:

| PCSrcE | Next PC Source | Condition |
|--------|----------------|-----------|
| `2'b00` | `PC + 4` | No branch/jump (sequential execution) |
| `2'b01` | `PCTargetE` | Branch taken or `JAL` |
| `2'b10` | `ALUResultE` | `JALR` (register based jump) |

Which matches the logic in the pc_block: 

```systemverilog
case (pc_src)
  2'b00: internal_pc <= inc_pc;    // PC + 4
  2'b01: internal_pc <= branch_pc; // PC + Imm
  2'b10: internal_pc <= ALU;       // JALR
  default: internal_pc <= inc_pc;  
```

#### Branch Resolution Logic

When `Branch_e` is asserted, the module decodes `funct3` to determine which comparison flag to evaluate:

| funct3 | Instruction | Branch Taken When |
|--------|-------------|-------------------|
| `3'b000` | `BEQ` | `EQ == 1` (equal) |
| `3'b001` | `BNE` | `EQ == 0` (not equal) |
| `3'b100` | `BLT` | `LT == 1` (less than, signed) |
| `3'b101` | `BGE` | `LT == 0` (greater or equal, signed) |
| `3'b110` | `BLTU` | `LTU == 1` (less than, unsigned) |
| `3'b111` | `BGEU` | `LTU == 0` (greater or equal, unsigned) |

Note the symmetry: each pair of branches (`BLT`/`BGE`, `BLTU`/`BGEU`, `BEQ`/`BNE`) uses the **same flag** but with **opposite polarity**.

#### Jump Resolution Logic

When `Jump_e` is asserted:

| ALUSrcE | Instruction | PCSrcE | Target Calculation (computed in the pc block) |
|---------|-------------|--------|-------------------|
| `0` | `JAL` | `2'b01` | `PC + immediate` (PC-relative) |
| `1` | `JALR` | `2'b10` | `rs1 + immediate` (register-based) |


---

### 2.2 Hazard Unit
#### 1.	Why hazards occur in a pipeline? 
(A good analogy may be the conveyor belt along an assembly line in a car factory. At any one time, there are multiple cars along the belt, with each car being built stage by stage by workers who only specialize in one action)
In a pipelined CPU, multiple instructions are executed in parallel. Hazards arise due to this inherently parallel structure. 
Data Hazards occur when one or more instructions depend on results that have not yet been written back into the register file. Specifically, this arises when the destination register of the previous instruction is one of the source registers of the latter instruction. This phenomenon is called a Read-After-Write hazard.
![diagram](images/image1.png)

In the figure above, instructions that follow the `add s8, s4, s5` instruction use the s8 register as a source register in their arithmetic and logical operations. For instance, `sub s2, s8, s3` requires the contents of the register s8 in the 3rd clock cycle, the next instruction in the 4th, and the one after on the 5th. However, the initial add instruction is only able to write back to the register file by the end of the 5th clock cycle. Therefore, the instructions that follow read the previous value of s8 from the register, which is invalid in the logical sequence of execution and will most likely culminate in an erroneous result. 
A special case arises when the first instruction is a “Load” instruction.

![diagram](images/image2.png)
 
When the instruction immediately after an “lw” instruction has a source register that is meant to be written into by the `lw` instruction, the 2 stage difference between the decode and memory stages means that the result of the “lw” instruction only becomes available once the next instruction has already reached and completed its execution stage. This is shown by the topmost arrow pointing from the bus carrying the result of the data memory (the “lw” result) to the top input of the ALU. Since the data dependency involves a result that only becomes available in the same clock cycle as the execution of the dependent instruction, forwarding on its own is no longer sufficient. 

Control Hazards are caused by branch instructions where the condition required for the branch is true, meaning the branch is taken. Once it is determined that the branch predicate is true, the program counter must branch to a different location, and the sequential order in which instructions are fetched from the instruction memory is broken. Depending on the offset of a branch instruction, an asserted branch invalidates the instructions fetched after the branch instruction and before the deduction of the branch condition’s validity. 

#### 2.	Motivation for/responsibilities of the hazard unit
Our hazard unit encapsulates all of the regulatory logic required to tackle the issues introduced by pipelining, including both data hazards and control hazards. Hence, the hazard unit is a single comprehensive module that triggers and employs stalling, flushing, and forwarding mechanisms (what these mechanisms do will be explained later together with the solutions). We chose this unitary and holistic approach to resolving both kinds of hazards because the input signals required to generate the relevant control signals for stalling, flushing and forwarding are the same or similar.

In summary, the primary goals of the Hazard Unit are:

•	To resolve data hazards through forwarding whenever possible, minimizing performance loss.

•	To detect and stall only when forwarding cannot supply the required operand in time (“Load” data dependency).

•	To flush instructions that enter the pipeline speculatively once a branch outcome becomes known.




#### Data hazard resolution: forwarding logic
For most arithmetic and logical instructions, the result becomes available before Write-Back, either at the end of the `EX` or `MEM` stage, allowing us to resolve these hazards without inserting stalls by forwarding the result directly to the ALU inputs.
The Hazard Unit implements this forwarding by checking whether the source registers used by the instruction currently in the Execute (EX) stage match the destination registers of instructions that are still in the Memory (MEM) or Write-Back (WB) stages.
Forwarding Decision Conditions (PUT the code for forwarding only somewhere around here or right next)
```systemverilog
always_comb begin
    //Default:no forwarding
    selectline1 = 2'b00;
    selectline2 = 2'b00;

    //Operand1 forwarding
    if (regWriteM && rdM != 0 && rdM == rs1E) begin
        selectline1 = 2'b10;  //from MEM stage
    end 
    else if (WriteBack_Regfile && rdWB !=0 && rdWB == rs1E) begin
        selectline1 = 2'b01;  //from WB stage
    end

    // Operand 2 forwarding
    if (regWriteM && rdM !=0 && rdM == rs2E) begin
        selectline2 = 2'b10;
    end 
    else if (WriteBack_Regfile && rdWB !=0 && rdWB == rs2E) begin
        selectline2 = 2'b01;
    end

end

```
The forwarding logic compares decoded operands rs1E and rs2E with the destination registers rdM and rdWB:

•	If the instruction in the MEM stage writes a register (regWriteM = 1) and its destination rdM matches the operand in EX, then the operand should be forwarded from MEM.

•	Else if the instruction in the WB stage writes a register (WriteBack_Regfile = 1) and its destination rdWB matches, then forward from WB.

•	Register x0 is never forwarded, so matches must ignore rd = 0.


##### Select Line Encoding
To control operand multiplexers feeding the ALU, the Hazard Unit sets two 2-bit signals:
| Value | Operand Source          |
| ----- | ----------------------- |
| 00    | Register file output    |
| 01    | Forward from Write-Back |
| 10    | Forward from Memory     |



So the circuit schematic for exclusively the hazard unit’s forwarding mechanism is identical to that detailed in the lecture slides as shown below:

![diagram](images/image3.png)
 
What this diagram does not cover is how the hazard unit tackles load word data dependencies and control hazards, discussed later.
Why forwarding ignores loads here
Even though this logic covers most RAW hazards, it does not prevent a load word hazard, because a load instruction does not produce valid data until the end of the MEM stage. In such cases, forwarding would still not provide the correct value in time, which is why the Hazard Unit must insert a stall (described in Section 4).
Forwarding entirely removes stalls that would otherwise be caused by data dependencies for:

•	ALU-to-ALU dependency chains (e.g., add, sub, and, or, etc.)

•	Immediate arithmetic dependencies (e.g., addi, ori)

•	Register-producing control instructions if value is known early (e.g., jalr)

#### 4. Load word data dependency
Forwarding cannot resolve a dependency when the preceding instruction is a load. In a load instruction, the data is only available after the Memory stage, meaning forwarding cannot provide a valid operand in the immediate next cycle.

![diagram](images/image4.png)
 
(Modify this diagram to show that the execute stage is actually flushed, not stalled)
In this case, the Hazard Unit must stall the pipeline for exactly one cycle. It freezes the Program Counter and Fetch-to-Decode pipeline register and flushes the Decode-to-Execute pipeline register. The reason why Decode-to-Execute pipeline register is flushed is that if it were only stalled, the “lw” instruction would propagate through to the memory stage but also still remain in the Decode-to-Execute pipeline register, essentially duplicating the lw instruction. Thus, flushing this stage of the pipeline both achieves the stall required for synchronization (since the next register is not able to propagate into the execute stage) and prevents the duplication that would cause 2 back to back “lw” instructions.

```systemverilog
logic wStall;
//logic lw_write_back;

assign wStall = (resultSrCE == 2'b01) &&
                 ( (rdE != 0) &&
                   ( (rdE == rs1D) || (rdE == rs2D) ) );

...

always_comb begin

    // Default: no stall, and no flush
    PCWrite     = 1;
    F_Write = 1;
    flush_d_exec = 0;
    flush_f_d = 0;

    ... //Control hazard detection and flushing

    if(wStall == 1) begin
        PCWrite     = 0;
        F_Write = 0;
        flush_d_exec = 1;
    end
end

```

The stall condition used in the design asserts when: (Same as data dependency section, put the code somewhere over here)
•	The instruction in Execute is a load (resultSrCE == 2'b01), and
•	Its destination register rdE matches either source register in Decode (rs1D or rs2D), and
•	rdE != 0.
This is implemented in:
(code)
When a stall is necessary:
•	PCWrite = 0 prevents PC update,
•	F_Write = 0 prevents writing to IF/ID,
•	flush_d_exec = 1 inserts a bubble into Execute.
Thus, one cycle later, forwarding can resume as normal.


#### 5. Control hazard detection and Flush logic

![diagram](images/image5.png)
 
In the image, the first instruction in the sequence is “beq s1, s2, L1”. In the first clock cycle, the instruction is fetched from instruction memory and fed to the pipeline register connecting the fetch stage to the decode stage. In the second clock cycle, the branch instruction is decoded and the relevant registers read from the register file. Meanwhile, the next instruction – “sub s8, t1, s3” – is fetched from instruction memory. Only by the third clock cycle, does the ALU determine that s1 and s2 are equal. However, two new instructions have been fetched already from instruction memory under the speculative assumption that the branch will not be taken. The solution is to “flush” the fetch and decode stages. To do this, the hazard unit outputs a control signal to the Fetch-to-Decode and Decode-to-Execute pipeline registers. Our pipeline registers have internal logic that synchronously sets the contents of the pipeline registers to 0 once the one-bit control signal from the hazard unit triggers flushing. Since the PC is updated to the branch target, the pipeline then continues with correct instructions.

```systemverilog
if(PCSrcE == 2'b10 || PCSrcE == 2'b01) begin
        flush_f_d = 1;
        flush_d_exec = 1;
    end
```
---

## 3. Schematic

![diagram](pipelining.png)

---

## 4. Testing & Verification

### 4.1 Hazard Unit Testing
#### Test 1: Forward From MEM to Operand1 (`T1_MEM_Fwd_Op1`)

##### Purpose
Ensures the hazard unit forwards data from the MEM stage when `rdM` matches `rs1E`.

##### Signal Setup
```text
rs1E      = 5
rdM       = 5
regWriteM = 1
```

##### Input Signals

| Signal             | Value  |
|--------------------|--------|
| `rs1D`             | 0      |
| `rs2D`             | 0      |
| `rs1E`             | 5      |
| `rs2E`             | 0      |
| `rdM`              | 5      |
| `rdE`              | 0      |
| `rdWB`             | 0      |
| `regWriteM`        | 1      |
| `resultSrCE`       | 0      |
| `WriteBack_Regfile`| 0      |
| `PCSrcE`           | 0b00   |

##### Expected Output
```text
selectline1  = 2'b10
selectline2  = 2'b00
PCWrite      = 1
F_Write      = 1
flush_d_exec = 0
flush_f_d    = 0
```

##### What It Tests
- RAW hazard on operand 1 resolved via forwarding from MEM stage
- No stall or flush when there is no load-use or branch/jump
---
#### Test 2: Forward From WB to Operand2 (`T2_WB_Fwd_Op2`)

##### Purpose
Ensures the hazard unit forwards data from the WB stage when `rdWB` matches `rs2E` and MEM does not write.

##### Signal Setup
```text
rs2E              = 9
rdWB              = 9
WriteBack_Regfile = 1
regWriteM         = 0
```

##### Input Signals

| Signal             | Value  |
|--------------------|--------|
| `rs1D`             | 0      |
| `rs2D`             | 0      |
| `rs1E`             | 0      |
| `rs2E`             | 9      |
| `rdM`              | 0      |
| `rdE`              | 0      |
| `rdWB`             | 9      |
| `regWriteM`        | 0      |
| `resultSrCE`       | 0      |
| `WriteBack_Regfile`| 1      |
| `PCSrcE`           | 0b00   |

##### Expected Output
```text
selectline1  = 2'b00
selectline2  = 2'b01
PCWrite      = 1
F_Write      = 1
flush_d_exec = 0
flush_f_d    = 0
```

##### What It Tests
- RAW hazard on operand 2 resolved via forwarding from WB stage
- WB forwarding only used when MEM does not provide a matching destination
---
#### Test 3: Load-Use Stall via `rs1D` (`T3_LW_Stall_rs1D`)

##### Purpose
Ensures a load-use dependency between the instruction in EX and the instruction in Decode triggers a stall and inserts a bubble into EX.

##### Signal Setup
```text
resultSrCE = 2'b01   (load in EX)
rdE        = rs1D    (true dependency)
```

##### Input Signals

| Signal             | Value  |
|--------------------|--------|
| `rs1D`             | 3      |
| `rs2D`             | 0      |
| `rs1E`             | 0      |
| `rs2E`             | 0      |
| `rdM`              | 0      |
| `rdE`              | 3      |
| `rdWB`             | 0      |
| `regWriteM`        | 0      |
| `resultSrCE`       | 2'b01  |
| `WriteBack_Regfile`| 0      |
| `PCSrcE`           | 0b00   |

##### Expected Output
```text
PCWrite      = 0
F_Write      = 0
flush_d_exec = 1
flush_f_d    = 0
selectline1  = 2'b00
selectline2  = 2'b00
```

##### What It Tests
- Load-use hazard detection (`wStall = 1`)
- Program counter and fetch stage are stalled
- Decode→Execute pipeline register is flushed (bubble inserted)
---
#### Test 4: Branch Flush Without Stall (`T4_Branch_Flush`)

##### Purpose
Ensures that when a branch/jump is taken in EX (`PCSrcE != 2'b00`), the hazard unit flushes F/D and D/EX but does not stall the PC or fetch.

##### Signal Setup
```text
PCSrcE = 2'b01   (taken branch)
no load-use hazards
```

##### Input Signals

| Signal             | Value  |
|--------------------|--------|
| `rs1D`             | 0      |
| `rs2D`             | 0      |
| `rs1E`             | 0      |
| `rs2E`             | 0      |
| `rdM`              | 0      |
| `rdE`              | 0      |
| `rdWB`             | 0      |
| `regWriteM`        | 0      |
| `resultSrCE`       | 0      |
| `WriteBack_Regfile`| 0      |
| `PCSrcE`           | 2'b01  |

##### Expected Output
```text
flush_f_d    = 1
flush_d_exec = 1
PCWrite      = 1
F_Write      = 1
selectline1  = 2'b00
selectline2  = 2'b00
```

##### What It Tests
- Control hazard handling for taken branches/jumps
- Both F/D and D/EX pipeline registers are flushed
- No unnecessary stall of PC or fetch stage

---
```bash
[==========] Running 4 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 4 tests from HazardUnitTestbench
[ RUN      ] HazardUnitTestbench.ForwardOperand1FromMem
[       OK ] HazardUnitTestbench.ForwardOperand1FromMem (1 ms)
[ RUN      ] HazardUnitTestbench.LoadUseStall
[       OK ] HazardUnitTestbench.LoadUseStall (1 ms)
[ RUN      ] HazardUnitTestbench.ForwardOperand2FromWb
[       OK ] HazardUnitTestbench.ForwardOperand2FromWb (0 ms)
[ RUN      ] HazardUnitTestbench.BranchFlushWithoutStall
[       OK ] HazardUnitTestbench.BranchFlushWithoutStall (0 ms)
[----------] 4 tests from HazardUnitTestbench (4 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (4 ms total)
[  PASSED  ] 4 tests.
```
---

### 4.2 Full Pipeline Testing

This section verifies the pipelined design through four test scenarios, each targeting a specific aspect of pipeline behavior and hazard handling.

#### 1) Pipelined Overlapping (No Hazards)
This test demonstrates correct instruction overlapping in the pipeline when no data or control hazards are present, confirming that multiple instructions execute simultaneously across different pipeline stages.

Here is the assembly code run by the processor and the results are shown in the waveform below:


**Waveform:**


---

#### 2) Data Hazards: Read After Write (RAW)
This test verifies the forwarding unit by demonstrating how RAW hazards are resolved through the forwarding muxes, showing the change in the forward select lines when a dependent instruction requires data from a previous instruction still in the pipeline.

**Waveform:**


**Forwarding Mux Select Lines:**


---

#### 3) Load-Use Hazards
This test demonstrates the 1-cycle stall required when a load instruction is immediately followed by a dependent instruction. The stall is achieved by:
- Disabling (freezing) the FD pipeline register for 1 cycle
- Preventing the program counter from incrementing for 1 cycle
- Flushing the DE pipeline register

**Waveform:**


**Stall Signal Behavior:**


---

#### 4) Control Hazards: Branch Misprediction
Branches are predicted as not taken by default (see [Branch Prediction Enhancement]([https://github.com/TahaMunir2/Team5/tree/branchprediction]) for improved prediction). When a branch reaches the execute stage and is determined to be taken, a flush occurs to discard the incorrectly fetched instructions.

**Waveform:**

---

