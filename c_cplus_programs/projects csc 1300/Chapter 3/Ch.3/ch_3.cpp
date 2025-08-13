/*
    File Name: Program_1.cpp
    Author: Tate Finley
    Date: February 9th, 2022
    Purpose: This menu based program will demonstrate the use of several 
             sub menus based on the choices the user selects or inputs.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    int optionChoice1; //main menu option
    string movie1; //names first movie
    string movie2; //names second movie
    string movieCombination; //combines movie1 and movie2 strings
    int optionChoice2; //submenu option
    int purchaseQuantity1; //quantity of first item
    int purchaseQuantity2; //quantity of second item if needed
    float purchasePrice; //total cost
    const float speakerPrice = 19.99; //set speaker price
    const float printerPrice = 44.99; //set printer price
    const float inkCartridgePrice = 14.99; //set ink cartridge price

    //execute main menu with choice
    cout << "Please choose from the following options:\n\n";
    cout << "1. Play with the movies' names\n\n";
    cout << "2. Calculate the total purchase price.\n\n";
    cout << "CHOOSE 1 or 2: ";
    cin >> optionChoice1;

    //validates choice
    if (optionChoice1 < 1 || optionChoice1 > 2) {
        cout << "\nInvalid answer,\n CHOOSE 1 or 2: ";
        cin >> optionChoice1;
    }
    
    //switch to determine path of user choice
    switch(optionChoice1) {
        
        //choice 1
        case 1:
            
            //submenu 1 is pulled up, choice can be made
            cout << "\n\nYou chose to play with the movies' names!\n\n";
            cout << "Choose from the following options:\n\n";
            cout << "1. Longest movie name\n\n";
            cout << "2. Add movies' names\n\n";
            cout << "CHOOSE 1 or 2: ";
            cin >> optionChoice2;

            //validates choice
            if (optionChoice2 < 1 || optionChoice2 > 2) {
                cout << "\nInvalid answer,\n CHOOSE 1 or 2: ";
                cin >> optionChoice2;
            }

            //submenu 1 choice 1
            if (optionChoice2 == 1) {
                //store movie name
                cout << "\nEnter a movie name: ";
                cin.ignore();
                getline(cin, movie1);

                //store another movie name  
                cout << "\nEnter another movie name: ";
                getline(cin, movie2);

                //compares movie string length    
                if (movie1 > movie2) {
                    cout << "\n\" " << movie1 << " \" is longer than \" ";
                    cout << movie2 << " \"";
                } else if (movie1 < movie2) {
                    cout << "\n\" " << movie2 << " \" is longer than \" ";
                    cout << movie1 << " \"";
                } else {
                    cout << "\n\" " << movie1 << " \" and \" ";
                    cout << movie2 << " \" are equal";
                }
            } //submenu 1 choice 2
             else {
                //user enters string preferably a movie
                cout << "\nEnter a string: ";
                cin.ignore();
                getline(cin, movie1);

                //user enters second string preferably a movie    
                cout << "\nEnter another string: ";
                getline(cin, movie2);

                //combines strings    
                movieCombination = movie1 + " and " + movie2;

                //output statement
                cout << "\nYou like to watch " << movieCombination;
                cout << ". Wow!";
            }
            break;
        //choice 2
        case 2:
            
            //submenu 2 is pulled up, user determines second choice
            cout << "\n\nYou chose to calculate the total purchase price!\n\n";
            cout << "Choose from following options, what do you want to buy:\n\n";
            cout << "1. Speakers ($19.99/each)\n\n";
            cout << "2. Printer ($44.99/each) + Ink cartridge ($14.99/each)\n\n";
            cout << "CHOOSE 1 or 2: ";
            cin >> optionChoice2;

            //validates choice
            if (optionChoice2 < 1 || optionChoice2 > 2) {
                cout << "\nInvalid answer,\n CHOOSE 1 or 2: ";
                cin >> optionChoice2;
            }

            //submenu 2 choice 1
            if (optionChoice2 == 1){
                //user enters amount to buy for speakers
                cout << "\nEnter the quantity you want to buy:  ";
                cin >> purchaseQuantity1;
                
                //determines price with apropriate decimals
                purchasePrice = purchaseQuantity1 * speakerPrice;
                cout << fixed << setprecision(2);

                //outputs total cost
                cout << "\nThe total purchase price is $";
                cout << purchasePrice;
            } //submenu 2 choice 2
            else {
                //user enters amount to buy for each product
                cout << "\nEnter the quantity of printers and ink cartridges you";
                cout << " want to buy seperated by a\nspace:  ";
                cin >> purchaseQuantity1 >> purchaseQuantity2;

                //calculation of total cost with apropriate decimals
                purchasePrice = (purchaseQuantity1 * printerPrice) + (purchaseQuantity2 * inkCartridgePrice);
                cout << fixed << setprecision(2);

                //outputs total price
                cout << "\nThe total purchase price is $";
                cout << purchasePrice;
            }        
            break;
    }
    return 0;
}