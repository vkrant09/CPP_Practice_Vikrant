#ifndef VIKRANT_OCT11_TASK4_GLOBALFUNCTIONS_H
#define VIKRANT_OCT11_TASK4_GLOBALFUNCTIONS_H

#include "Vikrant_Oct11_Task4_Student.h"

// Function 1: Summarize grade distribution across students
void summarizeGrades(Student *students[], int studentCount);

// Function 2: Find top scorer by subject
const SubjectScore *findTopScorer(Student *students[], int studentCount, const std::string &subject);

// Function 3: Export all distinctions
void exportAllDistinctions(Student *students[], int studentCount, const std::string &filename);

#endif
