.text
.globl main

main:
    addi a3, x0, 127      # a3 = 127
    lb   a2, 0(a3)        # a2 = sign-extended 0x80 -> 0xFFFFFF80
    lbu  a1, 0(a3)        # a1 = zero-extended 0x80 -> 0x00000080
    add  a0, a2, a1       # a0 = 0xFFFFFF80 + 0x00000080 = 0x00000000
    