/*
	Title:    floatCompare.cpp
	Author:   Gaddis, modified by Crockett
	Date:     6-1-2017
	Purpose:  This program demonstrates how floating-point 
              round-off errors can make equality operations 
			  unreliable.  
			  (solution is to stick with > or < with doubles)
*/
#include <iostream>
using namespace std;

int main()
{
	double a = 1.5000000000000001;
	double b = 1.5;         
	
	if (a == b) 
	{
		cout << "Both a and b are the same.\n";
	}
	else
		cout << "a and b are not the same.\n";


	return 0;
}



