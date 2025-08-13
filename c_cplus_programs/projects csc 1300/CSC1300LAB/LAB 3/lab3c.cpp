/*
    File Name: lab3c.cpp
    Author: Tate Finley
    Date: February 9th, 2022
    Purpose: This program calculates the current of a circuit.
*/
#include <iostream>
using namespace std;

int main()
{
	const double voltage = 5.95487; //sets voltage to constant
	string fullName; //allows user to input their name
	double current, resistance; //variables in the equation, resistance known, solve for current.

	//user inputs the resistance of the circuit
    cout << "\n\nWhat is the resistance in Kilo-ohms of your circuit?\n";
	cin >> resistance;
	
    //user inputs first and last name
    cout << "\n\nWhat is your first & last name?\n";
    cin.ignore();
	getline(cin, fullName);

	// Calculates the current.
	current = voltage / resistance;
	
	// Displays the current.
	cout << "\n\nHello, " << fullName;
	cout << "! The current of your circuit is: " << current << " Millie-amp.";
	cout << endl << endl;
	
	return 0;
}