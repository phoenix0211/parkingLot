#pragma once
#include <string>
#include "Car.hpp"

class Customer {
    private:
    int customerId;
    string carRegistrationNumber;
    int ticketId;

    public:
    static int id;
    
    Customer();
    Customer(string registrationNumber);

    int getCustomerId();
    string getCarRegistrationNumber();

    void setCarRegistrationNumber(string registrationNumber);

    void getTicket(int ticketId);
    int returnTicket();

};