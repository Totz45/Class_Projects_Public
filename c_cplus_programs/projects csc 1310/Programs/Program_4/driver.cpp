/*
	File Name: driver.cpp
	Author: Tate Finley
	Date: 11/30/22
	Purpose: Main Program implementing markovChain
*/
#include<iostream>
//#include "markovMat.h"
#include "markovList.h"
using namespace std;

int main()
{
	//markovMat* chain = new markovMat("corpus.txt");
	markovList* chain = new markovList("corpus.txt");
	
	cout << chain->generate(100) << endl;
	return 0;
}