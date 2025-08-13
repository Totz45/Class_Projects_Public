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

int main()
{
	Circle *c;
	c = new Circle;

	cout << "\n\nEnter the diameter of a circle: ";
	cin >> c->diameter;
	c->radius = c->diameter / 2.0;

	// Calculate the circle's area.
	c->area = PI * pow(c->radius, 2.0);

	// Display the circle data.
	cout << "\n\nThe radius and area of the circle are:\n";
	cout << fixed << setprecision(2);
	cout << "Radius: " << c->radius << endl;
	cout << "Area: " << c->area << endl << endl;

	delete c;

	return 0;
}


