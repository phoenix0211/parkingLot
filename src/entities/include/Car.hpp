#pragma once
#include <string>

using namespace std;

class Car {
    private:
    string registrationNumber;
    string color;

    public:
    // Default constructor
    Car();

    Car(string registrationNumber, string color);

    const string getRegistrationNumber();
    const string getColor();

    void setRegistrationNumber(string registrationNumber);
    void setColor(string color);
};