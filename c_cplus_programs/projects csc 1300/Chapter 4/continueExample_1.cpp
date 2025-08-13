/*
	Title:  continueExample_1.cpp
	Author:  April Crockett
	Date:  7/24/2017
	Purpose:  demonstrate using continue in a loop
*/
#include <iostream>
using namespace std;

int main()
{
	cout << "\n\nHello - I am before the loop!\n\n";
	
	for(int x=0; x<20; x++)
	{
		cout << "I am at iteration " << (x+1) << " with counter (x) at " << x << endl;
		if(x == 10)
			continue;
		cout << "\nHI\n";
	}
	
	return 0;
}



