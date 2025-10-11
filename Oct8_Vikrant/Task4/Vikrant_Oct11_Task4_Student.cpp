#include "Vikrant_Oct11_Task4_Student.h"
#include <iostream>

// Constructor
Student::Student(const std::string &name) : studentName(name) {}

// Add subject score
void Student::addScore(const SubjectScore &score)
{
    scores.push_back(score);
}

// Display all subject scores
void Student::displayAllScores() const
{
    std::cout << "\n--- Report for Student: " << studentName << " ---" << std::endl;
    for (const auto &s : scores)
    {
        s.displayScore();
    }
}

// Return all scores (const reference)
const std::vector<SubjectScore> &Student::getScores() const
{
    return scores;
}

// Get student name
std::string Student::getStudentName() const
{
    return studentName;
}
