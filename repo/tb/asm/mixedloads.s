.text
.globl main

main:
    # 1) Word load from 0
    lw   a7, 0(x0)            # a0 = 0x04030201

    # 2) Byte loads (positive & negative)
    lb   a1, 1(x0)            # a1 = sign-ext  0x02     -> 0x00000002
    lbu  a2, 127(x0)          # a2 = zero-ext  0x80     -> 0x00000080
    lb   a3, 127(x0)          # a3 = sign-ext  0x80     -> 0xFFFFFF80

    # 3) Halfword loads (positive & negative)
    lh   a4, 0(x0)            # a4 = sign-ext  0x0201   -> 0x00000201
    lhu  a5, 126(x0)          # a5 = zero-ext  0x807F   -> 0x0000807F
    lh   a6, 126(x0)          # a6 = sign-ext  0x807F   -> 0xFFFF807F

    # 4) Simple ALU using load results
    add  a0, a1, a2           # a0 = 0x00000002 + 0x00000080 = 0x00000082
