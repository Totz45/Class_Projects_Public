/*
	Title: randExampleB.cpp
	Author:  April Crockett
	Date:  5-31-2017
	Purpose: generating random numbers between certain ranges
*/
#include <iostream>
#include <cstdlib> //Enables use of rand() function
using namespace std;

int main()
{
	//variable definitions
	int low, high;
	
	cout << endl << endl;
	
	//generate a number 10 to 15
	cout << "RANDOM NUMBER 10-15:  " << rand()%(15-10+1)+10 << endl;
	
	//generate a number 1 to 35
	cout << "RANDOM NUMBER 1-35:  " << rand()%(35-1+1)+1 << endl;
	
	//generate a number -50 to 0
	cout << "RANDOM NUMBER -50-0:  " << rand()%(0+50+1)-50 << endl;
	
	//generate a number low to high (determined by the user)
	cout << "I am going to generate a number for you.\n";
	cout << "You can determine the range.\n";
	cout << "What is the lowest number you want generated?\n";
	cin >> low;
	cout << "What is the highest number you want generated?\n";
	cin >> high;
	
	cout << "RANDOM NUMBER " << low << "-" << high <<":  ";
	cout <<	rand()%(high-low+1)+low << endl << endl;
	
	return 0;
}