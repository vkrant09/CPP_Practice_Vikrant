#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

enum class FlightStatus {
    PARKED,
    TAXIING,
    WAITING_TAKEOFF,
    TAKING_OFF,
    CLIMBING,
    CRUISING,
    CHANGING_ALTITUDE,
    DESCENDING,
    LANDING
};

class Flight {
private:
    std::string airline;
    std::string flightNumber;
    std::string makeModel;
    std::string origin;
    std::string destination;
    int currentAltitude;
    int newAltitude;
    int currentSpeed;
    std::string direction;
    std::string departureTime;
    std::string arrivalTime;
    FlightStatus status;

public:
    Flight(const std::string& air, const std::string& num, const std::string& model,
           const std::string& from, const std::string& to, const std::string& dep, const std::string& arr);

    void changeAltitude(int altitude);
    void reduceSpeed(int speed);
    void beginLandingApproach();
    std::string toString() const;
};

#endif
