#ifndef HYBRIDVEHICLE_H
#define HYBRIDVEHICLE_H

#include <string>
#include <iostream>

class HybridVehicle {
private:
    std::string modelName;
    float electricKm;
    float gasolineKm;
    float gasolineUsed;
    int trips[10];   // fixed size array for max 10 trips
    int tripCount;   // how many trips are stored

public:
    // Constructor
    HybridVehicle(const std::string& name = "Unknown",
                  float eKm = 0.0F,
                  float gKm = 0.0F,
                  float gUsed = 0.0F);

    // Copy assignment (deep copy)
    HybridVehicle& operator=(const HybridVehicle& other);

    // Overloaded operators
    HybridVehicle operator+(const HybridVehicle& other) const;
    bool operator==(const HybridVehicle& other) const;
    HybridVehicle& operator++(); // prefix ++
    int& operator[](int index);  // subscript
    float operator()() const;    // total distance
    explicit operator float() const; // convert to efficiency

    // Friend function for output
    friend std::ostream& operator<<(std::ostream& os, const HybridVehicle& hv);
};

#endif
