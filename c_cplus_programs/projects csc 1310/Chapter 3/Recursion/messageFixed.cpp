//messageFixed.cpp

#include <iostream>
using namespace std;

void message(int);

int main()
{
	message(3);
	
	return 0;
}

void message(int times)
{
	if(times > 0)  //recursive case
	{
		cout << "\nThis is a recursive function.\n";
		message(times-1);
	}
}

