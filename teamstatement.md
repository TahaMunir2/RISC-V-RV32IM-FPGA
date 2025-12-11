
## Introduction

This Team Statement details the design and testing processes carried out by Team 5 for the implementation of the RISCV 32-bit CPU architecture, including a number of its extensions. 

Throughout the project, we maintained regular discussions to validate design decisions, prioritised deadlines, and resolved implementation challenges collaboratively. Whenever a module affected others, we aligned our work through version control, interface documentation, and consistent SystemVerilog conventions. This helped us avoid conflicts, streamline testing, and iterate on complex features in our design.

At the beginning of each stage of the project, our team established a clear division of tasks and agreed on common design principles to ensure that every component of the processor could integrate smoothly into a single unified architecture. Difficulties such as timing conflicts or inconsistent module behaviour were addressed collaboratively, reinforcing the importance of collective problem-solving in computer architecture projects.

Overall, this CPU project has been a practical demonstration of technical cooperation, disciplined planning, and organised development. Our final implementation not only reflects the functionality of a working RISC-V processor but also the effectiveness of our workflow, communication, and mutual accountability as a team. We all worked with passion, which we believe drove us to produce the results that we revel in.

## Quick Start
For this project, in accordance with the guidance provided in the Project Brief, we implemented the full set of 37 instructions in the RISCV32I architecture, which we then extended by implementing the proposed extensions of Pipelining and Cache. We implemented 2 levels of cache: 2-way associative split level 1 cache (L1d and L1i) and 4-way associative level 2 cache. We then further complemented our design by implementing a 2-bit branch predictor, the RISCV M, Zicsr and Zba extensions, and an out-of-order Superscalar architecture for arithmetic and load instructions. Finally, we added external and timer interrupts and specific control status registers for trap handling, which we then used to port our CPU onto a DE-10 Lite with external inputs, an internal timer and external outputs.

Our final design is split amongst 3 different models:
- **5-stage pipelined, Hierarchical Cache, 2-bit branch predictor RV32IM_Zicsr_Zba Processor**
- **5-stage pipelined Out-of-Order Superscalar Processor**
- **5-stage FPGA ported CPU with 2 types of interrupts**

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/finalwork.png)


## Future Considerations

Our current implementation represents a solid foundation that is architecturally close to supporting several advanced features. The modular design choices we made throughout the project position us well for future extensions. This section outlines the next steps we would pursue given additional time.

![Project Roadmap](Blank_diagram__2_.png)

### Out-of-Order Superscalar with Branches, Jumps, and Store Instructions

Our current out-of-order superscalar processor handles arithmetic instructions and Load instructions. Extending it to support control flow and store operations requires addressing two key challenges:

**Branch and Jump Handling**: The ROB already tracks instructions in program order, which is exactly what we need for speculative execution. When a branch misprediction is detected at commit, we would flush all ROB entries younger than the mispredicted branch and restore the RAT to its state before the branch was renamed. This is similar to what we implemented in our branch predictor section, but applied to the superscalar context.

The challenge is that misprediction penalties in superscalar processors are severe. This is because with 2-way issue and out-of-order execution, the pipeline fills with instructions much faster, so a misprediction wastes far more work than in a simple 5-stage pipeline.

Our simple 2-bit predictor would help, but achieving real performance gains requires a much more sophisticated predictor. Modern processors like the Cortex-A77 use neural-network-based predictors precisely because the cost of misprediction is so high in wide out-of-order machines.


**Store Instruction Handling:** Stores introduce complexity because different store operations could write to the same area in memory in a different order from the one specified in the assembly program. Hence, we need to implement Stores such that they would only write to the data cache at commit time.


### RISC-V Vector Extension (RVV)

The RISC-V "V" extension enables powerful vector processing, performing the same operation on multiple data elements simultaneously. Unlike traditional SIMD with fixed vector widths, RVV is **vector length agnostic**: the same code runs efficiently across different hardware vector sizes.

Implementation would require:

**Vector Register File:** A separate set of vector registers (v0–v31).

**Vector Functional Units:** Parallel ALUs that operate on all elements of a vector register simultaneously. Our existing dual-ALU infrastructure provides a starting point, we would extend this to process vector lanes in parallel.

**Vector Control Logic:** New control signals for vector length, element width, and masking operations that allow conditional execution on individual vector elements.

The key insight is that our superscalar infrastructure naturally extends to vector processing since we already have multiple ALUs operating in parallel, so vector instructions would simply dispatch the same operation across multiple lanes.

### FPGA Integration

Our ultimate goal is to synthesise the complete processor onto an FPGA, demonstrating that these advanced microarchitectural concepts translate to working hardware. We have already validated our pipelined design on FPGA with the F1 lights program.

The path forward involves:

**Synthesis of the Out-of Order superscalar design:** Mapping the RAT, ROB, and RUU structures to FPGA block RAMs

**Performance measurement:** Comparing cycle counts between our single-cycle, pipelined, and out of order superscalar implementations on real hardware to validate our theoretical performance analysis.

**TAHA TO ADD**

The architectural decisions we made such as tag-based register renaming, negative-edge timing for same-cycle wakeup and others are all techniques used in commercial processors. Our design demonstrates that the gap between educational implementations and real-world processor design is smaller than it appears. We are grateful that this course provided us with the foundational tools and knowledge to pursue these ambitious goals. We are excited to continue exploring advanced computer architecture and look forward to building on this foundation in future work.

---
