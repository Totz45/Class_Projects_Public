/*
    File name: List.h
    Author: Tate Finley
    Date: 9/30/22
    Purpose: This list functions as a templated doubly linked list
*/
#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

/*
    class name: List
    class purpose: functions like a doubly linked list
    Attributes: a struct, and two pointers to the struct
    Member functions: 1 constructor, 1 destructor, and several other member functions
*/
template <class T>
class List
{
    private:
        
        /*
            Struct Name: listNode
            Purpose: a node for a linked list
        */
        struct listNode 
        {
            T value;//value of type T
            listNode* next;//pointer to next node in list
            listNode* prev;//pointer to previous node in list
        };
        
        listNode* head;//points to the head of the list
        listNode* tail;//points to the tail of the list

        void print(listNode*);
        typename List<T>::listNode* mergeSort(listNode*, listNode*);
        listNode* merge(listNode*, listNode*);
        listNode* split(listNode*, listNode*);

    public:
        
        List();
        ~List();
        void print();
        void append(T);
        void mergeSort();
};
/*
    Function Name: print(listNode*)
    Parameters: a node pointer
    Returns:  void
    Purpose: this private print function will print every value 
             in the list after the parameter node. 

*/
template <typename T>
void List<T>::print(listNode* nodePointer)
{
    //first node already printed out start at next node
    nodePointer = nodePointer->next;
    int i = 2;//next node number
    //prints current node, gets next
    while(nodePointer != NULL)
    {
        cout << "\nNode " << i << ":  ";
        cout << *(nodePointer->value) << endl;
        nodePointer = nodePointer->next;
        i++;
    }
}

/*
    Function Name: mergeSort(listNode*,listNode*)
    Parameters: two node pointers, the first and last node of the list partition
    Returns:  a reference to a node, the first in the list partition that has been
              merged
    Purpose:  manages the recursive calls that mergesort needs to make.
*/
template <typename T>
typename List<T>::listNode* List<T>::mergeSort(listNode* first, listNode* last)
{
    listNode* refNode1 = first;//set first node to first in partition
    listNode* refNode2;//second node for placeholder
    listNode* firstSortedNode;//placeholder for final outcome
    if(first == last)//FIXED
    {
        return first;
    }
    refNode2 = split(first, last);//call split for finding middle of partition
    //When there are 0 or 1 nodes present, function returns first parameter
    /*if not partitions the lower and upper bounds of the lists then merges them
        back together*/
    refNode1 = mergeSort(first, refNode2->prev);
    refNode2 = mergeSort(refNode2, last);
    firstSortedNode = merge(refNode1, refNode2);
\
    return firstSortedNode;
}

/*
    Function Name: merge()
    Parameters: two node pointers, the first node in the two list partitions 
                being merged.
    Returns:  a reference to a node, the first in the list partition that has 
                been merged
    Purpose:  merge two list partitions together
*/
template <typename T>
typename List<T>::listNode* List<T>::merge(listNode* firstNode1, listNode* firstNode2)
{
    //if the first node is NULL, the lower partition is empty, return other node
    if(firstNode1 == NULL)
    {
        return firstNode2;
    } 
    //if the second node is NULL, the upper partition is empty, return other node
    else if(firstNode2 == NULL)
    {
        return firstNode1;
    } 
    //otherwise the values can be compared and merged appropriately
    else 
    {
        //if the first node is greater, the next node is the result of the merge 
        //between the second node and the next node after the first
        if(*(firstNode1->value) > *(firstNode2->value))
        {
            firstNode1->next = merge(firstNode1->next, firstNode2);
            //set prev pointers
            firstNode1->next->prev = firstNode1;
            firstNode1->prev = NULL;
            return firstNode1;
        }
        //if the second node is greater, the next node is the result of the merge 
        //between the first node and the next node after the second
        else
        {
            firstNode2->next = merge(firstNode1, firstNode2->next);
            //set prev pointers
            firstNode2->next->prev = firstNode2;
            firstNode2->prev = NULL;
            return firstNode2;
        }
    }


}

/*
    Function Name: split()
    Parameters: two node pointers, the first and last node in the list 
                partition being split
    Returns:  a node reference to the middle node
    Purpose:  subdivide a list partition into two more partitions

*/
template <typename T>
typename List<T>::listNode* List<T>::split(listNode* firstNode, listNode* lastNode)
{
    listNode* middleNode;//keep track of the middle node
    //using double traversal from each end to find middle node 
    while(firstNode != lastNode && firstNode->prev != lastNode)
    {
        firstNode = firstNode->next;
        lastNode = lastNode->prev;

    } 
    //for the first exit condition where last and first end up on same point
    if(firstNode == lastNode)
    {
        middleNode = lastNode->prev;
        middleNode->next = NULL;
        return firstNode;//returns firstNode of upperbound
    } 
    //for the next exit condition where last is in front of first 
    else {
        middleNode = lastNode;
        middleNode->next = NULL;
        return firstNode;//returns firstNode of upperbound 
    }
    
}

/*
    Function Name: List()
    Parameters:  no parameters
    Purpose:  creates an empty list by setting head and tail to null
*/
template <typename T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
}

/*
    Function Name: ~List()
    Purpose:  called when the list is removed from memory
*/
template <typename T>
List<T>::~List()
{
    listNode* deleteNode;//node being deleter
    listNode* nextNode;//pointer to next node in the list

    deleteNode = head;//start at head

    //traverse through list to delete each and every node
    while(deleteNode != NULL)
    {
        nextNode = deleteNode->next;
        delete deleteNode;
        deleteNode = nextNode;
    }
}

/*
    Function Name: print()
    Parameters: no parameters
    Returns:  void
    Purpose:  prints the first value of the list then calls the private print 
              function to print every element in the list
*/
template <typename T>
void List<T>::print()
{
    listNode* nodePtr;//pointer to node
    nodePtr = head;//first node
    cout << "\nNode 1: " << *(nodePtr->value) << endl;
    print(nodePtr);//call function
}

/*
    Function Name: append()
    Parameters: the new value we are appending to the end
    Returns:  void
    Purpose:  create a new node and add that node as the 
              last element of the list
*/
template <typename T>
void List<T>::append(T newValue)
{
    listNode* newNode;//node being created

    //create new node with Dynamic allocation and initialization
    newNode = new listNode;
	newNode->value = newValue;
	newNode->next = NULL;
	newNode->prev = NULL;  

    //if this is the first element, the head and tail are set to the node
    if (!head) 
	{
        head = newNode;
		tail = newNode;
	} 
    //otherwise the tail is moved and newNode is at end of list with tail pointing to it
    else
    {
        tail->next = newNode;
		newNode->prev = tail;
        tail = newNode;
    } 
}

/*
    Parameters: no parameters
    Returns:  void
    Purpose:  this is the public-facing function call to begin sorting 
              the list in descending order.
*/
template <typename T>
void List<T>::mergeSort()
{
    listNode* accessNodePtr;//for traversing the list
    head = mergeSort(head, tail);//head is the first element of the sorted list
    accessNodePtr = head;
    //access the tail and set the last node to the tail
    while(accessNodePtr)
    {
        tail = accessNodePtr;
        accessNodePtr = accessNodePtr->next;
    }
}

#endif