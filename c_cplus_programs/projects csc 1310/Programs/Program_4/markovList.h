/*
	File Name: markovList.h
	Author: Tate Finley
	Date: 11/30/22
	Purpose: This is the class definition of the markovList. It is implemented
	using maps/graphs.
*/

#ifndef MARKOVLIST_H
#define MARKOVLIST_H

#include<map>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

/*
	Class Name: markovList
	Class Purpose: implemented using graphs and maps
	Attributes: a struct, an integer, a map
	Member functions: see definitions
*/
class markovList
{
	private:
		/*
			Struct Name: edge
			Struct Purpose: this struct serves as a node in the map.
		*/
		struct edge
			{
				float weight;//probability of going to this node
				string destination;//word of the destination node
				edge* next;//pointer to next node
			};
		int corpusSize;//size of the map
		map<string, edge*> corpus;//similar to a hashArray but uses strings instead
		
	public:
		markovList(const char*);
		~markovList();
		
		string generate(int);
};

/*
	Function Name: markovList
	Purpose: constructor function
*/
markovList::markovList(const char* filename)
{
	ifstream file(filename);//name of file
	stringstream parser, splitter;//retrieve strings from file
	string line, index, word;//words in filename
	float weight;//probability of going to a node
	edge* newEdge;//pointer to an edge object
	srand (time(0));
	
	if(file.good()) {
	file >> corpusSize;
	file.ignore(1, '\n');

	
	while(getline(file, line, '\n')) //map every word to a position in the matrix, keep the line in an array of buffers for later
	{
		parser.clear();
		parser << line;
		getline(parser, index,',');	//pulls the first word of the line, which is the node for which we're making a list of neighbors
		//initialize an empty list at the index---
		corpus[index] = NULL;
		while(getline(parser, word, ','))
		{
			//allocate a new node in the edge list---
			newEdge = new edge;
			splitter.clear();
			splitter.str(word);
			splitter >> word >> weight;
			//stick word and weight on the node you've just allocated---
			newEdge->weight = weight;
			newEdge->destination = word;
			newEdge->next = NULL;
			
			//make sure your new node is attached to the list---
			if(corpus[index] == NULL)
			{
				corpus[index] = newEdge;
			} else
			{
				edge* traverseEdge = corpus[index];
				while(traverseEdge->next != NULL)
				{
					traverseEdge = traverseEdge->next;
				}
				traverseEdge->next = newEdge;

			}

			
			
		}
	}}
}

/*
	Function Name: ~markovList()
	Purpose: destructor function
*/
markovList::~markovList()
{
	map<string, edge*>::iterator it = corpus.begin();
	
	//loop through every element and delete contents
	for(it; it != corpus.end(); it++)
	{
		edge* eraseEdge = it->second;//current node
		edge* prevEdge = NULL;//previous node

		while(eraseEdge != NULL)
		{
			prevEdge = eraseEdge;
			eraseEdge = eraseEdge->next;
			delete prevEdge;
		}
	}
}

/*
	Function Name: generate()
	Purpose: generates a string containing the amount of words passed by reference.
	Parameters: an integer which is the word count
	Returns: a string consisting of all the words
*/		
string markovList::generate(int length)
{
	float matchWeight;//used for weight comparison
	string fullString;//the full string that will be returned
	string editString;//a word on the current edge
	cout << endl;
	map<string, edge*>::iterator it = corpus.begin();	//initialize an iterator to find a random node in the next line
	advance(it,rand() % corpusSize);	//this grabs a random node from your corpus as a starting point
	edge* getNextEdge = corpus[it->first];//initialize an edge to starting node
	for(int i = 0; i < length; i++)
	{
		float randNum = (rand() + 0.0)/RAND_MAX;
		matchWeight = getNextEdge->weight;//obtain the weight of node
		
		//compare weight to random number
		while(matchWeight < randNum)
		{	
			getNextEdge = getNextEdge->next;//go to next if less than random number
			matchWeight += getNextEdge->weight;//add next weight to matchWeight
		}
		//get string and append to fullString
		editString = getNextEdge->destination;
		editString += ' ';
		fullString.append(editString);

		//obtain the next edge
		getNextEdge = corpus[getNextEdge->destination];
	}

	return fullString;
}


#endif