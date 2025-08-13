/*
	Title:  nestedExample_3.cpp
	Author: April Crockett
	Date:  7/24/2017
	Purpose: This program demonstrates nested loops. 
	It simulates a 24 hour clock.
*/
#include <iostream>

using namespace std;

int main()
{
	cout << fixed << right;
	cout.fill('0');
	
	for (int hours = 0; hours < 24; hours++)
	{
		for (int minutes = 0; minutes < 60; minutes++)
		{
			for (int seconds = 0; seconds < 60; seconds++)
			{
				cout << hours << ":";
				cout << minutes << ":";
				cout << seconds << endl;
			}
		}
	}

	return 0;
}
