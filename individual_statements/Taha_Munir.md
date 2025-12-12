
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

![alt_text](https://github.com/TahaMunir2/Team5/blob/main/images/units.png)

With each test bench thoroughly testing the full functionality of the block:

![alt_text](https://github.com/TahaMunir2/Team5/blob/main/images/pc_tb.png)
> Example: Testbench for PC block.

To make the testbenches, I used the 2 reference test benches we were given and spent a lot of time combing through the header files to try and fully understand how to best utilise the tools we had available to most thoroughly and efficiently troubleshoot our design for the many, many mistakes we were bound to make. I standardised an approach for our whole group where we would add unit test benches the first time we would integrate a new block into the circuit, and then using CPU wide testbenches for that block going forward. This was a healthy balance between thorough testing and time efficiency.

For the top-level integration, I used this schematic provided to use in the project brief as a reference:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/microarchitecture.jpg)

---

### Single Cycle:

I wrote the full documentation of this section. For more details, see the [GitHub README](https://github.com/TahaMunir2/Team5/blob/single-cycle-cpu/README.md).

For this section, my primary responsibility was to add the 6 additional instructions such that we were able to pass the 5 reference programs provided to us in the project brief:

![alt_text](https://github.com/TahaMunir2/Team5/blob/main/images/asms.png)

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

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/functions.png)

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

### Z Extensions:

I wrote the full documentation of this section. For more details, see the [GitHub README](https://github.com/TahaMunir2/Team5/blob/Z-extensions/README.md).

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

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/zba_instructions.png)

### Interrupts and FPGA:

This was the hardest yet most rewarding thing I designed for this project. I was able to port our pipelined CPU with the Z extension onto an FPGA, as well as add a trap handler for 2 types of interrupts: timer and external (trigger) interrupts and design a 4-state FSM to run the F1 lights in assembly utilising the functionality of our interrupts. 

Due to the extreme depth of the implementation, please refer to: [GitHub README](https://github.com/TahaMunir2/Team5/blob/Interrupts-and-FPGA/README.md).
> This part is not easily summarisable as changes and additions were required in almost every part of the CPU, so please look at my thorough breakdown of the FPGA implementation.

#### Design Decisions:
- I chose to add 2 types of outputs, the 7-segment displays and the LEDs, to show how our CPU could handle multiple outputs, as well as 2 types of interrupts to demonstrate the robustness of our design.
- I wanted to make sure our CPU wasn't only an output circuit but was also responsive to inputs, so I changed trigger to be key[0] on the FPGA and utilised the trap handler to deal with I/O as an actual CPU would, instead of how trigger is described in the project brief.
- I chose to use MMIO due to our memory map practically inviting us to make use of the unmapped space between RAM and ROM.
- I removed M instructions due to our simulated circuit lacking multi-cycle divide logic (as division is extremely complex on real hardware).
- I removed the branch predictor as its logic almost completely broke with our synchronous read.
- I chose to implement the F1 Lights FSM as it was made in the EEE labs using simply an FSM defined in SystemVerilog, and I wanted to push myself to make an assembly program to run the same logic on our actual CPU that had been ported onto the same FPGA.

#### F1 FSM Video
https://github.com/user-attachments/assets/2adacb26-7459-44d5-94f8-997369829358

## Mistakes

## Reflection

