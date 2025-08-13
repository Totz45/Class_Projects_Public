/*
	Title: ifElseMultiA.cpp
	Author:  Gaddis, modified by Crockett
	Date:  6-1-17
	Purpose:  This program uses an if/else if statement to 
	          assign a letter grade (A, B, C, D, or F) to 
			  a numeric test score.
*/
#include <iostream>
using namespace std;
		  
int main()
{
	float testScore;

	// Get the numeric test score.
	cout << "Enter your numeric test score and I will\n"
	<< "tell you the letter grade you earned: ";
	cin >> testScore;

	// Determine the letter grade.
	if (testScore >= 90)
	{
		cout << "Your grade is A.\n";
		cout << "You are awesome!\n";
	}
	else if (testScore >= 80)
		cout << "Your grade is B.\n";
	else if (testScore >= 70)
	{
		cout << "Your grade is C.\n";
		cout << "You are just plain.\n";
	}
	else if (testScore >= 60)
		cout << "Your grade is D.\n";
	else
	{
		cout << "Your grade is F.\n";
		cout << "You really need help.\n";
	}

	cout << "\n\nThe end!\n\n";
	
	return 0;
}