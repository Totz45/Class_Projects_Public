/*
	Title: randExampleC.cpp
	Author:  zyBooks, modified by Crockett
	Date:  5-31-2017
	Purpose: show how to generate a random number.
*/
#include <iostream>
#include <cstdlib> //Enables use of rand() and srand() function
#include <ctime> //Enables use of time() function
using namespace std;

int main()
{
	cout << endl << endl; //added by Crockett
	
	//seed the random number generator with time function
	srand(time(0)); // you only need to do this once
	
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	
	cout << "(RAND_MAX: " << RAND_MAX << ")" << endl;
	
	return 0;
}