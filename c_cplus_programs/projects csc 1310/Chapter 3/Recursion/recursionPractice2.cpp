//recursionPractice2.cpp
#include <iostream>
using namespace std;
void function(int);
int main()
{
	int x = 5;
	function(x);//makes a right triangle of asterisks
	return 0;
}

void function (int num)
{
	if(num > 0) //recursive case
	{
		for (int x=0; x<num; x++)
			cout << '*';
		cout << endl;
		function(num-1);
	}
}


