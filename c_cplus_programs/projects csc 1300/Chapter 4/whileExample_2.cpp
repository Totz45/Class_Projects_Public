/*
	Title: whileExample_2.cpp
	Author: April R. Crockett
	Date: February 8, 2009
	Purpose:  A C++ program to demonstrate while loops
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	bool goAgain = true;
	char response;
	int guess = 0;
	int randomNumber = 0;

	while (goAgain)
	{
		cout << "Guess the right number, and you get $1 billion dollars\n";
		cout << "Enter a number between 1 and 100.\n";
		cin >> guess; 
		
		randomNumber = 1 + rand() % 100; //generates a random number between 1 and 100
		cout << "Randomnumber:  " << randomNumber <<endl;

		if (guess == randomNumber)
			cout << "You win $1 billion dollars!\n\n";
		else
			cout << "Better luck next time.\n\n";		

		cout << "Do you want to run the program again? (y/n)\n";
		cin >> response;
		if (response == 'n' || response == 'N')
			goAgain = false;
		
	}
	return 0;
}
