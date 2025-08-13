/*
    File Name: Lab9a.cpp
    Author: Tate Finley
    Date: March 30th, 2022
    Purpose: This program uses vectors to store strings and double variables.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> itemName(0); //vector storing each item's string in an index
    vector<double> itemCost(0); //vector storing each item's cost in an index
    int i; //initializer in for loop
    string itemNameStorer; //used to store string in vector
    double itemCostStorer; //used to store item's cost in vector
    double totalCost; //running total adding up each items cost
    
    cout << "\nWelcome to the Market! \n";
    
    //obtain items and item cost from user
    for(i = 0; i <= itemName.size(); ++i)
    {
        cout << "Please enter your item: ";
        getline(cin, itemNameStorer); //retrieves an item in string form
        itemName.push_back(itemNameStorer);/*adds another index to vector so that
                                             itemNameStorer = itemName.at(i)*/

        /*if the user does not enter quit, they will be prompted
          to input the cost of the item. When quit is entered, the
          string is initialized to a index but removed from vector
          soon after.*/
        if (itemName.at(i) != "quit" && itemName.at(i) != "Quit")
        {
            cout << "Please enter your item's cost: ";
            cin >> itemCostStorer; //retrieves cost of the item
            itemCost.push_back(itemCostStorer); /*adds another index to vector so that
                                                  itemCostStorer = itemCost.at(i)*/
            cin.ignore(); //because getline function is the next to output
        } else {
            itemName.pop_back();//removes "quit" from vector
        }
        
        
    }
    
    cout << "\n\nReceipt\n";

    //prints out each item and cost
    for(i = 0; i < itemName.size(); ++i)
    {
        cout << itemName.at(i) << " " << itemCost.at(i) << endl;
    }

    //adds each item cost to total
    totalCost = 0;
    for(i = 0; i < itemName.size(); ++i)
    {
        totalCost += itemCost.at(i);
    }

    //outputs total cost for number of items purchased
    cout << "\nTotal for " << itemCost.size() << " items: " << totalCost;

    cout << "\nThank you for shopping at The Market";

    return 0;

}
