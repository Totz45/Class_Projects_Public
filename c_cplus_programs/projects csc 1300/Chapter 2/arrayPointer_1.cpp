/*****************************************************
	Title:  	arrayPointer_1.cpp
	Author:  	April Crockett
	Date:  		8/15/2017
	Purpose:  	show an array being dereferenced 
				with the indirection operator
*****************************************************/

#include <iostream>
using namespace std;

int main()
{
	short numbers[] = {10, 20, 30, 40, 50};

	cout << "The first element of the array is ";
	cout << *numbers << endl;

	return 0;
}