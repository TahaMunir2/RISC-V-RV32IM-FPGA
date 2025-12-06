
#include "base_testbench.h"


unsigned int ticks = 0;

class ControlTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->EQ = 0;
        top->LT = 0;
        top->LTU = 0;
    }
    //member function of the class defined : to set instruction and evaluate
    //uint32_t : unisgned integer of 32 bits (to match RISCV32 instructions) : It is important to understand that the int type does not have a fixed size and is signed, thus the testing is not consistent if we use int 
    void loadInstr(uint32_t instr) {
        top->instr = instr;
        top->eval();
    }
};


//UPPER IMMEDIATE INSTRUCTIONS (LUI, AUIPC)
TEST_F(ControlTestbench, UpperImmediate) {
    // LUI
    loadInstr(0b00000000000000000001000010110111);
    EXPECT_EQ(top->RegWrite, 1);
    EXPECT_EQ(top->ALUCtrl, 0b1010);
    EXPECT_EQ(top->ALUSrc, 1);
    EXPECT_EQ(top->ImmSrc, 0b100);
    EXPECT_EQ(top->PCSrc, 0b00);
    EXPECT_EQ(top->ResultSrc, 0);
    EXPECT_EQ(top->MemWrite, 0);
    EXPECT_EQ(top->ALUsrc2, 0);

    // AUIPC
    loadInstr(0b00000000000000000001000010010111);
    EXPECT_EQ(top->RegWrite, 1);
    EXPECT_EQ(top->ALUCtrl, 0b1011);
    EXPECT_EQ(top->ALUSrc, 1);
    EXPECT_EQ(top->ImmSrc, 0b100);
    EXPECT_EQ(top->PCSrc, 0b00);
    EXPECT_EQ(top->ALUsrc2, 1);
}


//JUMP INSTRUCTIONS (JAL, JALR)
TEST_F(ControlTestbench, Jumps) {
    //JAL
    loadInstr(0b00000000000100000000000011101111);
    EXPECT_EQ(top->RegWrite, 1);
    EXPECT_EQ(top->PCSrc, 0b01);
    EXPECT_EQ(top->ImmSrc, 0b011);

    //JALR
    loadInstr(0b00000000000000001000000011100111);
    EXPECT_EQ(top->RegWrite, 1);
    EXPECT_EQ(top->PCSrc, 0b10);
    EXPECT_EQ(top->ImmSrc, 0b000);
}


// BRANCH INSTRUCTIONS (BEQ, BNE, BLT, BGE, BLTU, BGEU)
TEST_F(ControlTestbench, Branches) {
    //BEQ taken
    loadInstr(0b00000000000100000000000001100011);
    top->EQ = 1; top->eval();
    EXPECT_EQ(top->PCSrc, 0b01);

    //BEQ not taken
    top->EQ = 0; top->eval();
    EXPECT_EQ(top->PCSrc, 0b00);

    //BNE taken
    loadInstr(0b00000000000100000001000001100011);
    top->EQ = 0; top->eval();
    EXPECT_EQ(top->PCSrc, 0b01);

    //BNE not taken
    top->EQ = 1; top->eval();
    EXPECT_EQ(top->PCSrc, 0b00);

    //BLT taken
    loadInstr(0b00000000000100000100000001100011);
    top->LT = 1; top->eval();
    EXPECT_EQ(top->PCSrc, 0b01);

    //BLT not taken
    top->LT = 0; top->eval();
    EXPECT_EQ(top->PCSrc, 0b00);

    //BGE taken
    loadInstr(0b00000000000100000101000001100011);
    top->LT = 0; top->eval();
    EXPECT_EQ(top->PCSrc, 0b01);

    //BGE not taken
    top->LT = 1; top->eval();
    EXPECT_EQ(top->PCSrc, 0b00);

    //BLTU taken
    loadInstr(0b00000000000100000110000001100011);
    top->LTU = 1; top->eval();
    EXPECT_EQ(top->PCSrc, 0b01);

    //BLTU not taken
    top->LTU = 0; top->eval();
    EXPECT_EQ(top->PCSrc, 0b00);

    //BGEU taken
    loadInstr(0b00000000000100000111000001100011);
    top->LTU = 0; top->eval();
    EXPECT_EQ(top->PCSrc, 0b01);

    //BGEU not taken
    top->LTU = 1; top->eval();
    EXPECT_EQ(top->PCSrc, 0b00);
}


// LOAD INSTRUCTIONS (LB, LH, LW, LBU, LHU)
TEST_F(ControlTestbench, Loads) {
    //LB
    loadInstr(0b00000000000100000000000010000011);
    EXPECT_EQ(top->RegWrite, 1);
    EXPECT_EQ(top->ResultSrc, 0b01);
    EXPECT_EQ(top->LoadSize, 0b00);
    EXPECT_EQ(top->LoadUnsigned, 0);

    //LH
    loadInstr(0b00000000000100000001000010000011);
    EXPECT_EQ(top->LoadSize, 0b01);
    EXPECT_EQ(top->LoadUnsigned, 0);

    //LW
    loadInstr(0b00000000000100000010000010000011);
    EXPECT_EQ(top->LoadSize, 0b10);
    EXPECT_EQ(top->LoadUnsigned, 0);

    //LBU
    loadInstr(0b00000000000100000100000010000011);
    EXPECT_EQ(top->LoadSize, 0b00);
    EXPECT_EQ(top->LoadUnsigned, 1);

    // LHU
    loadInstr(0b00000000000100000101000010000011);
    EXPECT_EQ(top->LoadSize, 0b01);
    EXPECT_EQ(top->LoadUnsigned, 1);
}


//STORE INSTRUCTIONS (SB,SH, SW)

TEST_F(ControlTestbench, Stores) {
    //SB
    loadInstr(0b00000000000100000000000010100011);
    EXPECT_EQ(top->MemWrite, 1);
    EXPECT_EQ(top->SizeWrite, 0b00);

    //SH
    loadInstr(0b00000000000100000001000010100011);
    EXPECT_EQ(top->MemWrite, 1);
    EXPECT_EQ(top->SizeWrite, 0b01);

    //SW
    loadInstr(0b00000000000100000010000010100011);
    EXPECT_EQ(top->MemWrite, 1);
    EXPECT_EQ(top->SizeWrite, 0b10);
}


// I-TYPE (ADDI,SLTI, SLTIU,XORI,ORI, ANDI, SLLI, SRLI, SRAI)
TEST_F(ControlTestbench, ITypeALU) {
    // ADDI
    loadInstr(0b00000000000100000000000010010011);
    EXPECT_EQ(top->ALUCtrl, 0b0000);
    EXPECT_EQ(top->ALUSrc, 1);

    // SLTI
    loadInstr(0b00000000000100000010000010010011);
    EXPECT_EQ(top->ALUCtrl, 0b1000);

    // SLTIU
    loadInstr(0b00000000000100000011000010010011);
    EXPECT_EQ(top->ALUCtrl, 0b1001);

    //XORI
    loadInstr(0b00000000000100000100000010010011);
    EXPECT_EQ(top->ALUCtrl, 0b0100);

    //ORI
    loadInstr(0b00000000000100000110000010010011);
    EXPECT_EQ(top->ALUCtrl, 0b0011);

    //ANDI
    loadInstr(0b00000000000100000111000010010011);
    EXPECT_EQ(top->ALUCtrl, 0b0010);

    //SLLI
    loadInstr(0b00000000000100000001000010010011);
    EXPECT_EQ(top->ALUCtrl, 0b0101);

    //SRLI
    loadInstr(0b00000000000100000101000010010011);
    EXPECT_EQ(top->ALUCtrl, 0b0110);

    // SRAI
    loadInstr(0b01000000000100000101000010010011);
    EXPECT_EQ(top->ALUCtrl, 0b0111);
}


// R-TYPE ALU INSTRUCTIONS (ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND)
TEST_F(ControlTestbench, RTypeALU) {
    //ADD
    loadInstr(0b00000000000100000000000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0000);
    EXPECT_EQ(top->ALUSrc, 0);

    //SUB
    loadInstr(0b01000000000100000000000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0001);

    //SLL
    loadInstr(0b00000000000100000001000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0101);

    //SLT
    loadInstr(0b00000000000100000010000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b1000);

    // SLTU
    loadInstr(0b00000000000100000011000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b1001);

    // XOR
    loadInstr(0b00000000000100000100000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0100);

    // SRL
    loadInstr(0b00000000000100000101000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0110);

    // SRA
    loadInstr(0b01000000000100000101000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0111);

    // OR
    loadInstr(0b00000000000100000110000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0011);

    // AND
    loadInstr(0b00000000000100000111000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0010);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    auto res =RUN_ALL_TESTS();
    return res;
}


