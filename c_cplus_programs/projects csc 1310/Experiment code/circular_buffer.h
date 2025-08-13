#include <stdint.h>

#define BUFFER_SIZE 128

typedef struct {
    uint8_t c_Buffer[BUFFER_SIZE]; // Buffer array
    volatile int8_t i8_Head;
    volatile int8_t i8_Tail;               
    volatile int8_t i8_CurrBufferCount;              
} CIRCULAR_BUFFER;

/*
    Function Name: init_circular_buffer()
    Purpose: initializes the circular buffer
    Attributes: a circular buffer object
    Returns: None
*/
void init_circular_buffer(CIRCULAR_BUFFER *cb) {
    cb->i8_Head = 0;
    cb->i8_Tail = 0;
    cb->i8_CurrBufferCount = 0;
}

/*
    Function Name: push_circular_buffer()
    Purpose: pushes a character onto the circular buffer.
    Attributes: a circular buffer object and a character to insert.
    Returns: None
*/
void push_circular_buffer(CIRCULAR_BUFFER *cb, uint8_t c_BufferData) {
    if (cb->i8_CurrBufferCount == BUFFER_SIZE) {
        // Buffer is full, overwrite the oldest data
        cb->i8_Tail = (cb->i8_Tail + 1) % BUFFER_SIZE;
    } else {
        cb->i8_CurrBufferCount++;
    }
    cb->c_Buffer[cb->i8_Head] = c_BufferData;
    cb->i8_Head = (cb->i8_Head + 1) % BUFFER_SIZE;
}

/*
    Function Name: pop_circular_buffer()
    Purpose: appends a character from the circular buffer.
    Attributes: a circular buffer object and a pointer to reference a char which is the most recent insert.
    Returns: an integer indicating if the function successfully appends the char.
*/
int pop_circular_buffer(CIRCULAR_BUFFER *cb, uint8_t *pc_BufferData) {
    if (cb->i8_CurrBufferCount == 0) {
        // Buffer is empty
        return -1; // Or some error code
    }
    *pc_BufferData = cb->c_Buffer[cb->i8_Tail];
    cb->i8_Tail = (cb->i8_Tail + 1) % BUFFER_SIZE;
    cb->i8_CurrBufferCount--;
    return 0;
}

/*
    Function Name: peek_circular_buffer()
    Purpose: retrieves the top character from the circular buffer.
    Attributes: a circular buffer object and a pointer to reference a char which is the most recent insert.
    Returns: an integer indicating if the function successfully views the most recent char.
*/
int peek_circular_buffer(CIRCULAR_BUFFER *cb, uint8_t *pc_BufferData) {
    if (cb->i8_CurrBufferCount == 0) {
        // Buffer is empty
        return -1;
    }
    int8_t i8_RecentIndex = (cb->i8_Head - 1 + BUFFER_SIZE) % BUFFER_SIZE;
    *pc_BufferData = cb->c_Buffer[i8_RecentIndex];
    return 0; // Success
}
