/*
    File Name: Text.cpp
    Author: Tate Finley
    Date: 9/14/22
    Purpose: Function Definitions for the Text Class
*/

#include "Text.h"

/*
    Function Name: Text()
    Function Purpose: dynamically allocates a new character array and
                      stores the value in textArray
    Parameters: pointer to a c-string aka a character array
    Returns: None
*/
Text::Text(char* characterArray)
{
    textArray = new char [strlen(characterArray) + 1];//DMA of a new char array
    
    textArray = strcpy(textArray, characterArray);//copies data from argument
}

/*
    Function Name: ~Text()
    Function Purpose: destructor that releases memory from c-strings
    Parameters: None
    Returns: None
*/
Text::~Text()
{
    delete [] textArray;
    cout << "\nText Destructor: Released memory for textArray";
}

/*
    Function Name: displayText()
    Function Purpose: outputs c-string to screen
    Parameters: None
    Returns: None
*/
void Text::displayText()
{
    cout << textArray;
}

/*
    Function Name: getText()
    Function Purpose: retreives the c-string
    Parameters: None
    Returns: pointer to a constant character array
*/
char* Text::getText() const
{
    return textArray;
}

/*
    Function Name: getLength()
    Function Purpose: returns the length of the c-string
    Parameters: None
    Returns: an integer(the length of the c-string)
*/
int Text::getLength() const
{
    return strlen(textArray);
}