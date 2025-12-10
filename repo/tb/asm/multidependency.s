.text
.globl main
main:
    lw   a2, 0(x0)            # = 0x04030201
    lw   a1, 4(x0)            # = 0x08070605
    add  a0, a2, a1           # a0 = a2 + a1

    