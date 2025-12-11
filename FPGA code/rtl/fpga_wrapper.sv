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
    logic trigger_raw;
    logic trigger_clean;
    logic [31:0] cpu_a0;
    logic rst_n_meta;  
    logic cpu_rst;     
	 logic rst_n_sync;
    
	 always_ff @(posedge cpu_clk) begin
        rst_n_meta <= KEY[1];
        rst_n_sync <= rst_n_meta;
    end
    
	 assign cpu_rst = ~rst_n_sync; 
	 
	
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
	 
	 top top (
        .clk(cpu_clk),
        .rst(cpu_rst),
        .trigger(trigger_clean), // trigger pulse doesnt work for some reason
        .a0(cpu_a0),
        .leds(LED_FPGA)           
    );
    

    sevensegment s0 ( 
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

    sevensegment s5 ( 
        .hex_in(cpu_a0[23:20]), 
        .hex_out(SEGMENT5)
        ); 

endmodule
