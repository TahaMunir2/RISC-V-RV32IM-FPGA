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
            mtime_ref <= '1; // Set to max value on reset so it doesn't trigger immediately
        end else begin
            // Default: Increment the timer every cycle
            mtime <= mtime + 1;

            if(we) begin
                // Lower 32 bits (Address 0x80001000)
                if (addr == 32'h80001000) begin
                    mtime_ref[31:0] <= data;
                    
                    // --- THE FIX ---
                    // Reset the counter to 0 whenever we set a new delay.
                    mtime <= '0; 
                end
                
                // Upper 32 bits (Address 0x80001004)
                if (addr == 32'h80001004) begin
                    mtime_ref[63:32] <= data;
                end
            end
        end
    end
    
    // Interrupt fires when time >= reference
    always_comb begin
        if (mtime >= mtime_ref) 
            timer_interrupt = 1'b1;
        else 
            timer_interrupt = 1'b0;
    end
    
endmodule
