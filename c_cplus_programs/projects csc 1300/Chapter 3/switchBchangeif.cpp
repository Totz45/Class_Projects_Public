/* 
	Title:   switchB.cpp
	Author:  April Crockett
	Date:    6-1-2017
	Purpose: The switch statement in this program tells the user something
             he or she already knows: what they just entered!
*/
#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "Enter 1, 2, or 3: ";
	cin >> choice;
	if(choice == 1)
	{
		cout << "You entered 1.\n";
		cout << "HELLO\n\n";
	}
	else if (choice == 2)
		cout << "You entered 2.\n";
	else if (choice == 3)
		cout << "You entered 3.\n";
	else
		cout << "You did not enter 1, 2, or 3!\n";


	return 0;
} 