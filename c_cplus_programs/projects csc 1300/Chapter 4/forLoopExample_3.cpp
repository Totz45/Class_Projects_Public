/*
	Title: 		forLoopExample_3.cpp
	Author: 	Gaddis, modified by Crockett
	Date:  		February 12, 2009
	Purpose:	This program converts the speeds 60 kph through
				130 kph (in 10 kph increments) to mph.
*/
#include <iostream>
using namespace std;

int main()
{
	// Constants for the speeds
	const int START_KPH = 60;  // Starting speed
	const int END_KPH = 130;   // Ending speed
	const int INCREMENT = 10;  // Speed increment

	// Constant for the conversion factor
	const double CONVERSION_FACTOR = 0.6214;

	// Other Variables
	int kph;       // To hold speeds in kph
	double mph;    // To hold speeds in mph


	cout << "\n\nKPH\tMPH\n";
	cout << "---------------\n";

	// Display the speeds.
	for (kph = START_KPH; kph <= END_KPH; kph += INCREMENT) //notice the update statement doesn't just add ONE
	{
		// Calculate mph
		mph = kph * CONVERSION_FACTOR;

		// Display the speeds in kph and mph.
		cout << kph << "\t" << mph << endl;
	}
	
	return 0;
} 