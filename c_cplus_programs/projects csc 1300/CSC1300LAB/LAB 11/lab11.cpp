/*
    File Name: lab11.cpp
    Author: Tate Finley
    Date: April 20th, 2022
    Purpose: This program will calculate, for five students, if they should take a part-time job 
    or not based on how many credit hours they are currently enrolled in.
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct Course
{   
    int numCourse;//number of courses taken
    int* ptr;//pointer variable
};

struct Student
{
    string studentName;//name of student
    string house;//name of computer science house
    Course courseInfo;// contains structure members of Course
};

void enterData(Student[]);
int calculateHours(Course);

int main()
{
    Student studentInfo[5];//array of structure Student
    int i; //used in for loop
    int hoursTotal; //total amount of hours taken by a student
    string line(30, '*'); //outputs 30 characters of *

    //output prompt
    cout << "\nWhich of the five students can work in addition to going to school?";
    cout << "\n\nEnter each student's information";

    enterData(studentInfo); //called for student information

    cout << line << endl; //formating

    /* In for loop, calls calculate hours for each student array which receives 
    the structure courseInfo and returns the total amount of hours for a student. 
    It is then assigned to hoursTotal and if else statement outputs the correct 
    response to the question based on if the hours taken is 30 or less. */
    for(i = 0; i < 5; ++i)
    {
        hoursTotal = calculateHours(studentInfo[i].courseInfo);

        if(hoursTotal <= 30)
        {
            cout << studentInfo[i].studentName << " is going to class and studying ";
            cout << hoursTotal << " hours, so they could take a part-time job.";
            cout << endl << endl;
        } else 
        {
            cout << studentInfo[i].studentName << " is going to class and studying ";
            cout << hoursTotal << " hours, so they should not take a job this semester.";
            cout << endl << endl;
        }
       
    }
    
    //deletes the dynamically allocated array and elements found in enterData()
    for(i = 0; i < 5; ++i)
    {
        delete [] studentInfo[i].courseInfo.ptr;
    }
    


    return 0;
    
}
/*
    Function Name: enterData()
    Parameter: student array
    Returns: none
    Purpose: Retrieves information to input into the student array 
*/
void enterData(Student studentInfo[])
{   
    int i;//for loop 1
    int j;//for loop 2
    string line(10, '*');//10 characters of *

    /* This for loop is designed to retrieve data for each member
    of the student array. The pointer variable found in the Course
    structure is dynamically allocated to an array of integers with
    the size based on the number of courses taken. This allows the 
    number of credit hours taken to be inputed into the array. */
    for(i = 0; i < 5; ++i)
    {
        cout << "\n" << line << "Student ";
        cout << i + 1 << line << endl;

        cout << "Name: ";
        getline(cin, studentInfo[i].studentName);

        cout << "House: ";
        getline(cin, studentInfo[i].house);

        cout << "Number of classes this semester: ";
        cin >> studentInfo[i].courseInfo.numCourse;

        studentInfo[i].courseInfo.ptr = new int[studentInfo[i].courseInfo.numCourse];

        for (j = 0; j < studentInfo[i].courseInfo.numCourse; ++j)
        {
            cout << "Course " << j + 1 << " - ";
            cin >> *(studentInfo[i].courseInfo.ptr + j);
        }

        //next input is a getline
        cin.ignore();
    }

}
/*
    Function Name: calculateHours()
    Parameter: Student member courseInfo
    Returns: an integer
    Purpose: to calculate the cumulative hours taken by the student
    over all of their courses.
*/
int calculateHours(Course courseInfo)
{
    int totalHours = 0;//total amount of hours over all classes
    int i;//used in for loop

    //running total starting at 0 hours
    for(i = 0; i < courseInfo.numCourse; ++i)
    {
        totalHours += *(courseInfo.ptr + i) * 4;
    }

    return totalHours;

}
