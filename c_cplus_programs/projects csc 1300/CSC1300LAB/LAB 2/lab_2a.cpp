/* 
    File Name: lab_2a.cpp
    Author: Tate Finley
    Date: February 2nd, 2022
    Purpose: This program is written for waiters & waitresses at
			 Donuts shop so that they can calculate total cost
			 of donuts for their customers.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float numDonuts; //The number of donuts purchased
    const float costDonuts = 0.99; //Cost per donut
    const float salesTax = 0.085; //Sales tax represented in decimal form
	float totalCost; //Total cost of the purchase

	/* 	the line below will allow floating point amounts to display
		two numbers after the decimal point.  (it will make amounts pretty) */
	cout <<	setprecision(2) << fixed << showpoint; 
	cout << "\nPlease input the number of dounts purchased:  ";
	
	//	User input for the quantity of dounts.
	cin >> numDonuts;
	
	//	Calculation for the total bill.
	totalCost = (costDonuts * numDonuts) + (costDonuts * numDonuts * salesTax);
	
	//	Prints the total bill as shown in the calculation.
	cout << "Your total bill is $" << totalCost << endl;
	
	return 0; 
}