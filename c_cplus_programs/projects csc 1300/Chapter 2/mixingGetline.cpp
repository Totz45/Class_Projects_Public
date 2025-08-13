//mixingGetline.cpp

#include <iostream>
using namespace std;

int main()
{
   string name;
   int age;
   string city;

   cout << "\n\nEnter your name: ";
   getline(cin, name);
   
   cout << "\n\nEnter your age: ";
   cin >> age;
   cin.ignore();
   
   cout << "\n\nEnter your city: ";
   getline(cin, city);
   
   cout << "\n\nThank You!\n\n";
   return 0;
}