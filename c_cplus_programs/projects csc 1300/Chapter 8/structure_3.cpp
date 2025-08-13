/*
	Title:  structure_3.cpp
	Author:  April Crockett
	Date:  8/15/2017
	Purpose:  demonstrate a structure definition, defining a structure
				variable, and accessing structure members.
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct PayRoll
{
    int empNumber;
    string name;
    double hours;
    double payRate;
    double grossPay;
};  

int main()
{
    PayRoll employee;
    cout << "\nEnter employee\'s number: ";
    cin >> employee.empNumber;
	 
    cout << "\nEnter employee\'s name: ";
    cin.ignore();  //skip \n
    getline(cin, employee.name);
	
    cout << "\nHow many hours did the employee work?";
    cin >> employee.hours;
    
	cout << "\nWhat is the employee\'s pay rate?";
    cin >> employee.payRate;

    employee.grossPay = employee.hours * employee.payRate;

    //Display employee data
    cout << "\nNUMBER:\t\t" << employee.empNumber << endl;
	cout << "NAME:\t\t"	<< employee.name << endl;
	cout << "HOURS:\t\t"	<< employee.hours << endl;
	cout << "PAYRATE:\t" << employee.payRate << endl;
	cout << "GROSS PAY:\t" << employee.grossPay << endl;

    return 0;
}
