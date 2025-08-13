/*
	Title:  structDMA_1.cpp
	Author:  Gaddis, modified by April Crockett
	Date:  8/16/2017
	Purpose:  This program uses a function to return a structure. 
*/
#include <iostream>
#include <iomanip>
#include <cmath>  // For the pow function
using namespace std;

const double PI = 3.14159;

// Structure declaration
struct Circle
{
	double radius;      // A circle's radius
	double diameter;    // A circle's diameter
	double area;        // A circle's area
};

Circle* createCircleArray(int);

int main()
{
	Circle *c;
	int numCircles;

	cout << "\n\nHow many circles do you have?\n";
	cin >> numCircles;
	
	c = createCircleArray(numCircles);

	
	for(int i=0; i<numCircles; i++)
	{
		cout << "\nCIRCLE " << i+1 << " DIAMETER: ";
		cin >> c[i].diameter;
		
		c[i].radius = c[i].diameter / 2.0;

		// Calculate the circle's area.
		c[i].area = PI * pow(c[i].radius, 2.0);
		
		cout << "\n\nRadius: " << c[i].radius << endl;
		cout << "Area: " << c[i].area << endl << endl;
	}	

	delete [] c;

	return 0;
}


Circle* createCircleArray(int size)
{
	Circle* myArray;
	myArray = new Circle[size];
	return myArray;
}








