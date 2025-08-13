#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

// Queue template
template <typename T>
class Queue
{
	private:
	   T *queueArray;		// Points to the queue array
	   int queueSize;		// The queue size
	   int front;			// Subscript of the queue front
	   int rear;			// Subscript of the queue rear
	   int numItems;		// Number of items in the queue
	public:
	   // Constructor
	   Queue(int);
	   
	   // Copy constructor
	   Queue(const Queue &);
	   
	   // Destructor
	   ~Queue();

	   // Queue operations
	   void push_back(T);
	   void pop_front(T &);
	   bool isEmpty() const;
	   bool isFull() const;
	   void clear();
};

template <typename T>
Queue<T>::Queue(int s)
{
   queueArray = new T[s];
   queueSize = s;  //number of items that are possible to be in the queue
   front = -1; //subscript of front of queue
   rear = -1; //subscript of back of queue
   numItems = 0;  //number of items in the queue
}
	   
template <typename T>
Queue<T>::Queue(const Queue &obj)
{
   // Allocate the queue array.
   queueArray = new T[obj.queueSize];
   
   // Copy the other object's attributes.
   queueSize = obj.queueSize;
   front = obj.front;
   rear = obj.rear;
   numItems = obj.numItems;
   
   // Copy the other object's queue array.
   for (int count = 0; count < obj.queueSize; count++)
      queueArray[count] = obj.queueArray[count];
}
	   
template <typename T>
Queue<T>::~Queue()
{
   delete [] queueArray;
}

template <typename T>
void Queue<T>::push_back(T item)
{
   if(isFull())
      cout << "The queue is full.\n";
   else
   {
      // Calculate the new rear position
      rear = (rear + 1) % queueSize;
      // Insert new item
      queueArray[rear] = item;
      // Update item count
      numItems++;
   }
}

template <typename T>
void Queue<T>::pop_front(T &item)
{
   if (isEmpty())
      cout << "The queue is empty.\n";
   else
   {
      // Move front
      front = (front + 1) % queueSize;
      // Retrieve the front item
      item = queueArray[front];
      // Update item count
      numItems--;
   }
}

template <typename T>
bool Queue<T>::isEmpty() const
{
   bool status;

   if (numItems)
      status = false;
   else
      status = true;

   return status;
}

template <typename T>
bool Queue<T>::isFull() const
{
   bool status;

   if (numItems < queueSize)
      status = false;
   else
      status = true;

   return status;
}

template <typename T>
void Queue<T>::clear()
{
   front = queueSize - 1;
   rear = queueSize - 1;
   numItems = 0;
}
#endif