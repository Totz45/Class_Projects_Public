/*
	Title: numbersClassTempalte.cpp
	Author: April Crockett
	Date:  2019
	Purpose: demonstrate a class template
*/

#include <iostream>
using namespace std;

template<typename T>
class Numbers
{
	private:
		T number1;
		T number2;
	
	public:
		Numbers(T one, T two)
		{
			number1 = one;
			number2 = two;
		}
		T add()
		{
			return number1 + number2;
		}
		
		float average()
		{
			return ((number1 + number2) / 2.0);
		}
		
		void swap()
		{
			T temp = number1;
			number1 = number2;
			number2 = temp;
		}
		
		void print()
		{
			cout << "Number 1: " << number1 << endl;
			cout << "Number 2: " << number2 << endl;
		}
		
		T getHighest()
		{
			if(number1 > number2)
				return number1;
			else if(number2 > number1)
				return number2;
			else
				return -1;
		}
		
		T getLowest()
		{
			if(number1 < number2)
				return number1;
			else if(number2 < number1)
				return number2;
			else
				return -1;
		}
		
		void setNumberOne(T num);

		void setNumberTwo(T num)
		{
			number2 = num;
		}
		T getNumberOne()
		{
			return number1;
		}
		T getNumberTwo()
		{
			return number2;
		}

};

template <typename T>
void Numbers::setNumberOne(T num)
{
	number1 = num;
}

int main()
{	
	double num1, num2;
	
	cout << "\n\nEnter in the first floating point number.\n";
	cin >> num1;
	cout << "\n\nEnter in the second floating point number.\n";
	cin >> num2;
	
	Numbers<double> myNums(num1, num2);
	myNums.print();
	cout << "\n\nTotal:  " << myNums.add();
	cout << "\nAverage:  " << myNums.average();
	cout << "\nHighest:  " << myNums.getHighest();
	cout << "\nLowest:  " << myNums.getLowest();
	myNums.swap();
	cout << "\n\nAfter Swapping the values are...\n";
	myNums.print();
	cout << endl;
	
	int num1I, num2I;
	
	cout << "\n\nEnter in the first integer number.\n";
	cin >> num1I;
	cout << "\n\nEnter in the second integer number.\n";
	cin >> num2I;
	
	Numbers<int> myNumsI(num1I, num2I);
	myNumsI.print();
	cout << "\n\nTotal:  " << myNumsI.add();
	cout << "\nAverage:  " << myNumsI.average();
	cout << "\nHighest:  " << myNumsI.getHighest();
	cout << "\nLowest:  " << myNumsI.getLowest();
	myNumsI.swap();
	cout << "\n\nAfter Swapping the values are...\n";
	myNumsI.print();
	cout << endl;
	
	return 0;
}



