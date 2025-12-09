# Team 5 CPU Project team statement


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
|               | [Sign Extend]        |              *             |                       |                   |                     |
|               | [Top File]       |                  **       |                       |                   |                     |
|               | Testing [pdf](https://github.com/luju1108/Team14/blob/55573bf5cd5188fad616eb12a406bb40f62c1772/RTL/README_PDF.md) [F1](https://youtu.be/zJto4plLvCE)                       |             **           |   **                 |        *       |               |
|               |
| Full 37 instructions implementation      | Control Unit             |                   |                       |                   |                       |
|      | Data Path             |                       |                       |                   |                       |
|      | Program Counter Block             |                       |                       |                   |                       |
|      | Integration             |                       |                       |                   |                       |
|      | Testing and Verification          |                       |                       |                   |                       |
| Pipeline      | Pipeline Register             | **                         |                       |                   |                       |
|               | [Hazard unit]               |                           |                       | **                 |                       |
|               | [Forwarding Logic]            |                          |        **               |                   |                       |
|               | [Top File]            | *                         |    *                   |      *             |                       |
|               | Testing [pdf](https://github.com/luju1108/Team14/blob/98bc1b035346cb44bc519077c4daae0fd198ed2f/RTL/README_PDF.md) [F1](https://youtu.be/59yWMzJzut0)                      |                          |                       | *                |                       |
|       Branch prediction        |                        |                          |           **          |                   |                     |
| Cache         | 2-way L1d and L1i cache  |            *          |         *           |                   | **                 |
|               | 4-way L2  cache  |                           |                   |                   | **                 |
|               | Top Level Integration |                           |                    |                   | **                  |
|               | Unit Testing   |                 *       |      *             |                   |                    |
| M-extension              |              Control Path          |                           |                      |           **       |                      |
|               |             ALU         |                           |                      |                  |              **        |
|               |              Testing          |                           |                      |          **        |                      |
| Z-extension              |          Zicsr            |          **                |                      |                   |                      |
|                           |         Zba              |            **              |                      |                   |                      |
|                           |         Testing               |         **                 |                      |                   |                      |
| Interrupts & FPGA       |              Interrupts           |       **                   |                      |                   |                      |
|                           |            Timer            |             **             |                      |                   |                      |
|                           |             Memory           |                          |                      |    **               |                      |
|                           |          MMIO        |              **            |                      |                   |                      |
|                           |          Top Level Integration              |        **                  |                      |                   |                      |
|                           |              FPGA Wrapper         |              **            |                      |                   |                      |
|                           |          Testing             |                **          |                      |                   |                      |
| Out of Order Superscalar arithmetic            |     Register-Aliasing Table                   |                           |        **              |                   |                      |
|             |     Register-Update Unit                   |                           |             **         |                  |                      |
|             |     Re-Order Buffer                   |                           |           **           |                  |                      |
|             |     Integration and Pipeline Division                   |                           |             **         |                   |                      |
|             |     Testing and Verification                   |                           |                  **    |                   |                      |
| Out of Order Superscalar full version           |     Data Memory Adaptation                  |                           |   **                   |                   |                      |
|             |     Common Data Bus Adaptation                   |                           |          **            |                   |                      |
|             |     Load Instruction Integratioon                  |                           |       **               |                   |                      |
|             |     Testing and Verification                   |                           |         **             |                   |                      |



