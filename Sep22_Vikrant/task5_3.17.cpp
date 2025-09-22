#include <iostream>
#include <string>

class HealthProfile {
private:
    std::string firstName;
    std::string lastName;
    std::string gender;
    int birthMonth;
    int birthDay;
    int birthYear;
    int heightInInches;
    int weightInPounds;

public:
    // constructor
    HealthProfile(const std::string& f, const std::string& l, const std::string& g,
                  int m, int d, int y, int h, int w)
        : firstName(f), lastName(l), gender(g),
          birthMonth(m), birthDay(d), birthYear(y),
          heightInInches(h), weightInPounds(w) {}

    // setters
    void setFirstName(const std::string& f) { firstName = f; }
    void setLastName(const std::string& l) { lastName = l; }
    void setGender(const std::string& g) { gender = g; }
    void setBirthMonth(int m) { birthMonth = m; }
    void setBirthDay(int d) { birthDay = d; }
    void setBirthYear(int y) { birthYear = y; }
    void setHeight(int h) { heightInInches = h; }
    void setWeight(int w) { weightInPounds = w; }

    // getters
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getGender() const { return gender; }
    int getBirthMonth() const { return birthMonth; }
    int getBirthDay() const { return birthDay; }
    int getBirthYear() const { return birthYear; }
    int getHeight() const { return heightInInches; }
    int getWeight() const { return weightInPounds; }

    // calculate age
    int getAge() const {
        int cMonth, cDay, cYear;
        std::cout << "Enter current month day and year: ";
        std::cin >> cMonth >> cDay >> cYear;

        int age = cYear - birthYear;
        if (cMonth < birthMonth || (cMonth == birthMonth && cDay < birthDay)) {
            age--;
        }
        return age;
    }

    // max heart rate
    int getMaximumHeartRate(int age) const {
        return 220 - age;
    }

    // target heart rate range
    void getTargetHeartRate(int age, int& lower, int& upper) const {
        int max = getMaximumHeartRate(age);
        lower = static_cast<int>(max * 0.50);
        upper = static_cast<int>(max * 0.85);
    }

    // body mass index
    double getBMI() const {
        return (703.0 * weightInPounds) / (heightInInches * heightInInches);
    }

    // print BMI chart
    void printBMIChart() const {
        std::cout << "\nBMI VALUES\n"
                  << "Underweight: less than 18.5\n"
                  << "Normal:      between 18.5 and 24.9\n"
                  << "Overweight:  between 25 and 29.9\n"
                  << "Obese:       30 or greater\n";
    }
};

int main() {
    // input details
    std::string first, last, gender;
    int m, d, y, height, weight;

    std::cout << "Enter first name: ";
    std::cin >> first;
    std::cout << "Enter last name: ";
    std::cin >> last;
    std::cout << "Enter gender: ";
    std::cin >> gender;
    std::cout << "Enter birth month day year: ";
    std::cin >> m >> d >> y;
    std::cout << "Enter height (in inches): ";
    std::cin >> height;
    std::cout << "Enter weight (in pounds): ";
    std::cin >> weight;

    HealthProfile person(first, last, gender, m, d, y, height, weight);

    // show details
    std::cout << "\nName: " << person.getFirstName() << " " << person.getLastName() << "\n";
    std::cout << "Gender: " << person.getGender() << "\n";
    std::cout << "Date of Birth: " << person.getBirthMonth() << "/"
              << person.getBirthDay() << "/" << person.getBirthYear() << "\n";
    std::cout << "Height: " << person.getHeight() << " in\n";
    std::cout << "Weight: " << person.getWeight() << " lbs\n";

    // calculations
    int age = person.getAge();
    std::cout << "Age: " << age << " years\n";

    int maxHR = person.getMaximumHeartRate(age);
    std::cout << "Maximum Heart Rate: " << maxHR << " bpm\n";

    int low, high;
    person.getTargetHeartRate(age, low, high);
    std::cout << "Target Heart Rate Range: " << low << " - " << high << " bpm\n";

    double bmi = person.getBMI();
    std::cout << "BMI: " << bmi << "\n";

    person.printBMIChart();

    return 0;
}
