#pragma once
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

void modifyValue(int*& array, int size, string indexInput, std::ofstream& outFile);
void addValue(int*& array, int size, string newValueInput, std::ofstream& outFile);
int findIndex(int*& array, int size, int value);
void replaceValue(int*& array, int& size, int index);
char options();
void outputArray(int*& arrayint, int& size, std::ofstream& outFile);