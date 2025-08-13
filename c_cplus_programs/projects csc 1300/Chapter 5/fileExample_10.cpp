/*
	Title:  fileExample_10.cpp
	Author:  April R Crockett
	Date:  7/27/2017
	Purpose:  input file example that lets the user enter a 
			  filename and uses the eof & good functions
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	fstream inputFile;
	string filename;
	double number;

	// Get the filename from the user.
	cout << "Enter the filename: (name.txt)";
	cin >> filename;

	// Open the file.
	inputFile.open(filename, ios::in); //c_str()

	// If the file successfully opened, process it.
	if (inputFile)
	{
		// Read the numbers from the file and
		// display them.
		while (!inputFile.eof())
		{
			inputFile >> number;
			if(inputFile.good())
				cout << number << endl;
		}

		// Close the file.
		inputFile.close();
	}
	else
	{
		// Display an error message.
		cout << "Error opening the file.\n";
	}
	return 0;
}