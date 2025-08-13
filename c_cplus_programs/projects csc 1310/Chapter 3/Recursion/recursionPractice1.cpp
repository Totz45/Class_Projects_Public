//recursionPractice1.cpp

#include <iostream>
using namespace std;
int function(int);

int main()
{
	int x = 10;
	cout << function(x) << endl;
	return 0;
}
int function (int num)
{
	cout << "VALUE OF NUM: " << num << endl;
	if(num <= 0)	//Base Case
		return 0;
	else			//Recursive Case
	{
		return function(num-1) + num;
	}
}