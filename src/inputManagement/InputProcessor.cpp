#include "include/InputProcessor.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

InputProcessor::InputProcessor() {
    filename = "";
    manager = nullptr;
}

InputProcessor::InputProcessor(string filename) {
    this->filename = filename;
    manager = nullptr;
}

InputProcessor::~InputProcessor() {
    delete manager;
}

vector<string> InputProcessor::processCommand(string command) {
    vector<string> commandSegments;
    stringstream ss(command);
    string word;
    while(ss >> word) {
        commandSegments.push_back(word);
    }
    ss.clear();
    return commandSegments;
}

void InputProcessor::executeCommand(vector<string>& commandSegments) {
    string command = commandSegments[0];
    if(command == "create_parking_lot") {
        int n = stoi(commandSegments[1]);
        manager = new ParkingLotManager(n);
        cout << "Created a parking lot with " << n << " slots" << endl;
    } else if (command == "park") {
        string registrationNumber = commandSegments[1];
        string color = commandSegments[2];
        int slotNumber = manager->attemptParking(registrationNumber, color);
        if(slotNumber != -1) {
            cout << "Allocated slot number: " << slotNumber << endl;
        } else {
            cout << "Sorry, parking lot is full" << endl;
        }
    } else if (command == "status") {
        vector<vector<string>> status = manager->getStatus();
        for(auto row: status) {
            for(auto col: row) {
                cout << col << "\t";
            }
            cout << endl;
        }
    } else if (command == "leave") {
        int slotId = stoi(commandSegments[1]);
        manager->freeParking(slotId);
        cout << "Slot number " << slotId << " is free" << endl;
    } else if (command == "registration_numbers_for_cars_with_colour") {
        string color = commandSegments[1];
        vector<string> registrationNumbers = manager->getRegistrationNumbersOfCarsByColor(color);
        for(long unsigned int i = 0; i < registrationNumbers.size(); ++i) {
            cout << registrationNumbers[i];
            if(i != registrationNumbers.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    } else if (command == "slot_number_for_registration_number") {
        string registrationNumber = commandSegments[1];
        int slotId = manager->getSlotNumberForRegistrationNumber(registrationNumber);
        if(slotId == -1) {
            cout << "Not found" << endl;
        } else {
            cout << slotId << endl;
        }
    } else if (command == "slot_numbers_for_cars_with_colour") {
        string color = commandSegments[1];
        vector<string> registrationNumbers = manager->getRegistrationNumbersOfCarsByColor(color);
        for(long unsigned int i = 0; i < registrationNumbers.size(); ++i) {
            cout << manager->getSlotNumberForRegistrationNumber(registrationNumbers[i]);
            if(i != registrationNumbers.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    } else {
        cout << "Invalid command, try again!" << endl;
    }
}

void InputProcessor::processInteractiveInput() {
    cout << "Welcome to the Parking Lot. Please enter your commands below" << endl;
    string command;
    getline(cin, command);
    while(command != "exit") {
        vector<string> commandSegments = processCommand(command);
        executeCommand(commandSegments);
        getline(cin, command);
    }
}

void InputProcessor::processFileInput() {
    string line;
    ifstream filestream(filename);
    vector<string> commands;
    if(filestream.is_open()) {
        while(getline(filestream, line)) {
            commands.push_back(line);
        }
        filestream.close();
    } else {
        cout << "Error! File: " << filename << " does not exist!" << endl;
        return;
    }
    cout << "Input (contents of file):" << endl;
    for(string command: commands) {
        cout << command << endl;
    }
    cout << "Output (to STDOUT):" << endl;
    for(string command: commands) {
        vector<string> commandSegments = processCommand(command);
        if(command == "exit") {
            break;
        }
        executeCommand(commandSegments);
    }
    
}