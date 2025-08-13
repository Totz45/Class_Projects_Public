#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
using namespace std;

class Student
{
	private:
		double gpa;
		string name;
		string major;
	public:
		Student(){}
	
		Student(double g, string n, string m)
		{
			gpa = g;
			name = n;
			major = m;
		}
		
		double getGPA() const
		{
			return gpa;
		}
		string getName() const
		{
			return name;
		}
		string getMajor() const
		{
			return major;
		}
		
		//overloaded > operator
		friend bool operator >(const Student& l, const Student& r)
		{
			return (l.gpa > r.gpa); 
		}
		
		friend bool operator <(const Student& l, const Student& r)
		{
			return (l.gpa < r.gpa); 
		}
		
		friend ostream &operator << (ostream &strm, Student &s)
		{
			strm << "GPA: " << s.gpa << ", ";
			strm << "NAME: " << s.name << ", ";
			strm << "MAJOR: " << s.major << endl;
			return strm;
		}
};
#endif