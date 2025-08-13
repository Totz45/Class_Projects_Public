#include "sort.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	int size = 13;
	int array[size] = {25, 8, 87, 61, 16, 27, 56, 99, 43, 28, 53, 73, 81};
	 
	//bubbleSort(array, size);
	//insertionSort(array, size);
	//quickSort(array, 0, size);
	
	for(int x=0; x < size; x++)
	{
		cout << array[x] << ", ";
	}
	cout << endl;
	
	return 0;
}
