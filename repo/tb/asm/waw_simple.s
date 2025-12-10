.text
.globl main

main:
    addi    a0, zero, 10        # a0 = 10 (first write)
    addi    a0, zero, 99        # a0 = 99 (second write) , expected output a0 = 99

    