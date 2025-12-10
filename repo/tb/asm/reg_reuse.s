.text
.globl main
main:
    addi    t0, zero, 1         # t0 = 1
    addi    t1, t0, 1           # t1 = 2
    addi    t0, t1, 1           # t0 = 3  
    addi    t1, t0, 1           # t1 = 4 
    addi    t0, t1, 1           # t0 = 5 
    addi    t1, t0, 1           # t1 = 6 
    addi    t0, t1, 1           # t0 = 7
    addi    t1, t0, 1           # t1 = 8 
    addi    t0, t1, 1           # t0 = 9 
    addi    t1, t0, 1           # t1 = 10 
    addi    a0, t1, 90          # a0 = 10 + 90 = 100

