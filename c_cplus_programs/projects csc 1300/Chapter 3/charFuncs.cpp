/*
	Title:   charFuncs.cpp
	Author:  Gaddis, modified by Crockett
	Date:    6-1-2017
	Purpose: This program demonstrates some character testing functions.
*/

#include <iostream>
#include <cctype>  //you must include this file to use the character testing functions!
using namespace std;

int main()
{
	char input;

	cout << "Enter any character: ";
	cin.get(input);
	cout << "The character you entered is: " << input << endl;
	if (isalnum(input))
		cout << "That is either alphabetic character or a numeric digit.\n";
	if (isalpha(input))
		cout << "That's an alphabetic character.\n";
	if (isdigit(input))
		cout << "That's a numeric digit.\n";
	if (islower(input))
		cout << "The letter you entered is lowercase.\n";
	if (isupper(input))
		cout << "The letter you entered is uppercase.\n";
	if (isspace(input))
		cout << "That's a whitespace character.\n";
	if (ispunct(input))
		cout << "That is a printable character other than digit, letter or space.\n";
	if (isprint(input))
		cout << "That is a printable character.\n";

	return 0;
}