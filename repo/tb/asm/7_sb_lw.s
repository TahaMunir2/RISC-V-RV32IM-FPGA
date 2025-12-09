.text
.globl main
main:
    li t1, 0
    li a0, 1
    sb a0, 0(zero)
    sb a0, 1(zero)
    sb t1, 2(zero)
    sb t1, 3(zero)
    lw a0, 0(zero)
# a0 becomes 0x101
