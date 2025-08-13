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
	ifstream inFile;
	string line;
	
	//open the file
	inFile.open("demofile.txt");
	
	inFile >> line;
	cout << line;
	inFile >> line;
	cout << line;
	
	inFile.close();
	
	return 0;
}