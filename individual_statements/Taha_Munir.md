# Taha Munir (02562044) Individual Statement

## Table of Contents

- [Overview](#overview)
- [Implementation](#implementation)
  - [Lab 4](#lab-4)
  - [Single Cycle](#single-cycle)
  - [Pipelining](#pipelining)
  - [Z Extensions](#z-extensions)
  - [Interrupts and FPGA](#interrupts-and-fpga)
    - [F1 FSM Video](#f1-fsm-video)
- [Mistakes](#mistakes)
- [Reflection](#reflection)

---

## Overview

My main contributions in chronological order were:
- Test Benching and Top-level integration for Lab 4
- Implementing all 6 instructions for the Single Cycle CPU
- Designing the Pipeline Registers
- Helped design L1d and L1i cache
- Zicsr and Zba Extensions
- FPGA and Interrupts

I was also the GitHub "repo master" and although I did try to keep on top of keeping our GitHub structure organised and cleaning up redundant files and folders, especially at the end, this was a responsibility that was shared with the whole group, and I shared my ideas to make sure everyone had the same approach to using our GitHub.

---

## Implementation

### Lab 4

For Lab 4, we spun a random wheel, and I was fortunate enough to be handed the role of top-level integration and test benching. This meant I would have to not only fully understand how each module works to make unit test benches for each module to thoroughly test their functionality, but also understand how our CPU works overall to correctly integrate the whole circuit and troubleshoot using gtkWave.

I made the following unit test benches:

![alt_text](https://github.com/TahaMunir2/RISC-V-RV32IM-FPGA/blob/main/images/units.png)

With each test bench thoroughly testing the full functionality of the block:

```cpp
TEST_F(SignextTestbench, SRC0Test1)
{
    top->instr = 4063236096; // F2300000
    top->eval();
    EXPECT_EQ(top->immext, 4294967075); // FFFFFF23
}

TEST_F(SignextTestbench, SRC0Test2)
{
    top->instr = 180097588; // instr[31] is 0 so imm = 0AB
    top->eval();
    EXPECT_EQ(top->immext, 171); // 000000AB
}

TEST_F(SignextTestbench, SRC1Test1)
{
    top->ImmSrc = 1;
    top->instr = 202506240; // 0C120000
    top->eval();
    EXPECT_EQ(top->immext, 192); // 000000C0
}

TEST_F(SignextTestbench, SRC1Test2)
{
    top->ImmSrc = 1;
    top->instr = 4229038080; // FC120000
    top->eval();
    EXPECT_EQ(top->immext, 4294967232); //FFFFFFC0
}

TEST_F(SignextTestbench, SRC2Test1)
{
    top->ImmSrc = 2;
    top->instr = 2113933056; // 01111110000000000000111100000000
    top->eval();
    EXPECT_EQ(top->immext, 2046); // 00000000000000000000011111111110
}

TEST_F(SignextTestbench, SRC2Test2)
{
    top->ImmSrc = 2;
    top->instr = 4261416832; // 11111110000000000000111110000000
    top->eval();
    EXPECT_EQ(top->immext, 4294967294); // 11111111111111111111111111111110
}
```
> Example: Testbench for Sign Extension block

To make the testbenches, I used the 2 reference test benches we were given and spent a lot of time combing through the header files to try and fully understand how to best utilise the tools we had available to most thoroughly and efficiently troubleshoot our design for the many, many mistakes we were bound to make. I standardised an approach for our whole group where we would add unit test benches the first time we would integrate a new block into the circuit, and then using CPU wide testbenches for that block going forward. This was a healthy balance between thorough testing and time efficiency.

For the top-level integration, I used this schematic provided to use in the project brief as a reference:

![diagram](https://github.com/TahaMunir2/RISC-V-RV32IM-FPGA/blob/main/images/microarchitecture.jpg)

---

### Single Cycle:

I wrote the full documentation of this section. For more details, see the [GitHub README](https://github.com/TahaMunir2/RISC-V-RV32IM-FPGA/blob/single-cycle-cpu/README.md).

For this section, my primary responsibility was to add the 6 additional instructions such that we were able to pass the 5 reference programs provided to us in the project brief:

![alt_text](https://github.com/TahaMunir2/RISC-V-RV32IM-FPGA/blob/main/images/asms.png)

These were the instructions I added:

| # | Mnemonic | Type | Opcode | Brief Description |
|---|----------|------|--------|-------------------|
| 1 | `ADD` | R | `0110011` | Register-register add |
| 2 | `LBU` | I | `0000011` | Load zero-extended byte |
| 3 | `JALR` | I | `1100111` | Jump to rs1 + imm, save return address |
| 4 | `SB` | S | `0100011` | Store byte to memory |
| 5 | `JAL` | J | `1101111` | PC-relative jump, save return address |
| 6 | `LUI` | U | `0110111` | Load 20-bit upper immediate |

And they required minor/major revamps of almost all the modules we defined in lab 4 (thoroughly explained in the README above).

#### PC Block:

```systemverilog
always_ff @(posedge clk)
    if (rst) internal_pc <= 32'hBFC00000;
    else begin
        case (pc_src)
            2'b00: internal_pc <= inc_pc;    // PC + 4
            2'b01: internal_pc <= branch_pc; // Branch and JAL
            2'b10: internal_pc <= ALU;       // JALR 
            default: internal_pc <= inc_pc;  
        endcase
    end
assign pc = internal_pc;
```

- I had to add a case statement for the different values pc_next can take, depending on the type of instruction currently being executed
- For the JAL and JALR instructions, I also had to add functionality to "save" the **`pc`** address.

#### Control:

I assigned the appropriate control signals for each of the new instructions, taking care to make sure we weren't accidentally interfering with other instructions or registers/memory addresses when we weren't meant to.

I also had to add a new output:
```systemverilog
 ByteWrite = 0; // determines if we are doing word(0) or byte(1) logic
```

#### ALU:

I had to just add more functionality in the case statement:

```systemverilog
    3'b000 : ALUout = ALUop1 + ALUop2; // add
    ...
    3'b100: ALUout = ALUop2; // for LUI
```

- I just passed ALUop2 through the ALU to let it writeback into the register instead of adding an output from the sign extender to the regfile.

#### Sign Extender:

```systemverilog
    else if (ImmSrc == 3'b001) begin // for S instructions
        immext = {{20{instr[31]}}, instr[31:25], instr[11:7]};
    end
    else if (ImmSrc == 3'b100) begin // for U instructions
        immext = {{instr[31:12]}, 12'b0};
    end
    else if (ImmSrc == 3'b011) begin  // for J instructions
        immext = {{12{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};
    end
end
```

I added the following cases in the signextender block for it to be able to understand the new instruction types we added in accordance with the table below:

![diagram](https://github.com/TahaMunir2/RISC-V-RV32IM-FPGA/blob/main/images/functions.png)

#### Data Memory:

For lab 4, we only defined the logic to load a word from the RAM; however, now we need to handle store instructions and byte addressing.

##### Read Logic

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

##### Write Logic

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

---

### Pipelining

For pipelining, my work was simpler; I simply had to pass the registers through if there was no stall active and then flush the content if we needed to flush for branch instructions. I can demonstrate this by just showing my Fetch to Decode pipeline register:

```systemverilog
    always @(posedge clk) begin
        if (rst || flush) begin
            instr_d <= 32'h00000033;
            pc_d <= 0;
            pc_save_d <= 0;
        end
        
        else if(enable) begin
            instr_d <= instr_f;
            pc_d <= pc_f;
            pc_save_d <= pc_save_f;
        end
    end
```
- For stalls, we simply make enable low so the pipeline register maintains its old values for 1 more cycle.
- In the case of a flush, we want to send a no-op out, so we send out the instruction for ADDI x0, x0, 0.
- We treat rst as the same as flushing the CPU.

This was repeated for the rest of the pipeline registers.

---

### Z Extensions:

I wrote the full documentation of this section. For more details, see the [GitHub README](https://github.com/TahaMunir2/RISC-V-RV32IM-FPGA/blob/Z-extensions/README.md).

I noticed that CSR instructions were omitted on the project brief from the full RV32I implementation, so I did some research into them and found out they are sometimes referred to as the Zicsr extension and are used to implement interrupts by utilising a Control Status Register module.

The control shift register is a register of a fixed size, much larger than the register we use in the reg file module, and has special registers with each register having a special name, purpose and way of handling, unlike the general-purpose registers we use in regfile. The registers are used for a variety of purposes, such as handling interrupts (as discussed in the Interrupts and FPGA branch), managing privilege levels, measuring time/performance, and identifying hardware, among others.

The Zicsr instructions are implemented with the CSR to read from it and write to it. All Zicsr instructions are atomic read-modify-write instructions, as in they read the old value of the control status register into rd and modify rd all in 1 instruction. In contrast, if we wanted to do this with our normal registers, it would require 2 instructions, one to copy and one to write. There are 6 Zicsr instructions csrrw, csrrs, csrrc, csrrwi, csrrsi and csrrci, with the latter 3 being immediate (instead of register) versions of the first 3. Each instruction has a CSR register (that will be both the source and the destination), a destination register that will get the old value of that CSR, and either a source register or a 5-bit unsigned immediate that will be used for determining the new value of that CSR, as shown below:

| Instruction | funct3 | Operation |
|-------------|--------|-----------|
| CSRRW | 001 | rd = CSR[addr], CSR[addr] = rs1 |
| CSRRS | 010 | rd = CSR[addr], CSR[addr] = CSR[addr] \| rs1 |
| CSRRC | 011 | rd = CSR[addr], CSR[addr] = CSR[addr] & ~rs1 |
| CSRRWI | 101 | rd = CSR[addr], CSR[addr] = uimm[4:0] |
| CSRRSI | 110 | rd = CSR[addr], CSR[addr] = CSR[addr] \| uimm[4:0] |
| CSRRCI | 111 | rd = CSR[addr], CSR[addr] = CSR[addr] & ~uimm[4:0] |


The logic for these was implemented as shown below:

```systemverilog
always_comb begin
        temp = dout;
        case(CSR_OP)
            2'b01: temp =  wd; // CSRRW(I)
            2'b10: temp = temp | wd;   // CSRRS(I)  
            2'b11: temp = temp & (~wd); // CSRRC(I)
            default: temp = dout;
        endcase
    end
```

This was done inside a new module called CSR, which started with instantiating a register of size 4096:

```systemverilog
  logic[DATA_WIDTH-1:0] csr_array [CSR_WIDTH-1:0];
```

Key Points:
- As CSR instructions are atomic, we had to modify our stall logic to check for data dependencies in CSR instructions.
- I would modify this file to make the CSRs more special in the next extension.
- I had to add a new ALU Source MUX at the top, which determined if ALUop1 was an imm or register value for CSR instructions ending with an I.
- I also had to modify the Sign Extension block to properly extend the 5-bit unsigned immediate.
- I also had to modify the control path to handle these new instructions.

I also added Zba instructions while I was at it, as they seemed quite easy and helped simplify shift and add instructions into just 1 atomic instruction:

![diagram](https://github.com/TahaMunir2/RISC-V-RV32IM-FPGA/blob/main/images/zba_instructions.png)

---

### Interrupts and FPGA:

This was the hardest yet most rewarding thing I designed for this project. I was able to port our pipelined CPU with the Z extension onto an FPGA, as well as add a trap handler for 2 types of interrupts: timer and external (trigger) interrupts and design a 4-state FSM to run the F1 lights in assembly utilising the functionality of our interrupts. 

Due to the extreme depth of the implementation, please refer to: [GitHub README](https://github.com/TahaMunir2/RISC-V-RV32IM-FPGA/blob/Interrupts-and-FPGA/README.md).
> This part is not easily summarisable as changes and additions were required in almost every part of the CPU, so please look at my thorough breakdown of the FPGA implementation for this section.

#### Design Decisions:
- I chose to add 2 types of outputs, the 7-segment displays and the LEDs, to show how our CPU could handle multiple outputs, as well as 2 types of interrupts to demonstrate the robustness of our design.
- I wanted to make sure our CPU wasn't only an output circuit but was also responsive to inputs, so I changed trigger to be key[0] on the FPGA and utilised the trap handler to deal with I/O as an actual CPU would, instead of how trigger is described in the project brief.
- I chose to use MMIO due to our memory map practically inviting us to make use of the unmapped space between RAM and ROM.
- I removed M instructions due to our simulated circuit lacking multi-cycle divide logic (as division is extremely complex on real hardware).
- I removed the branch predictor as its logic almost completely broke with our synchronous read.
- I chose to implement the F1 Lights FSM as it was made in the EEE labs using simply an FSM defined in SystemVerilog, and I wanted to push myself to make an assembly program to run the same logic on our actual CPU that had been ported onto the same FPGA.

#### F1 FSM Video
https://github.com/user-attachments/assets/2adacb26-7459-44d5-94f8-997369829358

---

## Mistakes

Although we were able to achieve so much in just a few weeks, we were still prone to many mistakes and learning opportunities. For example, at the start, we struggled with task delegation. I found myself having to do the majority of the work for lab 4 and the single cycle, which led to the CPU mostly developing under my design philosophy and the others having trouble catching up with all the changes I made. We were able to better understand how to delegate tasks as the project went o,n to more fairly distribute the workload so everyone was able to understand what was changing in our CPU.

I also did not fully utilise gtkWave at first, choosing to only use it as a last resort when test benching lab 4; however, I quickly realised how brilliant it was, especially after we pipelined our CPU and broke the signals into dozens upon dozens of wires.

I also found developing on the FPGA extremely daunting and wish I had spent more time initially trying to understand FPGAs by using the CAS labs as a reference instead of trying to jump right in. After the first day of hopelessly wandering through the Quartus interface I quickly realised I needed to take time to research it, so I did, instead of skipping to the fun part and found it very useful to use the EEE Year 2 resources as guidance on how to get started.

---

## Reflection

Overall, we achieved a lot more than we could have ever imagined in this project and I am proud of my contributions as well as the work of the group overall. Going in 3 of us had already worked together quite a bit in projects last year so we were quite familiar with each other as project partners and knew we were compatible and this project helped solidify that belief, by the end of the project we were spending 10 hours straight in the EEE building all designing debugging and planning together. 

I tried pushing our learning to the absolute limits of what we were taught implementing all of what we were suggested to do in the lectures; such as branch prediction, split heirarchical cache and superscalar as well as stuff we were told probably wasn't worth our time such as porting onto FPGA and we were also able to tie in concepts from other modules like software for the trap handler and synchronisation of the interrupts. I learnt a lot about researching as well as planning and organising my thoughts before jumping into a design.

If we had more time, I would have probably focused on implementing the rest of the extensions onto our FPGA by adding a branch predictor with a buffer, adding cache and implementing appropriate stalls for division instructions and taking advantage of DSP for multiplication. I could have also added more inputs to our CPU, such as using the 10 switches on the FPGA to have different MMIO usecases. Perhaps I could have added software interrupts and exceptions as well to further expand the utility of our Control Status Register, as in a completely RISC-V implementation, it has a very wide array of functionality. However, given the time restraints of the project, I am very satisfied with all that I was able to accomplish. 

