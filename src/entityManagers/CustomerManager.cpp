#include "include/CustomerManager.hpp"

CustomerManager::CustomerManager() {}

int CustomerManager::createCustomer(string registrationNumber) {
    Customer customer(registrationNumber);
    int customerId = customer.getCustomerId();
    customers.insert({customerId, customer});
    //TODO: check if customer exists or not
    return customerId;
}

bool CustomerManager::removeCustomer(int customerId) {
    // TODO: check if this customer exists or nott
    customers.erase(customerId);
    return true;
}

void CustomerManager::assignTicketToCustomer(int customerId, int ticketId) {
    customers[customerId].getTicket(ticketId);
}

int CustomerManager::takeTicketFromCustomer(int customerId) {
    return customers[customerId].returnTicket();
}

Customer CustomerManager::getCustomer(int customerId) {
    return customers[customerId];
}

Customer CustomerManager::getCustomerByCarRegistrationNumber(string registrationNumber) {
    for(auto it = customers.begin(); it != customers.end(); ++it) {
        if(it->second.getCarRegistrationNumber() == registrationNumber) {
            return it->second;
        }
    }
    Customer dummyCustomer("NotFound");
    return dummyCustomer;
}