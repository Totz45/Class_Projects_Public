// This program uses a switch statement to determine
// the item selected from a menu.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int choice;       // To hold a menu choice
	int months;       // To hold the number of months
	double charges;   // To hold the monthly charges

	// Constants for membership rates
	const double ADULT = 40.0, SENIOR = 30.0, CHILD = 20.0;

	// Display the menu and get a choice.
	cout << "\t\tHealth Club Membership Menu\n\n"
	<< "1. Standard Adult Membership\n"
	<< "2. Child Membership\n"
	<< "3. Senior Citizen Membership\n"
	<< "4. Quit the Program\n\n"
	<< "Enter your choice: ";
	cin >> choice;

	//validate user's choice
	if(choice < 1 || choice > 4)
	{
		cout << "\nInvalid choice.  Please choose from 1 to 4:  ";
		cin >> choice;
	}

	// Set the numeric ouput formatting.
	cout << fixed << showpoint << setprecision(2);

	cout << "For how many months?  ";
	cin >> months;
	
	// Respond to the user's menu selection.
	switch (choice)
	{
		case 1:
			charges = months * ADULT;
			cout << "The total charges are $" << charges << endl;
			break;

		case 2:
			charges = months * CHILD;
			cout << "The total charges are $" << charges << endl;
			break;

		case 3:
			charges = months * SENIOR;
			cout << "The total charges are $" << charges << endl;
	}
	
	cout << "\nProgram ending.\n\n";

	return 0;
}