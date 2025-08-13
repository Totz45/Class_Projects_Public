/*
    File Name: lab4a.cpp
    Author: Tate Finley
    Date: February 16th, 2022
    Purpose: Using logical operators to output a
             qualified statement.
*/

#include <iostream>
using namespace std;

int main() 
{
    int waterConsumption; //cups of water consumed
    int softDrinkConsumption; //cups of soft drink consumed

    /*Output statement asking user to input the number of
      cups of water consumed.                            */
    cout << "\nWhat is your daily water consumption?\n";
    cout << "Daily water consumption in cups:  ";
    cin >> waterConsumption;

    /*Output statement asking user to input the number of
      cups of soft drink consumed.                       */
    cout << "\nWhat is your daily soft drinks consumption?\n";
    cout << "Daily soft drinks consumption in cups:  ";
    cin >> softDrinkConsumption;

    /*executes if cups of water is less than or equal to 8
      and cups of soft drink is greater than or equal to 2*/
    if (waterConsumption <= 8 && softDrinkConsumption >= 2) {
        cout << "\nYou need to drink more water and less soft drink.";
    } 
    /*executes if cups of water is greater than 8 and 
      cups of soft drink is greater than or equal to 2  */
    else if (waterConsumption > 8 && softDrinkConsumption >= 2) {
        cout << "\nYou need to limit the amount of soft drinks you consume.\n";
        cout << "It isn't the best way to manage hydration.";
    } 
    /*executes if cups of water is less than or equal to 8
      and cups of soft drink is less than 2               */
    else if (waterConsumption <= 8 && softDrinkConsumption < 2) {
        cout << "\nYou need to be more hydrated. Drink more water.";
    } 
    /*executes if cups of water is greater than 8 and
      cups of soft drink is less than 2              */
    else {
        cout << "\nGood job. You managed it!";
    }

    return 0;

}