# Zicsr and Zba Extensions

## Table of Contents
- [1. Overview](#1-overview)


---

## 1. Overview

We decided to implement 2 new extensions, the Zicsr extension, which entailed adding a Control Shift Register module and 6 new instructions, as well as the Zba extension, which introduced 3 new instructions used for Bit-Manipulation.

The control shift register is a register of a fixed size, much larger than the register we use in the reg file module, and has special registers with each register having a special name, purpose and way of handling, unlike the general-purpose registers we use in regfile. The registers are used for a variety of things, such as handling interrupts (as discussed in the Interrupts and FPGA branch), privilege levels, measuring time/performance and identifying hardware, just to name a few. The Zicsr instructions come




Testbench info:

We set x1 to 12345678 and csr[340] to 12345678 with t1 by running csr read and write

We use csr read and set with t2 which is 0000FFFF to set the bottom 2 bytes to 1 so csr[340] = 1234FFFF

We use csr read and clear with t3 which is 000000FF to clear the bottom byte to 0 to get csr[340] = 1234FF00

We use csr read and ser with x0 (0) to just copy csr[340] into a0 so a0 = 1234FF00

![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/csr_tb.png)

Each time we are saving csr[340] into x1 so we can trace it to check its actually changing correctly as shown below:

![alt text](https://github.com/TahaMunir2/Team5/blob/main/images/gtkwave.png)
