/*
	Titel:  2_2_b.cpp
	Author:  April Crockett
	Date:  5-30-2017
	Purpose: Example to show assignments and expressions
*/
#include <iostream>
using namespace std;

int main()
{
	int length, width, area;
	
	width = 7;  //assignment - storing or assigning the number 7 to the variable named width
	
	cout << "\n\nWhat is the length of the rectangle?  ";
	cin >> length;
	
	area = length * width;  //length * width is an expression.  Then the result of this expression is stored or assigned to area
	
	cout << "\nThe area of the rectangle is " << area << endl << endl;
	

	return 0;
}