
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



//UPPER IMMEDIATE INSTRUCTIONS

// LUI: 
TEST_F(ControlTestbench, LUI) {
    loadInstr(0b00000000000000000001000010110111);
    EXPECT_EQ(top->RegWrite,1);
    EXPECT_EQ(top->ALUCtrl, 0b1010);
    EXPECT_EQ(top->ALUSrc,1);
    EXPECT_EQ(top->ImmSrc, 0b100);
    EXPECT_EQ(top->PCSrc,0b00);
    EXPECT_EQ(top->ResultSrc, 0);
    EXPECT_EQ(top->MemWrite,0);
    EXPECT_EQ(top->SizeWrite,0);
}
// AUIPC
TEST_F(ControlTestbench, AUIPC) {
    loadInstr(0b00000000000000000001000010010111);
    EXPECT_EQ(top->RegWrite,1);
    EXPECT_EQ(top->ALUCtrl, 0b1011);
    EXPECT_EQ(top->ALUSrc, 1 );
    EXPECT_EQ(top->ImmSrc,0b100);
    EXPECT_EQ(top->PCSrc,0b00);
    EXPECT_EQ(top->ALUsrc2, 1);
}



//JUMPS

TEST_F(ControlTestbench, JAL) {
    loadInstr(0b00000000000100000000000011101111);
    EXPECT_EQ(top->RegWrite,1);
    EXPECT_EQ(top->PCSrc, 0b01);
    EXPECT_EQ(top->ImmSrc,0b011);
}
TEST_F(ControlTestbench,JALR) {
    loadInstr(0b00000000000000001000000011100111);
    EXPECT_EQ(top->RegWrite,1);
    EXPECT_EQ(top->PCSrc,  0b10);
    EXPECT_EQ(top->ImmSrc,  0b000);
}



 //BRANCH INSTRUCTIONS


TEST_F(ControlTestbench,BEQ_taken) {
    loadInstr(0b00000000000100000000000001100011);
    top->EQ = 1;
    top->eval();
    EXPECT_EQ(top->PCSrc, 0b01);
}
TEST_F(ControlTestbench,BEQ_not_taken) {
    loadInstr(0b00000000000100000000000001100011);
    top->EQ = 0;
    top->eval();
    EXPECT_EQ(top->PCSrc,0b00);
}


TEST_F(ControlTestbench,BNE_taken) {
    loadInstr(0b00000000000100000001000001100011);
    top->EQ=0;
    top->eval();
    EXPECT_EQ(top->PCSrc,  0b01);
}


TEST_F(ControlTestbench,  BNE_not_taken) {
    loadInstr(0b00000000000100000001000001100011);
    top->EQ = 1;
    top->eval();
    EXPECT_EQ(top->PCSrc,  0b00);
}



TEST_F(ControlTestbench,  BLT_taken) {
    loadInstr(0b00000000000100000100000001100011);
    top->LT =1;
    top->eval();
    EXPECT_EQ(top->PCSrc,  0b01);
}



TEST_F(ControlTestbench,BLT_not_taken) {
    loadInstr(0b00000000000100000100000001100011);
    top->LT = 0;
    top->eval();
    EXPECT_EQ(top->PCSrc, 0b00);
}
TEST_F(ControlTestbench, BGE_taken) {
    loadInstr(0b00000000000100000101000001100011);
    top->LT = 0;
    top->eval();
    EXPECT_EQ(top->PCSrc, 0b01);
}


TEST_F(ControlTestbench, BGE_not_taken) {
    loadInstr(0b00000000000100000101000001100011);
    top->LT = 1;
    top->eval();
    EXPECT_EQ(top->PCSrc, 0b00);
}
TEST_F(ControlTestbench, BLTU_taken) {
    loadInstr(0b00000000000100000110000001100011);
    top->LTU = 1;
    top->eval();
    EXPECT_EQ(top->PCSrc, 0b01);
}



TEST_F(ControlTestbench, BLTU_not_taken) {
    loadInstr(0b00000000000100000110000001100011);
    top->LTU = 0;
    top->eval();
    EXPECT_EQ(top->PCSrc, 0b00);
}




TEST_F(ControlTestbench, BGEU_taken) {
    loadInstr(0b00000000000100000111000001100011);
    top->LTU =0;
    top->eval();
    EXPECT_EQ(top->PCSrc,  0b01);
}



TEST_F(ControlTestbench,BGEU_not_taken) {
    loadInstr(0b00000000000100000111000001100011);
    top->LTU =1;
    top->eval();
    EXPECT_EQ(top->PCSrc,0b00);
}



//LOAD INSTRUCTIONS

TEST_F(ControlTestbench,LB) {
    loadInstr(0b00000000000100000000000010000011);
    EXPECT_EQ(top->RegWrite,1);
    EXPECT_EQ(top->ResultSrc,0b01);
    EXPECT_EQ(top->LoadSize,0b00);
    EXPECT_EQ(top->LoadUnsigned,0);
}
TEST_F(ControlTestbench, LH) {
    loadInstr(0b00000000000100000001000010000011);
    EXPECT_EQ(top->LoadSize,  0b01);
    EXPECT_EQ(top->LoadUnsigned,0);
}
TEST_F(ControlTestbench, LW) {
    loadInstr(0b00000000000100000010000010000011);
    EXPECT_EQ(top->LoadSize, 0b10);
    EXPECT_EQ(top->LoadUnsigned, 0);
}
TEST_F(ControlTestbench, LBU) {
    loadInstr(0b00000000000100000100000010000011);
    EXPECT_EQ(top->LoadSize,0b00);
    EXPECT_EQ(top->LoadUnsigned,  1);
}



TEST_F(ControlTestbench,LHU) {
    loadInstr(0b00000000000100000101000010000011);
    EXPECT_EQ(top->LoadSize,0b01);
    EXPECT_EQ(top->LoadUnsigned,1);
}



//STORE INSTRUCTIONS


TEST_F(ControlTestbench, SB) {
    loadInstr(0b00000000000100000000000010100011);
    EXPECT_EQ(top->MemWrite,1);
    EXPECT_EQ(top->SizeWrite, 0b00);
}
TEST_F(ControlTestbench, SH) {
    loadInstr(0b00000000000100000001000010100011);
    EXPECT_EQ(top->MemWrite, 1);
    EXPECT_EQ(top->SizeWrite, 0b01);
}
TEST_F(ControlTestbench, SW) {
    loadInstr(0b00000000000100000010000010100011);
    EXPECT_EQ(top->MemWrite, 1);
    EXPECT_EQ(top->SizeWrite,0b10);
}



//I-TYPE ALU (OPIMM)
TEST_F(ControlTestbench,ADDI) {
    loadInstr(0b00000000000100000000000010010011);
    EXPECT_EQ(top->ALUCtrl,0b0000);
    EXPECT_EQ(top->ALUSrc,1);
}

TEST_F(ControlTestbench, SLTI) {
    loadInstr(0b00000000000100000010000010010011);
    EXPECT_EQ(top->ALUCtrl,0b1000);
}
TEST_F(ControlTestbench,SLTIU) {
    loadInstr(0b00000000000100000011000010010011);
    EXPECT_EQ(top->ALUCtrl,0b1001);
}


TEST_F(ControlTestbench, XORI) {
    loadInstr(0b00000000000100000100000010010011);
    EXPECT_EQ(top->ALUCtrl, 0b0100);
}


TEST_F(ControlTestbench, ORI) {
    loadInstr(0b00000000000100000110000010010011);
    EXPECT_EQ(top->ALUCtrl,0b0011);
}

TEST_F(ControlTestbench, ANDI) {
    loadInstr(0b00000000000100000111000010010011);
    EXPECT_EQ(top->ALUCtrl,0b0010);
}


TEST_F(ControlTestbench,SLLI) {
    loadInstr(0b00000000000100000001000010010011);
    EXPECT_EQ(top->ALUCtrl,0b0101);
}


TEST_F(ControlTestbench,SRLI) {
    loadInstr(0b00000000000100000101000010010011);
    EXPECT_EQ(top->ALUCtrl, 0b0110);
}

TEST_F(ControlTestbench, SRAI) {
    loadInstr(0b01000000000100000101000010010011);
    EXPECT_EQ(top->ALUCtrl,0b0111);
}



//R-TYPE ALU (OP)
TEST_F(ControlTestbench, ADD) {
    loadInstr(0b00000000000100000000000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0000);
}
TEST_F(ControlTestbench, SUB) {
    loadInstr(0b01000000000100000000000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0001);
}
TEST_F(ControlTestbench,SLL) {
    loadInstr(0b00000000000100000001000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0101);
}


TEST_F(ControlTestbench, SLT) {
    loadInstr(0b00000000000100000010000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b1000);
}


TEST_F(ControlTestbench, SLTU) {
    loadInstr(0b00000000000100000011000010110011);
    EXPECT_EQ(top->ALUCtrl,0b1001);
}

TEST_F(ControlTestbench,XOR) {
    loadInstr(0b00000000000100000100000010110011) ;
    EXPECT_EQ(top->ALUCtrl, 0b0100);
}

TEST_F(ControlTestbench, SRL) {
    loadInstr(0b00000000000100000101000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0110);
}
TEST_F(ControlTestbench, SRA) {
    loadInstr(0b01000000000100000101000010110011);
    EXPECT_EQ(top->ALUCtrl,0b0111);
}

TEST_F(ControlTestbench,OR) {
    loadInstr(0b00000000000100000110000010110011);
    EXPECT_EQ(top->ALUCtrl, 0b0011);
}
TEST_F(ControlTestbench, AND) {
    loadInstr(0b00000000000100000111000010110011);
    EXPECT_EQ(top->ALUCtrl,0b0010);
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    auto res =RUN_ALL_TESTS();
    return res;
}


