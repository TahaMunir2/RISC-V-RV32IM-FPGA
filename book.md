# Compilation of READMEs from all the Branches

## Table of READMEs
[1. Single Cycle Reduced RV32I CPU](#Single-cycle-Reduced-RV32I-CPU)
[2. Full RV32I (37-Instruction)](#Full-RV32I-(37-Instruction))
[3. Pipelined RISC-V Processor](#Pipelined-RISC-V-Processor)
[4. Branch Prediction](#Branch-Prediction)
[5. Hierarchical Cache](#Hierarchical-Cache)
[6. M-type Instructions](#M-type-Instructions)
[7. Zicsr and Zba Extensions](#Zicsr-and-Zba-Extensions)
[8. Interrupts and FPGA](#Interrupts-and-FPGA)
[9. Out-of-Order Superscalar Processor](#Out-of-Order=Superscalar-Processor)
[10. Out-of-Order Superscalar Processor with Load Instructions](#Out-of-Order-Superscalar-Processor-with-Load-Instructions)

# Single Cycle Reduced RV32I CPU:

## Table of Contents
- [1. Overview](#overview)
- [2. Implementation](#implementation)
  - [2.1 PC](#pc)
    - [2.1.1 Inputs](#inputs)
    - [2.1.2 Logic](#logic)
  - [2.2 Instruction Memory](#instruction-memory)
  - [2.3 Data Memory](#data-memory)
    - [2.3.1 Initialisation](#initialisation)
    - [2.3.2 Read Logic](#read-logic)
    - [2.3.3 Write Logic](#write-logic)
  - [2.4 Register File](#register-file)
    - [2.4.1 Read Logic](#read-logic-1)
    - [2.4.2 Write Logic](#write-logic-1)
  - [2.5 Decoder](#decoder)
    - [2.5.1 Initialisation](#initialisation-1)
    - [2.5.2 Control Signals](#control-signals)
    - [2.5.3 Instructions](#instructions)
  - [2.6 Sign Extender](#sign-extender)
  - [2.7 ALU](#alu)
  - [2.8 Top](#top)
- [3. Schematic](#schematic)
- [4. Testing](#testing)
  - [4.1 Test Benches](#test-benches)
  - [4.2 F1 Lights](#f1-lights)

---

## Overview

This section goes over the baseline foundation of our RV32I CPU and includes the work covered in Lab 4. Working on the single-cycle CPU gave our team an introduction to working with each other and designing and testing a CPU using SystemVerilog and shell script testing environments. Our single-cycle CPU implements the following 9 instructions:


| # | Mnemonic | Type | Opcode (binary) | funct3 | funct7   | Brief description                            |
|---|----------|------|-----------------|--------|----------|----------------------------------------------|
| 1 | `ADDI`   | I    | `0010011`       | `000`  | –        | Add sign-extended immediate to `rs1`.        |
| 2 | `BNE`    | B    | `1100011`       | `001`  | –        | Branch if `rs1 != rs2`.                      |
| 3 | `ADD`    | R    | `0110011`       | `000`  | `0000000`| Register-register add.                       |
| 4 | `LW`     | I    | `0000011`       | `010`  | –        | Load 32-bit word from memory.                |
| 5 | `LBU`    | I    | `0000011`       | `100`  | –        | Load zero-extended byte from memory.         |
| 6 | `JALR`   | I/J* | `1100111`       | `000`* | –        | Jump to `rs1 + imm`, write return PC to `rd`.|
| 7 | `SB`     | S    | `0100011`       | `000`  | –        | Store byte to memory.                        |
| 8 | `JAL`    | J    | `1101111`       | –      | –        | PC-relative jump, write return PC to `rd`.   |
| 9 | `LUI`    | U    | `0110111`       | –      | –        | Load 20-bit upper immediate into `rd`.       |

> *In the reduced version, `JALR` is treated as its own control-flow case and the funct3 field is not fully generalised.

To do so, we had to implement a control path and a datapath for our CPU, as well as learning how to initialise the ROM and RAM with memory.

## Implementation

We can break our implementation into each new module we have made for our RV32I CPU.

### PC 


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

### Instruction Memory 

Our instruction memory effectively acts like a ROM:

```systemverilog
   logic [7:0] rom_array [2**12-1:0];

    initial begin
        $display("Loading rom.", );
        $readmemh("program.hex", rom_array);
    end
```

- It will have a size of 4096 in line with the memory map
-We will initialise it using the program.hex, which is the byte converted version of our asm file using the assemble.sh script.

```systemverilog
 always_comb begin // asynchronous read
        local_addr = addr - 32'hBFC00000;
        if (addr >= 32'hBFC00000 && local_addr < (2**12 - 3)) begin
            instr = {
                rom_array[local_addr + 3], 
                rom_array[local_addr + 2], 
                rom_array[local_addr + 1], 
                rom_array[local_addr]
            };
        end else begin
            instr = 32'b0; 
        end
```

- We remove the offset from the address so we can have an array that starts with index 0
- If we are trying to access an address that isn't in the instruction memory, then don't output anything (illegal operation).

### Data Memory

Our data memory is very similar to the instruction memory, but it is a RAM instead, meaning that in addition to reading from it, we can write to it as well.

#### Initialisation

```systemverilog
logic [7:0] ram_array [2**17-1:0];

initial begin
    $display("Loading ram.");
    $readmemh("reference/gaussian.mem", ram_array, 0x10000);
end
```

- We now make an array of size 131,072 in compliance with our memory map.
- We read from gaussian.mem for the pdf.s testcase provided in the project brief. To pass the test, we need an offset of 0x10,0000.

#### Read Logic

```systemverilog
always_comb begin
    if(ByteWrite) begin
        dout[7:0] = ram_array[A];
        dout[31:8] = 24'b0;
    end
    else  begin
        dout[7:0] = ram_array[A];
        dout[15:8] = ram_array[A+1];
        dout[23:16] = ram_array[A+2];
        dout[31:24] = ram_array[A+3];
    end
end
```
- We use ByteWrite to determine if we are trying to read just 1 byte or the whole word.
- The rest of the logic is the same as the ROM.
- We use little-endian logic.

#### Write Logic

```systemverilog
always_ff @(posedge clk) begin
    if (MemWrite) begin
        if (ByteWrite) begin
        ram_array[A] <= WD[7:0];
        end
    end
end
```

- The write logic is clocked since reading does not alter the memory, but writing does, so we need it to only do so when we are absolutely ready.
- MemWrite tells us if the instruction is a Store Word instruction, hence requiring writing to the memory; else, we must NOT write to it.

### Register File

The registers are made using a much smaller array of 32 32-bit registers used by the instructions. 

#### Read Logic:

```systemverilog
    always_comb begin
        RD1= regfile_array[AD1];
        RD2= regfile_array[AD2];
        A0 = regfile_array[10];
        regfile_array[0] = 0;
        regfile_array[8][0] = trigger; // we do not use trigger for now, besides allocating it to the bottom bit of a random register we don't use in our asms 
    end
```

- We have 2 read ports for the register
- A0 is connected to x10 and is our output port
- x0 is always 0 in RISCV
- Trigger is implemented later in our FPGA implementation; for now, it just lets our CPU always run.

#### Write Logic

```systemverilog
    always_ff @(posedge clk) begin
        if(WE3) regfile_array[AD3] <= WD3;
    end
```

- WE3 is an input from the decoder that tells us if we are supposed to be writing to the register or not.
- WD3 is the input that tells us what we should write into AD3.
- We only have 1 write port.

### Decoder

Our decoder takes the 32-bit instruction and breaks it down into different segments to determine what logic we should perform for that given instruction.

#### Initialisation

```systemverilog
logic [6:0] op;
logic [2:0] funct3;
logic [6:0] funct7;
assign op = instr[6:0];
assign funct3 = instr[14:12];
assign funct7 = instr [31:25];
```

The 3 segments that the decoder uses are the OPcode, the funct3 (if available) and the funct7 (if available) to determine what type of instruction we are decoding. The OPcode is always mapped to the bottom 7 bits, and the locations of funct3 and funct7 don't change; however, whether they are available depends on the type of instruction, however. They simply aren't used if they don't exist for that OPcode.

![alt_text](https://github.com/TahaMunir2/Team5/blob/main/images/functions.png)

#### Control Signals

Here, we describe what each type of control signal does and set them to 0 to prevent latching:

```systemverilog
always_comb begin
    RegWrite  = 0; // 1 for writing 
    ALUCtrl   = 3'b000; // determines operation of alu
    ALUSrc    = 0; // imm (1) or rd2 (0) for alu
    ImmSrc    = 3'b000; // determines type of sign extension
    PCSrc     = 2'b00; // determines next pc
    ResultSrc = 2'b00; // alu result(0) or RD[alu_result] (1)
    MemWrite  = 0; // write enable for data mem
    ByteWrite = 0; // determines if we are doing word(0) or byte(1) logic
```

#### Instructions

Here, we reassign control signals for each instruction; later on, we will not assign signals to 0 (as they already have been), but we do it here to help illustrate what each signal does and where they do and don't matter.

```systemverilog
// i type instructions
    if (op == 7'b0010011) begin  // ADDI
        if (funct3 == 3'b0) begin
            RegWrite = 1; // enable write to write the result into
            ALUCtrl = 3'b000; // addition
            ALUSrc = 1; // we need imm for addi
        end
    end

    else if (op == 7'b1100011) begin  // BNE
        if (funct3 == 3'b001) begin
            ALUCtrl = 3'b001; // subtraction
            ImmSrc = 3'b010; // type of signext for bne
            if (EQ == 0) begin
                PCSrc = 1; // pc + imm
            end
        end
    end

    else if (op == 7'b0110011) begin
        if (funct3 == 3'b000)  begin
            if (funct7 == 7'b0000000) begin // ADD
                RegWrite = 1; // we are writing into rd
                ALUCtrl = 3'b000; // we are adding
                ALUSrc = 0; // use ALU_op2
            end
        end
    end

    else if (op== 7'b0000011) begin
        if (funct3 == 3'b010) begin // LW
            RegWrite=1;
            ALUSrc = 1'b1; // we need the imm to write 
            ImmSrc = 3'b000; //must be 00 because it is an immediate type instruction
            ResultSrc = 1; //we are writing the output of the data mem to the regfile
        end
    else if (funct3 == 3'b100) begin // LBU
            RegWrite=1;
            ALUSrc = 1'b1; 
            ImmSrc = 3'b000; //must be 000 because it is an immediate type instruction
            ResultSrc = 1; //we are writing the output of the data mem to the regfile
            ByteWrite = 1; // bytwwise logic
        end
    end

    else if (op == 7'b1100111) begin // JALR    
        RegWrite = 1; // as we are saving the old value
        ALUCtrl = 3'b0; // we need to add r1 and imm
        ALUSrc = 1; // to add imm
        ImmSrc = 3'b000; // 000 for jalr  instruction
        PCSrc = 2'b10; // for adding an offset to PC and register
        ResultSrc = 2'b10; // for jump instruction
    end

    // S type instructions
    else if (op == 7'b0100011) begin // SB
        ALUCtrl  = 3'b000; // adding rs1 and imm
        ALUSrc   = 1; // we need imm
        ImmSrc   = 3'b001;  // for store
        MemWrite = 1; // need to write into memory
        ByteWrite = 1; // byte wise logic
    end

    // J type instructions
    else if (op == 7'b1101111) begin // JAL 
        RegWrite = 1; // as we are saving the old value
        ALUCtrl = 3'b0; // doesn't matter, ALU not used
        ALUSrc = 0; // // doesn't matter
        ImmSrc = 3'b011; // 11 for j type instruction
        PCSrc = 1; // for adding an offset to PC
        ResultSrc = 2'b10; // for jump instruction
    end

    // U type instructions
    else if (op == 7'b0110111) begin // LUI 
        RegWrite = 1; // to write into R[Rd]
        ALUCtrl = 3'b100; // just makes ALUout rd
        ALUSrc = 1; // we need to use the imm
        ImmSrc = 3'b100; // 4 for U type instructions
    end
end
```

### Sign Extender

The Immediate we get from the instruction will always be less than 32 bits; however, its location, length and type of extension we need to apply varies from instruction to instruction as shown by the diagram above. Hence, we must use a case statement as below:

```systemverilog
always_comb begin
    if (ImmSrc == 3'b000) begin   // for I instructions
        immext = {{20{instr[31]}}, instr[31:20]};
    end
    else if (ImmSrc == 3'b001) begin // for S instructions
        immext = {{20{instr[31]}}, instr[31:25], instr[11:7]};
    end
    else if (ImmSrc == 3'b010) begin // for B instructions
        immext = {{20{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0};
    end

    else if (ImmSrc == 3'b100) begin // for U instructions
        immext = {{instr[31:12]}, 12'b0};
    end

    else if (ImmSrc == 3'b011) begin  // for J instructions
        immext = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};
    end
    else immext = 32'b0; // no Imm
end
```

- Note there is actually no sign extension happening for U instructions, just bit shifting
- For J instructions, the last bit is always 0, as we can't jump to half of an instruction

### ALU

The ALU is the Arithmetic Logic Unit, where register and immediate operations happen, with the type of operation happening depending on the input ALUCtrl.

```systemverilog
    always_comb
    begin
        //default to avoid latches
        ALUout = 0;
        EQ = 1'b0;

        if (ALUop1 - ALUop2 == 0) EQ = 1'b1;
        else EQ = 1'b0;

        case (ALUctrl)
        3'b000 : ALUout = ALUop1 + ALUop2; // add
        3'b001 : ALUout = ALUop1 - ALUop2; // subtract
        3'b010 : ALUout = ALUop1 & ALUop2; // and
        3'b011 : ALUout = ALUop1 | ALUop2; // or
        3'b100: ALUout = ALUop2; // for LUI
        default: ALUout = 32'b0;
        endcase
    end
```

- We added some extra operations that would be useful in future additions, such as AND and OR.
- We use the EQ "flag" for branch instructions that depend on equality of the registers.


### Top

We need to add some multiplexers in the top-level file to determine the inputs to certain modules:

To determine what we are writing to the register, we use this MUX:

```systemverilog
    always_comb begin
        case (ResultSrc)
            2'b00: write_to_reg = output_ALU;     // ALU
            2'b01: write_to_reg = output_DataMem; // Memory
            2'b10: write_to_reg = pc_save;        // for jump instructions
            default: write_to_reg = 32'b0;
        endcase
    end
```

To determine if the 2nd operator in the ALU comes from the register or is an immediate:

```systemverilog
        mux mux(
        .in0(regOp2),
        .in1(ImmOp),
        .sel(ALUsrc),
        .out(ALUop2)
    );
```

We also have a MUX in our top-level schematic (below) for determining PC; however, we implemented that one in the PC_block.

## Schematic

![alt text](https://github.com/TahaMunir2/Team5/blob/single-cycle-cpu/images/Modified%20Single%20Cycle%20CPU%20diagram.jpg)

## Testing

### Test Benches:

For lab 4 (which covered the first 3 instructions), we made unit tests for every block:

![alt_text](https://github.com/TahaMunir2/Team5/blob/main/images/units.png)

With each test bench containing many test cases:

![alt_text](https://github.com/TahaMunir2/Team5/blob/main/images/pc_tb.png)
> Example: Testbench for PC block.

For a single cycle, we used the testbenches provided in the project brief for our testing:

![alt_text](https://github.com/TahaMunir2/Team5/blob/main/images/asms.png)

And all the tests passed:

![alt_text](https://github.com/TahaMunir2/Team5/blob/main/images/singlecyclepass.png)

### F1 Lights



https://github.com/user-attachments/assets/0c69e605-449a-43a5-ae6c-754687139dbb




Here is the assembly code that we used to implement the F1 countdown mechanism:
```

.text
.globl main
.text
.globl main
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
    


### PDF tests
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

#### triangle.mem




https://github.com/user-attachments/assets/bff91a51-b9f0-47c0-a872-223c2331e0df



#### noisy.mem, 1





https://github.com/user-attachments/assets/770a829a-33fc-433d-b491-fc4e19501dce




#### noisy.mem, 2




https://github.com/user-attachments/assets/ee6f12fb-fede-4ab4-96b9-0ce7068977f9






