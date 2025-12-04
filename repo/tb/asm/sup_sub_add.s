.text
.globl main
main:
    # li is broken into lui and addi for >12-bit values
    # don't forget that addi sign-extends
    li t1, 1    #
    li t2, 2    #
    sub a1, t1, t2  # a1 = -1
    add a0, t2, a1  # a0 = 1
    add a3, t1, t2  # no dependency, a3 =3
    add a0, a0, a3 # output : a0 = 4

    