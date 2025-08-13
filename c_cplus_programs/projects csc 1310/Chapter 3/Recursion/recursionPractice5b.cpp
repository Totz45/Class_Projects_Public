//recursionPractice5b.cpp

#include <iostream>
using namespace std;

int getTotalArrayElements(int*, int);

const int SIZE = 5;

int main()
{
	int myArr[SIZE] = {7, 14, 1, 5, 3};
	
	cout << "\n\nThe total of the array elements:  ";
	cout << getTotalArrayElements(myArr, SIZE-1) << endl << endl;
	return 0;
}

int getTotalArrayElements(int* arr, int size)
{
	if(size > 0)
	{
		return (arr[size] + getTotalArrayElements(arr, size-1));
	}
	else
		return arr[size];
}