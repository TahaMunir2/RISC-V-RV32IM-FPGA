# RV32M (“M-type”) Instructions – Design and Implementation

This section documents how the RV32M integer multiplication and division extension is integrated into our RV32I core. The focus is on the additional functionality and on the changes made to the ALU and control logic; everything else in the CPU (pipeline structure, hazard unit, memories, etc.) behaves as before.

---

## 1. Scope of the M Extension

We implement the full RV32M base extension as defined in the RISC-V spec:

- **MUL** – computes the full 64-bit product  
  \( P = (\text{int32})rs1 \times (\text{int32})rs2 \)  
  and writes the low 32 bits \( P[31:0] \) to `rd` (modulo \(2^{32}\) wrap-around).

- **MULH** – computes the 64-bit signed product  
  \( P = (\text{int32})rs1 \times (\text{int32})rs2 \)  
  and writes the high 32 bits \( P[63:32] \) to `rd` (signed×signed high word).

- **MULHSU** – computes the 64-bit mixed-sign product  
  \( P = (\text{int32})rs1 \times (\text{uint32})rs2 \)  
  and writes the high 32 bits \( P[63:32] \) to `rd` (signed×unsigned high word).

- **MULHU** – computes the 64-bit unsigned product  
  \( P = (\text{uint32})rs1 \times (\text{uint32})rs2 \)  
  and writes the high 32 bits \( P[63:32] \) to `rd` (unsigned×unsigned high word).

- **DIV** – performs signed integer division  
  \( q = \text{trunc}((\text{int32})rs1 / (\text{int32})rs2) \)  
  with special cases:
  - \( q = -1 \) if divisor is 0  
  - \( q = 0x80000000 \) for the overflow case \( -2^{31} / -1 \).

- **DIVU** – performs unsigned division  
  \( q = (\text{uint32})rs1 / (\text{uint32})rs2 \),  
  with \( q = 0xFFFFFFFF \) if the divisor is 0.

- **REM** – returns the signed remainder  
  \( r = (\text{int32})rs1 \% (\text{int32})rs2 \)  
  such that \( rs1 = q \cdot rs2 + r \) and **r has the same sign as rs1**.  
  If divisor is 0, `r = rs1`, and in the overflow case \((-2^{31} / -1)\) we return `r = 0`.

- **REMU** – returns the unsigned remainder  
  \( r = (\text{uint32})rs1 \% (\text{uint32})rs2 \)  
  (always in \([0, 2^{32}-1]\)); if divisor is 0, `r = rs1` (bit-pattern preserved).

Architecturally, these are encoded as standard **R-type** instructions with:

- `opcode = OP (0110011)`
- `funct7 = 0000001` to indicate “M-extension” operation
- `funct3` to select which of the eight operations.

In our design, all eight M operations are executed in the existing **ALU**. They are treated like any other R-type ALU instruction by the pipeline and hazard unit:

- Read `rs1` and `rs2` from the register file  
- Produce a 32-bit result in `rd`  
- Set `RegWrite = 1` and write back in the WB stage  
- No special cases in the forwarding logic; M ops forward exactly like `ADD`/`SUB`/etc.

The rest of this section explains how the ALU and control logic were extended to support these operations.

---

## 2. ALU Changes for M Instructions

### 2.1 Wider ALU control signal

Originally, `ALUCtrl` was 4 bits, enough to encode the basic RV32I operations (ADD, SUB, logic, shifts, SLT/SLTU, LUI, AUIPC, etc.). To accommodate all the new M operations **without overloading existing encodings**, we widened the control signal.

Existing RV32I operations were kept on small values (`00000`–`01011`), and the M extension used the higher codes (`01100`–`10011`) in order of next available, which kept the mapping readable and easy to scale.

Concretely, the ALU now interprets `ALUCtrl` for the new M-extension codes as:

- `01100` – **MUL** (low 32 bits)  
- `01101` – **MULH** (high 32 bits of signed×signed)  
- `01110` – **MULHU** (high 32 bits of unsigned×unsigned)  
- `01111` – **MULHSU** (high 32 bits of signed×unsigned)  
- `10000` – **DIV** (signed)  
- `10001` – **DIVU** (unsigned)  
- `10010` – **REM** (signed remainder)  
- `10011` – **REMU** (unsigned remainder)

These codes are chosen such that:

- Existing RV32I behaviour is unchanged  
- All eight M operations have unique control values without conflict  
- The mapping is easy to decode in the control unit and to extend for new instructions

---

### 2.2 64-bit intermediate product signals

To implement the `MUL*` family, the ALU conceptually supports 64-bit products for each combination of operand signedness required by the ISA:

```systemverilog
logic [63:0] unsigned_mult;
logic [63:0] signed_mult;
logic [63:0] signed_unsigned_mult;

assign unsigned_mult        = $unsigned(ALUop1) * $unsigned(ALUop2);
assign signed_mult          = $signed(ALUop1)   * $signed(ALUop2);
assign signed_unsigned_mult = $signed(ALUop1)   * $unsigned(ALUop2);
