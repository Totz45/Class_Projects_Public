#include <iostream>
using namespace std;

int main()
{
	int humps = 0;
	
	while(humps < 5)
	{
		int cow = 1;
		humps++;
		cout << "\nAlice the camel has " << humps << " humps.";
		cout << "\nThere is always " << cow << " cow.";
	}
	
	cout << "\nThere is still only " << cow << " cow.";
	
	return 0;
}