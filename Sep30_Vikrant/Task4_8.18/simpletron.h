#ifndef SIMPLETRON_H
#define SIMPLETRON_H

class Simpletron {
private:
    static const int MEMORY_SIZE = 100;
    int memory[MEMORY_SIZE];   // 100-word memory
    int accumulator;           // Accumulator register
    int instructionCounter;    // Current memory location
    int instructionRegister;   // Current instruction
    int operationCode;         // Operation part of instruction
    int operand;               // Operand part of instruction

    void executeInstruction();

public:
    Simpletron();
    void loadProgram();
    void run();
};

#endif
