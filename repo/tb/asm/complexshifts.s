.text
.globl main
main:
    addi    t0, zero, 1         # t0 = 1
    slli    t1, t0, 5           # t1 = 1 << 5 = 32     (RAW on t0)
    addi    t2, zero, 3         # t2 = 3
    sll     t3, t0, t2          # t3 = 1 << 3 = 8      (RAW on t0, t2)
    add     t4, t1, t3          # t4 = 32 + 8 = 40     (RAW on t1, t3)
    addi    t5, zero, 64        # t5 = 64
    srli    s2, t5, 2           # s2 = 64 >> 2 = 16    (RAW on t5)
    addi    s0, zero, 2         # s0 = 2
    srl     s1, s2, s0          # s1 = 16 >> 2 = 4     (RAW on s2, s0)
    add     a0, t4, s1          # a0 = 40 + 4 = 44

    