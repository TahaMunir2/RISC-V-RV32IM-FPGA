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

##### Comparing performance between a 1-bit and a 2-bit branch predictor

Consider a simple loop that iterates 100 times:

**One-bit predictor** (remembers only the last outcome):
- First iteration: Predicted not taken → Actually taken → **Misprediction #1**
- Iterations 2–99: Predicted taken → Actually taken → Correct
- Last iteration: Predicted taken → Actually not taken → **Misprediction #2**
- **Result: 2 mispredictions per loop**

**Two-bit predictor** (requires two consecutive mispredictions to flip):
- First iteration: Starts at `WEAKLY_NOT_TAKEN`, predicted not taken → Actually taken → **Misprediction #1**, moves to `WEAKLY_TAKEN`
- Second iteration: Now predicting taken → Actually taken → Correct, moves to `STRONGLY_TAKEN`
- Iterations 3–99: Predicted taken → Actually taken → Correct, stays at `STRONGLY_TAKEN`
- Last iteration: Predicted taken → Actually not taken → **Misprediction #2**, moves to `WEAKLY_TAKEN`
- **Next loop entry**: Still predicting taken → Actually taken → **Correct** (unlike one-bit!)
- **Result: 1 misprediction per loop** (only the exit)

The key insight is that after exiting a loop, the two-bit predictor stays in `WEAKLY_TAKEN` rather than flipping to "not taken". This means when the loop is re-entered, it still predicts correctly.

#### Branch Target Buffer (BTB)

We maintain a table indexed by the branch PC containing:
- The **2-bit prediction state**
- The **target address** for fast redirection when predicting "taken"

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/branchp.png)

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

This implements a **saturating counter**: the state moves toward "strongly taken" when branches are taken, and toward "strongly not taken" when they aren't, but never wraps around.

#### Prediction Output (Moore Machine)

```systemverilog
pred_taken = array[predict_index][1];
```

The prediction is simply the **MSB of the current state**:
- `STRONGLY_NOT_TAKEN (00)` → bit[1] = `0` → predict **not taken**
- `WEAKLY_NOT_TAKEN (01)` → bit[1] = `0` → predict **not taken**
- `WEAKLY_TAKEN (10)` → bit[1] = `1` → predict **taken**
- `STRONGLY_TAKEN (11)` → bit[1] = `1` → predict **taken**

This is a **Moore machine** : the output depends only on the current state, not the inputs.

#### Timing: We update at the Negative Edge?

```systemverilog
always_ff @(negedge clk)
```

The state update occurs on the **falling edge** of the clock. This ensures that:
1. The prediction is read during the **first half** of the cycle (Fetch stage)
2. The state update from Execute happens during the **second half**, avoiding read-write conflicts


### 2.2 PCSrcF Assertion

The `PCSrcF_assertion` module resolves conflicts between the Fetch and Execute stages when determining the next Program Counter. It decides whether to follow a prediction, correct a misprediction, or proceed sequentially.

#### The Challenge

Two stages compete to control the PC:
- **Fetch stage**: Makes speculative predictions for newly fetched branch instructions
- **Execute stage**: Resolves actual branch outcomes and may need to correct mispredictions

This module arbitrates between them and selects the appropriate next PC.

#### Outputs

| PCSrcF | Next PC Source | Condition |
|--------|----------------|-----------|
| `2'b00` | `PC + 4` (Fetch) | Sequential execution (no branch or prediction = not taken) |
| `2'b01` | `FinalTarget` | Branch predicted/confirmed taken, or jump |
| `2'b11` | `PCPlus4E` (Execute) | Misprediction recovery: predicted taken but actually not taken |

> **Note**: `2'b00` and `2'b11` both select a `PC + 4` value, but from **different stages**. When recovering from a "predicted taken, actually not taken" misprediction, we must return to the `PC + 4` of the mispredicted branch, which has propagated to the Execute stage as `PCPlus4E`. This distinction is handled in the `pc_block` module (see [Overall Integration](#23-overall-integration)).

#### Branch Detection in Fetch

```systemverilog
logic BranchF;
assign BranchF = (opcodeF == 7'b1100011);
```

We check if the fetched instruction is a branch by examining its opcode (`1100011` = B-type).

#### Priority Logic

The module uses a priority-based tree in order to implement synchronization between the 2 stages (2 different instructions are communicating with this block at the same time):

##### Priority 1: Jump Instructions (Highest)

```systemverilog
if (JumpE) begin
    PCSrcF = PCSrcE;
    FinalTarget = targetE;
end
```

Jump instructions (`JAL`/`JALR`) in Execute take precedence. We use the resolved `PCSrcE` and actual target from Execute.

##### Priority 2: Misprediction Recovery

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

When Execute detects a misprediction, we must correct the PC:

| Prediction | Actual | Recovery Action |
|------------|--------|-----------------|
| Taken | Not Taken | `PCSrcF = 2'b11` → Resume at `PC + 4` (we went down the wrong path) |
| Not Taken | Taken | `PCSrcF = 2'b01` → Jump to `targetE` (we should have branched) |

##### Priority 3: New Branch Prediction (Lowest)

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

If no Execute-stage corrections are needed and Fetch contains a branch:
- **Prediction = Taken**: Speculatively jump to `targetF`
- **Prediction = Not Taken**: Continue with `PC + 4`

#### Default Behavior

```systemverilog
PCSrcF = 2'b00;
FinalTarget = targetE;
```

By default, we proceed sequentially (`PC + 4`). The `FinalTarget` default doesn't matter since it's only used when `PCSrcF = 2'b01`.

##### Target Address Computation

```systemverilog
PCSrcF_assertion PCSourceF(
    // ...
    .targetF(PCF + {{20{InstrF[31]}}, InstrF[7], InstrF[30:25], InstrF[11:8], 1'b0}),
    .targetE(PCE + ExtImmE),
    .FinalTarget(target),
    // ...
);
```

Two targets are computed:
- **`targetF`**: Speculative target from Fetch (B-type immediate extracted directly from `InstrF`)
- **`targetE`**: Actual target from Execute (`PCE + ExtImmE`)

The `PCSrcF_assertion` module selects which one to use as `FinalTarget`.


### 2.3 Overall Integration

This section describes how the branch predictor, PC source assertion, and PC block are wired together. All connections described here are illustrated in the schematic below.

#### Modified PC Block

The `pc_block` module was extended to handle four PC sources instead of three:

```systemverilog
case (pc_src)
    2'b00: internal_pc <= inc_pc;     // PC + 4 (sequential)
    2'b01: internal_pc <= branch_pc;  // Branch target (Imm_op)
    2'b10: internal_pc <= ALU;        // JALR (register-based jump)
    2'b11: internal_pc <= pc_saved;   // Misprediction recovery
    default: internal_pc <= inc_pc;  
endcase
```

| PCSrcF | Source | Signal | Use Case |
|--------|--------|--------|----------|
| `2'b00` | `inc_pc` | `PC + 4` | Sequential execution or prediction = not taken |
| `2'b01` | `branch_pc` | `Imm_op` (target) | Branch/jump target (predicted or confirmed taken) |
| `2'b10` | `ALU` | `ALUResultE` | `JALR` instruction |
| `2'b11` | `pc_saved` | `PCPlus4E` | Recovery from "predicted taken, actually not taken" |

#### Difference between `pc_saved` and `inc_pc` (`pc_saved` is different from `pc_save` in our previous designs) 

Both represent a `PC + 4` value, but from **different instructions**:

- **`inc_pc`** = Current `PCF + 4` (next sequential address from Fetch)
- **`pc_saved`** = `PCPlus4E` (the `PC + 4` of the branch instruction now in Execute)

When we mispredicted "taken", we speculatively jumped to the target. To recover, we need the sequential address of the **mispredicted branch**, not the current Fetch PC.


#### Integration in Top Module

##### 1. Branch Predictor Connections

```systemverilog
branchpredictor2bit branchpredictor (
    .clk(clk),
    .rst(rst),
    .enable(BranchE),           // Update only when Execute has a branch
    .update_index(PCE[7:2]),    // Index from Execute stage PC
    .actual_taken(actual_taken),// Real outcome from PCSrcE
    .predict_index(PCF[7:2]),   // Index from Fetch stage PC
    .pred_taken(pred_takenF)    // Prediction output for Fetch
);
```

- **Prediction path**: `PCF[7:2]` : identifying the branch from the buffer and associating a prediction to it
- **Update path**: `PCE[7:2]` + `actual_taken` : updating the state of this specific entry in the buffer (we update only when `BranchE` is high : used as an enable signal to write to the buffer)

##### 2. Actual Outcome Derivation

```systemverilog
always_comb begin
    case (PCSrcE)
        2'b00:   actual_taken = 0;  // Branch not taken
        2'b01:   actual_taken = 1;  // Branch taken
        default: actual_taken = 0;  // Don't care (not a branch)
    endcase
end
```

The `PCSrcE` output from `PCSrcE_assertion` tells us the real branch outcome. We convert this to a single bit for the predictor update.

##### 3. Misprediction Detection (`evalprediction`)

This module compares what we **predicted** against what **actually happened** to determine if a flush is needed.
```systemverilog
module evalprediction(
    input logic [1:0] PCSrcE,      // Actual branch outcome
    input logic BranchE,           // Is this a branch instruction?
    input logic pred_taken,        // What we predicted in Fetch
    output logic false_prediction  // Misprediction flag
);
```

#### Logic

The module only evaluates predictions when `BranchE == 1` (a branch is in Execute):

```systemverilog
always_comb begin
    false_prediction = 0;  // Default: prediction was correct
    if (BranchE == 1) begin
        case (PCSrcE)
            2'b00: if (pred_taken)  false_prediction = 1;  // Predicted taken, actually not taken
            2'b01: if (!pred_taken) false_prediction = 1;  // Predicted not taken, actually taken
            default: false_prediction = 0;
        endcase
    end
end
```

- Defaulting to `0` prevents unnecessary pipeline flushes

#### Output Usage

The `false_prediction` signal feeds into:
1. **Hazard Unit**: Triggers `flush_f_d` and `flush_d_exec` to clear speculative instructions
2. **`PCSrcF_assertion`**: Overrides Fetch-stage decisions to correct the PC


##### 4. Prediction Propagation Through Pipeline

The prediction made in Fetch must travel with the instruction to Execute for comparison:
This ensures that when a branch reaches Execute, we still know what prediction was made for it.

##### 5. Hazard Unit Modifications

The hazard unit was modified to handle branch mispredictions. Previously, flushing occurred whenever a branch was taken (`PCSrcE != 0`). Now, we only flush on **mispredictions** or **jumps**:
```systemverilog
input logic JumpE,
input logic false_prediction  // Replaces PCSrcE for flush decisions
```

#### Flush Logic
```systemverilog
always_comb begin
    // Default: no stall, no flush
    PCWrite      = 1;
    F_Write      = 1;
    flush_d_exec = 0;
    flush_f_d    = 0;

    // Flush on misprediction or jump
    if (false_prediction || JumpE) begin
        flush_f_d    = 1;  // Flush Fetch-Decode register
        flush_d_exec = 1;  // Flush Decode-Execute register
    end

    // Stall on load-use hazard
    if (wStall == 1) begin
        PCWrite      = 0;
        F_Write      = 0;
        flush_d_exec = 1;
    end
end
```

#### Key Change: When to Flush

| Condition | Old Behavior | New Behavior |
|-----------|--------------|--------------|
| Branch taken, correctly predicted | Flush | **No flush** |
| Branch taken, mispredicted | Flush | Flush |
| Branch not taken, correctly predicted | No flush | No flush |
| Branch not taken, mispredicted | No flush | **Flush** |
| Jump (`JAL`/`JALR`) | Flush | Flush |

This reduces unnecessary flushes when the branch predictor guesses correctly, improving pipeline efficiency.

## 3. Schematic

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/branchpredictio.png)


---

## 4. Testing & Verification

### 4.1 Branch Predictor Testing

We created a c++ testbench ( `predictor_tb.cpp ` ) that isolates the branch predictor module and verifies the correct FSM transitions across all four states: STRONGLY_NOT_TAKEN, WEAKLY_NOT_TAKEN, WEAKLY_TAKEN, and STRONGLY_TAKEN.

**Tests performed:**
- **Initial State:** All entries initialize to WEAKLY_NOT_TAKEN after reset
- **State Transitions:** Correct transitions on taken/not-taken outcomes
- **Saturation:** Counter remains at STRONGLY_TAKEN or STRONGLY_NOT_TAKEN when saturated
- **Misprediction Tolerance:** Two consecutive mispredictions required to flip prediction

#### Running the code

1. Navigate to the testbench ( `tb` ) folder:
   ```bash
   cd repo/tb
   ```

2. Make scripts executable:
   ```bash
   chmod +x doitpredictor.sh
   ```
   Grant execution permissions to the assembly and run scripts.

3. Run the test:
   ```bash
   ./doitpredictor.sh tests/predictor_tb.cpp
   ```
   Execute the testbench with the verification file to validate the program.

Here are the results:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/bverifyingpredictor.jpg)

---

### 4.2 Full Circuit Testing

For examination, we will use the assembly program : `1_addi_bne`

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

This program runs an inner loop that counts a1 from 0 up to 255, continuously copying the current value of i into a0, so when the loop stops a0 holds 254 (the last value before the branch fails).

##### Correct Prediction (No Flush)

When the branch predictor correctly predicts the branch outcome, no pipeline flush occurs and execution continues without penalty.

Since the branch predictor's initial state is `WEAKLY_NOT_TAKEN`, it will start prediciting correctly at the second iteration of the loop. 

In the following waveform, we observe that the value of `PCF` ( PC at the fetch stage) decreases by 8 (jumps back by 2 to `iloop`) automaticaly when the branch instruction is fetched.

Thus, we avoid the penalty of waiting 2 extra cycles (until the branch instruction reaches the Execute stage) to jump back to the correct address. 

Note that:
- `0xFE659CE3` corresponds to the instruction : ` bne     a1, t1, iloop `
- `0x00058513` corresponds to the instruction : ` bne     a0, a1, 0 `


**Waveform:**

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/bverifyingcorrectpred.jpg)


##### Performance Comparison
Comparison of pipeline behavior with and without branch prediction, showing reduced flush cycles for predictable branch patterns.

**Without Branch Prediction:**


**With Branch Prediction:**



#### Running the code

1. Navigate to the testbench ( `tb` ) folder:
   ```bash
   cd repo/tb
   ```

2. Make scripts executable:
   ```bash
   chmod +x assemble.sh
   chmod +x doit.sh
   ```
   Grant execution permissions to the assembly and run scripts.

3. Run the test:
   ```bash
   ./doit.sh tests/verify.cpp
   ```
   Execute the testbench with the verification file to validate the program.

Here are the results:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/bverify.jpg)



---

