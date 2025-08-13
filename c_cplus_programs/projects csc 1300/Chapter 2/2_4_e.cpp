/*
	Title:   2_4_e.cpp
	Author:  April Crockett
	Date:    5-30-2017
	Purpose: Example to demonstrate compound assignment
*/
#include <iostream>
using namespace std;

int main()
{
	int result = 75;
	
	cout << "\n\nResult:  " << result << endl;
	
	result += 5;
	cout << "\n\nResult after result += 5 is " << result << endl;
	
	result -= 2;
	cout << "\n\nThe result after result -= 2 is " << result << endl;
	
	result *= 3;
	cout << "\n\nThe result after result *= 3 is " << result << endl;
	
	result /= 4;
	cout << "\n\nThe result after result /= 4 is " << result << endl;
	
	result %= 2;
	cout << "\n\nThe result after result %= 2 is " << result << endl << endl;
	

	return 0;
}