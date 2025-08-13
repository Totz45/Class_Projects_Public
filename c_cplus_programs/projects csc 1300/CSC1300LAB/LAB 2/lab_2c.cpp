/* 
    File Name: lab_2c.cpp
    Author: Tate Finley
    Date: February 2nd, 2022
    Purpose: This program will read in a city's name and average the
             temperature in that city over a period of three days.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cityName; //so the user can insert their city
    int temperature1; //temperature for first day
    int temperature2; //temperature for second day
    int temperature3; //temperature for third day
    float temperatureAverage; //average temperature of the three days

    //user gets to input their city
    cout << "\nEnter the city's name:  ";
    getline (cin, cityName);

    //user inputs temperature on first day (Monday)
    cout << "Enter the temperature on Monday at " << cityName;
    cout << ":  ";
    cin >> temperature1;

    //user inputs temperature on second day (Tuesday)
    cout << "Enter the temperature on Tuesday at " << cityName;
    cout << ":  ";
    cin >> temperature2;

    //user inputs temperature on third day (Wednesday)
    cout << "Enter the temperature on Wednesday at " << cityName;
    cout << ":  ";
    cin >> temperature3;
    cout << endl;

    //Calculation for average temperature
    temperatureAverage = (temperature1 + temperature2 + temperature3) / 3.0;

    //Output of average temperature from calculation
    cout << cityName << " has a temperature average of ";
    cout << temperatureAverage << endl;

    return 0;
}