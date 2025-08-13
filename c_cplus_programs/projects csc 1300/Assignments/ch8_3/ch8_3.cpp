/*
    File Name: ch8_3.cpp
    Author: Tate Finley
    Date: April 22, 2022
    Purpose: Dynamic Memory Allocation of an array of structures.
*/
#include <iostream>
using namespace std;

const int SIZE = 5;//size of array

struct Phone 
{
    string type;//type of phone
    string color;// color of phone
    int memory;//memory capacity of phone
};

void addPhone(Phone *);
void printArray(Phone *);

int main()
{
    Phone* phoneData;//pointer variable of type Phone(structure)
    phoneData = new Phone[SIZE];//dynamically allocating an array of Phone

    addPhone(phoneData);// call function

    printArray(phoneData);// call function

    delete [] phoneData;//delete dynamically allocated array
    
    return 0;
}
/*
    Function Name: addPhone()
    Parameters: pointer to Phone array
    Returns: none
    Purpose: read the data of each user's phone and place it in the
             correct location in the array.
*/
void addPhone(Phone *ptr)
{
    for(int i = 0; i < SIZE; ++i)
    {
        cout << "\nEnter data for phone number " << i + 1 << endl;
        
        cout << "What phone do you have?\n";
        getline(cin, ptr[i].type);
        
        cout << "What color is it?\n";
        getline(cin, ptr[i].color);
        
        cout << "What is the capacity of the phone (in GB)?\n";
        cin >> ptr[i].memory;
        cin.ignore();
    }
}
/*
    Function Name: printArray()
    Parameters: pointer to Phone array
    Returns: none 
    Purpose: prints all of the data from the array. 
*/
void printArray(Phone *result)
{
    for(int i = 0; i < SIZE; ++i)
    {
        cout << endl;
        cout << "Phone:\t\t" << result[i].type << endl;
        cout << "Color:\t\t" << result[i].color << endl;
        cout << "Capacity:\t" << result[i].memory << " GB" << endl;
    }
}