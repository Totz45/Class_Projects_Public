/*
    File name: DynStack.h
    Author: Tate Finley
    Date: 9/30/22
    Purpose: Know how a stack works
*/
#ifndef DYNSTACK_H
#define DYNSTACK_H

/*
    Class Name: Stack
    Class Purpose: this class behaves like a dynamic stack, only accessable at the top
    Attributes: a struct, and a pointer to a struct 
    Member Functions: a constructor, a destructor, and three functions used to edit the linked list
*/
template <class T>
class Stack
{
    private:
        /*
            Struct Name: StackNode
            Struct Purpose: this struct serves as the node in the stack. It contains a
            value of typename T, and a struct pointer to the next node.
        */
        struct StackNode
        {
            T value;//value that is stored in the node
            StackNode* next;//pointer to next nodr
        };

        StackNode* top;//node at the top of the stack
    public:
        
        //constructor function
        Stack()
        {
            top = NULL;
        }

        ~Stack();

        void push(T);
        void pop(T &);
        bool isEmpty();
};

/*
    Function Name: ~Stack()
    Function Purpose: deletes all of the elements in the stack, destructor function
    Parameters: none
    Returns: none
*/
template <typename T>
Stack<T>::~Stack()
{
    StackNode *nodeToDelete;//pointer to node being deleted 
    StackNode *nextNode;//pointer to the next node beneath top

   // Position nodePtr at the top of the stack.
   nodeToDelete = top;

   // Traverse the list deleting each node.
   while (nodeToDelete != NULL)
   {
      nextNode = nodeToDelete->next;
      delete nodeToDelete;
      nodeToDelete = nextNode;
   }
}

/*
    Function Name: push(T)
    Function Purpose: inserts a new element at the top of the stack
    Parameters: a item of type T
    Returns: none
*/
template <typename T>
void Stack<T>::push(T item)
{
    StackNode *newNode = NULL; // Pointer to a new node

   // Allocate a new node and store item in its value.
   newNode = new StackNode;
   newNode->value = item;

   // If there are no nodes in the list
   // make newNode the first node.
   if (isEmpty())
   {
      top = newNode;
      newNode->next = NULL;
   }
   else  // Otherwise, insert NewNode at top.
   {
      newNode->next = top;
      top = newNode;
   }
}



/*
    Function Name: pop(T &)
    Function Purpose: deletes the top element of the stack
    Parameters: an address of typename T
    Returns: none
*/
template <typename T>
void Stack<T>::pop(T &item)
{
    StackNode *temp = NULL; //pointer used to reassign top

    //process of not having a segmentation fault
    item = top->value;
    temp = top->next;
    delete top;
    top = temp;
}

/*
    Function Name: isEmpty()
    Function Purpose: checks to see if the stack is empty
    Parameters: None
    Returns: a boolean indicating whether the stack is empty or not
*/
template <typename T>
bool Stack<T>::isEmpty()
{
    bool empty; //is the stack empty or not
    
    //top points to null whenever the list is empty
    if(top == NULL)
    {
        empty = true; //stack is empty
    }else
    {
        empty = false; //stack is not empty
    }
    return empty;
}

#endif