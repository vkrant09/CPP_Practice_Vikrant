#include "Vikrant_Oct11_Task3_Student.h"
#include <iostream>

int main()
{
    Student student;

    // Adding sample data as per problem statement
    student.addScore(SubjectScore("Math", 92, GradeLevel::Distinction));
    student.addScore(SubjectScore("Physics", 78, GradeLevel::Merit));
    student.addScore(SubjectScore("Chemistry", 65, GradeLevel::Pass));
    student.addScore(SubjectScore("History", 45, GradeLevel::Fail));
    student.addScore(SubjectScore("English", 88, GradeLevel::Distinction));

    // Display all scores
    student.displayAllScores();

    // Compute and display average score
    double avg = student.computeAverage();
    std::cout << "\nAverage Score: " << avg << std::endl;

    // Count and display distinctions
    int distinctions = student.countDistinctions();
    std::cout << "Number of Distinction subjects: " << distinctions << std::endl;

    // Display only Merit and Distinction scores
    student.displayMeritAndDistinction();

    return 0;
}
