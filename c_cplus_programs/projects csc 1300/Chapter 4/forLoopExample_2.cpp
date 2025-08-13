/*
	Title: 		forLoopExample_2.cpp
	Author: 	Gaddis, modified by Crockett
	Date:  		February 12, 2009
	Purpose:	This program demonstrates a user controlled for loop.
*/
#include <iostream>
using namespace std;

int main()
{
	int minNumber, maxNumber;

	// Get the minimum and maximum values to display.
	cout << "\n\nI will display a table of numbers and their squares.\n";
	
	cout << "Enter the starting number: ";
	cin >> minNumber;

	cout << "Enter the ending number: ";
	cin >> maxNumber;
	
	while(maxNumber < minNumber)
	{
		cout << "\n\nPROBLEM!\n";
		cout << "Enter the starting number: ";
		cin >> minNumber;

		cout << "Enter the ending number: ";
		cin >> maxNumber;	
	}

	// Display the table.
	cout << "Number Number Squared\n"
	<< "-------------------------\n";

	for (int num = minNumber; num <= maxNumber; num++)
		cout << num << "\t\t" << (num * num) << endl;
	

	return 0;
} 
















