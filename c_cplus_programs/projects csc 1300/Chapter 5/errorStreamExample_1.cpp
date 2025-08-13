/*
	Title: errorStreamExample_1.cpp
	Author:  zyBooks
	Date:  7/27/2017
	Purpose:  To demonstrate what happens when user enters string instead of integer
*/

#include <iostream>
using namespace std;

int main() 
{
	int num1 = -1; // Initial value -1 for demo purposes.
	int num2 = -1;

	cout << "Enter a number: " << endl;
	cin  >> num1; // User enters "six" - stream error state entered here.
	if(!cin)
	{
		cin.clear();
		cin.ignore(..........max);
		cin >> num1;
	}

	cout << "Enter a second number:" << endl;
	cin  >> num2; // Stream already in error state, so extraction skipped.

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;

	return 0;
}