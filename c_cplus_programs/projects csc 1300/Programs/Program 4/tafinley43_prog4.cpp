/*
    File Name: tafinley43_prog4.cpp
    Author: Tate Finley
    Date: April 24th, 2022
    Purpose: Main function for the program. Purpose is to store information about heroes in
             an array that allows the information to be easily accessible. 
*/
#include "tafinley43_prog4.h"

int main()
{
    int SIZE;//maximum number of heroes that can be stored
    int numHeroes = 0;//number of heroes in the array
    Heroes * ptrArr;//ptr to the heroes array
    int answer;//user's choice
    
    //asks for maximum capacity of the condo
    cout << "\nHow many superheroes can live in your condo complex?  ";
    cin >> SIZE;

    //dynamically allocates a pointer to the heroes array
    ptrArr = new Heroes[SIZE];

    //main menu for program
    do 
    {
        cout << "\nWhat would you like to do?\n";
        cout << "\t1.  Enter some superheroes\n";
        cout << "\t2.  Delete a superheroes\n";
        cout << "\t3.  Print all superheroes\n";
        cout << "\t4.  Print rent details\n";
        cout << "\t5.  End Program\n";
        cout << "\tEnter 1, 2, 3, 4, or 5.\n";
        cout << "CHOICE: ";
        cin >> answer;

        //validates answer
        if(answer < 1 || answer > 5)
        {
            cout << "\nInvalid response.\n";
        } 
        else 
        {
            //calls appropriate function for task.
            switch (answer) {
                case 1:
                    numHeroes = enterHeroes(SIZE, numHeroes, ptrArr);
                    break;
                case 2:
                    numHeroes = deleteHeroes(numHeroes, ptrArr);
                    break;
                case 3:
                    printHeroes(numHeroes, ptrArr);
                    break;
                case 4:
                    printRentDetails(numHeroes, ptrArr);
                    break;
                case 5:
                    saveToFile(numHeroes, ptrArr);
                    break;
            
            }
        }
    } while(answer != 5);//if the choice is 5, exits the loop

    delete [] ptrArr;//deleting the dynamically allocated pointer variable to array

    return 0;
}
