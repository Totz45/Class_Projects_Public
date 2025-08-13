/*
	Title:  2_2_a.cpp
	Author:  April Crockett
	Date:  5-30-2017
	Purpose:  Example for assignment statements
*/
#include<iostream>
using namespace std;

int main()
{
	int number = 5; //initialization statement
	int width, length(20), height, depth = 2, num = 48;

	width = 47; //assignment statement
	height = 28; //assignment statement
	cout << endl << "The value of number is "<< number << endl;
	cout << "Width: " << width << ", Length: " << length << ", Height: " << height << ", Depth: " << depth <<endl;
	cout << "This is how I print out a newline: \\n" << endl;
	
	cout << "Short experiment: " << num << endl;
	num = 7;
	cout << "Short experiment: " << num << endl;
	
	return 0;
}


















