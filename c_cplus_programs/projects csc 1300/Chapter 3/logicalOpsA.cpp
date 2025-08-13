/*
	Title:    logicalOpsA.cpp
	Author:   Gaddis, modified by Crockett
	Date:     6-1-2017
	Purpose:  This program demonstrates the && and || logical operators.
*/
#include <iostream>
using namespace std;

int main()
{
	char employed, recentGrad;

	// Is the user employed and a recent graduate?
	cout << "\n\nAre you employed? (Y/N) ";
	cin >> employed; 
	cout << "\nHave you graduated from college in the past two years? (Y/N) ";
	cin >> recentGrad;

	// Determine the user's loan qualifications.
	if ((employed == 'Y' || employed == 'y') && (recentGrad == 'Y' || recentGrad == 'y'))
		cout << "\nYou qualify for the special interest rate.\n\n";
	else
	{
		cout << "\nYou must be employed and have graduated from college in the ";
		cout << "past two years to qualify.\n\n";
	}
	
	return 0;
} 