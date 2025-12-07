# Branch Prediction

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
  - [2.1 Branch Predictor](#21-branch-predictor)
  - [2.2 PCSrcF Assertion](#22-pcsrcf-assertion)
  - [2.3 Overall Integration](#23-overall-integration)
- [3. Schematic](#3-schematic)
- [4. Testing & Verification](#4-testing--verification)
  - [4.1 Branch Predictor Testing](#41-branch-predictor-testing)
  - [4.2 Full Circuit Testing](#42-full-circuit-testing)

---

## 1. Overview

In our pipelined processor, instructions are fetched sequentially assuming `PC + 4`. Branch decisions are only resolved in the Execute stage, meaning incorrect instructions may already be in the pipeline. This causes **control hazards** requiring flushes, which waste cycles.
The baseline approach predicts all branches as **not taken**, but this performs poorly for loops where backward branches are typically taken repeatedly.

#### Our Solution: Two-Bit Dynamic Prediction

- A **one-bit predictor** remembers only the last outcome
- Problem: it **mispredicts twice per loop** (first and last iteration)

- A **two-bit predictor** requires two consecutive mispredictions before changing its prediction
- Four states: *Strongly Taken → Weakly Taken → Weakly Not Taken → Strongly Not Taken*
- Result: **mispredicts only once per loop** instead of twice

#### Branch Target Buffer (BTB)

We maintain a table indexed by the branch PC containing:
- The **2-bit prediction state**
- The **target address** for fast redirection when predicting "taken"

![diagram](branchp.png)

Finite State Machine diagram taken from Harris and Harris book

**Integration**: Integrating the branch predictor into the pipeline is also challenging because both the Fetch stage (making predictions) and the Execute stage (resolving actual outcomes) compete to update the Program Counter, so we had to implement synchronization between these 2 stages.

---

## 2. Implementation

### 2.1 Branch Predictor

The branch predictor uses a **2-bit counter** for each entry, implementing a four-state finite state machine (FSM) that tracks branch history.

#### Parameters

```systemverilog
parameter TARGET_BUFFER_SIZE = 64,
parameter INDEX_BITS = $clog2(TARGET_BUFFER_SIZE)  // 6 bits
```

- **`TARGET_BUFFER_SIZE`**: Number of branch entries stored (kept small for fast access)
- **`INDEX_BITS`**: Bits extracted from PC to index the table (bits `[7:2]`, skipping the 2 LSBs since instructions are word-aligned)

#### State Encoding

```systemverilog
typedef enum logic [1:0] {
    STRONGLY_NOT_TAKEN = 2'b00,
    WEAKLY_NOT_TAKEN   = 2'b01,
    WEAKLY_TAKEN       = 2'b10,
    STRONGLY_TAKEN     = 2'b11
} my_state;
```

The states are intentionally encoded so that the **MSB indicates the prediction**:
- `0x` → Predict **not taken**
- `1x` → Predict **taken**

#### Storage

```systemverilog
my_state array [TARGET_BUFFER_SIZE-1:0];      // Current state
my_state next_array [TARGET_BUFFER_SIZE-1:0]; // Next state
```

Two arrays hold the current and next states for all 64 entries.

#### Initialization (Reset)

```systemverilog
if (rst) begin
    for (int i = 0; i < TARGET_BUFFER_SIZE; i++)
        array[i] <= WEAKLY_NOT_TAKEN;
end
```

On reset, all entries initialize to **`WEAKLY_NOT_TAKEN`**, a neutral starting point since we have no prior branch history.
We could have also picked **`WEAKLY_TAKEN`** .
However, we intentionally don't pick **`STRONGLY_TAKEN`** or **`STRONGLY_NOT_TAKEN`** because these extreme states would bias the predictor before any branch history is available.

#### State Transitions (Update Logic)

When `enable` is asserted (i.e., a branch instruction reaches the Execute stage), the FSM updates based on the **actual outcome**:

```systemverilog
case (array[update_index])
    STRONGLY_NOT_TAKEN: next = actual_taken ? WEAKLY_NOT_TAKEN : STRONGLY_NOT_TAKEN;
    WEAKLY_NOT_TAKEN:   next = actual_taken ? WEAKLY_TAKEN     : STRONGLY_NOT_TAKEN;
    WEAKLY_TAKEN:       next = actual_taken ? STRONGLY_TAKEN   : WEAKLY_NOT_TAKEN;
    STRONGLY_TAKEN:     next = actual_taken ? STRONGLY_TAKEN   : WEAKLY_TAKEN;
endcase
```

| Current State | Branch Taken | Next State |
|---------------|--------------|------------|
| `STRONGLY_NOT_TAKEN` | No | `STRONGLY_NOT_TAKEN` |
| `STRONGLY_NOT_TAKEN` | Yes | `WEAKLY_NOT_TAKEN` |
| `WEAKLY_NOT_TAKEN` | No | `STRONGLY_NOT_TAKEN` |
| `WEAKLY_NOT_TAKEN` | Yes | `WEAKLY_TAKEN` |
| `WEAKLY_TAKEN` | No | `WEAKLY_NOT_TAKEN` |
| `WEAKLY_TAKEN` | Yes | `STRONGLY_TAKEN` |
| `STRONGLY_TAKEN` | No | `WEAKLY_TAKEN` |
| `STRONGLY_TAKEN` | Yes | `STRONGLY_TAKEN` |

This implements a **saturating counter**: the state moves toward "strongly taken" when branches are taken, and toward "strongly not taken" when they aren't — but never wraps around.

#### Prediction Output (Moore Machine)

```systemverilog
pred_taken = array[predict_index][1];
```

The prediction is simply the **MSB of the current state**:
- `STRONGLY_NOT_TAKEN (00)` → bit[1] = `0` → predict **not taken**
- `WEAKLY_NOT_TAKEN (01)` → bit[1] = `0` → predict **not taken**
- `WEAKLY_TAKEN (10)` → bit[1] = `1` → predict **taken**
- `STRONGLY_TAKEN (11)` → bit[1] = `1` → predict **taken**

This is a **Moore machine** — the output depends only on the current state, not the inputs.

#### Timing: Why Negative Edge?

```systemverilog
always_ff @(negedge clk)
```

The state update occurs on the **falling edge** of the clock. This ensures that:
1. The prediction is read during the **first half** of the cycle (Fetch stage)
2. The state update from Execute happens during the **second half**, avoiding read-write conflicts

#### Interface Summary

| Signal | Direction | Description |
|--------|-----------|-------------|
| `predict_index` | Input | PC bits `[7:2]` from Fetch stage |
| `pred_taken` | Output | Prediction for Fetch stage |
| `update_index` | Input | PC bits `[7:2]` from Execute stage |
| `actual_taken` | Input | Real branch outcome from Execute |
| `enable` | Input | Asserted when Execute has a branch instruction |
---

### 2.2 PCSrcF Assertion

<!-- TODO: PCSrcF assertion module explanation -->

---

### 2.3 Overall Integration

<!-- TODO: How components connect together -->

---

## 3. Schematic

<!-- TODO: Circuit diagram -->

---

## 4. Testing & Verification

### 4.1 Branch Predictor Testing

<!-- TODO: Branch predictor unit tests -->

---

### 4.2 Full Circuit Testing

<!-- TODO: Integration tests with assembly programs -->

---

