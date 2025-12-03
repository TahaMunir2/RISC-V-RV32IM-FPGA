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

    logic [2*DATA_WIDTH-1:0] mtime;
    logic [2*DATA_WIDTH-1:0] mtime_ref;
    
    always_ff @(posedge clk) begin
        if(rst) begin
            mtime <= '0;
            mtime_ref <= '1;
        end else begin
            mtime <= mtime + 1; 
            
            if(we) begin
                if (addr == 32'h8000_1000) mtime_ref[31:0]  <= data;
                if (addr == 32'h8000_1004) mtime_ref[63:32] <= data;
            end
        end
    end
    
    always_comb begin
        if (mtime >= mtime_ref) timer_interrupt = 1;
        else timer_interrupt = 0;
    end
    
endmodule
