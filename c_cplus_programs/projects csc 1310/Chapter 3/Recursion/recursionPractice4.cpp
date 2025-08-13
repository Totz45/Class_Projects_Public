//recursionPractice4.cpp

#include <iostream>
using namespace std;
void sign(int);

int main()
{
	int number;
	cout << "Enter an integer and I will display a sign:  ";
	cin >> number; //pretend user enters 5
	sign(number);
	return 0;
}
void sign(int n)
{
	if(n > 0)
	{
		cout << "Do you need a hug?\n";
		sign(--n);
	}
}

