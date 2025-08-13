/**************************************************************
 * FileName:         circular_buffer.h
 * Dependencies:     None
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Purpose:
 * This header file implements the circular buffer data structure
 * in c. 
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author            Date
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Tate Finley       11/14/2024 
 **************************************************************/

#include <stdint.h>

#define BUFFER_SIZE 128

typedef struct {
    uint8_t u8_Buffer[BUFFER_SIZE]; //storage for circular buffer elements
    volatile int8_t i8_Head; //frontmost element
    volatile int8_t i8_Tail; //last element added               
    volatile int8_t i8_CurrBufferCount; //number of characters in buffer             
} CIRCULAR_BUFFER;

/*****************************************************************
 * Function: void init_circular_buffer(CIRCULAR_BUFFER *)
 * 
 * PreCondition: None
 * 
 * Input: Pointer to a circular buffer
 * 
 * Output: None
 * 
 * Side Effects: None noted
 * 
 * Overview: This routine initializes the circular buffer.
 *****************************************************************/
void init_circular_buffer(CIRCULAR_BUFFER *pCB_cb) {
    pCB_cb->i8_Head = 0;
    pCB_cb->i8_Tail = 0;
    pCB_cb->i8_CurrBufferCount = 0;
}

/*****************************************************************
 * Function: void push_circular_buffer(CIRCULAR_BUFFER *, uint8_t)
 * 
 * PreCondition: circular buffer initialized
 * 
 * Input: Pointer to a circular buffer and a unsigned 8-bit integer
 * 
 * Output: None
 * 
 * Side Effects: None noted
 * 
 * Overview: This routine pushes a uint8_t intepreted as a character 
 *           onto the circular buffer.
 *****************************************************************/
void push_circular_buffer(CIRCULAR_BUFFER *pCB_cb, uint8_t u8_BufferData) {
    if (pCB_cb->i8_CurrBufferCount == BUFFER_SIZE) {
        // Buffer is full, overwrite the oldest data
        pCB_cb->i8_Tail = (pCB_cb->i8_Tail + 1) % BUFFER_SIZE;
    } else {
        pCB_cb->i8_CurrBufferCount++;
    }
    pCB_cb->u8_Buffer[pCB_cb->i8_Head] = u8_BufferData;
    pCB_cb->i8_Head = (pCB_cb->i8_Head + 1) % BUFFER_SIZE;
}

/*****************************************************************
 * Function: uint8_t pop_circular_buffer(CIRCULAR_BUFFER *, uint8_t *)
 * 
 * PreCondition: circular buffer initialized
 * 
 * Input: Pointer to a circular buffer and a pointer to an unsigned 
 *        8-bit integer
 * 
 * Output: uint8_t interpreted as a character
 * 
 * Side Effects: None noted
 * 
 * Overview: This routine appends a uint8_t interpreted as a character 
 *           from the circular buffer.
 *****************************************************************/
uint8_t pop_circular_buffer(CIRCULAR_BUFFER *pCB_cb, uint8_t *pu8_BufferData) {
    if (pCB_cb->i8_CurrBufferCount == 0) {
        // Buffer is empty
        return 0;
    }
    *pu8_BufferData = pCB_cb->u8_Buffer[pCB_cb->i8_Tail];
    pCB_cb->i8_Tail = (pCB_cb->i8_Tail + 1) % BUFFER_SIZE;
    pCB_cb->i8_CurrBufferCount--;
    return *pu8_BufferData;
}

/*****************************************************************
 * Function: uint8_t peek_circular_buffer(CIRCULAR_BUFFER *, uint8_t)
 * 
 * PreCondition: circular buffer initialized
 * 
 * Input: Pointer to a circular buffer and a pointer to an unsigned 
 *        8-bit integer
 * 
 * Output: uint8_t interpreted as a character
 * 
 * Side Effects: None noted
 * 
 * Overview: This routine retrieves the top character from the 
 *           circular buffer without removing it.
 *****************************************************************/
uint8_t peek_circular_buffer(CIRCULAR_BUFFER *pCB_cb, uint8_t *pu8_BufferData) {
    if (pCB_cb->i8_CurrBufferCount == 0) {
        // Buffer is empty
        return 0;
    }
    int8_t i8_RecentIndex = (pCB_cb->i8_Head - 1 + BUFFER_SIZE) % BUFFER_SIZE;
    *pu8_BufferData = pCB_cb->u8_Buffer[i8_RecentIndex];
    return *pu8_BufferData; // Success
}
