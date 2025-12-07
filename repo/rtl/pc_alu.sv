module pc_alu #(
    parameter DATA_WIDTH = 32  
) (
    input  logic [DATA_WIDTH-1:0] PCE,
    input  logic [DATA_WIDTH-1:0] ExtImmE,
    output logic [DATA_WIDTH-1:0] Jump
);

    always_comb begin
        Jump = ExtImmE + PCE;
    end

endmodule
