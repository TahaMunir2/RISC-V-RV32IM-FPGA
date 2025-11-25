.text
.globl main
main:
    addi t1, zero, 1
    li a0, 0
iloop:
    addi a0, a0, 1
    beq t1, a0, iloop