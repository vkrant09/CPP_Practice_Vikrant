#include "Vikrant_Oct1_Task4_student.h"
#include <iostream>
#include <vector>

int main() {
    // Sample data from the question
    Freshman f("Amit", "UG101", "Computer Science", 1, 15);
    HonorsSenior hs("Neha", "UG401", "Physics", 4, 120, "Quantum Entanglement Thesis");
    ExchangeSenior es("Luca", "UG402", "Mechanical", 4, 110, "Politecnico di Milano");

    ThesisMastersStudent tm("Priya", "GR201", "Electrical", "Dr. Rao", "Smart Grid Optimization");
    NonThesisMastersStudent ntm("Raj", "GR202", "Civil", "Dr. Mehta", "Bridge Load Simulation");

    PhDCandidate phd("Sneha", "GR301", "Biotech", "Dr. Kapoor", "Gene Editing Ethics", 3);
    PostDocFellow pdf("Dr. Tanmay", "GR401", "AI Research", "Dr. Bose", "DARPA Grant");

    // Store all students in vector for polymorphism
    std::vector<Student*> students = {&f, &hs, &es, &tm, &ntm, &phd, &pdf};

    // Polymorphic calls
    for (Student* s : students) {
        s->displayInfo();
        std::cout << " | Level: " << s->getLevel() << std::endl;
    }

    return 0;
}
