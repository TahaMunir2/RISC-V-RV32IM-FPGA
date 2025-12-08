# Out-of-Order Superscalar Processor with Load Instructions

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
  - [2.1 Adapting Data Memory for Superscalar](#21-adapting-data-memory-for-superscalar)
  - [2.2 Doubling the Common Data Bus Width](#22-doubling-the-common-data-bus-width)
    - [2.2.1 ROB Writeback Expansion](#221-rob-writeback-expansion)
    - [2.2.2 RUU Writeback Expansion](#222-ruu-writeback-expansion)
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
- **Add memory stage**: After address calculation, loads access data memory in a subsequent stage
- **Double CDB width**: The ROB and RUU now accept 4 writeback inputs (2 from ALUs, 2 from memory) instead of 2

The following sections detail each modification. For understanding the base Tomasulo implementation, refer to the previous branch documentation.

---

## 2. Implementation

### 2.1 Adapting Data Memory for Superscalar


---

### 2.2 Doubling the Common Data Bus Width


#### 2.2.1 ROB Writeback Expansion


---

#### 2.2.2 RUU Writeback Expansion


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
