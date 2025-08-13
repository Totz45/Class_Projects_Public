//factorialWithoutRecursion.cpp

//find the factorial of a number entered by the user.
#include <iostream>
using namespace std;

int factorial(int);

int main()
{
	int num;
	cout << "\n\nEnter an integer and I will find the factorial:  ";
	cin >> num;
	cout << endl;
	cout << factorial(num);	
	return 0;
}
int factorial(int n)
{
	int fac = 1;
	if(n == 0)
		return fac;
	else
	{
		for(int x=1; x<=n; x++)
		{
			fac *= x; 
		}
	}
	return fac;
}













