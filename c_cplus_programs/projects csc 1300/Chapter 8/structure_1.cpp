/*
	Title:  structure_1.cpp
	Author:  April Crockett
	Date:  8/15/2017
	Purpose:  demonstrate a structure definition, defining a structure
				variable, and accessing structure members.
*/
#include <iostream>
#include <cmath>
using namespace std;

struct Circle
{
     double radius, diameter, area;
};

const double PI = 3.14159;

int main()
{
    Circle circle1, circle2;
	
	
	cout << "\nWhat is the radius of the first circle?  ";
	cin >> circle1.radius;
	
	cout << "\nWhat is the radius of the second circle?  ";
	cin >> circle2.radius;
	
    circle1.area = PI * pow(circle1.radius, 2.0);
	
	circle2.area = PI * pow(circle2.radius, 2.0);
	
	circle1.diameter = circle1.radius * 2;
	
	circle2.diameter = circle2.radius * 2;
	
	//see if the two circles are equal
	//if(circle1 == circle2)   WRONG WAY TO COMPARE

	if(circle1.radius == circle2.radius)  //CORRECT
		cout << "\nThe two circles are the same.\n";
	else
		cout << "\nThe two circles are different.\n";
	
	return 0;
}








