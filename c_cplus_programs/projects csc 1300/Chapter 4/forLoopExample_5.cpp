/*
	Title: 		forLoopExample_5.cpp
	Author: 	April R. Crockett
	Date:  		February 12, 2009
	Purpose:	C++ program to help teachers grade exams 
				(and to demonstrate a for loop).
*/

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	float average;

	for (int questionsMissed = 1; questionsMissed<=50; questionsMissed++)
	{
		cout << setw(3) << questionsMissed << ": ";
		average = static_cast<float>(50 - questionsMissed) / 50.0 * 100;
		cout << setprecision(1) << fixed << average <<"%\n";
	}
			
    return 0;	
}



		