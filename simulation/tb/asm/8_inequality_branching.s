.text
.globl main
main:
    addi t2, zero, 2
    li a0, -5
    bltu a0, t2, mloop
    blt a0, t2, iloop
mloop:
    bgeu a0, t2, endm
iloop:
    addi a0, a0, 1 
    blt a0, t2, iloop 
    bge a0, t2, endi 
endm:
    li a0, 10 
endi:

