/**********************************************************
	Title:  	dynamicMemoryAlloc_2.cpp
	Author:  	Gaddis, modified by April Crockett
	Date:  		8/15/2017
	Purpose:  	This program demonstrates a function that 
				returns a pointer to a dynamically 
				allocated array.
**********************************************************/

#include <iostream>
#include <cstdlib>   // For rand and srand
#include <ctime>     // For the time function
using namespace std;

// Function prototype
int* getRandomNumbers(int);

int main()
{
	int *numbers;  // To point to the numbers
	// Get an array of five random numbers.
	numbers = getRandomNumbers(5);

	// Display the numbers.
	for (int count = 0; count < 5; count++)
		cout << *(numbers+count) << endl;

	// Free the memory.
	delete [] numbers;
	
	return 0;
}

//**************************************************
// The getRandomNumbers function returns a pointer *
// to an array of random integers. The parameter   *
// indicates the number of numbers requested.      *
//**************************************************

int *getRandomNumbers(int num)
{
	int *arr;    // Array to hold the numbers

	if (num <= 0)
		return NULL;

	arr = new int[num];

	srand( time(0) );

	//place a random number in each element of the array
	for (int count = 0; count < num; count++)
		*(arr+count) = rand();

	return arr;
}