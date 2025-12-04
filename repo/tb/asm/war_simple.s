.text
.globl main
main:
    addi    t0, zero, 5         # t0 = 5 (old value)
    addi    a0, t0, 0           # a0 = t0 + 0 = 5  (reading t0 must get old value)
    addi    t0, zero, 100       # t0 = 100 (new value , we don't want this value to get written to a0)
    # a0 should still be 5, not 100

    