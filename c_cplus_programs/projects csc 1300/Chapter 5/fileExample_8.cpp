/*
	Title:  fileExample_8.cpp
	Author:  April R Crockett
	Date:  7/27/2017
	Purpose:  input file example that reads data from a file in a loop
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream inputFile;
   string name;

   // Open the file.
   inputFile.open("Friends.txt");

   if(inputFile.good())
   {
	   // Read the numbers from the file and
	   // display them.
	   while (getline(inputFile, name))
	   {
		  cout << name << endl;
	   }
	
	   // Close the file.
	   inputFile.close();
   }
   else
	   cout << "\n\nOh no!!!  I can\'t open the file!\n\n";
   return 0;
}





