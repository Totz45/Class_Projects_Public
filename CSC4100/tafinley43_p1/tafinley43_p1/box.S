.section .data
add_corner:	    .byte    '+'
add_to_top_bottom: 	    .byte    '-'
add_to_right_left:	    .byte    '|'
.section .text
.global     box

.extern     term_txtheight
.extern     term_txtwidth
.extern     print_to  
.extern     putc_to 
box:
 
    // standard entry: save link and stack frame registers
    //    load the stack frame with the pointer to current frame
    stp     x29, x30, [sp, -16]!

    // Save the arguments.  Called functions may overwrite x0-x3
    sub     sp, sp, 32
    stp     x0, x1, [sp]
    stp     x2, x3, [sp, 16]
    
    // sr in w0, sc in w1, er in w2, ec in w3
    
    // Make sure the argument are valid    
    bl      _box_check_box_
    cmp     w0, 0
    bne     _box_error_

 
    // first, draw the corners:
    // +        +
    // +        +
    ldp     x0, x1, [sp]
    ldp     x2, x3, [sp, 16]
    bl      _box_draw_corners_

    // Now, draw the top and bottom:
    // +------+
    // +------+
    ldp     x0, x1, [sp]
    ldp     x2, x3, [sp, 16]
    bl      _box_draw_top_bottom_
    
    // draw left and right sides
    ldp     x0, x1, [sp]
    ldp     x2, x3, [sp, 16]
    bl      _box_draw_right_left_

    mov     w0, 0
    b       _box_exit_

_box_check_box_:
    stp     x29, x30, [sp, -16]!
    
    sub     sp, sp, 32
    stp     x0, x1, [sp]
    stp     x2, x3, [sp, 16]
    //get height and compare to end_row
       
    bl      term_txtheight  
    mov     w4, w0
    bl      term_txtwidth
    mov     w5, w0
    //get width and compare to end_column
    
    ldr	    w0, [sp] 
    cmp	    w0, 0
    blt     _return_1
    cmp     w0, w4
    bge     _return_1
    ldr     w1, [sp, 8]
    cmp	    w1, 0
    blt     _return_1
    cmp     w1, w5
    bge     _return_1
    
    ldr     w2, [sp, 16]
    ldr     w3, [sp, 24]
    //compare end_row with start_row
    cmp     w2, w0
    ble     _return_1
    //compare end_column with start_column
    cmp     w3, w1
    ble     _return_1
    
    //return if conditions are met
    mov     w0, 0
    b       _return_0
    
_return_1:
    //return 1
    mov     w0, 1   
_return_0:
    add     sp, sp, 32   // pop save arg regs
    ldp     x29, x30, [sp], 16
    ret


_box_draw_corners_:
    stp     x29, x30, [sp, -16]!

    // save our parameters away because we call functions
    //   that may destroy them
    sub     sp, sp, 32
    stp     x0, x1, [sp]
    stp     x2, x3, [sp, 16]
    
    ldr     w0, [sp]
    ldr     w1, [sp, 8]   
    adr     x2, add_corner
    ldr	    w2, [x2] 
    
    //send start_row, start_column, and corner to function
    bl      putc_to
    ldr     w0, [sp]
    ldr     w1, [sp, 24] 
    adr     x2, add_corner
    ldr	    w2, [x2] 
    
    //send start_row, end_column, and corner to function
    bl      putc_to
    ldr     w0, [sp, 16] 
    ldr     w1, [sp, 8]
    adr     x2, add_corner
    ldr	    w2, [x2] 
    
    //send end_row, start_column, and corner to function
    bl      putc_to
    ldr     w0, [sp, 16]
    ldr     w1, [sp, 24] 
    adr     x2, add_corner
    ldr	    w2, [x2] 
    
    //send end_row, end_column, and corner to function
    bl      putc_to
    add     sp, sp, 32   // pop save arg regs
    ldp     x29, x30, [sp], 16
    ret
    
_box_draw_top_bottom_:
    stp     x29, x30, [sp, -16]!
    
    sub     sp, sp, 32
    stp     x0, x1, [sp]
    stp     x2, x3, [sp, 16]
    
    mov     w3, 1 
    //iterate to create top side
_loop_top_:
    ldr     w0, [sp]
    ldr     w1, [sp, 8]
    ldr     w4, [sp, 24]
    add     w1, w1, w3
    adr     x2, add_to_top_bottom
    ldr     w2, [x2]
    cmp     w1, w4
    bge     continue_bottom
    
    bl      putc_to
    add     w3, w3, 1
    b 	    _loop_top_
    
continue_bottom:
    mov     w3, 1
    
    //iterate to create bottom side
_loop_bottom_:
    ldr     w0, [sp, 16]
    ldr     w1, [sp, 8]
    ldr     w4, [sp, 24]
    add     w1, w1, w3
    adr     x2, add_to_top_bottom
    ldr     w2, [x2]
    cmp     w1, w4
    bge     _top_bottom_done_
    
    bl      putc_to
    add     w3, w3, 1
    b 	    _loop_bottom_   
     	  
_top_bottom_done_:
    add     sp, sp, 32 
    ldp     x29, x30, [sp], 16
    ret

_box_draw_right_left_:
    stp     x29, x30, [sp, -16]!
    
    sub     sp, sp, 32
    stp     x0, x1, [sp]
    stp     x2, x3, [sp, 16]
    
    mov     w3, 1 
    
    //iterate to create right side
_loop_right_:
    ldr     w0, [sp]
    ldr     w1, [sp, 8]
    ldr     w4, [sp, 16]
    add     w0, w0, w3
    adr     x2, add_to_right_left
    ldr     w2, [x2]
    cmp     w0, w4
    bge     continue_left
    
    bl      putc_to
    add     w3, w3, 1
    b 	    _loop_right_
    
continue_left:
    mov     w3, 1
    //iterate to create left side
_loop_left_:
    ldr     w0, [sp]
    ldr     w1, [sp, 24]
    ldr     w4, [sp, 16]
    add     w0, w0, w3
    adr     x2, add_to_right_left
    ldr     w2, [x2]
    cmp     w0, w4
    bge     _right_left_done_
    
    sub     sp, sp, 16
    str     x30, [sp]
    bl      putc_to
    ldr     x30, [sp]
    add     sp, sp, 16
    add     w3, w3, 1
    b 	    _loop_left_   
     	  
_right_left_done_:
    add     sp, sp, 32
    ldp     x29, x30, [sp], 16
    ret
    
_box_error_:
    mov     w0, 1
    
_box_exit_:
    add     sp, sp, 32   // pop save arg regs
    ldp     x29, x30, [sp], 16
    ret
