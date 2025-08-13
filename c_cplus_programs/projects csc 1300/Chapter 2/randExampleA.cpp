/*
	Title: randExampleA.cpp
	Author:  zyBooks
	Date:  5-31-2017
	Purpose: show how to generate a random number.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << endl << endl; //added by Crockett
	
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	
	cout << "(RAND_MAX: " << RAND_MAX << ")" << endl;
	
	return 0;
}