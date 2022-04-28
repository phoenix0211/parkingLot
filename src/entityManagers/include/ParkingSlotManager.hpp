#pragma once
#include <vector>
#include "../../entities/include/ParkingSlot.hpp"

using namespace std;

class ParkingSlotManager {
    private:
    vector<ParkingSlot> slots;
    int currentSlot;
    int numberOfParkedCars;

    void updateCurrentSlot();

    public:
    ParkingSlotManager(int n);

    bool isFull();
    bool isEmpty();

    int park();

    bool unpark(int slotId);

};