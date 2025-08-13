/*	Title:  structInit_1.cpp
	Author:  April Crockett
	Date:  November 9, 2009
	Purpose:  To show you struct initialization
*/

#include <iostream>

using namespace std;


struct CityInfo
{
    char cityName[30];   //DO NOT INITIALIZE in struct declaration
	char state[3];
	long population;
	int distance;
};

//prototypes

int main()
{
	CityInfo myCity; // none of the members will be initilized...junk data
	
	CityInfo location = {"Ashville", "NC", 50000, 28}; //like initializing an array

	CityInfo location2 = {"Cookeville", "TN"}; //partial initialization; population & distance ARE set to zero

	CityInfo location3 = {"Knoxville", "TN", , 90}; //ILLEGAL - will produce syntax error!


	return 0;
}

