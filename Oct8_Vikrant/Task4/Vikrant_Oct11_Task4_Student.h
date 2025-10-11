#ifndef VIKRANT_OCT11_TASK4_STUDENT_H
#define VIKRANT_OCT11_TASK4_STUDENT_H

#include <vector>
#include <string>
#include "Vikrant_Oct11_Task3_SubjectScore.h"

// Class representing a single student
class Student
{
private:
    std::string studentName;
    std::vector<SubjectScore> scores;

public:
    // Constructor
    explicit Student(const std::string &name);

    // Add subject score
    void addScore(const SubjectScore &score);

    // Display all subject scores
    void displayAllScores() const;

    // Get all scores
    const std::vector<SubjectScore> &getScores() const;

    // Get student name
    std::string getStudentName() const;
};

#endif
