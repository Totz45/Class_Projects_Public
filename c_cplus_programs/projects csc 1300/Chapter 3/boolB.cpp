/*
	Title:   boolB.cpp
	Author:  April R. Crockett
	Date:    January 29, 2009
	Purpose: A C++ program to demonstrate if statements
*/

#include <iostream>
using namespace std;

int main()
{

	float average;    // holds the grade average
	bool failFlag; // a flag to signal when student fails the class
	
	failFlag = false;  //initialize failFlag

	cout << "\nInput your average: ";
	cin >> average;

	if (average > 60) 
		cout << "\nYou Pass" << endl;
	else
	{
		cout << "\nYou Fail" << endl;
		failFlag = true;
	}
	
	if (failFlag)  //you could also write this (failFlag == true)
		cout << "Sorry, you will have to take the class again or change your major.\n\n";
	else
		cout << "Congratulations!\n\n";

    return 0;	
}