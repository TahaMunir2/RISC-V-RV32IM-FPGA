# Taha Munir (02562044) Individual Statement

## Table of Contents

- [Overview](#overview)
- [Implementation](#implementation)
  - [Lab 4](#lab-4)
  - [Single Cycle](#single-cycle)
  - [Pipelining](#pipelining)
  - [Z Extensions](#z-extensions)
  - [Interrupts and FPGA](#interrupts-and-fpga)
- [Mistakes](#mistakes)
- [Reflection](#reflection)

---

## Overview

My main contributions were:
- Designing the control path for Lab 4
- Implementing L1d and L1i cache
- Test Benching the L1d and L1i cache
- Implementing the L2 cache
- Test Benching the L2 cache

I also wrote the full documentation of the cache section, which goes into much more detail about how the cache works. The file can be found here: [Cache README](https://github.com/TahaMunir2/Team5/blob/Hierarchical-cache/README.md)

---

## Implementation

### Lab 4

For Lab 4, we decided our roles using a random wheel. I was given the task of designing the part of the control path of the reduced RISC-V processor, including the instruction memory (which we decided to use a ROM block for), the control unit, and the sign extender. The components that I created are highlighted in green below:

![alt_text](https://github.com/TahaMunir2/Team5/blob/main/images/reducedRV.png)

It is, however, important to note that I did not testbench this code and that multiple bug fixes had to be made to the components that I created. Also, since Lab 4 was only using addi and bne instructions, i only implemented the addi and bne instructions to the decoder, and not the full RISC-V instruction set.

---

### L1d and L1i cache

Initially, my goal for this section was to create the cache array for the i cache and d cache, which were 2-way associative caches that included a valid bit in each block, and a used bit (for LRU replacement policy) in each set.

I intended for the blocks to mirror the image below:
![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/cache_array.png)

I intended for the instruction cache array to be able to load data from L2 on command, supply data to the processor when requested, and update its valid and dirty bits as directed by the cache controller. The controller would have specified the set, block offset, transfer size, and whether a read or write is enabled.

The data cache array was originally intended to support the same operations as the instruction cache array (and more), taking direction from the cache controller. In addition to the previously defined functions, each block would have a dirty bit that was going to be updated based on whether the write originated from L2 or the processor, and the array would implement a writeback mechanism to return dirty data to the L2 cache.

However, after my teammates designed the L1i and L1d cache controller, we decided to implement both the cache array and cache controller on the same SystemVerilog module, as it would be easier to understand from a top level view. Additionally, the cache controller required quite a few internal signals from the cache array, so placing both components on the same sheet made it easier to access these values directly without routing them out of the array as outputs.

Thus, after I finished the L1i and L1d cache array, and my teammates finished the cache controller, we integrated both onto the same .sv file.

---

### L1i and L1d cache testbenching

After completing both the L1i and L1d cache, I was tasked with testing them. This was my first testbenching experience for this project, so I turned to my teammates for help in getting started. This helped me learn how to testbench much more quickly compared to the time it would take if I learned by myself.



---

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

---

### Interrupts and FPGA:

This was the hardest yet most rewarding thing I designed for this project. I was able to port our pipelined CPU with the Z extension onto an FPGA, as well as add a trap handler for 2 types of interrupts: timer and external (trigger) interrupts and design a 4-state FSM to run the F1 lights in assembly utilising the functionality of our interrupts. 

Due to the extreme depth of the implementation, please refer to: [GitHub README](https://github.com/TahaMunir2/Team5/blob/Interrupts-and-FPGA/README.md).
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


