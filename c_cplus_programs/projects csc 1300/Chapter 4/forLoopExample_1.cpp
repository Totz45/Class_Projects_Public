/*
	Title: 		forLoopExample_.cpp
	Author: 	Gaddis, modified by Crockett
	Date:  		February 12, 2009
	Purpose:	This program displays the numbers 1 through 10 and
				their squares.
*/
#include <iostream>
using namespace std;

int main()
{
	cout << "\n\nNumber Number Squared\n";
	cout << "-------------------------\n";

	for (int num = 1; num <= 10; num++)
		cout << num << "\t\t" << (num * num) << endl;

	return 0;
}