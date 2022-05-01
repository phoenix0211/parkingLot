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

};