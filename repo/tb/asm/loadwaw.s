.text
.globl main
main:
    lw   a0, 0(x0)            # older: a0 = MEM[0] = 0x04030201
    lw   a0, 4(x0)            # younger: a0 = MEM[4] = 0x08070605
    addi a0, a0, 1            # a0 = 0x08070606

