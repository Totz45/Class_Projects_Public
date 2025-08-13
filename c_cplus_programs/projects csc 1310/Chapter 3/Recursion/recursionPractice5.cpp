//recursionPractice5.cpp

#include <iostream>
using namespace std;
int getTotalArrayElements(int[], int);

const int SIZE = 5;

int main()
{
	int myArr[SIZE] = {7, 14, 1, 5, 3};
	
	cout << "\n\nThe total of the array elements:  ";
	cout << getTotalArrayElements(myArr,0) << endl << endl;
	
	return 0;
}

int getTotalArrayElements(int arr[], int pos)
{
	if(pos < SIZE)
	{
		return getTotalArrayElements(arr, pos+1) + arr[pos];
	}
	else
		return 0;
}
