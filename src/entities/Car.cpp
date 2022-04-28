#include "include/Car.hpp"
#include <string>

using namespace std;

Car::Car() {}

Car::Car(string registrationNumber, string color) {
    this->registrationNumber = registrationNumber;
    this->color = color;
}

const string Car::getRegistrationNumber() {
    return this->registrationNumber;
}

const string Car::getColor() {
    return this->color;
}

void Car::setRegistrationNumber(string registrationNumber) {
    this->registrationNumber = registrationNumber;
}

void Car::setColor(string color) {
    this->color = color;
}

