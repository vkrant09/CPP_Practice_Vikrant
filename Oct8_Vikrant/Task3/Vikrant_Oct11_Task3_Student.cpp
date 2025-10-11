#include "Vikrant_Oct11_Task3_Student.h"
#include <iostream>

// Add a new subject score
void Student::addScore(const SubjectScore &score)
{
    scores.push_back(score);
}

// Display all scores
void Student::displayAllScores() const
{
    std::cout << "\n--- Student Score Report ---" << std::endl;
    for (const auto &s : scores)
    {
        s.displayScore();
    }
}

// Compute average score
double Student::computeAverage() const
{
    if (scores.empty())
    {
        return 0.0;
    }

    int total = 0;
    for (const auto &s : scores)
    {
        total += s.getScore();
    }

    return static_cast<double>(total) / static_cast<double>(scores.size());
}

// Count Distinction subjects
int Student::countDistinctions() const
{
    int count = 0;
    for (const auto &s : scores)
    {
        if (s.getGrade() == GradeLevel::Distinction)
        {
            ++count;
        }
    }
    return count;
}

// Display only Merit and Distinction scores
void Student::displayMeritAndDistinction() const
{
    std::cout << "\n--- Merit and Distinction Scores ---" << std::endl;
    for (const auto &s : scores)
    {
        if (s.getGrade() == GradeLevel::Merit || s.getGrade() == GradeLevel::Distinction)
        {
            s.displayScore();
        }
    }
}
