module rat #(
  parameter NREGS     = 32,
  parameter PROD_BITS = 6
) (
  input  logic                 clk,
  input  logic                 rst,

  // Destination registers of 2 fetched instructions (in-order)
  input  logic [4:0] inst1_rd,
  output logic [PROD_BITS-1:0] inst1_prod_id,

  input  logic [4:0]           inst2_rd,
  output logic [PROD_BITS-1:0] inst2_prod_id,

  // Query source producer for operands
  input  logic [4:0]           rs1,
  output logic [PROD_BITS-1:0] rs1_prod_id,
  input  logic [4:0]           rs2,
  output logic [PROD_BITS-1:0] rs2_prod_id,
  input  logic [4:0]           rs3,
  output logic [PROD_BITS-1:0] rs3_prod_id,
  input  logic [4:0]           rs4,
  output logic [PROD_BITS-1:0] rs4_prod_id,

  //latest tag
  output logic [PROD_BITS-1:0] latest_tag
);

  // Each RAT entry = last producer ID for that architectural register
  logic [PROD_BITS-1:0] rat_table [NREGS];


  // global producer counter
  logic [PROD_BITS-1:0] producer_counter;

    assign latest_tag = producer_counter -1;


  // read sources
  assign rs1_prod_id = rat_table[rs1];
  assign rs2_prod_id = rat_table[rs2];
  assign rs3_prod_id = rat_table[rs3];
  assign rs4_prod_id = rat_table[rs4];

  always_ff @(posedge clk) begin
    if (rst) begin
      producer_counter <= '0;
      for (int i = 0; i < NREGS; i++) begin
        rat_table[i] <= '0;
      end
      inst1_prod_id <= '0;
      inst2_prod_id <= '0;

    end else begin
      // instruction 1 uses current counter
      inst1_prod_id <= producer_counter;
      if (inst1_rd != 5'd0) begin  // never rename x0
        rat_table[inst1_rd] <= producer_counter;
      end
      producer_counter <= producer_counter + 1;

      // instruction 2 uses next value
      inst2_prod_id <= producer_counter;
      if (inst2_rd != 5'd0) begin
        rat_table[inst2_rd] <= producer_counter;
      end
      producer_counter <= producer_counter + 1;
    end
  end

endmodule

