.global dispatch
.global restore_context
.global go

.extern enqueue
.extern dequeue 
.extern ReadyQueue
.extern Running
.extern clear_timer

go:
    b   restore_context
dispatch: 
    /* 
        This function will later be turned into a service/interrupt call.
        stack layout:
        x0
        x2
        ...
        x28
        x29
        x30
        PSTATE
    */
    
    msr     DAIFSet, #0x2

    str     x1, [sp]
    mrs     x1, SP_EL0

    sub     x1, x1, 16*17
    
    stp     x0, x1, [x1, 16*0]
    stp     x2, x3, [x1, 16*1]
    stp     x4, x5, [x1, 16*2]
    stp     x6, x7, [x1, 16*3]
    stp     x8, x9, [x1, 16*4]
    stp     x10, x11, [x1, 16*5]
    stp     x12, x13, [x1, 16*6]
    stp     x14, x15, [x1, 16*7]
    stp     x16, x17, [x1, 16*8]
    stp     x18, x19, [x1, 16*9]
    stp     x20, x21, [x1, 16*10]
    stp     x22, x23, [x1, 16*11]
    stp     x24, x25, [x1, 16*12]
    stp     x26, x27, [x1, 16*13]
    stp     x28, x29, [x1, 16*14]
    str     x30, [x1, 16*15]

    mrs     x0, SPSR_EL1      // Save PSTATE
    str     x0, [x1, 16*15+8]
    mrs     x0, ELR_EL1       // Save interrupt return address       
    str     x0, [x1, 16*16]

    adr     x0, ReadyQueue
    adr     x4, Running 
    ldr     x4, [x4] 
    str     x1, [x4]  //    Then store the new sp in x1 to the PCB
    mov     x1, x4
    
    bl     enqueue
restore_context:

    adr   x0, ReadyQueue
    bl    dequeue

    //read value out of the function into the sp register
    adr   x1, Running
    str   x0, [x1]
    ldr   x2, [x0]
    mov   x1, x2

    ldr     x0, [x1, 16*15+8]   // Restore PSTATE
    msr     SPSR_EL1, x0
    ldr     x0, [x1, 16*16]   //Restore interrupt return address
    msr     ELR_EL1, x0

    mov     x0, x1        
    add     x0, x0, 16*17    
    msr     SP_EL0, x0

    //copy all registers from the stack
    ldp     x2, x3, [x1, 16*1]
    ldp     x4, x5, [x1, 16*2]
    ldp     x6, x7, [x1, 16*3]
    ldp     x8, x9, [x1, 16*4]
    ldp     x10, x11, [x1, 16*5]
    ldp     x12, x13, [x1, 16*6]
    ldp     x14, x15, [x1, 16*7]
    ldp     x16, x17, [x1, 16*8]
    ldp     x18, x19, [x1, 16*9]
    ldp     x20, x21, [x1, 16*10]
    ldp     x22, x23, [x1, 16*11]
    ldp     x24, x25, [x1, 16*12]
    ldp     x26, x27, [x1, 16*13]
    ldr     x28, [x1, 16*14]

    stp     x0, x1, [sp, 16*0] 
    bl      clear_timer
    ldp     x0, x1, [sp, 16*0] 
    ldp     x29, x30, [x1, 16*14+8]
    ldp     x0, x1, [sp, 16*0] 
    //ldr     x1, [sp, 8]
    
    msr     DAIFClr, #0x2

    eret
