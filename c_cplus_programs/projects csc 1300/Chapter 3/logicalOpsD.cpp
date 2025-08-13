/*
	Title:   logicalOpsD.cpp
	Author:  Gaddis, modified by Crockett
	Date:    6-1-2017
	Purpose: This program displays a menu and asks the user to make a
             selection. An if/else if statement determines which item
             the user has chosen.
*/
#include <iostream>
using namespace std;

int main()
{
	int choice;       // To hold a menu choice
	int months;       // To hold the number of months
	double charges;   // To hold the monthly charges

	// Display the menu and get a choice.
	cout << "\t\tHealth Club Membership Menu\n\n";
	cout << "1. Standard Adult Membership\n";
	cout << "2. Child Membership\n";
	cout << "3. Senior Citizen Membership\n";
	cout << "Choose 1-3: ";
	cin >> choice;

	if(choice < 1 || choice > 3)
	{
		cout << "Invalid choice.  Choose 1-3: ";
		cin >> choice;
	}

	cout << "For how many months? ";
	cin >> months;

	// calculate the charges
	if (choice == 1)
		charges = months * 40;
	else if (choice == 2)
		charges = months * 30;
	else if (choice == 3)
		charges = months * 20;
	
	//print result
	cout << "The total charges are $" << charges << endl << endl;

	return 0;
}