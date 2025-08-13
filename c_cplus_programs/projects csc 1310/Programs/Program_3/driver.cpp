/*
	File Name: Driver.cpp
	Author: Tate Finley
	Date: 11/6/22
	Purpose: This program allows a user to create an account, login into a
			 account and delete an account.
*/

#include <iostream>
#include <fstream>
#include "sha256.h"
#include "hashTable.h"
//include your hash table---------------------------------------------------------------------------------------------------

using namespace std;

int main()
{
	
	ifstream file("testlist.txt");
	int menuChoice;
	int numUsers;
	string user, pwd, salt;
	string username, password;
	string passwordSalt, hashPassword;//new password after appending salt and hashing
	hashTable* universalHashTable;//hashTable for program
	
	if(file.is_open()) {
	file >> numUsers;
	file.ignore(1, '\n');
	//dynamically allocate your hash table-------------------------------------------------------------------------------
	universalHashTable = new hashTable(numUsers);

	while(getline(file, user))
	{
		getline(file, pwd);
		//generate a salt and add the new user to your table--------------------------------------------------------
		salt = (*universalHashTable).generateSalt();
		passwordSalt = pwd.append(salt);//append salt to end of password
		hashPassword = sha256(passwordSalt);//hash password
		universalHashTable->addEntry(user, hashPassword, salt);//add the entry
		
	}}

	do
	{
		cout << "\nWhat would you like to do?\n";
		cout << "1.  Login.\n";
		cout << "2.  Create account.\n";
		cout << "3.  Delete account.\n";
		cout << "4.  Exit.\n";
		cout << "CHOOSE 1-4:  ";
		cin >> menuChoice;
		while(menuChoice < 1 || menuChoice > 4)
		{
			cout << "That is not a valid choice.\n";
			cout << "CHOOSE 1-4:  ";
			cin >> menuChoice;
		}
		
		switch(menuChoice)
		{
			case 1:	cout << "enter your username:  ";
					cin >> username;
					cout << "enter your password:  ";
					cin >> password;

					
					salt = universalHashTable->getSalt(username);//retrieve salt
					passwordSalt = password.append(salt);//append salt
					hashPassword = sha256(passwordSalt);//hash password
					if(universalHashTable->validateLogin(username, hashPassword))//check if the user's credentials are correct-----------------------------------
						cout << "login successful\n";
					else
						cout << "invalid credentials\n";
					
					break;
					
			case 2: cout << "enter your new username:  ";
					cin >> username;
					cout << "enter your new password:  ";
					cin >> password;
					
					//generate a salt for the new user and add the user to the table--------------------
					salt = universalHashTable->generateSalt();
					passwordSalt = password.append(salt);//append salt to password
					hashPassword = sha256(passwordSalt);//hash password
					universalHashTable->addEntry(username, hashPassword, salt);

					break;
					
			case 3:	cout << "enter your username:  ";
					cin >> username;
					cout << "enter your password:  ";
					cin >> password;

					salt = universalHashTable->getSalt(username);//get the salt for the user
					passwordSalt = password.append(salt);//append salt to password
					hashPassword = sha256(passwordSalt);//hash password
					
					if(universalHashTable->removeUser(username, hashPassword))//remove the user from the table and check if they were removed successfully----
						cout << "user removed successfully.\n";
					else
						cout << "invalid credentials, cannot remove user.\n";
					break;
					
			case 4:	cout << "goodbye" << endl;
					//delete the hash table-------------------------------------------------------------
					delete universalHashTable;
					break;
					
		}
		
	} while(menuChoice != 4);

	return 0;
}