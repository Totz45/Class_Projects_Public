/*
	Title:  fileExample_9.cpp
	Author:  April R Crockett
	Date:  7/27/2017
	Purpose:  input file example that tests for file open errors.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream inputFile;
	int number;

	// Open the file.
	inputFile.open("BadListOfNumbers.txt");

	// If the file successfully opened, process it.
	if (inputFile.is_open())
	{
		// Read the numbers from the file and
		// display them.
		while (inputFile >> number && inputFile.good())
		{
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