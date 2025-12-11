.text
.globl _start

# consts
.eqv LED_ADDR,      0x80002000   
.eqv TIMER_LOW,     0x80001000   
.eqv TIMER_HIGH,    0x80001004   
# 500 cycles = 10 microseconds at 50MHz 
.eqv DELAY_VAL,     500          

_start:
    la      x5, trap_handler  # x5 = trap hanlder address 
    csrw    0x305, x5  # mtvec
    li      x5, 0x80   # enable MTIE
    csrs    0x304, x5  # mie
    li      x5, 0x8    #enable mie
    csrs    0x300, x5   # mstatus
    li      s1, LED_ADDR         
    li      t0, 0x1              
    sw      t0, 0(s1)  # LED 0 ON
    li      s2, TIMER_LOW        
    li      s3, TIMER_HIGH       
    sw      zero, 0(s3)          
    li      t0, DELAY_VAL
    sw      t0, 0(s2) # store into timer
wait_loop:
    j       wait_loop
trap_handler:
    addi    sp, sp, -16  # save t0, t1
    sw      t0, 0(sp)  
    sw      t1, 4(sp)
    lw      t0, 0(s1) # read state of leds           
    xori    t0, t0, 0xFF  # flip the leds
    sw      t0, 0(s1)            
    li      t1, DELAY_VAL # restart timer
    sw      t1, 0(s2)            
    lw      t1, 4(sp) # get old values back
    lw      t0, 0(sp) 
    addi    sp, sp, 16
    mret #return
    


