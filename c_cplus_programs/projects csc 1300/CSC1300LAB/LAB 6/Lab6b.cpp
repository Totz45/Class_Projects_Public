/*
    File Name: Lab6b.cpp
    Author: Tate Finley
    Date: 3/5/22
    Purpose: This program creates a money tree using for loops.
*/

#include <iostream>
using namespace std;

int main() 
{
    int numOfRows; //number of rows, a user input
    int i; //counts up for outer for loop
    int j; //counts up for inner for loop
    int k; //counts down for inner for loop

    /*allows user to affect the size of the money tree 
      by setting the number of rows.*/
    cout << "\nEnter the number of Rows: ";
    cin >> numOfRows;
    
    //validates that the number of rows is greater than 1.
    while(numOfRows <= 1) 
    {
        cout << "Oops! You must enter a number greater than 1!";
        cout << "\nEnter the number of Rows: ";
        cin >> numOfRows;
    }

    cout << "\n\n";
    
    //for loop so that two inner loops, loop again after newline.
    for(i = 1; i <= numOfRows; i++) 
    {
        //sets up the spaces to center the $, decrements # of spaces over time
        for(k = numOfRows; k >= i; k--) {
            cout << " ";
        }
        //inserts the $, increments # of $ over time
        for(j = 1; j <= i; j++) {
            cout << "$ ";
        }
        cout << endl;
    }


    return 0;
}