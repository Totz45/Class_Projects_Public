/*
	Title:   2_5_c.cpp
	Author:  Gaddis, modified by Crockett
	Date:    10-30-2017
	Purpose: This program calculates the circumference of a circle.
*/
#include <iostream>
using namespace std;

int main()
{
	// Constants
	const double PI = 3.14159;
	const double DIAMETER = 10.0;

	// Variable to hold the circumference
	double circumference;

	// Calculate the circumference.
	circumference = PI * DIAMETER;

	// Display the circumference.
	cout << "\n\nThe circumference is: " << circumference << endl << endl;
	
	return 0;
}