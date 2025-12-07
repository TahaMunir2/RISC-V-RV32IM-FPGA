# Branch Prediction

## Table of Contents
- [1. Overview](#1-overview)
- [2. Implementation](#2-implementation)
  - [2.1 Branch Predictor](#21-branch-predictor)
  - [2.2 PCSrcF Assertion](#22-pcsrcf-assertion)
  - [2.3 Overall Integration](#23-overall-integration)
- [3. Schematic](#3-schematic)
- [4. Testing & Verification](#4-testing--verification)
  - [4.1 Branch Predictor Testing](#41-branch-predictor-testing)
  - [4.2 Full Circuit Testing](#42-full-circuit-testing)

---

## 1. Overview

In our pipelined processor, instructions are fetched sequentially assuming `PC + 4`. Branch decisions are only resolved in the Execute stage, meaning incorrect instructions may already be in the pipeline. This causes **control hazards** requiring flushes, which waste cycles.
The baseline approach predicts all branches as **not taken**, but this performs poorly for loops where backward branches are typically taken repeatedly.

### Our Solution: Two-Bit Dynamic Prediction

- A **one-bit predictor** remembers only the last outcome
- Problem: it **mispredicts twice per loop** (first and last iteration)

- A **two-bit predictor** requires two consecutive mispredictions before changing its prediction
- Four states: *Strongly Taken → Weakly Taken → Weakly Not Taken → Strongly Not Taken*
- Result: **mispredicts only once per loop** instead of twice

### Branch Target Buffer (BTB)

We maintain a table indexed by the branch PC containing:
- The **2-bit prediction state**
- The **target address** for fast redirection when predicting "taken"

**Integration**: Integrating the branch predictor into the pipeline is also challenging because both the Fetch stage (making predictions) and the Execute stage (resolving actual outcomes) compete to update the Program Counter, so we had to implement synchronization between these 2 stages.

---

## 2. Implementation

### 2.1 Branch Predictor

<!-- TODO: Branch predictor design and logic -->

---

### 2.2 PCSrcF Assertion

<!-- TODO: PCSrcF assertion module explanation -->

---

### 2.3 Overall Integration

<!-- TODO: How components connect together -->

---

## 3. Schematic

<!-- TODO: Circuit diagram -->

---

## 4. Testing & Verification

### 4.1 Branch Predictor Testing

<!-- TODO: Branch predictor unit tests -->

---

### 4.2 Full Circuit Testing

<!-- TODO: Integration tests with assembly programs -->

---

