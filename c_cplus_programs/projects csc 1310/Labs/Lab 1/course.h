/*
	Title:  Course.h
	Author:  Tate Finley
	Date:  8/23/2022
	Purpose: This is the header file that contains all of the 
             needed libraries, structure definition for 'Course',
             and function prototypes.
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
using namespace std;

struct Course
{
    string courseName; //name of the course
    string courseLocation; //location or where the course is
    string* sectionPtr; //pointer to a string array containing info about sections
    int numSections; //number of sections in a course
    int creditHours; //number of credit hours in a course.
};

Course* createCourse(string, string, int, int);

void destroyCourse(Course* myCourse);

void printCourse(Course* myCourse);

#endif 