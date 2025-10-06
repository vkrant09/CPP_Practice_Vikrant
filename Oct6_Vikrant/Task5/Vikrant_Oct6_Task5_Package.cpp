#include "Vikrant_Oct6_Task5_Package.h"
#include <iostream>

// ---------------- Base Class ----------------
Package::Package(const std::string& sName, const std::string& sAddr, const std::string& sCity,
                 const std::string& sState, const std::string& sZip,
                 const std::string& rName, const std::string& rAddr, const std::string& rCity,
                 const std::string& rState, const std::string& rZip,
                 double w, double cost)
    : senderName(sName), senderAddress(sAddr), senderCity(sCity), senderState(sState), senderZip(sZip),
      recipientName(rName), recipientAddress(rAddr), recipientCity(rCity), recipientState(rState), recipientZip(rZip),
      weight(w > 0 ? w : 0), costPerOunce(cost > 0 ? cost : 0) {
    // used ternary operator to ensure positive weight and cost
}

Package::~Package() {}

double Package::calculateCost() const {
    return weight * costPerOunce;
}

void Package::displayInfo() const {
    std::cout << "Sender: " << senderName << ", " << senderCity << ", " << senderState << std::endl;
    std::cout << "Recipient: " << recipientName << ", " << recipientCity << ", " << recipientState << std::endl;
    std::cout << "Weight: " << weight << " oz, Cost per ounce: $" << costPerOunce << std::endl;
}

// ---------------- TwoDayPackage ----------------
TwoDayPackage::TwoDayPackage(const std::string& sName, const std::string& sAddr, const std::string& sCity,
                             const std::string& sState, const std::string& sZip,
                             const std::string& rName, const std::string& rAddr, const std::string& rCity,
                             const std::string& rState, const std::string& rZip,
                             double w, double cost, double fee)
    : Package(sName, sAddr, sCity, sState, sZip, rName, rAddr, rCity, rState, rZip, w, cost),
      flatFee(fee > 0 ? fee : 0) {}

double TwoDayPackage::calculateCost() const {
    // base class cost + flat fee
    return Package::calculateCost() + flatFee;
}

void TwoDayPackage::displayInfo() const {
    std::cout << "[Two-Day Package]" << std::endl;
    Package::displayInfo();
    std::cout << "Flat Fee: $" << flatFee << std::endl;
    std::cout << "Total Cost: $" << calculateCost() << std::endl << std::endl;
}

// ---------------- OvernightPackage ----------------
OvernightPackage::OvernightPackage(const std::string& sName, const std::string& sAddr, const std::string& sCity,
                                   const std::string& sState, const std::string& sZip,
                                   const std::string& rName, const std::string& rAddr, const std::string& rCity,
                                   const std::string& rState, const std::string& rZip,
                                   double w, double cost, double extraFee)
    : Package(sName, sAddr, sCity, sState, sZip, rName, rAddr, rCity, rState, rZip, w, cost),
      extraFeePerOunce(extraFee > 0 ? extraFee : 0) {}

double OvernightPackage::calculateCost() const {
    // (cost per ounce + extra fee) * weight
    return weight * (costPerOunce + extraFeePerOunce);
}

void OvernightPackage::displayInfo() const {
    std::cout << "[Overnight Package]" << std::endl;
    Package::displayInfo();
    std::cout << "Extra Fee per Ounce: $" << extraFeePerOunce << std::endl;
    std::cout << "Total Cost: $" << calculateCost() << std::endl << std::endl;
}
