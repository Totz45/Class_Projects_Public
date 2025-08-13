/*
	Title: debugExample.cpp
	Author:  April Crockett
	Date:  5-31-2017
	Purpose: Example in debugging techniques.
             This program DOES contain errors!
*/
#include <iostream>

using namespace std;

int main()
{
	//variable definitions
	double tempF, tempC;
	
	//get user input
	cout << "\n\nWhat is the temperature in degrees Celsius?\n";
	cin >> tempC;
	
	//calculation
	tempF = tempC * (9.0 / 5.0) + 32;
	
	//print results
	cout << tempC << " degrees Celsius is " << tempF << " degrees Fahrenheit.\n\n";
	
	return 0;
}