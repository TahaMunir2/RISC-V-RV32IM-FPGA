# Lab 4

|Table of Contents    |
|:-------------------:|
|[Introduction](#introduction)         |
|[Design Implementation](#designimplementation)|
|[Challenges](#challenges)            |

# Introduction
This lab required introducing 6 more instructions (LBU, LUI, JALR, JAL, ADD, SB) to our functioning CPU from Lab 4 and creating an assembly file to run the F1 lights from Lab 3.

In this lab, we had to modify all the hardware to be compatible with the new instructions as we needed to implement J, U, S, and I-type instructions. Below is an edited version of the diagram provided in the project brief, showing our modifications to the CPU for the single-cycle CPU.
![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/microarchitecture.jpg)

# Design Implementation Setbacks
There were a few problems that we ran into in this task:
* Inconsistent input and output logic names across the team.
* Integrating all of the modules into a singular top-level module.
* Other minor bug fixes and errors.
* Learning how to testbench.
* Making the ROM too big (2^32) and the code not compiling.

Thankfully, though, this lab proved not to be too difficult, allowing us to prepare our skills in these areas before taking on harder tasks.

# Challenge
As a challenge, we decided to implement a RAM of size 2^17 alongside our existing ROM and the load word instruction in our design. This was done using the datamem.sv. This required adding output to the control module, which selected the output of a MUX after the ALU. We added a testcase in verify.cpp to test out that the RAM worked, along with a test bench for the datamem module.



