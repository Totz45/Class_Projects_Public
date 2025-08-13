/*
	Title: whileExample_6.cpp
	Author: April R Crockett
	Date: February 9, 2009
	Purpose:  use a while loop to validate input
*/

#include <iostream>
using namespace std;

int main()
{
	double balance, income, debit;
	int choice;
	double groceries=0, gas=0, dining=0, doctor=0, entertain=0, carPayment=0, mortgage=0, ccPayment=0;
	int counter=0;
	
	cout <<"\nEnter your Monthly income: ";
	cin >> income;
	
	balance = income;
	
	while (balance > 0)  //using a while loop to repeat several programming statements
	{
		cout << "Pick a category for your purchase\n";
		cout << "1.  Grocery Item\n";
		cout << "2.  Gas\n";
		cout << "3.  Dining Out \n";
		cout << "4.  Doctor / Medicine \n";
		cout << "5.  Entertainment \n";
		cout << "6.  Vehicle payments \n";
		cout << "7.  Mortgage \n";
		cout << "8.  Credit Card / Loan payments \n\n";
		cout << "Choose a number: ";
		cin >> choice;
		
		while (choice < 1 || choice > 8)  //Using a while loop for validating user input
		{
			cout << "You did not enter an appropriate response.\n";
			cout << "Choose a number between 1 & 8.\n";
			cout << "Choose a number: ";
			cin >> choice;
		}
		
		switch(choice)
		{
			case 1: 	cout << "\nEnter in the amount of your grocery purchase: ";
						cin >> debit;
						groceries = groceries + debit;
						balance = balance - debit;
						counter++; //increment counter
						if (balance < 0)
						{
							cout << "\nYou are trying to spend more money than your income.\n";
							groceries = groceries + balance;
						}
						break;
			case 2:		cout << "\nEnter in the amount of your gas purchase: ";
						cin >> debit;
						gas = gas + debit;
						balance = balance - debit;
						if (balance < 0)
						{
							cout << "\nYou are trying to spend more money than your income.\n";
							gas = gas + balance;
						}
						break;
			case 3:		cout << "\nEnter in the amount you spent while dining out: ";
						cin >> debit;
						dining = dining + debit;
						balance = balance - debit;
						if (balance < 0)
						{
							cout << "\nYou are trying to spend more money than your income.\n";
							dining = dining + balance;
						}
						break;
			case 4:		cout << "\nEnter in the amount you spent on doctor's fees and medicine: ";
						cin >> debit;
						doctor = doctor + debit;
						balance = balance - debit;
						if (balance < 0)
						{
							cout << "\nYou are trying to spend more money than your income.\n";
							doctor = doctor + balance;
						}
						break;
			case 5:		cout << "\nEnter in the amount you spent on entertainment (movies, books, etc.): ";
						cin >> debit;
						entertain = entertain + debit;
						balance = balance - debit;
						if (balance < 0)
						{
							cout << "\nYou are trying to spend more money than your income.\n";
							entertain = entertain + balance;
						}
						break;
			case 6:		cout << "\nEnter in the amount you spent on your vehicle payment: ";
						cin >> debit;
						carPayment = carPayment + debit;
						balance = balance - debit;
						if (balance < 0)
						{
							cout << "\nYou are trying to spend more money than your income.\n";
							carPayment = carPayment + balance;
						}
						break;
			case 7:		cout << "\nEnter in the amount you spent on your Home Mortgage: ";
						cin >> debit;
						mortgage = mortgage + debit;
						balance = balance - debit;
						if (balance < 0)
						{
							cout << "\nYou are trying to spend more money than your income.\n";
							mortgage = mortgage + balance;
						}
						break;
			case 8:		cout << "\nEnter in the amount you spent on your credit card / loan payments: ";
						cin >> debit;
						ccPayment = ccPayment + debit;
						balance = balance - debit;
						if (balance < 0)
						{
							cout << "\nYou are trying to spend more money than your income.\n";
							ccPayment = ccPayment + balance;
						}
		}//end of switch
			
	}
	
	cout << "Your budget for this month:\n\n";
	cout << "INCOME:  " << income << endl;
	cout << endl;
	cout << "DEBITS:\n";
	cout << "\tGroceries: " << groceries << " (making " << counter << " trips to the grocery store.)";
	cout << "\n\tGas: " << gas;
	cout << "\n\tDining Out: " << dining;
	cout << "\n\tDoctor/Medicine: " << doctor;
	cout << "\n\tEntertainment: " << entertain;
	cout << "\n\tCar Payments: " << carPayment;
	cout << "\n\tMortgage Payment: " << mortgage;
	cout << "\n\tCredit Cards/Loans: " << ccPayment;
	cout << endl;
	
	return 0;
}
