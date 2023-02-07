#include "functions.h"
using namespace std;

#include <fstream>

int main() {

    // int array[150];
    int* array = new int[150];
    int arraySize = 0;
    ifstream file("input.txt");
    // i literally just found out that there is a chat box here on replit lol
    if (file.fail()) {
        cout << "Input file opening failed" << endl;
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
            for (int i = 0; i < arraySize; i++) {
                cout << array[i] << " ";
            
                if ((i + 1) % 10 == 0) {
                    cout << endl;
                    
                }
            }
            
            cout << endl;
            break;
        }
                // Modify the index
        case 'B': {
            int modifyIndex, ValueToModify;
            cout << "Enter the index to modify: ";
            cin >> modifyIndex;
            if (modifyIndex >= 0 && modifyIndex < arraySize) {
                cout << "Enter the new value: ";
                cin >> ValueToModify;
                array[modifyIndex] = ValueToModify;
            }
            else {
                cout << "Invalid index." << endl;
            }
            for (int i = 0; i < arraySize; i++) {
                cout << array[i] << " ";
                
                if ((i + 1) % 10 == 0) {
                    cout << endl;
                    
                }
            }
           
            cout << endl;
            break;
        }
                // A value to add to the end of the array
        case 'C': {
            int newValue;
            cout << "Enter a value to add to the end of the array: ";
            cin >> newValue;
            addValue(array, arraySize, newValue);
            arraySize++;
            for (int i = 0; i < arraySize; i++) {
                cout << array[i] << " ";
                
                if ((i + 1) % 10 == 0) {
                    cout << endl;
                    
                }
            }
           
            cout << endl;
            cout << endl;
            break;
        }
                // Remove a value at index
        case 'D': {
            int removeIndex;
            cout << "Enter the index to remove: ";
            cin >> removeIndex;
            replaceValue(array, arraySize, removeIndex);
            for (int i = 0; i < arraySize; i++) {
                cout << array[i] << " ";
                
                if ((i + 1) % 10 == 0) {
                    cout << endl;
                   
                }
            }
            
            cout << endl;
            break;
        }
        }
        // Quit the program

    } while (choice != 'Q');

    // Close the files
    file.close();
   
    return 0;
}