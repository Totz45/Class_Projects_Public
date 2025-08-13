/*
	Title: characterDataType.cpp
	Author:  April R. Crockett
	Date:  Janaury 19, 2009
	Purpose:  To demonstrate the character (char) data type in C++
*/

#include <iostream>
using namespace std;

int main()
{
	char firstInitial;  //variable definition - I am defining a varaible
	char middleInitial;
	char lastInitial;
	
	firstInitial = 65;  //assignment
	middleInitial = 'R'; //assignment
	lastInitial = 'C'; //assignment

	cout<< endl << "My initials are: " << firstInitial << middleInitial << lastInitial << endl;

	return 0;
}