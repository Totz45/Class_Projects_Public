/*
	Title: nestedExample_2.cpp
	Author: April Crockett
	Date:  February 15, 2009
	Purpose:  Nested loops in C++
*/

#include <iostream>

using namespace std;

int main()
{
	int students, classes, hours, totalHours = 0;

	cout << "Enter the number of students.\n";
	cin >> students;

	for (int x = 1; x <= students; x++)
	{
		cout << "Student " << x << ", How many classes do you have?\n";
		cin >> classes;

		for(int y = 1; y <= classes; y++)
		{
			cout << "How many hours is class " << y << "?\n";
			cin >> hours;
			totalHours += hours;
		}
	}

	cout << "The total number of class hours taken "
	     << "by all students is " << totalHours;
	
	return 0;	
}

