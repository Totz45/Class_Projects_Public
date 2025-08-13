/*
    File Name: VideoGameLibrary.h
    Author: Tate Finley
    Date: 9/13/22
    Purpose: This header file defines the attributes and functions of the class VideoGameLibrary
*/

#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include "VideoGame.h"
using namespace std;

/*
    Class Name: VideoGameLibrary
    Attributes: a pointer to an array of VideoGame pointers and 2 integers
    Functions: a constructor, a destructor, a setter function,
    and two getter functions.
    Class Purpose: Creation of a character array or string.
*/
class VideoGameLibrary
{
    private:
        VideoGame** videoGamesArray;//pointer to an array of VideoGame pointers
        int maxGames;//the maximum amount of VideoGames
        int numGames;//the current amount of VideoGames
    public:
        VideoGameLibrary(int);
        ~VideoGameLibrary();
        void resizeVideoGameArray();
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(char*);
        void removeVideoGamesFromArray();
        void saveToFile(char*);
};

#endif