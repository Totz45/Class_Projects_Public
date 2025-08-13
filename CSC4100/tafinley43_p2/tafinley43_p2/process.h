/*
    File name: process.c
    Author: Tate Finley
    Purpose: Declarations for global variables and creation functions.
*/
#include "queue.h"

extern PCB_Q_t ReadyQueue;
extern PCB_t *Running;

extern uint64_t stacks[][1024];
extern uint32_t next_stack;
extern PCB_t pcbs[];
extern uint32_t advance;
extern uint32_t next_pid;

int create_process(int (*code_address)());

uint64_t *alloc_stack();
PCB_t *alloc_pcb();