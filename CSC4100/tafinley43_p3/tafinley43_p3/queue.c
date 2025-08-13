/*
    File name: queue.c
    Author: Tate Finley
    Purpose: Definitions for queue functions.
*/
#include "queue.h"

/*
    Function name: init_PCB_Q_t()
    Purpose: initializes Process Control Block Queue data structure.
    Parameters: pointer to object of type PCB_Q_t.
    Returns: None
*/
void init_PCB_Q_t(PCB_Q_t *q)
{
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

/*
    Function name: enqueue()
    Purpose: queues PCBs to be serviced by the OS after dequeue
    Parameters: pointer to object of type PCB_Q_t, and pointer to PCB.
    Returns: None
*/
void enqueue(PCB_Q_t *q, PCB_t *pcb)
{
    if(q->tail != NULL)
    {
        q->tail->next = pcb;
    }else{
        q->head = pcb;
    }
    q->tail = pcb;
    q->size++;
}

/*
    Function name: dequeue()
    Purpose: dequeues a PCB to be serviced by the OS
    Parameters: pointer to object of type PCB_Q_t.
    Returns: The PCB being serviced.
*/
PCB_t *dequeue(PCB_Q_t *q)
{
    PCB_t *process;
    if(q->head == NULL){
        return NULL;
    }
    process = q->head;
    q->head = q->head->next;
    if(q->head == NULL){
        q->tail = NULL;
    }
    q->size--;
    return process;
}
