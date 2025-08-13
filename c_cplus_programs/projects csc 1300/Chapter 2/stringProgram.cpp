/*
	Title:  stringProgram.cpp
	Author:  April Crockett
	Date:  5-31-2017
	Purpose:  demonstrate using strings in C++
*/
#include <iostream>
#include <string> // Required for the string class on some computers.
using namespace std;

int main()
{
   string movieTitle;
   
   movieTitle = "Zootopia";
   cout << "My favorite movie is " << movieTitle << endl;
   
   movieTitle = ""; //putting an empty string in movieTitle
   
   cout << "Printing out movieTitle variable again now: " << movieTitle << endl << endl;
   
   cout << "\n\nWhat is your favorite movie?\n";
   getline(cin, movieTitle);
   
   cout << "\n\nYour favorite movie is " << movieTitle << endl << endl;
   
   return 0;
}





