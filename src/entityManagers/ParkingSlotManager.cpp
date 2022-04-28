#include "include/ParkingSlotManager.hpp"

ParkingSlotManager::ParkingSlotManager(int n): slots(n) {
    currentSlot = 0;
    numberOfParkedCars = 0;
}

bool ParkingSlotManager::isEmpty() {
    return numberOfParkedCars == 0;
}

bool ParkingSlotManager::isFull() {
    return numberOfParkedCars == (int)slots.size();
}

void ParkingSlotManager::updateCurrentSlot() {
    if(isFull()) {
        return;
    }
    int freeSlot = (currentSlot + 1) % slots.size();
    while(freeSlot != currentSlot) {
        if(slots[freeSlot].isFree()) {
            break;
        }
        freeSlot = (freeSlot + 1) % slots.size();
    }
    currentSlot = freeSlot;
}

int ParkingSlotManager::park() {
    if(isFull()) {
        return -1;
    }

    bool isBookingSuccessful = slots[currentSlot].bookSlot();

    if(!isBookingSuccessful) {
        return -1;
    }

    int slotId = slots[currentSlot].getId();
    ++numberOfParkedCars;
    updateCurrentSlot();
    return slotId;
}

bool ParkingSlotManager::unpark(int slotId) {
    if(isEmpty()) {
        return false;
    }
    if(slots[slotId].isFree()) {
        return false;
    }
    slots[slotId].setFree();
    --numberOfParkedCars;
    currentSlot = slots[currentSlot].isFree() && currentSlot < slotId ? currentSlot : slotId;
    return true;
}

