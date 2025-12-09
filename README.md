# Team 5 CPU Project team statement


## Introduction

This Team Statement details the design and testing processes carried out by Team 5 for the implementation of the RISCV 32-bit CPU architecture, including a number of its extensions. 
The development of our RISC-V CPU has been a collaborative effort built on shared responsibility, structured planning, and open technical communication. At the beginning of each stage of the project, our team established a clear division of tasks, defined weekly/daily milestones, and agreed on common design principles to ensure that every component of the processor could integrate smoothly into a single unified architecture.

Throughout the project, we maintained regular discussions to validate design decisions, prioritize deadlines, and resolve implementation challenges collaboratively. Whenever a module affected others, we aligned our work through version control, interface documentation, and consistent SystemVerilog conventions. This helped us avoid conflicts, streamline testing, and iterate on complex features in our design.

Each member contributed both individually and collectively: individual ownership of modules enabled efficiency, while peer review, shared debugging sessions, and cross-testing ensured quality and correctness. Difficulties such as timing conflicts or inconsistent module behavior were addressed collaboratively, reinforcing the importance of collective problem-solving in computer architecture projects.

Most importantly, This project taught us the importance of collaboration and sharing ideas in any design-related endeavor.

Overall, this CPU project has been a practical demonstration of technical cooperation, disciplined planning, and organized development. Our final implementation not only reflects the functionality of a working RISC-V processor but also the effectiveness of our workflow, communication, and mutual accountability as a team.

We all worked with passion, which we believe drove us to produce the results that we revel in.

## Quick Start
For this project, in accordance with the guidance provided in the Project Brief, we implemented the full set of 37 instructions in the RISCV32I architecture, which we then extended by implementing the proposed extensions of Pipelining and Cache. We implemented 2 levels of cache: 2-way associative level 1 cache and 4-way associative level 2 cache. We then further complemented our design by implementing branch prediction, the RISCV M and Z extensions, and an out-of-order Superscalar architecture for arithmetic and load instructions. Finally, [basically describe FPGA now]

## Contributions table

|               |                               | Taha Munir (TahaMunir2)  | Cyril Abdelnour (Cyllocoding)  | Yusuf Kerem Teker (Ke1911)  | Leo Yin (Cathugger8)   |
| ------------  | ----------------------------- | ------------------------- | --------------------- | ----------------- | --------------------- |
| General       | [Top Testbenches]          |                           |                    |                 |                       |
|               | [Subfile Testbenches]     |                        |                    |                |                     |
|               | [Shell Script]             |                       |                       |                   |                       |
|               | [F1 Assembly]     |                        |                    |       **            |                       |
| Single Cycle  | [Program Counter]        |        *                 |                       |                  |                       |
|               | [Control Unit]             |        *                   |                       |                  |                     |
|               | [Register File]         |           *                |                       |                 |                       |
|               | [ALU]               |               *          |                       |                 |                       | 
|               | [Data Memory]          |             *         |                       |                   |                     |
|               | [Datapath]               |           *                |                     |                 |                       |
|               | [Sign Extend]        |              *             |                       |                   |                     |
|               | [Top File]       |                  **       |                       |                   |                     |
|               | Testing [pdf](https://github.com/luju1108/Team14/blob/55573bf5cd5188fad616eb12a406bb40f62c1772/RTL/README_PDF.md) [F1](https://youtu.be/zJto4plLvCE)                       |             **           |   **                 |        *       |               |
|               
| Pipeline      | Pipeline Register             | **                         |                       |                   |                       |
|               | [Hazard unit]               |                           |                       | **                 |                       |
|               | [Forwarding Logic]            |                          |        **               |                   |                       |
|               | [Top File]            | *                         |    *                   |      *             |                       |
|               | Testing [pdf](https://github.com/luju1108/Team14/blob/98bc1b035346cb44bc519077c4daae0fd198ed2f/RTL/README_PDF.md) [F1](https://youtu.be/59yWMzJzut0)                      |                          |                       | *                |                       |
|       Branch prediction        |                        |                          |           **          |                   |                     |
| Cache         | [Direct Mapped Cache]    |                      |                    |                   | **                 |
|               | RAM Refactor                  |                           |                   |                   | **                 |
|               | Data Memory                   |                           |                    |                   | **                  |
|               | [Control Unit Refactor]      |                        |                   |                   | **                    |
|               | [Pipelining Refactor]       |                      |                       |                   |        **               |
|               | Testing                       |                    |                  |               |                    |
|               | [Fully Associative Cache]    |                           |                     |                   |                    |
| M-extension              |                        |                           |                      |                  |                      |
| Z-extension              |                        |                          |                      |                   |                      |
| Interrupts & FPGA       |                        |                          |                      |                   |                      |
|               |    Memory           |                           |                      |                 |                      |
| Superscalar              |                        |                           |                      |                   |                      |



