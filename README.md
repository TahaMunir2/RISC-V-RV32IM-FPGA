RV32M Extension (Multiply / Divide Unit)

This section documents our extension from RV32I → RV32IM, adding full support for the eight instructions defined in the RV32M standard. Only the ALU and Control Unit were modified. No changes were required to our pipeline, forwarding, memory subsystem, or branch logic.

🔧 ALU Extensions

We expanded the ALU to include a 64-bit multiplication datapath and signed/unsigned division and remainder units. Three internal multiplication signals are computed:

signed_mult           = $signed(rs1) * $signed(rs2);
unsigned_mult         = $unsigned(rs1) * $unsigned(rs2);
signed_unsigned_mult  = $signed(rs1) * $unsigned(rs2);


Only the appropriate 32-bit segment is written to ALUout. Division and remainder also implement all ISA-mandated corner cases, including division by zero and −2³¹ ÷ −1.

📌 Instruction Behaviors
Instruction	Description
MUL	Low 32 bits of signed × signed
MULH	High 32 bits of signed × signed
MULHSU	High 32 bits of signed × unsigned
MULHU	High 32 bits of unsigned × unsigned
DIV	Signed division, handles overflow & divide-by-zero
DIVU	Unsigned division, divide-by-zero → 0xFFFFFFFF
REM	Signed remainder, divide-by-zero → dividend
REMU	Unsigned remainder, divide-by-zero → dividend
🧠 Control Unit Integration

All M-extension instructions occur under the R-type opcode 0110011, uniquely identified by funct7 = 0000001.

funct3	funct7	Instruction	ALUCtrl
000	0000001	MUL	1100
001	0000001	MULH	1101
010	0000001	MULHSU	1110
011	0000001	MULHU	1111
100	0000001	DIV	10000
101	0000001	DIVU	10001
110	0000001	REM	10010
111	0000001	REMU	10011

🔹 No pipeline changes were required.
🔹 All instructions are still R-type, write back normally, and use existing forwarding logic.

🧪 ALU M-Extension Testing

We extended alu_tb.cpp with exhaustive tests covering both valid and corner-case results.

ALU Test: MUL (Low 32-bit Product)

Purpose
Verifies that the ALU returns the lower 32 bits of a full 64-bit multiplication.

Test Case (ALUTest3)

ALUCtrl = MUL
ALUop1  = 5
ALUop2  = 4
Expected ALUout = 20


What It Tests

32-bit signed × signed multiplication

Truncation to low 32 bits

Correctness of basic multiplication behavior

ALU Test: MULH (High 32-bit Signed×Signed Product)

Purpose
Checks that MULH yields the upper word of a signed 64-bit multiplication.

Test Case (ALUTest4)

ALUCtrl = MULH
ALUop1  = 0x0FFF0000
ALUop2  = 256
Expected ALUout = 0x0000000F


What It Tests

Signed interpretation of both operands

Extraction of bits [63:32] from the 64-bit product

Correct handling of large positive products

ALU Test: MULH (Negative Operand Case)

Purpose
Validates MULH behavior with negative values.

Test Case (ALUTest5)

ALUCtrl = MULH
ALUop1  = 0xFFFFFFF0   # -16
ALUop2  = 0xFFFFFFF0   # -16
Expected ALUout = 0x00000000


What It Tests

Signed multiplication of two negatives

High word drops to zero when full product fits in 32 bits

ALU Test: DIV (Signed Division)

Purpose
Confirms the correct quotient for signed division.

Test Case (ALUTest6)

ALUCtrl = DIV
ALUop1  = 0xFFFFFFF0   # -16
ALUop2  = 0xFFFFFFF0   # -16
Expected ALUout = 1


What It Tests

Signed division semantics

Negative ÷ Negative → Positive

Proper sign extension

ALU Test: REM (Signed Remainder)

Purpose
Validates signed remainder semantics, especially with negative values.

Test Case (ALUTest7)

ALUCtrl = REM
ALUop1  = 0xFFFFFFFD   # -3
ALUop2  = 0xFFFFFFFE   # -2
Expected ALUout = 0xFFFFFFFF   # -1


What It Tests

Remainder follows dividend sign (ISA rule)

Correct signed behavior on negative modulo

Exact edge-case handling

ALU Test: REMU (Unsigned Remainder)

Purpose
Verifies the remainder result using unsigned interpretation.

Test Case (ALUTest8)

ALUCtrl = REMU
ALUop1  = 0xFFFFFFFD   # 4294967293
ALUop2  = 0xFFFFFFFE   # 4294967294
Expected ALUout = 0xFFFFFFFD


What It Tests

Unsigned interpretation of both operands

Remainder must be in range [0, divisor)

No sign extension applied

ALU Test: MULHSU (High 32-bit Signed×Unsigned Product)

Purpose
Checks the mixed-signed behavior unique to MULHSU.

Test Case (ALUTest9)

ALUCtrl = MULHSU
ALUop1  = 0xFFFFFFFF   # -1 (signed)
ALUop2  = 0x00000002   # 2  (unsigned)
Expected ALUout = 0xFFFFFFFF   # high part of (-2)


What It Tests

Mixed signed/unsigned multiplication

High 32-bit extraction from 64-bit result

Proper handling of negative × positive product
