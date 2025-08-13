/*
	Title:   2_4_c.cpp
	Author:  April Crockett
	Date:    10-30-2017
	Purpose: Example to demonstrate using the modulus. 
*/
#include <iostream>
using namespace std;

int main()
{
	int testNum;
	int result;
	
	cout << "\n\nPlease enter a number:  ";
	cin >> testNum;
	
	result = testNum % 2;
	
	cout << "\n\nIf the result is 0 then the number you entered is an even number.\n";
	cout << "Otherwise, it is an odd number.\n\n";
	cout << "RESULT:  " << result << endl << endl;
	
	return 0;
}