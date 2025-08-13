/* 
    File Name: List.h
    Author: Tate Finley
    Date: 9/24/2022
    Purpose: Figure out how a linked list works
*/
#ifndef LIST_H
#define LIST_H

#include "DataSource.h"
#include "SLelement.h"
#include <vector>
#include <iostream>

using namespace bridges;

/*
    Class name: List
    Class Purpose: Serves as a linked list
    Attributes: 2 pointers of type GutenbergBook, and an integer
    storing the size.
    Member Functions: 2 constructors, 1 destructor, and several getter and 
    setter functions.
*/
class List
{
  private:
    SLelement<GutenbergBook>* head;//points to the head of the linked list
    SLelement<GutenbergBook>* tail;//points to the tail of the linked list
    int size;//size of vector

  public:
    /*
        Function Name: List()
        Function Purpose: default constructor
        Parameters: none
        Returns: none
    */
    List(){
      head = NULL;//sets head to point to null
      tail = NULL;//sets tail to point to null
      size = 0;//set size to zero
    };
    
    /*
        Function Name: List(vector<>)
        Function Purpose: constructor
        Parameters: a vector
        Returns: none
    */
    List(vector<GutenbergBook> books){
      //Tried calling default constructor here, did NOT work
      head = NULL;
      tail = NULL;
      size = 0;
      //loop through each element and add to linked list
      for(GutenbergBook b : books)
      {
        appendNode(b);
      }
    };
    
    /*
        Function Name: ~List()
        Function Purpose: destructor
        Parameters: none
        Returns: none
    */
    ~List(){
      SLelement<GutenbergBook>* newNode = head;//node starts at head
      //loop retrieves next node before deleting current node
      for(int i = 0; i < size; i++)
        {
          head = newNode->getNext();
          delete newNode;
          newNode = head;
        }
    };
    
    /*
        Function Name: appendNode()
        Function Purpose: appends a node to the end of the linked list
        Parameters: an object of type GutenbergBook
        Returns: none
    */
    void appendNode(GutenbergBook book)
    {
      SLelement<GutenbergBook>* newNode;//node 
      newNode = new SLelement<GutenbergBook> (book, book.getTitle());//give data to pointer/node
      //if head points to null the if statement assigns head and tail to newNode.
      if(!head)
      {
        head = newNode;
        tail = newNode;
      }else {
        //otherwise only the tail is set to newNode
        tail->setNext(newNode);
        tail = newNode;
      }
      size++;//increment size by one
    }
    
    /*
        Function Name: insertNode()
        Function Purpose: inserts a node at an index somewhere in the middle
        of the linked list
        Parameters: a integer to hold the index and an object of type GutenbergBook
        Returns: none
    */
    void insertNode(int index, GutenbergBook moveBook)
      {
        SLelement<GutenbergBook>* newNode;//node
        newNode = new SLelement<GutenbergBook> (moveBook, moveBook.getTitle());//node gets data
        //if head points to null the if statement assigns head and tail to newNode.
        if(!head)
        {
          head = newNode;
          tail = newNode;
        } else if (newNode == tail){
          /* if the newNode and the tail have the same value then the node
             is inserted before the tail
          */
          tail->setNext(newNode);
          tail = newNode;
        } else {
          SLelement<GutenbergBook>* currNode = head;
          //now finding the node located at index
          for(int i = 0; i < index-1; i++){
            currNode = currNode->getNext();
          }
          /* The newNode is inserted at the index and the node previously
             at the index gets moved.
          */
          newNode->setNext(currNode->getNext());
          currNode->setNext(newNode);
        }
        size++;
      }
    
    /*
        Function Name: deleteNode()
        Function Purpose: deletes the node at the index
        Parameters: an integer containing the index
        Returns: none
    */
    void deleteNode(int index)
      {
        SLelement<GutenbergBook>* findNode;//node finder
        int i = 1;//used for finding index
        //no head, nothing to delete
        if(!head){
          return;
        }
        if(index == 0){
          /*if the node being deleted is the head, the head is moved
           to the next node*/
          findNode = head->getNext();
          delete head;
          head = findNode;
          size--;
        } else {
          SLelement<GutenbergBook>* deleteNode = head;//node being deleted
          /* findNode is now the previous node and this while loop searches
              for the node before index
          */
          while(deleteNode != NULL && i != index) {
            findNode = deleteNode;
            deleteNode = deleteNode->getNext();
            i++;
          }

          /*if a node was found at the index it is deleted after
            after the previous node points to the node that the deleted
            node is pointing to*/
          if(deleteNode)
          {
            //if the node is at the tail, the tail is moved
            if(deleteNode == tail)
            {
              tail = deleteNode;
            }
            findNode->setNext(deleteNode->getNext());
            delete deleteNode;
            size--;//one less element
          }
          
        }
      };
    /*
        Function Name: getHead()
        Function Purpose: accessor function 
        Parameters: none
        Returns: pointer to the head of GutenbergBook vector
    */
    SLelement<GutenbergBook>* getHead()
      { return head; }
    /*
        Function Name: getSize()
        Function Purpose: returns the size of the linked list
        Parameters: none
        Returns: an integer of the size of the array
    */
    int getSize()
      { return size; }
};


#endif