# Pipelined RISC-V Processor

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
  - [2.1 Overall Hierarchy](#21-overall-hierarchy)
  - [2.2 L1 Instruction Cache](#22-l1-instruction-cache)
  - [2.3 L1 Data Cache](#23-l1-data-cache)
  - [2.4 L2 Cache](#24-l2_cache)
- [3. Schematic](#3-schematic)
- [4. Testing & Verification](#4-testing--verification)
  - [4.1 L1 Instruction Cache Testing](#41-l1-instruction-cache-testing)
  - [4.2 L1 Data Cache Testing](#42-l1-data-cache-testing)
  - [4.3 L2 Cache Testing](#43-l2-cache-testing)
---

## 1. Overview

Caches are relatively small and fast memory components that are used to improve processer performance by decreasing the time taken per fetch and writeback (on average). Caches provide quick and efficient access to a small portion of the main memory, and are also able to be written to and write back to main memory if need be.

Caches exploit spatial and temporal locality in order to improve fetch and writeback speed. Spatial locality is the principle that accessing one memory location increases the likelihood that adjacent memory locations (in the virtual memory space) will be accessed shortly afterward. On the other hand, the concept of temporal locality is that recently accessed data is also highly likely to be re-accessed due to the inherently cyclic nature of programming.

In our design, we have implemented a 2-way associative L1 instruction cache and L1 data cache, as well as a 4-way associative L2 cache. We have decideed not to implement further lower level memory (other than main memory) such as an L3 cache or an L4 cache as these typically handle data from different cores or processors, of which we have neither.

---

## 2. Implementation

### 2.1 Overall Hierarchy

The overall memory hierarchy is as such:

-insert overall hierarchy img

As shown in the diagram above, the processor reads and writes from the L1 caches, which read from and write to the L2 cache, which reads from and writes to main memory.

We have also decided to implement the cache controller and cache array in the same SystemVerilog sheet for all of the caches due to simplicity when integrating all of the submodules into the CPU.

### 2.2 L1 Instruction Cache

The instruction cache supports read requests from the processer and writing from the L2 cache, but does not support writing from the processor, as we are not expecting the processor to change and write over an instruction.


### 2.3 L1 Data Cache

### 2.4 L2 Cache

## 3. Schematic

---

## 4. Testing & Verification

### 4.1 L1 Instruction Cache Testing

---

### 4.2 L1 Data Cache Testing

---

### 4.3 L2 Cache Testing

---