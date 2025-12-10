.text
.globl main
main:
    addi    t0, zero, 1         # t0 = 1
    slli    t1, t0, 4           # t1 = 1 << 4 = 16     (RAW on t0)
    slli    t2, t1, 2           # t2 = 16 << 2 = 64    (RAW on t1)
    addi    t3, zero, 256       # t3 = 256
    srli    t4, t3, 1           # t4 = 256 >> 1 = 128  (RAW on t3)
    add     a0, t2, t4          # a0 = 64 + 128 = 192
    srli    a0, a0, 1           # a0 = 192 >> 1 = 96   (RAW on a0)
    addi    a0, a0, 32          # a0 = 96 + 32 = 128   (RAW on a0)

    