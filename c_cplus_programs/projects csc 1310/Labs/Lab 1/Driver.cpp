/*
	LAB 1 - CSC1310

	Title: Driver.cpp
	Author: Tate Finley
	Date: 8/26/2022
	Purpose: This is the main program which can dynamically allocate an
			 array of structure pointers and uses it to store information
			 about courses to each element of the array provided by the user.
*/

#include "course.h"

int main ()
{
	//This is a course pointer that is able to point to an array
	Course** myCourses; 
	
	int numCourses, numSections;
	string name, location;
	int numHours;
	
	cout << "\nHow many courses are you taking this semester?\n";
	cin >> numCourses;
	cin.ignore();
	//This is the dynamic allocation of a course array to the pointer
	myCourses = new Course* [numCourses];
	
	for (int i=0; i< numCourses; i++)
	{
		cout << "\nCOURSE NAME:\t\t";
		getline(cin, name);
		cout << "\nCOURSE LOCATION:\t";
		getline(cin, location);
		cout << "\nCOURSE HOURS:\t\t";
		cin >> numHours;
		cout << "\nNUMBER OF SECTIONS?\t";
		cin >> numSections;
		cin.ignore();

		
		/*the function, createCourse() was called and the values will
		  be stored in an element in the myCourses array*/
		myCourses[i] = createCourse(name, location, numSections, numHours);

		for(int x=0; x<numSections; x++)
		{
			cout << "\nSECTION " << x+1 << ":\t\t";
			
			/*Reads a string from the user and puts it in the correct array 
			  element of the sections array.*/
			getline(cin, myCourses[i]->sectionPtr[x]);
		}
		cout << "\n*******************************\n";
	}
	
	cout << "\n\nThe following are the courses you entered:\n\n";
	for(int i=0; i<numCourses; i++)
	{
		cout << "******************************* COURSE " << (i+1) << "*******************************\n";
		printCourse(myCourses[i]); //print function called
	}
	
	for(int i=0;  i< numCourses; i++)
	{
		destroyCourse(myCourses[i]); //destroyer function called
	}
	delete [] myCourses;
	cout << endl << endl;
	return 0;
}