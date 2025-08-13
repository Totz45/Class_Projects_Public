/*
    File Name: lab3a.cpp
    Author: Tate Finley
    Date: February 9th, 2022
    Purpose: To calculate the cost of night stays at the resort.
             It uses setw() and setfill() text manipulators to 
             acheive its goal.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    string name; //input user name
    const float nightCost = 199.99; //cost for 1 night
    float discountCost; //cost after discounts
    float totalCost; //cost calculated by nightStay * discountPrice
    int nightStay; //stores how long you stay
    int numPeople; //indicates number of people

    //fixed decimal placement
    cout << fixed << setprecision(2);

    //user is prompted to insert their name
    cout << "Welcome to Happy Summer Resort!\n\n";
    cout << "What is your name?  ";
    getline(cin, name);

    //user is prompted to input how many nights
    cout << "\nThe night cost is $199.99.\n\n";
    cout << "How many nights you want to stay?  ";
    cin >> nightStay;

    //states group discounts in a table like format
    cout << "We offer group discounts as follows:";
    cout << "\n\n\t" << setw(25) << left << "Number of people";
    cout << setw(15) << left << "Discount";
    cout << "\n\t" << setw(25) << left << "5-10";
    cout << setw(15) << left << "10%";
    cout << "\n\t" << setw(25) << left << "11-20";
    cout << setw(15) << left << "15%";
    cout << "\n\t" << setw(25) << left << "21-30";
    cout << setw(15) << left << "20%";
    cout << "\n\t" << setw(25) << left << "31 or more";
    cout << setw(15) << left << "25%";

    //user inputs the number of people
    cout << "\n\n\n" << name;
    cout << ", how many people are in your group?  ";
    cin >> numPeople;

    //check validity
    if (numPeople <= 0) 
    {
        cout << "Invalid input:  Please run the program again ";
        cout << "and enter a non-negative integer";
    } 
    //check discounts
    else if (numPeople >= 5 && numPeople <= 10)
    {
        discountCost = nightCost * 0.90;
    } else if (numPeople >= 11 && numPeople <= 20)
    {
        discountCost = nightCost * 0.85;
    } else if (numPeople >= 21 && numPeople <= 30)
    {
        discountCost = nightCost * 0.80;
    } else if (numPeople > 30)
    {
        discountCost = nightCost * 0.75;
    } else 
    {
        discountCost = nightCost;
    }

    //calculated cost of stay
    totalCost = nightStay * discountCost;

    //total bill indicating end of program
    cout << "\n\n" << setfill('-') << setw(40) << "" << endl;
    cout << setfill(' ') << setw(25) << left << "BILL FOR:";
    cout << name << endl;
    cout << setw(25) << left << "DISCOUNTED COST:";
    cout << "$" << discountCost << " (per night)" << endl;
    cout << setw(25) << left << "TOTAL COST:  $";
    cout << " " << totalCost << endl;
    return 0;
}