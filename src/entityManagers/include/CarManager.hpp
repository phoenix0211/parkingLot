#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include "../../entities/include/Car.hpp"

using namespace std;

class CarManager {
    private:
    unordered_map<string, Car> cars;

    public:
    CarManager();

    bool createCar(string registrationNumber, string color);
    bool removeCar(string registrationNumber);

    vector<string> getRegistrationNumbersOfCarsByColor(string color);
};
