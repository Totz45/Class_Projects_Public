/*
    File Name: Queue.h
    Author: Tate Finley
    Date: 10/14/22
    Purpose: This header file implements the concept of a queue.
*/
#ifndef QUEUE_H
#define QUEUE_H

/*
    Class Name: Queue
    Class Purpose: functions like a queue or a type of linked list
    Attributes: a struct, an integer, and two pointers to the struct
    Member functions: see function definitions
*/
class Queue
{
    private:
        /*
            Struct name: queueNode
            Struct purpose: functions like a node in a linked list
        */
        struct queueNode
        {
            std::string riderName;//name of the rider
            queueNode* next;//pointer to next node
        };

        int numNodes;//the number of nodes in the queue
        queueNode* head;//pointer to the head of the queue
        queueNode* tail;//pointer to the tail of the queue
    public:

        /*
            Function Name: Queue()
            Function Purpose: constructor function of the class
        */
        Queue()
        {
            head = NULL;
            tail = NULL;
            numNodes = 0;
        }

        /*
            Function Name: ~Queue()
            Function Purpose: destructor function of the class
        */
        ~Queue()
        {
            queueNode* nodePtr;//pointer to the current node
            queueNode* nextNode;//pointer to the next node

            nodePtr = head;//start at head

            /*
                output rider name being deleted before deleting the node,
                obtaining the next, and decrementing the amount in the queue.
            */
            while (nodePtr)
            {
                std::cout << "\nOh shoot, I am sorry, our park is closed so ";
                std::cout << nodePtr->riderName << " will not get to ride today.";
                nextNode = nodePtr->next;//store nextNode
                delete nodePtr;
                nodePtr = nextNode;//move to next node
                numNodes--;
            }
        }


        /*
            Function Name: enqueue()
            Function Purpose: create a new Node for the rider and append to end.
            Parameters: a string containing the name of the rider
            Returns: none
        */
        void enqueue(std::string rider)
        {
            queueNode* newNode;//pointer to a new Node

            newNode = new queueNode;//create a new Node

            newNode->riderName = rider;//pass data to node

            //append node to end as appropriate
            if(!head)
            {
                //only for first node
                newNode->next = NULL;
                head = newNode;
                tail = newNode;
            } else 
            {
                //every other node
                tail->next = newNode;
                tail = newNode;
                tail->next = NULL;
            }
            numNodes++;//increment number in queue

        }
        
        /*
            Function Name: dequeue()
            Function Purpose: remove the node/rider at the front of the queue
            Parameters: None
            Returns: a string containing the rider's name being removed
        */
        std::string dequeue()
        {
            queueNode* deleteNode;//node being deleted
            std::string ridingRider;//name of rider

            deleteNode = head;//node at the front of queue
            head = head->next;//obtain next node in the queue

            ridingRider = deleteNode->riderName;
            delete deleteNode;
            numNodes--;//decrement number in queue    
            return ridingRider;
        }
        
        /*
            Function Name: isEmpty()
            Function Purpose: check if the queue is empty
            Parameters: None
            Returns: a boolean indicating if the queue is empty
        */
        bool isEmpty()
        {
            if(!head)
            {
                //no node at front means no one in queue
                return true;
            } else
            {
                //there is a node at front, someone in queue
                return false;
            }
        }

};

#endif