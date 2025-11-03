```c++
//Name: Atletl Gomez Vargas
//Course: CISC 192 - C++ Programming
//Date: Nov, 2, 2025
//Assignment: Non-Duplicated Integer Array Operations

#include <iostream>
#include <array>

int findMax(int arr[], int size) {
    int highestValue = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > highestValue) {
            highestValue = arr[i];
        }
    }
    return highestValue;
};

void ascending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        //rotation shrinks as the first loop increases
        for (int j = 0; j < ((size - i) - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                int heldValue = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = heldValue;
            }
        }
    }

    std::cout << "ascending order: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }

}

void descending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        //rotation shrinks as the first loop increases
        for (int j = 0; j < ((size - i) - 1); j++) {
            //flipped sign to descend
            if (arr[j] < arr[j + 1]) {
                int heldValue = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = heldValue;
            }
        }
    }

    std::cout << "descending order: " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }

}


int main() {

    std::array<int, 5> userNums;
    bool duplicate = false;
    bool operationChosen = false;
    int userChoice = 0;
    int result = 0;
    
    std::cout << "Enter 5 unique intergers: " << std::endl;

// loops 5 times to get user input
        for (int i = 0; i < 5; i++) {

            std::cout << "Number " << i+1 << ": " << std::endl;
            std::cin >> userNums[i];

            //checks for duplicates
            for (int j = 0; j < i; j++) {
                
                if(userNums[i] == userNums[j]) {
                    std::cout << "Duplicate found. Please enter a UNIQUE number!" << std::endl;
                    duplicate = true;
                }
    
                //while loop if there is a duplicate
                while (duplicate) {
                    std::cout << "Number " << i+1 << ": " << std::endl;
                    std::cin >> userNums[i];
                    if(userNums[i] != userNums[j]) {
                    duplicate = false;
                    }
                }
            }
        }


        std::cout << "You entered: ";
        for (int i = 0; i < 5; i++) {
            std::cout << userNums[i] << " ";
        }
        std::cout << '\n';


        while (!operationChosen) {
            std::cout << "Choose an operation:" << std::endl;
            std::cout << "1. sort ascending" << std::endl;
            std::cout << "2. sort descending" << std::endl;
            std::cout << "3. find max" << std::endl;
            std::cin >> userChoice;

            switch (userChoice) {

                case 1: {
                    ascending(userNums.data(), userNums.size());
                    operationChosen = true;
                    break;
                }
                case 2: {
                    descending(userNums.data(), userNums.size());
                    operationChosen = true;
                    break;
                }
                case 3: {
                    result = findMax(userNums.data(), userNums.size());
                    std::cout << "The max value is: " << result << std::endl;
                    operationChosen = true;
                    break;
                }
                default: {
                    std::cout << "choose a number offered" << std::endl;
                    break;
                }

            }
        }

           return 0;
    }
