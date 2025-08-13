/*
    File Name: tafinley43_prog4.h
    Author: Tate Finley
    Date: April 24th, 2022
    Purpose: Header File for program. Includes structure definitions, function prototypes, and libraries.
*/
#ifndef TAFINLEY_PROG4_H
#define TAFINLEY_PROG4_H


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

struct Rent
{
    float heroCost; //rent cost for hero
    float heroDamage;//damage cost for hero
    float rentYears;//amount of years in condo
};

struct Heroes
{
    string heroName;//name of hero
    string heroDescription;//hero descriptio
    bool heroDanger;//is the hero dangerous
    Rent rentTotal;//variable of structure Rent
};

int enterHeroes(int, int, Heroes[]);
int deleteHeroes(int, Heroes[]);
bool moveArrayElement(int, string, Heroes[]);
void printHeroes(int, Heroes[]);
void printRentDetails(int, Heroes[]);
void saveToFile(int, Heroes[]);

#endif