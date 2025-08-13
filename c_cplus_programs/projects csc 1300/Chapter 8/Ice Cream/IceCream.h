/*
    File Name: IceCream.h
    Author: Tate Finley
    Date: April 28th, 2022
    Purpose: Header function for program, contains class members and member functions.
*/
#ifndef ICECREAM_H
#define ICECREAM_H

#include <iostream>
#include <iomanip>
using namespace std;

class IceCream
{
    private:
        string cone;//holds type of ice cream cone
        string flavor;//holds type of ice cream flavor
        string topping;//holds type of ice cream topping
        double price;//holds ice cream price
    public:
        IceCream();//constructor
        
        //setter functions
        void SetCone(string)
        {
            cout << "Type of cone:\t";
            getline(cin, cone);
        }
        void SetFlavor(string)
        {
            cout << "What flavor?\t";
            getline(cin, flavor);
        }
        void SetTopping(string)
        {
            cout << "What topping?\t";
            getline(cin, topping);
        }
        void SetPrice(double)
        {
            cout << "Price\t\t";
            cin >> price;
        }

        //getter functions
        string GetCone() const
        {
            return cone;
        }
        string GetFlavor() const
        {
            return flavor;
        }
        string GetTopping() const
        {
            return topping;
        }
        double GetPrice() const
        {
            return price;
        }

        //prints ice cream data for a desired IceCream array element
        void printIceCream(int);

};

#endif