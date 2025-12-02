module hazard_unit#(
    parameter reg_addressing_width = 5
)
(
    input logic [reg_addressing_width-1:0] rs1D, 
    input logic [reg_addressing_width-1:0] rs2D,
    input logic [reg_addressing_width-1:0] rs1E, 
    input logic [reg_addressing_width-1:0] rs2E,
    input logic [reg_addressing_width-1:0] rdM,
    input logic [reg_addressing_width-1:0] rdE, 
    input logic [reg_addressing_width-1:0] rdWB,
    input logic regWriteM,
    input logic [1:0] resultSrCE,
    input logic JumpE,
    input logic false_prediction,
    input logic WriteBack_Regfile,
    input logic [1:0] csr_typeD,
    input logic [1:0] csr_typeE,
    input logic [1:0] csr_typeM,
    input logic [1:0] csr_typeW,
    input logic [11:0] csr_addrD,
    input logic [11:0] csr_addrE,
    input logic [11:0] csr_addrM,
    input logic [11:0] csr_addrW,
    output logic [1:0] selectline1,
    output logic [1:0] selectline2,
    output logic flush_d_exec,
    output logic flush_f_d,
    output logic F_Write,
    output logic PCWrite



    //we replace the input PCSrcE with false prediction because we don't want to flush everytime a jump/branch is taken, we want to flush everytime the branch predictor makes an incorrect guess
);
    
//forwarding:

always_comb begin
    //Default:no forwarding
    selectline1 = 2'b00;
    selectline2 = 2'b00;

    //Operand1 forwarding
    if (regWriteM && rdM != 0 && rdM == rs1E) begin
        selectline1 = 2'b10;  //from MEM stage
    end 
    else if (WriteBack_Regfile && rdWB !=0 && rdWB == rs1E) begin
        selectline1 = 2'b01;  //from WB stage
    end

    // Operand 2 forwarding
    if (regWriteM && rdM !=0 && rdM == rs2E) begin
        selectline2 = 2'b10;
    end 
    else if (WriteBack_Regfile && rdWB !=0 && rdWB == rs2E) begin
        selectline2 = 2'b01;
    end

end
    
logic wStall;
logic csrStall;


assign wStall = (resultSrCE == 2'b01) &&
                 ( (rdE != 0) &&
                   ( (rdE == rs1D) || (rdE == rs2D) ) );

assign csrStall = (|csr_typeD) && ( // check if the current instruction is csr type
                    ( (|csr_typeE) && (csr_addrE == csr_addrD)) || // check if the one before was csr and had data dependancies
                        ( (|csr_typeM) && (csr_addrM == csr_addrD)) ||  // check if the one in memory stage was csr and had data dependancies
                            ( (|csr_typeW) && (csr_addrW == csr_addrD)) // check the one in writeback
                    );


always_comb begin

    // Default: no stall, and no flush
    PCWrite     = 1;
    F_Write = 1;
    flush_d_exec = 0;
    flush_f_d = 0;

    if(false_prediction || JumpE) begin
        flush_f_d = 1;
        flush_d_exec = 1;
    end

    if(wStall || csrStall) begin
        PCWrite     = 0;
        F_Write = 0;
        flush_d_exec = 1;
    end



end

endmodule
