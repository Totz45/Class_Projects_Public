/*
    File Name: Lab6a.cpp
    Author: Tate Finley
    Date: 3/2/22
    Purpose: This program uses do while and while loops to validate a user's input
             and allow the program to run again. This is a game where the user must
             guess a number between 1 and 5, the program keeps count on how many attempts
             the user makes to try and guess the number.
*/

#include <iostream>
#include <ctime>
using namespace std;

int main() 
{
    bool playGame = true; //allows program to be played again
    
    int generatedNum; //random number between 1 and 5
    int userGuess; //user's pick for the number generated
    int numGuesses; //number of attempts to guess the number
    char playAgain; //choice for running program again or quitting

    do{
        srand(time(0)); //seeded with time for pure randomness
        
        numGuesses = 1; //set to 1 for first guess
        playAgain = ' '; //resets playAgain to pass through the while loop at end.
        
        generatedNum = rand() % 5 + 1; //number between 1 and 5
        
        //first user guess
        cout << "\n\nGuess a number between 1 and 5\n";
        cout << "Enter your guess:  ";
        cin >> userGuess;
        
        //while loop validates answer
        while (userGuess < 1 || userGuess > 5)
        {
            cout << "\nYou entered an invalid number.  Choose between 1 and 5.\n";
            cout << "Enter your guess:  ";
            cin >> userGuess;
             
        }
        
        //runs if user does not guess the random number first try
        while (userGuess != generatedNum) 
            {
                //if statement runs if user's answer is greater than random number
                if(userGuess > generatedNum) 
                {
                    cout << "Too high\n\n";
                    numGuesses = numGuesses + 1; //adds to the number of guesses
                    cout << "Enter your guess:  ";
                    cin >> userGuess;

                    //validates input 
                    while (userGuess < 1 || userGuess > 5)
                    {
                        cout << "\nYou entered an invalid number.  Choose between 1 and 5.\n";
                        cout << "Enter your guess:  ";
                        cin >> userGuess;
                    }

                } 
                /*otherwise it must be less than random number;
                  if it were equal it would not be in the while loop*/
                else if(userGuess < generatedNum)
                {
                    cout << "Too low\n\n";
                    numGuesses = numGuesses + 1; //adds to the number of guesses
                    cout << "Enter your guess:  ";
                    cin >> userGuess;

                    //validates input
                    while (userGuess < 1 || userGuess > 5)
                    {
                        cout << "\nYou entered an invalid number.  Choose between 1 and 5.\n";
                        cout << "Enter your guess:  ";
                        cin >> userGuess;
                    }
                }
            }

        /*if the user guesses correctly, it would skip or exit 
          the previous while loop and output this statement.
          
          numGuesses increments everytime the user guesses a valid
          answer incorrectly to the random number*/
        if (userGuess == generatedNum)
        {
            cout << "Correct!  You got it in ";
            cout << numGuesses << " tries!\n\n"; 
        }

        //while loop to check if the user wants to run program again.
        while (playAgain != 'n' && playAgain != 'N' && playAgain != 'y' && playAgain != 'Y')
        {
            cout << "Do you want to play again (y/n)?";
            cin >> playAgain; 
            //if n or N, exits do while loop
            if(playAgain == 'n' || playAgain == 'N') {
                playGame = false;
            } 
            //if y or Y, runs do while loop again
            else if(playAgain == 'y' || playAgain == 'Y') {
                playGame = true;
            } 
            //anything else will lead to this result and the while will loop again.
            else {
                cout << "\n\nInvalid input.  You must enter a 'y' or a 'n'.\n";
            }
        }    
            
    } while(playGame);

    return 0;

}