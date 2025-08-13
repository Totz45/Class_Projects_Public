/*
	Title:   ifStatementD.cpp
	Author:  Gaddis, modified by Crockett
	Date:    6-1-17
	Purpose: This program averages 3 test scores. The 
	         if statement uses the = operator, but the 
			 == operator was intended.
*/

#include <iostream>
using namespace std;

int main()
{
	int score1, score2, score3;  // To hold three test scores
	double average;              // TO hold the average score

	// Get the three test scores.
	cout << "Enter 3 test scores and I will average them: ";
	cin >> score1 >> score2 >> score3;

	// Calculate and display the average score.
	average = (score1 + score2 + score3) / 3.0;
	cout << "Your average is " << average << endl;

	// Congratulate the user if they scored perfect
	if (average = 100)
	{
		cout << "Congratulations! That's a perfect score!\n";
		cout << "You are super awesome!!\n";
	}	  

	return 0;
}