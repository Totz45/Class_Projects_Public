//scopeA.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	int userNumber, randomNum; //this is where the variables are created in memory	
	/*
		Note:  the SCOPE of the userNumber & randomNum variables 
		is from line 9 to line 33.  This means this is where these variables can be
		accessed and modified.
	*/	
	srand(time(0));
	
	cout << "\n\nGuess a number between 1 and 100:  ";
	cin >> userNumber;
	
	randomNum = rand() % 100 + 1;
	
	if(userNumber == randomNum)
	{
		cout << "\nYES!  You guessed the correct number!\n";
		cout << "You win one million dollars!\n\n";
	}
	else
	{
		cout << "It\'s a big NOPE.  My number was ";
		cout << randomNum << endl << endl;
	}
	
	return 0; //program ends, both local variables (userNumber & randomNum) are deleted in memory
}