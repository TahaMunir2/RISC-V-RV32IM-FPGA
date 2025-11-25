# Basic Single-Cycle RV32I Design

|Table of Contents    |
|:-------------------:|
|[Introduction](#introduction)         |
|[Design Implementation](#designimplementation)|
|[Challenges](#challenges)            |

# Introduction
This lab required introducing 6 more instructions (LBU, LUI, JALR, JAL, ADD, SB) to our functioning CPU from Lab 4 and creating an assembly file to run the F1 lights from Lab 3.

In this lab, we had to modify all the hardware to be compatible with the new instructions as we needed to implement J, U, S, and I-type instructions. Below is an edited version of the diagram provided in the project brief, showing our modifications to the CPU for the single-cycle CPU.

![alt text](https://github.com/TahaMunir2/Team5/blob/single-cycle-cpu/images/Modified%20Single%20Cycle%20CPU%20diagram.jpg)

# Design Implementation:

* We modified the Control module by expanding the bits for PCSrc, ResultSrc and ImmSrc, as well as adding an output called ByteWrite as well and adding decoding logic for our 6 new instructions.
* The MUX for the PC module was expanded for the JALR instruction, allowing us to choose rs1 + Imm.
* The MUX after the datamem module was expanded, allowing us to store the value of the next PC for JALR and JAL instructions.
* A new input called ByteWrite was added to the datamem module to determine if we are working on bytes or whole words for LBU and SB instructions, and we adjusted the module to start reading from 10000 according to the memory structure provided in the brief.
* The signext module had 2 new cases added to it for dealing with U and J-type instructions.
* The ALU had new cases added to it based on the basic ones provided on the slides, and an additional one to allow the output to just be ALUop2 for the LUI instruction.

Overall, this lab proved to be quite challenging as it required rethinking our design for the CPU; however, it improved our understanding of how to expand its capabilities for the future.

# Challenges

* It took quite a while to work out what the different types of instructions mean and how to implement them differently. 
* Some things, such as adding ALUCtrl for letting ALUop2 pass, took quite a bit of time to work out.
* I kept running into an issue with pdf.s where I would get 200 instead of the expected value because I forgot to implement the correct memory structure and was reading the instructions from the start and not the offset
* Small issues like forgetting to write the size of pc_save in top.sv, which led to it not working properly




