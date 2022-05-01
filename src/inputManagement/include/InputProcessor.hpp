#pragma once
#include <vector>
#include "ParkingLotManager.hpp"

using namespace std;

class InputProcessor {
    private:
    ParkingLotManager* manager;
    string filename;

    public:
    InputProcessor();
    InputProcessor(string filename);
    ~InputProcessor();

    void processInteractiveInput();
    void processFileInput();

    vector<string> processCommand(string command);
    void executeCommand(vector<string>& commandSegments);
    void processAndExecuteCommand(string comamnd);

    bool executeCreateParkingLot(vector<string>& commandSegments);
    bool executePark(vector<string>& commandSegments);
    bool executeStatus(vector<string>& commandSegments);
    bool executeLeave(vector<string>& commandSegments);
    bool executeRegistrationNumberForCarsWithColor(vector<string>& commandSegments);
    bool executeSlotNumberForRegistrationNumber(vector<string>& commandSegments);
    bool executeSlotNumberForCarsWithColor(vector<string>& commandSegments);


};