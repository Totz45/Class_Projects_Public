/*
	Title:  variableNotUsed.cpp
	Author: April Crockett
	Date:  9/2/2019
	Purpose:  compile with -Wall to see the warning.
*/

#include <iostream>
using namespace std;

int main()
{
   int num = 0;
   int variableThatIsNotUsed;
   int total;
   
   total = (6+18)/(8%(2+1));
   cout << total << endl;

   cout << "How many fidget spinners did you throw away today?\n";
   cin >> num;
   
   total = 3 * num;
   
   cout << "You made " << total << " kids cry today.\n\n";
   
   return 0;
} 

