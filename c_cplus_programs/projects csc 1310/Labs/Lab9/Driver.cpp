/*
    File Name: Driver.cpp
    Author: Tate Finley
    Date: 11/3/22
    Purpose: This program reads the number of vertices from the file and 
             creates edges between vertices based on the edge specifications
             defined in the file.
*/

#include "GraphList.h"
#include <fstream>

using namespace std;

int main()
{
    ifstream file("graph.txt");//file for graph definition
    int numVertices;//number of vertices
    int edge1, edge2;//indicate the vertices being edged together

    if(file.is_open()) {
	    file >> numVertices;//input number of vertices

        //indicate to user
        cout << "There are " << numVertices << " vertices in the graph.\n\n";
	    
        //create a new graph based on the number of vertices 
        Graph* newGraph = new Graph(numVertices);

        //get the vertices to map edges between while the file doesn't end
        while(!file.eof())
        {
            file >> edge1;//vertice1(edge mapped from)

            file >> edge2;//vertice2(edge mapped to)
            
            cout << "Adding an edge from " << edge1 << " to " << edge2 << ".\n";

            //call function to add the edge
            newGraph->addEdge(edge1, edge2);
        }

        //print the graph and the edge connections
        newGraph->printGraph();

        //delete the graph
        delete newGraph;

    }
    return 0;
}