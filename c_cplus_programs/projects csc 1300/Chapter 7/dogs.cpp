#include <iostream>
using namespace std;

int main()
{
	int numStudents;
	int* myArray;
	int totalDogs = 0;
	
	cout << "\nHow many students are in the class?\n";
	cin >> numStudents;
	
	myArray = new int [numStudents];
	
	cout << "How many dogs will each student adopt in the next five years?\n";
	for(int i = 0; i < numStudents; i++)
	{
		cout << "\nSTUDENT " << i+1 << ":  ";
		cin >> *(myArray+i);
		totalDogs += *(myArray+i);
	}
	
	cout << "The total number of dogs adopted is " << totalDogs << endl;
	
	delete [] myArray;
	
	return 0;
}