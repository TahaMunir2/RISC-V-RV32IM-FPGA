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

#### Purpose

The Re-Order Buffer is a central module in the implementation. 

It interacts in three different stages: 
1. **Decode/Rename** : it has to keep track of all the instructions fetched because it retains the program order
2. **Execution** : after execution results are saved in the buffer
3. **Commit** : It commits these results in program order to the register file (taking values asssigned to producer register and writing to the architectural registers)

It serves three critical functions:

1. **Tracks all in-flight instructions** in program order
2. **Stores results** of completed instructions until they can be committed
3. **Ensures in-order commit** — instructions retire at the head in strict program order, preserving architectural correctness

#### Structure

The ROB is implemented as a circular buffer with 64 entries:

```systemverilog
parameter DEPTH    = 64,
parameter TAG_BITS = $clog2(DEPTH)  // 6 bits
```

Each entry contains:

| Field | Width | Description |
|-------|-------|-------------|
| `dest_reg` | 5 bits | Destination architectural register (x0–x31) |
| `value` | 32 bits | Computed result (filled on writeback) |
| `ready` | 1 bit | Set when execution completes; entry can commit |

```systemverilog
logic [4:0]   dest_reg [DEPTH];   // Destination register
logic [31:0]  value    [DEPTH];   // Result value
logic         ready    [DEPTH];   // Ready to commit flag
```

#### Interfaces

##### Query Interface (4 ports)

When the RAT indicates a register has an in-flight producer, we query the ROB to check if the result is already available:

```systemverilog
input  logic [TAG_BITS-1:0] q1_tag,    // Query tag
output logic                q1_ready,  // Is result ready?
output logic [31:0]         q1_value   // Result value (if ready)
```

Four query ports support looking up source operands for 2 instructions (2 sources each):

```systemverilog
assign q1_ready = ready[q1_tag];
assign q1_value = value[q1_tag];
// ... same for q2, q3, q4
```

##### Allocation Interface (2 ports)

Two instructions can be allocated per cycle:

```systemverilog
// Instruction 1
input  logic                alloc1_en,    // Allocate enable
input  logic [4:0]          alloc1_rd,    // Destination register
input  logic [TAG_BITS-1:0] alloc1_tag,   // Assigned ROB index

// Instruction 2
input  logic                alloc2_en,
input  logic [4:0]          alloc2_rd,
input  logic [TAG_BITS-1:0] alloc2_tag,
```

On allocation:
- `dest_reg[tag]` is set to the destination register
- `ready[tag]` is cleared (instruction not yet complete)
- `tail` advances by 1 or 2 depending on how many instructions are allocated

##### Writeback Interface (2 ports)

Two results can be written back per cycle (from 2 ALUs via CDB):

```systemverilog
input  logic                wb1_en,
input  logic [TAG_BITS-1:0] wb1_tag,     // Which ROB entry completed
input  logic [31:0]         wb1_value,   // Computed result

input  logic                wb2_en,
input  logic [TAG_BITS-1:0] wb2_tag,
input  logic [31:0]         wb2_value,
```

On writeback:
- `value[tag]` is updated with the result
- `ready[tag]` is set to 1

##### Commit Interface (2 ports)

Up to two instructions can commit per cycle (in order from head):

```systemverilog
output logic                  commit1_valid,  // Head entry ready?
output logic [4:0]            commit1_rd,     // Destination register
output logic [31:0]           commit1_value,  // Value to write
output logic [TAG_BITS-1:0]   commit1_tag,    // Tag (to free RUU entry)
input  logic                  commit1_en,     // Commit acknowledged

// Same for commit2 (head + 1)
```

#### Pointers

In this module, we implement signals serving as pointers, so that we can track the oldest instruction (ready to commit) and the next free slot (ready for allocation) without searching through the entire buffer.

```systemverilog
logic [TAG_BITS-1:0] head;  // Oldest in-flight instruction (next to commit)
logic [TAG_BITS-1:0] tail;  // Next free slot (next to allocate)
logic                full_flag;
```

- **`head`**: Points to the oldest instruction — the next candidate for commit
- **`tail`**: Points to the next free slot for allocation

#### Commit Logic

Commits happen **strictly in order** from the head:

```systemverilog
assign commit1_valid = !rob_empty && ready[head];
assign commit1_rd    = dest_reg[head];
assign commit1_value = value[head];
assign commit1_tag   = head;
```

For the second commit slot, the condition is a bit trickier and requires a different manipulation of the pointers siganls:
1. The first commit is valid (we cannot skip the head)

2. We check that there is a second entry in the buffer:
The `tail` pointer marks the first *empty* slot, valid entries exist between `head` and `tail` (with `tail` not included in the interval). If `head_next == tail`, we've reached the empty region for this second commit, meaning only one instruction can potentialy be commited (so there are no second valid instrcution in the buffer that can potentially be commited). 
On the other hand, if `head_next != tail`, there is at least one more valid entry at `head+1` that can potentially commit.

3. That entry is also ready (execution has completed)

```systemverilog
logic [TAG_BITS-1:0] head_next;
assign head_next = head + 1'b1;

assign commit2_valid =
    commit1_valid &&                          // First must be valid
    (head_next != tail) &&     // Second entry exists
    ready[head_next];                         // Second is ready
```

#### Sequential Operations :

```systemverilog
always_ff @(posedge clk) begin
    if (rst) begin
        head      <= 6'b000001;
        tail      <= 6'b000001;
        full_flag <= 1'b0;
        // Clear all entries...
    end else begin
        // Allocation: advance tail by 1 or 2
        // Writeback: set ready[tag] = 1, value[tag] = result
        // Commit: advance head by 1 or 2, clear ready bits
    end
end
```

The ROB performs three sequential operations: **Allocation**, **Writeback**, and **Commit**. Each is illustrated below.

##### Allocation: Adding New Instructions

When instructions are dispatched, they are allocated at the `tail` pointer. The `tail` advances by 1 or 2 depending on how many instructions are allocated.

![diagram](rob-allocation.png)

In this diagram, we clearly observe how the tail pointer advances in the buffer at allocation.

##### Writeback: Marking Instructions Complete

When an ALU finishes execution, it broadcasts the result on the CDB. The ROB captures the value and sets `ready=1`.

![diagram](rob-writeback.png)

In this diagram, we clearly observe how the common data bus transmits the results of each execution which are allocated to specific tags in the Re-Order Buffer.
We also note that since execution does not occur in order, the transmission of data in the Re-Order Buffer will not necessarly follow the program order.

##### Commit: Retiring Instructions In Order

Instructions commit from the `head` in program order. 

Only entries with `ready=1` and `commit = 0` (it has not yet been commited) can commit.

The Re-Order Buffer commits up to 2 instructions per cycle, the number of commits per cycle depends on the number of ready instructions in the buffer:
- No instructions ready : 0 instrutcions commmited
- 1 instruction ready (even though the other instructions might be valid, here we only consider the ones that are ready) : 1 instruction commited
- 2 or more instructions ready : exactly 2 instructions commited




### 2.3 Register Update Unit (RUU)

#### Purpose

The Register Update Unit (also known as **Reservation Stations** in Tomasulo's algorithm) holds instructions that are waiting for their operands. It enables **out-of-order execution** by:

1. **Buffering instructions** until their source operands become available
2. **Waking up instructions** when results are broadcast on the CDB
3. **Issuing ready instructions** to the ALUs for execution

#### Structure

The RUU is implemented as an array of 64 entries:

```systemverilog
parameter DEPTH          = 64,
parameter TAG_BITS       = $clog2(DEPTH),  // 6 bits
parameter CONTROL_WIDTH  = 4               // ALU control bits
```

Each entry is a packed struct containing:

```systemverilog
typedef struct packed {
    logic                     valid;      // Slot in use
    logic                     issued;     // Already sent to ALU?
    logic [TAG_BITS-1:0]      dest_tag;   // ROB tag for this instruction
    logic                     src1_valid; // Is source 1 ready?
    logic [TAG_BITS-1:0]      src1_tag;   // Producer tag for source 1
    logic [31:0]              src1_value; // Value of source 1
    logic                     src2_valid; // Is source 2 ready?
    logic [TAG_BITS-1:0]      src2_tag;   // Producer tag for source 2
    logic [31:0]              src2_value; // Value of source 2
    logic [CONTROL_WIDTH-1:0] ctrl;       // ALU control signals
} ruu_entry_t;
```

| Field | Description |
|-------|-------------|
| `valid` | Entry contains an instruction |
| `issued` | Instruction has been sent to ALU (prevents re-issue) |
| `dest_tag` | The ROB tag identifying this instruction |
| `src1_valid` | Source operand 1 is available |
| `src1_tag` | If not valid, the ROB tag of the producing instruction |
| `src1_value` | The actual value (when valid) |
| `src2_valid`, `src2_tag`, `src2_value` | Same for source operand 2 |
| `ctrl` | ALU operation control signals |

#### Interfaces

##### Dispatch Interface (2 instructions per cycle)

```systemverilog
// Instruction 1
input  logic                 dispatch1_en,
input  logic [TAG_BITS-1:0]  dispatch1_dest_tag,
input  logic                 dispatch1_src1_valid,
input  logic [TAG_BITS-1:0]  dispatch1_src1_tag,
input  logic [31:0]          dispatch1_src1_value,
input  logic                 dispatch1_src2_valid,
input  logic [TAG_BITS-1:0]  dispatch1_src2_tag,
input  logic [31:0]          dispatch1_src2_value,
input  logic [CONTROL_WIDTH-1:0] dispatch1_ctrl,

// Instruction 2 (same signals)
```

##### Writeback Interface (CDB broadcast)

```systemverilog
input  logic                 wb1_en,
input  logic [TAG_BITS-1:0]  wb1_tag,
input  logic [31:0]          wb1_value,

input  logic                 wb2_en,
input  logic [TAG_BITS-1:0]  wb2_tag,
input  logic [31:0]          wb2_value,
```

##### Free Interface (after commit)

```systemverilog
input  logic                 free1_en,
input  logic [TAG_BITS-1:0]  free1_tag,
input  logic                 free2_en,
input  logic [TAG_BITS-1:0]  free2_tag,
```

##### Execute Interface (to ALUs)

```systemverilog
output logic [TAG_BITS-1:0]  exec0_dest_tag,
output logic [31:0]          exec0_src1_value,
output logic [31:0]          exec0_src2_value,
output logic [CONTROL_WIDTH-1:0] exec0_ctrl,

// Same for exec1 (second ALU)
```

---

#### Sequential Operations

The RUU performs four operations: **Dispatch**, **Writeback (Wake-up)**, **Issue**, and **Free**. 

##### Dispatch: Adding New Instructions

When instructions are decoded, they are dispatched to the first available RUU slots. The module scans for free entries (`valid == 0`):

```systemverilog
always_comb begin
    found1 = 1'b0;
    found2 = 1'b0;
    for (int i = 0; i < DEPTH; i++) begin
        if (!entries[i].valid) begin
            if (!found1) begin
                found1    = 1'b1;
                slot1_idx = i;
            end else if (!found2) begin
                found2    = 1'b1;
                slot2_idx = i;
            end
        end
    end
end
```

##### Writeback (Wake-up): CDB Broadcast

When an ALU completes, it broadcasts the result on the CDB. All RUU entries **simultaneously** check if they're waiting for this tag. This happens on the **negative edge** to allow same-cycle wake-up and issue.

```systemverilog
always_ff @(negedge clk) begin
    if (wb1_en) begin
        for (int i = 0; i < DEPTH; i++) begin
            // Check source 1
            if (entries[i].valid && !entries[i].src1_valid &&
                (entries[i].src1_tag == wb1_tag)) begin
                entries[i].src1_valid <= 1'b1;
                entries[i].src1_value <= wb1_value;
            end
            // Check source 2
            if (entries[i].valid && !entries[i].src2_valid &&
                (entries[i].src2_tag == wb1_tag)) begin
                entries[i].src2_valid <= 1'b1;
                entries[i].src2_value <= wb1_value;
            end
        end
    end
    // Same for wb2...
end
```

##### Issue: Selecting Ready Instructions

The issuer scans for entries that are **valid**, **not yet issued**, and have **both operands ready**. Up to 2 instructions can issue per cycle to the 2 ALUs.

```systemverilog
always_comb begin
    issue0_valid = 1'b0;
    issue0_idx   = '0;
    
    // First ALU: find oldest ready instruction
    for (int i = 2; i < DEPTH; i++) begin
        if (!issue0_valid &&
            entries[i].valid &&
            !entries[i].issued &&
            entries[i].src1_valid &&
            entries[i].src2_valid) begin
            issue0_valid = 1'b1;
            issue0_idx   = i;
        end
    end
    
    // Second ALU: find next ready instruction (different from first)
    for (int i = 2; i < DEPTH; i++) begin
        if (!issue1_valid &&
            entries[i].valid &&
            !entries[i].issued &&
            entries[i].src1_valid &&
            entries[i].src2_valid &&
            (!issue0_valid || (issue0_idx != i))) begin
            issue1_valid = 1'b1;
            issue1_idx   = i;
        end
    end
end
```

##### Free: Releasing Entries After Commit

When the ROB commits an instruction, the corresponding RUU entry is freed by clearing its `valid` bit. The entry is matched by `dest_tag`.

```systemverilog
if (free1_en) begin
    for (int i = 0; i < DEPTH; i++) begin
        if (free1_tag == entries[i].dest_tag) begin
            entries[i].valid  <= 1'b0;
            entries[i].issued <= 1'b0;
        end
    end
end
```

---

#### Timing strategy: Negative Edge for Writeback?

```systemverilog
always_ff @(negedge clk) begin
    // Writeback (wake-up) logic
end
```

The writeback logic runs on the **negative edge** of the clock while dispatch, issue, and free run on the **positive edge**. This design choice enables **same-cycle wake-up**:

![diagram](ruuwritebacktrick.png)

Without this, an instruction would have to wait an extra cycle after its producer completes before it could issue.

This technique was not part of the first implementation of this circuit. However, using GTKWave, we examined the ALU operands signals wave and observed a delay.

Below is what we observed before writing back at the negative edge of the clock: (all the work was done in the positive edge)

![diagram](writebackposedge.jpeg)

Below is what we observed before writing back at the negative edge of the clock:

![diagram](writebacknegedge.jpeg)

Indeed, this strategy of writing back at the negative edge eliminates the delay and increase the throughput.

---

### 2.4 Pipelined Design

#### Overview

To maximize throughput, we divide the processor into **5 pipeline stages**, each designed to complete within a similar time budget. The clock period is determined by the **slowest stage**, so balancing stage delays is critical for performance.

#### Component Delays

The following table (from Harris and Harris) shows typical propagation delays:

![diagram](component_delays.png)

---

#### Pipeline Stages and Timing Analysis

##### Stage 1: Fetch (F)

**Operations:**
- Read 2 instructions from instruction memory using PC
- Compute PC + 8 for next fetch

**Components in critical path:**
```
t_pcq + t_mem + t_setup
= 40 + 200 + 50
= 290 ps
```

> Note: The instruction memory is implemented as a dual-port memory, allowing two instructions to be fetched in parallel within a single t_mem = 200 ps access.
> 
---

##### Stage 2: Rename/Decode (D)

**Operations:**
- Decode both instructions (control unit)
- Sign-extend immediates
- Read 4 source registers from register file
- Query RAT for producer tags (4 lookups)
- Query ROB for operand values (4 lookups)
- Determine operand validity
- Select operand sources via muxes

**Components in critical path:**
```
t_pcq + t_dec + t_RFread + t_mux + t_setup
= 40 + 25 + 100 + 30 + 50
= 245 ps
```

However, the RAT/ROB queries and validity logic run in parallel with register file reads:
```
RAT lookup + ROB lookup + validity logic + mux:
t_pcq + t_RAT + t_ROB + t_AND-OR + t_mux + t_setup
≈ 40 + 30 + 30 + 20 + 30 + 50
= 200 ps
```

The register file read path dominates, so: **245 ps**

---

##### Stage 3: Dispatch/Issue (Iss)

**Operations:**
- Insert entries into RUU (dispatch)
- Scan RUU for ready instructions (issue selection)
- Output operands and control signals for ready instructions

**Components in critical path:**

The issue logic scans all 64 RUU entries to find ready instructions. This is a priority encoder over valid & ready bits:
```
t_pcq + t_RUU_scan + t_mux + t_setup
= 40 + (64 × t_AND-OR) + 30 + 50
```

In practice, the scan is implemented as combinational logic with depth proportional to log(DEPTH):
```
≈ 40 + 6 × 20 + 30 + 50
= 240 ps
```

---

##### Stage 4: Execute + Writeback to ROB (E)

**Operations:**
- ALU computation (2 ALUs in parallel)
- Broadcast results on CDB
- Write results to ROB entries

**Components in critical path:**
```
t_pcq + t_ALU + t_setup
= 40 + 120 + 50
= 210 ps
```

The ROB write is a register array write, so we use t_setup.

The CDB broadcast to RUU (wake-up) happens on the **negative edge**, so it doesn't add to this stage's delay.

---

##### Note: Implicit Pipelining Between Execute and Commit

There is **no explicit pipeline register** between the Execute (E) and Commit (C) stages. However, pipelining is still correctly maintained because:

- **Execute stage** writes results to ROB on the **positive edge**
- **Commit stage** reads from ROB head and writes to the register file on the **positive edge**

Since the ROB is a buffer **with separate head and tail pointers**, these operations target **different entries**.

As a result, while a pair of instruction is being written to the Re-Order Buffer another pair of instruction is being commited into the register file.

---

##### Stage 5: Commit (C)

**Operations:**
- Read 2 entries from ROB head
- Write up to 2 results to architectural register file
- Free corresponding RUU entries

**Components in critical path:**
```
t_pcq + t_ROB_read + t_RFsetup
= 40 + 30 + 60
= 130 ps
```

---

#### Pipeline Summary

| Stage | Name | Operations | Critical Path Delay |
|-------|------|------------|---------------------|
| **F** | Fetch | Read 2 instructions from memory | **290 ps** |
| **D** | Rename/Decode | Decode, read registers, RAT/ROB lookup | 245 ps |
| **Iss** | Dispatch/Issue | Insert to RUU, select ready instructions | 240 ps |
| **E** | Execute | ALU computation, write to ROB | 240 ps |
| **C** | Commit | Write to register file, free RUU | 130 ps |

**Clock Period = max(all stages) = 290 ps** (limited by Fetch stage)

---

#### Performance Comparison

For a fair comparison, we consider a single-cycle arithmetic-only processor (no load/store), where the single cycle clock cycle can be calculated as follow:

```
Tc_single_arith = t_pcq + t_mem + t_RFread + t_ALU + t_mux + t_RFsetup
                = 40 + 200 + 100 + 120 + 30 + 60
                = 550 ps
```

| Metric | Single-Cycle (Arith Only) | 5-Stage Pipelined OoO |
|--------|---------------------------|----------------------|
| Clock Period | ~550 ps | **290 ps** |
| CPI | 1.0 | < 1.0 (superscalar) |
| Instructions/Cycle | 1 | Very close to 2 |

**Theoretical Speedup:**
- Clock speedup: 550 / 290 = **1.9×**
- Superscalar factor: up to **2×** (2 ALUs)
- Combined potential: up to **3.8×** throughput improvement
In practice, dependencies and structural hazards reduce the effective IPC below 2.0, but the out-of-order execution minimizes stalls compared to an in-order superscalar design.

---

### 2.5 Overall Integration

This section describes how all components connect together, with particular focus on the **source operand validity logic** which is the critical decision-making process that determines where each operand comes from and whether the instruction can issue immediately.

#### Modified Core Components

To support 2-way superscalar out-of-order execution, the basic processor components were modified:

##### Register File: 4 Read Ports, 2 Write Ports

```systemverilog
module sup_regfile (
    // WRITE PORT 1
    input  logic [DATA_WIDTH-1:0] WD1,
    input  logic WE1,
    input  logic [4:0] AD1W,
    // WRITE PORT 2
    input  logic [DATA_WIDTH-1:0] WD2,
    input  logic WE2,
    input  logic [4:0] AD2W,
    // READ PORTS 1-4
    input  logic [4:0] AD1R, AD2R, AD3R, AD4R,
    output logic [DATA_WIDTH-1:0] RD1, RD2, RD3, RD4,
    ...
);
```

| Ports | Purpose |
|-------|---------|
| 4 Read Ports | 2 source registers × 2 instructions |
| 2 Write Ports | 2 commits per cycle from ROB |

Writes occur on **negative edge** to allow same-cycle read-after-write .

##### ALU: Simplified (No Comparison Flags)

```systemverilog
module sup_alu (
    input  logic [DATA_WIDTH-1:0] ALUop1,
    input  logic [DATA_WIDTH-1:0] ALUop2,
    input  logic [3:0]            ALUCtrl,
    output logic [DATA_WIDTH-1:0] ALUout
);
```

Since we only support arithmetic instructions (no branches), the ALU no longer outputs comparison flags (`EQ`, `LT`, `LTU`). Two identical ALUs operate in parallel.

##### Control Unit: Arithmetic Only

```systemverilog
module sup_control (
    input  logic [DATA_WIDTH-1:0] instr,
    output logic [3:0] ALUCtrl,   // ALU operation
    output logic       ALUSrc,    // 0=register, 1=immediate for operand 2
    output logic [2:0] ImmSrc,    // Immediate format
    output logic       ALUsrc2    // 0=register, 1=PC for operand 1
);
```

The control unit is simplified to only decode:
- R-type arithmetic (`ADD`, `SUB`, `AND`, `OR`, `XOR`, `SLT`, `SLTU`, `SLL`, `SRL`, `SRA`)
- I-type arithmetic (`ADDI`, `ANDI`, `ORI`, `XORI`, `SLTI`, `SLTIU`, `SLLI`, `SRLI`, `SRAI`)
- Upper immediate (`LUI`, `AUIPC`)

Two identical control units decode both instructions in parallel.

---

#### Source Operand Validity Logic

The most critical part of the integration is determining **where each source operand comes from** and **whether it's available**. This logic runs during the Rename/Decode stage.

##### Decision Tree

For each source register, we follow this decision process:

![diagram](decisiontree.jpg)

##### Implementation

```systemverilog
module src_operand_validity_logic (
    input  logic                      rat_has_producer,
    input  logic [ROB_TAG_WIDTH-1:0]  rat_tag,
    input  logic                      rob_entry_ready,
    output logic                      operand_valid,
    output logic                      fetch_from_regfile
);
    always_comb begin
        if (!rat_has_producer) begin
            // Case 1: No producer, we fetch from register file
            operand_valid      = 1'b1;
            fetch_from_regfile = 1'b1;
        end
        else if (rob_entry_ready) begin
            // Case A: Producer finished, we fetch from ROB
            operand_valid      = 1'b1;
            fetch_from_regfile = 1'b0;
        end
        else begin
            // Case B: Producer not finished, we wait for CDB
            operand_valid      = 1'b0;
            fetch_from_regfile = 1'b0;  // Don't care
        end
    end
endmodule
```

##### Value Selection

Based on the validity logic output, we select the operand value:

```systemverilog
assign value_source1 = source1_selectline ? q1_value : RS1_val;

```

---

#### Special Case: Instruction 2 Depends on Instruction 1

The logic above works for Instruction 1, but **Instruction 2 has a complication**: the RAT and ROB haven't been updated yet with Instruction 1's destination.

Consider this sequence fetched together:
```asm
ADD  x5, x1, x2    # Instr1: produces x5
SUB  x6, x5, x3    # Instr2: needs x5 — but RAT doesn't know about Instr1 yet!
```

When we look up `x5` in the RAT for Instruction 2, it returns the **old** producer (or none), not Instruction 1. We must add **extra dependency checking**:

```systemverilog
// Check if Instruction 2's sources depend on Instruction 1's destination
assign is_rs3_dependent_on_RD1 = (RD1 == RS3);  // RD1 = Instr1's dest
assign is_rs4_dependent_on_RD1 = (RD1 == RS4);
```

If there's a dependency, we **bypass** the normal RAT/ROB lookup :

```systemverilog
// Source 3 (Instruction 2's first source)
assign value_source3 = is_rs3_dependent_on_RD1 ? 
                       32'b0 :                          // Value unknown, will come via CDB
                       (source3_selectline ? q3_value : RS3_val);

assign validity_source3 = is_rs3_dependent_on_RD1 ? 
                          1'b0 :                        // Not valid — must wait
                          tmp_validity_source3;

assign tag_source3 = is_rs3_dependent_on_RD1 ? 
                     (latest_tag - 1) :                 // Use Instr1's tag
                     tmp_q3_tag;
```

The key insight: when Instruction 2 depends on Instruction 1, we:
1. Set `validity = 0` (operand not ready)
2. Set `tag = Instr1's tag` (so CDB can wake it up)
3. Set `value = don't care` (will be filled by CDB)

When Instruction 2 depends on Instruction 1, we use `latest_tag - 1` as the producer tag so that when it's paired instruction has executed, it will correctly fill the corresponding operand value in the register update unit.

The RAT assigns tags as:
- Instruction 1 gets `latest_tag - 1`
- Instruction 2 gets `latest_tag`


---

#### Immediate Operand Handling

For I-type instructions, the second operand is an immediate, not a register. In this case, we **force validity to 1** because we know that the operand contains the right value and we avoid overwritting in the register update unit by the common data bus:

```systemverilog
assign final_validity_source1 = ALU1Src2 ? 1'b1 : validity_source1;
assign final_validity_source2 = ALU1Src1 ? 1'b1 : validity_source2;
assign final_validity_source3 = ALU2Src2 ? 1'b1 : validity_source3;
assign final_validity_source4 = ALU2Src1 ? 1'b1 : validity_source4;
```

The muxes select between register values and immediates/PC in the decode/rename stage because we want to store the correct operand in the Register Update Unit (Reservation Station) :

```systemverilog
// Operand 1: Register value or PC
mux mux_ALU1_pcVSreg(
    .in0(value_source1),
    .in1(PCPlus8D - 8),      // PC value for AUIPC
    .sel(ALU1Src2),
    .out(ALU1_op1D)
);

// Operand 2: Register value or Immediate
mux mux_ALU1_immVSreg(
    .in0(value_source2),
    .in1(ExtImm1D),          // Sign-extended immediate
    .sel(ALU1Src1),
    .out(ALU1_op2D)
);
```

---

## 3. Schematic


---

## 4. Testing & Verification

### 4.1 Unit Testing

#### 4.1.1 RAT Testing



---

#### 4.1.2 ROB Testing


---

#### 4.1.3 RUU Testing


---

### 4.2 Assembly Test Programs


---

### 4.3 Results


---

## 5. References


---
