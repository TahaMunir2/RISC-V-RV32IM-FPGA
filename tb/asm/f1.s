.text
.globl main
main:
    addi a0, zero, 0
    addi t2, zero, 1
mloop:
    bne x8, t2, mloop
    jal t3, iloop
    addi a0, zero, 0
    jal t3, mloop
iloop:
    li a0, 0
    addi    a0, a0, 1
    addi    a0, a0, 2
    addi    a0, a0, 4
    addi    a0, a0, 8
    addi    a0, a0, 16
    addi    a0, a0, 32
    addi    a0, a0, 64
    addi    a0, a0, 128
    jalr t3, t3, 0
end:
    addi a0, zero, 0

    
