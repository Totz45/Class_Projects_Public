/*
    File Name: HashTable.h
    Author: Tate Finley
    Date: 10/18/22
    Purpose: This class implements the functions of a hash table
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashEntry.h"

/*
    Class Name: HashTable
    Class Purpose: Functions like a hash table to map a key to a bucket
                   using closed hashing specifically Linear Probing.
*/
class HashTable
{
    private:
        int tableSize;//size of the hash table
        HashEntry** hashArray;//a table of hash entries:array of HashEntry pointers
    public:
        /*
            Function Name: HashTable()
            Function Purpose: Contructor function for the hash table
            Parameters: an integer indicating the size of the table
        */
        HashTable(int size)
        {
            tableSize = size;//store the table size passed by argument
            //Create a new Hash Table 
            hashArray = new HashEntry*[tableSize];
            //initialize elements to Null
            for(int i = 0; i < tableSize; i++)
            {
                hashArray[i] = NULL;
            }
        }
        /*
            Function Name: ~HashTable()
            Function Purpose: Destructor function for the hash table
        */
        ~HashTable()
        {
            //go through table and check if any hash entry is still in table then delete array
            for(int i = 0; i < tableSize; i++)
            {
                //delete the entry if there is an entry in it
                if(hashArray[i] != NULL)
                {
                    delete hashArray[i];
                }
            }
            delete [] hashArray;
        }
        /*
            Function Name: putValue()
            Function Purpose: Inserts an entry into the table in the corresponding bucket
            Parameters: an integer containing the element key, a pointer to a Costume
            Returns: None
        */
        void putValue(int key, Costume* newCostume)
        {
           //create new hash entry
            HashEntry* h = new HashEntry(key, newCostume);

            
            //find the bucket for the hash entry to be inserted
            int bucketIndex = key % tableSize;

            if(hashArray[bucketIndex] != NULL)
            {
                //if something is already in the bucket indicate collision
                cout << "Collision at bucket " << bucketIndex << endl;
            } else {
                //if bucket is empty, indicate which bucket the entry will be inserted into
                cout << "BUCKET " << bucketIndex << endl;
            }
            
            //process of linear probing to find a new bucket for an entry to be inserted into
            while(hashArray[bucketIndex] != NULL && hashArray[bucketIndex]->getKey() != key)
            {
                //go to next bucket
                bucketIndex = (bucketIndex+1) % tableSize;
                //same process as above
                if(hashArray[bucketIndex] != NULL)
                {
                    cout << "Collision at bucket " << bucketIndex << endl;
                } else {
                    cout << "BUCKET " << bucketIndex << endl;
                }
            }
            //insert key to bucket
            hashArray[bucketIndex] = h;
        }
        
        /*
            Function Name: printHashTable()
            Function Purpose: Prints all of the entries of the hash table in order
            Parameters: None
            Returns: None
        */
        void printHashTable()
        {
            cout << "----------\n";

            //print elements with corresponding bucket number
            for(int i=0; i < tableSize; i++)
            {
                cout << i << ": " << *(hashArray[i]->getValue()) << endl; 
            }

            cout << "----------";

        }
};

#endif