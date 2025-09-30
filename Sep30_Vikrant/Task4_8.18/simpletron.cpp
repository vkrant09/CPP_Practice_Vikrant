#include <iostream>
#include "simpletron.h"

Simpletron::Simpletron() {
    accumulator = 0;
    instructionCounter = 0;
    instructionRegister = 0;
    operationCode = 0;
    operand = 0;
    for (int i = 0; i < MEMORY_SIZE; i++)
        memory[i] = 0;
}

// Load a program into memory from user input
void Simpletron::loadProgram() {
    int instruction;
    std::cout << "*** Welcome to Simpletron! ***\n";
    std::cout << "*** Please enter your program one instruction ***\n";
    std::cout << "*** (or data word) at a time. Enter -99999 to stop ***\n";

    for (int i = 0; i < MEMORY_SIZE; i++) {
        std::cout << i << " ? ";
        std::cin >> instruction;
        if (instruction == -99999) break;
        memory[i] = instruction;
    }
    std::cout << "*** Program loading completed ***\n";
}

// Execute loaded program
void Simpletron::run() {
    std::cout << "*** Program execution begins ***\n";
    while (true) {
        instructionRegister = memory[instructionCounter];
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;

        executeInstruction();
        instructionCounter++;
    }
}

// Execute a single instruction
void Simpletron::executeInstruction() {
    switch (operationCode) {
        case 10: // READ
            std::cout << "Enter an integer: ";
            std::cin >> memory[operand];
            break;
        case 11: // WRITE
            std::cout << memory[operand] << std::endl;
            break;
        case 20: // LOAD
            accumulator = memory[operand];
            break;
        case 21: // STORE
            memory[operand] = accumulator;
            break;
        case 30: // ADD
            accumulator += memory[operand];
            break;
        case 31: // SUBTRACT
            accumulator -= memory[operand];
            break;
        case 32: // DIVIDE
            if (memory[operand] != 0)
                accumulator /= memory[operand];
            else {
                std::cout << "*** Division by zero error ***\n";
                exit(1);
            }
            break;
        case 33: // MULTIPLY
            accumulator *= memory[operand];
            break;
        case 40: // BRANCH
            instructionCounter = operand - 1; // -1 because it will be incremented
            break;
        case 41: // BRANCHNEG
            if (accumulator < 0) instructionCounter = operand - 1;
            break;
        case 42: // BRANCHZERO
            if (accumulator == 0) instructionCounter = operand - 1;
            break;
        case 43: // HALT
            std::cout << "*** Simpletron execution terminated ***\n";
            exit(0);
        default:
            std::cout << "*** Unknown operation code encountered ***\n";
            exit(1);
    }
}
