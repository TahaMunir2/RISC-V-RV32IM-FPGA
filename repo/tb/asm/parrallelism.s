.text
.globl main
main:
    addi    t0, zero, 10        # t0 = 10 
    addi    t1, zero, 20        # t1 = 20 
    addi    t2, zero, 30        # t2 = 30 
    addi    t3, zero, 40        # t3 = 40
    addi    a0, t3, 0           # a0 = t3 = 40

    # see in report evidence of instructions running in parrallel (verified using gtkwave)

    