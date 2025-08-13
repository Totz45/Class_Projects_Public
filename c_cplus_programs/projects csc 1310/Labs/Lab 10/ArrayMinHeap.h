/*
    File Name: ArrayMinHeap.h
    Author: Tate Finley
    Date: 11/25/22
    Purpose: This header file defines the class of ArrayMinHeap which inserts elements
    like a Heap.
*/

#ifndef ARRAYMINHEAP_H
#define ARRAYMINHEAP_H

#include "Creature.h"
#include <cmath>
#include <iostream>
using namespace std;

/*
    Class Name: ArrayMinHeap
    Class Purpose: serves as a heap sorted by minimum value
    Attributes: a pointer to creature object, two integers, and three
    private member functions.
    Member functions: see definitions
*/
class ArrayMinHeap
{
    private:
        Creature *heapArray; //pointer to an array of creatures
        int capacity;//maximum number of elements in the heap
        int heap_size;//current size of heap

        /*
            Function Name: swap()
            Function Purpose: swaps the positions of two creature nodes
            Parameters: two creature pointers
            Returns: none
        */
        void swap(Creature *x, Creature *y)
        {
            Creature temp = *x;
            *x = *y;
            *y = temp;
        }
        /*
            Function Name: parent()
            Function Purpose: returns the parent of a given node
            Parameters: an integer indicating the position of the node
            Returns: an integer indicating the position of the parent
        */
        int parent(int i)
        {
            return (i-1)/2;
        }
        /*
            Function Name: left()
            Function Purpose: returns the left child of a given node
            Parameters: an integer indicating the position of the node
            Returns: an integer indicating the position of the left child
        */
        int left(int i)
        {
            return (2*i + 1);
        }
        /*
            Function Name: right()
            Function Purpose: returns the right child of a given node
            Parameters: an integer indicating the position of the node
            Returns: an integer indicating the position of the right child
        */
        int right(int i)
        {
            return (2*i + 2);
        }
    public:
        ArrayMinHeap(int);
        ~ArrayMinHeap();

        void minHeapify(int);

        /*
            Function Name: peek()
            Function Purpose: return the root creature
            Parameters: None
            Returns: the root creature 
        */
        Creature peek()
        {
            return heapArray[0];
        }

        bool remove();

        void insert(Creature);

        void resizeArray();

        /*
            Function Name: isEmpty()
            Function Purpose: checks if heap is empty
            Parameters: None
            Returns: a boolean indicating if the heap is empty
        */
        bool isEmpty()
		{
			if(heap_size == 0)
				return true;
			else
				return false;
		}

        /*
            Function Name: getNumberOfNodes()
            Function Purpose: returns the number of nodes in the heap
            Parameters: none
            Returns: an integer
        */
        int getNumberOfNodes()
        {
            return heap_size;
        }

        /*
            Function Name: getHeight()
            Function Purpose: returns the height of the heap
            Parameters: none
            Returns: an integer
        */
        int getHeight()
        {
            return ceil(log2(heap_size + 1));
        }

        /*
            Function Name: display()
            Function Purpose: prints all the nodes in the heap
            Parameters: none
            Returns: none
        */
        void display()
        {
           for(int i = 0; i < heap_size; i++)
           {
                cout << "\n" << heapArray[i].getName();
           } 
        }

        /*
            Function Name: saveToFile()
            Function Purpose: saves creatures to a file
            Parameters: None
            Returns: None
        */
        void saveToFile()
        {
            for(int i = 0; i < heap_size; i++)
            {
                heapArray[i].printCreatureToFile("savedCreatures.txt");
            }
        }

};

/*
    Function Name: ArrayMinHeap()
    Function Purpose: constuctor function
    Parameters: an integer which is the size of the heap
*/
ArrayMinHeap::ArrayMinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    heapArray = new Creature[cap];
}

/*
    Function Name: ~ArrayMinHeap()
    Function Purpose: destructor function
*/
ArrayMinHeap::~ArrayMinHeap()
{
    delete [] heapArray;
}

/*
    Function Name: minHeapify()
    Function Purpose: balances the heap if the heap is not balanced
    Parameters: an integer indicating the position to balance
    Returns: None
*/
void ArrayMinHeap::minHeapify(int i)
{
    int l = left(i);//left node
    int r = right(i);//right node
    int smallest = i;//smallest node value
    //process of finding the smallest node
    if(l < heap_size && heapArray[l].getName() < heapArray[r].getName())
    {
        smallest = l;
    }
    if(r < heap_size && heapArray[r].getName() < heapArray[smallest].getName())
    {
        smallest = r;
    }
    //if the smallest node changes position, swap elements and balance heap
    if(smallest != i)
    {
        swap(&heapArray[i], &heapArray[smallest]);
        minHeapify(smallest);
    }
}

/*
    Function Name: remove()
    Function Purpose: remove the root creature which is returned by reference
    Parameters: None
    Returns: a boolean indicating if the creature was removed
*/
bool ArrayMinHeap::remove()
{
    //no nodes
    if(heap_size == 0)
    {
        cout << "\nError:  there is no nodes in the heap.\n";
        cout << "\nNo creatures were removed\n";
        return false;
    }
    //only root node
    else if(heap_size == 1)
    {
        heap_size--;
        cout << "\nYou have removed " << heapArray[0].getName();
        return true;
    }

    //more than one node
    cout << "\nYou have removed " << heapArray[0].getName();
    Creature root = heapArray[0];
    heapArray[0] = heapArray[heap_size-1];//move elements one position over
    heap_size--;
    minHeapify(0);//balance heap
    return true;
}

/*
    Function Name: insert()
    Function Purpose: inserts a creature into the heap
    Parameters: a creature object 
    Returns: None
*/
void ArrayMinHeap::insert(Creature newCreature)
{
    //resize heap if no room is left
    if(heap_size == capacity)
    {
        resizeArray();
    }

    //insert creature
    heapArray[heap_size] = newCreature;
    heap_size++;
    int i = heap_size - 1;

    //balances heap by moving element up
    while(i != 0 && heapArray[parent(i)].getName() > heapArray[i].getName())
    {
        swap(&heapArray[i], &heapArray[parent(i)]);
        i = parent(i);
    }
}

/*
    Function Name: resizeArray()
    Function Purpose: doubles the capacity of the array
    Parameters: none
    Returns: none
*/
void ArrayMinHeap::resizeArray()
{
    int cap = capacity*2;
    Creature* newHeapArray = new Creature[cap];
    //move elements from old heap to new heap
    for (int x = 0; x < capacity; x++)
    {
        newHeapArray[x] = heapArray[x];
    }
    delete [] heapArray;//delete old heap
    //store data on new heap
    heapArray = newHeapArray;
    capacity = cap;
}

#endif