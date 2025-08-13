/*
	Title:   stringAccessB.cpp
	Author:  April Crockett
	Date:    6-1-2017
	Purpose: to demonstrate different string access functions
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int stringIndex, length;
	string city, temp, random, anotherRandom;
	char letter;

	
	cout << "\n\nWhat city are you from? ";
	getline(cin, city);
	
	if(city.empty())
		cout << "\nYou didn\'t enter a city.\n";
	else
		cout << "\nYou did enter a city.\n";
	
	cout << "Your city\'s name has " << city.length() << " characters\n";
	cout << "Your city\'s name has " << city.size() << " characters\n";
	
	//use find where item is a char literal
	stringIndex = city.find('C');
	cout << "Your city has a \'C\' in it at index " << stringIndex << endl;
	
	//use find where item is a char variable
	cout << "\nEnter a letter:  ";
	cin >> letter;
	stringIndex = city.find(letter);
	cout << "Your city has a \'" << letter << "\' in it at index " << stringIndex << endl;
	
	//use find where item is a string literal
	stringIndex = city.find("ville");
	cout << "Your city has a \"ville\" in it at index " << stringIndex << endl;
	
	//use find where item is a string variable
	cout << "\nEnter a string:  ";
	cin.ignore();
	getline(cin, temp);
	stringIndex = city.find(temp);
	cout << "Your city has a \"" << temp << "\" in it at index " << stringIndex << endl;
	
	//use find where item is a string literal and find starts at index 14 (it will find the 2nd m in move)
	random = "I like to move it move it!";
	stringIndex = random.find("move", 14);
	cout << "\n\nYour string \"" << random << "\" has a \"move\" in it at index " << stringIndex << " starting after index 14." << endl;
	
	//use substr
	cout << endl << endl;
	anotherRandom = random.substr(18, 8);
	cout << anotherRandom << endl << endl;
	
	return 0;
}