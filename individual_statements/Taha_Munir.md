
## Overview

My main contributions in chronological order were:
- Test Benching and Top-level integration for Lab 4
- Implementing all 6 instructions for the Single Cycle CPU
- Designing the Pipeline Registers
- Designed L1d and L1i cache
- Zicsr and Zba Extensions
- FPGA and Interrupts

I was also the GitHub "repo master" and although I did try to keep on top of keeping our GitHub structure organised and cleaning up redundant files and folders, especially at the end, this was a responsibility that was shared with the whole group, and I shared my ideas to make sure everyone had the same approach to using our GitHub.

---

## Implementation

---

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

---

### Pipelining

```systemverilog

```

## Mistakes

## Reflection

