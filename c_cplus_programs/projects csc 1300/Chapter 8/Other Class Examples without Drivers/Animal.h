/***************************************************************
	Title:  	Animal.h
	Author:  	April Crockett
	Date:		2/13/2019
	Purpose:	Animal class
****************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class Animal
{
	private:
		string name;
		int age;
		float weight;
		string animalType; //dog, cat, rat, etc.
		char* dateEnteredShelter;		
	
	public:
		/*
			Animal Constructor
			Purpose: ask the user for the name, age, time at the animal shelter, and weight of the animal
		*/
		Animal(string n, int a, float w, string t)
		{
			name = n;
			age = a;
			weight = w;
			animalType = t;
			
			//the time the animal entered the shelter is generated here
			time_t now = time(0); //get system time 
			dateEnteredShelter = ctime(&now); //cenvert time_t value to c-string
			cout << "\nThe local date and time the " << animalType << " entered the shelter is " << dateEnteredShelter << endl;
		}
		
		string getName()
		{
			return name;
		}
		int getAge()
		{
			return age;
		}
		char* getDateEnteredShelter()
		{
			return dateEnteredShelter;
		}
		string getAnimalType()
		{
			return animalType;
		}
		float getWeight()
		{
			return weight;
		}
		
		/*
			overloaded << operator
			when printing out an Animal object with cout << it will print out 
			all attributes in the Animal class.
		*/
		friend ostream &operator << (ostream &strm, Animal &a)
		{
			strm << setw(18) << "NAME:  " << a.name << endl;
			strm << setw(18) << "AGE:  " << a.age << endl;
			strm << setw(18) << "WEIGHT:  " << a.weight << endl;
			strm << setw(18) << "ANIMAL:  " << a.animalType << endl;
			strm << setw(18) << "DATE ARRIVED:  " << a.dateEnteredShelter << endl;
			return strm;
		}		
		
		/*
			overloaded == operator
			used when comparing two Animal objects - will compare the name string attribute
		*/
		bool operator == (const Animal &a)
		{
			if(name == a.name)
				return true;
			else
				return false;
		}
		

};

#endif
