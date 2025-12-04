module rat #(
  parameter NREGS     = 32,
  parameter PROD_BITS = 6
) (
  input  logic                 clk,
  input  logic                 rst,

  input  logic [4:0] inst1_rd,
  output logic [PROD_BITS-1:0] inst1_prod_id,

  input  logic [4:0]           inst2_rd,
  output logic [PROD_BITS-1:0] inst2_prod_id,

  input  logic [4:0]           rs1,
  output logic [PROD_BITS-1:0] rs1_prod_id,
  input  logic [4:0]           rs2,
  output logic [PROD_BITS-1:0] rs2_prod_id,
  input  logic [4:0]           rs3,
  output logic [PROD_BITS-1:0] rs3_prod_id,
  input  logic [4:0]           rs4,
  output logic [PROD_BITS-1:0] rs4_prod_id,

  output logic [PROD_BITS-1:0] latest_tag
);

  logic [PROD_BITS-1:0] rat_table [NREGS];
  logic [PROD_BITS-1:0] producer_counter;

  // Combinational: compute the two tags for this cycle
  assign inst1_prod_id = producer_counter - 6'b000001;
  assign inst2_prod_id = producer_counter;
  assign latest_tag = producer_counter;  // or producer_counter + 1 depending on your needs

  // Read sources (combinational)
  assign rs1_prod_id = rat_table[rs1];
  assign rs2_prod_id = rat_table[rs2];
  assign rs3_prod_id = rat_table[rs3];
  assign rs4_prod_id = rat_table[rs4];

  always_ff @(posedge clk) begin
    if (rst) begin
      producer_counter <= 6'b000000;
      for (int i = 0; i < NREGS; i++) begin
        rat_table[i] <= '0;
      end

    end else begin
      // Update RAT for instruction 1
      if (inst1_rd != 5'd0) begin
        rat_table[inst1_rd] <= producer_counter - 6'b000001;
      end

      // Update RAT for instruction 2
      if (inst2_rd != 5'd0) begin
        rat_table[inst2_rd] <= producer_counter;
      end

      // Increment counter by 2 (for 2 instructions)
      producer_counter <= producer_counter + 2;
    end
  end

endmodule

