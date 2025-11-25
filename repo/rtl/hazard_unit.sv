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
    input logic [1:0] resultSrCE,
    input logic [1:0] resultSrCM,
    input logic WriteBack_Regfile,    
    output logic [1:0] selectline1,
    output logic [1:0] selectline2,
    output logic flush_d_exec,
    output logic flush_f_d,
    output logic F_Write,
    output logic PCWrite
);

logic wstall;
//logic lw_write_back;

assign wStall = (resultSrCE == 2'b01) &&
                 ( (rdE != 0) &&
                   ( (rdE == rs1D) || (rdE == rs2D) ) );


// assign lw_write_back = (resultSrCM == 2'b01) &&
//                  ( (rdM != 0) &&
//                    ( (rdM == rs1D) || (rdM == rs2D) ) );

always_comb begin

    // Default: no stall, no flush
    PCWrite     = 1;
    F_Write = 1;
    flush_d_exec = 0;
    flush_f_d = 0;

    if(PCSrcE == 1) begin
        flush_f_d = 1;
        flush_d_exec = 1;
    end

    if(wStall == 1) begin
        PCWrite     = 0;
        F_Write = 0;
        flush_d_exec = 1;
    end

    // if(lw_write_back == 1) begin
    //     if((rdM == rs1D)) begin

    //     end

    //     ;






end






endmodule
