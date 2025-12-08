# Out-of-Order Superscalar Processor

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
  - [2.1 Register Alias Table (RAT)](#21-register-alias-table-rat)
  - [2.2 Re-Order Buffer (ROB)](#22-re-order-buffer-rob)
  - [2.3 Register Update Unit (RUU)](#23-register-update-unit-ruu)
  - [2.4 Pipelined Design](#24-pipelined-design)
  - [2.5 Overall Integration](#25-overall-integration)
- [3. Schematic](#3-schematic)
- [4. Testing & Verification](#4-testing--verification)
  - [4.1 Unit Testing](#41-unit-testing)
    - [4.1.1 RAT Testing](#411-rat-testing)
    - [4.1.2 ROB Testing](#412-rob-testing)
    - [4.1.3 RUU Testing](#413-ruu-testing)
  - [4.2 Assembly Test Programs](#42-assembly-test-programs)
  - [4.3 Results](#43-results)
- [5. References](#5-references)

---

## 1. Overview

### Superscalar: Breaking the CPI Barrier

A conventional pipelined processor achieves a **CPI (Cycles Per Instruction) of 1 or above** (also limited by hazards and dependencies). A **superscalar processor** breaks this barrier by duplicating execution hardware (in our case the only functional unit to duplicate is the ALU, but for processors containing multiple functional units of different types we duplicate all of them), enabling **multiple instructions to complete per cycle**.

Our implementation is a **2-way superscalar** processor featuring:
- **2 instructions fetched** per cycle
- **2 ALUs** operating in parallel
- **Dual-ported register file** to support simultaneous reads and writes

To keep both ALUs busy, two instructions must be issued every clock cycle. This requires duplicating internal hardware: register file ports, data paths, and control logic.

### The Problem: Data Dependencies

Superscalar execution introduces a critical challenge: **data hazards are amplified**.

When two instructions are fetched together, they may depend on each other or on recently issued instructions. In an **in-order superscalar** processor, a dependent instruction **blocks all subsequent instructions** from executing even if they are independent.

Let's consider the following assembly code to illustrate our purpose:

```asm
ADD  x1, x2, x3    # Produces x1
SUB  x4, x1, x5    # Depends on x1, must wait
AND  x6, x7, x8    # Independent, could execute, but is blocked
```

In an in-order design, `AND` cannot be issued until `SUB` is issued, even though `AND` has no dependency.

### The Solution: Out-of-Order Execution

**Out-of-order execution** solves this by allowing independent instructions to **bypass** stalled ones.

The processor fetches instructions into a buffer, analyzes their dependencies, and issues them **not in program order**, but in an order that **maximizes ALU utilization** while respecting true data dependencies.

This means:
- Instructions **execute** out of order (when operands are ready), decoding and execution are interfaced by the Register Update Unit
- Instructions **commit** in order (preserving program correctness), execution and commiting into the register file are interfaced by the Re-Order Buffer

### The Tomasulo Algorithm

Our implementation is based on **Tomasulo's algorithm**, originally developed for the IBM System/360 Model 91. It introduces:

| Component | Purpose |
|-----------|---------|
| **Register Alias Table (RAT)** | Renames registers to eliminate data hazards (false dependencies : WAR and WAW) |
| **Re-Order Buffer (ROB)** | Tracks instructions for in-order commit |
| **Register Update Unit (RUU)** | Holds instructions waiting for operands to be ready and can issue any instruction ready to execute disregarding the original program order (reservation stations) |
| **Common Data Bus (CDB)** | Broadcasts results to wake up dependent instructions |

### Instruction Flow

1. **Fetch**: Retrieve 2 instructions per cycle from instruction memory
2. **Decode/Rename**: Decode instructions, rename destination registers via RAT, allocate ROB entries
3. **Dispatch/Issue**: Place instructions into RUU with source operand tags/values; when all operands are ready, issue to ALUs (out of order)
4. **Execute**: ALUs compute results; results are broadcast on the CDB to wake up dependent instructions and written to the corresponding ROB entry
5. **Commit**: Retire instructions in program order from ROB head; update architectural register file

### Scope

This implementation demonstrates the core out-of-order machinery using **arithmetic instructions only** (R-type and I-type ALU operations, including `LUI`). The design handles all three types of data hazards: 
Read After Write (RAW) via common data bus transmission ( replacing the forwarding logic implemented in our previous designs) , Write After Read (WAR), Write After Write (WAW) hazards via register renaming.

Load, store, branch, and jump instructions introduce additional complexity such as memory disambiguation and speculative execution and will be explored in further branches.

---

## 2. Implementation

### 2.1 Register Alias Table (RAT)

#### Purpose

The Register Alias Table eliminates **false dependencies** (WAR and WAW hazards) through **register renaming**. Instead of tracking architectural register names (x0–x31), the RAT maps each register to a **producer tag** which is a unique identifier for the instruction that will produce the register's value.

This allows multiple instructions targeting the same architectural register to coexist in the pipeline without conflicts.

#### How It Works

When an instruction writes to a register, it is assigned a unique **producer ID** (tag). Any subsequent (subsequent in terms of program order) instruction that reads from that register will receive this tag instead of the actual value, allowing it to:
- Wait for the producing instruction to complete
- Receive the value via the Common Data Bus (CDB) when it becomes available

#### Parameters

```systemverilog
parameter NREGS     = 32,   // Number of architectural registers (x0–x31)
parameter PROD_BITS = 6     // Tag width (supports up to 64 in-flight instructions)
```

The 6-bit tag width was chosen to match the **ROB depth of 64 entries**. Since each in-flight instruction occupies one ROB entry, 6 bits (`2^6 = 64`) provides enough unique tags to identify all possible instructions in the pipeline. This keeps the tag field compact (in order to reduce delays incurred by the accessing a table) while supporting sufficient instruction-level parallelism for our 2-way superscalar design.

#### Storage

```systemverilog
logic [PROD_BITS-1:0] rat_table [NREGS];      // Maps each register to its latest producer tag
logic [PROD_BITS-1:0] producer_counter;       // Generates unique tags for new instructions
```

- **`rat_table`**: Array of 32 entries, one per architectural register. Each entry holds the tag of the instruction that will produce that register's value.
- **`producer_counter`**: A monotonically increasing counter that assigns unique tags to new instructions.

#### Interface

##### Destination Register Renaming (2 instructions per cycle)

| Signal | Direction | Description |
|--------|-----------|-------------|
| `inst1_rd` | Input | Destination register of instruction 1 |
| `inst1_prod_id` | Output | Assigned tag for instruction 1 |
| `inst2_rd` | Input | Destination register of instruction 2 |
| `inst2_prod_id` | Output | Assigned tag for instruction 2 |

##### Source Register Lookup (4 source registers for 2 instructions)

| Signal | Direction | Description |
|--------|-----------|-------------|
| `rs1`, `rs2` | Input | Source registers of instruction 1 |
| `rs1_prod_id`, `rs2_prod_id` | Output | Producer tags for instruction 1's sources |
| `rs3`, `rs4` | Input | Source registers of instruction 2 |
| `rs3_prod_id`, `rs4_prod_id` | Output | Producer tags for instruction 2's sources |

#### Tag Assignment

Each cycle, two new instructions receive consecutive tags:

```systemverilog
assign inst1_prod_id = producer_counter - 6'b000001;  // Tag N-1
assign inst2_prod_id = producer_counter;               // Tag N
```

Instruction 1 (older) gets `producer_counter - 1`, instruction 2 (younger) gets `producer_counter`. This ensures program order is encoded in the tag values.

#### Source Lookup (Combinational)

```systemverilog
assign rs1_prod_id = rat_table[rs1];
assign rs2_prod_id = rat_table[rs2];
assign rs3_prod_id = rat_table[rs3];
assign rs4_prod_id = rat_table[rs4];
```

For each source register, the RAT immediately returns the tag of the instruction that will produce its value.

#### RAT Update (Sequential)

```systemverilog
always_ff @(posedge clk) begin
    if (rst) begin
        producer_counter <= 6'b000000;
        for (int i = 0; i < NREGS; i++)
            rat_table[i] <= '0;
    end else begin
        // Update RAT for instruction 1
        if (inst1_rd != 5'd0)
            rat_table[inst1_rd] <= producer_counter - 6'b000001;
        
        // Update RAT for instruction 2
        if (inst2_rd != 5'd0)
            rat_table[inst2_rd] <= producer_counter;
        
        // Increment counter by 2 (for 2 instructions)
        producer_counter <= producer_counter + 2;
    end
end
```

Key points:
- **Register x0 is never renamed**: Writes to x0 are ignored (`inst_rd != 5'd0`)
- **Counter increments by 2**: Since we process 2 instructions per cycle
- **RAT entries are overwritten**: Only the latest producer matters


### 2.2 Re-Order Buffer (ROB)

<!-- TODO:
- Purpose: maintain program order for in-order commit
- Circular buffer structure
- Entry contents (valid, ready, value, destination register)
- Allocation, completion, and commit operations
-->

---

### 2.3 Register Update Unit (RUU)

<!-- TODO:
- Also known as reservation stations
- Purpose: hold instructions waiting for operands
- Operand wake-up via Common Data Bus (CDB)
- Issue logic: select ready instructions for execution
-->

---

### 2.4 Pipelined Design

<!-- TODO:
- Pipeline stage division based on component delays
- Optimization for efficiency
- Timing considerations between stages
-->

---

### 2.5 Overall Integration

<!-- TODO:
- How RAT, ROB, RUU, and ALUs connect
- Instruction flow: Fetch → Decode/Rename → Issue → Execute → Writeback → Commit
- Common Data Bus (CDB) broadcasting
- Out-of-order execution with in-order commit
-->

---

## 3. Schematic

<!-- TODO: Circuit diagram showing all components and connections -->

---

## 4. Testing & Verification

### 4.1 Unit Testing

#### 4.1.1 RAT Testing

<!-- TODO: RAT unit test cases and results -->

---

#### 4.1.2 ROB Testing

<!-- TODO: ROB unit test cases and results -->

---

#### 4.1.3 RUU Testing

<!-- TODO: RUU unit test cases and results -->

---

### 4.2 Assembly Test Programs

<!-- TODO:
- Test programs designed to verify out-of-order behavior
- RAW, WAR, WAW hazard scenarios
- Dependency chains and parallel execution
-->

---

### 4.3 Results

<!-- TODO:
- Test outcomes
- Waveforms demonstrating out-of-order execution
- Performance observations
-->

---

## 5. References

<!-- TODO:
- Tomasulo's algorithm papers/resources
- Harris & Harris textbook
- Other references used
-->

---
