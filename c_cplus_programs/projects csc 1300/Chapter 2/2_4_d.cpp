/*
	Title:   2_4_d.cpp
	Author:  April Crockett
	Date:    5-30-2017
	Purpose: Example to demonstrate order of evaluation
*/
#include <iostream>
using namespace std;

int main()
{
	int result;
	
	result = 5 + 2 * 4;
	cout << "\n\nThe result of 5 + 2 * 4 is " << result << endl;
	
	result = (5 + 2) * 4;
	cout << "\n\nThe result of (5 + 2) * 4 is " << result << endl;
	
	result = 10 / 5 - 3;
	cout << "\n\nThe result of 10 / 2 - 3 is " << result << endl;
	
	result = 10 / (5 - 3);
	cout << "\n\nThe result of 10 / (5 - 3) is " << result << endl;
	
	result = 6 - 3 * 2 + 7 - 1 + 17 % 2;
	cout << "\n\nThe result of 6 - 3 * 2 + 7 - 1 + 17 % 2 is " << result << endl;
	
	result = (6 - 3) * 2 + (7 - 1) + 17 % 2;
	cout << "\n\nThe result of (6 - 3) * 2 + (7 - 1) + 17 % 2 is " << result << endl;

	return 0;
}