/*****************************************************
	Title:  	arrayPointer_5.cpp
	Author:  	April Crockett
	Date:  		8/15/2017
	Purpose:  	This program uses a pointer to 
				display the contents of an array.
*****************************************************/

#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 4;
	int set[SIZE] = {5, 10, 15, 20};
	int *numPtr;   // Pointer
	int count;     // Counter variable for loops

	// Make numPtr point to the set array.
	numPtr = set;

	// Use the pointer to display the array contents.
	cout << "The numbers in set are:\n";
	for (count = 0; count < SIZE; count++)
	{
		cout << *numPtr << " ";
		numPtr++;
	}

	// Display the array contents in reverse order.
	cout << "\nThe numbers in set backward are:\n";
	for (count = 0; count < SIZE; count++)
	{
		numPtr--;
		cout << *numPtr << " ";
	}
	
	cout << endl;
	
	return 0;
}


