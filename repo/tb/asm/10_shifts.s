.text
.globl main
main:
    li t1, 5          
    li t2, 3         
    slli t3, t1, 2    
    add t4, t3, t2    
    srli t5, t4, 1    
    xor a0, t5, t2    

    
