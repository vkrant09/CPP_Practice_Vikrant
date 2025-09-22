#include <iostream>
#include <string>

class HeartRates {
private:
    std::string firstName;
    std::string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;

public:
    // constructor
    HeartRates(const std::string& f, const std::string& l,
               int m, int d, int y)
        : firstName(f), lastName(l), birthMonth(m), birthDay(d), birthYear(y) {}

    // setters
    void setFirstName(const std::string& f) { firstName = f; }
    void setLastName(const std::string& l) { lastName = l; }
    void setBirthMonth(int m) { birthMonth = m; }
    void setBirthDay(int d) { birthDay = d; }
    void setBirthYear(int y) { birthYear = y; }

    // getters
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    int getBirthMonth() const { return birthMonth; }
    int getBirthDay() const { return birthDay; }
    int getBirthYear() const { return birthYear; }

    // calculate age by asking current date
    int getAge() const {
        int cMonth, cDay, cYear;
        std::cout << "Enter current month day and year: ";
        std::cin >> cMonth >> cDay >> cYear;

        int age = cYear - birthYear;
        if (cMonth < birthMonth || (cMonth == birthMonth && cDay < birthDay)) {
            age--; // not had birthday yet this year
        }
        return age;
    }

    // max heart rate = 220 - age
    int getMaximumHeartRate(int age) const {
        return 220 - age;
    }

    // target heart rate = 50% to 85% of max
    void getTargetHeartRate(int age, int& lower, int& upper) const {
        int max = getMaximumHeartRate(age);
        lower = static_cast<int>(max * 0.50);
        upper = static_cast<int>(max * 0.85);
    }
};

int main() {
    // ask user info
    std::string first, last;
    int m, d, y;

    std::cout << "Enter first name: ";
    std::cin >> first;
    std::cout << "Enter last name: ";
    std::cin >> last;
    std::cout << "Enter birth month day year: ";
    std::cin >> m >> d >> y;

    // create object
    HeartRates person(first, last, m, d, y);

    // show info
    std::cout << "\nName: " << person.getFirstName() << " " << person.getLastName() << "\n";
    std::cout << "Date of Birth: " << person.getBirthMonth() << "/"
              << person.getBirthDay() << "/" << person.getBirthYear() << "\n";

    int age = person.getAge();
    std::cout << "Age: " << age << " years\n";

    int maxHR = person.getMaximumHeartRate(age);
    std::cout << "Maximum Heart Rate: " << maxHR << " bpm\n";

    int low, high;
    person.getTargetHeartRate(age, low, high);
    std::cout << "Target Heart Rate Range: " << low << " - " << high << " bpm\n";

    return 0;
}
