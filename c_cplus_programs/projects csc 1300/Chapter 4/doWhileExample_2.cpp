/*
	Title: 		doWhileExample_2.cpp
	Author: 	April Crockett
	Date: 		Feb 12, 2009
	Purpose: 	This program displays a hot beverage menu and prompts 
				the user to make a selection. A switch statement determines
				which item the user has chosen. A do-while loop repeats 
				until the user selects item E from the menu.
*/

#include <iostream>
using namespace std;

int main()
{
	int number; //number of beverages
	float cost; //cost of beverage
	int beverage; //beverage type	
	bool validBeverage;

	do
	{
		cout << endl << endl;
		cout << "Hot Beverage Menu" << endl << endl;
		cout << "1: Coffee         $1.00" << endl;
		cout << "2: Tea            $ .75" << endl;
		cout << "3: Hot Chocolate  $1.25" << endl;
		cout << "4: Cappuccino     $2.50" << endl <<endl << endl;
		
		cout << "Enter the beverage 1,2,3, or 4 you desire" << endl;
		cout << "Enter 5 to exit the program" << endl << endl;
		cin >> beverage;
		
		//validate user input
		while(beverage < 1 || beverage > 5 )
		{
			cout << "\nInvalid input.  Enter the beverage 1, 2, 3, or 4 you desire.\n";
			cout << "Enter 5 to exit the program." << endl<<endl;
			cin >> beverage;
		}
		
		if (beverage != 5)  //user does not want to quit program
		{
			cout << "How many cups would you like?" << endl;
			cin >> number;
		
		
			switch(beverage)
			{
				case 1: cost = number * 1.0;
						cout << "The total cost is $ " << cost << endl;
						break;
				case 2: cost = number * .75;
						cout << "The total cost is $ " << cost << endl;
						break;
				case 3: cost = number * 1.25;
						cout << "The total cost is $ " << cost << endl;
						break;
				case 4: cost = number * 2.50;
						cout << "The total cost is $ " << cost << endl;
			}
		}
		else  //user wants to quit program
			cout << "Thank you.  Please come again.\n\n";

	} while (beverage != 5);

	return 0;
}



