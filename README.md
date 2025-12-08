RV32M Extension Integration (Multiplier / Divider Unit)

This section documents the incremental modifications required to extend our existing pipelined RV32I CPU to support the full RV32M base extension, consisting of eight additional R-type multiply/divide instructions. These changes were limited to the ALU, Control Unit, and testing infrastructure, without modifying pipeline organization, branch prediction, or other datapath blocks.

1. ALU Extension for M Instructions

The ALU was expanded with logic to compute 64-bit intermediate products and support signed and unsigned division/remainder. Three internal multiplication signals are computed:

signed_mult = $signed(rs1) * $signed(rs2)

unsigned_mult = $unsigned(rs1) * $unsigned(rs2)

signed_unsigned_mult = $signed(rs1) * $unsigned(rs2)

Only the appropriate 32-bit subset is written to ALUout depending on the instruction. Division and remainder additionally implement corner-case behavior required by the ISA, such as division by zero and INT32 overflow (when −2³¹ / −1).

1.1 Implemented Operations
Instruction	Behavior (32-bit result)
MUL	Low 32 bits of signed × signed
MULH	High 32 bits of signed × signed
MULHSU	High 32 bits of signed × unsigned
MULHU	High 32 bits of unsigned × unsigned
DIV	Signed quotient with special case: −2³¹ ÷ −1 = −2³¹; division by zero → −1
DIVU	Unsigned quotient; division by zero → 0xFFFFFFFF
REM	Signed remainder; division by zero → rs1; special case −2³¹ % −1 = 0
REMU	Unsigned remainder; division by zero → rs1

These operations were encoded into the ALU control signal (ALUCtrl) using newly assigned 5-bit values.

2. Control Unit Extensions

The control unit was extended to decode the R-type instructions with funct7 = 0000001, which uniquely identifies operations from the RV32M extension. The existing R-type decode path was reused, with additional cases added under OPC_OP (opcode 0110011).

2.1 Decode Rules
funct3	funct7	Instruction	ALUCtrl
000	0000001	MUL	1100
001	0000001	MULH	1101
010	0000001	MULHSU	1110
011	0000001	MULHU	1111
100	0000001	DIV	10000
101	0000001	DIVU	10001
110	0000001	REM	10010
111	0000001	REMU	10011

All M instructions:

Remain R-type

Use register operands only (ALUSrc = 0)

Write results to the register file (RegWrite = 1)

Do not affect branching, memory, or PC control signals

No additional hazard logic was required because the multiplier/divider executes fully inside the ALU stage and writes back normally. Forwarding paths already handle RAW dependencies.

3. Testing the M Extension

We validated correctness at the unit level using GoogleTest-based C++ testbenches. The file alu_tb.cpp was expanded to exhaustively test all M instructions, including negative operands, mixed signed/unsigned multiplication, division overflow, and division-by-zero behavior.

3.1 Example Test Cases
