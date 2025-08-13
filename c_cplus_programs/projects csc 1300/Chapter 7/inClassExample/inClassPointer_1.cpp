/*
    File Name: inClassPointer_1.cpp
    Author: Tate Finley
    Date: April 6, 2022
    Purpose: Learning to use pointers and pointer notation with arrays.
*/

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 10; //for array size
    string favoriteFood[SIZE]; //string array with 10 elements
    string *topFood;//pointer variable
    int i;//initializer for loop
    
    topFood = favoriteFood; //topFood points to array favoriteFood

    //allows user to enter ten foods using pointer variable in pointer notation
    for(i = 0; i < SIZE; ++i)
    {
        cout << "Enter your fav. food #" << i + 1 << endl;
        getline(cin, *(topFood + i));
    }
    
    //basic output
    cout << "\nTop Ten Favorite Foods\n";

    //outputs inputed array elements with array name in array notation
    for(i = 0; i < SIZE; ++i)
        cout << favoriteFood[i] << endl;



    return 0;
}

