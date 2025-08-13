/*
	Title:  Lab2.cpp
	Author: Tate Finley
	Date:  8/30/22
	Purpose:  To demonstrate the use of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				cout << "\nThe sum of the numbers for that value is " << sumOfNumbers(num);
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				if (isMember(myArray, num, ARRAY_SIZE) == true)
				{
					cout << "\n" << num << " is in the array.";
				}
				else
				{
					cout << "\n" << num << " is not in the array. Sorry!";
				}
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				stringReverser(userString, userString.size());
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				if(isPalindrome(userStrModified))
				{
					cout << "\nYes! " << userStrModified << " is a palindrome.";
				} else
				{
					cout << "\nNo, " << userStrModified << " is not a palindrome.";
				}

				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << "The value of " << num1 << " x " << num2;
				cout << " is " << multiply(num1, num2);
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}

/*
	Function Name: sumOfNumbers()
	Function Purpose: This function returns the sum of all the 
	integers from 1 up to the number passed as an argument.
	Parameters: an integer 
	Returns: an integer containing the sum of all integers up to
	the number passed as an argument.
*/
int sumOfNumbers(int sumNum)
{
	if (sumNum == 0)
	{
		return sumNum;
	}
	else
	{
		return sumNum + sumOfNumbers(sumNum - 1);
	}
}
/*
	Function Name: isMember()
	Function Purpose: The function searches the array passed on as an
	argument to find if the value matches one of the elements in the array.
	Returns a boolean function whether it was successfully found or not.
	Parameters: pointer to an array, and two integers, one containing the size
	of the array.
	Returns: a boolean function, true if value was found, false if value was not
	found.
*/
bool isMember(int* array, int value, int arraySize)
{
	
	if (value == array[arraySize - 1])
	{
		return true;
	}
	else if (array[arraySize - 1] == array[0])
	{
		return false;
	}
	else
	{
		return isMember(array, value, arraySize - 1);
	}
}

/*
	Function Name: stringReverser()
	Function Purpose: This function reverses the letters in a given
	string and outputs them.
	Parameters: a string, and an integer with the length of the string
	Returns: None
*/
void stringReverser(string stringName, int length)
{
	if (length == 0)
	{
		return;
	}
	else
	{
		cout << stringName[length - 1];
		stringReverser(stringName, length - 1);
	}
}

/*
	Function Name: isPalindrome()
	Function Purpose: This function compares the first and last characters in the string 
	then deletes both characters, it uses a recursive function to retreive the next two letters
	on each end of the string. If at any point the string size reaches zero or the first and last
	letters don't match, the function returns a boolean statement.
	Parameters: a string
	Returns: a boolean variable based on if the string is a palindrome.
*/
bool isPalindrome(string stringName)
{
	if ((stringName.size() - 1) == 0 || stringName.size() == 0)
	{
		return true;
	}
	else if(stringName[0] == stringName[stringName.size() - 1])
	{
		stringName.erase(stringName.size() - 1, 1);
		stringName.erase(0, 1);
		return isPalindrome(stringName);
	}
	else
	{
		return false;
	}
}

/*
	Function Name: multiply()
	Function Purpose: This function uses recursive addition to solve a multiplication
	problem. 
	Parameters: two integers
	Returns: an integer representing the product of the two integers.
*/
int multiply(int x, int y)
{
	if (x - 1 == 0)
	{
		return y;
	}
	else
	{
		return y + multiply(x - 1, y);
	}
}

