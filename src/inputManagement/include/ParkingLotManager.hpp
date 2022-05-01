#pragma once

#include "../../entityManagers/include/CarManager.hpp"
#include "../../entityManagers/include/CustomerManager.hpp"
#include "../../entityManagers/include/ParkingSlotManager.hpp"
#include "../../entityManagers/include/TicketManager.hpp"

#include<vector>
#include<string>

using namespace std;

class ParkingLotManager {
    private:
    CarManager* carManager;
    CustomerManager* customerManager;
    ParkingSlotManager* parkingSlotManager;
    TicketManager* ticketManager;

    public:
    ParkingLotManager();

    ParkingLotManager(int n);

    ~ParkingLotManager();

    int attemptParking(string resistrationNumber, string color);
    vector<vector<string>> getStatus();
    void freeParking(int slotId);
    vector<string> getRegistrationNumbersOfCarsByColor(string color);
    int getSlotNumberForRegistrationNumber(string registrationNumber);

};