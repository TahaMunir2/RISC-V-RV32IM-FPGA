.text
.globl main
main:
    lh   a2, 0(x0)        # a2 = sign-extended 0x0201 -> 0x00000201
    lhu  a1, 0(x0)        # a1 = zero-extended 0x0201 -> 0x00000201
    add  a0, a2, a1       # a0 = 0x00000402

