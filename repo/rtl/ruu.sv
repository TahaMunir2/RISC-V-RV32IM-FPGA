module ruu #(
  parameter DEPTH          = 64,
  parameter TAG_BITS       = $clog2(DEPTH),
  parameter CONTROL_WIDTH  = 4
)(
  input  logic                 clk,
  input  logic                 rst,

  //Dispatch interface: 2 new instructions into the RUU

  // Instruction 1 (older)
  input  logic                 dispatch1_en,
  input  logic [TAG_BITS-1:0]  dispatch1_dest_tag,

  input  logic                 dispatch1_src1_valid,
  input  logic [TAG_BITS-1:0]  dispatch1_src1_tag,
  input  logic [31:0]          dispatch1_src1_value,

  input  logic                 dispatch1_src2_valid,
  input  logic [TAG_BITS-1:0]  dispatch1_src2_tag,
  input  logic [31:0]          dispatch1_src2_value,

  input  logic [CONTROL_WIDTH-1:0] dispatch1_ctrl,

  //output logic                 dispatch1_ok,
  //output logic [TAG_BITS-1:0]  dispatch1_idx, //which RUU slot we used

  // Instruction 2 (younger)
  input  logic                 dispatch2_en,
  input  logic [TAG_BITS-1:0]  dispatch2_dest_tag,

  input  logic                 dispatch2_src1_valid,
  input  logic [TAG_BITS-1:0]  dispatch2_src1_tag,
  input  logic [31:0]          dispatch2_src1_value,

  input  logic                 dispatch2_src2_valid,
  input  logic [TAG_BITS-1:0]  dispatch2_src2_tag,
  input  logic [31:0]          dispatch2_src2_value,

  input  logic [CONTROL_WIDTH-1:0] dispatch2_ctrl,

  //output logic                 dispatch2_ok,
  //output logic [TAG_BITS-1:0]  dispatch2_idx, // which RUU slot we used

  //Broadcast interface (writeback: we wake waiting operands)
  //execute stage
  input  logic                 wb1_en,
  input  logic [TAG_BITS-1:0]  wb1_tag,
  input  logic [31:0]          wb1_value,

  input  logic                 wb2_en,
  input  logic [TAG_BITS-1:0]  wb2_tag,
  input  logic [31:0]          wb2_value,

  //memory stage
  input  logic                 wb3_en,
  input  logic [TAG_BITS-1:0]  wb3_tag,
  input  logic [31:0]          wb3_value,

  input  logic                 wb4_en,
  input  logic [TAG_BITS-1:0]  wb4_tag,
  input  logic [31:0]          wb4_value,


  // Free interface: release up to 2 entries per cycle (e.g. after commit)
  input  logic                 free1_en,
  input  logic [TAG_BITS-1:0]  free1_tag,
  input  logic                 free2_en,
  input  logic [TAG_BITS-1:0]  free2_tag,


  //Execute interface: 2 issued instructions per cycle
  output logic [TAG_BITS-1:0]  exec0_dest_tag,
  output logic [31:0]          exec0_src1_value,
  output logic [31:0]          exec0_src2_value,
  output logic [CONTROL_WIDTH-1:0] exec0_ctrl,
  output logic [1:0] exec0_ResultSrc,
  output  logic [1:0] exec0_LoadSize,
  output  logic exec0_LoadUnsigned,


  output logic [TAG_BITS-1:0]  exec1_dest_tag,
  output logic [31:0]          exec1_src1_value,
  output logic [31:0]          exec1_src2_value,
  output logic [CONTROL_WIDTH-1:0] exec1_ctrl,
  output  logic [1:0] exec1_ResultSrc,
  output  logic [1:0] exec1_LoadSize,
  output  logic exec1_LoadUnsigned,


  input logic [1:0] dispatch1_ResultSrc,
  input  logic [1:0] dispatch1_LoadSize,
  input  logic dispatch1_LoadUnsigned,
  input  logic [1:0] dispatch2_ResultSrc,
  input  logic [1:0] dispatch2_LoadSize,
  input  logic dispatch2_LoadUnsigned
  

);

  //RUU entry type
  typedef struct packed {
    logic                     valid; // slot in use
    logic                     issued; //already sent to ALU?

    logic [TAG_BITS-1:0]      dest_tag;

    logic                     src1_valid;
    logic [TAG_BITS-1:0]      src1_tag;
    logic [31:0]              src1_value;

    logic                     src2_valid;
    logic [TAG_BITS-1:0]      src2_tag;
    logic [31:0]              src2_value;

    logic [CONTROL_WIDTH-1:0] ctrl;

    logic [1:0] ResultSrc;
    logic [1:0] LoadSize;
    logic LoadUnsigned;

  } ruu_entry_t;

  ruu_entry_t entries [DEPTH];


  //We find the two oldest RUU entries
  logic                 found1, found2;
  logic [TAG_BITS-1:0]  slot1_idx, slot2_idx;

  always_comb begin
    found1    = 1'b0;
    found2    = 1'b0;
    slot1_idx = '0;
    slot2_idx = '0;

    for (int i = 0; i < DEPTH; i++) begin
      if (!entries[i].valid) begin
        if (!found1) begin
          found1    = 1'b1;
          slot1_idx = i[TAG_BITS-1:0];
        end else if (!found2) begin
          found2    = 1'b1;
          slot2_idx = i[TAG_BITS-1:0];
        end
      end
    end
  end

  logic dispatch1_ok;
  logic dispatch2_ok;

  logic [TAG_BITS-1:0] dispatch1_idx;
  logic [TAG_BITS-1:0] dispatch2_idx;

  //Instr1 can dispatch if enabled
  assign dispatch1_ok  = dispatch1_en && found1;
  assign dispatch1_idx = slot1_idx;

  //Instr2 can dispatch if enabled and there is a second free slot
  assign dispatch2_ok  = dispatch2_en && found2;
  assign dispatch2_idx = slot2_idx;

  //Issuer: pick 2 oldest READY, non-issued entries
  logic                 issue0_valid, issue1_valid;
  logic [TAG_BITS-1:0]  issue0_idx,   issue1_idx;

  always_comb begin
    issue0_valid = 1'b0;
    issue0_idx   = '0;
    issue1_valid = 1'b0;
    issue1_idx   = '0;

//very important logic implemented with load instructions:
//if the instruction is a load (ResultSrc=01) then we don't need the second operand to be valid because we only need one
    // First ALU: oldest ready, not issued
    for (int i = 2; i < DEPTH; i++) begin
      if (!issue0_valid &&
          entries[i].valid &&
         !entries[i].issued &&
          entries[i].src1_valid &&
          (entries[i].src2_valid || (entries[i].ResultSrc == 2'b01) ) ) begin
        issue0_valid = 1'b1;
        issue0_idx   = i[TAG_BITS-1:0];
      end
    end

    //Second ALU:next oldest ready, different index
    for (int i = 2; i < DEPTH; i++) begin
      if (!issue1_valid &&
          entries[i].valid &&
         !entries[i].issued &&
          entries[i].src1_valid &&
          (entries[i].src2_valid || (entries[i].ResultSrc == 2'b01) ) &&
          (!issue0_valid || (issue0_idx != i[TAG_BITS-1:0]))) begin
        issue1_valid = 1'b1;
        issue1_idx   = i[TAG_BITS-1:0];
      end
    end
  end

  // Pack outputs for execute stage
  always_comb begin
    // exec0
    exec0_dest_tag   = issue0_valid ? entries[issue0_idx].dest_tag    : '0;
    exec0_src1_value = issue0_valid ? entries[issue0_idx].src1_value  : '0;
    exec0_src2_value = issue0_valid ? entries[issue0_idx].src2_value  : '0;
    exec0_ctrl       = issue0_valid ? entries[issue0_idx].ctrl        : '0;
    exec0_ResultSrc   = issue0_valid ? entries[issue0_idx].ResultSrc       : '0;
    exec0_LoadSize    = issue0_valid ? entries[issue0_idx].LoadSize       : '0;
    exec0_LoadUnsigned = issue0_valid ? entries[issue0_idx].LoadUnsigned  : '0;

    // exec1
    exec1_dest_tag   = issue1_valid ? entries[issue1_idx].dest_tag    : '0;
    exec1_src1_value = issue1_valid ? entries[issue1_idx].src1_value  : '0;
    exec1_src2_value = issue1_valid ? entries[issue1_idx].src2_value  : '0;
    exec1_ctrl       = issue1_valid ? entries[issue1_idx].ctrl        : '0;
    exec1_ResultSrc   = issue1_valid ? entries[issue1_idx].ResultSrc       : '0;
    exec1_LoadSize    = issue1_valid ? entries[issue1_idx].LoadSize      : '0;
    exec1_LoadUnsigned = issue1_valid ? entries[issue1_idx].LoadUnsigned   : '0;

  end

  //Sequential updates
  always_ff @(posedge clk) begin
    if (rst) begin
      for (int i = 0; i < DEPTH; i++) begin
        entries[i].valid      <= 1'b0;
        entries[i].issued     <= 1'b0;

        entries[i].dest_tag   <= '0;

        entries[i].src1_valid <= 1'b0;
        entries[i].src1_tag   <= '0;
        entries[i].src1_value <= 32'd0;

        entries[i].src2_valid <= 1'b0;
        entries[i].src2_tag   <= '0;
        entries[i].src2_value <= 32'd0;

        entries[i].ctrl       <= '0;

        entries[i].ResultSrc     <= '0;
        entries[i].LoadSize <= '0;
        entries[i].LoadUnsigned  <= '0;

      end

    end 

    else begin
      //Dispatch: insert up to 2 new instructions 

      // Instruction 1 (older)
      if (dispatch1_ok) begin
        ruu_entry_t e1; //we create a new entry in the Register Update Unit

        e1.valid       = 1'b1;
        e1.issued      = 1'b0;

        e1.dest_tag    = dispatch1_dest_tag;

        e1.src1_valid  = dispatch1_src1_valid;
        e1.src1_tag    = dispatch1_src1_tag;
        e1.src1_value  = dispatch1_src1_value;

        e1.src2_valid  = dispatch1_src2_valid;
        e1.src2_tag    = dispatch1_src2_tag;
        e1.src2_value  = dispatch1_src2_value;

        e1.ctrl        = dispatch1_ctrl;

        e1.ResultSrc = dispatch1_ResultSrc;
        e1.LoadSize = dispatch1_LoadSize;
        e1.LoadUnsigned = dispatch1_LoadUnsigned;


        entries[slot1_idx] <= e1; //we append it to the array
      end

      // Instruction 2 (younger)
      if (dispatch2_ok) begin
        ruu_entry_t e2; //we create another entry in the Register Update Unit (since 2 instructions are fetched at each cycle this is possible)

        e2.valid       = 1'b1;
        e2.issued      = 1'b0;

        e2.dest_tag    = dispatch2_dest_tag;

        e2.src1_valid  = dispatch2_src1_valid;
        e2.src1_tag    = dispatch2_src1_tag;
        e2.src1_value  = dispatch2_src1_value;

        e2.src2_valid  = dispatch2_src2_valid;
        e2.src2_tag    = dispatch2_src2_tag;
        e2.src2_value  = dispatch2_src2_value;

        e2.ctrl        = dispatch2_ctrl;

        e2.ResultSrc = dispatch2_ResultSrc;
        e2.LoadSize = dispatch2_LoadSize;
        e2.LoadUnsigned = dispatch2_LoadUnsigned;

        entries[slot2_idx] <= e2; //we append it to the array
      end

      //we mark issued entries as issued so they are not re-issued later 

      if (issue0_valid) begin //this means, if we have issued an instruction during this specific clock cycle 
        entries[issue0_idx].issued <= 1'b1;
      end

      if (issue1_valid) begin //we do it twice because we can issue up to 2 instructions per cycle
        entries[issue1_idx].issued <= 1'b1;
      end

      // Freeing after commits, we clear entries by switching the validity bits of an entry to 0
      if (free1_en) begin
        for (int i = 0; i < DEPTH; i++) begin
          if (free1_tag == entries[i].dest_tag) begin
            entries[i].valid      <= 1'b0;
            entries[i].issued     <= 1'b0;
            entries[i].ResultSrc     <= '0;
            entries[i].LoadSize <= '0;
            entries[i].LoadUnsigned  <= '0;
          end
        end
      end

      if (free2_en) begin
        for (int i = 0; i < DEPTH; i++) begin
          if (free2_tag == entries[i].dest_tag) begin
            entries[i].valid      <= 1'b0;
            entries[i].issued     <= 1'b0;
            entries[i].ResultSrc     <= '0;
            entries[i].LoadSize <= '0;
            entries[i].LoadUnsigned  <= '0;
          end
        end
      end
    end
  end
  
    //writing back needs to happen on the negative edge so that we don't incur a delay when we have a data dependency
    always_ff @(negedge clk) begin
      //Broadcast from the Common Broadcast Bus: 
      if (wb1_en) begin
        for (int i = 0; i < DEPTH; i++) begin
          if (entries[i].valid && !entries[i].src1_valid &&
              (entries[i].src1_tag == wb1_tag)) begin
            entries[i].src1_valid <= 1'b1;
            entries[i].src1_value <= wb1_value;
          end
          if (entries[i].valid && !entries[i].src2_valid &&
              (entries[i].src2_tag == wb1_tag)) begin
            entries[i].src2_valid <= 1'b1;
            entries[i].src2_value <= wb1_value;
          end
        end
      end


     //Broadcast from the Common Broadcast Bus: 
      if (wb2_en) begin
        for (int i = 0; i < DEPTH; i++) begin
          if (entries[i].valid && !entries[i].src1_valid &&
              (entries[i].src1_tag == wb2_tag)) begin
            entries[i].src1_valid <= 1'b1;
            entries[i].src1_value <= wb2_value;
          end
          if (entries[i].valid && !entries[i].src2_valid &&
              (entries[i].src2_tag == wb2_tag)) begin
            entries[i].src2_valid <= 1'b1;
            entries[i].src2_value <= wb2_value;
          end
        end
      end

      if (wb3_en) begin
        for (int i = 0; i < DEPTH; i++) begin
          if (entries[i].valid && !entries[i].src1_valid &&
              (entries[i].src1_tag == wb3_tag)) begin
            entries[i].src1_valid <= 1'b1;
            entries[i].src1_value <= wb3_value;
          end
          if (entries[i].valid && !entries[i].src2_valid &&
              (entries[i].src2_tag == wb3_tag)) begin
            entries[i].src2_valid <= 1'b1;
            entries[i].src2_value <= wb3_value;
          end
        end
      end


     //Broadcast from the Common Broadcast Bus: 
      if (wb4_en) begin
        for (int i = 0; i < DEPTH; i++) begin
          if (entries[i].valid && !entries[i].src1_valid &&
              (entries[i].src1_tag == wb4_tag)) begin
            entries[i].src1_valid <= 1'b1;
            entries[i].src1_value <= wb4_value;
          end
          if (entries[i].valid && !entries[i].src2_valid &&
              (entries[i].src2_tag == wb4_tag)) begin
            entries[i].src2_valid <= 1'b1;
            entries[i].src2_value <= wb4_value;
          end
        end
      end

    end

endmodule


