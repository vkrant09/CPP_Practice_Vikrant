#include <iostream>
#include <string>
#include <vector>

class ServiceRecord {
private:
    std::string date;
    int mileage;
    std::string desc;
public:
    ServiceRecord(std::string d = "", int m = 0, std::string s = "") {
        if (m < 0) throw std::invalid_argument("Mileage must be >= 0");
        date = d; mileage = m; desc = s;
    }
    std::string getDate() const { return date; }
    int getMileage() const { return mileage; }
    std::string getDesc() const { return desc; }
    void print() const {
        std::cout << date << " " << mileage << " " << desc << "\n";
    }
};

class Car {
private:
    std::string vin, make, model;
    double price;
    std::vector<ServiceRecord> services;
    std::vector<int> damages;
    static int total;
public:
    Car(std::string v = "", std::string mk = "", std::string md = "", double p = 0.0)
        : vin(v), make(mk), model(md), price(p) {
        if (p < 0) throw std::invalid_argument("Price must be >= 0");
        total++;
    }
    // copy constructor
    Car(const Car& other)
        : vin(other.vin), make(other.make), model(other.model),
          price(other.price), services(other.services), damages(other.damages) {
        total++;
    }
    // destructor
    ~Car() { total--; }

    // setters
    void setVIN(const std::string& v) { vin = v; }
    void setMake(const std::string& m) { make = m; }
    void setModel(const std::string& m) { model = m; }
    void setPrice(double p) { if (p < 0) throw std::invalid_argument("Price >= 0"); price = p; }

    // getters
    std::string getVIN() const { return vin; }
    std::string getMake() const { return make; }
    std::string getModel() const { return model; }
    double getPrice() const { return price; }
    int getServiceCount() const { return (int)services.size(); }
    int getDamageCount() const { return (int)damages.size(); }
    const std::vector<int>& getDamages() const { return damages; }

    // adders
    void addService(const ServiceRecord& s) { services.push_back(s); }
    void addDamage(int code) { damages.push_back(code); }

    void printInfo() const {
        std::cout << vin << " " << make << " " << model << " $" << price
                  << " services:" << services.size()
                  << " damages:" << damages.size() << "\n";
    }

    static int getTotalCars() { return total; }
};
int Car::total = 0;

// global functions
double avgPrice(Car arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i].getPrice();
    return n ? sum / n : 0;
}
bool compareAsc(const Car& a, const Car& b) { return a.getPrice() < b.getPrice(); }
bool compareDesc(const Car& a, const Car& b) { return a.getPrice() > b.getPrice(); }
bool areEqual(const Car& a, const Car& b) { return a.getVIN() == b.getVIN(); }
const Car* maxPriceCar(Car arr[], int n) {
    if (n == 0) return nullptr;
    const Car* mx = &arr[0];
    for (int i = 1; i < n; i++) if (arr[i].getPrice() > mx->getPrice()) mx = &arr[i];
    return mx;
}
const Car* findCarByVIN(Car arr[], int n, const std::string& vin) {
    for (int i = 0; i < n; i++) if (arr[i].getVIN() == vin) return &arr[i];
    return nullptr;
}
int countCarsWithDamage(Car arr[], int n, int code) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int d : arr[i].getDamages())
            if (d == code) { cnt++; break; }
    }
    return cnt;
}
void swapCars(Car& a, Car& b) {
    Car temp = a;
    a = b;
    b = temp;
}

// main demo
int main() {
    std::cout << "Total cars: " << Car::getTotalCars() << "\n";

    Car c1("1HGCM", "Honda", "Accord", 20000);
    c1.addService(ServiceRecord("2022-03-15", 15000, "Oil change"));
    c1.addDamage(101); c1.addDamage(205);
    c1.printInfo();

    // copy constructor demo
    Car c2 = c1;
    c2.setVIN("NEWVIN");
    c2.printInfo();

    std::cout << "Total cars: " << Car::getTotalCars() << "\n";

    Car garage[3] = {
        Car("A1", "BMW", "3", 34999),
        Car("B2", "Tesla", "Model3", 39999),
        Car("C3", "Ford", "Mustang", 31200)
    };

    garage[0].addDamage(101);
    garage[1].addDamage(205);
    garage[2].addDamage(101);

    for (int i = 0; i < 3; i++) garage[i].printInfo();

    std::cout << "Avg price: " << avgPrice(garage, 3) << "\n";

    const Car* mx = maxPriceCar(garage, 3);
    if (mx) std::cout << "Max price car VIN: " << mx->getVIN() << "\n";

    const Car* found = findCarByVIN(garage, 3, "B2");
    if (found) std::cout << "Found car VIN: " << found->getVIN() << "\n";

    std::cout << "Cars with damage code 101: " << countCarsWithDamage(garage, 3, 101) << "\n";

    swapCars(garage[0], garage[2]);
    std::cout << "After swap:\n";
    for (int i = 0; i < 3; i++) garage[i].printInfo();

    std::cout << "Total cars: " << Car::getTotalCars() << "\n";
}
