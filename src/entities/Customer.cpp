#include "include/Customer.hpp"

int Customer::id = 1001;

Customer::Customer() {
    customerId = id++;
    ticketId = -1;
}

Customer::Customer(string registrationNumber) {
    customerId = id++;
    carRegistrationNumber = registrationNumber;
    ticketId = -1;
}

int Customer::getCustomerId() {
    return customerId;
}

string Customer::getCarRegistrationNumber() {
    return carRegistrationNumber;
}

void Customer::setCarRegistrationNumber(string registrationNumber) {
    carRegistrationNumber = registrationNumber;
}

void Customer::getTicket(int ticketId) {
    this->ticketId = ticketId;
}

int Customer::returnTicket() {
    int temp = ticketId;
    ticketId = -1;
    return temp;
}