.text
.globl main
main:
    addi    t0, zero, 0xF0      # t0 = 240 (0b11110000)
    addi    t1, zero, 0x0F      # t1 = 15  (0b00001111)
    or      t2, t0, t1          # t2 = 240 | 15 = 255  (0b11111111)
    addi    t3, zero, 0xAA      # t3 = 170 (0b10101010)
    and     t4, t2, t3          # t4 = 255 & 170 = 170 (RAW on t2)
    addi    t5, zero, 0xDE      # t5 = 222 (0b11011110)
    xor     s0, t4, t5          # s0 = 170 ^ 222 = 116 (RAW on t4)
    addi    a0, s0, -16         # a0 = 116 - 16 = 100
