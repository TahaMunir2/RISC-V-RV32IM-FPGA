# Interrupts and FPGA

## Table of Contents
- [1. Overview](#overview)
    - [1.1 Interrupts](#interrupts)
    - [1.2 FPGA](#fpga)
- [2. Implementation](#implementation)
    - [2.1 Interrupts](#interrupts-1)
        - [2.1.1 CSR](#csr)
        - [2.1.2 Hazard Unit](#hazard-unit)
        - [2.1.3 PC Block](#pc-block)
        - [2.1.4 Timer](#timer)
        - [2.1.5 Top Level Integration](#top-level-integration)
    - [2.2 FPGA](#fpga-1)
        - [2.2.1 Memory](#memory)
        - [2.2.2 Top](#top)
        - [2.2.3 GPIO](#gpio)
        - [2.2.4 7-Segment Display](#7-segment-display)
        - [2.2.5 Debouncer](#debouncer)
        - [2.2.6 FPGA Wrapper](#fpga-wrapper)
        - [2.2.7 Pins](#pins)
- [3. Schematic](#3-schematic)
- [4. Testing](#4-testing)
    - [4.1 Interrupts and Simulation](#interrupts-and-simulation)
        - [4.1.1 External Interrupts](#external-interupts)
        - [4.1.2 Timer Interrupts](#timer-interrupts)
    - [4.2 FPGA](#fpga-2)
        - [4.2.1 LEDs and 7-Segment Displays Test](#leds-and-7-segment-displays-test)
        - [4.2.2 External Interrupt Test](#external-interrupt-test)
        - [4.2.3 Timer Interrupt Test](#timer-interrupt-test)
        - [4.2.4 F1 Lights](#f1-lights)

## Overview

### Intro to Branch

This branch contains both the code for making external and timer interrupts work in simulation and on an FPGA. You can skip ahead to see the video of F1 Lights working on an FPGA with external interrupts and a trap handler [here](#f1-lights). There are 3 files, 1 for the tb and rtl for simulation, 1 for the FPGA hardware files and 1 for the FPGA .mif files to initialise the ROM.

### Interrupts

We previously defined a CSR module and added some instructions to play around with the CSR's however, we also mentioned how each register has a special predetermined purpose and can be used for a variety of use cases. The use case we will delve into is **interrupts**, as these enable our CPU to interact with the outside world and also add additional functionality to our CPU. 

Let's start by talking about privilege levels. There are 3 privilege levels in the RV32I CPU: Machine Mode (highest privilege), Supervisor and User (lowest privilege). Depending on the privilege level that the CPU is currently in, certain CSRs might not be available, as they are only available to high privilege levels for security purposes; however, Machine mode can access all the CSRs. For this project, we can assume that we are always in Machine Mode and no other privilege level exists on our CPU; hence, the registers we define are exclusive to M-mode and would theoretically not be available in lower privilege levels. This also means we do not need to deal with complex ideas such as delegations. 

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/privelege.png)

Next, let's talk about the trap handler. The trap handler is a specific piece of code stored somewhere on the instruction memory, and it is only accessed when a "trap" is called. There are technically multiple different trap handlers corresponding to each privilege level; however, as we are only in M-mode, we only have 1. A trap can be either an interrupt (like external interrupts or timer interrupts) or an exception (like **`ecall`** or dividing by 0, etc), and the trap handler is called to deal with them. We will only be dealing with interrupts in this section; however, similar logic can be derived for exceptions.

When an interrupt is called, we must immediately drop everything and enter the trap handler, if we are allowed to (this will be discussed later). However, in a pipelined CPU, this means we need to flush everything that isn't in the Memory or Writeback stage, as we will be returning to the instruction running in the Execution stage after we exit the trap handler. It is the programmer's responsibility to save the registers when dealing with a trap; however, it is the hardware's responsibility to save the return address for the trap handler. The code in the trap handler is all written by the programmer, so it will do whatever they want it to, and then at the end they must call the **`mret`** instruction that allows us to return to whatever process we were in.

Now we need to define how interrupts can happen in our CPU. We will define 2 types of interrupts: External Interrupts and Timer Interrupts (there are also Software Interrupts; however, we don't define them). External Interrupts will replace our current trigger functionality. Now, when a trigger pulse is received, we perceive it as an external interrupt (in our FPGA, we will use one of the keys as a trigger, which is why we our defining it here). We will also add a new module in our CPU called the timer, which counts up to a certain reference value defined by the programmer and sends a timer interrupt pulse when it reaches that value (and then resets and counts again). These will be the 2 ways we enter the trap handler.

To allow these interrupts to occur, we need to define 7 special registers that will aid us with these interrupts, although in proper RISC-V there are many more for a variety of reasons we do not need to consider:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/m.png)

#### mtvec: 0x305
This CSR simply stores the address of where the trap handler program is stored. Theoretically, there are also utvec and stvec for the trap handlers of different privilege levels. This needs to be written by the programmer using the CSR instructions we previously defined, or else we will not know where to jump to for the trap handler. 

#### mepc: 0x341
This CSR stores the return address after we finish running the trap handler. This is written by the hardware right before we enter the trap handler.

#### mecause: 0x342
This CSR tells us what caused us to enter the trap handler. The top bit is high for interrupts (always will be true for our case) and low for exceptions. We set bit 7 for M-mode timer interrupts and bit 11 for M-mode external interrupts. This can be used by the trap handler to determine how to deal with the trap.

#### mscratch: 0x340
This is an extra register that can be used for "scratch work"; it is essentially a general-purpose register.

#### mstatus: 0x300
This is the status register; it is the global interrupt enable and tells us if any type of interrupt can occur (there are also interrupt-specific enables for each type of interrupt that we define later, and both need to be enabled for a trap to be taken). Bit 3 of mstatus tells us if interrupts can occur or not, and when an interrupt is called, that state is saved in bit 7 and bit 3 is overwritten with 0 (to stop infinite loops of going back into the trap handler) and bit 3 is restored once mret is called.

#### mip: 0x344
This CSR tells us if there is an interrupt pending. When an interrupt comes in, either bit 7 (for timer interrupts) is set, or bit 11 is set (for external interrupts). This is so that an interrupt that comes in as a pulse is not missed if we are already in the trap handler, for example.

#### mie: 0x304
This is the interrupt enable; bit 7 needs to be high for timer interrupts to be able to occur, and bit 11 for external interrupts. This needs to be set by the programmer. We can think of this like a local enable if mstatus is a global enable.

Therefore, we need mstatus[3], mip[7] and mie[7] to all be high to enter the trap handler for a timer interrupt (and for external interrupts, replace the 7's with 11's).

### FPGA

An FPGA (Field Programmable Gate Array) is a programmable integrated circuit which can form physical implementations of digital circuits described in HDLs. They are made of a matrix of configurable logic blocks (which can be further broken down into flip-flops, lookup tables and full adders) with configurable interconnects that allow FPGAs to create real digital circuits. The DE-10 lite FPGA that we were able to borrow from EEStore comes with 50,000 logic elements, 200 KB of BRAM, 6 7-segment displays and 10 individually addressable LEDs.

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/de10.jpeg)

We knew we had to use the BRAM to define the memory, or else the FPGA would use logic elements instead for each register, which would be terribly inefficient and slow and might not work at all. The BRAM on an FPGA are broken into ~1KB blocks called M9k BRAM blocks, which are synchronous are extremely fast and are similar to RAM used in PC's. However, to implement these, we would need to change our ROM and RAM to be read synchronously.

We were able to get everything from the full RV32I instruction set, along with pipelining, as well as external interrupts and timer interrupts, with a trap handler in machine mode working on our FPGA all running at the full 50 MHz and then make our own version of F1 lights in assembly to run on the FPGA.

## Implementation:

### Interrupts:

#### CSR:

We simplified our 4096 address register to a register of size 7 with all other addresses mapping back to the mscratch register. This was so we didn't use up a whole lot of logic on the FPGA, but also because we would only be using these CSRs going forward. We did this using a case statement as shown below:

```systemverilog
    logic[DATA_WIDTH-1:0] csr_array[7];

    always_comb begin
        case(addr)
            12'h300: mapped_address = 0; // mstatus 
            12'h304: mapped_address = 1; // mie
            12'h305: mapped_address = 2; // mtvec
            12'h341: mapped_address = 3; // mepc
            12'h342: mapped_address = 4; // mcause
            12'h344: mapped_address = 5; // mip
            default: mapped_address = 6; // scratch register
        endcase

        dout = csr_array[mapped_address]; 
```

We also needed to add logic to tell our CPU where to go (when going to or returning from the handler. **`mret_en`** is a signal from the control unit that tells us if an MRET assembly instruction has been called.

```systemverilog
  handler_address =   mret_en ? csr_array[3] : csr_array[2]; // are we going or returning
```

Some internal signals were defined for the interrupt logic with trap_en being an output signal to be used by the pc_block unit:

```systemverilog
    assign global_en = csr_array[0][3]; // the MIE bit allows all interrupts to occur
    assign int_ext_en = csr_array[1][11]; // the MEIE bit tells us if an external interrupt can occur
    assign int_tim_en = csr_array[1][7]; // the MTIE bit tells us if an external interrupt can occur
    assign int_ext_p = csr_array[5][11]; // the MEIP bit tells us if there's an external interrupt pending
    assign int_tim_p = csr_array[5][7]; // the MTIP bit tells us if there's a timer interrupt pending
    assign trap_en = (global_en && ((int_ext_en && int_ext_p) || (int_tim_en && int_tim_p) ) );
    // if interrupts are enabled and there is a certain type of interrupt pending, and that type is enabled, then enter the trap handler
```

And the interrupt logic is defined as shown:

```systemverilog
      csr_array[5][11] <= external_interrupt; // initialise pending que
            csr_array[5][7] <= timer_interrupt; 

            if(trap_en) begin

                csr_array[3] <= PCE; // save the instruction we are on into mepc
                csr_array[0][7] <= csr_array[0][3]; // save the value of MIE into MPIE
                csr_array[0][3] <= 1'b0; // disable interrupts while we handle this one

                if(int_ext_en && int_ext_p) csr_array[4] <= 32'h8000000B; // standard cause code for MEI
                else if (int_tim_en && int_tim_p) csr_array[4] <= 32'h80000007; // standard cause code for MT
           
            end else if (mret_en) begin
                
                csr_array[0][3] <= csr_array[0][7]; // get back enable value
                csr_array[0][7] <= 1'b1; // reset to 1
                
                end

            else if(en) csr_array[mapped_address] <= temp; // we only fully write into the scratch register
```

#### Hazard Unit

Obviously, for this new interrupt logic, we would need to update the Hazard Unit for flush logic as we discussed in the overview, adding a new em flush:

```systemverilog
        if (trap_en) begin 
            flush_f_d    = 1'b1;
            flush_d_exec = 1'b1;
            flush_e_m    = 1'b1;
        end

        else if (mret_en) begin
            flush_f_d = 1'b1;
            flush_d_exec = 1'b1;
        end
```
- Note: We don't flush the fd and de stages after mret is called in case there is some garbage data there.

#### PC Block

We also needed to update PC_block to jump to and from our new trap handler:

```systemverilog
    else if(trap_en || mret_en) internal_pc <= handler_address;
```

#### Timer
```systemverilog
    always_ff @(posedge clk) begin
        if(rst) begin
            mtime     <= '0;
            mtime_ref <= '1; // set to max value on reset so it doesn't trigger immediately
        end else begin
            // default
            mtime <= mtime + 1;

            if(we) begin
                // lower 32 bits 
                if (addr == 32'h80001000) begin
                    mtime_ref[31:0] <= data;
                    
                    // Reset the counter to 0
                    mtime <= '0; 
                end
                
                // upper 32 bits
                if (addr == 32'h80001004) begin
                    mtime_ref[63:32] <= data;
                end
            end
        end
    end
    

    always_comb begin
        if (mtime >= mtime_ref) 
            timer_interrupt = 1'b1; // time is above ref
        else 
            timer_interrupt = 1'b0;
    end
```

- We also implemented a Timer with the unused memory addresses 80001000 and 80001004 being used for the lower and upper 32 bits of the reference time, respectively. 
- This meant store word instructions to those addresses actually set the time for the timer.
- Once the time was set, the timer would restart and resend a high signal once it reached the reference time.
- If untouched, the timer would not send out a timer interrupt for 1000s of years at a clock frequency of 50 MHz.

#### Top Level Integration

We needed to add some safeguarding for the **`we`** in the timer:

```systemverilog
      assign timer_write_en = MemWriteM && (ALUResultM[31:4] == 28'h8000100);
```

We also added a new wire called PCE_Special that didn't get flushed in the DE pipeline, as in simulation, we were getting an issue where PCE gets reset; however, for some reason, on the FPGA, it works just fine, and PCE_Special doesn't.

### FPGA:

Before I describe what we implemented in the FPGA, I must tell you what we omitted; we branched off the Z extension branch, so superscalar and cache were not included in the rtl, due to time restraints, and they were still being developed, and fears of complexity added by them. M instructions were removed as division was causing huge timing delays in compilation in Quartus. Branch prediction and evalprediction modules had to be removed as memory was changed to synchronous, which meant their logic no longer applied, and a buffer and much more complex logic would need to be thought up to keep their functionality. This meant Z instructions and Full RV32I with Pipelining were still included in our FPGA implementation.

To program the FPGA, we had to use a program called Quartus. We were able to put our .sv files onto Quartus and use its many, many features to set up the right conditions for the FPGA to allow us to port our CPU onto it.

The first hurdle was the memory; as we discussed, we would need to use 2 BRAM blocks. First, imem: It would need 1024, 32-bit words called imem_ram, which we will call inside the insmem module. We MUST make sure to uncheck make the output registered or else it will take 2 cycles to read (I had this issue for days). For this imem block, we would also need to initialise its memory content using a program. mif file where we will write the instruction memory code (similar to our program.hex files). This insmem would now be clocked too, making reading from it synchronous. We initialise a new block inside our in-memory block like so:

#### Memory:

```systemverilog
    imem_ram imem_inst (
        .clock   (clk),
        .address (word_index),
        .data    (32'b0),   // never write
        .wren    (1'b0),
        .q       (q)
    );
```

- Note word_index is the address with the bottom 2 bits taken out, as they are always assumed to be 0.

We would follow the same process as above from datamem, however, now with 32768 32-bit words, and with byte-enable indexing turned on and no memory initialisation. We would need to compute the byteena logic as follows:

```systemverilog
    always_comb begin
        byteena = 4'b0000;
        case (SizeWrite)
            2'b00: begin
                // store byte
                byteena = 4'b0001 << byte_offset;
            end
            2'b01: begin
                // store halfword 
                if (byte_offset[1] == 1'b0)
                    byteena = 4'b0011;
                else
                    byteena = 4'b1100;
            end
            default: begin
                // store word
                byteena = 4'b1111;
            end
        endcase
    end
```

And now we would need to call the new dmem_ram inside the datamem module:

```systemverilog
    dmem_ram dmem_inst (
        .clock   (clk),
        .address (word_index),
        .data    (WD),
        .wren    (MemWrite),
        .byteena (byteena),
        .q       (raw_word)
    );
```
- Note **`raw_word`** is the word without load-size or load-sign logic implemented.

#### Top:
We must take note that, as reading memory is now synchronous, we must not pass the outputs of the memory blocks through the pipeline registers; instead, they can go straight to the next stage.

However, this also means we must now change the logic, as our previous instructions assumed that we had synchronous reads. This includes adding a stall buffer in top, as when we call stall, our BRAM has already gotten our instruction, and if we don't hold onto it will get overwritten and lost:

```systemverilog
    always_ff @(posedge clk) begin
        if (rst) begin
            Stall_Active <= 0;
            InstrD_Saved <= 0;
        end else begin
            Stall_Active <= flush_d_exec; 
            if (flush_d_exec && !Stall_Active) begin
                InstrD_Saved <= InstrF_raw;
            end
        end
    end
```
We must also kill the cycle that occurs while we are branching, as even though we update the address our ROM is accessing, as it is asynchronous, it still grabs the previous address, which will run an instruction we don't want to run:

```systemverilog
    always_ff @(posedge clk) begin
        if (rst) kill_cycle <= 0;
        else kill_cycle <= (JumpE || false_prediction || trap_en || mret_en); 
    end

    assign InstrF = (kill_cycle || rst) ? 32'h00000013 : // addi x0, x0, 0 or NOP
                    (Stall_Active) ? InstrD_Saved : InstrF_raw;
```

We also need to deal with RAW (read after write) hazards in the decode stage, while there are data dependancies in the writeback stage, by skipping the registers and forwarding directly:

```systemverilog
    always_comb begin
    if (RegWriteW && (Rs1D != 0) && (Rs1D == RdW)) RD1D_Correct = ResultW;
    else  RD1D_Correct = RD1D;

    if (RegWriteW && (Rs2D != 0) && (Rs2D == RdW))  RD2D_Correct = ResultW;
    else RD2D_Correct = RD2D;
    end
```

Now that the hazards are all dealt with, we can focus on adding FPGA-specific hardware to our SystemVerilog code. This includes GPIO (for LEDS), 7-segment display mapping, a debouncer and an FPGA Wrapper.

#### GPIO:

The DE-10 lite has 10 addressable LEDs, so we can again use the unused memory addresses to map one address to change the pattern of the LEDs. We picked address 80002000 and store words instructions to that address would now be able to control the pattern by using the bottom 10 bits of the word they are storing, with each bit representing one of the LEDs. The actual mapping of LED bits to LEDS was done using a TCL file that will be described later.

```systemverilog
module gpio #(
    parameter DATA_WIDTH = 32
    )(
    input  logic        clk,
    input  logic        rst,
    input  logic        we,
    input  logic [DATA_WIDTH-1:0] data,
    output logic [9:0]  leds     // 1 bit per LED
);
    always_ff @(posedge clk) begin
        if (rst) leds <= 10'b0; // reset leds
        else if (we) leds <= data[9:0]; // set leds
    end
```

For the **`we`** signal, we made a simple assignment in top.sv:

```systemverilog
    assign gpio_wen = MemWriteM && (ALUResultM[DATA_WIDTH-1:0] == 32'h80002000);
```

#### 7-Segment Display:

Since there are 6 7-segment displays, we can display the bottom 24 bits of a0 on the FPGA. To do this, we need to map 4 bits at a time to a display in the FPGA wrapper file and then map those displays in the TCL file.

```systemverilog
module sevensegment (
    input  logic [3:0] hex_in,
    output logic [7:0] hex_out 
);
    always_comb begin // for some reason the leds in a 7 segment display are active low
        case (hex_in)
            4'h0: hex_out = 8'b11000000;
            4'h1: hex_out = 8'b11111001;
            4'h2: hex_out = 8'b10100100;
            4'h3: hex_out = 8'b10110000;
            4'h4: hex_out = 8'b10011001;
            4'h5: hex_out = 8'b10010010;
            4'h6: hex_out = 8'b10000010;
            4'h7: hex_out = 8'b11111000;
            4'h8: hex_out = 8'b10000000;
            4'h9: hex_out = 8'b10010000;
            4'hA: hex_out = 8'b10001000;
            4'hB: hex_out = 8'b10000011;
            4'hC: hex_out = 8'b11000110;
            4'hD: hex_out = 8'b10100001;
            4'hE: hex_out = 8'b10000110;
            4'hF: hex_out = 8'b10001110;
            default: hex_out = 8'b1_1111111; // everything is off (1 is off and 0 is on)
        endcase
    end 
endmodule
```
- Note: The bits on the 7-segment display are active low so to turn one on, we set it to 0.

We can then define these in the FPGA wrapper as follows, with each segment being an output of the CPU:

```systemverilog
    sevensegment s0 ( // Lower 4 bits
        .hex_in(cpu_a0[3:0]),
        .hex_out(SEGMENT0)
        ); 

    sevensegment s1 (
        .hex_in(cpu_a0[7:4]),   
        .hex_out(SEGMENT1)
        );

    sevensegment s2 (
        .hex_in(cpu_a0[11:8]),  
        .hex_out(SEGMENT2)
        );

    sevensegment s3 (
        .hex_in(cpu_a0[15:12]), 
        .hex_out(SEGMENT3)
        );

    sevensegment s4 (
        .hex_in(cpu_a0[19:16]), 
        .hex_out(SEGMENT4)
        );

    sevensegment s5 ( // upper 4 bits
        .hex_in(cpu_a0[23:20]), 
        .hex_out(SEGMENT5)
        ); 
```

#### Debouncer

Now is where everything gets particularly tricky. We need to convert real-world actions into digital signals, only using digital logic. For example, we need a trigger pulse from pressing the button; however, if we just keep the button as an input (which we will do using the TCL file), without processing it first, it will lead to 100,000s of cycles of interrupt requests, which could very well break our program. We need something called a "debouncer" to wait for the signal to stop "bouncing" (as shown below) between high and low and become stable, and then an edge detector to only take in 1 pulse, so our external interrupt works as it does in simulation.

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/debounce.png)

The debouncing logic relies on 2 stages, one stage which removes metastability and a second stage that implements a timer for 2^20 cycles (20 ms at 50 MHz) to wait for a non-bouncy signal

```systemverilog
  logic [TIMER_WIDTH-1:0] timer;

    logic safety_stage, stable_input; // we need these to prevent metastability, as this adds a 1 clock cycle delay for the signal to stabilise before we put it into our logic circuit

    always_ff @(posedge clk) begin // stability stage added for safekeeping
        if (rst) begin
            safety_stage <= 0; 
            stable_input <= 0;
        end else begin
            safety_stage <= trigger; 
            stable_input <= safety_stage; // adds a 1 clock cycle delay to stabilise the input
        end
    end

    always_ff @(posedge clk) begin
        if (rst) begin 
            timer <= '0; 
            trigger_clean <= 0;
        end
        else begin
            if (stable_input) begin   // if trigger is high, we can start timing
                if (trigger_clean == 0) begin // if we are still waiting for stability
                    timer <= timer + 1;  // increment the timer
                    if (&timer) trigger_clean <= 1; //  if we hit the max value of the timer, output the clean value
                end
            end 
            else begin // if trigger is low, we can turn it off
                timer <= 0; 
                trigger_clean <= 0; 
            end
        end
    end
```

We then implement an edge detector in the FPGA wrapper because even after 20ms of holding the button will send a very large amount of external interrupts. Our Edge detector must operate under the logic that if the previous and next states are different, only then should the external interrupt go high. We use key[0] on the DE-10 lite as trigger.

```systemverilog
   assign trigger_raw = ~KEY[0]; // active low

    debouncer debouncer(
        .clk(cpu_clk),
        .rst(cpu_rst),
        .trigger(trigger_raw),
        .trigger_clean(trigger_clean)
    );
	
	 logic trigger_clean_prev;
	 logic trigger_pulse;
		

    always_ff @(posedge cpu_clk) begin
        trigger_clean_prev <= trigger_clean;
    end
	 
    assign trigger_pulse = trigger_clean && !trigger_clean_prev; // only high when trigger_clean is 1 and prev is 0
```

#### FPGA Wrapper

Finally, let's go over the actual FPGA Wrapper file. We already know how we define the 7-segment displays and trigger in this file but we also need it to interface with top.sv, the reset button and the FPGA itself with inputs and outputs as defined below:

```systemverilog
    input  logic cpu_clk,      
    input  logic [1:0] KEY,     
    output logic [9:0] LED_FPGA,
    output logic [7:0] SEGMENT0,
    output logic [7:0] SEGMENT1,
    output logic [7:0] SEGMENT2,
    output logic [7:0] SEGMENT3,
    output logic [7:0] SEGMENT4,
    output logic [7:0] SEGMENT5
```
- There are only 2 keys on the DE-10 Lite.

The Reset logic is similar to the Trigger logic, but for Reset, we don't need it to be as perfect as we can hold Reset.

```systemverilog
    logic rst_n_meta;  
    logic cpu_rst;     
	 logic rst_n_sync;
    
	 always_ff @(posedge cpu_clk) begin
        rst_n_meta <= KEY[1];
        rst_n_sync <= rst_n_meta;
    end
    
	 assign cpu_rst = ~rst_n_sync;
```

The top instantiation in the FPGA is quite simple; it just has the cleaned-up signals:

```systemverilog
	 top top (
        .clk(cpu_clk),
        .rst(cpu_rst),
        .trigger(trigger_pulse),
        .a0(cpu_a0),
        .leds(LED_FPGA)        
    );
```
#### Pins

Now we must make a .tcl file which just tells the FPGA how to configure the board with the outputs from the digital circuit to the hardware on the board, such as the clock, LEDs, display and Schmitt triggers. Looking at other projects done online on this board, I was able to work out how to set up the .tcl file for this implementation:

```
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
```

## 3 Schematic

Quartus actually provides you with an RTL netlist diagram:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/FPGA_schematic.png)


## 4 Testing

### Interrupts and Simulation

#### Running the code

1. Navigate to the testbench ( `tb` ) folder:
   ```bash
   cd repo/tb
   ```

2. Make scripts executable:
   ```bash
   chmod +x doit.sh assemble.sh
   ```
   Grant execution permissions to the assembly and run scripts.

3. Run the test:
   ```bash
   ./doit.sh tests/verify.cpp
   ```
   Execute the testbench with the verification file to validate the program.


#### External Interupts

We first edited our simulated circuit to have synchronous memory and then made test cases we could trace on gtkwave for debugging.

This first test case shows a simple program where the address of the trap handler is first written into MTVEC, then global interrupts are enabled, and then external interrupts are enabled, then we turn on trigger in verify.cpp.cpp and that changes the value of a0 to CAFEBABE.

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/external_interrupt.png)

This is done in verify.cpp via turning on a0 for a few cycles:

```cpp
	setupTest("interrupt_test"); 
    initSimulation();
    runSimulation(100);
    top_->trigger = 1;
    runSimulation(5); 
    top_->trigger = 0; 
    runSimulation(MAX_SIM_CYCLES);
    EXPECT_EQ(top_->a0, 3405691582); // 0xCAFEBABE
```
We can see on gtkwave that after the trigger goes high, we escape the loop and a0 is set to CAFEBABE.

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/external_gtk.png)

#### Timer Interrupts

The next test was to set the clock; this once was a bit longer as I wanted to show how good programming practice would require saving the registers and then getting them back if using them in the trap handler (as they are not automatically saved by the hardware). 

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/timer_interrupt.png)

- Lines 12-17 just enable global and timer interrupts to allow the trap handler to be entered.
- Lines 18-20 set the bottom LED to turn on.
- Lines 21-25 set the timer to wait 500 cycles (this would be very fast on the FPGA, but for our purposes, this is fine).
- Line 27 is an infinite wait loop.
- Once the timer reaches 500, we enter the trap handler 
- Lines 29-31 are the good programming practice I was talking about; they show how to save the registers in assembly.
- Lines 32-34 just change the LED so we can see that the timer interrupt has occurred.
- Lines 35-36 restart the timer (so this process repeats in 500 cycles).
- Lines 37-39 get back the original registers.
- Line 40 is mret, which returns to what we were doing before.

This is done in verify.cpp by doing:
```cpp
    setupTest("timer");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(100);
    EXPECT_EQ(top_->leds, 1); 
    runSimulation(450); // over 500 cycles at this point (it's not exactly 500 cycles due to setting it up)
    EXPECT_EQ(top_->leds, 255); 
```

Looking at GTKwave, we can see the LEDs flip after the time hits 500 and then flip back when it hits it the second time:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/timer_gtk1.png)

After another ~500 cycles

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/timer_gtk2.png)



### FPGA

Our first successful port onto an FPGA showed us these statistics:

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/fpga_stats.png)

Which matches up with the memory we expected. It is interesting to see that our design would need that many logic elements and registers.

#### LEDs and 7-Segment Displays Test

Firstly, we just wanted a simple test to check that our outputs and address mapping worked correctly on our FPGA.
```asm
WIDTH=32;
DEPTH=2048;
ADDRESS_RADIX=HEX;
DATA_RADIX=HEX;

CONTENT BEGIN
    00 : 800024B7; -- lui s1, 0x80002
    01 : 15500913;  -- addi s2, zero, 0x155 (10'b0101010101)
    02 : 0124A023;  -- sw s2, 0(s1)
    03 : 0000006F; -- jal x0, 0
    [04..7FF] : 00000000;
END;
```
- This program would first load an alternating pattern of 1's and 0's (Hex 255) into the address 8000200, which is the address we reserved for the LEDs's
- Then it would store that same value into a0, so the 7-segment displays should show 255.

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/leds_7.jpeg)
> That is exactly what we observed

#### External Interrupt Test

Next, we wanted to test out the  external interrupt logic and trap handler routine, as well as check if more complex instructions like branch and csrrw would work.

```asm
000 : BFC000B7; -- LUI x1, 0xBFC00 
001 : 03008093; -- ADDI x1, x1, 0x30 (x1 = 0xBFC00030, trap handler address)
002 : 30509073; -- CSRW mtvec, x1 
003 : 00800113; -- ADDI x2, x0, 8
004 : 30011073; -- CSRW mstatus, x2 (set MIE to 1)
005 : 00100193; -- ADDI x3, x0, 1
006 : 00B19193; -- SLLI x3, x3, 11
007 : 30419073; -- CSRW mie, x3 (enable external interrupts)
008 : 80002237; -- LUI x4, 0x80002 
009 : 00004537; -- LUI x10, 4      
00A : 44450513; -- ADDI x10, x10, 0x444 (x10 = 0x4444)
00B : 0140006F; -- JAL x0, 0x14 (d20 so 20 / 4 = 5 so 00B + 5 = 010 aka main)

-- Trap Handler 
00C : 00007537; -- LUI x10, 7
00D : 77750513; -- ADDI x10, x10, 0x777 (x10 = 0x7777)
00E : 00A22023; -- SW x10, 0(x4) (leds = 00 0100 0100 bottom 10 bits of 0x4444)
00F : 30200073; -- mret 

-- Main
010 : 00004537; -- LUI x10, 4
011 : 44450513; -- ADDI x10, x10, 0x444
012 : 00A22023; -- SW x10, 0(x4) (leds = 11 0111 0111 bottom 10 bits of 0x7777)
013 : FF4FF06F; -- JAL x0, -12 (address 010)
[014..3FF] : 00000000;
```

- The instructions 0-2 are used for setting up the trap handler address (BFC00030 when accounting for 4 bytes per instruction, goes to 010)
- 3-4 set MIE (global interrupts en) which is the third bit of mstatus
- 5-7 set mie for external interrupts
- 8-A set a0 to 4444
- B skips over the handler straight to 010 (this is to show the handler can be anywhere in the memory and that our jump instructions work)
- 10-11 reset a0 as if we return from a trap, we will return to this address)
- 12-13 set the LEDs in the pattern described above
- C-F is the trap handler; it is only ever accessed when the trap is triggered.


https://github.com/user-attachments/assets/d3bf95f0-1b92-4ace-abf1-3764e90d6b53
> We removed the pulse logic, as our CPU was not detecting it for some reason.

We can clearly see that external interrupts work on our FPGA.
Note: For some reason, our key[1] wasn't working on the FPGA we were given, so here we are using key[0] as trigger.

#### Timer Interrupt Test

Next, we wanted to out our timer interrupt logic for this we needed a test that would alternate the time every 'x' amount of time. 

```asm
000 : 0200006F; JAL x0, 32 (0x008)

-- Trap Handler
001 : 00150513; -- ADDI x10, x10, 1 (increment a0 by 1)
002 : 80002237; -- LUI x4, 0x80002 
003 : 00A22023; -- SW x10, 0(x4) (store a0 into the LEDs)
004 : 800012B7; -- LUI x5, 0x80001  
005 : 02000337; -- LUI x6, 0x02000 (set timer to 0x2000000 = 0.67 seconds at 50 MHz)
006 : 0062A023; -- SW x6, 0(x5)     
007 : 30200073; -- mret 

-- main
008 : 00400093; -- ADDI x1, x0, 4   
009 : 30509073; -- CSRW mtvec, x1 (trap handler address = 001)
00A : 00100193; -- ADDI x3, x0, 1
00B : 00719193; -- SLLI x3, x3, 7   
00C : 30419073; -- CSRW mie, x3 (enable bit 11 for timer interrupts)
00D : 00800113; -- ADDI x2, x0, 8 
00E : 30011073; -- CSRW mstatus, x2 (enable global interrupts) 
00F : 00000513; -- ADDI x10, x0, 0 
010 : 800012B7; -- LUI x5, 0x80001 
011 : 0002A223; -- SW x0, 4(x5) (clear upper 32 bits)
012 : 02000337; -- LUI x6, 0x02000 
013 : 0062A023; -- SW x6, 0(x5) (set lower bits)
014 : 0000006F; -- JAL x0, 0 (loop)
[015..3FF] : 00000000;
```
- 8-E set up the CSRs the same as before, but now for timers instead of trigger
- F just clears a0 to be safe
- 10-13 set the timer to be 33,554,432 cycles, which at 50MHz should only take about 2/3's of a second
- 14 is an infinite loop
- 1 (This is now in the trap handler) increments a0 by 1 (for our counter)
- 2-3 set the LEDs to display a0 (in binary)
- 4-6 reset the timer with the same value (our time resets if we set it)
- mret to go back to our infinite loop

This creates a simple binary counter with the value shown in Hex on the left, as shown below:

https://github.com/user-attachments/assets/702378ec-2748-4001-a209-32438d559ac6

## F1 Lights 

Finally, we wanted to recreate the F1 lights reaction test on our FPGA, now using our brand new timer and external interrupts for synchronisation and inputs.

First, I created this FSM model and defined 4 states for the implementation.

![diagram](https://github.com/TahaMunir2/Team5/blob/main/images/F1FSM.png)

- S0: We increment the amount of LEDs that are on 1 by 1 until they are all on.
- S1: Once they are all on, we wait 1 second and turn them off.
- S2: We start incrementing a0 to test reaction time.
- S3: If the trigger is pressed, then stop everything and display the reaction time.

This can be written in assembly for the .mif file as follows:

### Setup
```asm
000 : 00100513; -- ADDI x10, x0, 1
001 : 80002237; -- LUI x4, 0x80002
002 : 00A22023; -- SW x10, 0(x4) (turn on first LED)
003 : 10000093; -- ADDI x1, x0, 256
004 : 30509073; -- CSRW mtvec, x1 (set trap handler address (040))
005 : 00000513; -- ADDI x10, x0, 0 (x10 = 0)
006 : 00000A13; -- ADDI x20, x0, 0 (x20 = 0)
007 : 00000593; -- ADDI x11, x0, 0 (x11 = 0)
008 : 00100193; -- ADDI x3, x0, 1 (x3 = 1)
009 : 00719193; -- SLLI x3, x3, 7 (bit 7 = 1)
00A : 8001E193; -- ORI x3, x3, 0x800 (bit 11 and bit 7 = 1) 
00B : 30419073; -- CSRW mie, x3
00C : 00800113; -- ADDI x2, x0, 8
00D : 30011073; -- CSRW mstatus, x2 (MIE = 1)
00E : 800012B7; -- LUI x5, 0x80001
00F : 0002A223; -- SW x0, 4(x5) (clear upper bits)
010 : 02FAF337; -- LUI x6, 0x02FAF 
011 : 08030313; -- ADDI x6, x6, 0x080 (x6 = 50,000,000 or 1s at 50Mhz)
012 : 0062A023; -- SW x6, 0(x5)
013 : 0000006F; -- JAL x0, 0 (loop)
[014..03F] : 00000013;
```

### Trap Handler Setup
```asm
-- Trap Handler
040 : 342022F3; -- CSRR x5, mcause 
041 : 00F2F293; -- ANDI x5, x5, 15 (mask bottom 4 bits)
042 : 00B00313; -- ADDI x6, x0, 11 (Load 11)
043 : 06628663; -- BEQ x5, x6, Freeze (offset 112, if external interrupt then jump to state 3)
044 : 04059463; -- BNE x11, x0, Count-up (offset 72, if x11 is high, we are in state 2)
045 : 3FFA2A93; -- SLTI x21, x20, 0x3FF  (check if leds all high)
046 : 020A8063; -- BEQ x21, x0, Transition (offset 32, branch to transition if x21 is 0, state 1)
```

### State 0
```asm
-- LEDs light up (state 0):
047 : 001A1A13; -- SLLI x20, x20, 1  (turn next LED on: state 0)
048 : 001A6A13; -- ORI x20, x20, 1 (keep the previous LEDs on)
049 : 80002237; -- LUI x4, 0x80002
04A : 01422023; -- SW x20, 0(x4) (update LED)
04B : 02FAF337; -- LUI x6, 0x02FAF
04C : 08030313; -- ADDI x6, x6, 0x080 (prepare to load timer)
04D : 0380006F; -- JAL x0, Exit (offset 56)
```

### State 1
```asm
-- Transition (state 1)
04E : 00000A13; -- ADDI x20, x0, 0 (x20 = 0, turn off LEDs)
04F : 00100593; -- ADDI x11, x0, 1 (x11 = 1, go to state 2 next time)
050 : 00000513; -- ADDI x10, x0, 0 (reset x10)
051 : 80002237; -- LUI x4, 0x80002 
052 : 01422023; -- SW x20, 0(x4) (store LEDS to turn off)
053 : 0007A337; -- LUI x6, 0x0007A
054 : 12030313; -- ADDI x6, x6, 0x120 (prepare timer for 0.1s, 7A120 is 500,000)
055 : 0180006F; -- JAL x0, Exit (offset 24)
```

### State 2
```asm
-- Count-up (state 2)
056 : 00150513; -- ADDI x10, x10, 1 (increment a0)
057 : 80002237; -- LUI x4, 0x80002
058 : 00A22023; -- SW x10, 0(x4) (update LEDs to show x10)
059 : 0007A337; -- LUI x6, 0x0007A
05A : 12030313; -- ADDI x6, x6, 0x120 (reset timer for 0.1s)
```

### State 3
```asm
-- Freeze Logic (state 3)
05F : 30005073; -- CSRWI mstatus, 0  (turn off all interrupts)
060 : FFDFF06F; -- JAL x0, -4, (don't go back to main stay here)
[061..3FF] : 00000000;
```

### Trap Handler exit for States 0, 1 and 2
```asm
-- Exit (part of state 0, 1 and 2)
05B : 800012B7; -- LUI x5, 0x80001
05C : 0002A223; -- SW x0, 4(x5)
05D : 0062A023; -- SW x6, 0(x5) (set timer)
05E : 30200073; -- MRET
```

- We have made use of branch instructions to implement the FSM conditions.
- We have made use of the fact that the timer resets every time we set it, but also that we can change what it's set to.
- To stop the program once we press the trigger, we disable all interrupts after it is pressed and don't leave the trap handler.
- We increment a0 by 1 every 10ms, so to determine your reaction time, you must multiply a0 (in hex) by 0.01.

This leads to the satisfying demonstration below:

https://github.com/user-attachments/assets/2adacb26-7459-44d5-94f8-997369829358
> Note, we reused the binary counter logic here to show how cool it looks at a faster speed








