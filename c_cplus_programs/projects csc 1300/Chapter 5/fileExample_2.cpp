/*
	Title:  fileExample_2.cpp
	Author:  April R Crockett
	Date:  7/27/2017
	Purpose:  output file example that writes data to a single line in a file.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ofstream topaz;
   topaz.open("demofile.txt", ios::app);

   cout << "Now writing data to the file.\n";

   // Write four names to the file.
   topaz << "\n\n\n\nBach\n";
   topaz << "\tBeethoven\n";
   topaz << "Mozart\n";
   topaz << "Schubert\n";

   // Close the file
   topaz.close();
   cout << "Done.\n";
   return 0;
} 