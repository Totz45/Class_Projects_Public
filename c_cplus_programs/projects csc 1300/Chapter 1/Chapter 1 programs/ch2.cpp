/* 
   File Name: ch2.cpp
   Author: Tate Finley
   Date: January 24th, 2022
   Purpose: This program will calculate various arithematic equations.
*/
#include <iostream>
using namespace std;

int main()
{
    int result;

    cout << "\nBelow are the results of various "; // first statement
    cout << "arithematic operations." << endl; // continuation of first statement

    result = 5 + 2 * 4; // calculation
    cout << "1) The result of 5 + 2 * 4 is "; // statement 
    cout << result << "." << endl;  // continuation of statement with answer

    result = (5 + 2) * 4;
    cout << "2) The result of (5 + 2) * 4 is ";
    cout << result << "." << endl;

    result = 10 / 5 - 3;
    cout << "3) The result of 10 / 5 - 3 is ";
    cout << result << "." << endl;

    result = 10 / (5 - 3);
    cout << "4) The result of 10 / (5 - 3) is ";
    cout << result << "." << endl;

    result = 6 - 3 * 2 + 7 - 1 + 17 % 2;
    cout << "5) The result of 6 - 3 * 2 + 7";
    cout << " - 1 + 17 % 2 is ";
    cout << result << "." << endl;

    result = (6 - 3) * 2 + (7 - 1) + 17 % 2;
    cout << "6) The result of (6 - 3) * 2 + (7";
    cout << " - 1) + 17 % 2 is ";
    cout << result << "." << endl;
    return 0;
}