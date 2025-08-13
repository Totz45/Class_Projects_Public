/*
	Title:  fileExample_5.cpp
	Author:  April R Crockett
	Date:  7/27/2017
	Purpose:  input file example that reads data from a file.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
   ifstream inputFile;
   string name;

   inputFile.open("Friends.txt");
   cout << "Reading data from the file.\n";
   if(inputFile.is_open())
   {
	   while(getline(inputFile, name))
	   {
		   cout << name << endl;
	   }

	   inputFile.close();      // Close the file
   }
   else
   {
	   cout << "\n\nI can\'t open the file.\n";
   }
   return 0;
} 