/*
	Title:   stringCompB.cpp
	Author:  Gaddis, modified by Crockett
	Date:    6-1-2017
	Purpose: This program uses relational operators to compare strings to order them alphabetically
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string nameOne, nameTwo, nameThree;

	//get user input
	cout << "\n\nEnter the first name:  ";
	getline(cin, nameOne);
	cout << "\nEnter the second name:  ";
	getline(cin, nameTwo);
	cout << "\nEnter the third name:  ";
	getline(cin, nameThree);

	// Print them in alphabetical order
	cout << endl << endl;
	if(nameOne <= nameTwo && nameOne <= nameThree)
	{
		if(nameTwo <= nameThree)
			cout << nameOne << ", " << nameTwo << ", " << nameThree;
		else
			cout << nameOne << ", " << nameThree << ", " << nameTwo;
	}
	else if(nameTwo <= nameOne && nameTwo <= nameThree)
	{
		if(nameOne <= nameThree)
			cout << nameTwo << ", " << nameOne << ", " << nameThree;
		else
			cout << nameTwo << ", " << nameThree << ", " << nameOne;
	}
	else if(nameThree <= nameOne && nameThree <= nameTwo)
	{
		if(nameOne <= nameTwo)
			cout << nameThree << ", " << nameOne << ", " << nameTwo;
		else
			cout << nameThree << ", " << nameTwo << ", " << nameOne;
	}

	cout << endl << endl;
	
	return 0;
}