/*
    File name: kernal.c
    Author: Tate Finley
    Purpose: Create an initial code for an OS that displays a hello box.
*/

#include "libos.h"

/*
    Function name: box()
    Purpose: Creates a box in qemu
    Parameters: four integers indicating start row, start column, end row, and 
                end column of the box.
    Returns: an integer indicating if the command is successfully executed 
*/
int box (unsigned int srow,unsigned int scol,unsigned int erow, unsigned int ecol);

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

int main()
{ 
    clear_scr(21,49,27,79);
    box(21,49,27,79);
    print_to(24,59,"Hello world");
    return 0;
}
