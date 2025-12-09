# Team 5 CPU Project team statement


## Quick Start
For this project, in accordance with the guidance provided in the Project Brief, we implemented the full set of 37 instructions in the RISCV32I architecture, which we then extended by implementing the proposed extensions of Pipelining and Cache. We implemented 2 levels of cache: 2-way associative level 1 cache and 4-way associative level 2 cache. We then further complemented our design by implementing branch prediction, the RISCV M and Z extensions, and an out-of-order Superscalar architecture for arithmetic and load instructions. Finally, [basically describe FPGA now]

## Contributions table

|               |                               | Taha Munir (TahaMunir2)  | Cyril Abdelnour (Cyllocoding)  | Yusuf Kerem Teker (Ke1911)  | Leo Yin (Cathugger8)   |
| ------------  | ----------------------------- | ------------------------- | --------------------- | ----------------- | --------------------- |
| General       | Shell Script        |                           |                    |      **           |                       |
|               | F1 Assembly     |                        |                    |       **            |                       |
| [Single Cycle](https://github.com/TahaMunir2/Team5/tree/single-cycle-cpu)  | Program Counter       |        *                 |                       |        **          |                       |
|               | Control Unit            |        *                   |                       |                  |        **             |
|               | Data Path        |           *                |            **           |                 |                       |
|               | Sign Extend        |              *             |                       |           **        |                     |
|               | Top Level Integration     |                  **       |                       |                   |                     |
|               | Testing                    |             **           |                    |        *       |               |
| [Full 37 Instructions implementation](https://github.com/TahaMunir2/Team5/tree/FULL-RV32I)      | Control Unit             |                   |     **                  |                   |                       |
|          | Data Path             |                       |                 **      |                  |                       |
|        | Program Counter Block             |                       |                 **      |                   |                       |
|      | Integration             |                       |                  **     |                   |                       |
|      | Testing and Verification          |                       |            **           |                   |                       |
| [Pipelining](https://github.com/TahaMunir2/Team5/tree/PIPELINING)      | Pipeline Register             | **                         |                       |                   |                       |
|               | Hazard unit              |                           |                       | **                 |                       |
|               | Forwarding Logic            |                          |        **               |                   |                       |
|               | Top File           | *                         |    *                   |      *             |                       |
|               | Testing                     |                          |             *          | **                |                       |
|       [ Branch prediction](https://github.com/TahaMunir2/Team5/tree/branchprediction)        |          2-bit Branch Predictor Design                 |                          |           **          |                   |                     |
|            |             Program Counter Logic Redefined         |                          |           **          |                   |                     |
|            |       Top Level Integration                |                          |           **          |                   |                     |
|            |     Testing and Verification                |                          |           **          |                   |                     |
| [Hierarchical Cache](https://github.com/TahaMunir2/Team5/tree/Hierarchical-cache)         | 2-way L1d and L1i cache  |            *          |         *           |                   | **                 |
|               | 4-way L2  cache  |                           |                   |                   | **                 |
|               | Top Level Integration |                 *          |        *            |                   |                  |
|               | Unit Testing   |                        |                   |                 |    **                |
| [M-extension](https://github.com/TahaMunir2/Team5/tree/M-Extension)              |              Control Path          |                           |                      |   **              |                      |
|               |             ALU         |                           |                      |        **          |                      |
|               |              Testing          |                           |                      |          **        |                      |
| [Z-extension](https://github.com/TahaMunir2/Team5/tree/Z-extensions)              |          Zicsr            |          **                |                      |                   |                      |
|                           |         Zba              |            **              |                      |                   |                      |
|                           |         Testing               |         **                 |                      |                   |                      |
| [Interrupts & FPGA](https://github.com/TahaMunir2/Team5/tree/Interrupts-and-FPGA)       |              Interrupts           |       **                   |                      |                   |                      |
|                           |            Timer            |             **             |                      |                   |                      |
|                           |             Memory           |                          |                      |    **               |                      |
|                           |          MMIO        |              **            |                      |                   |                      |
|                           |          Top Level Integration              |        **                  |                      |                   |                      |
|                           |              FPGA Wrapper         |              **            |                      |                   |                      |
|                           |          Testing             |                **          |                      |                   |                      |
| [Out of Order Superscalar arithmetic](https://github.com/TahaMunir2/Team5/tree/out_of_order_superscalar_arithmetic)            |     Register-Aliasing Table                   |                           |        **              |                   |                      |
|             |     Register-Update Unit                   |                           |             **         |                  |                      |
|             |     Re-Order Buffer                   |                           |           **           |                  |                      |
|             |     Integration and Pipeline Division                   |                           |             **         |                   |                      |
|             |     Testing and Verification                   |                           |                  **    |                   |                      |
| [Out of Order Superscalar full version](https://github.com/TahaMunir2/Team5/tree/out_of_order_superscalar_full_version)           |     Data Memory Adaptation                  |                           |   **                   |                   |                      |
|             |     Common Data Bus Adaptation                   |                           |          **            |                   |                      |
|             |     Load Instruction Integratioon                  |                           |       **               |                   |                      |
|             |     Testing and Verification                   |                           |         **             |                   |                      |



