//message.cpp

#include <iostream>
using namespace std;

void message();

int main()
{
	message();
	return 0;
}

void message()
{
	cout << "\nThis is a recursive function.\n";
	message();
}

