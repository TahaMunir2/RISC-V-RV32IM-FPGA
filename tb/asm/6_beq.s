.text
.globl main
main:
    addi t1, zero, 1
iloop:
    addi a0, zero, 1
    beq t1, a0, iloop