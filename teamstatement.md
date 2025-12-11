
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

## Methodology

### Shift in Design Approach
We initially approached each branch by breaking it into sections as suggested by the project brief (i.e. 1 person does testing, 1 does data path, etc.), and we continued this approach until everyone had testbenched 1 branch each to make sure everyone was comfortable with both hardware and software. However, after that we realised integrating code between different people can be tricky so we decided to focus on the theoretical implementation to each branch as a group but assigning the actual coding to 1 person, this is reflected in our contribution table where initially each section is split up evenly between each person and then later on 1 person does the whole section, although everyone was still involved in the theoretical appraoch. Due to this, and also for complexity and time issues, we forked our implementation at branch prediction and ended up with 3 different CPU's as our final implementations, as they were developed in parallel, as shown in the diagram below:
### Collaboration
We decided that having a strong collaborative approach was key to having success in this project. We had almost daily meetings where everyone would recap the work they've done in the past day, and then we would all plan together on how to approach the next extension we want to add. We often developed the theory as a group, which allowed us to bounce ideas off each other and make sure everyone understood what was going on in the CPU. This also helped keep motivation high as we found we are much more productive when working together than alone, and allowed us to keep pushing each other to add more and more extensions.

### Testing Philosophy
We decided to implement both CPU testing and unit testing each time we added a new component. This not only meant we were able to thoroughly test each case for each new component, but also check that it works in the overall circuit. We also heavily relied on gtkWave for debugging and traced instructions through our CPU to work out exactly where our bugs were coming from, which we found to be the most effective testing approach. 

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/finalwork.png)



## Over-arching Results

## VBuddy results
#### F1 test on Vbuddy



https://github.com/user-attachments/assets/0c69e605-449a-43a5-ae6c-754687139dbb

The delay that I introduced at the beginning of each cycle allows us to have the distinguisably slow count-up that you can observe in the video. To achieve interactivity, we mapped our trigger to one register 8 in our register file. Then, in the testbench, we set trigger via vbdFlag(), which corresponds to pushing the rotary encoder on the Vbuddy chip. To distinguish the change in the LEDs and make them truly similar to F1 lights, a delay was introduced at the beginning of each cycle in the testbench. See the single-cycle-cpu branch for details.

#### PDF tests

##### gaussian.mem




https://github.com/user-attachments/assets/e1337251-4626-412e-a283-311f928022b8




##### triangle.mem




https://github.com/user-attachments/assets/bff91a51-b9f0-47c0-a872-223c2331e0df



##### noisy.mem, 1





https://github.com/user-attachments/assets/770a829a-33fc-433d-b491-fc4e19501dce




##### noisy.mem, 2

The reason for the second video showing noisy.mem being ddislayed on Vbuddy is to emphasize the custom displaying frequency capability that I achieved by choosing to display the value of our output register a0 every N counter cycles. This allows us to fit the shapes on the Vbuddy display as we wish.


https://github.com/user-attachments/assets/ee6f12fb-fede-4ab4-96b9-0ce7068977f9


### Superscalar arithmetic: Shift Operations (`sup_shifts.s`)
```asm
addi t0, zero, 1
slli t1, t0, 4          # t1 = 16
slli t2, t1, 2          # t2 = 64
addi t3, zero, 256
srli t4, t3, 1          # t4 = 128
add  a0, t2, t4         # a0 = 192
srli a0, a0, 1          # a0 = 96
addi a0, a0, 32         # a0 = 128
```
This test verifies shift-immediate operations (slli, srli) with RAW dependencies. The processor must correctly execute logical shifts and forward results through the CDB for dependent instructions. Expected output: **a0 = 128**.

This waveform provides evidence of the performance advantage of out-of-order execution. We observe ALU1 executing tag 02 (the `slli t1, t0, 4` instruction producing 0x10 = 16) while simultaneously ALU2 executes tag 04 (the independent `addi t3, zero, 256` producing 0x100 = 256). The out-of-order scheduler ( the Register-Update Unit) identified that instruction 4 has no dependencies on instructions 2 or 3 and issued it immediately to the second ALU.

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/averifyingshifts.jpg)

**IPC Calculation:**

- In-order scalar processor: 8 instructions ÷ 8 cycles = **IPC = 1.0**
- In-order superscalar processor: 8 instructions ÷ 6 cycles = **IPC = 1.33**
- Out-of-order superscalar: 8 instructions ÷ 5 cycles = **IPC = 1.6**

This represents a **60% improvement** over the baseline IPC of 1.

---

### FPGA and Interrupts: F1 test on DE-10 Lite


https://github.com/user-attachments/assets/2adacb26-7459-44d5-94f8-997369829358

## Future Considerations

Our current implementation represents a solid foundation that is architecturally close to supporting several advanced features. The modular design choices we made throughout the project position us well for future extensions. This section outlines the next steps we would pursue given additional time.

![Project Roadmap](images/futureconsiderations.png)

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
