#include <iostream>
using namespace std;

int main()
{
	string name, city;
	int age;
	
	cout << "\n\nHow old are you?";
	cin >> age;
	
	cout << "\nWhat is your name?";
	getline(cin, name);
	
	cout << "\nWhat is your city?";
	getline(cin, city);
	
	cout << age << " " << name << " " << city << endl << endl;
	
	return 0;
}