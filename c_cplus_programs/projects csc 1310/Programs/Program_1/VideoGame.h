/*
    File Name: VideoGame.h
    Author: Tate Finley
    Date: 9/13/22
    Purpose: Defines the class of VideoGame
*/

#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Text.h"
#include <fstream>
#include <iomanip>
using namespace std;

/*
    Class Name: VideoGame
    Attributes: 3 pointers to Text objects and an integer
    Functions: a constructor, a destructor, a setter function,
    and two getter functions.
    Class Purpose: Creation of a character array or string.
*/
class VideoGame
{
    private:
        Text* title;//title of videoGame
        Text* developer;//maker of videoGame
        Text* publisher;//person who published videoGame
        int year;//the year the videoGame was made
    public:
        VideoGame(Text*, Text*, Text*, int);
        ~VideoGame();
        void printVideoGameDetails();
        void printVideoGameDetailsToFile(ofstream&);
        Text* getVideoGameTitle();
};

#endif