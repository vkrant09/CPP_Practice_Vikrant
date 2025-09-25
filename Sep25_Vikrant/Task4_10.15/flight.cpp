#include "flight.h"
#include <iostream>

Flight::Flight(const std::string& air, const std::string& num, const std::string& model,
               const std::string& from, const std::string& to, const std::string& dep, const std::string& arr)
    : airline(air), flightNumber(num), makeModel(model), origin(from), destination(to),
      departureTime(dep), arrivalTime(arr), currentAltitude(0), newAltitude(0),
      currentSpeed(0), direction("N/A"), status(FlightStatus::PARKED) {}

void Flight::changeAltitude(int altitude) {
    std::cout << airline << " " << flightNumber
              << " changing altitude from " << currentAltitude
              << " to " << altitude << " feet.\n";
    newAltitude = altitude;
    status = FlightStatus::CHANGING_ALTITUDE;
    currentAltitude = altitude; // assume instant change for simplicity
}

void Flight::reduceSpeed(int speed) {
    std::cout << airline << " " << flightNumber
              << " reducing speed from " << currentSpeed
              << " to " << speed << " knots.\n";
    currentSpeed = speed;
}

void Flight::beginLandingApproach() {
    std::cout << airline << " " << flightNumber
              << " beginning landing approach.\n";
    status = FlightStatus::LANDING;
}

std::string Flight::toString() const {
    std::string statusStr;
    switch (status) {
        case FlightStatus::PARKED: statusStr = "Parked"; break;
        case FlightStatus::TAXIING: statusStr = "Taxiing"; break;
        case FlightStatus::WAITING_TAKEOFF: statusStr = "Waiting for Takeoff"; break;
        case FlightStatus::TAKING_OFF: statusStr = "Taking Off"; break;
        case FlightStatus::CLIMBING: statusStr = "Climbing"; break;
        case FlightStatus::CRUISING: statusStr = "Cruising"; break;
        case FlightStatus::CHANGING_ALTITUDE: statusStr = "Changing Altitude"; break;
        case FlightStatus::DESCENDING: statusStr = "Descending"; break;
        case FlightStatus::LANDING: statusStr = "Landing"; break;
    }

    return airline + " " + flightNumber + " (" + makeModel + ")\n" +
           "From " + origin + " to " + destination + "\n" +
           "Departure: " + departureTime + " Arrival: " + arrivalTime + "\n" +
           "Altitude: " + std::to_string(currentAltitude) + " ft\n" +
           "Speed: " + std::to_string(currentSpeed) + " knots\n" +
           "Status: " + statusStr + "\n";
}
