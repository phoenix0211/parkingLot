#include "include/ParkingSlot.hpp"

int ParkingSlot::numberOfSlots = 0;

ParkingSlot::ParkingSlot() {
    numberOfSlots++;
    this->id = numberOfSlots;
    this->isOccupied = false;
}

int ParkingSlot::getId() {
    return this->id;
}

bool ParkingSlot::isFree() {
    return !isOccupied;
}

void ParkingSlot::setFree() {
    isOccupied = false;
}

bool ParkingSlot::bookSlot() {
    if(isOccupied) return false;
    isOccupied = true;
    return true;
}