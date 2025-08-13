/*****************************************************
	Title:  	basicPointer_2.cpp
	Author:  	April Crockett
	Date:  		8/15/2017
	Purpose:  	demonstrate the address operator, 
					defining a pointer, assignment 
					with a pointer, and the 
					indirection operator.
*****************************************************/

#include <iostream>
using namespace std;

int main()
{
	int x = 25;
	int *ptr = NULL;

	ptr = &x;

	cout << "The address of x is " << &x << endl; //using address operator
	cout << "The size of x is " << sizeof(x) << " bytes\n";
	cout << "The value in x is " << x << endl;
	cout << "The value in x is " << *ptr << endl; //using indirection operator
	cout << "The address of x is " << ptr << endl;

	return 0;
}