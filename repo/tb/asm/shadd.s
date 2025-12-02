.option arch, +zba
.text
.globl main
main:
    li t1, 64
    li t2, 7
    sh1add a0, t1, t2 # a0 = 64 * 2 + 7 = 135
    sh2add a0, t1, t2 # a0 = 64 * 4 + 7 = 263
    sh3add a0, t1, t2 # a0 = 64 * 8 + 7 = 519
