# Zicsr and Zba Extensions

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)


---

## 1. Overview

We decided to implement 2 new extensions, the Zicsr extension, which entailed adding a Control Shift Register module and 6 new instructions, as well as the Zba extension, which introduced 3 new instructions used for Bit-Manipulation.

The control shift register is a register of a fixed size, much larger than the register we use in the reg file module, and has special registers with each register having a special name, purpose and way of handling, unlike the general-purpose registers we use in regfile. The registers are used for a variety of purposes, such as handling interrupts (as discussed in the Interrupts and FPGA branch), managing privilege levels, measuring time/performance, and identifying hardware, among others. The Zicsr instructions are implemented with the CSR to read from it and write to it. All Zicsr instructions are atomic read-modify-write instructions, as in they read the old value of the control status register into rd and modify rd all in 1 instruction. In contrast, if we wanted to do this with our normal registers, it would require 2 instructions, one to copy and one to write. There are 6 Zicsr instructions csrrw, csrrs, csrrc, csrrwi, csrrsi and csrrci, with the latter 3 being immediate (instead of register) versions of the first 3. Each instruction has a CSR register (that will be both the source and the destination), a destination register that will get the old value of that CSR, and either a source register or a 5-bit unsigned immediate that will be used for determining the new value of that CSR, as shown below:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/ZICSR.jpg)

The Zba instructions are also atomic in the sense that they reduce shifting and adding into 1 instruction. They are called sh1add, sh2add and sh3add, which are shortened versions of shift and add. They operate on the normal registers and not on the CSR registers, and are just a simple way to make programs more efficient.


## 2. Implementation

### 2.1 Control Status Registers

We define a module called CSR, which will go in the execution stage of the pipeline. 


### Parameters

```systemverilog
parameter ADDRESS_WIDTH = 12,
parameter DATA_WIDTH = 32,
parameter CSR_WIDTH = 4096
```

- **`REGFILE_WIDTH = 4096`**: Standard number of Control Status Registers in an ideal RV32I implementation
- **`ADDRESS_WIDTH = 12`**: 2^12 = 4096 hence there are 12 address bits.

### Initialisation

```systemverilog
  logic[DATA_WIDTH-1:0] temp;
  logic[DATA_WIDTH-1:0] csr_array [CSR_WIDTH-1:0];
  assign dout = csr_array[addr];
```
- **`temp`**: A variable to temporarily hold the new value of the CSR, as we have a synchronous write
- **`dout = csr_array[addr]`**: We first assign the initial value of the CSR to be stored into the destination register.

### Zicsr Logic

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
- **`wd`** can either be RS1 or a 5-bit unsigned intermediate, depending on whether the instruction has I at the end or not.
- **`CSR_OP`**: A 2-bit logic that comes from the decoder that simply tells us what type of CSR instruction is going on
- **`2'b01: temp =  wd`**: CSRRW stands for **Control Status Register Read and Write**, and you simply **read** the value into rd and **write** the value of either the imm or RS1 into the CSR.
- **`2'b10: temp = temp | wd`**: **CSRRS stands for Control Status Register Read and Set**, and you do the same **read** as before but for writing, you go through all the bits in wd and if they are high than the corresponding bit in temp will also be **set** (the rest of the bits are untouched), this can be simplified into an OR operation.
- **`2'b11: temp = temp & (~wd)`**: CSRRC stands for **Control Status Register Read and Clear**, and you do the same **read** as always, but now you go through the bits of wd and if a bit is high, then you **clear** the corresponding bit in the CSR this is the same as an & operation but with **`wd`** inverted.

Testbench info:

We set x1 to 12345678 and csr[340] to 12345678 with t1 by running csr read and write

We use csr read and set with t2 which is 0000FFFF to set the bottom 2 bytes to 1 so csr[340] = 1234FFFF

We use csr read and clear with t3 which is 000000FF to clear the bottom byte to 0 to get csr[340] = 1234FF00

We use csr read and ser with x0 (0) to just copy csr[340] into a0 so a0 = 1234FF00

![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/csr_tb.png)

Each time we are saving csr[340] into x1 so we can trace it to check its actually changing correctly as shown below:

![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/gtkwave.png)
