# Yusuf Kerem Teker: Personal contributions and reflection
## Overview



## Succint Summary of contributions
My main contributions in chronological order was:
- Designing the Program Counter block for our single-cycle design
- Modifying the base doit.sh script for compatibility on Both WSL and MacOS
- Tests on Vbuddy: F1 assembly code and Testbench and Testbenching for PDF tests
- Pipelining: design and test-benching of Hazard unit and part of top-level integration
- M-extension
- Memory adaptation for Synthesis on FPGA



### 1. PC block
#### Inputs

```systemverilog
    input logic clk,
    input logic [WIDTH-1:0] Imm_op, 
    input logic [WIDTH-1:0] ALU,
    input logic rst,
    input logic [1:0] pc_src,
    output logic [WIDTH-1:0] pc,
    output logic [WIDTH-1:0] pc_save
```
> Width is 32 as our CPU is 32-bit
- We need Imm_op to add an offset to PC for JAL instructions
- We need ALU to add PC and rs1 for JALR instructions
- We need pc_src to determine how to increment PC
- We output pc_save for saving return addresses for jump instructions

#### Logic

```systemverilog
logic [WIDTH-1:0] branch_pc, inc_pc, internal_pc;
assign branch_pc = internal_pc+Imm_op;
assign inc_pc = internal_pc+4;
assign pc_save = inc_pc;

always_ff @(posedge clk)
    if (rst) internal_pc <= 32'hBFC00000;
    else begin
        case (pc_src)
            2'b00: internal_pc <= inc_pc;    // PC + 4
            2'b01: internal_pc <= branch_pc; // JAL
            2'b10: internal_pc <= ALU;       // JALR
            default: internal_pc <= inc_pc;  
        endcase
    end
assign pc = internal_pc;
```

- Our ROM starts at the address BFC00000 due to the memory map we were provided in the project brief:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/memory.jpg)

### 2. doit.sh script

The crux of the issue was that macOS does not ship realpath by default.
So every `realpath` call in the doit.sh file had to be replaced with POSIX-portable logic. Here is the final version of the code:
```bash
#!/bin/bash

# This script runs the testbench
# Usage: ./doit.sh <file1.cpp> <file2.cpp>

# Constants
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
TEST_FOLDER="$SCRIPT_DIR/tests"
RTL_FOLDER="$SCRIPT_DIR/../rtl"
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
RESET=$(tput sgr0)

# Variables
passes=0
fails=0

# Handle terminal arguments
if [[ $# -eq 0 ]]; then
    # If no arguments provided, run all tests
    files=(${TEST_FOLDER}/*.cpp)
else
    # If arguments provided, use them as input files
    files=("$@")
fi

cd $SCRIPT_DIR

# Wipe previous test output
rm -rf test_out/*

# Iterate through files
for file in "${files[@]}"; do
    name=$(basename "$file" _tb.cpp | cut -f1 -d\-)

    # If verify.cpp -> we are testing the top module
    if [ $name == "verify.cpp" ]; then
        name="top"
    fi

    # Translate Verilog -> C++ including testbench
    verilator   -Wall --trace \
                -cc ${RTL_FOLDER}/${name}.sv \
                --exe ${file} \
                -y ${RTL_FOLDER} \
                --prefix "Vdut" \
                -o Vdut \
                -LDFLAGS "-lgtest -lgtest_main -lpthread"

    # Build C++ project with automatically generated Makefile
    make -j -C obj_dir/ -f Vdut.mk

    # Run executable simulation file
    ./obj_dir/Vdut

    # Check if the test succeeded or not
    if [ $? -eq 0 ]; then
        ((passes++))
    else
        ((fails++))
    fi

done

# Save obj_dir in test_out
mv obj_dir test_out/
```

### 3. Tests on Vbuddy

#### F1 Lights

https://github.com/user-attachments/assets/0c69e605-449a-43a5-ae6c-754687139dbb

Here is the assembly code that we used to implement the F1 countdown mechanism:
```asm
main:
    addi a0, zero, 0
    addi t2, zero, 1
mloop:
    bne x8, t2, mloop
    jal t3, iloop
    addi a0, zero, 0
    jal t3, mloop
iloop:
    li a0, 0
    addi    a0, a0, 1
    addi    a0, a0, 2
    addi    a0, a0, 4
    addi    a0, a0, 8
    addi    a0, a0, 16
    addi    a0, a0, 32
    addi    a0, a0, 64
    addi    a0, a0, 128
    jalr t3, t3, 0
end:
    addi a0, zero, 0
```
Our trigger input is mapped to register 8 in our register file. This assembly code program loops at the top of mloop until the value of trigger is set to 1. If `x8` is set, we enter the F1 count-up subroutine by jumping to iloop. Once the subroutine is finished, we return to the main loop, where, if trigger is set again, the subroutine is re-entered.

```cpp
TEST_F(CpuTestbench, F1StartLights)
{
    setupTest("f1");

    initSimulation();

    // Initialise VBuddy
    vbdOpen();
    vbdSetMode(1);

    // Main simulation loop
    for (int i = 0; i < MAX_SIM_CYCLES && !Verilated::gotFinish(); ++i)
    {
        // delay introduced
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        // Advance one clock cycle
        runSimulation(1);
        top_->trigger = vbdFlag();

        // Drive the bargraph with the lower 8 bits of the F1 output signal
        vbdBar(top_->F1_SIGNAL & 0xFF);
        // & 0xFF is to truncate the result to fit the number of LEDs
    }

    vbdClose();

    // CpuTestbench::TearDown() will be called by gtest automatically
}

```


The delay that I introduced at the beginning of each cycle allows us to have the distinguisably slow count-up that you can observe in the video. As mentioned, trigger is set by `vbdFlag()` on the Vbuddy chip.
    


#### PDF tests
```cpp
TEST_F(CpuTestbench, noisy)
{

    setupTest("5_pdf");
    setData("reference/noisy.mem"); // the .mem file from which we read was changed for each test


    // Create Vdut, set up tracing, reset, etc.
    initSimulation();

    // Initialise VBuddy
    vbdOpen();
    vbdSetMode(1);
    vbdHeader("Single PDF");


    const int MAX_FUNC_CYC = 1000650;   // this gives pdf.s enough time to build the PDF
    int  bins = 0;     // display-cycle counter
    bool display = false;
    int  prev_a0 = top_->a0; // value of a0 before display phase, which will allow us to track when it first changes
    
    // Main simulation loop
    for (int i = 0;i <MAX_FUNC_CYC && !Verilated::gotFinish(); ++i)
    {

        runSimulation(1);



        // display turns on the first time the program changes a0
        if (!display && top_->a0 != prev_a0) {
            prev_a0 = top_->a0;
            display = true;
        }

        if (display) {
                ++bins;

                // a0 only changes every 4 instructions in display loop
                // so that we can fit the shape in a single or less windows
                //we can change this value as we see fit, which we did during testing and documentation (see videos)
                 if (bins % 4 == 0) {
                    vbdCycle(i);
                    vbdPlot(int(top_->a0) & 0xFF, 0, 255);
                 }
            // }
        }
    }

    vbdClose();

    // CpuTestbench::TearDown() will be called by gtest automatically
}
```

##### gaussian.mem




https://github.com/user-attachments/assets/e1337251-4626-412e-a283-311f928022b8




##### triangle.mem




https://github.com/user-attachments/assets/bff91a51-b9f0-47c0-a872-223c2331e0df



##### noisy.mem, 1





https://github.com/user-attachments/assets/770a829a-33fc-433d-b491-fc4e19501dce




##### noisy.mem, 2




https://github.com/user-attachments/assets/ee6f12fb-fede-4ab4-96b9-0ce7068977f9

### 4. Hazard Unit
#### 1.	Why hazards occur in a pipeline? 
In a pipelined CPU, multiple instructions are executed in parallel. Hazards arise due to this inherently parallel structure. 
Data Hazards occur when one or more instructions depend on results that have not yet been written back into the register file. Specifically, this arises when the destination register of the previous instruction is one of the source registers of the latter instruction. This phenomenon is called a Read-After-Write hazard.
![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/image1.png)

In the figure above, instructions that follow the `add s8, s4, s5` instruction use the s8 register as a source register in their arithmetic and logical operations. For instance, `sub s2, s8, s3` requires the contents of the register s8 in the 3rd clock cycle, the next instruction in the 4th, and the one after on the 5th. However, the initial add instruction is only able to write back to the register file by the end of the 5th clock cycle. Therefore, the instructions that follow read the previous value of s8 from the register, which is invalid in the logical sequence of execution and will most likely culminate in an erroneous result. To resolve this, forwarding logic is used, which in brief terms, is a shortcutting mechanism that writes back the result of an ALU operation to the register file as soon as it becomes available if the subsequent instructions are dependent upon that register.

A special case arises when the first instruction is a “Load” instruction.

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/image2.png)
 
When the instruction immediately after an “lw” instruction has a source register that is meant to be written into by the `lw` instruction, the 2 stage difference between the decode and memory stages means that the result of the “lw” instruction only becomes available once the next instruction has already reached and completed its execution stage. This is shown by the topmost arrow pointing from the bus carrying the result of the data memory (the “lw” result) to the top input of the ALU. Since the data dependency involves a result that only becomes available in the same clock cycle as the execution of the dependent instruction, forwarding on its own is no longer sufficient. 

Control Hazards are caused by branch instructions where the condition required for the branch is true, meaning the branch is taken. Once it is determined that the branch predicate is true, the program counter must branch to a different location, and the sequential order in which instructions are fetched from the instruction memory is broken. Depending on the offset of a branch instruction, an asserted branch invalidates the instructions fetched after the branch instruction and before the deduction of the branch condition’s validity. 

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/Untitled.png)

It is only at the point where the red arrow is, which is 2 clock cycles after the `beq` instruction is fetched from instruction memory, that the branch condition predicate is determined in the `EXECUTE` stage:

`FETCH` --> `DECODE` --> `EX`

#### 2.	Motivation for/responsibilities of the hazard unit
Our hazard unit encapsulates all of the regulatory logic required to tackle the issues introduced by pipelining, including both data hazards and control hazards. Hence, the hazard unit is a single comprehensive module that triggers and employs stalling, flushing, and forwarding mechanisms (what these mechanisms do will be explained later together with the solutions). We chose this unitary and holistic approach to resolving both kinds of hazards because the input signals required to generate the relevant control signals for stalling, flushing and forwarding are the same or similar.

In summary, the primary goals of the Hazard Unit are:

- To resolve data hazards through forwarding whenever possible, minimizing performance loss.

- To detect and stall only when forwarding cannot supply the required operand in time (“Load” data dependency).

- To flush instructions that enter the pipeline speculatively once a branch outcome becomes known.




#### Data hazard resolution: forwarding logic
For most arithmetic and logical instructions, the result becomes available before Write-Back, either at the end of the `EX` or `MEM` stage, allowing us to resolve these hazards without inserting stalls by forwarding the result directly to the ALU inputs.
The Hazard Unit implements this forwarding by checking whether the source registers used by the instruction currently in the Execute (EX) stage match the destination registers of instructions that are still in the Memory (MEM) or Write-Back (WB) stages.

Forwarding Decision Conditions:
```systemverilog
always_comb begin
    //Default:no forwarding
    selectline1 = 2'b00;
    selectline2 = 2'b00;

    //Operand1 forwarding
    if (regWriteM && rdM != 0 && rdM == rs1E) begin
        selectline1 = 2'b10;  //from MEM stage
    end 
    else if (WriteBack_Regfile && rdWB !=0 && rdWB == rs1E) begin
        selectline1 = 2'b01;  //from WB stage
    end

    // Operand 2 forwarding
    if (regWriteM && rdM !=0 && rdM == rs2E) begin
        selectline2 = 2'b10;
    end 
    else if (WriteBack_Regfile && rdWB !=0 && rdWB == rs2E) begin
        selectline2 = 2'b01;
    end

end

```
The forwarding logic compares decoded operands rs1E and rs2E with the destination registers rdM and rdWB:

•	If the instruction in the MEM stage writes a register (regWriteM = 1) and its destination rdM matches the operand in EX, then the operand should be forwarded from MEM.

•	Else if the instruction in the WB stage writes a register (WriteBack_Regfile = 1) and its destination rdWB matches, then forward from WB.

•	Register x0 is never forwarded, so matches must ignore rd = 0.


##### Select Line Encoding
To control operand multiplexers feeding the ALU, the Hazard Unit sets two 2-bit signals:
| Value | Operand Source          |
| ----- | ----------------------- |
| 00    | Register file output    |
| 01    | Forward from Write-Back |
| 10    | Forward from Memory     |



So the circuit schematic for exclusively the hazard unit’s forwarding mechanism is identical to that detailed in the lecture slides as shown below:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/image3.png)
 
What this diagram does not cover is how the hazard unit tackles load word data dependencies and control hazards, discussed later.
Why forwarding ignores loads here
Even though this logic covers most RAW hazards, it does not prevent a load word hazard, because a load instruction does not produce valid data until the end of the MEM stage. In such cases, forwarding would still not provide the correct value in time, which is why the Hazard Unit must insert a stall (described in Section 4).
Forwarding entirely removes stalls that would otherwise be caused by data dependencies for:

•	ALU-to-ALU dependency chains (e.g., add, sub, and, or, etc.)

•	Immediate arithmetic dependencies (e.g., addi, ori)

•	Register-producing control instructions if value is known early (e.g., jalr)

#### 4. Load word data dependency
Forwarding cannot resolve a dependency when the preceding instruction is a load. In a load instruction, the data is only available after the Memory stage, meaning forwarding cannot provide a valid operand in the immediate next cycle.

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/image4.png)
 
(Modify this diagram to show that the execute stage is actually flushed, not stalled)
In this case, the Hazard Unit must stall the pipeline for exactly one cycle. It freezes the Program Counter and Fetch-to-Decode pipeline register and flushes the Decode-to-Execute pipeline register. The reason why Decode-to-Execute pipeline register is flushed is that if it were only stalled, the “lw” instruction would propagate through to the memory stage but also still remain in the Decode-to-Execute pipeline register, essentially duplicating the lw instruction. Thus, flushing this stage of the pipeline both achieves the stall required for synchronization (since the next register is not able to propagate into the execute stage) and prevents the duplication that would cause 2 back to back “lw” instructions.

```systemverilog
logic wStall;
//logic lw_write_back;

assign wStall = (resultSrCE == 2'b01) &&
                 ( (rdE != 0) &&
                   ( (rdE == rs1D) || (rdE == rs2D) ) );

...

always_comb begin

    // Default: no stall, and no flush
    PCWrite     = 1;
    F_Write = 1;
    flush_d_exec = 0;
    flush_f_d = 0;

    ... //Control hazard detection and flushing

    if(wStall == 1) begin
        PCWrite     = 0;
        F_Write = 0;
        flush_d_exec = 1;
    end
end

```

The stall condition used in the design asserts when: (Same as data dependency section, put the code somewhere over here)
•	The instruction in Execute is a load (resultSrCE == 2'b01), and
•	Its destination register rdE matches either source register in Decode (rs1D or rs2D), and
•	rdE != 0.
This is implemented in:
(code)
When a stall is necessary:
•	PCWrite = 0 prevents PC update,
•	F_Write = 0 prevents writing to IF/ID,
•	flush_d_exec = 1 inserts a bubble into Execute.
Thus, one cycle later, forwarding can resume as normal.


#### 5. Control hazard detection and Flush logic

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/image5.png)
 
In the image, the first instruction in the sequence is “beq s1, s2, L1”. In the first clock cycle, the instruction is fetched from instruction memory and fed to the pipeline register connecting the fetch stage to the decode stage. In the second clock cycle, the branch instruction is decoded and the relevant registers read from the register file. Meanwhile, the next instruction – “sub s8, t1, s3” – is fetched from instruction memory. Only by the third clock cycle, does the ALU determine that s1 and s2 are equal. However, two new instructions have been fetched already from instruction memory under the speculative assumption that the branch will not be taken. The solution is to “flush” the fetch and decode stages. To do this, the hazard unit outputs a control signal to the Fetch-to-Decode and Decode-to-Execute pipeline registers. Our pipeline registers have internal logic that synchronously sets the contents of the pipeline registers to 0 once the one-bit control signal from the hazard unit triggers flushing. Since the PC is updated to the branch target, the pipeline then continues with correct instructions.

```systemverilog
if(PCSrcE == 2'b10 || PCSrcE == 2'b01) begin
        flush_f_d = 1;
        flush_d_exec = 1;
    end
```
---

#### 3. Schematic

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/p_pipelining.png)


---

### M-extension
#### 1. Scope

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

#### 2. ALU changes

##### 2.1 ALUCtrl widened
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

##### 2.2 Multiplication implementation

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
##### 2.3. Division and remainder with edge cases
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

### 3. Control Path Changes for M Instructions

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
2. Add multiplier/divider/remainder datapaths in the ALU:
   - 64‑bit product with operand handling for signedness combination, sliced as upper/lower 32-bits per MUL* semantics.
   - Signed/unsigned division and remainder with RISC‑V corner cases (divide‑by‑zero, `-2^31 / -1`).
3. Extend control decode for `opcode == OPC_OP` and `funct7 == 7'b0000001`, mapping `(funct3, funct7)` → `ALUCtrl` while leaving all R‑type control signals unchanged.

Everything else in the CPU is unchanged — they see M instructions as standard R‑type ALU ops that take longer to compute. Integration was hence modular and local to ALU/control unit modules. Behaviour matches the RISC‑V spec, including all specified corner cases.

### 6 Trade-offs & notes
- Simplicity vs. timing: My combinational implementation is easy to verify but slow. Even though I did make optimisations when computing products, the design is not synthesizable. Alternatives for synthesis were the following: multi-cycle or pipelined multiply/divide units, or a long‑latency functional unit.
- On the other hand, only two modules changed: `alu.sv` (wider `ALUCtrl`, M logic) and `control.sv` (wider `ALUCtrl` output, M decoding). No structural changes to pipeline or hazards. This was benefitial in that my design integrated smoothly with the rest of the CPU, including our branch-predictor, multi-level cache, and Z-extensions.



### Memory Adaptation for FPGA

Array-based memory designs, which we used initially throughout the project, are convenient for correctness but do not map reliably onto physical FPGA resources. On an FPGA, on-chip memory is implemented using Block RAM (BRAM), which is a dedicated, fixed hardware resource with strict architectural constraints such as synchronous read/write behavior, limited port configurations, and vendor-specific inference rules. Simply describing a memory as a generic array in SystemVerilog does not guarantee that the synthesis tool will infer BRAM; instead, it may result in inefficient distributed logic or fail to synthesize altogether for larger memories. As a result, our original memory modules had to be redesigned to conform to BRAM-compatible access patterns—most notably by using synchronous reads, explicit clocking, and FPGA-friendly coding styles. 

To program the FPGA, we had to use a program called Quartus. We were able to put our .sv files onto Quartus and use its many, many features to set up the right conditions for the FPGA to allow us to port our CPU onto it.

The first hurdle was the memory; as we discussed, we would need to use 2 BRAM blocks. First, imem: It would need 1024, 32-bit words called imem_ram, which we will call inside the insmem module. We MUST make sure to uncheck make the output registered or else it will take 2 cycles to read (I had this issue for days). For this imem block, we would also need to initialise its memory content using a program.mif file where we will write the instruction memory code (similar to our program.hex files). This insmem would now be clocked too, making reading from it synchronous. For exact details, see:


We would follow the same process as above from datamem, however, now with 32768 32-bit words, and with byte-enable indexing turned on and no memory initialisation.

Even though we adapted our memories in accordance with the FPGA-friendly coding styles necessary, Quartus did not correctly infer and implement our BRAM blocks on the target FPGA. As such, we used the IP 2-Port (Read and Write) RAM module in the catalogue section of Quartus, which allowed us to correctly implement our memory modules as BRAM blocks.

And now we would need to call the new dmem_ram inside the datamem module:

```systemverilog
    dmem_ram dmem_inst (
        .clock   (clk),
        .address (word_index),
        .data    (WD),
        .wren    (MemWrite),
        .byteena (byteena),
        .q       (raw_word)
    );
```
- Note **`raw_word`** is the word without load-size or load-sign logic implemented.

#### Top:
We must take note that, as reading memory is now synchronous, we must not pass the outputs of the memory blocks through the pipeline registers; instead, they can go straight to the next stage.

However, this also means we must now change the logic, as our previous instructions assumed that we had synchronous reads. This includes adding a stall buffer in top, as when we call stall, our BRAM has already gotten our instruction, and if we don't hold onto it will get overwritten and lost:

```systemverilog
    always_ff @(posedge clk) begin
        if (rst) begin
            Stall_Active <= 0;
            InstrD_Saved <= 0;
        end else begin
            Stall_Active <= flush_d_exec; 
            if (flush_d_exec && !Stall_Active) begin
                InstrD_Saved <= InstrF_raw;
            end
        end
    end
```
We must also kill the cycle that occurs while we are branching, as even though we update the address our ROM is accessing, as it is asynchronous, it still grabs the previous address, which will run an instruction we don't want to run:

```systemverilog
    always_ff @(posedge clk) begin
        if (rst) kill_cycle <= 0;
        else kill_cycle <= (JumpE || false_prediction || trap_en || mret_en); 
    end

    assign InstrF = (kill_cycle || rst) ? 32'h00000013 : // addi x0, x0, 0 or NOP
                    (Stall_Active) ? InstrD_Saved : InstrF_raw;
```

We also need to deal with RAW (read after write) hazards in the decode stage, while there are data dependancies in the writeback stage, by skipping the registers and forwarding directly:

```systemverilog
    always_comb begin
    if (RegWriteW && (Rs1D != 0) && (Rs1D == RdW)) RD1D_Correct = ResultW;
    else  RD1D_Correct = RD1D;

    if (RegWriteW && (Rs2D != 0) && (Rs2D == RdW))  RD2D_Correct = ResultW;
    else RD2D_Correct = RD2D;
    end
```

Now that the hazards are all dealt with, we can focus on adding FPGA-specific hardware to our SystemVerilog code. This includes GPIO (for LEDS), 7-segment display mapping, a debouncer and an FPGA Wrapper.

## Mistakes made

## Reflection



