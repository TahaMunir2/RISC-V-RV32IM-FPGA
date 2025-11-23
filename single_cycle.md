# Lab 4

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


# Challenges




