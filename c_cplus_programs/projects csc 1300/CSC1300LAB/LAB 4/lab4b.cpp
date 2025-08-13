/*
	Title:  	lab4b.cpp
	Author:		Tate Finley
	Date:		February 16th, 2022
	Purpose:	Learning switch statements
*/

#include <iostream>
using namespace std;

int main()
{
	char grade; //stores letter of grade

    //outputs question with user input for variable 'grade'
	cout << "What grade will you earn on this lab assignment?" << endl;
	cout << "GRADE: ";
	cin >> grade;

    //outputs according to what letter the user has inputed
	switch (grade) {
        
        //executes statement if and only if input is A
        case 'A':
            cout << "An A - you rock!!\n";
            break;
        
        //executes statement if and only if input is B
        case 'B':
            cout << "You got a B - good job.\n" ;
            break;
            
        //executes statement if and only if input is C
        case 'C':
            cout << "Earning a C is satisfactory.\n";
            break;

        //executes statement if and only if input is D
        case 'D':
            cout << "While D is passing, there is a problem.\n";
		    cout << "You really didnt learn much.\n";
            break;

        //executes statement if and only if input is F
        case 'F':
            cout << "Oh BARF!  You failed - better luck next time.\n";
            break;

        //executes statement if any other character is inputed
        default :
            cout << "You did not enter an A, B, C, D, or F.\n";
            break;
    }
		
    return 0;
}