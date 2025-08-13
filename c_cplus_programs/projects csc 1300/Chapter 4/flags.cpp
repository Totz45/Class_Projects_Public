// This program demonstrates the logical ! operator.
#include <iostream>
using namespace std;

int main()
{
	bool salesQuotaMet = false;
	float sales;
	const float QUOTA = 15000.00;
	
	cout << "\n\nEnter in your sales: ";
	cin >> sales;
	
	if(sales >= QUOTA)
		salesQuotaMet = true;
	else
		salesQuotaMet = false;
	
	if(!salesQuotaMet)
		cout << "\nYou need to sell more stuff!!\n\n";
	else
		cout << "\nGOOD JOB! Sales quota was met!\n\n";
   
	return 0;
}