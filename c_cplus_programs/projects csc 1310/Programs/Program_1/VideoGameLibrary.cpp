/*
    File Name: VideoGameLibrary.cpp
    Author: Tate Finley
    Date: 9/13/22
    Purpose: Defines the functions for the header file VideoGameLibrary.h
*/

#include "VideoGameLibrary.h"

/*
    Function Name: VideoGameLibrary()
    Function Purpose: Creates a new videoGameLibrary function
    Parameters: an integer for the number of video games
    Returns: None
*/
VideoGameLibrary::VideoGameLibrary(int numberOfGames)
{
    videoGamesArray = new VideoGame*[numberOfGames];//DMA of an array of videoGame pointers to pointer
    numGames = 0;//initialize the current number of games to zero
    maxGames = numberOfGames;//assigns maximum number of games allowed in array from the integer argument
}

/*
    Function Name: ~VideoGameLibrary()
    Function Purpose: deletes the videoGameLibrary function
    Parameters: None
    Returns: None
*/
VideoGameLibrary::~VideoGameLibrary()
{
    for(int i = 0; i < numGames; i++)
    {
        delete *(videoGamesArray + i);//deletes all DMA found deeper in the array
    }
    delete [] videoGamesArray;//deletes the DMA array created
    cout << "\nVideoGameLibrary Destructor: Released memory for each";
    cout << " game in the video game array and the array itself.";
}

/*
    Function Name: resizeVideoGameArray()
    Function Purpose: this function doubles the space in the video game array
    Parameters: None
    Returns: None
*/
void VideoGameLibrary::resizeVideoGameArray()
{
    VideoGame** tempVideoGameArray;//used for DMA
    cout << "\nResizing VideoGameArray from " << numGames << " to " << numGames * 2;//Check code
    tempVideoGameArray = new VideoGame*[numGames*2];//DMA is one of the only ways to resize an array
    //Copies the data from each element of the videoGameArray to the new resized array
    for(int i = 0; i < numGames; i++)
    {
        tempVideoGameArray[i] = videoGamesArray[i];
    }
    delete [] videoGamesArray;//deletes the old array
    videoGamesArray = tempVideoGameArray;//assigns the now empty pointer to the new array
    maxGames = numGames * 2;//set new maximum because array changed
    //not sure if tempVideoGameArray can be deleted or not without ruining the program
}

/*
    Function Name: addVideoGameToArray()
    Function Purpose: adds user data into the VideoGameArray
    Parameters: None
    Returns: None
*/
void VideoGameLibrary::addVideoGameToArray()
{
    char tempArray[100];//holds user answer
    Text* tempText;//for storing the title info
    Text* tempText2;//for storing the developer info
    Text* tempText3;//for storing the publisher info
    int yearPublished;//stores information about year published
    
    /*
        The next few statements below involve obtaining information,
        storing it into a character array, then dynamically allocating
        a new Text object to that information.
    */
    cout << "\nVideo Game TITLE:  ";
    cin.ignore();//Program 1 has a cin before this getline so ignore was used
    cin.getline(tempArray, sizeof(tempArray));
    tempText = new Text(tempArray);
    cout << "\nVideo Game DEVELOPER:  ";
    cin.getline(tempArray, sizeof(tempArray));
    tempText2 = new Text(tempArray);
    cout << "\nVideo Game PUBLISHER:  ";
    cin.getline(tempArray, sizeof(tempArray));
    tempText3 = new Text(tempArray);
    
    //this is an exception, only the integer is needed
    cout << "\nVideo Game YEAR:  ";
    cin >> yearPublished;

    //checks to see if the array needs to be resized
    if(numGames == maxGames)
    {
        resizeVideoGameArray();
    }

    //creates a new videoGame object from the info obtained
    videoGamesArray[numGames] = new VideoGame(tempText, tempText2, tempText3, yearPublished);
    tempText = videoGamesArray[numGames]->getVideoGameTitle();
    cout << "\n";
    tempText->displayText();
    cout  << " was successfully added to the array";//outputs that videogame has been added
    numGames++;//increment numGames because a new game was added 
}

/*
    Function Name: displayVideoGames()
    Function Purpose: prints the details of all videoGames
    Parameters: None
    Returns: None
*/
void VideoGameLibrary::displayVideoGames()
{ 
    for (int j = 0; j < numGames; j++)
    {
        cout << "\n";
        cout << right;
        cout << setw(40) << setfill(' ') << "----------Video Game ";
        cout << j + 1 << "----------";//check code
        videoGamesArray[j]->printVideoGameDetails();//calls function from videoGame
    }
}

/*
    Function Name: displayVideoGameTitle()
    Function Purpose: displays all of the titles from the videoGameArray
    Parameters: None
    Returns: None
*/
void VideoGameLibrary::displayVideoGameTitles()
{
    Text* textRetriver;//used in order to access class functions in Text
    for (int j = 0; j < numGames; j++)
    {
        cout << "\nVideo Game " << j + 1 << ": ";//indicates video game number
        textRetriver = videoGamesArray[j]->getVideoGameTitle();//gets title pointer from VideoGame class
        textRetriver->displayText();//outputs the title name 
    }
}

/*
    Function Name: loadVideoGamesFromFile()
    Function Purpose: this function uses the filename passed as an argument
                      and reads in the file searching for the data for each
                      videoGame listed in the file
    Parameters: a character array containing the name of the file
    Returns: None
*/
void VideoGameLibrary::loadVideoGamesFromFile(char* filename)
{
    Text* tempTextFile;//for storing the title info
    Text* tempTextFile2;//for storing the developer info
    Text* tempTextFile3;//for storing the publisher info
    int yearPublishedFile;//stores information about year published
    ifstream infile;//file stream
    int numGamesAdded = 0;//indicates number of videogames added from this function
    char tempCharArray[10000];//character array for storing file info
    infile.open(filename);
    if (infile.is_open())
    {
        
        if(!infile.eof())
        {
            //gets first title
            infile.getline(tempCharArray, 10000, '\n');

            do{
                if(numGames == maxGames)
                {
                    resizeVideoGameArray();
                }   
                tempTextFile = new Text(tempCharArray);
                //gets developer information and creates a text pointer to that data
                infile.getline(tempCharArray, 10000, '\n');
                tempTextFile2 = new Text(tempCharArray);
                //gets publisher information and creates a text pointer to that data
                infile.getline(tempCharArray, 10000, '\n');
                tempTextFile3 = new Text(tempCharArray);
                //gets year released
                infile.getline(tempCharArray, 10000, '\n');
                yearPublishedFile = atoi(tempCharArray);
                //uses data to create a new video game
                videoGamesArray[numGames] = new VideoGame(tempTextFile, tempTextFile2, tempTextFile3, yearPublishedFile);
                //state that the video game was added
                tempTextFile = videoGamesArray[numGames]->getVideoGameTitle();
                cout << "\n";
                tempTextFile->displayText();
                cout  << " was successfully added to the array";//outputs that videogame has been added
                numGames++;//increment the number of video games
                numGamesAdded++;//same as numGames but specific for this function
            } while(infile.getline(tempCharArray, 10000, '\n'));

        }
        cout << "\n" << numGamesAdded << " games were found in the file and added to your library.";
        
        infile.close();
    }
    else{
        cout << "\nSorry, I could not open file";
    }
    
}

/*
    Function Name: removeVideoGamesFromArray()
    Function Purpose: this function removes a selected videogame from the array
    Parameters: None
    Returns: None
*/
void VideoGameLibrary::removeVideoGamesFromArray()
{
    int answer = 0;//index of videogame to be removed
    Text* textRetreiver;//accessor to text functions.
    //if statement runs when there is nothing in the array
    if(numGames == 0)
    {
        cout << "\nThere must be at least one video game in the library!";
    }
    else
    {
        while(answer < 1 || answer > numGames)
        {
            //asks user which video game to remove
            displayVideoGameTitles();
            cout << "\nWhich video game do you want removed";
            cout << " between " << 1 << " & " << numGames << ": ";
            cin >> answer;
        }
        //retrieves pointer to title so it can display title
        textRetreiver = videoGamesArray[answer - 1]->getVideoGameTitle();
        cout << "\n" << textRetreiver->getText();
        cout << " has been removed from the video game library";
        delete videoGamesArray[answer - 1];//deletes the selected videoGame
        //moves up each array starting from deleted videoGame
        for (int i = answer - 1; i < numGames; i++)
        {
            videoGamesArray[i] = videoGamesArray[i + 1];
        }
        numGames--;//one less videoGame in the array
    }
}

/*
    Function Name: saveToFile()
    Function Purpose: opens the output file which will use a function
                      to display the information inside the file.
    Parameters: a character array containing the name of the file
    Returns: None
*/
void VideoGameLibrary::saveToFile(char* filename)
{
    ofstream inTheFile; //filestream
    inTheFile.open(filename);
    //opens file and prints each video game
    for(int j = 0; j < numGames; j++)
    {
        videoGamesArray[j]->printVideoGameDetailsToFile(inTheFile);
    }
    inTheFile.close();
    cout << "\n\nAll video games in your library have been printed to ";
    cout << filename;
}