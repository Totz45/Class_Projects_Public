/*
	Title: stringInput.cpp
	Author:  April Crockett
	Date: 5-31-2017
	Purpose:  demonstrate using strings in C++
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//variable definitions
	string favoriteColor, favoriteFood, favoriteDrink;
	
	//get input from the user
	//HOW CAN I CHANGE THIS PROGRAM TO ALLOW USER TO ENTER SPACES?
	cout << "What is your favorite color?\n";
	cin >> favoriteColor;
	
	cout << "\nWhat is your favorite food?\n";
	cin >> favoriteFood;
	
	cout << "\nWhat is your favorite drink?\n";
	cin >> favoriteDrink;
	
	//output
	cout << "Favorite Color: " << favoriteColor << endl;
	cout << "Favorite Food: " << favoriteFood << endl;
	cout << "Favorite Drink: " << favoriteDrink << endl << endl;
	
	return 0;
}