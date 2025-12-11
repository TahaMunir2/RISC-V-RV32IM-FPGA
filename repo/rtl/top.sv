module top #(
    parameter DATA_WIDTH = 32,
    parameter PROD_BITS = 6
) (
    input   logic clk,
    input   logic rst,
    input logic trigger,
    output  logic [DATA_WIDTH-1:0] a0    
);


/*The 5 pipelining states now are :
-Fetching 2 instructions (F)
-Rename/Decode (D)
-Issuing stage (Register Update Unit) (Iss)
-Execute stage (2 ALUs working in parrallel) and writing to the Re-Order Buffer (Ex)
-Memory stage (added for load instructions)
-Commit stage: we write back to the Register file from the Re-Order Buffer (Comm)
*/

//extra logic declaration
logic [PROD_BITS-1:0] q1_tag, q2_tag, q3_tag, q4_tag;
logic [PROD_BITS-1:0] tmp_q3_tag, tmp_q4_tag;
logic q1_ready, q2_ready, q3_ready, q4_ready;
logic [31:0] q1_value, q2_value, q3_value, q4_value;
logic tmp_validity_source3, tmp_validity_source4;
logic [PROD_BITS-1:0] Instr1_tagD, Instr2_tagD,Instr1_tagI, Instr2_tagI;
logic [PROD_BITS-1:0] commit1_tag, commit2_tag;
logic [PROD_BITS-1:0] ALU1_tagE, ALU2_tagE;
logic [PROD_BITS-1:0] ALU1_dest_tagIss, ALU2_dest_tagIss;
logic [3:0] ALU1CtrlIss, ALU2CtrlIss, ALU1CtrlE, ALU2CtrlE;
logic [3:0] ALUCtrl1I, ALUCtrl2I;
logic [31:0] ALU1_op1Iss, ALU1_op2Iss, ALU2_op1Iss, ALU2_op2Iss;
logic [31:0] ALU1_op1E, ALU1_op2E, ALU2_op1E, ALU2_op2E;
logic RegWrite1W, RegWrite2W;
logic [4:0] Rd1W, Rd2W;
logic [31:0] Result1W, Result2W;
logic [31:0] RS1_val, RS2_val, RS3_val, RS4_val;
logic [31:0] PCF, PCD;
logic PCWrite;
logic Instr1_enableRUU, Instr2_enableRUU;
logic validity_source1I, validity_source2I, validity_source3I, validity_source4I;
logic [PROD_BITS-1:0] tag_source1I, tag_source2I, tag_source3I, tag_source4I;
logic ALU1Src1, ALU1Src2, ALU2Src1, ALU2Src2;

    logic [DATA_WIDTH-1 : 0] ExtImm1D;
    logic [DATA_WIDTH-1 : 0] Instr1F;
    logic [DATA_WIDTH-1:0] Instr1D;

    logic [DATA_WIDTH-1 : 0] ExtImm2D;
    logic [DATA_WIDTH-1 : 0] Instr2F;
    logic [DATA_WIDTH-1:0] Instr2D;

    logic [DATA_WIDTH-1 : 0] PCPlus8F;
    logic [DATA_WIDTH-1 : 0] PCPlus8D;

    logic [2:0] ImmSrc1D;
    logic [2:0] ImmSrc2D;

    logic [DATA_WIDTH-1: 0] ALU1ResultE;
    logic [DATA_WIDTH-1: 0] ALU2ResultE;
    

     logic [3:0] ALUCtrl1D;
     logic [3:0] ALUCtrl2D;

     logic [1:0] PCSrcE;
    assign PCSrcE = 2'b00;

    logic [4:0] RS1, RS2, RS3, RS4;
    assign RS1 = Instr1D[19:15];
    assign RS2 = Instr1D[24:20];
    assign RS3 = Instr2D[19:15];
    assign RS4 = Instr2D[24:20];

    
    //pipeline enable signals at constant 1 now since there are no hazard units and stalls in this implementation (all the data hazards are correctly handled without having to disable a register)
    logic cons_en_pip;
    assign cons_en_pip = 1'b1;



    logic [PROD_BITS-1 :0] mem1_tag, mem2_tag;

    logic LoadUnsigned1I, LoadUnsigned2I;
    logic [1:0] LoadSize1I, LoadSize2I, ResultSrc1I,ResultSrc2I ;
//we define 3 very important parameters assigned for each register source operand at the rename/decode stage:

logic [DATA_WIDTH-1: 0] value_source1;
logic validity_source1;
logic [PROD_BITS-1 : 0] tag_source1;

logic [DATA_WIDTH-1: 0] value_source2;
logic validity_source2;
logic [PROD_BITS-1 : 0] tag_source2;

logic [DATA_WIDTH-1: 0] value_source3;
logic validity_source3;
logic [PROD_BITS-1 : 0] tag_source3;

logic [DATA_WIDTH-1: 0] value_source4;
logic validity_source4;
logic [PROD_BITS-1 : 0] tag_source4;



//extra intermediate logic for wiring up the register source operands validity logic with the rest of the circuit:
logic source1_selectline;
logic source2_selectline;
logic source3_selectline;
logic source4_selectline;

logic rat_has_producer_src1;
logic rat_has_producer_src2;
logic rat_has_producer_src3;
logic rat_has_producer_src4;

assign rat_has_producer_src1 = (q1_tag != 6'b0 );
assign rat_has_producer_src2 = (q2_tag != 6'b0 );
assign rat_has_producer_src3 = (tmp_q3_tag != 6'b0 );
assign rat_has_producer_src4 = (tmp_q4_tag != 6'b0 );


//for the first instruction it is simple because all the logic is already updated by the time we are accessing the RAT and the ROB buffers
src_operand_validity_logic src1_availabality_logic (
    .rat_has_producer(rat_has_producer_src1),  
    .rat_tag(q1_tag), 
    .rob_entry_ready(q1_ready),
    .operand_valid(validity_source1),
    .fetch_from_regfile(source1_selectline)
);

src_operand_validity_logic src2_availabality_logic (
    .rat_has_producer(rat_has_producer_src2),  
    .rat_tag(q2_tag), 
    .rob_entry_ready(q2_ready),
    .operand_valid(validity_source2),
    .fetch_from_regfile(source2_selectline)
);

src_operand_validity_logic src3_availabality_logic (
    .rat_has_producer(rat_has_producer_src3),  
    .rat_tag(q3_tag), 
    .rob_entry_ready(q3_ready),
    .operand_valid(tmp_validity_source3),
    .fetch_from_regfile(source3_selectline)
);

src_operand_validity_logic src4_availabality_logic (
    .rat_has_producer(rat_has_producer_src4),  
    .rat_tag(q4_tag), 
    .rob_entry_ready(q4_ready),
    .operand_valid(tmp_validity_source4),
    .fetch_from_regfile(source4_selectline)
);


//we assign the value of each register source depending on their availability logic (see diagram inserted on github concerning operand validity logic)
//for the first 2 register source it is simple because the state of the buffers is fully complete and there is no need to check for anything else in order to detect dependency
assign value_source1 = source1_selectline ? q1_value : RS1_val;
assign value_source2 = source2_selectline ? q2_value : RS2_val;


//for the second instruction it gets a bit tricky because the buffers did not get updated by the its paired (first) instruction 
//we add an extra validty check before going in that logic (if the operands of the second instruction depends on the first instruction then we don't care about the content of the other buffers)

logic is_rs3_dependent_onRD1;
logic is_rs4_dependent_onRD1;

logic [4:0] RD1;
assign RD1 =Instr1D[11:7];


assign is_rs3_dependent_onRD1 = (RD1 == RS3);
assign is_rs4_dependent_onRD1 = (RD1 == RS4);

assign value_source3 = is_rs3_dependent_onRD1 ?  32'b0 : (source3_selectline ? q3_value : RS3_val); //If it is dependent we don't care about the value but we care about the tag of instr1
assign validity_source3 = is_rs3_dependent_onRD1 ? 1'b0 : tmp_validity_source3 ;
assign tag_source3 = is_rs3_dependent_onRD1 ? (latest_tag - 1) : tmp_q3_tag; //In the case it is dependent I assign the latest tag which is the tag that is going to be assigned to instr1

assign value_source4 = is_rs4_dependent_onRD1 ?  32'b0 : (source4_selectline ? q4_value : RS4_val); //If it is dependent we don't care about the value but we care about the tag of instr1
assign validity_source4 = is_rs4_dependent_onRD1 ?  1'b0 : tmp_validity_source4;
assign tag_source4 = is_rs4_dependent_onRD1 ? (latest_tag - 1) : tmp_q4_tag ; //In the case it is dependent I assign the latest tag which is the tag that is going to be assigned to instr1


assign q3_tag = tag_source3;
assign q4_tag = tag_source4;

    //Re-Order Buffer logic: Fundemental part of the Hardware Out Of Order Structure:
    //(Accessed in most of the pipeline stages)

//I want to allocate an instruction to the Re-Order Buffer if and only if a correct instruction is fetched from the fetched stage and is brought to the rename/decode stage:
logic instr1_alloc_rob, instr2_alloc_rob;
 //and we also use the same logic for inserting an instruction in the Register Update Unit (we don't want to insert no ops in the issuer)
assign instr1_alloc_rob = (Instr1D != 0); //high if and only if the instruction fetched is not a no-op
assign instr2_alloc_rob = (Instr2D != 0); //high if and only if the instruction fetched is not a no-op

logic commit_en ;
assign commit_en = 1'b1;

assign tag_source1 = q1_tag;
assign tag_source2 = q2_tag;


    robdual robdual(
        .clk(clk),
        .rst(rst),

        //source registers : rename/decode stage
        .q1_tag(q1_tag),
        .q1_ready(q1_ready),
        .q1_value(q1_value),
        .q2_tag(q2_tag),
        .q2_ready(q2_ready),
        .q2_value(q2_value),
        .q3_tag(q3_tag),
        .q3_ready(q3_ready),
        .q3_value(q3_value),
        .q4_tag(q4_tag),
        .q4_ready(q4_ready),
        .q4_value(q4_value),

        //destination registers and allocation of their specific order in the re-order buffer
        .alloc1_en(instr1_alloc_rob),
        .alloc1_rd(Instr1D[11:7]),
        .alloc1_tag(Instr1_tagD),
        .alloc2_en(instr2_alloc_rob),
        .alloc2_rd(Instr2D[11:7]),
        .alloc2_tag(Instr2_tagD), 

        //write back from the common data bus at the execute stage:
        
        .wb1_en( (ResultSrc1E == 2'b00) ),
        .wb1_tag(ALU1_tagE),
        .wb1_value(ALU1ResultE),       
        .wb2_en((ResultSrc2E == 2'b00)),
        .wb2_tag(ALU2_tagE),
        .wb2_value(ALU2ResultE),  

        //write back from the common data bus at the memory stage:
        .wb3_en((ResultSrc1M == 2'b01)),
        .wb3_tag(mem1_tag),
        .wb3_value(MemoryOut1),       
        .wb4_en((ResultSrc2M == 2'b01)),
        .wb4_tag(mem2_tag),
        .wb4_value(MemoryOut2),  

        //commit stage: commiting to the register file :
         //at this stage we keep the enable signal constantly 1: 
         .commit1_valid(RegWrite1W),
         .commit1_rd(Rd1W),
         .commit1_value(Result1W),
         .commit1_tag(commit1_tag), //in order to free up the entry from the Register Update Unit
         .commit1_en(commit_en),   

         .commit2_valid(RegWrite2W),
         .commit2_rd(Rd2W),
         .commit2_value(Result2W),
         .commit2_tag(commit2_tag), //in order to free up the entry from the Register Update Unit
         .commit2_en(commit_en)

    );

logic [PROD_BITS-1 : 0] latest_tag;

    rat Register_Aliasing_Table(
        .clk(clk),
        .rst(rst),
        .inst1_rd(Instr1D[11:7]),
        .inst1_prod_id(Instr1_tagD),
        .inst2_rd(Instr2D[11:7]),
        .inst2_prod_id(Instr2_tagD),
        .rs1(Instr1D[19:15]),
        .rs1_prod_id(q1_tag),
        .rs2(Instr1D[24:20]),
        .rs2_prod_id(q2_tag),
        .rs3(Instr2D[19:15]),
        .rs3_prod_id(tmp_q3_tag),
        .rs4(Instr2D[24:20]),
        .rs4_prod_id(tmp_q4_tag),
        .latest_tag(latest_tag)        
    );



//Register Update Unit which serves as a queue for the instructions to be issued in the execute stage where they are executed in parrallel with the 2 ALUs
    ruu Register_Update_Unit(

        .clk(clk),
        .rst(rst),

        .dispatch1_en(Instr1_enableRUU),
        .dispatch1_dest_tag(Instr1_tagI),

        .dispatch1_src1_valid(validity_source1I),
        .dispatch1_src1_tag(tag_source1I),
        .dispatch1_src1_value(ALU1_op1I),

        .dispatch1_src2_valid(validity_source2I),
        .dispatch1_src2_tag(tag_source2I),
        .dispatch1_src2_value(ALU1_op2I),

        .dispatch1_ctrl(ALUCtrl1I),
        .dispatch1_ResultSrc(ResultSrc1I),
        .dispatch1_LoadSize(LoadSize1I),
        .dispatch1_LoadUnsigned(LoadUnsigned1I),


        //.dispatch1_ok,
        //.dispatch1_idx,

//similarly for instruction 2, we have:
        .dispatch2_en(Instr2_enableRUU),
        .dispatch2_dest_tag(Instr2_tagI),

        .dispatch2_src1_valid(validity_source3I),
        .dispatch2_src1_tag(tag_source3I),
        .dispatch2_src1_value(ALU2_op1I),

        .dispatch2_src2_valid(validity_source4I),
        .dispatch2_src2_tag(tag_source4I),
        .dispatch2_src2_value(ALU2_op2I),

        .dispatch2_ctrl(ALUCtrl2I),
        .dispatch2_ResultSrc(ResultSrc2I),
        .dispatch2_LoadSize(LoadSize2I),
        .dispatch2_LoadUnsigned(LoadUnsigned2I),


        //.dispatch1_ok,
        //.dispatch1_idx,

    //common data bus:
        .wb1_en( (ResultSrc1E == 2'b00) ), //if the instruction is a load instruction we don't want to write back
        .wb1_tag(ALU1_tagE),
        .wb1_value(ALU1ResultE),
        .wb2_en( (ResultSrc2E == 2'b00) ),
        .wb2_tag(ALU2_tagE),
        .wb2_value(ALU2ResultE),
    
    //we double the number of write back ports because we can also write from memory now:
        .wb3_en( (ResultSrc1M == 2'b01) ), //if the instruction is an arithmetic instruction we don't want to write back
        .wb3_tag(mem1_tag),
        .wb3_value(MemoryOut1),
        .wb4_en( (ResultSrc2M == 2'b01) ),
        .wb4_tag(mem2_tag),
        .wb4_value(MemoryOut2),

    //freeing enries when we commit to the register file:
        .free1_en(RegWrite1W),
        .free1_tag(commit1_tag),
        .free2_en(RegWrite2W),
        .free2_tag(commit2_tag),

    //issuing an instruction:
        .exec0_dest_tag(ALU1_dest_tagIss),
        .exec0_ctrl(ALU1CtrlIss),
        .exec0_src1_value(ALU1_op1Iss),
        .exec0_src2_value(ALU1_op2Iss),
        .exec0_LoadSize(LoadSize1Iss),
        .exec0_LoadUnsigned(LoadUnsigned1Iss),
        .exec0_ResultSrc(ResultSrc1Iss),

        .exec1_dest_tag(ALU2_dest_tagIss),
        .exec1_ctrl(ALU2CtrlIss),
        .exec1_src1_value(ALU2_op1Iss),
        .exec1_src2_value(ALU2_op2Iss),
        .exec1_LoadSize(LoadSize2Iss),
        .exec1_LoadUnsigned(LoadUnsigned2Iss),
        .exec1_ResultSrc(ResultSrc2Iss)
    );


    fd_pipeline fd_pip(
        .clk(clk),
        .rst(rst),
        .enable(cons_en_pip),
        .instr1_f(Instr1F),
        .instr2_f(Instr2F),
        .pc_f(PCF),
        .pc_save_f(PCPlus8F),
        .instr1_d(Instr1D),
        .instr2_d(Instr2D),
        .pc_d(PCD),
        .pc_save_d(PCPlus8D)
    );


//we duplicate the logic for sign extension
    signext sign_extension1 (
        .instr(Instr1D),
        .ImmSrc(ImmSrc1D),
        .immext(ExtImm1D)
    );

    signext sign_extension2 (
        .instr(Instr2D),
        .ImmSrc(ImmSrc2D),
        .immext(ExtImm2D)
    );


    logic [DATA_WIDTH-1:0] ALU1_op1D;
    logic [DATA_WIDTH-1:0] ALU1_op2D;
    logic [DATA_WIDTH-1:0] ALU2_op1D;
    logic [DATA_WIDTH-1:0] ALU2_op2D;
    logic [DATA_WIDTH-1:0] ALU1_op1I;
    logic [DATA_WIDTH-1:0] ALU1_op2I;
    logic [DATA_WIDTH-1:0] ALU2_op1I;
    logic [DATA_WIDTH-1:0] ALU2_op2I;


    di_pipeline di_pip(
    .clk(clk),
    .rst(rst),
     .enable(cons_en_pip),


    // data logic
    .ALU1_op1D(ALU1_op1D),
    .ALU1_op2D(ALU1_op2D),
    .ALU2_op1D(ALU2_op1D),
    .ALU2_op2D(ALU2_op2D),
    .ALU1_op1I(ALU1_op1I),
    .ALU1_op2I(ALU1_op2I),
    .ALU2_op1I(ALU2_op1I),
    .ALU2_op2I(ALU2_op2I),

    // control logic
     .ALUCtrl1_d(ALUCtrl1D),
     .ALUCtrl1_i(ALUCtrl1I),
     .ALUCtrl2_d(ALUCtrl2D),
     .ALUCtrl2_i(ALUCtrl2I),

    //propagating enable signals to avoid stalls when we have no-ops
    .instr1_alloc_rob(instr1_alloc_rob),
    .instr2_alloc_rob(instr2_alloc_rob),
    .Instr1_enableRUU(Instr1_enableRUU),
    .Instr2_enableRUU(Instr2_enableRUU),

    //propagating the specific instructions tag:
    .instr1_tag_d(Instr1_tagD),
    .instr2_tag_d(Instr2_tagD),
    .instr1_tag_i(Instr1_tagI),
    .instr2_tag_i(Instr2_tagI),

    //propagating the validity of the sources:
    .validity_source1(final_validity_source1),
    .validity_source2(final_validity_source2),
    .validity_source3(final_validity_source3),
    .validity_source4(final_validity_source4),

    .validity_source1I(validity_source1I),
    .validity_source2I(validity_source2I),
    .validity_source3I(validity_source3I),
    .validity_source4I(validity_source4I),

    //propagating the source tags: 
    .tag_source1(tag_source1),
    .tag_source2(tag_source2),
    .tag_source3(tag_source3),
    .tag_source4(tag_source4),

    .tag_source1I(tag_source1I),
    .tag_source2I(tag_source2I),
    .tag_source3I(tag_source3I),
    .tag_source4I(tag_source4I),

    .ResultSrc1D(ResultSrc1D),
    .LoadSize1D(LoadSize1D),
    .LoadUnsigned1D(LoadUnsigned1D),
    .ResultSrc2D(ResultSrc2D),
    .LoadSize2D(LoadSize2D),
    .LoadUnsigned2D(LoadUnsigned2D),

    .ResultSrc1I(ResultSrc1I),
    .LoadSize1I(LoadSize1I),
    .LoadUnsigned1I(LoadUnsigned1I),
    .ResultSrc2I(ResultSrc2I),
    .LoadSize2I(LoadSize2I),
    .LoadUnsigned2I(LoadUnsigned2I)

    );


    logic [1:0] ResultSrc1D;
    logic [1:0] LoadSize1D;
    logic LoadUnsigned1D;
    logic [1:0] ResultSrc2D;
    logic [1:0] LoadSize2D;
    logic LoadUnsigned2D;

    logic [1:0] ResultSrc1Iss;
    logic [1:0] LoadSize1Iss;
    logic LoadUnsigned1Iss;
    logic [1:0] ResultSrc2Iss;
    logic [1:0] LoadSize2Iss;
    logic LoadUnsigned2Iss;

//2 control blocks:
    sup_control control1 (
        .instr(Instr1D),
        .ALUCtrl(ALUCtrl1D), 
        .ALUSrc(ALU1Src1),
        .ImmSrc(ImmSrc1D),
        .ALUsrc2(ALU1Src2),
        .ResultSrc(ResultSrc1D),
        .LoadSize(LoadSize1D),
        .LoadUnsigned(LoadUnsigned1D)
    );

    sup_control control2 (
        .instr(Instr2D),
        .ALUCtrl(ALUCtrl2D), 
        .ALUSrc(ALU2Src1),
        .ImmSrc(ImmSrc2D),
        .ALUsrc2(ALU2Src2),
        .ResultSrc(ResultSrc2D),
        .LoadSize(LoadSize2D),
        .LoadUnsigned(LoadUnsigned2D)
    );


    supinsmem Instr_Mem (
        .instr1(Instr1F),
        .instr2(Instr2F),
        .addr(PCF)
    );

    logic [1:0] PCSrcF; //for the moment we don't have the branch predictor logic so PCSrcF is equal to PCSrcE
    assign PCSrcF = PCSrcE;


logic [31:0] target;
assign target = 32'b0; //we don't care about this signal here
assign PCWrite =1'b1;

//we don't care about this signal for now:
    logic [DATA_WIDTH-1:0] cons_result;
    assign cons_result = 0;
    sup_pc_block pc_block (
        .clk(clk),
        .rst(rst),
        .enable(PCWrite),
        .Imm_op(target), //very important line 
        .pc_src(PCSrcF),
        .pc(PCF),
        //OMITTED LOGIC FOR NOW: .pc_saved(PCPlus8E), //in the case the predictor forecasted a jump and made a false guess
        .pc_save(PCPlus8F),
        .ALU(cons_result)
    );


sup_regfile regfile(
        .clk(clk),
        .trigger(trigger),
        
        // WRITE PORT 1
        .WD1(Result1W),
        .WE1(RegWrite1W),
        .AD1W(Rd1W),
        
        // WRITE PORT 2
        .WD2(Result2W),
        .WE2(RegWrite2W),
        .AD2W(Rd2W),
        
        // READ PORT 1
        .AD1R(RS1),
        .RD1(RS1_val),
        
        // READ PORT 2
        .AD2R(RS2),
        .RD2(RS2_val),
        
        // READ PORT 3
        .AD3R(RS3),
        .RD3(RS3_val),
        
        // READ PORT 4
        .AD4R(RS4),
        .RD4(RS4_val),
        
        // Always expose x10
        .A0(a0)
    );

logic final_validity_source1, final_validity_source2, final_validity_source3, final_validity_source4;

assign final_validity_source1 = ALU1Src2 ? 1'b1: validity_source1;
assign final_validity_source2 = ALU1Src1 ? 1'b1: validity_source2;
assign final_validity_source3 = ALU2Src2 ? 1'b1 : validity_source3;
assign final_validity_source4 = ALU2Src1 ? 1'b1 : validity_source4;

logic [DATA_WIDTH-1 :0] tmp_ALU1_op1D;
logic [DATA_WIDTH-1 :0] tmp_ALU2_op1D;

//Source 1 drives the second operand of the alu and source 2 drives the first operand of the ALU

    mux mux_ALU1_pcVSreg( //additional mux, because we never use data from a register and from pc_save in any instructiom
        .in0(value_source1),
        .in1(PCPlus8D -8 ), //we substract by 8 to get the exact value of pc
        .sel(ALU1Src2),
        .out(tmp_ALU1_op1D)
    );

//if the instruction is a load instruction we want the offset to be added to rs1 before it is stored:
assign ALU1_op1D = (ResultSrc1D == 2'b00) ? tmp_ALU1_op1D : tmp_ALU1_op1D + ExtImm1D;

    mux mux_ALU1_immVSreg( 
        .in0(value_source2),
        .in1(ExtImm1D),
        .sel(ALU1Src1),
        .out(ALU1_op2D) 
    );

    //for the second instruction we substract by 4 to get the exact value of pc
    mux mux_ALU2_pcVSreg( //additional mux, because we never use data from a register and from pc_save in any instructiom
        .in0(value_source3),
        .in1(PCPlus8D -4),
        .sel(ALU2Src2),
        .out(tmp_ALU2_op1D)
    );

assign ALU2_op1D = (ResultSrc2D == 2'b00) ? tmp_ALU2_op1D : tmp_ALU2_op1D + ExtImm2D;

    mux mux_ALU2_immVSreg( 
        .in0(value_source4),
        .in1(ExtImm2D),
        .sel(ALU2Src1),
        .out(ALU2_op2D)
    );



ie_pipeline ie_pipeline(
    .clk(clk),
    .enable(cons_en_pip),
    .rst(rst),

    //ALU operands
    .ALU1_op1Iss(ALU1_op1Iss),
    .ALU1_op2Iss(ALU1_op2Iss),
    .ALU2_op1Iss(ALU2_op1Iss),
    .ALU2_op2Iss(ALU2_op2Iss),
    .ALU1_op1E(ALU1_op1E),
    .ALU1_op2E(ALU1_op2E),
    .ALU2_op1E(ALU2_op1E),
    .ALU2_op2E(ALU2_op2E),

    //ALU control signals
    .ALU1CtrlIss(ALU1CtrlIss),
    .ALU2CtrlIss(ALU2CtrlIss),
    .ALU1CtrlE(ALU1CtrlE),
    .ALU2CtrlE(ALU2CtrlE),

    .ALU1_dest_tagIss(ALU1_dest_tagIss),
    .ALU2_dest_tagIss(ALU2_dest_tagIss),
    .ALU1_dest_tagE(ALU1_tagE),
    .ALU2_dest_tagE(ALU2_tagE),

    .ResultSrc1I(ResultSrc1Iss),
    .LoadSize1I(LoadSize1Iss),
    .LoadUnsigned1I(LoadUnsigned1Iss),    
    .ResultSrc2I(ResultSrc2Iss),
    .LoadSize2I(LoadSize2Iss),
    .LoadUnsigned2I(LoadUnsigned2Iss), 

    .ResultSrc1E(ResultSrc1E),
    .LoadSize1E(LoadSize1E),
    .LoadUnsigned1E(LoadUnsigned1E),    
    .ResultSrc2E(ResultSrc2E),
    .LoadSize2E(LoadSize2E),
    .LoadUnsigned2E(LoadUnsigned2E)      
);

    sup_alu alu1(
        .ALUop1(ALU1_op1E),
        .ALUop2(ALU1_op2E),
        .ALUout(ALU1ResultE),
        .ALUCtrl(ALU1CtrlE)
    );
    sup_alu alu2(
        .ALUop1(ALU2_op1E),
        .ALUop2(ALU2_op2E),
        .ALUout(ALU2ResultE),
        .ALUCtrl(ALU2CtrlE)
    );

logic [DATA_WIDTH-1 :0 ] A1, A2;
logic [1:0] ResultSrc1E;
logic [1:0] LoadSize1E;
logic       LoadUnsigned1E;

logic [1:0] ResultSrc2E;
logic [1:0] LoadSize2E;
logic       LoadUnsigned2E;

logic [1:0] ResultSrc1M;
logic [1:0] LoadSize1M;
logic       LoadUnsigned1M;

logic [1:0] ResultSrc2M;
logic [1:0] LoadSize2M;
logic       LoadUnsigned2M;

logic [DATA_WIDTH-1:0] MemoryOut1, MemoryOut2;


//we add the pipeline register seperating the execute and memory stage:
em_sup_pipeline em_pipeline(
    //control inputs coming from the previous pipeline register
    .rst(rst),
    .clk(clk),

    .ResultSrc1_e(ResultSrc1E),
    .LoadSize1_e(LoadSize1E), 
    .LoadUnsigned1_e(LoadUnsigned1E),
    
    //control outputs:
    .ResultSrc1_m(ResultSrc1M),
    .LoadSize1_m(LoadSize1M), 
    .LoadUnsigned1_m(LoadUnsigned1M),

    .ResultSrc2_e(ResultSrc2E),
    .LoadSize2_e(LoadSize2E), 
    .LoadUnsigned2_e(LoadUnsigned2E),
    
    //control outputs:
    .ResultSrc2_m(ResultSrc2M),
    .LoadSize2_m(LoadSize2M), 
    .LoadUnsigned2_m(LoadUnsigned2M),

    .address1_e(ALU1_op1E), //value of RS1
    .address1_m(A1),
    .address2_e(ALU2_op1E),
    .address2_m(A2),

    .ALU1_tagE(ALU1_tagE),
    .ALU2_tagE(ALU2_tagE),
    .ALU1_tagM(mem1_tag),
    .ALU2_tagM(mem2_tag)
);

sup_datamem datamem(
    .A1(A1), 
    .LoadSize1(LoadSize1M), //additional output signal
    .LoadUnsigned1(LoadUnsigned1M), //additional output signal
    .dout1(MemoryOut1),

    .A2(A2),
    .LoadSize2(LoadSize2M), //additional output signal
    .LoadUnsigned2(LoadUnsigned2M), //additional output signal
    .dout2(MemoryOut2)
);

endmodule



