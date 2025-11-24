.text
.globl main
main:
    li a0, 0xf00f
    sb a0, 1(zero)
    sb a0, 2(zero)
    lw a0, 0(zero)
#a0 becomes 0x0ff0, which is 4080