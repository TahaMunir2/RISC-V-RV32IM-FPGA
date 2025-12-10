# Single Cycle Reduced RV32I CPU:

## Table of Contents
- [1 Overview](#overview)
- [2 Implementation](#implementation)
- [3 Schematic](#schematic)
- [4 Testing](#testing)

## Overview

This section goes over the baseline foundation of our RV32I CPU. Working on the single-cycle CPU gave our team an introduction to working with each other and designing and testing a CPU using SystemVerilog and shell script testing environments. Our single-cycle CPU implements the following 9 instructions:


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


#### Inputs:
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

### Registers

The registers are made using a much smaller array of 32 32-bit registers used by the instructions. 

#### Read Logic:
```systemverilog
    always_comb begin
        RD1= regfile_array[AD1];
        RD2= regfile_array[AD2];
        A0 = regfile_array[10];
        regfile_array[0] = 0;
    end
```
- We have 2 read ports for the register
- A0 is connected to x10 and is our output port
- x0 is always 0 in RISCV

#### Write Logic


## Schematic

![alt text](https://github.com/TahaMunir2/Team5/blob/single-cycle-cpu/images/Modified%20Single%20Cycle%20CPU%20diagram.jpg)

## Testing
https://github.com/user-attachments/assets/36d3a1a0-e795-473e-b112-f805138e5dc2

