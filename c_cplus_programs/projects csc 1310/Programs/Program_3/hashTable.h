/*
	File Name: hashTable.h
	Author: Tate Finley
	Date: 11/6/22
	Purpose: class definitions for hashTable and entry classes
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
using std::string;

/*
	Class name: hashTable
	Purpose: a class implemented in the form of a hashTable
	Attributes: a class, an integer, a pointer to an entry of pointers,
				and two private functions.
	Member Functions: see function defintions in hashTable.cpp
*/
class hashTable
{
	private:
		class entry;//see class definition

		//add the attributes you need for the class---------------------------------------------------------
		int tableSize;//size of the hashTable
		entry** hashArray;//used for storing the entries
		int hash(string);
		entry* getEntry(string);
	public:
		//add all the functions you need--------------------------------------------------------------------
		string generateSalt();
		hashTable(int);
		~hashTable();
		string getSalt(string);
		void addEntry(string, string, string);
		bool validateLogin(string, string);
		bool removeUser(string, string);
};

/*
	Class Name: entry
	Purpose: class that is used to store the information of a user
	Attributes: three strings
	Member functions: see function definitions
*/
class hashTable::entry
{
	private:
		string uname;//username
		string salt;//salt of username
		string passHash;//hashed password
	public:
		entry* next;//next entry in a bucket list

		//add the constructor and getter functions-----------------------------------------------------------
		/*
			Function Name: entry()
			Function Purpose: constructor for the entry class
		*/
		entry(string userName, string hashedPassword, string addedSalt)
		{
			uname = userName;
			passHash = hashedPassword;
			salt = addedSalt;
			next = NULL;
		}
		/*
			Function Name: getUsername()
			Purpose: return a string which is the username
		*/
		string getUsername()
		{
			return uname;
		}
		/*
			Function Name: getSalt()
			Purpose: return a string which is the salt
		*/
		string getSalt()
		{
			return salt;
		}
		/*
			Function Name: getHashedpwd()
			Purpose: return a string which is the hashed password
		*/
		string getHashedpwd()
		{
			return passHash;
		}
};

#endif