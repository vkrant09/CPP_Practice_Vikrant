#ifndef VIKRANT_OCT6_TASK2_STUDENT_H
#define VIKRANT_OCT6_TASK2_STUDENT_H

#include <string>

// Base class for all students
class Student {
protected:
    std::string studentName;
    int studentId;

public:
    Student(const std::string& name, int id);
    virtual void displayInfo() const; // virtual so derived classes can override
    virtual ~Student(); // virtual destructor for cleanup
};

// Derived class for undergraduates
class UndergraduateStudent : public Student {
public:
    UndergraduateStudent(const std::string& name, int id);
    void displayInfo() const override;
};

// Derived classes from UndergraduateStudent
class Freshman : public UndergraduateStudent {
public:
    Freshman(const std::string& name, int id);
    void displayInfo() const override;
};

class Sophomore : public UndergraduateStudent {
public:
    Sophomore(const std::string& name, int id);
    void displayInfo() const override;
};

class Junior : public UndergraduateStudent {
public:
    Junior(const std::string& name, int id);
    void displayInfo() const override;
};

class Senior : public UndergraduateStudent {
public:
    Senior(const std::string& name, int id);
    void displayInfo() const override;
};

// Derived class for graduate students
class GraduateStudent : public Student {
public:
    GraduateStudent(const std::string& name, int id);
    void displayInfo() const override;
};

// Derived classes from GraduateStudent
class MastersStudent : public GraduateStudent {
public:
    MastersStudent(const std::string& name, int id);
    void displayInfo() const override;
};

class DoctoralStudent : public GraduateStudent {
public:
    DoctoralStudent(const std::string& name, int id);
    void displayInfo() const override;
};

#endif
