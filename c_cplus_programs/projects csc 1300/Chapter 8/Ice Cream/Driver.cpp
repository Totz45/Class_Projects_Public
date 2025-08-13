/*
    File Name: Driver.cpp
    Author: Tate Finley
    Date: April 28th, 2022
    Purpose: Main function for program. Asks for ice cream details and outputs them.
*/
#include "IceCream.h"

int main()
{
    string iceCreamCone;//cone of ice cream
    string iceCreamFlavor;//flavor of ice cream
    string iceCreamTopping;//topping of ice cream
    double iceCreamPrice;//price of ice cream
    int iceCreamCount;//amount of ice cream
    int i;//serves as a way to access an array element
    
    //asks for number of ice cream
    cout << "\nHow many ice creams would you like?\n";
    cin >> iceCreamCount;
    
    //dynamically allocating a pointer to the IceCream array
    IceCream * iceCreamPtr;
    iceCreamPtr = new IceCream[iceCreamCount];

    //acquires data for the IceCream array
    for(i = 0; i < iceCreamCount; ++i)
    { 
        cout << "\nEnter the data for ice cream " << i + 1 << ":\n\n";
        cin.ignore();
        iceCreamPtr[i].SetCone(iceCreamCone);
        iceCreamPtr[i].SetFlavor(iceCreamFlavor);
        iceCreamPtr[i].SetTopping(iceCreamTopping);
        iceCreamPtr[i].SetPrice(iceCreamPrice);
    }

    //output statement
    cout << "\nYOUR ICE CREAM ORDER:\n";
    cout << fixed << showpoint << setprecision(2);

    //print the details for each ice cream
    for(i = 0; i < iceCreamCount; ++i)
    {
        iceCreamPtr[i].printIceCream(i);
        cout << "Cone:\t\t" << iceCreamPtr[i].GetCone() << endl;
        cout << "Flavor:\t\t" << iceCreamPtr[i].GetFlavor() << endl;
        cout << "Topping:\t" << iceCreamPtr[i].GetTopping() << endl;
        cout << "Price:\t\t" << iceCreamPtr[i].GetPrice() << endl;
    }

    //deletes the pointer to the IceCream array along with its elements
    for(i = 0; i < iceCreamCount; ++i)
    {
        delete [] iceCreamPtr;
    }

    return 0;
}