#ifndef VIKRANT_OCT11_TASK3_STUDENT_H
#define VIKRANT_OCT11_TASK3_STUDENT_H

#include "Vikrant_Oct11_Task3_SubjectScore.h"
#include <vector>

// Class representing a Student with multiple subject scores
class Student
{
private:
    std::vector<SubjectScore> scores;

public:
    // Add a subject score
    void addScore(const SubjectScore &score);

    // Display all subject scores
    void displayAllScores() const;

    // Compute average score
    double computeAverage() const;

    // Count how many subjects are Distinction
    int countDistinctions() const;

    // Display only Merit and Distinction scores
    void displayMeritAndDistinction() const;
};

#endif
