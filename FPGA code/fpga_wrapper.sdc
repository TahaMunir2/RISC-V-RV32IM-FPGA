# 1. REMOVE the existing "create_clock" for cpu_clk
#    (We will constrain the generated clock instead)

# 2. Define the 25 MHz clock directly on the internal net
#    Period = 40.000 ns (25 MHz)
create_clock -name {clk_25MHz} -period "40.000" [get_nets {clk_25MHz}]