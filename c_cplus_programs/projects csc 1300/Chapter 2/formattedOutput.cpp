/*
	Title:  formattedOutput.cpp
	Author: April R. Crockett
	Date:  January 27, 2009
	Purpose:  A C++ programm to demonstrate formatted input & output
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double origHouseValue, houseValue ;
	double origHouseTax, houseTax;
	int year = 2008;

	cout << "\nIf the value of a house appreciates by 10% every year,\n";
	cout << "and the yearly taxes increase by 2% every year, what will\n";
	cout << "the value of a house and the taxes be after 10 years?\n\n";

	cout << "Enter the value of your house in 2008: ";
	cin >> origHouseValue;
	houseValue = origHouseValue;

	cout << "\nEnter your 2008 property tax: ";
	cin >> origHouseTax;
	houseTax = origHouseTax;

	cout << "The following is what I predict your house value and\n";
	cout << "property tax will look like in future years.\n\n";

	cout << setw(4)<<"Year"<<setw(5)<<""<<setw(11)<<"House Value"<<setw(5)<<"";
	cout << setw(12) << "Property Tax\n";


	cout << setprecision(2) << fixed << showpoint;	

	cout << setw(4)<<year<<setw(5)<<""<<"$"<<setw(10)<<houseValue<<setw(5)<<"";
	cout << "$" << setw(11) << houseTax << endl;

	while (year < 2018)
	{
		//make calculations for the next year
		houseValue = houseValue * 1.10;
		houseTax = houseTax * 1.02;
		year++;

		//print out the next year
		cout << setw(4) << year << setw(5) << "" << "$" << setw(10) << houseValue;
		cout << setw(5) << "" << "$" << setw(11) << houseTax << endl;
	}

	cout << "\nThe value of your property will change by $";
	cout << (houseValue - origHouseValue);
	cout << "\nHowever, your taxes will be increased by $";
	cout << (houseTax - origHouseTax) << "\n\n";

	return 0;
}