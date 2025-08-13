/*
	Title:  runningTotalExample_1.cpp
	Author:  April Crockett
	Date:  7/25/2017
	Purpose:  simple running total example
*/
#include <iostream>
using namespace std;

int main()
{
	/*
		The variable total is called the accumulator.
		The accumulator is usually called "total" or "sum"
		The accumulator is ALWAYS initialized to zero!!!!
	*/
	int total = 0; 
	int numDogs = 5;
	
	cout << "\n\nThe accumulator always begins with " << total << endl << endl;
	
	for(int x=0; x<10; x++)
	{
		total += numDogs;
		cout << "\nThe accumulator, total, is now updated to " << total;
	}
	
	cout << "\n\nThe total number of dogs is " << total << endl << endl;
	
	return 0;
}
