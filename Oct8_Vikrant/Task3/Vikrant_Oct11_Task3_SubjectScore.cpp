#include "Vikrant_Oct11_Task3_SubjectScore.h"

// Convert GradeLevel to readable string
std::string gradeToString(GradeLevel grade)
{
    switch (grade)
    {
    case GradeLevel::Fail:
        return "Fail";
    case GradeLevel::Pass:
        return "Pass";
    case GradeLevel::Merit:
        return "Merit";
    case GradeLevel::Distinction:
        return "Distinction";
    default:
        return "Unknown";
    }
}

// Constructor
SubjectScore::SubjectScore(const std::string &name, int marks, GradeLevel gradeLevel)
    : subjectName(name), score(marks), grade(gradeLevel) {}

// Display one subject score
void SubjectScore::displayScore() const
{
    std::cout << "Subject: " << subjectName
              << " | Score: " << score
              << " | Grade: " << gradeToString(grade)
              << std::endl;
}

// Getters
int SubjectScore::getScore() const { return score; }
std::string SubjectScore::getSubjectName() const { return subjectName; }
GradeLevel SubjectScore::getGrade() const { return grade; }
