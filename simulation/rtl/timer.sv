module timer #(
    parameter DATA_WIDTH = 32
)(
    input logic                     clk,
    input logic                     rst,
    input logic                     we,
    input logic [DATA_WIDTH-1:0]    addr,
    input logic [DATA_WIDTH-1:0]    data, 
    output logic                    timer_interrupt
);
    logic [63:0] mtime;      // 64-bit counter
    logic [63:0] mtime_ref;  // 64-bit reference
    
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
    
endmodule
