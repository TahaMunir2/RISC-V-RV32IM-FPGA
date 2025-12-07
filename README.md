# Pipelined RISC-V Processor

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
  - [2.1 Pipeline Architecture](#21-pipeline-architecture)
  - [2.2 Hazard Unit](#22-hazard-unit)
- [3. Schematic](#3-schematic)
- [4. Testing & Verification](#4-testing--verification)
  - [4.1 Hazard Unit Testing](#41-hazard-unit-testing)
  - [4.2 Full Pipeline Testing](#42-full-pipeline-testing)

---

## 1. Overview

Pipelining is a technique used to improve processor performance by letting different parts of multiple instructions run at the same time instead of completing one instruction fully before starting the next.
In a single-cycle CPU, each instruction passes sequentially through several steps: fetch, decode, execute, memory access, and writeback and this total delay defines the clock cycle. 

Pipelining divides these steps into separate hardware stages and places pipeline registers between them, so that each stage works on a different instruction every cycle. As a result, while one instruction is being executed, another is being decoded and a third is already being fetched. The processor therefore achieves higher throughput.

In our design, we extend the original single-cycle (full 37 instructions) cpu into a classic 5-stage pipeline processor. This will require new pipeline registers, modified writeback timing, and hazard-handling logic. We will add forwarding and stalling mechanisms to resolve data dependencies, and flushing logic to handle control hazards introduced by branches.

---

## 2. Implementation

### 2.1 Pipeline Architecture

#### 2.1.1 Pipeline Stages

#### 2.1.2 forwarding multiplexers

#### 2.1.3 PCSrc_assertion logic explained

---

### 2.2 Hazard Unit

---

## 3. Schematic

![diagram](pipelining.png)

---

## 4. Testing & Verification

### 4.1 Hazard Unit Testing

---

### 4.2 Full Pipeline Testing

---

