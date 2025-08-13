/*
	Title:  Course.cpp
	Author:  Tate Finley
	Date:  8/23/2022
	Purpose: This program defines all of the functions in the header file 
*/
#include "course.h"

/* 
    Function Name: createCourse()
    Function Purpose: This function will dynamically create a new Course structure variable 
    and then enter the given data into the Course structure members. This function 
    will also dynamically create the sections array containing the number of elements as 
    there are sections of the course.
    Parameters: 2 strings one containing the name of the course and the other the location, 
    and 2 integers for the number of sections and the number of credit hours that each 
    course has
    Returns: a pointer to the Course variable with all the given data
*/
Course* createCourse(string name, string location, int numOfSection, int numCreditHour) 
{
    Course* myCourse = new Course; 
    myCourse->courseName = name;
    myCourse->courseLocation = location;
    myCourse->numSections = numOfSection;
    myCourse->creditHours = numCreditHour;
    myCourse->sectionPtr = new string[myCourse->numSections];
    
    return myCourse;

}

/* 
    Function Name: destroyCourse()
    Function Purpose: This function will release all of the dynamically
    allocated data including the sections array and the Course variable.
    Parameters: A pointer to the Course variable with all of the data
    Returns: None
*/
void destroyCourse(Course* myCourse)
{
    delete [] myCourse->sectionPtr;
    delete myCourse;
}

/* 
    Function Name: printCourse()
    Function Purpose: This function prints all of the data from the
    members of the Course structure in a nice, easy to read format.
    Parameters: A pointer to the Course variable with all of the data
    Returns: None
*/
void printCourse(Course* myCourse)
{
    cout << "\nCOURSE NAME:\t\t" << myCourse->courseName;
	cout << "\nCOURSE LOCATION:\t" << myCourse->courseLocation;
	cout << "\nCOURSE HOURS:\t\t" << myCourse->creditHours;
	cout << "\nCOURSE SECTIONS:\n";
    for(int y=0; y < myCourse->numSections; y++)	
    {
        cout << "\t\t\t" << myCourse->sectionPtr[y] << endl;
    }
}