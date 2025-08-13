/*
    File Name: ch8_2.cpp
    Author: Tate Finley
    Date: April 20th, 2022
    Purpose: demonstrate the use of nested structures and array structures

*/
#include <iostream>
#include <iomanip>
using namespace std;

struct CarInfo
{
    string carMake; //brand of the car
    string carModel; //model of the car
    int carYear; //year of the car
};

struct Car
{
    CarInfo carType; //includes all members in structure CarInfo
    string carColor; //color of car
    double carCost; //cost of car
};

int main()
{
    Car carDetail[3]; //contains make, model, year, color, and cost of car.
    int i; //used in for loop

    //acquires data from user about the car
    for(i = 0; i < 3; ++i)
    {
        cout << "\n\nEnter data for car " << i + 1 << endl;
        cout << "What car is it?\t\t";
        getline(cin, carDetail[i].carType.carMake);
        cout << "What model?\t\t";
        getline(cin, carDetail[i].carType.carModel);
        cout << "Year of the car\t\t";
        cin >> carDetail[i].carType.carYear;
        cin.ignore();
        cout << "Color of the car?\t";
        getline(cin, carDetail[i].carColor);
        cout << "How much does it cost?\t$";
        cin >> carDetail[i].carCost;
        cin.ignore();
    }

    //outputs the data for each car in an easy to read format
    for(i = 0; i < 3; ++i)
    {
        cout << "\nYour Car:" << endl;
        cout << "Make:\t";
        cout << carDetail[i].carType.carMake << endl;
        cout << "Model:\t";
        cout << carDetail[i].carType.carModel << endl;
        cout << "Year:\t";
        cout << carDetail[i].carType.carYear << endl;
        cout << "Color:\t";
        cout << carDetail[i].carColor << endl;
        cout << "Cost:\t$";
        cout << fixed << showpoint << setprecision(2);
        cout << carDetail[i].carCost << endl;
    }


    return 0;
}

