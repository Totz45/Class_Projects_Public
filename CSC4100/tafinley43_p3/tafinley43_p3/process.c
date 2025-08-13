/*
    File name: process.c
    Author: Tate Finley
    Purpose: Definitions for stack and pcb allocation, and process creation.
*/
#include "process.h"

#define MAX_STACKS 10
uint64_t stacks[MAX_STACKS][1024]; //a stack with allocated memory space
uint32_t next_stack = 0; //current stack where a process is
PCB_t pcbs[MAX_STACKS]; //PCB for a process
uint32_t pcb_placement = 0; //a given PCB's location on queue
uint32_t next_pid = 0; //process id of next PCB

PCB_t *Running;
PCB_Q_t ReadyQueue;

/*
    Function name: alloc_stack()
    Purpose: allocate stack space for a PCB
    Parameters: None.
    Returns: memory space where the PCB can be allocated
*/
uint64_t *alloc_stack(){
    if(next_stack == MAX_STACKS) return NULL;
    return stacks[next_stack++];
}

/*
    Function name: alloc_pcb()
    Purpose: allocate a PCB for a process
    Parameters: None.
    Returns: a PCB for the process
*/
PCB_t *alloc_pcb(){
    if(pcb_placement >= MAX_STACKS) return NULL;
    return &pcbs[pcb_placement++];
}

/*
    Function name: create_process()
    Purpose: creates a process from a function
    Parameters: the code address of the function
    Returns: a integer in the case of successful creation of a process.
*/
int create_process(int (*code_address)()) {
    uint64_t *sp;
    uint64_t *stackptr = alloc_stack(); 

    if(stackptr == NULL) return -1;
       
    sp = stackptr + 1024;
   
    //context for gen purpose registers
    for(int i = 0; i < 33; i++)
    {
        sp--;
        *sp = 0;
    }
        
    *(sp+32) = (uint64_t)code_address;

    //Process Control Block creation and queueing  
    PCB_t *pcb = alloc_pcb();

    if(pcb == NULL) return -1;

    pcb->sp = sp;
    pcb->pid = next_pid++;

    enqueue(&ReadyQueue,pcb);

    return 0;
}