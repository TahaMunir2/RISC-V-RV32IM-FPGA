# Zicsr and Zba Extensions

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
    - [2.1 Zicsr](#21-zicsr)
        - [Control Status Register](#control-status-register)
        - [Decoder](#decoder)
        - [Immediate MUX](#immediate-mux)
        - [Sign Extension](#sign-extension)
        - [Hazard Unit](#hazard-unit)
    - [2.2 Zba](#22-zba)
        - [Decoder](#decoder-1)
        - [ALU](#alu)
    - [2.3 Top-Level Integration](#23-top-level-integration)
- [3. Schematic](#3-schematic)
- [4. Testing and Verification](#4-testing-and-verification)
    - [Zicsr Testbench](#zicsr-testbench)
    - [Zba Testbench](#zba-testbench)

---

## 1. Overview

We decided to implement 2 new extensions, the Zicsr extension, which entailed adding a Control Shift Register module and 6 new instructions, as well as the Zba extension, which introduced 3 new instructions used for Bit-Manipulation.

The control shift register is a register of a fixed size, much larger than the register we use in the reg file module, and has special registers with each register having a special name, purpose and way of handling, unlike the general-purpose registers we use in regfile. The registers are used for a variety of purposes, such as handling interrupts (as discussed in the Interrupts and FPGA branch), managing privilege levels, measuring time/performance, and identifying hardware, among others. The Zicsr instructions are implemented with the CSR to read from it and write to it. All Zicsr instructions are atomic read-modify-write instructions, as in they read the old value of the control status register into rd and modify rd all in 1 instruction. In contrast, if we wanted to do this with our normal registers, it would require 2 instructions, one to copy and one to write. There are 6 Zicsr instructions csrrw, csrrs, csrrc, csrrwi, csrrsi and csrrci, with the latter 3 being immediate (instead of register) versions of the first 3. Each instruction has a CSR register (that will be both the source and the destination), a destination register that will get the old value of that CSR, and either a source register or a 5-bit unsigned immediate that will be used for determining the new value of that CSR, as shown below:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/ZICSR.jpg)

The Zba instructions are also atomic in the sense that they reduce shifting and adding into 1 instruction. They are called sh1add, sh2add and sh3add, which are shortened versions of shift and add. They operate on the normal registers and not on the CSR registers, and are just a simple way to make programs more efficient.

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/zba_instructions.png)

## 2. Implementation

### 2.1 Zicsr

#### Control Status Register

We define a module called CSR, which will go in the execution stage of the pipeline. 


##### Parameters

```systemverilog
parameter ADDRESS_WIDTH = 12,
parameter DATA_WIDTH = 32,
parameter CSR_WIDTH = 4096
```

- **`REGFILE_WIDTH = 4096`**: Standard number of Control Status Registers in an ideal RV32I implementation
- **`ADDRESS_WIDTH = 12`**: 2^12 = 4096 hence there are 12 address bits.


##### Initialisation

```systemverilog
  logic[DATA_WIDTH-1:0] temp;
  logic[DATA_WIDTH-1:0] csr_array [CSR_WIDTH-1:0];
  assign dout = csr_array[addr];
```
- **`temp`**: A variable to temporarily hold the new value of the CSR, as we have a synchronous write
- **`dout = csr_array[addr]`**: We first assign the initial value of the CSR to be stored into the destination register.


##### Zicsr Logic

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


#### Decoder

We had to update the control module to be able to handle CSR instructions.

```systemverilog
 OPC_CSR: begin
                csr_type = funct3[1:0];
                ALUSrc3 = funct3[2];

                if(funct3 == 3'b001) RegWrite = 1'b1; // CSSRW
                if(funct3 == 3'b010) RegWrite = 1'b1; // CSSRS
                if(funct3 == 3'b011) RegWrite = 1'b1; // CSSRC
                
                if(funct3 == 3'b101) begin // CSSRWI
                    RegWrite = 1'b1;
                    ImmSrc = 3'b101; // for CSR--I instructions
                end
                
                if(funct3 == 3'b110) begin // CSSRSI
                    RegWrite = 1'b1;
                    ImmSrc = 3'b101;
                end 
                
                if(funct3 == 3'b111) begin // CSSRCI
                    RegWrite = 1'b1;
                    ImmSrc = 3'b101; 
                end
            end
```

- We started by defining the OP Code for CSR instructions as **`OPC_CSR = 7'b1110011;`** at the top of the control module.
- As shown in the diagram below, the bottom 2 bits of funct3 in CSR instructions can be used to distinguish the type of CSR instruction, and the top bit can be used to determine if it uses an immediate or RS1, which is controlled by **`ALUSrc3`**
- For the non-immediate instructions, we can simply just do **`RegWrite = 1'b1`** as we only need to write into the destination register
- We control the sign extension done on the 5-bit immediate by **`ImmSrc`** for the I-type CSR instructions, with them reserving the code **`3'b101`**.

    | funct3 | Instruction |
    |--------|-------------|
    | **001** | CSRRW |
    | **010** | CSRRS |
    | **011** | CSRRC |
    | **101** | CSRRWI |
    | **110** | CSRRSI |
    | **111** | CSRRCI |

#### Immediate MUX

We place a MUX before the CSR module to determine the value of **`wd`**.

| ALUSrc3 | Output | Insutrctions |
|---------|--------|--------------|
| 0 | RS1 | CSRRW/CSRRS/CSRRC |
| 1 | 0-Extended 5-bit Imm | CSRRWI/CSRRSI/CSRRCI |


#### Sign Extension

We also added this case in the Sign Extension module to deal with the 5-bit unsigned immediate.

```systemverilog
    else if(ImmSrc == 3'b101) begin
        immext = {27'b0, instr[19:15]};
    end
```

#### Hazard Unit

We need to add brand new Hazard logic for this new CSR module. Now, since we are atomically reading and writing, the simplest way of dealing with forwarding is to implement stalls if there are any data dependencies. 

```systemverilog
assign csrStall = (|csr_typeD) && ( // check if the current instruction is csr type
                    ( (|csr_typeE) && (csr_addrE == csr_addrD)) || // check if the one before was csr and had data dependancies
                        ( (|csr_typeM) && (csr_addrM == csr_addrD)) ||  // check if the one in memory stage was csr and had data dependancies
                            ( (|csr_typeW) && (csr_addrW == csr_addrD)) // check the one in writeback
                    );
```

And then we can keep our current stall logic and just OR **`wStall`** with **`csrStall`**.

### 2.2 Zba

#### Decoder:


```systemverilog
else if (funct7 == 7'b0010000) begin // sh1add
                        RegWrite = 1;
                        ALUCtrl = 5'b10100;
                    end         
```

For Zba instructions, all we had to do was set RegWrite and assign new ALUCtrl signals for each instruction.

| funct7 | funct3 | Instruction |
| :--- | :--- | :--- |
| 0010000 | 010 | sh1add |
| 0010000 | 100 | sh2add |
| 0010000 | 110 | sh3add |

#### ALU:

These were the only changes we had to make for the Zba instructions in the ALU, with **`<<`** meaning shift left.

```systemverilog
        5'b10100: ALUout = (ALUop1 << 1) + ALUop2; // sh1add
        5'b10101: ALUout = (ALUop1 << 2) + ALUop2; // sh2add
        5'b10110: ALUout = (ALUop1 << 3) + ALUop2; // sh3add
```

### 2.3 Top-Level Integration

The main challenge was working out where to put this new CSR module. It made the most sense to integrate it into the Execute stage with the ALU, as it also operates on the regular registers, so we would not need to change any of the forwarding logic, as it is essentially an extended version of the ALU, but with its own register that only it deals with.

```systemverilog
    csr csr ( // belongs in the execute stage
        .clk(clk),
        .CSR_OP(csr_typeE),
        .addr(csr_addrE),
        .en(|csr_typeE), // as all csr_type instructions have write in them and none correspond to 00
        .wd(CSR_write),
        .dout(CSR_read)
    );
```
Beyond this, we only needed to add a few lines to the Hazard unit for the CSR addresses and enables, and one new line out of the control unit called **`csr_type`**.

## 3 Schematic

## 4 Testing and Verification

### Zicsr Testbench

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/csr_tb.png)

- Line 6: We set x1 to 12345678 and csr[340] to 12345678 with t1 by running csr read and write
- Line 8: We use csr read and set with t2, which is 0000FFFF to set the bottom 2 bytes to 1, so csr[340] = 1234FFFF
- Line 10: We use csr read and clear with t3, which is 000000FF to clear the bottom byte to 0 to get csr[340] = 1234FF00
- Line 11: We use csr read and ser with x0 (0) to just copy csr[340] into a0, so a0 = 1234FF00

Each time we are saving csr[340] into x1, so we can trace the waveforms to check it's actually changing correctly (note: t1 = reg[6], t2 = reg[7], t3 = reg[28]) as shown below:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/gtkwave.png)

### Zba Testbench

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/shadd_tb.png)


We ran the following assembly code to test out the Zba functionality. Notably, we had to add a line at the top of the file to allow the compiler to accept the Zba instructions **`.option arch, +zba`**.

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/zba_gtkwave.png)


As we can see, a0 goes from 135 (0x87) to 263 (0x107) to 519 (0x207), and each operation takes 1 clock cycle, whereas without these instructions it would be spread out over 2 cycles.


