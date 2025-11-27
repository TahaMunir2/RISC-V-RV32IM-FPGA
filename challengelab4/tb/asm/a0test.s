    .text
    .globl main

main:
    addi x10, zero, 155      # a0 = 1
loop:
    jal  zero, loop       # infinite loop
