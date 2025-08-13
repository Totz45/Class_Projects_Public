/*
	File Name: hashTable.cpp
	Author: Tate Finley
	Date: 11/6/22
	Purpose: Function defintions for hashTable class
*/
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"
using std::string;
using std::cout;

/*
	Function Name: hashTable()
	Purpose: constructor function for class
*/
hashTable::hashTable(int size)
{
	//you need to add everything else that belongs in the constructor--------------------------------------
	tableSize = size;
	hashArray = new entry*[tableSize];//DA an array of entry pointers
	//initialize each element
	for(int i = 0; i < tableSize; i++)
	{
		hashArray[i] = NULL;
	}
	srand (time(0));	//this needs to be in the constructor, otherwise every user gets the same salt
}

/*
	Function Name: ~hashTable()
	Purpose: destructor function for class
*/
hashTable::~hashTable()
{
	//go through buckets to delete every entry in them
	for(int i = 0; i < tableSize; i++)
	{
		if(hashArray[i] != NULL)
		{
			entry* prevEntry = NULL;
			entry* currEntry = hashArray[i];
			while(currEntry != NULL)
			{
				prevEntry = currEntry;
				currEntry = currEntry->next;
				delete prevEntry;
			}
		}
	}
	//delete the array
	delete [] hashArray;
}

/*
	Function Name: getSalt()
	Purpose: get the salt from a given user
	Parameters: a string with the username
	Returns: a string which is the salt for the user
*/
string hashTable::getSalt(string username)
{
	entry* user = getEntry(username);//get the entry for the user

	if(!user)
	{
		//indicate that user can't be found
		cout << "Sorry, could not find user...\n";
		string salt = generateSalt();
		return salt;//return a salt different from the user salt
	} else
	{
		return (*user).getSalt();//call function in entry class
	}
	
}

/*
	Function Name: validateLogin()
	Purpose: validate if the user input and the corresponding entry match.
	Parameters: two strings, the username and password
	Returns: a boolean indicating if the password matches the entry.
*/
bool hashTable::validateLogin(string userName, string password)
{
	entry* findEntry;//accessor to entry functions
	findEntry = getEntry(userName);//get the entry for the user
	//see if the password matches
	if(password == findEntry->getHashedpwd())
	{
		return true;
	} else
	{
		return false;
	}
}
		
/*
	Function Name: removeUser()
	Purpose: remove a user provided they entered the correct username and password
	Parameters: two strings, a username and a password
	Returns: a boolean, indicating if the user was deleted
*/
bool hashTable::removeUser(string userName, string password)
{
	entry* deleteEntry;//entry pointer for the entry being deleted
	entry* prevEntry;//the deleted entry's previous entry
	
	int bucketIndex = hash(userName);//hash to find bucket
	//check bucket
	if(hashArray[bucketIndex] != NULL)
	{
		//manually find the entry
		prevEntry = NULL;
		deleteEntry = hashArray[bucketIndex];
		while(deleteEntry->next != NULL & deleteEntry->getUsername() != userName)
		{
			prevEntry = deleteEntry;
			deleteEntry = deleteEntry->next;
		}
		//verify username
		if(deleteEntry->getUsername() == userName)
		{
			//verify password
			if(deleteEntry->getHashedpwd() == password)
			{
				//delete entry based on where it is in the chain of linked lists
				if(prevEntry == NULL)
				{
					entry* nextEntry = deleteEntry->next;
					delete deleteEntry;
					hashArray[bucketIndex] = nextEntry;
					return true;
				} else
				{
					entry* nextEntry = deleteEntry->next;
					delete deleteEntry;
					prevEntry->next = nextEntry;
					return true;
				}
			} else
			{
				return false;
			}
		} else
		{
			return false;
		}
	} else
	{
		return false;
	}
	
}

/*
	Function Name: addEntry()
	Purpose: add an entry and store the entry in the corresponding bucket
	Parameters: three strings, the username, password, and the salt for the user
	Returns: None
*/
void hashTable::addEntry(string userName, string hashPassword, string salt)
{
	entry* newEntry;//create new entry
	newEntry = new entry(userName, hashPassword, salt);//Allocate memory for entry
	
	int bucketIndex = hash(userName);//find bucket
	//check bucket contents
	if(hashArray[bucketIndex] == NULL)
	{
		//if empty, new entry can be stored in bucket
		hashArray[bucketIndex] = newEntry;
	} else
	{
		//undergo the process of chaining to find empty entry in bucket
		entry* linkEntry = hashArray[bucketIndex];
		while(linkEntry->next != NULL)
		{
			linkEntry = linkEntry->next;
		}if(linkEntry->getUsername() == userName)
		{
			cout << "Sorry, that user already exists\n";
		}else 
		{
			//assign entry to list in bucket
			linkEntry->next = newEntry;
		}
	}	
		
}

/*
	Function Name: getEntry()
	Purpose: retrieve the entry for a given user
	Parameters: a string which is the key we are looking for
	Returns: pointer to the associated entry
*/
hashTable::entry* hashTable::getEntry(string key)
{
	int bucketIndex = hash(key);//find bucket
	//search bucket for user
	if(hashArray[bucketIndex] == NULL)
	{
		return NULL;
	} else
	{
		entry* entryName = hashArray[bucketIndex];
		while(entryName != NULL && entryName->getUsername() != key) 
		{
			entryName = entryName->next;
		}
		if(entryName == NULL)
		{
			return NULL;
		} else
		{
			//if the user is found, return the entry
			return entryName;
		}
	}
}


//don't touch this!
int hashTable::hash(string key)
{
	int sum = 0;
	for(int i = 0; i < key.size(); i++)
		sum += key[i];
	
	return sum % tableSize;
}

//don't touch this!
string hashTable::generateSalt()
{
	string s = "";
	
	for(int i = 0; i < tableSize; i++)
		s = s + char('!' + (rand() % 93));
	return s;
}