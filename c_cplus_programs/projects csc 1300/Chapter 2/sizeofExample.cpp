#include <iostream>
using namespace std;

int main()
{
    double number;
    int anotherNum;
    short aShort;
    char myChar;
    bool flag;  //boolean

    cout << "\nThe size of a double is " << sizeof(number) << " bytes.";
    cout << "\nThe size of a double is " << sizeof(double);
    cout << "\nThe size of an int is " << sizeof(anotherNum);
    cout << "\nThe size of a short is " << sizeof(aShort);
    cout << "\nThe size of an char is " << sizeof(myChar);
    cout << "\nThe size of a bool is " << sizeof(bool);
    return 0;
}