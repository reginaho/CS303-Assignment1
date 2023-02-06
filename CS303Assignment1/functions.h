
#pragma once
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

void modifyValue(int*& array, int size, int index, int newValue);
void addValue(int*& array, int size, int newValue);
int findIndex(const int*& array, int size, int value);
void replaceValue(int*& array, int& size, int index);
char options();