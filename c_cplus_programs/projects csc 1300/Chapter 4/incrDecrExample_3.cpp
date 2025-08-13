/*
	Title:		incrDecrExample_3.cpp
	Author:		Gaddis, modified by Crockett
	Date:  		6/9/2017
	Purpose:	This program demonstrates a simple while loop using increment postfix.
*/
#include <iostream>
using namespace std;

int main()
{
   int number = 0;

   while (number < 5)
   {
      cout << "Hello\n";
      number++;
   }
   cout << "That's all!\n";
   return 0;
}