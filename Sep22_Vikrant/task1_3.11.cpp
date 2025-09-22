#include <iostream>
#include <string>

class GradeBook {
private:
    std::string courseName;
    std::string instructorName;

public:
    // constructor sets both course and instructor name
    GradeBook(const std::string& cName, const std::string& iName) {
        if (cName.empty() || iName.empty()) {
            throw std::invalid_argument("Names cannot be empty.");
        }
        courseName = cName;
        instructorName = iName;
    }

    // set and get for course name
    void setCourseName(const std::string& cName) {
        if (cName.empty()) {
            throw std::invalid_argument("Course name cannot be empty.");
        }
        courseName = cName;
    }
    std::string getCourseName() const {
        return courseName;
    }

    // set and get for instructor name
    void setInstructorName(const std::string& iName) {
        if (iName.empty()) {
            throw std::invalid_argument("Instructor name cannot be empty.");
        }
        instructorName = iName;
    }
    std::string getInstructorName() const {
        return instructorName;
    }

    // prints welcome message with course and instructor
    void displayMessage() const {
        std::cout << "Welcome to the grade book for: " << courseName << "\n";
        std::cout << "This course is presented by: " << instructorName << "\n";
    }
};

int main() {
    try {
        // create object with course + instructor
        GradeBook myCourse("C++ Programming", "Dr. Smith");

        myCourse.displayMessage();

        // change instructor name
        myCourse.setInstructorName("Prof. Johnson");
        std::cout << "\nAfter update:\n";
        myCourse.displayMessage();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
