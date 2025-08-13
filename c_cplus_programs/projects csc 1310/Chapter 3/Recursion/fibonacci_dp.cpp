/*
	Title:  fibonacci_dp.cpp
	Author:  April Crockett
	Date:  11/1/2018
	Purpose:  Demonstrate dynamic programming with fibonacci numbers
*/

#include <iostream>
using namespace std;

int fib(int, int*);
const int SIZE = 300;
int main()
{
	int memo[SIZE] = {0};
	cout << "The first " << SIZE << " Fibonacci numbers are:\n";
	for (int x = 1; x < SIZE; x++)
		cout << fib(x, memo) << " ";
	cout << endl;
	return 0;
}

int fib(int n, int *memo)
{
	int result;
	if(memo[n] != 0)					// BASE CASE 
		return memo[n];
	if (n == 1 || n == 2)
		result = 1;                       // BASE CASE
	else
		result = fib(n - 1, memo) + fib(n - 2, memo); // Recursive case
	memo[n] = result;
	return result;
}




