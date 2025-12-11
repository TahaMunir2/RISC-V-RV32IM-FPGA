.text
.globl main
main:

    li      t1, 0x12345678
    csrrw   x1, 0x340, t1       #  0x12345678
    li      t2, 0x0000FFFF
    csrrs   x1, 0x340, t2       #  0x1234FFFF
    li      t3, 0x000000FF
    csrrc   x1, 0x340, t3       #  0x1234FF00
    csrrs   a0, 0x340, x0
