#pragma once

class ParkingSlot {
    private:
    int id;
    bool isOccupied;

    public:
    static int numberOfSlots;

    ParkingSlot();

    int getId();
    bool isFree();

    void setFree();
    bool bookSlot();
};