/*
	Title:  circle.h
	Author:  Tate Finley
	Date:  8/23/2022
	Purpose:  This program uses a function to return a structure. 
*/

#ifndef CIRCLE_H
#define CIRCLE_H

const double PI = 3.14159;

// Structure declaration
struct Circle
{
   double radius;      // A circle's radius
   double diameter;    // A circle's diameter
   double area;        // A circle's area
};

int howManyCircles();

#endif