/* 
    File Name: lab_2b.cpp
    Author: Tate Finley
    Date: February 2nd, 2022
    Purpose: This program uses an item's name, quantity, and price to
             calculate the total cost, with tax, of an order typically
             made at a grocery store.
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string itemName1; //name of 1st item in string form
    float itemNumber1; //quantity of 1st item in string form
    float itemPrice1; //price of 1st item in string form
    
    string itemName2; //name of 2nd item 
    float itemNumber2; //quantity of 2nd item
    float itemPrice2; //price of 2nd item

    float totalPrice; //price of all items bought
    const float salesTax = 0.0975; //tax on items

    //user inputs name of first item
    cout << "\nPlease input the name of the first item:  ";
    getline (cin, itemName1);

    //user inputs the quantity they want to buy of the first item
    cout << "Please input the number of " << itemName1;
    cout << " bought:  ";
    cin >> itemNumber1;

    //user inputs the price for one of the first item
    cout << "Please input the price of " << itemName1;
    cout << ":  $";
    cin >> itemPrice1;    
    cout << "\n\n";
    
    
    //user inputs name of second item
    cout << "Please input the name of the second item:  ";
    cin.ignore();
    getline (cin, itemName2);

    //user inputs the quantity they want to buy of the second item
    cout << "Please input the number of " << itemName2;
    cout << " bought:  ";
    cin >> itemNumber2;

    //user inputs the cost for one of the second item
    cout << "Please input the price of " << itemName2;
    cout << ":  $";
    cin >> itemPrice2;    
    cout << "\n";

    //Calculation of total cost based of price, quantity, and tax
    cout <<	setprecision(2) << fixed << showpoint;
    totalPrice = (itemNumber1 * itemPrice1) + (itemNumber2 * itemPrice2);
    totalPrice = totalPrice + (totalPrice * salesTax);

    //Output of the calculation
    cout << "The total bill is $" << totalPrice << ".\n";

    return 0;
}