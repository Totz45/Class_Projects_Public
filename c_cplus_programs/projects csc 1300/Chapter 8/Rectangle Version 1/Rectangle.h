// Specification file for the Rectangle class.
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>     
#include <cstdlib>  
using namespace std;     

// Rectangle class declaration.

class Rectangle
{
   private:
      double width;
      double length;
   public:
      void setWidth(double);
      void setLength(double);
      double getWidth() const;
      double getLength() const;
      double getArea() const;
};

#endif







