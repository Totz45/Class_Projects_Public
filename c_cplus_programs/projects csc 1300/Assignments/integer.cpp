#include <iostream>
using namespace std;

int main()
{
    int number1;

    cout << "Enter a number so I can tell you if\n";
    cout << "it is odd or even.  ";
    cin >> number1;

    if (number1 % 2 == 0) {
        cout << number1 << " is even.";
    } 
    else {
        cout << number1 << " is odd.";
    }
    cout << "\n\n";
    return 0;

}