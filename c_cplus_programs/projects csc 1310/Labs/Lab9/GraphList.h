/*
    File Name: GraphList.h
    Author: Tate Finley
    Date: 11/3/22
    Purpose: this header file is the class definition of graph
*/

#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <iostream>
using namespace std;

/*
    Class Name: Graph
    Class Purpose: create an array of vertices to able to connect edges
    between one vertice to the other.
    Attributes: a struct, a pointer to an array of struct pointers, and 2 integers
                to keep track of vertices and edges
    Member Functions: See function definitions
*/
class Graph
{
    private:

        /*
            Struct Name: ListNode
            Struct Purpose: serves as a node for a particular vertice
        */
        struct ListNode
        {
            int value;//value in the node
            ListNode* next;//pointer to the next node
        };
        ListNode** headArray;//serves as an array of listNode pointers
        int numVertices;//number of vertices
        int numEdges;//number of edges

    public:

        /*
            Function Name: Graph()
            Function Purpose: constructor function for the Graph class
        */
        Graph(int vertices)
        {
            numVertices = vertices;//store number of vertices
            headArray = new ListNode*[numVertices];//DMA for the headArray
            //initialize array contents and number of edges
            for(int i = 0; i < numVertices; i++)
            {
                headArray[i] = NULL;
            }
            numEdges = 0;
        }
        /*
            Function Name: Graph()
            Function Purpose: destructor function for the Graph class
        */
        ~Graph()
        {
            for(int i = 0; i < numVertices; i++)
            {
                
                //find each edge and delete the edge
                
                if(headArray[i] != NULL)
                {
                    ListNode* currNode = headArray[i];
                    ListNode* prevNode = NULL;
                    
                    //Process of finding edges for a node
                    
                    while(currNode != NULL)
                    { 
                        prevNode = currNode;
                        currNode = currNode->next;
                        delete prevNode;
                    }
                }
            }

            //delete the array
            delete [] headArray;
        }
        /*
            Function Name: addEdge()
            Function Purpose: creates an edge from 1 vertice to another
            Parameters: two integers indicating the vertice
            Returns: None
        */
        void addEdge(int vertice1, int vertice2)
        {
            ListNode* newNode;//for a new edge
            newNode = new ListNode;
            newNode->value = vertice2;//new edge end value
            newNode->next = NULL;
            
            //if the list is empty, newNode is first element
            if(headArray[vertice1] == NULL)
            {
                headArray[vertice1] = newNode;
            }else
            {
                //search for a null node to store the edge
                ListNode* emptyNode = headArray[vertice1];
                while(emptyNode->next != NULL)
                {
                    emptyNode = emptyNode->next;
                }
                emptyNode->next = newNode;//store the edge
                
            } 

            //increment the number of edges
            numEdges++;
        
        }
        /*
            Function Name: printGraph()
            Function Purpose: prints all edges corresponding to a vertice
            Parameters: None
            Returns: None
        */
        void printGraph()
        {
            int bucketIndex;//indicates current node in array
            ListNode* currNode;//the current node

            cout << "\nAdjacency List...\n";

            //print all edges corresponding to a node
            for(bucketIndex = 0; bucketIndex < numVertices; bucketIndex++)
            {
                currNode = headArray[bucketIndex];
                cout << bucketIndex << "-->";
                while(currNode != NULL)
                {
                    cout << currNode->value << "-->";
                    currNode = currNode->next;
                }
                cout << "NULL\n";
            }
        }

};
#endif