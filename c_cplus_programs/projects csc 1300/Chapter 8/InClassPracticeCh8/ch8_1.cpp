/*
    File Name: ch8_1.cpp
    Author: Tate Finley
    Date: April 18th, 2022
    Purpose: Using structures as input and output variables.
*/

#include <iostream>
#include <iomanip>
using namespace std;

struct SongData
{
    string songName; //name of song
    string songAuthor; //author of song
    double songLength; //length of song in minutes
};


int main()
{
    SongData song; //variable containing songName, songAuthor, and songLength

    //allows user to input the song name
    cout << "Enter the name of the song...  ";
    getline(cin, song.songName);

    //allows user to input the song author
    cout << "Enter the author...  ";
    getline(cin, song.songAuthor);

    //allows user to input the song length w/ two decimal points
    cout << "Enter the length of the song...  ";
    cin >> song.songLength;
    cout << fixed << showpoint << setprecision(2);

    //outputs structure members in the order that they are needed
    cout << "\n\nYour Song:\n";
    cout << "Name:\t" << song.songName << endl;
    cout << "Author:\t" << song.songAuthor << endl;
    cout << "Length:\t" << song.songLength << endl;

    return 0;

}