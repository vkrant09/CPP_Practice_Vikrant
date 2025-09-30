#include "simpletron.h"

int main() {
    Simpletron sim;
    sim.loadProgram();  // Load SML program into memory
    sim.run();          // Execute program
    return 0;
}
