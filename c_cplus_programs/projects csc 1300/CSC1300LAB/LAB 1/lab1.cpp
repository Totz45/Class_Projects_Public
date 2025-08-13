/*
    File Name: lab1.cpp
    Author: Tate Finley
    Date: January 26th, 2022
    Purpose: This program converts kilometers per hour (km/h) to miles per hour (mph).
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double kiloPerHour; //variable for kilometers per hour
    double milePerHour; //variable for miles per hour
    
    cout << "What is the speed in km/h?  "; //first statement
    cin >> kiloPerHour; //user inputs for km/h

    milePerHour = kiloPerHour / 1.609344; //equation converting km/h to mph
    
    cout << "\nRESULT:  "; //prints next statement on newline
    cout << kiloPerHour << " km/h speed is "; //statement with user input
    cout << fixed << setprecision(6) << milePerHour; //statement with precise output to 6 decimal places
    cout << " mph." << endl; //end of statement
    return 0;
}