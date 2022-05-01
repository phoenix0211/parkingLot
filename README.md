# PARKING LOT

## Steps to build
Open the terminal, and run the following command in the base directory:
```
make
```
This will compile the code and add the parking_lot build in the bin directory

## Steps to run the build
You have two mode to run the build  
Please ensure that you have built the code before executing this

1. To run the code in interactive mode, just execute the following command in terminal
```
./bin/parking_lot
```
2. To run the code through inputs from a file, just add the filename, ex. file_inputs.txt, to the previous command
```
./bin/parking_lot file_inputs.txt
```

## Commands supported by the program (both Interactive and File mode)
Here is the list of commands supported by the program in both modes
* **create_parking_lot**  
Purpose: To create a parking lot with n slots  
Format:
```
create_parking_lot <n>
```
* **park**  
Purpose: To park a car with a registration number and a color  
Format:
```
park <registration_number> <color>
```
* **status**  
Purpose: To show the SlotID, Registration Number and Color of parked vehicles    
Format:
```
status
```
* **leave**  
Purpose: To record and complete the exit of a car parked on a given slotId   
Format:
```
leave <slotId>
```
* **registration_numbers_for_cars_with_colour**  
Purpose: To fetch the registration numbers of parked cars with the given color   
Format:
```
registration_numbers_for_cars_with_colour <color>
```
* **slot_number_for_registration_number**  
Purpose: To fetch the slot number for the registration number of a parked car, if it exists  
Format:
```
slot_number_for_registration_number <registration_number>
```
* **slot_numbers_for_cars_with_colour**  
Purpose: To fetch of parked cars with the given color  
Format:
```
slot_numbers_for_cars_with_colour <color>
```
* **exit**  
Purpose: To exit the program  
Format:
```
exit
```
