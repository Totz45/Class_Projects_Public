/**********************************************************
	Title: 		pointerFunction_2.cpp
	Author:  	Gaddis, modified by April Crockett
	Date:  		8/15/2017
	Purpose:   	This program demonstrates that a pointer 
				may be used as a parameter to accept the 
				address of an array. 
**********************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getSales(double *, int);
double totalSales(double *, int);

int main()
{
	const int QTRS = 4;
	double sales[QTRS];

	// Get the sales data for all quarters.
	getSales(sales, QTRS);

	// Set the numeric output formatting.
	cout << fixed << showpoint << setprecision(2);

	// Display the total sales for the year.
	cout << "The total sales for the year are $";
	cout << totalSales(sales, QTRS) << endl;
	
	return 0;
}

void getSales(double *arr, int size)
{
	for (int count = 0; count < size; count++)
	{
		cout << "Enter the sales figure for quarter ";
		cout << (count + 1) << ": ";
		cin >> *(arr+count);  //read in value & place in array
	}
}

double totalSales(double *arr, int size)
{
	double sum = 0.0; //accumulator

	for (int count = 0; count < size; count++)
	{
		sum += *(arr+count); //add current array element to sum
	}
	return sum;
}










