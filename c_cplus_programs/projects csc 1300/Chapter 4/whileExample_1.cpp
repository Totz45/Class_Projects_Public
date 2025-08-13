/*
	Title:		whileExample_1.cpp
	Author:		April Crockett
	Date:		6/9/2017
	Purpose:	simple while loop example
*/
#include <iostream>
using namespace std;

int main()
{
	int x = 3;
	int counter = 1;
	
	cout << "\n\nBEFORE THE LOOP\n\n";
	
	while(x <= 10)
	{
		cout << "This is iteration " << counter << " of this loop.\n";
		x = x + 1;
		counter = counter + 1;
	}
	
	cout << "\nAFTER THE LOOP\n\n";
	
	return 0;
}