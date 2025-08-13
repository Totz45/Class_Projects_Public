/*
	Title: 		forLoopExample_7.cpp
	Author: 	April R. Crockett
	Date:  		February 12, 2009
	Purpose:  	C++ program to help teachers grade exams 
				and to demonstrate a for loop).
*/
#include <iostream>
using namespace std;

int main()
{	
	int x = 1, y = 1;
	
	
	for (; y <= 10;)
	{
		cout << "\nThe area of a rectangle with width of " << x 
			<< " and height of " << y << " is "<< (x*y) <<".";
		x++;
		y+=3;
	}
		
	cout << endl;
	
    return 0;	
}
		