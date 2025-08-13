/*
	Title:    logicalOpsB.cpp
	Author:   Gaddis, modified by Crockett
	Date:     6-1-2017
	Purpose:  This program demonstrates the logical ! operator.
*/

#include <iostream>
using namespace std;

int main()
{
	// variable definitions
	const double MIN_INCOME = 35000.0;
	const int MIN_YEARS = 5;
	double income;  // Annual income
	int years;      // Years at the current job

	// Get the user's input
	cout << "What is your annual income? ";
	cin >> income;
	cout << "How many years have you worked at your current job? ";
	cin >> years;

	// Determine the user's loan qualifications.
	if (!(income >= MIN_INCOME || years >  MIN_YEARS))
	{
		cout << "You must earn at least $"
		<< MIN_INCOME << " or have been "
		<< "employed more than " << MIN_YEARS 
		<< "years.\n";
	}
	else
		cout << "You qualify.\n";

	return 0;
}