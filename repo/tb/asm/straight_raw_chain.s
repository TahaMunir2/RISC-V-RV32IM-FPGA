.text
.globl main

main:
    # Register Initialization
    addi t0, x0, 5      # t0 = 5
    addi t1, x0, 7      # t1 = 7

    # Instruction 1: produces t2
    add  t2, t0, t1     # t2 = 5 + 7 = 12 (RAW: t2 is produced here)

    # Instruction 2: uses t2 as source
    add  t3, t2, t1     # t3 = 12 + 7 = 19 (RAW: depends on t2)

    # Instruction 3: uses t3 and t0
    add  a0, t3, t0     # a0 = 19 + 5 = 24 (RAW: depends on t3)

