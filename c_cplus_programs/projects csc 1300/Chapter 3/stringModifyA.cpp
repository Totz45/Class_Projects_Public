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
	string nurseryRhyme = "Jack and Jill went up the hill to fetch a pail of water.";
	
	cout << "\n\nORIGINAL:  " << nurseryRhyme << endl;
	
	//insert a substring starting at index 13
	nurseryRhyme.insert(13, " and April");
	
	cout << "\n\nAFTER INSERT:  " << nurseryRhyme << endl;
	
	//replace the word "hill" with "mountain"
	//STEP 1 - find the string "hill" in nurseryRhyme and return index
	int indexOfHill = nurseryRhyme.find("hill"); 
	//STEP 2 - send the starting index of hill, number of characters in hill
	//			and the substring of what you want to put in its place
	nurseryRhyme.replace(indexOfHill, 4, "mountain");
	
	cout << "\n\nAFTER REPLACE:  " << nurseryRhyme << endl;
	
	nurseryRhyme.append(" Jack fell down and broke his crown and Jill came tumbling after.");
	nurseryRhyme.append("  April was perfectly fine though.");
	
	cout << "\n\nAFTER APPEND:  " << nurseryRhyme << endl;
	return 0;
}