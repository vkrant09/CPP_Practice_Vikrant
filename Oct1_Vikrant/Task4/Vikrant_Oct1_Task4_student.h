#ifndef VIKRANT_OCT1_TASK4_STUDENT_H
#define VIKRANT_OCT1_TASK4_STUDENT_H

#include <iostream>
#include <string>

// ---------------- Base Class ----------------
// Generic student class
class Student {
protected:
    std::string name;
    std::string studentID;
    std::string department;
public:
    Student(const std::string& n, const std::string& id, const std::string& dept);
    virtual ~Student() {}

    // Virtual methods for polymorphism
    virtual void displayInfo() const;
    virtual std::string getLevel() const;
};

// ---------------- Undergraduate ----------------
class UndergraduateStudent : public Student {
protected:
    int year;
    int creditsEarned;
public:
    UndergraduateStudent(const std::string& n, const std::string& id,
                         const std::string& dept, int y, int credits);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class Freshman : public UndergraduateStudent {
public:
    Freshman(const std::string& n, const std::string& id,
             const std::string& dept, int y, int credits);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class Sophomore : public UndergraduateStudent {
public:
    Sophomore(const std::string& n, const std::string& id,
              const std::string& dept, int y, int credits);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class Junior : public UndergraduateStudent {
public:
    Junior(const std::string& n, const std::string& id,
           const std::string& dept, int y, int credits);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class Senior : public UndergraduateStudent {
public:
    Senior(const std::string& n, const std::string& id,
           const std::string& dept, int y, int credits);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class HonorsSenior : public Senior {
    std::string thesisTitle;
public:
    HonorsSenior(const std::string& n, const std::string& id,
                 const std::string& dept, int y, int credits,
                 const std::string& thesis);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class ExchangeSenior : public Senior {
    std::string homeUniversity;
public:
    ExchangeSenior(const std::string& n, const std::string& id,
                   const std::string& dept, int y, int credits,
                   const std::string& uni);
    void displayInfo() const override;
    std::string getLevel() const override;
};

// ---------------- Graduate ----------------
class GraduateStudent : public Student {
protected:
    std::string advisor;
public:
    GraduateStudent(const std::string& n, const std::string& id,
                    const std::string& dept, const std::string& adv);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class MastersStudent : public GraduateStudent {
public:
    MastersStudent(const std::string& n, const std::string& id,
                   const std::string& dept, const std::string& adv);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class ThesisMastersStudent : public MastersStudent {
    std::string thesisTitle;
public:
    ThesisMastersStudent(const std::string& n, const std::string& id,
                         const std::string& dept, const std::string& adv,
                         const std::string& thesis);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class NonThesisMastersStudent : public MastersStudent {
    std::string projectTitle;
public:
    NonThesisMastersStudent(const std::string& n, const std::string& id,
                            const std::string& dept, const std::string& adv,
                            const std::string& project);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class DoctoralStudent : public GraduateStudent {
protected:
    std::string dissertationTitle;
    int yearsInProgram;
public:
    DoctoralStudent(const std::string& n, const std::string& id,
                    const std::string& dept, const std::string& adv,
                    const std::string& diss, int years);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class PhDCandidate : public DoctoralStudent {
public:
    PhDCandidate(const std::string& n, const std::string& id,
                 const std::string& dept, const std::string& adv,
                 const std::string& diss, int years);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class PostDocFellow : public GraduateStudent {
    std::string researchGrant;
public:
    PostDocFellow(const std::string& n, const std::string& id,
                  const std::string& dept, const std::string& adv,
                  const std::string& grant);
    void displayInfo() const override;
    std::string getLevel() const override;
};

#endif
