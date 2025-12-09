# Interrupts and FPGA

## Table of Contents
- [1. Overview](#overview)

## Overview

We previously defined a CSR module and added some instructions to play around with the CSR's however, we also mentioned how each register has a special predetermined purpose and can be used for a variety of use cases. The use case we will delve into is **interrupts**, as these help our CPU interact with the outside world and also add some additional functionality to our CPU. 

Let's start by talking about privilege levels. There are 3 privilege levels in the RV32I CPU: Machine Mode (highest privilege), Supervisor and User (lowest privilege). Depending on the privilege level that the CPU is currently in, certain CSRs might not be available, as they are only available to high privilege levels for security purposes. For this project, we can assume that we are always in Machine Mode and no other privilege level exists on our CPU, hence the registers we define are exclusive to M-mode and would theoretically not be available in lower privilege levels.
