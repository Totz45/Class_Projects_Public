/*
	Title:   switchD.cpp
	Author:  Gaddis, modified by Crockett
	Date:    6-1-2017
	Purpose: This program is carefully constructed to use the "fallthrough" 
             feature of the switch statement.
*/
#include <iostream>
using namespace std;

int main()
{
	int modelNum; 

	// Get a model number from the user.
	cout << "Our TVs come in three models:\n";
	cout << "The 100, 200, and 300. Which do you want? ";
	cin >> modelNum;

	// Display the model's features.
	cout << "That model has the following features:\n";
	switch (modelNum)
	{
		case 300: 	cout << "\tSmart TV\n";
		case 200: 	cout << "\tHDTV\n";
		case 100: 	cout << "\tRemote control.\n";
					break;
		default:  	cout << "You can only choose the 100,";
					cout << "200, or 300.\n";
	}

	return 0;
} 