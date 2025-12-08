# RV32M (“M-type”) Instructions — Design & Implementation

This document describes how the RV32M integer multiply/divide extension was integrated into our RV32I core. It focuses only on the added functionality and the changes made to the ALU and control modules. Everything else in the CPU (pipeline, hazard unit, register file, memories, etc.) is unchanged.

---

## 1. Scope

We implemented the full RV32M base extension (eight instructions):

- **MUL** — low 32 bits of signed×signed product: `rd = (rs1 * rs2)[31:0]`
- **MULH** — high 32 bits of signed×signed product: `rd = (signed(rs1) * signed(rs2))[63:32]`
- **MULHSU** — high 32 bits of signed×unsigned product: `rd = (signed(rs1) * unsigned(rs2))[63:32]`
- **MULHU** — high 32 bits of unsigned×unsigned product: `rd = (unsigned(rs1) * unsigned(rs2))[63:32]`
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

From the pipeline perspective, M instructions behave like ordinary R-type ALU ops:
- Read `rs1` and `rs2` from the register file
- Produce a 32-bit result and write to `rd` in WB
- `RegWrite = 1`, `ALUSrc = 0`, `ResultSrc = ALU`
- Forwarding and hazard logic identical to other R-type ops

---

## 2. ALU changes

### 2.1 ALUCtrl widened
- `ALUCtrl` was widened from 4 bits to **5 bits** so M operations have distinct encodings and do not reuse existing codes.
- New mapping (examples — chosen contiguous codes to avoid conflicts):

  - `5'b01100` — MUL  (low 32 bits)
  - `5'b01101` — MULH (high 32 bits signed×signed)
  - `5'b01110` — MULHU(high 32 bits unsigned×unsigned)
  - `5'b01111` — MULHSU(high 32 bits signed×unsigned)
  - `5'b10000` — DIV  (signed)
  - `5'b10001` — DIVU (unsigned)
  - `5'b10010` — REM  (signed remainder)
  - `5'b10011` — REMU (unsigned remainder)

All previous RV32I ALU codes remain unchanged in the lower range.

### 2.2 Multiplication implementation
- ALU computes 64-bit intermediate products (combinational):

```systemverilog
logic [63:0] unsigned_mult;
logic [63:0] signed_mult;
logic [63:0] signed_unsigned_mult;

assign unsigned_mult        = $unsigned(ALUop1) * $unsigned(ALUop2);
assign signed_mult          = $signed(ALUop1)   * $signed(ALUop2);
assign signed_unsigned_mult = $signed(ALUop1)   * $unsigned(ALUop2);
```
Results are selected/sliced by `ALUCtrl` in the ALU. Example selections:

```systemverilog
// MUL family (examples)
5'b01100: ALUout = unsigned_mult[31:0];         // MUL   : low 32 bits
5'b01101: ALUout = signed_mult[63:32];         // MULH  : high 32 bits (signed×signed)
5'b01110: ALUout = unsigned_mult[63:32];       // MULHU : high 32 bits (unsigned×unsigned)
5'b01111: ALUout = signed_unsigned_mult[63:32];// MULHSU: high 32 bits (signed×unsigned)
```

Notes:
- For the low‑32 MUL case the low 32 bits of signed×signed and unsigned×unsigned products coincide for 32‑bit operands, so using `unsigned_mult[31:0]` is safe.
- The ALU computes 64‑bit intermediates combinationally; this is simple but increases EX-stage critical path.

Division / remainder (with RISC‑V corner cases):

```systemverilog
5'b10000: begin // DIV (signed)
    if (ALUop2 == 32'h0)                 ALUout = 32'hFFFFFFFF; // -1 per spec
    else if (ALUop1 == 32'h80000000 && ALUop2 == 32'hFFFFFFFF)
                                         ALUout = 32'h80000000; // overflow case
    else                                 ALUout = $signed(ALUop1) / $signed(ALUop2);
end

5'b10001: begin // DIVU (unsigned)
    if (ALUop2 == 32'h0)                 ALUout = 32'hFFFFFFFF;
    else                                 ALUout = $unsigned(ALUop1) / $unsigned(ALUop2);
end

5'b10010: begin // REM (signed)
    if (ALUop2 == 32'h0)                 ALUout = ALUop1; // remainder = dividend
    else if (ALUop1 == 32'h80000000 && ALUop2 == 32'hFFFFFFFF)
                                         ALUout = 32'h0; // special case
    else                                 ALUout = $signed(ALUop1) % $signed(ALUop2);
end

5'b10011: begin // REMU (unsigned)
    if (ALUop2 == 32'h0)                 ALUout = ALUop1;
    else                                 ALUout = $unsigned(ALUop1) % $unsigned(ALUop2);
end
```

Flag outputs
- `EQ`, `LT`, `LTU` are computed as before and are unchanged by M-type logic:
  - `EQ  = (ALUop1 == ALUop2)`
  - `LT  = ($signed(ALUop1) < $signed(ALUop2))`
  - `LTU = (ALUop1 < ALUop2)`

Control-path changes
- `ALUCtrl` widened in `control.sv`:
```systemverilog
output logic [4:0] ALUCtrl;
```
- Decode M-ops under `opcode = OPC_OP` when `funct7 == 7'b0000001`; `funct3` selects the specific M instruction. For all M cases the remaining control signals mirror a normal R-type ALU op:
  - `RegWrite = 1`, `ALUSrc = 0`, `ResultSrc = ALU`, `MemWrite = 0`, `Branch = 0`, `Jump = 0`.

Pipeline & hazard interaction
- M instructions are ordinary R-type ALU instructions from IF to WB.
- Forwarding and hazard/stall logic remain unchanged.
- Timing caveat: single-cycle combinational multiplier/divider may be the EX critical path; acceptable for simulation/coursework but not optimal for synthesis.

## 5. ALU test cases (selected) — exact format

### 5.1.11 ALU Test: DIVU (Unsigned Division by Zero)

Purpose  
Checks divide-by-zero behaviour for unsigned division.

Test Case (ALUTest13)

ALUCtrl = DIVU (5'b10001)

ALUop1 = 0x00000010

ALUop2 = 0x00000000

Expected ALUout = 0xFFFFFFFF

What It Tests

- Unsigned divide-by-zero semantics (quotient = all 1s)  
- Distinction between signed and unsigned division rules

---

### 5.1.12 ALU Test: REM (Remainder with Divisor Zero)

Purpose  
Verifies that for signed remainder the dividend is returned when the divisor is zero.

Test Case (ALUTest14)

ALUCtrl = REM

ALUop1 = 0x00000010 (16)

ALUop2 = 0x00000000 (0)

Expected ALUout = 0x00000010

What It Tests

- RISC-V rule: when divisor is zero, remainder = dividend (signed)  
- Difference between quotient and remainder behaviour in corner cases

---

### 5.1.13 ALU Test: REMU (Unsigned Remainder with Divisor Zero)

Purpose  
Confirms that in the unsigned case, the remainder also returns the dividend on divide-by-zero.

Test Case (ALUTest15)

ALUCtrl = REMU

ALUop1 = 0x00000010

ALUop2 = 0x00000000

Expected ALUout = 0x00000010

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