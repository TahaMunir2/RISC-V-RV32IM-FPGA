module fpga_wrapper(
    input  logic cpu_clk,      
    input  logic [1:0] KEY,     
    output logic [9:0] LED_FPGA,
    output logic [7:0] SEGMENT0,
    output logic [7:0] SEGMENT1,
    output logic [7:0] SEGMENT2,
    output logic [7:0] SEGMENT3,
    output logic [7:0] SEGMENT4,
    output logic [7:0] SEGMENT5
);

    logic cpu_rst;
    logic trigger_raw;
    logic trigger_clean;
    logic [31:0] cpu_a0;

    assign cpu_rst = ~KEY[0]; // Key 0 is reset
    assign trigger_raw = ~KEY[1]; // Key 1 is trigger

    debouncer debouncer(
        .clk(cpu_clk),
        .rst(cpu_rst),
        .trigger(trigger_raw),
        .trigger_clean(trigger_clean)
    );

    top top (
        .clk(cpu_clk),
        .rst(cpu_rst),
        .trigger(trigger_clean),
        .a0(cpu_a0),
        .leds(LED_FPGA)           
    );

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

endmodule
