/*********************************************
	Title: 		referenceVariable_1.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	This program uses a reference
				variable as a funciton 
				parameter.
**********************************************/

#include <iostream>
using namespace std;

// Function prototype. The parameter is a reference variable.
void doubleNum(int&);

int main()
{
	int value = 4;

	cout << "In main, value is " << value << endl;
	cout << "Now calling doubleNum..." << endl;
	doubleNum(value);
	cout << "Now back in main. value is " << value << endl;
	
	return 0;
}

/**********************************************************
	Function Name:  	doubleNum()
	Function Purpose:	The parameter refVar is a reference
						varaible.  The value in refVar
						is doubled.
***********************************************************/
void doubleNum(int& refVar)
{
   refVar *= 2;
}














