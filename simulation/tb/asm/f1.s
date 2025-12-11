.text
.globl main
main:
    li t1, 0
    li t2, 1
    li a0, 0
    jal t3, iloop
iloop:
    li a0, 0
    bne t1, zero, iloop
    addi    a0, a0, 1
    bne t1, zero, iloop
    addi    a0, a0, 2
    bne t1, zero, iloop
    addi    a0, a0, 4
    bne t1, zero, iloop
    addi    a0, a0, 8
    bne t1, zero, iloop
    addi    a0, a0, 16
    bne t1, zero, iloop
    addi    a0, a0, 32
    bne t1, zero, iloop
    addi    a0, a0, 64
    bne t1, zero, iloop
    addi    a0, a0, 128
    bne t1, zero, iloop
    jalr t3, t3, -4
    
