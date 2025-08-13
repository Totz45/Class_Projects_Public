/*
	Title:    ifStatementC.cpp
	Author:   Gaddis, modified by Crockett
	Date:     6-1-2017
	Purpose:  This program demonstrates an if statement with a logical issue
*/
#include <iostream>
using namespace std;

int main()
{
	int a, b;  

	cout << "\n\nEnter two integers, separated by a space:  ";
	cin >> a >> b;
	
	if (a == b)
		cout << "Both a and b are the same.\n";


	return 0;
}



