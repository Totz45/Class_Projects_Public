//scopeB.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int num = 14;

int main()
{
	cout << "\n\nThe global variable num is " << num << endl;
	int num = 10, y = 2;
	//int num = 18;

	
	cout << "\n\nThe value of num at line 11 is " << num << endl;
	
	if(num == 10)
	{
		int num = 5;
		if(num == 5)
		{
			int num = 3;
			cout << "\nThe value of num at line 22 is " << num << endl;
		}
		cout << "\nThe value of num at line 24 is " << num << endl;
	}

	cout << "\nThe value of num at line 27 is " << num << endl;
	return 0; 
}