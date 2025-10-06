#ifndef VIKRANT_OCT6_TASK5_PACKAGE_H
#define VIKRANT_OCT6_TASK5_PACKAGE_H

#include <string>

// Base class representing a generic package
class Package {
protected:
    // sender info
    std::string senderName;
    std::string senderAddress;
    std::string senderCity;
    std::string senderState;
    std::string senderZip;

    // receiver info
    std::string recipientName;
    std::string recipientAddress;
    std::string recipientCity;
    std::string recipientState;
    std::string recipientZip;

    // package details
    double weight;        // in ounces
    double costPerOunce;  // cost per ounce

public:
    // constructor to set all details
    Package(const std::string& sName, const std::string& sAddr, const std::string& sCity,
            const std::string& sState, const std::string& sZip,
            const std::string& rName, const std::string& rAddr, const std::string& rCity,
            const std::string& rState, const std::string& rZip,
            double w, double cost);

    virtual ~Package();

    // this function calculates normal cost = weight * cost per ounce
    virtual double calculateCost() const;

    // display info
    virtual void displayInfo() const;
};

// Derived class for two-day delivery
class TwoDayPackage : public Package {
private:
    double flatFee; // extra flat charge for 2-day delivery

public:
    TwoDayPackage(const std::string& sName, const std::string& sAddr, const std::string& sCity,
                  const std::string& sState, const std::string& sZip,
                  const std::string& rName, const std::string& rAddr, const std::string& rCity,
                  const std::string& rState, const std::string& rZip,
                  double w, double cost, double fee);

    double calculateCost() const override; // redefined to add flat fee
    void displayInfo() const override;
};

// Derived class for overnight delivery
class OvernightPackage : public Package {
private:
    double extraFeePerOunce; // additional fee per ounce for overnight service

public:
    OvernightPackage(const std::string& sName, const std::string& sAddr, const std::string& sCity,
                     const std::string& sState, const std::string& sZip,
                     const std::string& rName, const std::string& rAddr, const std::string& rCity,
                     const std::string& rState, const std::string& rZip,
                     double w, double cost, double extraFee);

    double calculateCost() const override; // redefined to include extra per ounce cost
    void displayInfo() const override;
};

#endif
