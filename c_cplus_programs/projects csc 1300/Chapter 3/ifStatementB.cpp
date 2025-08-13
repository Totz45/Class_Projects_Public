/*
	Title:    ifStatementB.cpp
	Author:   April Crockett
	Date:     6-1-2017
	Purpose:  This program demonstrates how a misplaced semicolon
              prematurely terminates an if statement.
*/
#include <iostream>
using namespace std;

int main()
{
   int x = 0, y = 10;

   cout << "x is " << x << " and y is " << y << endl;
   
   if (x > y);
		cout << "x is greater than y\n"; 
		
   return 0;
}





