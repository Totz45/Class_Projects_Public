/*
	Title: 		forLoopExample_6.cpp
	Author: 	April R. Crockett
	Date:  		February 12, 2009
	Purpose:  	C++ program to help teachers grade exams 
				(and to demonstrate a for loop).
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int questionsMissed; 
 	int totalQuestions;
	float average;

  	cout << "\nPlease enter the total number of questions on the exam." << endl;
   	cin >> totalQuestions;

  	if (totalQuestions > 0)
  	{
      	for (questionsMissed = 1; questionsMissed <= totalQuestions; questionsMissed++)
		{        	    
			cout << setw(3) <<  questionsMissed << ": ";
			average = (float)(totalQuestions - questionsMissed) / totalQuestions * 100;
			cout << setprecision(1) << fixed << average <<"%\n";
		}
			
	}
	else 
		cout << "Invalid input - total number of questions must be positive" << endl;

	return 0;
}




		