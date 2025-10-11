#include "Vikrant_Oct11_Task4_GlobalFunctions.h"
#include <iostream>
#include <map>

// Summarize grade distribution across all students
void summarizeGrades(Student *students[], int studentCount)
{
    std::map<GradeLevel, int> summary = {
        {GradeLevel::Fail, 0},
        {GradeLevel::Pass, 0},
        {GradeLevel::Merit, 0},
        {GradeLevel::Distinction, 0}};

    for (int i = 0; i < studentCount; ++i)
    {
        if (students[i] == nullptr)
        {
            continue;
        }

        const auto &scores = students[i]->getScores();
        for (const auto &s : scores)
        {
            ++summary[s.getGrade()];
        }
    }

    std::cout << "\n--- Global Grade Summary ---" << std::endl;
    for (const auto &pair : summary)
    {
        std::cout << gradeToString(pair.first) << ": " << pair.second << std::endl;
    }
}

// Find top scorer for a specific subject
const SubjectScore *findTopScorer(Student *students[], int studentCount, const std::string &subject)
{
    const SubjectScore *top = nullptr;

    for (int i = 0; i < studentCount; ++i)
    {
        if (students[i] == nullptr)
        {
            continue;
        }

        const auto &scores = students[i]->getScores();
        for (const auto &s : scores)
        {
            if (s.getSubjectName() == subject)
            {
                if (top == nullptr || s.getScore() > top->getScore())
                {
                    top = &s;
                }
            }
        }
    }

    return top;
}

// Export (display) all distinction scores across students
void exportAllDistinctions(Student *students[], int studentCount, const std::string &filename)
{
    std::cout << "\n--- Exporting All Distinctions (" << filename << ") ---" << std::endl;

    bool foundAny = false;

    for (int i = 0; i < studentCount; ++i)
    {
        if (students[i] == nullptr)
        {
            continue;
        }

        const auto &scores = students[i]->getScores();
        for (const auto &s : scores)
        {
            if (s.getGrade() == GradeLevel::Distinction)
            {
                foundAny = true;
                std::cout << "Student: " << students[i]->getStudentName()
                          << " | Subject: " << s.getSubjectName()
                          << " | Score: " << s.getScore()
                          << " | Grade: " << gradeToString(s.getGrade())
                          << std::endl;
            }
        }
    }

    if (!foundAny)
    {
        std::cout << "No distinctions found.\n";
    }
}
