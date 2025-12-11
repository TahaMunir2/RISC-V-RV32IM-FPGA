.text
.globl _start

_start:
    la   x5, trap_handler # Load address of handler into x5
    csrw 0x305, x5 # Write x5 to mtvec
    li   x5, 0x8  # Load 8 (binary 1000)
    csrs 0x300, x5 # Set bit 3 in mstatus
    li   x5, 0x800 # Load 0x800 (binary 100000000000)
    csrs 0x304, x5  # Set bit 11 in mie     
wait_loop:
    j    wait_loop
trap_handler:
    li   a0, 0xCAFEBABE   
    mret
    

    