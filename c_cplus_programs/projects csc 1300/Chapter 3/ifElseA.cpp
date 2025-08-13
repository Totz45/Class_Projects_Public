/*
	Title:   ifElseA.cpp
	Author:  Gaddis, modified by Crockett
	Date:    6-1-17
	Purpose: This program uses the modulus operator to determine
             if a number is odd or even. If the number is evenly 
			 divisible by 2, it is an even number. A remainder 
			 indicates it is odd.
*/
#include <iostream>
using namespace std;

int main()
{
	int number;

	//get input from user
	cout << "Enter an integer and I will tell you if it\n";
	cout << "is odd or even. ";
	cin >> number;

	//calculate & print results
	if (number % 2 == 0) {
		cout << number << " is even.\n";
		cout << "I like even numbers\n\n";
	} 
	else
	{
		cout << number << " is odd.\n";
	    cout << "I like odd numbers\n\n";
	}

	return 0;
}