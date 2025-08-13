// Implementation file for the Rectangle class.
#include "Rectangle.h"   // Needed for the Rectangle class


//***********************************************************
// setWidth sets the value of the member variable width.    *
//***********************************************************

void Rectangle::setWidth(double w) 
{
   width = w;
}

//***********************************************************
// setLength sets the value of the member variable length.  *
//***********************************************************

void Rectangle::setLength(double len)
{
   length = len;
}

//***********************************************************
// getWidth returns the value in the member variable width. *
//***********************************************************

double Rectangle::getWidth() const
{
   return width;
}

//*************************************************************
// getLength returns the value in the member variable length. *
//*************************************************************

double Rectangle::getLength() const
{
   return length;
}

//************************************************************
// getArea returns the product of width times length.        *
//************************************************************

double Rectangle::getArea() const
{
   return width * length;
}




