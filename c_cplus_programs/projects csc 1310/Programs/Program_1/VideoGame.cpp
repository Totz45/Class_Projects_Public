/*
    File Name: VideoGame.cpp
    Author: Tate Finley
    Date: 9/13/22
    Purpose: includes the header file VideoGame.h which can access functions of class text
             and defines the functions in the included header file.
*/
#include "VideoGame.h"

/*
    Function Name: VideoGame()
    Function Purpose: assigns parameters to the associated videoGame object to store 
                      their data and create new videoGame
    Parameters: 3 pointers to a Text object and an integer
    Returns: None
*/
VideoGame::VideoGame(Text* gameTitle, Text* gameMaker, Text* gamePublisher, int yearMade)
{
    title = gameTitle;//storing title of game
    developer = gameMaker;//storing developer of game
    publisher = gamePublisher;//storing publisher of game
    year = yearMade;//storing year made
}

/*
    Function Name: ~VideoGame()
    Function Purpose: destructor of videoGame object
    Parameters: None
    Returns: None
*/
VideoGame::~VideoGame()
{
    //calls Text destructor
    delete title;
    delete publisher;
    delete developer;
    cout << "\nVideoGame Destructor: Released memory for VideoGame object";
}

/*
    Function Name: printVideoGameDetails()
    Function Purpose: prints the data found in the videoGame object
    Parameters: None
    Returns: None
*/
void VideoGame::printVideoGameDetails()
{
    //Formatted nicely for display
    cout << right;
    cout << "\n" << setw(30) << "Game Title: ";
    cout << left;
    title->displayText();
    cout << right;
    cout << "\n" << setw(30) << "Developer: ";
    cout << left;
    developer->displayText();
    cout << right;
    cout << "\n" << setw(30) << "Publisher: ";
    cout << left;
    publisher->displayText();
    cout << right;
    cout << "\n" << setw(30) << "Year Released: ";
    cout << left;
    cout << year;
    cout << "\n";
}

/*
    Function Name: printVideoGameDetailsToFile()
    Function Purpose: prints the video game details into a text document or file
    Parameters: address of file stream 
    Returns: None
*/
void VideoGame::printVideoGameDetailsToFile(ofstream& fileOutput)
{
    fileOutput << title->getText() << "\n";//outputs the tite
    fileOutput << developer->getText() << "\n";//outputs the developer
    fileOutput << publisher->getText() << "\n";//outputs the  publisher
    fileOutput << year << "\n";//outputs the year
}

/*
    Function Name: getVideoGameTitle()
    Function Purpose: returns the Text pointer of title of the videoGame object.
    Parameters: None
    Returns: Text pointer to title of game
*/
Text* VideoGame::getVideoGameTitle()
{
    return title;
}