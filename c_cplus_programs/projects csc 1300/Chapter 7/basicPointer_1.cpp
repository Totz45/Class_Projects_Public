/*****************************************************
	Title:  	basicPointer_1.cpp
	Author:  	April Crockett
	Date:  		8/15/2017
	Purpose:  	demonstrate the address operator, 
					defining a pointer, and 
					assignment with a pointer.
*****************************************************/
#include <iostream>
using namespace std;

int main()
{
	int x = 25;
	int *ptr = NULL; //C++11 use nullptr to initialize a pointer
	
	cout << "The address in ptr before x " << ptr << endl;
	ptr = &x;

	cout << "The address of x is " << &x << endl;
	cout << "The size of x is " << sizeof(x) << " bytes\n";
	cout << "The value in x is " << x << endl;
	cout << "The address of x is " << ptr << endl;

	return 0;
}














