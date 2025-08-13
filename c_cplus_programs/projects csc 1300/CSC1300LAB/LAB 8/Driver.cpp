/*
    File Name: Driver.cpp
    Author: Tate Finley
    Date: March 23, 2022
    Purpose: This is the main program, its purpose is to obtain information
             in order to calculate which elephant ate the most, what was the
             total that all of the elephants have eaten and the average amount
             an elephant eats at the user's defined zoo.
*/

#include "Elephant.h"

int main() 
{
    float foodTotal; //holds total for food consumption by all elephants
    float foodAverage; //holds average for food consumption by an elephant
    int largestElephantConsumption; //serves as the index of the elephant who consumes the most
    char zooName[100]; //stores the name of the zoo in 100 characters or less.
    string elephantName[SIZE]; //stores elephant names
    float elephantConsumption[SIZE]; //stores elephant consumption

    //retrieves zoo name from user.
    cout << "\nHello! What is the name of your elephant zoo?\n";
    cin.getline(zooName, 100);
    
    //go to functions.cpp for more info, string and float array sent here.
    getElephantData(elephantConsumption, elephantName);
    
    /*go to functions.cpp for more info, string and float array sent here.
      everything else BUT the character array is passed by reference*/
    getStats(elephantConsumption, elephantName, foodTotal, foodAverage, largestElephantConsumption);

    /* Prints out total amount consumed, average amount consumed, and the elephant
       who ate the most separated by dashes in the user's zoo*/
    cout << endl;
    cout << setfill('-') << setw(50) << " ";
    cout << "\nThe total amount of food consumed by all 10 elephants at ";
    cout << zooName << " is " << foodTotal << " pounds in one month.";
    cout << endl;
    cout << "\nThe average amount of food consumed at " << zooName;
    cout << " is " << foodAverage << "pounds." << endl;
    cout << "\n\nThe elephant who eats the most (" << elephantConsumption[largestElephantConsumption];
    cout << " pounds) is " << elephantName[largestElephantConsumption] << "!!\n";
    cout << setfill('-') << setw(50) << " ";
    

    return 0;
}