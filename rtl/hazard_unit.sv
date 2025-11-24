module hazard_unit#(
    parameter reg_addressing_width = 5
)
(
    input logic [reg_addressing_width-1:0] rs1D, 
    input logic [reg_addressing_width-1:0] rs2D,
    input logic [reg_addressing_width-1:0] rdM,
    input logic [reg_addressing_width-1:0] rdE, 
    input logic [reg_addressing_width-1:0] rdWB,
    input logic regWriteM,
    input logic PCSrcE, //branch taken
    input logic [1:0] resultSrCE,
    input logic WriteBack_Regfile,    
    output logic [1:0] selectline1,
    output logic [1:0] selectline2,
    output logic insert_nop_exec,
    output logic insert_nop_fd,
    output logic PF_PD_Write,
    output logic PCWrite
);

logic wstall;

assign wStall = (resultSrCE == 2'b01) &&
                 ( (rdE != 0) &&
                   ( (rdE == rs1D) || (rdE == rs2D) ) );


always_comb begin

    // Default: no stall, no flush
    PCWrite     = 1;
    PF_PD_Write = 1;
    insert_nop_exec = 0;
    insert_nop_fd = 0;

    if(PCSrcE == 1) begin
        insert_nop_fd = 1;
        insert_nop_exec = 1;
    end

    if(lwStall == 1) begin
        PCWrite     = 0;
        PF_PD_Write = 0;
        insert_nop_exec = 1;
    end






end






endmodule