# Single Cycle Reduced RV32I CPU:

## Table of Contents
- [1 Overview](#overview)
- [2 Implementation](#implementation)
- [3 Schematic](#schematic)
- [4 Testing](#testing)

## Overview

This section goes over the baseline foundation of our RV32I CPU. Working on the single-cycle CPU gave our team an introduction to working with each other and designing and testing a CPU using SystemVerilog and shell script testing environments. Our single-cycle CPU implements the following 9 instructions:


| # | Mnemonic | Type | Opcode (binary) | funct3 | funct7   | Brief description                            |
|---|----------|------|-----------------|--------|----------|----------------------------------------------|
| 1 | `ADDI`   | I    | `0010011`       | `000`  | –        | Add sign-extended immediate to `rs1`.        |
| 2 | `BNE`    | B    | `1100011`       | `001`  | –        | Branch if `rs1 != rs2`.                      |
| 3 | `ADD`    | R    | `0110011`       | `000`  | `0000000`| Register-register add.                       |
| 4 | `LW`     | I    | `0000011`       | `010`  | –        | Load 32-bit word from memory.                |
| 5 | `LBU`    | I    | `0000011`       | `100`  | –        | Load zero-extended byte from memory.         |
| 6 | `JALR`   | I/J* | `1100111`       | `000`* | –        | Jump to `rs1 + imm`, write return PC to `rd`.|
| 7 | `SB`     | S    | `0100011`       | `000`  | –        | Store byte to memory.                        |
| 8 | `JAL`    | J    | `1101111`       | –      | –        | PC-relative jump, write return PC to `rd`.   |
| 9 | `LUI`    | U    | `0110111`       | –      | –        | Load 20-bit upper immediate into `rd`.       |


## Implementation

## Schematic

![alt text](https://github.com/TahaMunir2/Team5/blob/single-cycle-cpu/images/Modified%20Single%20Cycle%20CPU%20diagram.jpg)

## Testing
https://github.com/user-attachments/assets/36d3a1a0-e795-473e-b112-f805138e5dc2

