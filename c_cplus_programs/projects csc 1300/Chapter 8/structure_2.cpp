/*	Title:  structure_2.cpp
	Author:  April Crockett
	Date:  November 9, 2009
	Purpose:  To show you can use C-Strings inside a struct
*/

#include <iostream>
#include <cstring>

using namespace std;

const int LENGTH = 15;
const int FULL_LENGTH = 50;

struct Name
{
    char first[LENGTH];
	char middle[LENGTH];
	char last[LENGTH];
	char full[FULL_LENGTH];
};

int main()
{
    Name personName;
	
	cout << "\nEnter first name: ";
	cin >> personName.first;
	
	cout << "\nEnter middle name: ";
	cin >> personName.middle;
	
	strcpy(personName.last,"Crockett");

	//cout << "\nEnter last name: ";
	//cin >> personName.last;
	
	strcpy(personName.full, personName.first);
	strcat(personName.full, " ");
	strcat(personName.full, personName.middle);
	strcat(personName.full, " ");
	strcat(personName.full, personName.last);
	
	cout << personName.full << endl;

	return 0;
}













