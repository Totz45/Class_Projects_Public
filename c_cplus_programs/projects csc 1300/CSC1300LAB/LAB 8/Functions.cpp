/*
    File Name: Functions.cpp
    Author: Tate Finley
    Date: March 23, 2022
    Purpose: This program defines the functions found in Driver.cpp
*/

#include "Elephant.h"

/*
    Function Name : getElephantData()
    Parameters: float array for elephant food amounts, string array for elephant names
    Returns: void
    Purpose: allows the user to enter in each of the 10 elephant’s names and 
             the amount of food that each elephant eats
*/
void getElephantData(float elephantFood[SIZE], string elephantName[SIZE])
{
    int i; //served for initialization and index number

    //asks for user input
    cout << "\n\nEnter the name and how many pounds of food each elephant ate last month.\n";

    //for loop that allows 10 elephants to be named and detailed
    for(i = 0; i < SIZE; ++i) 
    {
        char elephantNames[100]; //allows each index to carry a string rather than a character
        cout << "ELEPHANT " << i + 1 << ": \n";
        cout << "\tNAME - ";
        cin.getline (elephantNames, 100); //retrieve string
        elephantName[i] = elephantNames; //assigns array index with inputed string
        cout << "\tFOOD AMOUNT - ";
        cin >> elephantFood[i];
        cin.ignore();
    }


}

/*
    Function Name : getStats()
    Parameters: float array for elephant food amounts, string array for elephant names.
                2 floats passed by reference to store average and total food amounts, 1
                int passed by reference serving as the index of the elephant who ate the most
    Returns: void
    Purpose: finds the average and total amount eaten by the elephants, then the index of the
             elephant with the largest consumption
*/
void getStats(float elephantFood[SIZE], string elephantName[SIZE], float& totalFood, float& averageFood, int& biggestConsumption)
{
    int i;//used as initialization and index
    
    //initialization and for loop to calculate total amount of food eaten
    totalFood = elephantFood[0];
    for(i = 1; i < SIZE; ++i)
    {
        totalFood += elephantFood[i];//running total
    }

    averageFood = totalFood / SIZE; //calculation for average food eaten by an elephant

    //calculation for the index of the elephant who consumed the most
    biggestConsumption = 0;
    for(i = 1; i < SIZE; ++i)
    {
        if(elephantFood[i] > elephantFood[biggestConsumption])
        {
            biggestConsumption = i;
        }
    }
}