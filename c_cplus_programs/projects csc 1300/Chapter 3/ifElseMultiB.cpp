/*
	Title:  ifElseMultiB.cpp
	Author:  April Crockett
	Date:  6-1-2017
	Purpose:  demonstrate multiple if else branches with nested if-else statements.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int age;
	string name;
	string state;
	
	//get user input
	cout << "\n\nEnter your state:  ";
	getline(cin, state);
	cout << "\nEnter your name:  ";
	getline(cin, name);
	cout << "\nEnter your age:  ";
	cin >> age;
	
	//determine the state and print results
	if(state == "Mississippi")
	{
		if(age < 21)
			cout << endl << name << ", you are too young to get married in " << state << ".";
		else
			cout << endl << name << ", you are old enough get married in " << state << ".";	
	}
	else if (state == "Nebraska")
	{
		if(age < 19)
			cout << endl << name << ", you are too young to get married in " << state << ".";
		else
			cout << endl << name << ", you are old enough get married in " << state << ".";	
	}
	else if (state == "West Virginia")
	{
		if(age < 3)
			cout << endl << name << ", you are too young to get married in " << state << ".";
		else
			cout << endl << name << ", you are old enough get married in " << state << ".";	
	}
	else
	{
		if(age < 18)
			cout << endl << name << ", you are too young to get married in " << state << ".";
		else
			cout << endl << name << ", you are old enough get married in " << state << ".";	
	}
	
	cout << endl << endl;
	return 0;
}