#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{

	Queue<int> q(5);
	int num, choice = 0;

	while(choice != 3)
	{
		cout << "1. push, 2. pop, 3. quit: ";
		cin >> choice;

		if(choice == 1)
		{
			cout << "enter a number: ";
			cin >> num;
			q.push_back(num);
		}
		elif(choice == 2)
		{
			q.pop_front(num);
			cout << "removed " << num << endl;
		}
		else
			cout << "we're done, bye bye!\n";
	}

}