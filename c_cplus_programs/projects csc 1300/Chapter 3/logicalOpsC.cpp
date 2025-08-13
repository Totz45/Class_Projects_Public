/*
	Title:    logicalOpsC.cpp
	Author:   April Crockett
	Date:     6-1-2017
	Purpose:  This program demonstrates checking numeric ranges with logical operators
*/

#include <iostream>
using namespace std;

int main()
{
	// variable definitions
	int age;
	float salary;
	float gpa;
	
	//get user input & validate
	cout << "\n\nWhat is your age (0 - 120):  ";
	cin >> age;
	if(age < 0 || age > 120)
	{
		cout << "\nInvalid age.  Please enter your age (0 - 120):  ";
		cin >> age;
	}
	
	cout << "\nWhat is your salary:  $";
	cin >> salary;
	if(salary < 0)
	{	
		cout << "\nInvalid salary.  Please enter a positive number:  $";
		cin >> salary;
	}
	
	cout << "\nWhat is your GPA:  ";
	cin >> gpa;
	if(gpa < 0.0 || gpa > 4.0)
	{
		cout << "\nInvalid GPA - must be between 0.0 and 4.0.\n  What is your GPA:  ";
		cin >> gpa;
	}
	
	//output results
	cout << "\nAGE:  " << age;
	cout << "\nSALARY:  $" << salary;
	cout << "\nGPA:  " << gpa << endl << endl;

	return 0;
}