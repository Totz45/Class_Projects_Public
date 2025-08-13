/*
	Title:  ifElseMultiC.cpp
	Author:  April Crockett
	Date:  6-1-2017
	Purpose:  demonstrate multiple if statements.  
	          This program has a logical (run-time error)
			  How should it be fixed?
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	double age;
	double temp;
	
	//get user input
	cout << "\n\nEnter your child\'s age:  ";
	cin >> age;
	cout << "\nEnter your child\'s temperature:  ";
	cin >> temp;
	
	//determine if the child can get vaccinated and the format and print results
	if(temp >= 99)
		cout << "\nChild does not get flu vaccine today.";
	else
	{
		if(age >= 4)
			cout << "\nChild gets flu mist vaccine";
		else if(age >= 2)
			cout << "\nChild gets flu shot vaccine";
		else if(age >= .5)
			cout << "\nChild gets booster flu vaccine.";
		else
			cout << "\nChild does not receive flu vaccine....too young.";	
	}
	
	
	cout << endl << endl;
	
	return 0;
}