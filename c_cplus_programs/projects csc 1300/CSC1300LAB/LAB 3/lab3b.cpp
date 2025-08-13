/*
    File Name: lab3b.cpp
    Author: Tate Finley
    Date: February 9th, 2022
    Purpose: This program will demonstrate the use of random numbers
             in order to produce a unique output.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int randomNum1; // generates a random number
	string name, anotherName, location, food; //user assigns variables
	string original; //produces string output
	
	/* time(0) will seed the random number generator based on time */
	srand(time(0));
	
    /* Input statements for output later*/
	cout << "Good afternoon!  Please enter the following information:\n\n";
	cout << "YOUR NAME:  ";
	getline(cin, name);
	cout << "ANOTHER PERSON\'s NAME:  ";
	getline(cin, anotherName);
	cout << "LOCATION NAME:  ";
	getline(cin, location);
	cout << "FOOD NAME:  ";
	getline(cin, food);
	
	cout << endl;
	
	/* Generates a random number from 1 to 2 and saves it in randomNum1 */
	randomNum1 = (rand() % 2) + 1;
	
    //if randomNum is equal to 1, it will print out the first message
	if (randomNum1 == 1) {
        cout << name << ", fortunately you can eat " << food << " in the ";
        cout << location << ". Watch out, " << anotherName << " wants \nto";
        cout << " take a bite. Have a happy meal.";
    } 
    // if randomNum is to 2, it will print out the second message
    else {
        cout << name << ", unfortunately you cannot eat " << food << " in the ";
        cout << location << ". You are lucky " << anotherName << " will not\n";
        cout << "take a bite. You can eat elsewhere.";
    }
	cout << original;
	
	
	
	cout << endl;
	return 0;
}