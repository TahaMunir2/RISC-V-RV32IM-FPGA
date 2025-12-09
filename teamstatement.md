
## Introduction

This Team Statement details the design and testing processes carried out by Team 5 for the implementation of the RISCV 32-bit CPU architecture, including a number of its extensions. 

Throughout the project, we maintained regular discussions to validate design decisions, prioritised deadlines, and resolved implementation challenges collaboratively. Whenever a module affected others, we aligned our work through version control, interface documentation, and consistent SystemVerilog conventions. This helped us avoid conflicts, streamline testing, and iterate on complex features in our design.

At the beginning of each stage of the project, our team established a clear division of tasks and agreed on common design principles to ensure that every component of the processor could integrate smoothly into a single unified architecture. Difficulties such as timing conflicts or inconsistent module behaviour were addressed collaboratively, reinforcing the importance of collective problem-solving in computer architecture projects.

Overall, this CPU project has been a practical demonstration of technical cooperation, disciplined planning, and organised development. Our final implementation not only reflects the functionality of a working RISC-V processor but also the effectiveness of our workflow, communication, and mutual accountability as a team. We all worked with passion, which we believe drove us to produce the results that we revel in.

## Quick Start
For this project, in accordance with the guidance provided in the Project Brief, we implemented the full set of 37 instructions in the RISCV32I architecture, which we then extended by implementing the proposed extensions of Pipelining and Cache. We implemented 2 levels of cache: 2-way associative split level 1 cache (L1d and L1i) and 4-way associative level 2 cache. We then further complemented our design by implementing a 2-bit branch predictor, the RISCV M, Zicsr and Zba extensions, and an out-of-order Superscalar architecture for arithmetic and load instructions. Finally, we added external and timer interrupts and specific control status registers for trap handling, which we then used to port our CPU onto a DE-10 Lite with external inputs, an internal timer and external outputs.

Our final design is split amongst 3 different models:
- **5-stage pipelined, Hierarchical Cache, 2-bit branch predictor RV32IM_Z_icsr_Zba Processor**
- **5-stage pipelined Out-of-Order Superscalar Processor**
- **5-stage FPGA ported CPU with 2 types of interrupts**


