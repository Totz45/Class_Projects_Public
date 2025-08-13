// This program calls the Rectangle class constructor.
#include <iostream>
#include <iomanip>
#include "Rectangle.h"
using namespace std;

int main()
{
   Rectangle myMomNDadsCrib;  //will call the default constructor
   double houseWidth, houseLength;
   cout << setprecision(2) << fixed;
   
   myMomNDadsCrib.setWidth(100);
   myMomNDadsCrib.setLength(25);
   cout << "\n\nMy Mom & Dad\'s house is " << myMomNDadsCrib.getArea() << " square feet.\n\n";

   // Get the width of the house.
   cout << "In feet, how wide is your house? ";
   cin >> houseWidth;

   // Get the length of the house.
   cout << "In feet, how long is your house? ";
   cin >> houseLength;
   
   // Create a Rectangle object.
   Rectangle house(houseWidth, houseLength); //will call the overloaded constructor
   
   // Display the house's width, length, and area.
   
   cout << "The house is " << house.getWidth() << " feet wide.\n";
   cout << "The house is " << house.getLength() << " feet long.\n";
   cout << "The house has " << house.getArea() << " square feet of area.\n";
   return 0;
}