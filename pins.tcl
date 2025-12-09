# 1. CLOCK
set_location_assignment PIN_P11 -to cpu_clk
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to cpu_clk

# 2. KEYS (Buttons)
set_location_assignment PIN_B8 -to KEY[0]
set_location_assignment PIN_A7 -to KEY[1]
set_instance_assignment -name IO_STANDARD "3.3 V SCHMITT TRIGGER" -to KEY[0]
set_instance_assignment -name IO_STANDARD "3.3 V SCHMITT TRIGGER" -to KEY[1]

# 3. LEDs
set_location_assignment PIN_A8 -to LED_FPGA[0]
set_location_assignment PIN_A9 -to LED_FPGA[1]
set_location_assignment PIN_A10 -to LED_FPGA[2]
set_location_assignment PIN_B10 -to LED_FPGA[3]
set_location_assignment PIN_D13 -to LED_FPGA[4]
set_location_assignment PIN_C13 -to LED_FPGA[5]
set_location_assignment PIN_E14 -to LED_FPGA[6]
set_location_assignment PIN_D14 -to LED_FPGA[7]
set_location_assignment PIN_A11 -to LED_FPGA[8]
set_location_assignment PIN_B11 -to LED_FPGA[9]
# Set Voltage for ALL LEDs
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to LED_FPGA[*]

#3 Displays
# SEGMENT0
set_location_assignment PIN_C14 -to SEGMENT0[0]
set_location_assignment PIN_E15 -to SEGMENT0[1]
set_location_assignment PIN_C15 -to SEGMENT0[2]
set_location_assignment PIN_C16 -to SEGMENT0[3]
set_location_assignment PIN_E16 -to SEGMENT0[4]
set_location_assignment PIN_D17 -to SEGMENT0[5]
set_location_assignment PIN_C17 -to SEGMENT0[6]
set_location_assignment PIN_D15 -to SEGMENT0[7]

# SEGMENT1
set_location_assignment PIN_C18 -to SEGMENT1[0]
set_location_assignment PIN_D18 -to SEGMENT1[1]
set_location_assignment PIN_E18 -to SEGMENT1[2]
set_location_assignment PIN_B16 -to SEGMENT1[3]
set_location_assignment PIN_A17 -to SEGMENT1[4]
set_location_assignment PIN_A18 -to SEGMENT1[5]
set_location_assignment PIN_B17 -to SEGMENT1[6]
set_location_assignment PIN_A16 -to SEGMENT1[7]

# SEGMENT2
set_location_assignment PIN_B20 -to SEGMENT2[0]
set_location_assignment PIN_A20 -to SEGMENT2[1]
set_location_assignment PIN_B19 -to SEGMENT2[2]
set_location_assignment PIN_A21 -to SEGMENT2[3]
set_location_assignment PIN_B21 -to SEGMENT2[4]
set_location_assignment PIN_C22 -to SEGMENT2[5]
set_location_assignment PIN_B22 -to SEGMENT2[6]
set_location_assignment PIN_A19 -to SEGMENT2[7]

#  SEGMENT3
set_location_assignment PIN_F21 -to SEGMENT3[0]
set_location_assignment PIN_E22 -to SEGMENT3[1]
set_location_assignment PIN_E21 -to SEGMENT3[2]
set_location_assignment PIN_C19 -to SEGMENT3[3]
set_location_assignment PIN_C20 -to SEGMENT3[4]
set_location_assignment PIN_D19 -to SEGMENT3[5]
set_location_assignment PIN_E17 -to SEGMENT3[6]
set_location_assignment PIN_D22 -to SEGMENT3[7]

#  SEGMENT4
set_location_assignment PIN_F18 -to SEGMENT4[0]
set_location_assignment PIN_E20 -to SEGMENT4[1]
set_location_assignment PIN_E19 -to SEGMENT4[2]
set_location_assignment PIN_J18 -to SEGMENT4[3]
set_location_assignment PIN_H19 -to SEGMENT4[4]
set_location_assignment PIN_F19 -to SEGMENT4[5]
set_location_assignment PIN_F20 -to SEGMENT4[6]
set_location_assignment PIN_F17 -to SEGMENT4[7]

#SEGMENT5
set_location_assignment PIN_J20 -to SEGMENT5[0]
set_location_assignment PIN_K20 -to SEGMENT5[1]
set_location_assignment PIN_L18 -to SEGMENT5[2]
set_location_assignment PIN_N18 -to SEGMENT5[3]
set_location_assignment PIN_M20 -to SEGMENT5[4]
set_location_assignment PIN_N19 -to SEGMENT5[5]
set_location_assignment PIN_N20 -to SEGMENT5[6]
set_location_assignment PIN_L19 -to SEGMENT5[7]

# FORCE ALL SEGMENTS TO 3.3V
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to SEGMENT0[*]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to SEGMENT1[*]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to SEGMENT2[*]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to SEGMENT3[*]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to SEGMENT4[*]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to SEGMENT5[*]
