.text
.globl main
main:
    lw   a3, 0(x0)              # chain 1
    addi a1, a3, 1              # depends on a3

    lw   a2, 8(x0)              # chain 2
    addi a0, a2, 2              # depends on a2

    