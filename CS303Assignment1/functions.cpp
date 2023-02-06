#include "functions.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

char options() {
    cout << "CHOICES\n";
    cout << "A - Search for a value\n";
    cout << "B - Modify an index\n";
    cout << "C - Add a value to the end of the array\n";
    cout << "D - Remove an index\n";
    cout << "Q - Quit\n";
    cout << "Enter your choice: ";
    cout << endl;

    char choice;
    string choiceOptions = "ABCDEQ";

    while (true) {
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            continue;
        }
        try {
            if (choiceOptions.find(toupper(choice)) == string::npos)
                throw(runtime_error("Invalid input.Please try again\n"));

        }
        catch (runtime_error(except)) {
            cout << except.what() << endl;
            continue;
        }

        cin.ignore(256, '\n');
        return toupper(choice);
    }
}

void modifyValue(int*& array, int size, int index, int newValue) {
    if (index < 0 || index >= size) {
        cout << "Index out of range" << endl;
        return;
    }

    int oldValue = array[index];
    array[index] = newValue;
    cout << "The old value at index " << index << " was " << oldValue
        << " and is now " << array[index] << endl;
    cout << endl;
}

void addValue(int*& array, int size, int newValue) {
    array[size] = newValue;
    cout << "Value " << newValue << " was added to the end of the array." << endl;
    cout << endl;
}

int findIndex(const int*& array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

void replaceValue(int*& array, int& size, int index) {
    if (index < 0 || index >= size) {
        return;
    }
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
}
