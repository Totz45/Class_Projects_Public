#include <iostream>
using namespace std;

int main()
{
	char name[30] = "CHARLIE";
	string anotherName = "RALPH";
	
	//print out the names
	cout << name << endl;
	cout << anotherName << endl;
	
	//ask user for names (with whitespace)
	cout << "What is your name?\n";
	cin.getline(name, 30);
	
	cout << "What is another name?\n";
	getline(cin, anotherName);
	
	//print out the names
	cout << name << endl;
	cout << anotherName << endl;
	
	//assign names to the strings
	//name = "BARTLET";  //THIS WON't WORK SO WHAT SHOULD I DO?
	anotherName = "GEORGE";
	
	//print out the names with loop
	int x=0;
	while(name[x] != '\0')
	{
		cout << name[x] << "     ";
		x++;
	}
	cout << endl;
	x=0;
	while(anotherName[x] != '\0')
	{
		cout << anotherName[x] << "     ";
		x++;
	}
	
	return 0;
}