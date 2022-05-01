#pragma once
#include <unordered_map>
#include "../../entities/include/Customer.hpp"

using namespace std;

class CustomerManager {
    private:
    unordered_map<int, Customer> customers;

    public:
    CustomerManager();

    int createCustomer(string registrationNumber);
    bool removeCustomer(int customerId);

    void assignTicketToCustomer(int customerId, int ticketId);
    int takeTicketFromCustomer(int customerId);

    Customer getCustomer(int customerId);
    Customer getCustomerByCarRegistrationNumber(string registrationNumber);
};