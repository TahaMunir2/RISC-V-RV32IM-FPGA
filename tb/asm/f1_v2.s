.text
.globl main

main:
    li      t1, 0              # t1 = reset flag (0 = no reset)
    li      t2, 1              # t2 = "enable" (unused for now)
    li      a0, 0              # a0 drives VBuddy
    jal     x0, iloop          # jump to main pattern loop (no return)

# ---------------------------------------------------------
# delay subroutine: simple busy-wait to make states visible
# ---------------------------------------------------------
delay:
    li      t0, 5000           # adjust this for visible speed
delay_loop:
    addi    t0, t0, -1         # t0--
    bne     t0, zero, delay_loop
    jalr    x0, ra, 0          # return

# ---------------------------------------------------------
# main pattern loop (software FSM for a0)
# ---------------------------------------------------------
iloop:
    # S0: 00000000
    li      a0, 0
    jal     ra, delay          # hold 0 for a while
    bne     t1, zero, reset    # if reset flag set, restart

    # S1: 00000001
    addi    a0, a0, 1          # a0 = 1
    jal     ra, delay
    bne     t1, zero, reset

    # S2: 00000011
    addi    a0, a0, 2          # a0 = 3
    jal     ra, delay
    bne     t1, zero, reset

    # S3: 00000111
    addi    a0, a0, 4          # a0 = 7
    jal     ra, delay
    bne     t1, zero, reset

    # S4: 00001111
    addi    a0, a0, 8          # a0 = 15
    jal     ra, delay
    bne     t1, zero, reset

    # S5: 00011111
    addi    a0, a0, 16         # a0 = 31
    jal     ra, delay
    bne     t1, zero, reset

    # S6: 00111111
    addi    a0, a0, 32         # a0 = 63
    jal     ra, delay
    bne     t1, zero, reset

    # S7: 01111111
    addi    a0, a0, 64         # a0 = 127
    jal     ra, delay
    bne     t1, zero, reset

    # S8: 11111111
    addi    a0, a0, 128        # a0 = 255
    jal     ra, delay
    bne     t1, zero, reset

    # after S8, loop back to S0
    jal     x0, iloop

# ---------------------------------------------------------
# reset behaviour: clear flag and restart pattern from S0
# ---------------------------------------------------------
reset:
    li      t1, 0              # clear the reset flag
    jal     x0, iloop          # restart at S0 (li a0, 0)
