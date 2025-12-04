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

endmodule
