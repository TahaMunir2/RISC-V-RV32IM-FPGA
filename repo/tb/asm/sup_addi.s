.text
.globl main
main:
    addi    t1, zero, 0xff      # t1 = 255
    addi    a0, zero, 0x0       # output = 0
    addi    a1, zero, 0x01       #
    addi    a0, a1, 10          # expected output : a0=11

