# Lab 4

|Table of Contents    |
|:-------------------:|
|[Introduction](#introduction)         |
|[Design Implementation](#designimplementation)|
|[Challenge](#challenge)            |

# Introduction
Lab 4 laid out the basic foundation of our RISC-V CPU, and helped us ease into using GitHub and working as a team.

In this lab, we were able to create the basic components of the CPU and combine them all together in a top-level module, along with making test benches for each module and adding functionality for ADDI and BNE instructions, with the hierarchy specified in the image below:

![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/microarchitecture.jpg)

# Design Implementation Setbacks
There were a few problems that we ran into in this task:
* Inconsistent input and output logic names across the team.
* Integrating all of the modules into a singular top-level module.
* Other minor bug fixes and errors.
* Learning how to testbench.
* Making the ROM too big (2^32) and the code not compiling.

Thankfully though, this lab proved not to be too difficult, allowing us to prepare our skills in these areas before taking on harder tasks.

# Challenge
As a challenge, we decided to implement a RAM of size 2^17 alongside our existing ROM and the load word instruction in our design. This was done using the datamem.sv. This required adding output to the control module, which selected the output of a MUX after the ALU. We added a testcase in verify.cpp to test out that the RAM worked, along with a test bench for the datamem module.



