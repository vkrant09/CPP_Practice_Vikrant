#ifndef VIKRANT_OCT11_TASK3_SUBJECTSCORE_H
#define VIKRANT_OCT11_TASK3_SUBJECTSCORE_H

#include <string>
#include <iostream>

// Enum class representing grade levels
enum class GradeLevel
{
    Fail,
    Pass,
    Merit,
    Distinction
};

// Utility: Convert enum to readable string
std::string gradeToString(GradeLevel grade);

// Class representing a single subject score
class SubjectScore
{
private:
    std::string subjectName;
    int score;
    GradeLevel grade;

public:
    // Constructor
    SubjectScore(const std::string &name, int marks, GradeLevel gradeLevel);

    // Display a single subject score
    void displayScore() const;

    // Getters
    int getScore() const;
    std::string getSubjectName() const;
    GradeLevel getGrade() const;
};

#endif
