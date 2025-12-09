# Interrupts and FPGA

## Table of Contents
- [1. Overview](#overview)

## Overview

### Interrupts

We previously defined a CSR module and added some instructions to play around with the CSR's however, we also mentioned how each register has a special predetermined purpose and can be used for a variety of use cases. The use case we will delve into is **interrupts**, as these enable our CPU to interact with the outside world and also add additional functionality to our CPU. 

Let's start by talking about privilege levels. There are 3 privilege levels in the RV32I CPU: Machine Mode (highest privilege), Supervisor and User (lowest privilege). Depending on the privilege level that the CPU is currently in, certain CSRs might not be available, as they are only available to high privilege levels for security purposes; however, Machine mode can access all the CSRs. For this project, we can assume that we are always in Machine Mode and no other privilege level exists on our CPU; hence, the registers we define are exclusive to M-mode and would theoretically not be available in lower privilege levels. This also means we do not need to deal with complex ideas such as delegations. 

Next, let's talk about the trap handler. The trap handler is a specific piece of code stored somewhere on the instruction memory, and it is only accessed when a "trap" is called. There are technically multiple different trap handlers corresponding to each privilege level; however, as we are only in M-mode, we only have 1. A trap can be either an interrupt (like external interrupts or timer interrupts) or an exception (like **`ecall`** or dividing by 0, etc), and the trap handler is called to deal with them. We will only be dealing with interrupts in this section; however, similar logic can be derived for exceptions.

When an interrupt is called, we must immediately drop everything and enter the trap handler, if we are allowed to (this will be discussed later). However, in a pipelined CPU, this means we need to flush everything that isn't in the Memory or Writeback stage, as we will be returning to the instruction running in the Execution stage after we exit the trap handler. It is the programmer's responsibility to save the registers when dealing with a trap; however, it is the hardware's responsibility to save the return address for the trap handler. The code in the trap handler is all written by the programmer, so it will do whatever they want it to, and then at the end they must call the **`mret`** instruction that allows us to return to whatever process we were in.

Now we need to define how interrupts can happen in our CPU. We will define 2 types of interrupts: External Interrupts and Timer Interrupts (there are also Software Interrupts; however, we don't define them). External Interrupts will replace our current trigger functionality. Now, when a trigger pulse is received, we perceive it as an external interrupt (in our FPGA, we will use one of the keys as a trigger, which is why we our defining it here). We will also add a new module in our CPU called the timer, which counts up to a certain reference value defined by the programmer and sends a timer interrupt pulse when it reaches that value (and then resets and counts again). These will be the 2 ways we enter the trap handler.

To allow these interrupts to occur, we need to define 7 special registers that will aid us with these interrupts:

#### mtvec: 0x305
This CSR simply stores the address of where the trap handler program is stored. Theoretically, there are also utvec and stvec for the trap handlers of different privilege levels. This needs to be written by the programmer using the CSR instructions we previously defined, or else we will not know where to jump to for the trap handler. 

#### mepc: 0x341
This CSR stores the return address after we finish running the trap handler. This is written by the hardware right before we enter the trap handler.

#### mecause: 0x342
This CSR tells us what caused us to enter the trap handler. The top bit is high for interrupts (always will be true for our case) and low for exceptions. We set bit 7 for M-mode timer interrupts and bit 11 for M-mode external interrupts. This can be used by the trap handler to determine how to deal with the trap.

#### mscratch: 0x340
This is an extra register that can be used for "scratch work"; it is essentially a general-purpose register.

#### mstatus: 0x300
This is the status register; it is the global interrupt enable and tells us if any type of interrupt can occur (there are also interrupt-specific enables for each type of interrupt that we define later, and both need to be enabled for a trap to be taken). Bit 3 of mstatus tells us if interrupts can occur or not, and when an interrupt is called, that state is saved in bit 7 and bit 3 is overwritten with 0 (to stop infinite loops of going back into the trap handler) and bit 3 is restored once mret is called.

#### mip: 0x344
This CSR tells us if there is an interrupt pending. When an interrupt comes in, either bit 7 (for timer interrupts) is set, or bit 11 is set (for external interrupts). This is so that an interrupt that comes in as a pulse is not missed if we are already in the trap handler, for example.

#### mie: 0x304
This is the interrupt enable; bit 7 needs to be high for timer interrupts to be able to occur, and bit 11 for external interrupts. This needs to be set by the programmer. We can think of this like a local enable if mstatus is a global enable.

Therefore, we need mstatus[3], mip[7] and mie[7] to all be high to enter the trap handler for a timer interrupt (and for external interrupts, replace the 7's with 11's).




