/*
    File name: kernal.c
    Author: Tate Finley
    Purpose: Implementing cooperative multitasking within an OS.
*/
#include "libos.h"
#include "process.h"

extern int box (unsigned int srow,unsigned int scol,unsigned int erow, unsigned int ecol);
extern void dispatch();
extern void go();

/*
    Function name: clear_scr()
    Purpose: clears the screen displayed in qemu.
    Parameters: four integers indicating start row, start column, end row, and 
                end column of the box.
    Returns: an integer indicating if the command is successfully executed
*/
int clear_scr(int start_row, int start_col, int end_row, int end_col)
{
    int width = term_txtwidth(); //max width
    int height = term_txtheight(); //max height
    for(int i = start_row; i <= end_row; i++)
    {
        for(int j = start_col; j <= end_col; j++)
        {
            //check boundaries
            if(i < 0 || j < 0)
            {
                return 1;
            }else if (i > height || j > width)
            {
               return 1;
            } 
            putc_to(i,j,' ');
        }
    }
    
    return 0; 
}

/*
    Function name: p1()
    Purpose: Serves as 1 of 4 processors accessed by the OS
    Parameters: None
    Returns: an integer, but runs forever
*/
int p1(){
    char message[] = "Process 1: 0";
    box(9,23,11,39);
    print_to(10,25,message);

    int num = 0;
    while(1)
    {
        char character = (num + '0');
        message[11] = character;
        print_to(10,25,message);
        num++;
        if(num > 9)
        {
            num = 0;
        }
        dispatch();
    }
}

/*
    Function name: p2()
    Purpose: Serves as 1 of 4 processors accessed by the OS
    Parameters: None
    Returns: an integer, but runs forever
*/
int p2(){
    char message[] = "Process 2: 0";
    box(13,23,15,39);
    print_to(14,25,message);

    int num = 0;
    while(1)
    {
        char character = (num + '0');
        message[11] = character;
        print_to(14,25,message);
        num++;
        if(num > 9)
        {
            num = 0;
        }
        dispatch();
    }
}

/*
    Function name: p3()
    Purpose: Serves as 1 of 4 processors accessed by the OS
    Parameters: None
    Returns: an integer, but runs forever
*/
int p3(){
    char message[] = "Process 3: 0";
    box(9,49,11,65);
    print_to(10,51,message);

    int num = 0;
    while(1)
    {
        char character = (num + '0');
        message[11] = character;
        print_to(10,51,message);
        num++;
        if(num > 9)
        {
            num = 0;
        }
        dispatch();
    }
}

/*
    Function name: p4()
    Purpose: Serves as 1 of 4 processors accessed by the OS
    Parameters: None
    Returns: an integer, but runs forever
*/
int p4(){
    char message[] = "Process 4: 0";
    box(13,49,15,65);
    print_to(14,51,message);

    int num = 0;
    while(1)
    {
        char character = (num + '0');
        message[11] = character;
        print_to(14,51,message);
        num++;
        if(num > 9)
        {
            num = 0;
        }
        dispatch();
    }
}

int main()
{ 
    int retval;
    clear_scr(0,0,47,127);
    print_to(0,1,"Running Processes");

    // Initialize the queue data structure
    init_PCB_Q_t(&ReadyQueue);

    //Create processes for each of the 4 functions
    retval = create_process(p1);
    if(retval != 0) return 1;

    retval = create_process(p2);
    if(retval != 0) return 1;

    retval = create_process(p3);
    if(retval != 0) return 1;

    retval = create_process(p4);
    if(retval != 0) return 1;

    go();

    return 0;
}
