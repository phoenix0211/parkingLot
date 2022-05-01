#include "include/CarManager.hpp"

using namespace std;

CarManager::CarManager() {}

bool CarManager::createCar(string registrationNumber, string color) {
    //TODO: check if car already exists
    Car car(registrationNumber, color);
    cars.insert({registrationNumber, car});
    return true;
}

bool CarManager::removeCar(string registrationNumber) {
    //TODO: check if car exists or not
    cars.erase(registrationNumber);
    return true;
}

vector<string> CarManager::getRegistrationNumbersOfCarsByColor(string color) {
    vector<string> registrationNumbers;
    for(auto it = cars.begin(); it != cars.end(); ++it) {
        if(it->second.getColor() == color) {
            registrationNumbers.push_back(it->first);
        }
    }
    return registrationNumbers;
}

Car CarManager::getCar(string registrationNumber) {
    return cars[registrationNumber];
}