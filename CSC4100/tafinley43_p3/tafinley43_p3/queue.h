/*
    File name: queue.h
    Author: Tate Finley
    Purpose: Declarations for PCB and PCB queue data types and functions.
*/
#include <stdint.h>
#include <stdio.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct PCB {
    uint64_t *sp; //stack pointer
    uint32_t pid; //process id
    struct PCB *next;
} PCB_t;

typedef struct PCB_Q {
    PCB_t *head;                // Index of the head
    PCB_t *tail;                // Index of the tail
    uint32_t size;               // Current number of elements
} PCB_Q_t;

void init_PCB_Q_t(PCB_Q_t *q);

void enqueue(PCB_Q_t *q, PCB_t *pcb);

PCB_t *dequeue(PCB_Q_t *q);


#endif