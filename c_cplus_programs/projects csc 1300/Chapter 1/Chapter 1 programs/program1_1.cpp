/********************************************************************
 *   File Name: program1_1.cpp									    *
 *   Author: Gaddis and Krupnow; modified by April Crockett         *
 *   Date:     2007                                                 *
 *   Purpose: this program calculates employee pay based on hourly  *
 *            pay rate and hours worked.                            *
 ********************************************************************/
#include <iostream>
using namespace std;

int main ()
{
	double hours;
	double rate;
	double pay;
	int employeeCount = 0;
	bool goAgain = true;
	char response;

	cout << endl << endl;
	while (goAgain == true)
	{
		// INPUT
		cout << "Enter hours worked for this pay period: ";
		cin  >> hours;
		cout << "Enter hourly pay rate for this pay period: ";
		cin  >> rate;

		// PROCESSING - Calculate pay, based upon input values.
		pay = hours * rate;

		// OUTPUT
		cout << "Your pay this period is $" << pay << endl;
		cout << endl << endl;

		employeeCount++;
		cout << "Go Again? y/n & <enter>: ";
		cin  >> response;
		cout << endl;
		if (response == 'n' || response == 'N') 
			goAgain = false;
	}
	cout << "Count of employees for this run was: " << employeeCount << endl << endl; 

	return 0;  // this indicates that a normal exit from the program
}
