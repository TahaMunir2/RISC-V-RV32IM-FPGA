# Pipelined RISC-V Processor

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
  - [2.1 Pipeline Architecture](#21-pipeline-architecture)
  - [2.2 Performance Analysis](#performance_analysis)
  - [2.3 Hazard Unit](#22-hazard-unit)
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


#### forwarding multiplexers

#### PCSrc_assertion logic explained

---

### 2.2 Hazard Unit

---

## 3. Schematic

![diagram](pipelining.png)

---

## 4. Testing & Verification

### 4.1 Hazard Unit Testing

---

### 4.2 Full Pipeline Testing

---

