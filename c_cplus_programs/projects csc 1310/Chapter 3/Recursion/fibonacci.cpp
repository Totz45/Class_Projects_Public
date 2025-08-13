/*
	Title:  fibonacci_dp.cpp
	Author:  April Crockett
	Date:  11/1/2018
	Purpose:  Demonstrate fibonacci numbers (simple recursive solution)
*/
#include <iostream>
using namespace std;

int fib(int);

const int SIZE = 300;
int main()
{
	cout << "The first " << SIZE << " Fibonacci numbers are:\n";
	for (int x = 1; x < SIZE; x++)
		cout << fib(x) << " ";
	cout << endl;
	return 0;
}

int fib(int n)
{
	//if (n <= 0)
	//	return 0;                       // Base case
	if (n == 1 || n == 2)
		return 1;                       // Base case
	else
		return fib(n - 1) + fib(n - 2); // Recursive case
}




