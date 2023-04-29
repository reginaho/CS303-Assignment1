#include "functions.h"
using namespace std;

#include <fstream>

int main() {

    int* array = new int[150];
    int arraySize = 0;
    ifstream file("input.txt");
    if (file.fail()) {
        cout << "Input file opening failed" << endl;
        exit(1);
    }

    ofstream outFile("output1.txt");
    if (outFile.fail()) {
        cout << "Output file opening failed" << endl;
        exit(1);
    }

    int value;
    while (file >> value) {
        array[arraySize++] = value;
    }

    char choice;
    do {

        choice = options();
        if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' &&
            choice != 'Q') {
            cout << "Invalid option, please enter a valid option." << endl;
            continue;
        }
        switch (choice) {
            // Search for a value

        case 'A': {
            int searchValue;
            cout << "Enter a value to search for: ";
            cin >> searchValue;
            int index = -1;
            for (int i = 0; i < arraySize; i++) {
                if (array[i] == searchValue) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                cout << "Value not found." << endl;
            }
            else {
                cout << "Value found at index " << index << endl;
            }
            outputArray(array, arraySize, outFile);
            break;
        }
                // Modify the index
        case 'B': {
            string modifyIndex;
            cout << "Enter the index to modify: ";
            cin >> modifyIndex;
            modifyValue(array, arraySize, modifyIndex, outFile);
            break;
        }
                // A value to add to the end of the array
        case 'C': {
            string newValue;
            cout << "Enter a value to add to the end of the array: ";
            cin >> newValue;
            addValue(array, arraySize, newValue, outFile);
            break;
        }
                // Remove a value at index
        case 'D': {
            int removeIndex;
            cout << "Enter the index to remove: ";
            cin >> removeIndex;
            replaceValue(array, arraySize, removeIndex);
            outputArray(array, arraySize, outFile);
            break;
        }
        case 'Q': {
            cout << "Have a good day" << endl;
        }
        }

    } while (choice != 'Q');

    // Quit the program
    file.close();
    outFile.close();
    return 0;
}