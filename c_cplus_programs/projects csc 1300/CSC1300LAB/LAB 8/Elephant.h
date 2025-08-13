/*
    File Name: Elephant.h
    Author: Tate Finley
    Date: March 23, 2022
    Purpose: This header file contains all of the code nessesary to execute
             the other two .cpp files.
*/

#ifndef ELEPHANT_H
#define ELEPHANT_H

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 10;

void getElephantData(float[SIZE], string[SIZE]);
void getStats(float[SIZE], string[SIZE], float&, float&, int& );

#endif