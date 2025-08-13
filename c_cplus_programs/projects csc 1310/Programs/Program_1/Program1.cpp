/*
    File Name: Program1.cpp
    Author: Tate Finley
    Date: 9/9/22
    Purpose: Main compiler for all previous programs and header files.
    For: CSC 1310-001
*/

#include "VideoGameLibrary.h"

int main()
{
    int numberOfVideoGames = 0;//initialized, indicates the max number of videogames allowed in array
    VideoGameLibrary* gameLibrary;//accessor to other videoGameLibrary functions
    char nameOfFile[100];//substitute for not being able to use c++ strings in program
    
    //Asks user to input for numberOfVideoGames to determine array size
    cout << "\nHow many video games can your library hold?  ";
    cin >> numberOfVideoGames;
    
    gameLibrary = new VideoGameLibrary(numberOfVideoGames);//DMA of VideoGameLibrary to pointer
    int option = 0; //initialized, allows user to select function to execute
    
    //do while loop used to loop program until exit value which is 6
    do {
        
        cout << "\n\nWhat would you like to do?";
        cout << "\n1.\tLoad video games from file.";
        cout << "\n2.\tSave video games to a file.";
        cout << "\n3.\tAdd a video game.";
        cout << "\n4.\tRemove a video game.";
        cout << "\n5.\tDisplay all video games.";
        cout << "\n6.\tRemove ALL video games from this library and end program.";
        cout << "\nCHOOSE 1-6:  ";
        cin >> option;
        //Checks to see if the option is one of the six available
        if(option < 1 || option > 6)
        {
            cout << "\nThat is not a valid choice.";
        } else {
            switch(option) 
            {
                //function for option 1
                case 1:
                    cout << "\nWhat is the name of the file you are loading? ";
                    cin.ignore();
                    cin.getline(nameOfFile, sizeof(nameOfFile));
                    gameLibrary->loadVideoGamesFromFile(nameOfFile);
                    break;
                //function for option 2
                case 2:
                    cout << "\nWhat is the name of the file you are saving data to? ";
                    cin.ignore();
                    cin.getline(nameOfFile, sizeof(nameOfFile));
                    gameLibrary->saveToFile(nameOfFile);
                    break;
                //function for option 3
                case 3:
                    gameLibrary->addVideoGameToArray();//calls function to add video game
                    break;
                //function for option 4
                case 4:
                    gameLibrary->removeVideoGamesFromArray();//calls function to remove video game
                    break;
                //function for option 5
                case 5:
                    gameLibrary->displayVideoGames();//calls function to display all video games
                    break;
                //function for option 6
                case 6:
                    delete gameLibrary;//calls video game library destructor
                    break;
            }
        }
    } while(option != 6);
    //end program
    cout << "\n\nGoodbye!";
    return 0;
}