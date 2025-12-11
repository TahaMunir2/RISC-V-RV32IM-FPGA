https://github.com/TahaMunir2/Team5/blob/main/images/ooofverify.jpg# Out-of-Order Superscalar Processor with Load Instructions

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
  - [2.1 Adapting Data Memory in the Out of Order Superscalar circuit](#21-adapting-data-memory-for-superscalar)
  - [2.2 Doubling the Common Data Bus Width](#22-doubling-the-common-data-bus-width)
  - [2.3 Load Instruction Integration](#23-load-instruction-integration)
- [3. Schematic](#3-schematic)
- [4. Testing & Verification](#4-testing--verification)

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

This section details the specific changes required to integrate load instructions into the out-of-order superscalar processor. We compare the arithmetic-only version with the load-enabled version to highlight each modification.

#### Control Unit Expansion

The control unit now generates additional signals for load instructions:

**Before (arithmetic only):**
```systemverilog
sup_control control1 (
    .instr(Instr1D),
    .ALUCtrl(ALUCtrl1D),
    .ALUSrc(ALU1Src1),
    .ImmSrc(ImmSrc1D),
    .ALUsrc2(ALU1Src2)
);
```

**After (with loads):**
```systemverilog
sup_control control1 (
    .instr(Instr1D),
    .ALUCtrl(ALUCtrl1D),
    .ALUSrc(ALU1Src1),
    .ImmSrc(ImmSrc1D),
    .ALUsrc2(ALU1Src2),
    .ResultSrc(ResultSrc1D),      // New: 01 = load instruction
    .LoadSize(LoadSize1D),        // New: byte/half/word
    .LoadUnsigned(LoadUnsigned1D) // New: sign extension control
);
```

| New Signal | Width | Purpose |
|------------|-------|---------|
| `ResultSrc` | 2 bits | `00` = ALU result, `01` = memory result |
| `LoadSize` | 2 bits | `00` = byte, `01` = half, `10` = word |
| `LoadUnsigned` | 1 bit | `0` = sign-extend, `1` = zero-extend |

---

#### Critical Change (Key design choice): Address Calculation in Decode Stage

The most significant change in the Decode/Rename stage is **pre-computing the effective address** for load instructions.

Load instructions have the form: `lw rd, offset(rs1)`

The effective address is: `address = rs1 + offset`

In the arithmetic-only design, operand 1 (`ALU_op1`) was simply the register value. For loads, we need to **add the immediate offset before storing in the RUU**.

##### Implementation

**Before (arithmetic only):**
```systemverilog
mux mux_ALU1_pcVSreg(
    .in0(value_source1),
    .in1(PCPlus8D - 8),
    .sel(ALU1Src2),
    .out(ALU1_op1D)      // Direct output to pipeline
);
```

**After (with loads):**
```systemverilog
logic [DATA_WIDTH-1:0] tmp_ALU1_op1D;

mux mux_ALU1_pcVSreg(
    .in0(value_source1),
    .in1(PCPlus8D - 8),
    .sel(ALU1Src2),
    .out(tmp_ALU1_op1D)  // Intermediate value
);

// If load instruction, pre-add the offset
assign ALU1_op1D = (ResultSrc1D == 2'b00) ? tmp_ALU1_op1D : tmp_ALU1_op1D + ExtImm1D;
```

This means:
- **Arithmetic instructions** (`ResultSrc == 00`): `ALU_op1 = rs1` (unchanged)
- **Load instructions** (`ResultSrc == 01`): `ALU_op1 = rs1 + offset` (pre-computed address)

##### Justifying This Design Choice

This design decision involves a trade-off between **Decode stage complexity** and **RUU storage efficiency**.

**Option A: Pre-compute address in Decode (Our Choice)**
- Add an adder and mux in Decode stage
- Store only the computed address in RUU

**Option B: Store offset separately, compute in Execute**
- Store both `rs1_value` (32 bits) AND `offset` (32 bits) in each RUU entry
- Compute `rs1 + offset` in Execute stage

We chose Option A for the following reasons:

**1. RUU Entry Size Matters**

Each RUU entry already stores:
```
valid (1) + issued (1) + dest_tag (6) + 
src1_valid (1) + src1_tag (6) + src1_value (32) +
src2_valid (1) + src2_tag (6) + src2_value (32) +
ctrl (4) + ResultSrc (2) + LoadSize (2) + LoadUnsigned (1)
= 95 bits per entry
```

Adding a separate 32-bit offset field would increase this to **127 bits per entry**. With 64 entries, this adds **2,048 bits (256 bytes)** of storage.

**2. RUU Scan Performance**

The RUU performs multiple operations that scan all 64 entries every cycle:
- **Issue logic**: Find 2 oldest ready instructions
- **Wake-up logic**: Compare 4 CDB tags against all waiting operands
- **Free logic**: Find entries matching commit tags

Larger entries mean:
- More comparators and wider buses
- Increased wire delay across the array
- Higher power consumption

**3. Decode Stage Can Absorb the Cost**

The Decode stage already performs:
- Control decoding (t_dec = 25 ps)
- Register file read (t_RFread = 100 ps)
- RAT/ROB lookups
- Sign extension (t_ext = 35 ps)
- Operand validity logic

Adding one 32-bit adder in parallel with existing logic has minimal impact on the critical path, since:
- The adder operates on `value_source1` (already available from regfile/ROB)
- The immediate `ExtImm1D` is already computed by sign extension
- A 32-bit adder delay ≈ 30-40 ps (similar to t_mux)

**4. Pipeline Stage Timing Comparison**

| Stage | Without Pre-compute | With Pre-compute |
|-------|---------------------|------------------|
| Decode | 245 ps | ~275 ps (+adder) |
| RUU Scan | Slower (larger entries) | Faster (smaller entries) |
| Execute | +adder for loads | No change |

The Decode stage increase (~30 ps) is acceptable because:
- Decode (275 ps) is still faster than Fetch (290 ps)
- The clock period is limited by Fetch, not Decode
- RUU efficiency benefits every cycle, not just load cycles

The trade-off favors pre-computing: a small Decode stage penalty for significant RUU efficiency gains.

---

#### Conditional Writeback Enable

A critical change: writeback enables are now **conditional** based on instruction type.

**Before (arithmetic only):**
```systemverilog
// ROB writeback lways enabled
.wb1_en(write_back_rob),  // Constant 1
.wb1_tag(ALU1_tagE),
.wb1_value(ALU1ResultE),
```

**After (with loads):**
```systemverilog
// Execute stage writeback only for arithmetic
.wb1_en((ResultSrc1E == 2'b00)),  
.wb1_tag(ALU1_tagE),
.wb1_value(ALU1ResultE),

// Memory stage writeback only for loads
.wb3_en((ResultSrc1M == 2'b01)),  
.wb3_tag(mem1_tag),
.wb3_value(MemoryOut1),
```

This ensures:
- **Arithmetic results** write back from Execute stage (immediate)
- **Load results** write back from Memory stage (one cycle later)
- No double-writeback for the same instruction

---

#### New Execute Memory Pipeline

A completely new pipeline register is added:

```systemverilog
em_sup_pipeline em_pipeline(
    .clk(clk),
    .rst(rst),

    // Control signals
    .ResultSrc1_e(ResultSrc1E),
    .LoadSize1_e(LoadSize1E), 
    .LoadUnsigned1_e(LoadUnsigned1E),
    .ResultSrc1_m(ResultSrc1M),
    .LoadSize1_m(LoadSize1M), 
    .LoadUnsigned1_m(LoadUnsigned1M),

    .ResultSrc2_e(ResultSrc2E),
    .LoadSize2_e(LoadSize2E), 
    .LoadUnsigned2_e(LoadUnsigned2E),
    .ResultSrc2_m(ResultSrc2M),
    .LoadSize2_m(LoadSize2M), 
    .LoadUnsigned2_m(LoadUnsigned2M),

    // Address (computed in Execute, used in Memory)
    .address1_e(ALU1_op1E),
    .address1_m(A1),
    .address2_e(ALU2_op1E),
    .address2_m(A2),

    // ROB tags (for writeback identification)
    .ALU1_tagE(ALU1_tagE),
    .ALU2_tagE(ALU2_tagE),
    .ALU1_tagM(mem1_tag),
    .ALU2_tagM(mem2_tag)
);
```

The tags are propagated so the Memory stage knows which ROB entry to update.

---


## 3. Schematic

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/ooofverify.jpg)

---

## 4. Testing & Verification

This section documents the testing for the complete out-of-order superscalar processor . The test suite consists of 17 tests: 10 reused from the ALU-only version and 7 new tests specifically designed to verify load instruction functionality.

### Test Data Memory

All load tests use `reference/testing.mem` as the data memory, which contains a sequential byte pattern from `0x01` to `0xFF`:

```
01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 10
...
F1 F2 F3 F4 F5 F6 F7 F8 F9 FA FB FC FD FE FF
```

This predictable pattern allows easy verification of load operations at any address. 

---

### Reused Tests (1-10)

The following 10 tests from the ALU-only superscalar processor are reused to ensure backward compatibility:

| # | Test Name | Assembly File | Expected `a0` | Purpose |
|---|-----------|---------------|---------------|---------|
| 1 | TestLiAdd | `2_li_add.s` | 1000 | Basic arithmetic, `li` pseudo-instruction |
| 2 | TestSubAdd | `sup_sub_add.s` | 4 | Mixed add/sub with dependencies |
| 3 | TestRAWChain | `straight_raw_chain.s` | 24 | RAW dependency chain, CDB wakeup |
| 4 | SimpleWAW | `waw_simple.s` | 99 | WAW hazard, in-order commit |
| 5 | warsimple | `war_simple.s` | 5 | WAR hazard, register renaming |
| 6 | parrallelism | `parrallelism.s` | 40 | ILP demonstration, parallel execution |
| 7 | ReUsingRegisters | `reg_reuse.s` | 100 | RAT stress test with alternating writes |
| 8 | logicalops | `logical.s` | 100 | Bitwise OR/AND/XOR operations |
| 9 | shifts | `sup_shifts.s` | 128 | Shift operations with RAW dependencies |
| 10 | complexshifts | `complexshifts.s` | 44 | Immediate + register shifts |

---

### New Load Tests (11-17)

#### Test 11: Basic Word Load (`loadword.s`)

```asm
main:
    lw a0, 0(x0)
```

**Purpose:** Verifies basic `lw` instruction functionality.

**Execution:**
- Loads 4 bytes from address 0: `01 02 03 04`
- Little-endian assembly: `0x04030201`

**Expected:** `a0 = 67305985` (0x04030201)

---

#### Test 12: Load with RAW Dependency (`multidependency.s`)

```asm
main:
    lw   a2, 0(x0)        # a2 = 0x04030201
    lw   a1, 4(x0)        # a1 = 0x08070605
    add  a0, a2, a1       # a0 = a2 + a1
```

**Purpose:** Tests RAW dependencies between load instructions and subsequent ALU operations. The `add` must wait for both loads to complete via CDB wakeup.

**Execution:**
- `a2 = MEM[0] = 0x04030201`
- `a1 = MEM[4] = 0x08070605`
- `a0 = 0x04030201 + 0x08070605 = 0x0C0A0806`

**Expected:** `a0 = 201984006` (0x0C0A0806)

---

#### Test 13: Load WAW Hazard (`loadwaw.s`)

```asm
main:
    lw   a0, 0(x0)        # older: a0 = 0x04030201
    lw   a0, 4(x0)        # younger: a0 = 0x08070605
    addi a0, a0, 1        # a0 = 0x08070606
```

**Purpose:** Verifies WAW hazard handling with load instructions. The younger load to `a0` must overwrite the older load's result, and the `addi` must use the correct (younger) value.

**Execution:**
- First `lw` writes `0x04030201` to `a0` (stale)
- Second `lw` writes `0x08070605` to `a0` (this value persists)
- `addi` uses `0x08070605 + 1 = 0x08070606`

**Expected:** `a0 = 134678022` (0x08070606)

---

#### Test 14: Independent Load Chains (`independentchains.s`)

```asm
main:
    lw   a3, 0(x0)        # chain 1: load
    addi a1, a3, 1        # chain 1: depends on a3

    lw   a2, 8(x0)        # chain 2: load
    addi a0, a2, 2        # chain 2: depends on a2
```

**Purpose:** Tests the processor's ability to identify and execute two independent chains in parallel.

**Execution:**
- Chain 1: `a3 = 0x04030201`, `a1 = 0x04030202`
- Chain 2: `a2 = 0x0C0B0A09`, `a0 = 0x0C0B0A0B`

**Expected:** `a0 = 202050059` (0x0C0B0A0B)

---

#### Test 15: Signed vs Unsigned Byte Load (`loadbytes.s`)

```asm
main:
    addi a3, x0, 127      # a3 = 127
    lb   a2, 0(a3)        # a2 = sign-extended 0x80 → 0xFFFFFF80
    lbu  a1, 0(a3)        # a1 = zero-extended 0x80 → 0x00000080
    add  a0, a2, a1       # a0 = 0xFFFFFF80 + 0x00000080 = 0x00000000
```

**Purpose:** Verifies correct sign-extension (`lb`) vs unsigned-extension (`lbu`) for byte loads. Address 127 contains `0x80`, which has its MSB set, making it ideal for testing sign behavior.

**Expected:** `a0 = 0`

---

#### Test 16: Signed vs Unsigned Halfword Load (`loadhalf.s`)

```asm
main:
    lh   a2, 0(x0)        # a2 = sign-extended 0x0201 → 0x00000201
    lhu  a1, 0(x0)        # a1 = zero-extended 0x0201 → 0x00000201
    add  a0, a2, a1       # a0 = 0x00000402
```

**Purpose:** Verifies `lh` and `lhu` instructions. Since `0x0201` is positive (MSB=0), both produce the same result.

**Expected:** `a0 = 1026` (0x0402)

---

#### Test 17: Mixed Load Operations (`mixedloads.s`)

```asm
main:
    lw   a7, 0(x0)        # a7 = 0x04030201

    lb   a1, 1(x0)        # a1 = sign-ext 0x02 → 0x00000002
    lbu  a2, 127(x0)      # a2 = zero-ext 0x80 → 0x00000080
    lb   a3, 127(x0)      # a3 = sign-ext 0x80 → 0xFFFFFF80

    lh   a4, 0(x0)        # a4 = sign-ext 0x0201 → 0x00000201
    lhu  a5, 126(x0)      # a5 = zero-ext 0x807F → 0x0000807F
    lh   a6, 126(x0)      # a6 = sign-ext 0x807F → 0xFFFF807F

    add  a0, a1, a2       # a0 = 0x02 + 0x80 = 0x82
```

**Purpose:** test combining `lw`, `lb`, `lbu`, `lh`, and `lhu` with various addresses. Tests multiple in-flight loads and verifies the scheduler correctly handles all load types.

**Execution:**
- 7 different loads to various registers
- Final computation: `a0 = 0x02 + 0x80 = 0x82 = 130`

**Expected:** `a0 = 130` (0x82)

---

### Test Results

1. Navigate to the testbench ( `tb` ) folder:
   ```bash
   cd repo/tb
   ```

2. Make script executable:
   ```bash
   chmod +x doit.sh
   chmod +x assemble.sh
   ```

3. Run the test:
   ```bash
   ./doit.sh tests/verify_tb.cpp
   ```
   Execute the testbench with the verification file to validate the program.

Here are the results:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/ooofverify.jpg)

---
