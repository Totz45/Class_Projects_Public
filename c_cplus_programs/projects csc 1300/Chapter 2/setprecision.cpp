/*
	Title:  setprecision.cpp
	Author:  April Crockett
	Date: 2018
	Purpose: This program demonstrates how setprecision rounds a floating point value.
*/

#include <iostream>
#include <iomanip> //required to use setprecision
using namespace std;

int main()
{
   double quotient = 132.36485967;
   
   cout << setprecision(1) << fixed << quotient << endl;

   cout << quotient << endl;
   cout << setprecision(5) << quotient << endl;
   cout << setprecision(4) << quotient << endl;
   cout << setprecision(3) << quotient << endl;
   cout << setprecision(2) << quotient << endl;
   cout << setprecision(1) << quotient << endl;
   
   cout << fixed;
   cout << setprecision(5) << quotient << endl;
   cout << setprecision(4) << quotient << endl;
   cout << setprecision(3) << quotient << endl;
   cout << setprecision(2) << quotient << endl;
   cout << setprecision(1) << quotient << endl;
   
   return 0;
} 