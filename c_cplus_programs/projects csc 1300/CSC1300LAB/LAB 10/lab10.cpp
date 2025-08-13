/*
    File Name: lab10.cpp
    Author: Tate Finley
    Date: April 6th, 2022
    Purpose: This program demonstrates the basic uses of pointers
*/
#include <iostream>
using namespace std;

int main()
{
    int length, width, area;//an integer
    int *lengthptr, *widthptr = nullptr;//a pointer

    lengthptr = &length;//assigns the length pointer with the address of the length variable
    widthptr = &width;//assigns the width pointer with the address of the width variable

    //allows user to input length of the rectangle via the pointer variable
    cout << "Enter the length of the rectangle \n";
    cin >> *lengthptr;

    //allows user to input width of the rectangle via the pointer variable
    cout << "Enter the width of the rectangle \n";
    cin >> *widthptr;

    //*lengthptr == length, *widthptr == width, area is the multiple of the pointer variables
    area = *lengthptr * *widthptr;

    //outputs area
    cout << "The area is " << area;
    
    /* These if, if else statements determine whether the length or the
    width is greater or if they are equal to each other. Accomplishes task
    by checking each relationship*/
    if(*lengthptr < *widthptr)
    {
        cout << "\nThe width is greater than the length.";
    }else if(*lengthptr > *widthptr)
    {
        cout << "\nThe length is greater than the width.";
    }else if(*lengthptr == *widthptr)
    {
        cout << "\nThe length and width are the same.";
    }
    
    return 0;
}