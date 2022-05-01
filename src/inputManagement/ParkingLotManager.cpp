#include "include/ParkingLotManager.hpp"

ParkingLotManager::ParkingLotManager() {
    carManager = nullptr;
    customerManager = nullptr;
    parkingSlotManager = nullptr;
    ticketManager = nullptr;
}

ParkingLotManager::ParkingLotManager(int n) {
    carManager = new CarManager();
    customerManager = new CustomerManager();
    parkingSlotManager = new ParkingSlotManager(n);
    ticketManager = new TicketManager();
}

ParkingLotManager::~ParkingLotManager() {
    delete carManager;
    delete customerManager;
    delete parkingSlotManager;
    delete ticketManager;
}

int ParkingLotManager::attemptParking(string registrationNumber, string color) {
    if(!parkingSlotManager) return -1;

    int slotId = parkingSlotManager->park();
    if(slotId == -1) return -1;

    bool isCarCreationSuccess = carManager->createCar(registrationNumber, color);
    if(!isCarCreationSuccess) {
        parkingSlotManager->unpark(slotId);
        return -1;
    }

    int customerId = customerManager->createCustomer(registrationNumber);
    int ticketId = ticketManager->createTicket(customerId, slotId);
    customerManager->assignTicketToCustomer(customerId, ticketId);
    return slotId;
}

vector<vector<string>> ParkingLotManager::getStatus() {
    vector<vector<string>> status;
    if(!parkingSlotManager) return status;

    vector<string> header{"Slot No.", "Registration No.", "Colour"};
    status.push_back(header);

    vector<Ticket> tickets = ticketManager->getAllTickets();
    for(auto ticket: tickets) {
        vector<string> row;
        row.push_back(to_string(ticket.getSlotId()));
        Car car = carManager->getCar(customerManager->getCustomer(ticket.getCustomerId()).getCarRegistrationNumber());
        row.push_back(car.getRegistrationNumber());
        row.push_back(car.getColor());
        status.push_back(row);
    }
    return status;
}

void ParkingLotManager::freeParking(int slotId) {
    Ticket ticket = ticketManager->getTicket(slotId);
    int customerId = ticket.getCustomerId();
    customerManager->takeTicketFromCustomer(customerId);

    ticketManager->removeTicket(slotId);
    string registrationNumber = customerManager->getCustomer(customerId).getCarRegistrationNumber();
    customerManager->removeCustomer(customerId);
    carManager->removeCar(registrationNumber);
    parkingSlotManager->unpark(slotId);
}

vector<string> ParkingLotManager::getRegistrationNumbersOfCarsByColor(string color) {
    return carManager->getRegistrationNumbersOfCarsByColor(color);
}

int ParkingLotManager::getSlotNumberForRegistrationNumber(string registrationNumber) {
    Customer customer = customerManager->getCustomerByCarRegistrationNumber(registrationNumber);
    if(customer.getCarRegistrationNumber() != registrationNumber) {
        return -1;
    }
    return ticketManager->getTicketByCustomerId(customer.getCustomerId()).getSlotId();
}

