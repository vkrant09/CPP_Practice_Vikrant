#include "Vikrant_Oct11_Task4_GlobalFunctions.h"
#include <iostream>

int main()
{
    // Create students
    Student *students[3];
    students[0] = new Student("Alice");
    students[1] = new Student("Bob");
    students[2] = new Student("Charlie");

    // Populate student data
    students[0]->addScore(SubjectScore("Math", 92, GradeLevel::Distinction));
    students[0]->addScore(SubjectScore("Physics", 78, GradeLevel::Merit));

    students[1]->addScore(SubjectScore("Math", 85, GradeLevel::Merit));
    students[1]->addScore(SubjectScore("Chemistry", 65, GradeLevel::Pass));

    students[2]->addScore(SubjectScore("Math", 95, GradeLevel::Distinction));
    students[2]->addScore(SubjectScore("History", 45, GradeLevel::Fail));
    students[2]->addScore(SubjectScore("English", 88, GradeLevel::Distinction));

    // Display all student reports
    for (int i = 0; i < 3; ++i)
    {
        students[i]->displayAllScores();
    }

    // Global Function 1: Summarize grades
    summarizeGrades(students, 3);

    // Global Function 2: Find top scorer in "Math"
    const SubjectScore *topMath = findTopScorer(students, 3, "Math");
    std::cout << "\n--- Top Scorer in Math ---\n";
    if (topMath != nullptr)
    {
        topMath->displayScore();
    }
    else
    {
        std::cout << "No Math scores found.\n";
    }

    // Global Function 3: Export all distinctions
    exportAllDistinctions(students, 3, "distinction_report.txt");

    // Clean up
    for (int i = 0; i < 3; ++i)
    {
        delete students[i];
    }

    return 0;
}
