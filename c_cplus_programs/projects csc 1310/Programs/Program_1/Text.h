/*
    File Name: Text.h
    Author: Tate Finley
    Date: 9/14/22
    Purpose: Header file that defines the Text class
*/

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <cstring>
using namespace std;

/*
    Class Name: Text
    Attributes: a character pointer and an integer
    Functions: a constructor, a destructor, a setter function,
    and two getter functions.
    Class Purpose: Creation of a character array or string.
*/
class Text
{
    private:
        char* textArray;//functions as a string
        int textLength;//length of the character array
    public:
        Text(char*);
        ~Text();
        void displayText();
        char* getText() const;
        int getLength() const;
};

#endif