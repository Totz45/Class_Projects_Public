//leftRight.cpp
// This program displays three rows of numbers.

#include <iostream>
#include <iomanip>      // Required for setw
using namespace std;

int main()
{
   int num1 = 2897, num2 = 5,    num3 = 837,
       num4 = 34,   num5 = 7,    num6 = 1623,
       num7 = 390,  num8 = 3456, num9 = 12;
   
   cout << endl;
   
   cout << "The default alignment for output is right aligned.\n\n";
   
   cout << setw(6) << num1 << setw(6) << num2 << setw(6) << num3 << endl;
   cout << setw(6) << num4 << setw(6) << num5 << setw(6) << num6 << endl;
   cout << setw(6) << num7 << setw(6) << num8 << setw(6) << num9 << endl;
   
   cout << "\n\nUse left stream manipulator.\n\n";
   
   cout << left;
   
   cout << setw(6) << num1 << setw(6) << num2 << setw(6) << num3 << endl;
   cout << setw(6) << num4 << setw(6) << num5 << setw(6) << num6 << endl;
   cout << setw(6) << num7 << setw(6) << num8 << setw(6) << num9 << endl;
   
   cout << "\n\nUse right stream manipulator.\n\n";
   
   cout << right;
   
   cout << setw(6) << num1 << setw(6) << num2 << setw(6) << num3 << endl;
   cout << setw(6) << num4 << setw(6) << num5 << setw(6) << num6 << endl;
   cout << setw(6) << num7 << setw(6) << num8 << setw(6) << num9 << endl;
   
   return 0;
   
}