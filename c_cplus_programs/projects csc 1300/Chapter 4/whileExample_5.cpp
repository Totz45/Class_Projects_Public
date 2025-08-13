/*
	Title:  	whileExample_5.cpp
	Author:		Gaddis, modified by Crockett
	Date:  		6/9/2017
	Purpose:	This program displays a list of numbers and
				their squares.
*/
#include <iostream>
using namespace std;

int main()
{
	int num = 1; // Counter

	cout << "Number Number Squared\n";
	cout << "-------------------------\n";
	while (num <= 10)
		cout << num << "\t\t" << (num * num) << endl;
		num++;
	return 0;
}












