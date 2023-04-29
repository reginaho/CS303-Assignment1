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

void modifyValue(int*& array, int size, string indexInput, std::ofstream& outFile) {
    string userInput;
    int newValue, index;

    try {
        for (int i = 0; i < indexInput.size(); i++) {
            if (!isdigit(indexInput.at(i)))
                throw runtime_error("Invalid index value");
        }

        index = stoi(indexInput);

        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        cout << "Enter the new value: ";
        cin >> userInput;

        for (int i = 0; i < userInput.size(); i++) {
            if (!isdigit(userInput.at(i)))
                throw runtime_error("Invalid value for modification");
        }

        newValue = stoi(userInput);

        int oldValue = array[index];
        array[index] = newValue;
        cout << "The old value at index " << index << " was " << oldValue
            << " and is now " << array[index] << endl;
        cout << endl;
        outputArray(array, size, outFile);
    }
    catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl << endl;
    }
    catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl << endl;
    }
    catch (...) {
        cout << "Unknown error when modifying a value";
        abort();
    }
}

void addValue(int*& array, int size, string newValueInput, std::ofstream& outFile) {
    int newValue;

    try {
        for (int i = 0; i < newValueInput.size(); i++) {
            if (!isdigit(newValueInput.at(i))) {
                throw runtime_error("Invalid value");
            }
        }

        newValue = stoi(newValueInput);

        array[size] = newValue;
        cout << "Value " << newValue << " was added to the end of the array."
            << endl;
        cout << endl;

        size++;

        outputArray(array, size, outFile);
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl << endl;
    }
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

void outputArray(int*& arrayint, int& size, ofstream& outFile) {
    for (int i = 0; i < size; i++) {
        cout << arrayint[i] << " ";
        outFile << arrayint[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
            outFile << endl;
        }
    }
    outFile << endl;
    cout << endl;
    cin.clear();
    cin.ignore(512, '\n');
}