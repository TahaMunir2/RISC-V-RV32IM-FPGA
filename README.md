# Out-of-Order Superscalar Processor with Load Instructions

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
  - [2.1 Adapting Data Memory for Superscalar](#21-adapting-data-memory-for-superscalar)
  - [2.2 Doubling the Common Data Bus Width](#22-doubling-the-common-data-bus-width)
  - [2.3 Load Instruction Integration](#23-load-instruction-integration)
- [3. Schematic](#3-schematic)
- [4. Testing & Verification](#4-testing--verification)
- [5. References](#5-references)

---

## 1. Overview

### Building on the Foundation

This branch extends the **out-of-order superscalar arithmetic processor** developed in the previous branch by adding support for **load instructions** (`LW`, `LH`, `LB`, `LHU`, `LBU`).

The core Tomasulo-based infrastructure remains unchanged:
- **Register Alias Table (RAT)** for register renaming
- **Re-Order Buffer (ROB)** for in-order commit
- **Register Update Unit (RUU)** for instruction buffering and issue
- **Common Data Bus (CDB)** for result broadcasting
- **Source operand logic** for correct dispatch in the register update unit (RUU)

> **Important**: The fundamental logic of the out-of-order execution (including the source operand validity logic, the renaming in the Register Aliasing Table, the ROB circular buffer mechanics, and the RUU wake-up mechanism) is thoroughly explained in the [Out-of-Order Superscalar Arithmetic branch](../ooo-superscalar-arith/README.md). This README focuses only on the **modifications required to support load instructions**.

### Challenges imposed by the implementation of the load instruction

**Control Unit Complexity**: Loads decode differently from arithmetic instructions (single source operand, memory control signals), and integrating this into the already complex dual-instruction Rename/Decode stage requires careful control logic expansion.

**Additional Writeback Source**: Results now come from both ALUs and memory, requiring a wider Common Data Bus. The ROB and RUU must handle writeback from 4 sources instead of 2.

**Synchronization Between All 4 Writeback Sources**:The CDB must broadcast all results, the ROB must update four entries , and the RUU must wake up any instruction waiting on any of these four tags, all within a single clock cycle.

### Approach

To integrate loads while minimizing changes to the existing architecture:

- **Re-Using already existing signals in decode** : For a load instruction we ignore RS2 and use only RS1, we also calculate the offset in this stage so that we can store the correct operand in the Register Update Unit
- **Add memory stage To the Pipeline Architecture**: After address calculation, loads access data memory in a subsequent stage
- **Double CDB width**: The ROB and RUU now accept 4 writeback inputs (2 from ALUs, 2 from memory) instead of 2

The following sections detail each modification. For understanding the base Tomasulo implementation, refer to the previous branch documentation.

---

## 2. Implementation

### 2.1 Adapting Data Memory for Superscalar

#### Original Data Memory (Single-Port)

The original data memory module from the pipelined processor supports **one read and one write** per cycle:

```systemverilog
module datamem (
    input  logic                     MemWrite,
    input  logic [ADDRESS_WIDTH-1:0] WD,
    input  logic [1:0]               SizeWrite,
    input  logic [ADDRESS_WIDTH-1:0] A, 
    input  logic [1:0]               LoadSize,
    input  logic                     LoadUnsigned,
    input  logic                     clk,
    output logic [DATA_WIDTH-1:0]    dout
);
```

This is insufficient for our 2-way superscalar processor where **two load instructions may execute simultaneously**.

#### Superscalar Data Memory (Dual-Port)

The adapted memory module provides **two independent read ports**:

```systemverilog
module sup_datamem (
    // Port 1
    input  logic [ADDRESS_WIDTH-1:0] A1, 
    input  logic [1:0]               LoadSize1,
    input  logic                     LoadUnsigned1,
    output logic [DATA_WIDTH-1:0]    dout1,
    
    // Port 2
    input  logic [ADDRESS_WIDTH-1:0] A2,
    input  logic [1:0]               LoadSize2,
    input  logic                     LoadUnsigned2,
    output logic [DATA_WIDTH-1:0]    dout2
);
```

#### Load Type Encoding Remains The Same

| LoadSize | LoadUnsigned | Instruction | Loaded Data |
|----------|--------------|-------------|-------------|
| `2'b00` | `0` | `LB` | Sign-extended byte |
| `2'b00` | `1` | `LBU` | Zero-extended byte |
| `2'b01` | `0` | `LH` | Sign-extended halfword |
| `2'b01` | `1` | `LHU` | Zero-extended halfword |
| `2'b10` | `X` | `LW` | Full word (no extension) |


Both ports can access the same underlying memory array simultaneously, enabling two loads per cycle in our superscalar design.

Since we only support **load instructions** (not stores), the superscalar data memory has no write interface

---

### 2.2 Doubling the Common Data Bus Width

With load instructions, results can come from **two sources**: the ALUs and the data memory. Since both can produce results in the same cycle, the Common Data Bus must be widened to handle 4 writebacks simultaneously.

#### 2.2.1 ROB Writeback Expansion

##### Previous Design: 2 Writeback Ports

In the arithmetic-only implementation, the ROB received results from **2 ALUs**:

```systemverilog
// Writeback interface (2 ALUs)
input  logic                  wb1_en,
input  logic [TAG_BITS-1:0]   wb1_tag,
input  logic [31:0]           wb1_value,

input  logic                  wb2_en,
input  logic [TAG_BITS-1:0]   wb2_tag,
input  logic [31:0]           wb2_value,
```

##### New Design: 4 Writeback Ports

With memory operations, we add **2 additional ports** for memory results:

```systemverilog
// Writeback interface from the Execute stage (ALUs)
input  logic                  wb1_en,
input  logic [TAG_BITS-1:0]   wb1_tag,      
input  logic [31:0]           wb1_value,     

input  logic                  wb2_en,
input  logic [TAG_BITS-1:0]   wb2_tag,       
input  logic [31:0]           wb2_value,

// Writeback interface from the Memory stage (Loads)
input  logic                  wb3_en,
input  logic [TAG_BITS-1:0]   wb3_tag,        
input  logic [31:0]           wb3_value,      

input  logic                  wb4_en,
input  logic [TAG_BITS-1:0]   wb4_tag,        
input  logic [31:0]           wb4_value,
```

| Port | Source | Description |
|------|--------|-------------|
| `wb1` | ALU 1 | First ALU result |
| `wb2` | ALU 2 | Second ALU result |
| `wb3` | Memory Port 1 | First load result |
| `wb4` | Memory Port 2 | Second load result |

##### Writeback Logic Expansion

The sequential writeback logic is extended to handle all 4 ports:

**Before (2 ports):**
```systemverilog
always_ff @(posedge clk) begin
    // ...
    if (wb1_en) begin
        value[wb1_tag] <= wb1_value;
        ready[wb1_tag] <= 1'b1;
    end

    if (wb2_en) begin
        value[wb2_tag] <= wb2_value;
        ready[wb2_tag] <= 1'b1;
    end
end
```

**After (4 ports):**
```systemverilog
always_ff @(posedge clk) begin
    // ...
    // ALU writebacks
    if (wb1_en) begin
        value[wb1_tag] <= wb1_value;
        ready[wb1_tag] <= 1'b1;
    end

    if (wb2_en) begin
        value[wb2_tag] <= wb2_value;
        ready[wb2_tag] <= 1'b1;
    end

    // Memory writebacks
    if (wb3_en) begin
        value[wb3_tag] <= wb3_value;
        ready[wb3_tag] <= 1'b1;
    end

    if (wb4_en) begin
        value[wb4_tag] <= wb4_value;
        ready[wb4_tag] <= 1'b1;
    end
end
```

##### No Conflicts Between Ports

Each writeback port writes to a **different ROB entry** (identified by its unique tag). Since:
- Each in-flight instruction has a unique tag
- ALU results and memory results correspond to different instructions
- Tags are assigned sequentially and never reused until commit


#### 2.2.2 RUU Writeback Expansion

The Register Update Unit requires similar modifications to handle results from both ALUs and memory. Additionally, the RUU entry structure and issue logic must be adapted for load instructions.

##### Expanded Writeback Interface

**Before (2 CDB inputs):**
```systemverilog
// Execute stage only
input  logic                 wb1_en,
input  logic [TAG_BITS-1:0]  wb1_tag,
input  logic [31:0]          wb1_value,

input  logic                 wb2_en,
input  logic [TAG_BITS-1:0]  wb2_tag,
input  logic [31:0]          wb2_value,
```

**After (4 CDB inputs):**
```systemverilog
// Execute stage (ALUs)
input  logic                 wb1_en,
input  logic [TAG_BITS-1:0]  wb1_tag,
input  logic [31:0]          wb1_value,

input  logic                 wb2_en,
input  logic [TAG_BITS-1:0]  wb2_tag,
input  logic [31:0]          wb2_value,

// Memory stage (Loads)
input  logic                 wb3_en,
input  logic [TAG_BITS-1:0]  wb3_tag,
input  logic [31:0]          wb3_value,

input  logic                 wb4_en,
input  logic [TAG_BITS-1:0]  wb4_tag,
input  logic [31:0]          wb4_value,
```

##### Expanded Wake-Up Logic

The CDB broadcast logic now checks **4 sources** instead of 2. Each waiting operand must compare its tag against all 4 possible broadcasts:

```systemverilog
always_ff @(negedge clk) begin
    // ALU 1 broadcast
    if (wb1_en) begin
        for (int i = 0; i < DEPTH; i++) begin
            if (entries[i].valid && !entries[i].src1_valid &&
                (entries[i].src1_tag == wb1_tag)) begin
                entries[i].src1_valid <= 1'b1;
                entries[i].src1_value <= wb1_value;
            end
            if (entries[i].valid && !entries[i].src2_valid &&
                (entries[i].src2_tag == wb1_tag)) begin
                entries[i].src2_valid <= 1'b1;
                entries[i].src2_value <= wb1_value;
            end
        end
    end

    // ALU 2 broadcast
    if (wb2_en) begin
        // ... same pattern
    end

    // Memory port 1 broadcast
    if (wb3_en) begin
        // ... same pattern
    end

    // Memory port 2 broadcast
    if (wb4_en) begin
        // ... same pattern
    end
end
```

##### Expanded Entry Structure

Each RUU entry now includes **load-specific control signals**:

**Before:**
```systemverilog
typedef struct packed {
    logic                     valid;
    logic                     issued;
    logic [TAG_BITS-1:0]      dest_tag;
    logic                     src1_valid;
    logic [TAG_BITS-1:0]      src1_tag;
    logic [31:0]              src1_value;
    logic                     src2_valid;
    logic [TAG_BITS-1:0]      src2_tag;
    logic [31:0]              src2_value;
    logic [CONTROL_WIDTH-1:0] ctrl;
} ruu_entry_t;
```

**After:**
```systemverilog
typedef struct packed {
    logic                     valid;
    logic                     issued;
    logic [TAG_BITS-1:0]      dest_tag;
    logic                     src1_valid;
    logic [TAG_BITS-1:0]      src1_tag;
    logic [31:0]              src1_value;
    logic                     src2_valid;
    logic [TAG_BITS-1:0]      src2_tag;
    logic [31:0]              src2_value;
    logic [CONTROL_WIDTH-1:0] ctrl;
    // New fields for load instructions
    logic [1:0]               ResultSrc;      // 01 = load instruction
    logic [1:0]               LoadSize;       // 00=byte, 01=half, 10=word
    logic                     LoadUnsigned;   // 0=signed, 1=unsigned
} ruu_entry_t;
```

##### Modified Issue Logic: Loads Need Only One Operand

A critical change for load instructions: **loads only need `src1` (base address)**, not `src2`. The issue condition is modified:

**Before (arithmetic only):**
```systemverilog
// Issue when BOTH operands ready
if (!issue0_valid &&
    entries[i].valid &&
    !entries[i].issued &&
    entries[i].src1_valid &&
    entries[i].src2_valid) begin
    issue0_valid = 1'b1;
    issue0_idx   = i;
end
```

**After (with loads):**
```systemverilog
// Issue when src1 ready AND (src2 ready OR it's a load)
if (!issue0_valid &&
    entries[i].valid &&
    !entries[i].issued &&
    entries[i].src1_valid &&
    (entries[i].src2_valid || (entries[i].ResultSrc == 2'b01))) begin
    issue0_valid = 1'b1;
    issue0_idx   = i;
end
```

The condition `(entries[i].src2_valid || (entries[i].ResultSrc == 2'b01))` means:
- For arithmetic: both operands must be valid
- For loads (`ResultSrc == 01`): only `src1` (base address) needs to be valid

##### Expanded Execute Interface

The execute outputs now include load control signals:

```systemverilog
// Execute interface outputs
output logic [TAG_BITS-1:0]      exec0_dest_tag,
output logic [31:0]              exec0_src1_value,
output logic [31:0]              exec0_src2_value,
output logic [CONTROL_WIDTH-1:0] exec0_ctrl,
output logic [1:0]               exec0_ResultSrc,    // New
output logic [1:0]               exec0_LoadSize,     // New
output logic                     exec0_LoadUnsigned, // New

// Same for exec1
```

These signals flow to the memory stage to control the load operation.

##### Dispatch Interface Expansion

The dispatch interface also accepts load control signals:

```systemverilog
input logic [1:0] dispatch1_ResultSrc,
input logic [1:0] dispatch1_LoadSize,
input logic       dispatch1_LoadUnsigned,

input logic [1:0] dispatch2_ResultSrc,
input logic [1:0] dispatch2_LoadSize,
input logic       dispatch2_LoadUnsigned,
```

---

### 2.3 Load Instruction Integration


---


## 3. Schematic

<!-- TODO: Circuit diagram showing memory integration -->

---

## 4. Testing & Verification



## 5. References

<!-- TODO: References -->

---
