# M-type Instructions

**Table of Contents**

* [1. Scope](#1-scope)
* [2. ALU changes](#2-alu-changes)
    * [2.1 ALUCtrl widened](#21-aluctrl-widened)
    * [2.2 Multiplication implementation](#22-multiplication-implementation)
    * [2.3 Division and remainder with edge cases](#23-division-and-remainder-with-edge-cases)
* [3. Control-Path Changes for M Instructions](#3-control-path-changes-for-m-instructions)
    * [3.1 Wider ALUCtrl output](#31-wider-aluctrl-output)
    * [3.2 Decoding M operations under OPC_OP](#32-decoding-m-operations-under-opc_op)
* [4. Interaction with the Existing Pipeline and Hazards](#4-interaction-with-the-existing-pipeline-and-hazards)
* [5. Summary](#5-summary)
* [5. ALU test cases (selected) — exact format](#5-alu-test-cases-selected--exact-format)
    * [5.1.11 ALU Test: DIVU (Unsigned Division by Zero)](#5111-alu-test-divu-unsigned-division-by-zero)
    * [5.1.12 ALU Test: REM (Remainder with Divisor Zero)](#5112-alu-test-rem-remainder-with-divisor-zero)
    * [5.1.13 ALU Test: REMU (Unsigned Remainder with Divisor Zero)](#5113-alu-test-remu-unsigned-remainder-with-divisor-zero)
* [6. Trade-offs & notes](#6-trade-offs--notes)

---

This document describes how the RV32M integer multiply/divide extension was integrated into our RV32I core. It focuses only on the added functionality and the changes made to the ALU and control modules. Everything else in the CPU (pipeline, hazard unit, register file, memories, etc.) is unchanged.

---

## 1. Scope

We implemented the full RV32M base extension (eight instructions):

- **MUL** — low 32 bits of signed×signed product
- **MULH** — high 32 bits of signed×signed product
- **MULHSU** — high 32 bits of signed×unsigned product
- **MULHU** — high 32 bits of unsigned×unsigned product
- **DIV** — signed quotient with RISC‑V special cases:
  - divisor == 0 → `q = -1` (`0xFFFFFFFF`)
  - overflow `-2^31 / -1` → `q = -2^31` (`0x80000000`)
- **DIVU** — unsigned quotient:
  - divisor == 0 → `q = 0xFFFFFFFF`
- **REM** — signed remainder:
  - divisor == 0 → `r = rs1`
  - overflow case `-2^31 / -1` → `r = 0`
  - remainder has sign of dividend
- **REMU** — unsigned remainder:
  - divisor == 0 → `r = rs1`

Encoding: standard R-type (`opcode = OP (0110011)`), `funct7 = 7'b0000001` indicates M-extension, `funct3` selects the specific M op.

From the perspective of the internal logic of the CPU, M instructions behave like ordinary R-type ALU ops:
- Read `rs1` and `rs2` from the register file
- Produce a 32-bit result and write to `rd` in WB
- `RegWrite = 1`, `ALUSrc = 0`, `ResultSrc = ALU`
- Forwarding and hazard logic is identical to other R-type ops.

---

## 2. ALU changes

### 2.1 ALUCtrl widened
- `ALUCtrl` was widened from 4 bits to **5 bits** to accomodate for the 8 new M instructions.
- Here are the encodings in the new mapping:

  - `5'b01100` — MUL  (low 32 bits)
  - `5'b01101` — MULH (high 32 bits signed×signed)
  - `5'b01110` — MULHU(high 32 bits unsigned×unsigned)
  - `5'b01111` — MULHSU(high 32 bits signed×unsigned)
  - `5'b10000` — DIV  (signed)
  - `5'b10001` — DIVU (unsigned)
  - `5'b10010` — REM  (signed remainder)
  - `5'b10011` — REMU (unsigned remainder)

All previous RV32I ALU codes remain unchanged in the lower range. The new encodings were chosen to be contiguous, incrementing ALUCtrl for every new encoding.

### 2.2 Multiplication implementation

The RV32M multiplication instructions (`MUL`, `MULH`, `MULHSU`, `MULHU`) are all implemented inside the main ALU as purely combinational operations that produce a full 64-bit product and then select either the low or high 32 bits, with the correct signed/unsigned interpretation of the operands.

Approaches that would be possible to implement with fewer lines of code do exist, but the objective with the implementation here was to make the code more efficient for synthesis (even though we did not intend to include M instructions in the design that we put on our FPGA). In the code shown below, based on the ALUCtrl signal, which uniuely identifies the type of ALU instruction being executed, we select whether we want the signed or unsigned representation of each operand:

```Systemverilog
logic [63:0] ALUop1_ext;
logic [63:0] ALUop2_ext;
logic [63:0] product;

always_comb begin
    // default: something sensible
    ALUop1_ext = $unsigned(ALUop1);
    ALUop2_ext = $unsigned(ALUop2);

    unique case (ALUCtrl)
        5'b1100: begin // MUL: unsigned×unsigned low word
            ALUop1_ext = $unsigned(ALUop1);
			ALUop2_ext = $unsigned(ALUop2);
        end
        5'b1101: begin // MULH: signed×signed high word
            ALUop1_ext = $signed(ALUop1);
        ALUop2_ext = $signed(ALUop2);
        end
        5'b1110: begin // MULHSU: signed×unsigned high word
            ALUop1_ext = $signed(ALUop1);
			ALUop2_ext = $unsigned(ALUop2);
        end
        5'b1111: begin // MULHU: unsigned×unsigned high word
            ALUop1_ext = $unsigned(ALUop1);
			ALUop2_ext = $unsigned(ALUop2);
        end
        default: begin
            // non-M ops: a_sel/b_sel values don't matter
        end
    endcase
end

assign product = ALUop1_ext * ALUop2_ext;
```
The reason why we extend each operand to 64 bits even before the multiplication is that, in SystemVerilog, the width of a * b is the max of the operand widths. If the current 32-bit format of ALUop1 and ALUop2 were used, the raw product would also 32 bits. That 32-bit product would then extended to 64 bits when assigned to signed_unsigned_mult, but the upper 32 bits of the result of the multiplication would already have been lost. Therefore, we simply increase the number of bits of our operands to 64 and use ```Systemverilog $signed ``` and ```Systemverilog $unsigned ```, which already take care of the sign extension.

The only task that now remains is to select the upper or lower 32-bits of the product, which is then as such:
```Systemverilog
case (ALUCtrl)
...
5'b1100: ALUout = product[31:0]; //MUL
        5'b1101: ALUout = product[63:32]; //MULH
        5'b1110: ALUout = product[63:32]; //MULHSU
        5'b1111: ALUout = product[63:32]; //MULHU
...
default: ALUout = 32'b0;
endcase
```
### 2.3. Division and remainder with edge cases
The four division/remainder operations share the existing 32-bit ALUout result and are coded as:
•	DIV (ALUCtrl = 5'b10000)
•	DIVU (ALUCtrl = 5'b10001)
•	REM (ALUCtrl = 5'b10010)
•	REMU (ALUCtrl = 5'b10011)

```Systemverilog
        5'b10000: begin //DIV
            if (ALUop2 == 0) begin
                ALUout = -1;
            end
            else if (ALUop1 == 32'h80000000 && ALUop2 == 32'hFFFFFFFF) begin
                ALUout = 32'h80000000;
            end
            else begin
                ALUout = $signed(ALUop1)/$signed(ALUop2);
            end
        end
        5'b10001: begin //DIVU
            if (ALUop2 == 0) begin
                ALUout = -1;
            end
            else begin
                ALUout = $unsigned(ALUop1)/$unsigned(ALUop2);
            end
        end
        5'b10010: begin //REM
            if (ALUop2 == 0) begin
                ALUout = ALUop1;
            end
            else if (ALUop1 == 32'h80000000 && ALUop2 == 32'hFFFFFFFF) begin
                ALUout = 32'h00000000;
            end
            else begin
                ALUout = $signed(ALUop1) % $signed(ALUop2);
            end
        end
        5'b10011: begin //REMU
            if (ALUop2 == 0) begin
                ALUout = ALUop1;
            end
            else begin
                ALUout = $unsigned(ALUop1) % $unsigned(ALUop2);
            end
        end
```
		
They follow the RISC-V spec’s special cases:
1.	Division by zero
DIV / DIVU: result is −1 (all ones), i.e. 0xFFFFFFFF.
REM / REMU: result is the original dividend (rs1).
2.	Signed overflow (−2³¹ / −1):
- For DIV, when ALUop1 == 0x80000000 and ALUop2 == 0xFFFFFFFF:
The result saturates to 0x80000000 (unchanged dividend).
- For REM in this special case, the remainder is 0.
Again, this is a purely combinational, single-cycle implementation. In a real design you would normally use a multi-cycle divider for timing reasons, but for this coursework the emphasis is correctness and simplicity.


## 3. Control Path Changes for M Instructions

To support RV32M, the control unit (`control.sv`) was extended in two ways:

1. ALUCtrl width increased from 4 bits to 5 bits.  
2. Additional decoding for `opcode == OPC_OP` and `funct7 == 7'b0000001`.

#### 3.1 Wider ALUCtrl output

The module header was updated to:

```systemverilog
output logic [4:0] ALUCtrl;
```

All existing RV32I cases were adjusted to drive 5‑bit codes (e.g. `5'b00000` for ADD, `5'b00001` for SUB, etc.). No other control outputs required structural changes — M ops are treated as ordinary R‑type ALU instructions from the pipeline perspective.

#### 3.2 Decoding M operations under OPC_OP

M ops share the R‑type opcode `7'b0110011`. The control logic detects M‑extension via:

- `funct7 == 7'b0000001` → M‑extension present  
- `funct3` selects the specific M operation

Simplified decode sketch:

```systemverilog
OPC_OP: begin
    // funct3 == 3'b000 : ADD / SUB / MUL
    if (funct3 == 3'b000) begin
        if (funct7 == 7'b0000001) begin
            // MUL
            RegWrite = 1;
            ALUCtrl  = 5'b01100;
        end else begin
            // ADD / SUB normal decoding...
        end
    end

    // funct3 == 3'b100 : XOR / DIV
    else if (funct3 == 3'b100) begin
        if (funct7 == 7'b0000001) begin
            // DIV
            RegWrite = 1;
            ALUCtrl  = 5'b10000;
        end else begin
            // XOR normal decoding...
        end
    end

    // ...similar branches for MULH, MULHSU, MULHU, DIVU, REM, REMU
end
```

For every M case, control signals (other than `ALUCtrl`) are set to match a normal R‑type ALU op:

- `RegWrite = 1` — write result to `rd`  
- `ALUSrc = 0` — both operands from registers (`rs1`, `rs2`)  
- `ResultSrc = 2'b00` — select ALU result for WB  
- `MemWrite = 0` — no data-memory access  
- `Jump = 0`, `Branch = 0` — no control transfer  
- `ALUsrc2 = 0` — first ALU operand is `rs1` (not `pc_save`)

No special handling is required elsewhere (hazard unit, register file, pipeline control).

---

### 4. Interaction with the Existing Pipeline and Hazards

- M instructions are ordinary R‑type ALU instructions with a more complex datapath.  
- They pass through IF/ID → ID/EX → EX/MEM → MEM/WB exactly like ADD/SUB.  
- Forwarding and stall logic remain unchanged:
  - Hazard unit inspects register numbers and `RegWrite` / `ResultSrc` only.
  - It does not need to know whether EX does ADD or MUL.  
- Write‑back still selects ALU result / memory data / PC+4 based on `ResultSrc`.

Timing caveat: combinational multiplier/divider are likely the `EX` critical path. Typical mitigation for this are:

- Multi‑cycle or pipelined multiply/divide unit  
- Run core at lower clock frequency  
- Use a long‑latency functional unit with reservation stations

For this coursework, some modifications were indeed made to accomodate synthesis, but the design remains single‑cycle for the execution of M instructions. As such, M instructions were still omitted from the FPGA‑synthesized configuration.

---

### 5. Summary

Adding RV32M required three main changes:

1. Extend ALU control space to 5 bits (`ALUCtrl`) and add unique encodings for the eight M ops.  
2. Add multiplier/divider datapaths in the ALU:
   - 64‑bit products for each signedness combination, sliced per MUL* semantics.
   - Signed/unsigned division and remainder with RISC‑V corner cases (divide‑by‑zero, `-2^31 / -1`).
3. Extend control decode for `opcode == OPC_OP` and `funct7 == 7'b0000001`, mapping `(funct3, funct7)` → `ALUCtrl` while leaving all R‑type control signals unchanged.

Everything else in the CPU (pipeline registers, hazard unit, branch logic, memories) is unchanged — they see M instructions as standard R‑type ALU ops that take longer to compute.


## 5. ALU test cases (selected) — exact format

### 5.1.11 ALU Test: DIVU (Unsigned Division by Zero)

Purpose  
Checks divide-by-zero behaviour for unsigned division.

Test Case (ALUTest13)
```
ALUCtrl = DIVU (5'b10001)

ALUop1 = 0x00000010

ALUop2 = 0x00000000

Expected ALUout = 0xFFFFFFFF
```
What It Tests

- Unsigned divide-by-zero semantics (quotient = all 1s)  
- Distinction between signed and unsigned division rules

---

### 5.1.12 ALU Test: REM (Remainder with Divisor Zero)

Purpose  
Verifies that for signed remainder the dividend is returned when the divisor is zero.

Test Case (ALUTest14)
```
ALUCtrl = REM

ALUop1 = 0x00000010 (16)

ALUop2 = 0x00000000 (0)

Expected ALUout = 0x00000010
```
What It Tests

- RISC-V rule: when divisor is zero, remainder = dividend (signed)  
- Difference between quotient and remainder behaviour in corner cases

---

### 5.1.13 ALU Test: REMU (Unsigned Remainder with Divisor Zero)

Purpose  
Confirms that in the unsigned case, the remainder also returns the dividend on divide-by-zero.

Test Case (ALUTest15)
```
ALUCtrl = REMU

ALUop1 = 0x00000010

ALUop2 = 0x00000000

Expected ALUout = 0x00000010
```
What It Tests

- Unsigned remainder semantics on divide-by-zero  
- Consistency with the signed REM rule for this case

---

### 6 Trade-offs & notes
- Simplicity vs. timing: combinational implementation is easy to verify but slow. Alternatives for synthesis: multi-cycle or pipelined multiply/divide units, or a long‑latency functional unit.
- Only two modules changed: `alu.sv` (wider `ALUCtrl`, M logic) and `control.sv` (wider `ALUCtrl` output, M decoding). No structural changes to pipeline or hazards.

Summary
- RV32M support implemented in ALU + control with unique 5‑bit `ALUCtrl` encodings for all eight M instructions.
- Behaviour matches the RISC‑V spec, including all specified corner cases.
- M instructions forward and write back like other R-type ALU operations; integration is modular and local to ALU/control.
