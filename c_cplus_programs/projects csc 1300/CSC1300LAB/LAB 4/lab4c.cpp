/*
    File Name: lab4c.cpp
    Author: Tate Finley
    Date: February 16th, 2022
    Purpose: Using while loops to prompt an 
             expected response from the user.
*/

#include <iostream>
using namespace std;

int main() 
{
    char userResponse = 'n'; //initializes userResponse to n
    int caloriesBurned = 0; //initializes caloriesBurned to 0

    /*while loop, loops if either statement is true.
      loops if userResponse is y or if number of 
      calories burned is less than 200.            */
    while (userResponse != 'y' || caloriesBurned < 200) 
    {
        //user inputs calories burned
        cout << "\n\nHow many calories you burnt today?  ";
        cin >> caloriesBurned;

        //user can input y if they want to exit the program
        cout << "\nEnter the letter 'y' if you want to quit.\n";
        cin >> userResponse;

        //checks answer
        cout << "The letter you entered is " << userResponse;

        /*executes if the number of calories burned is
        less than 200 and user responds with y        */
        if(caloriesBurned < 200 && userResponse == 'y') {
            cout << "\nOh no! You need to workout more!";
        }

    }

    return 0;
}
