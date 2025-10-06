#include "Vikrant_Oct6_Task2_Student.h"
#include <iostream>

// constructor for base class
Student::Student(const std::string& name, int id) : studentName(name), studentId(id) {}

// destructor
Student::~Student() {}

// base version of display function
void Student::displayInfo() const {
    std::cout << "Student Name: " << studentName << ", ID: " << studentId << std::endl;
}

UndergraduateStudent::UndergraduateStudent(const std::string& name, int id)
    : Student(name, id) {}

void UndergraduateStudent::displayInfo() const {
    std::cout << "Undergraduate Student -> Name: " << studentName << ", ID: " << studentId << std::endl;
}

// freshman subclass
Freshman::Freshman(const std::string& name, int id) : UndergraduateStudent(name, id) {}

void Freshman::displayInfo() const {
    std::cout << "Freshman Student: " << studentName << " (ID: " << studentId << ")" << std::endl;
}

// sophomore subclass
Sophomore::Sophomore(const std::string& name, int id) : UndergraduateStudent(name, id) {}

void Sophomore::displayInfo() const {
    std::cout << "Sophomore Student: " << studentName << " (ID: " << studentId << ")" << std::endl;
}

// junior subclass
Junior::Junior(const std::string& name, int id) : UndergraduateStudent(name, id) {}

void Junior::displayInfo() const {
    std::cout << "Junior Student: " << studentName << " (ID: " << studentId << ")" << std::endl;
}

// senior subclass
Senior::Senior(const std::string& name, int id) : UndergraduateStudent(name, id) {}

void Senior::displayInfo() const {
    std::cout << "Senior Student: " << studentName << " (ID: " << studentId << ")" << std::endl;
}

GraduateStudent::GraduateStudent(const std::string& name, int id) : Student(name, id) {}

void GraduateStudent::displayInfo() const {
    std::cout << "Graduate Student -> Name: " << studentName << ", ID: " << studentId << std::endl;
}

// masters subclass
MastersStudent::MastersStudent(const std::string& name, int id) : GraduateStudent(name, id) {}

void MastersStudent::displayInfo() const {
    std::cout << "Master's Student: " << studentName << " (ID: " << studentId << ")" << std::endl;
}

// doctoral subclass
DoctoralStudent::DoctoralStudent(const std::string& name, int id) : GraduateStudent(name, id) {}

void DoctoralStudent::displayInfo() const {
    std::cout << "Doctoral (PhD) Student: " << studentName << " (ID: " << studentId << ")" << std::endl;
}
