module robdual #(
  parameter DEPTH    = 64,
  parameter TAG_BITS = $clog2(DEPTH)
)(
  input  logic                  clk,
  input  logic                  rst,

    //query interface: (in the case where we find that there is already a producer for the specific destination register in the register aliasing table)
    input  logic [TAG_BITS-1:0]   q1_tag,
    output logic                  q1_ready,
    output logic [31:0]           q1_value,

    input  logic [TAG_BITS-1:0]   q2_tag,
    output logic                  q2_ready,
    output logic [31:0]           q2_value,

    input  logic [TAG_BITS-1:0]   q3_tag,
    output logic                  q3_ready,
    output logic [31:0]           q3_value,

    input  logic [TAG_BITS-1:0]   q4_tag,
    output logic                  q4_ready,
    output logic [31:0]           q4_value,


  // Allocate interface (rename stage) : INSTRUCTION 1
  input  logic                  alloc1_en,       // request a new ROB entry
  input  logic [4:0]            alloc1_rd,       // destination architectural reg
  input logic [TAG_BITS-1:0]   alloc1_tag,      // ROB index for this instr

  // Allocate interface (rename stage):INSTRUCTION 2
  input  logic                  alloc2_en,       // request a new ROB entry
  input  logic [4:0]            alloc2_rd,       // destination architectural reg
  input logic [TAG_BITS-1:0]   alloc2_tag,      // ROB index for this instr

  // Writeback interface from the execute stage
  input  logic                  wb1_en,
  input  logic [TAG_BITS-1:0]   wb1_tag,      
  input  logic [31:0]           wb1_value,     

  input  logic                  wb2_en,
  input  logic [TAG_BITS-1:0]   wb2_tag,       
  input  logic [31:0]           wb2_value,

// Writeback interface from the memory stage
  input  logic                  wb3_en,
  input  logic [TAG_BITS-1:0]   wb3_tag,        
  input  logic [31:0]           wb3_value,      

  input  logic                  wb4_en,
  input  logic [TAG_BITS-1:0]   wb4_tag,        
  input  logic [31:0]           wb4_value,

  // Commit interface (to regfile) up to 2 commits per cycle
  output logic                  commit1_valid,  // head entry ready to commit
  output logic [4:0]            commit1_rd,
  output logic [31:0]           commit1_value,
  output logic [TAG_BITS - 1: 0] commit1_tag,
  input  logic                  commit1_en,     // commit this one

  output logic                  commit2_valid,  // head+1 entry ready to commit
  output logic [4:0]            commit2_rd,
  output logic [31:0]           commit2_value,
  output logic [TAG_BITS - 1: 0] commit2_tag,
  input  logic                  commit2_en     // commit second one

);

  // ROB storage: exactly 3 fields per entry
   logic [4:0]   dest_reg   [DEPTH] /* verilator public_flat_rw */ ;    // destination architectural register
    logic [31:0]  value      [DEPTH] /* verilator public_flat_rw */ ;   // result value
   logic         ready      [DEPTH] /* verilator public_flat_rw */ ;    // 1 = finished, ready to commit

  // pointers
  logic [TAG_BITS-1:0] head;  // oldest in-flight instruction
  logic [TAG_BITS-1:0] tail;  // next free slot
  logic                full_flag;

  logic rob_empty;
  logic rob_full;

//very simple query logic
  assign q1_ready = ready[q1_tag];
  assign q1_value = value[q1_tag];

  assign q2_ready = ready[q2_tag];
  assign q2_value = value[q2_tag];

  assign q3_ready = ready[q3_tag];
  assign q3_value = value[q3_tag];

  assign q4_ready = ready[q4_tag];
  assign q4_value = value[q4_tag];


  // basic empty/full
  assign rob_empty = (!full_flag) && (head == tail);
  assign rob_full  = full_flag;

  //Commit combinational: head and head+1
  logic [TAG_BITS-1:0] head_next;

  assign head_next = head + 1'b1;


//assigning the commit tags: (in order to free the entry from the Register Update Unit)
  assign commit1_tag   = head;
  assign commit2_tag   = head_next;


  // First commit slot (head)
  assign commit1_valid = !rob_empty && ready[head];
  assign commit1_rd    = dest_reg[head];
  assign commit1_value = value[head];

  // Second commit slot (head+1), only if first is valid & queue not effectively empty
  assign commit2_valid =
      commit1_valid &&                              // must be able to commit head
      ( (head_next != tail) || full_flag ) &&       // there is a second entry
      ready[head_next];                             // and it's ready

  assign commit2_rd    = dest_reg[head_next];
  assign commit2_value = value[head_next];

  //Sequential logic
  always_ff @(posedge clk) begin
    if (rst) begin
      head      <= 6'b000001;
      tail      <= 6'b000001;
      full_flag <= 1'b0;

      for (int i = 0; i < DEPTH; i++) begin
        dest_reg[i] <= 5'd0;
        value[i]    <= 32'd0;
        ready[i]    <= 1'b0;
      end

    end else begin
      //Allocation at tail - supports 0, 1, or 2 allocations per cycle
      if (alloc1_en) begin
        dest_reg[alloc1_tag] <= alloc1_rd;   // store destination register
        ready[alloc1_tag ]    <= 1'b0;        // not finished yet

        if (alloc2_en) begin
          // Allocate two entries: tail and tail+1
          dest_reg[alloc2_tag] <= alloc2_rd;
          ready[alloc2_tag]    <= 1'b0;

          // advance tail by 2
          tail <= tail + 2;

          // detect full condition after increment
          if ((tail + 2) == head)
            full_flag <= 1'b1;
        end else begin
          // Allocate only one entry: tail
          tail <= tail + 1'b1;

          // detect full condition after increment
          if ((tail + 1'b1) == head)
            full_flag <= 1'b1;
        end
      end else if (alloc2_en) begin
        // Only second allocation (first not enabled but second is)
        dest_reg[alloc2_tag] <= alloc2_rd;
        ready[alloc2_tag ]    <= 1'b0;

        tail <= tail + 1'b1;

        if ((tail + 1'b1) == head)
          full_flag <= 1'b1;
      end

      //Writeback:
      if (wb1_en) begin
        value[wb1_tag] <= wb1_value;
        ready[wb1_tag] <= 1'b1;
      end

      if (wb2_en) begin
        value[wb2_tag] <= wb2_value;
        ready[wb2_tag] <= 1'b1;
      end

      if (wb3_en) begin
        value[wb3_tag] <= wb3_value;
        ready[wb3_tag] <= 1'b1;
      end

      if (wb4_en) begin
        value[wb4_tag] <= wb4_value;
        ready[wb4_tag] <= 1'b1;
      end

      //Commit: retire up to 2 head entries in-order
      if (commit1_en && commit1_valid) begin
        // Clear ready bits 
        ready[head] <= 1'b0;

        if (commit2_en && commit2_valid) begin
          // Commit two entries: head and head_next
          ready[head_next] <= 1'b0;

          head <= head + 2;          // advance by 2
        end else begin
          // Commit only one entry: head
          head <= head_next;         // advance by 1
        end

        full_flag <= 1'b0;           // we definitely freed at least one slot
      end

      // If commit1_en is 0 or commit1_valid is 0, no commit happens this cycle
    end
  end

endmodule

