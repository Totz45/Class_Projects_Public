/* 
    File Name: lab_2d.cpp
    Author: Tate Finley
    Date: February 2nd, 2022
    Purpose: This program will find out how many total days of quarantining 
             would be required if a number of employees tested positive for 
             Covid 19 as well as in years.
*/
#include <iostream>
using namespace std;

int main()
{
    int positiveEmployee; //number of employees that tested positive
    const int quarantineEmployee = 21; //number of days an employee is quarantined
    int quarantineDay; //total number of days quarantined
    float quarantineYear; //total number of years quarantined

    //indicates number of employees that caught covid 19
    cout << "\nHow many employees tested positive for Covid-19?  ";
    cin >> positiveEmployee;
    cout << "\n";

    //calculation for total days and total years quarantined
    quarantineDay = positiveEmployee * quarantineEmployee;
    quarantineYear = quarantineDay / 365.0;

    //output for calculation in statement
    cout << "The employees went on quarantine for " << quarantineDay;
    cout << " days, which is " << quarantineYear << " years.\n";

    return 0;
}