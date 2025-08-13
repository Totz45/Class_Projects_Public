// Implementation file for the Rectangle class.
// This version has a constructor that accepts arguments.
#include "Rectangle.h"   // Needed for the Rectangle class
#include <iostream>      // Needed for cout
#include <cstdlib>       // Needed for the exit function
using namespace std;

//***********************************************************
// Default Constructor
//***********************************************************
Rectangle::Rectangle()
{
   cout << "\n\nHI!  You are creating a new rectangle object!!\n\n";
}

//***********************************************************
// The constructor accepts arguments for width and length.  *
//***********************************************************

Rectangle::Rectangle(double w, double len)
{
   width = w;
   length = len;
}

//***********************************************************
// Destructor
//***********************************************************
Rectangle::~Rectangle()
{
   cout << "\n\nGOODBYE!!\n\n";
}

//***********************************************************
// setWidth sets the value of the member variable width.    *
//***********************************************************

void Rectangle::setWidth(double w)
{
   if (w >= 0)
      width = w;
   else
   {
      cout << "Invalid width\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// setLength sets the value of the member variable length.  *
//***********************************************************

void Rectangle::setLength(double len)
{
   if (len >= 0)
      length = len;
   else
   {
      cout << "Invalid length\n";
      exit(EXIT_FAILURE);
   }
}
