/*
	Title:  fileExample_1.cpp
	Author:  April R Crockett
	Date:  7/27/2017
	Purpose:  output file example that writes data to a file.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outputFile;
	
	//open the file
	outputFile.open("demofile.txt");
	
	cout << "Now writing data to the file.\n";
	// Write four names to the file.
	outputFile << "Bach\n";
	outputFile << "Beethoven\n";
	outputFile << "Mozart\n";
	outputFile << "Schubert\n";

	// Close the file
	outputFile.close();

	//open file
	outputFile.open("demofile.txt", ios::app);
	outputFile << 3948 << endl;
	outputFile << 7 << endl;
	outputFile << 328472 << endl;
	outputFile.close();

	cout << "Done.\n";
	return 0;
}