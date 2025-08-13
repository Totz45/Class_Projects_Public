/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*
    File name: m1c.c
    Author: Tate F.
    Class: ECE 4140
    Purpose: m1b but outputs a 4-bit hexadecimal code to serial output based on button combinations.
*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "picoedub.h"

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 250
#endif


// Initialize the GPIO for the LED
void pico_led_init(void) {
#ifdef PICO_DEFAULT_LED_PIN
    // A device like Pico that uses a GPIO for the LED will define PICO_DEFAULT_LED_PIN
    // so we can use normal GPIO functionality to turn the led on and off
    gpio_init(PICO_DEFAULT_LED_PIN);

    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

#endif
}

/*
    Function Name: edub_init()
    Purpose: initialize GPIO pins to board.
    Attributes: None
    Returns: None
*/
void edub_init() {
    //initialize GPIO pins to LEDs
    gpio_init(PICOEDUB_LED0_PIN);
    gpio_init(PICOEDUB_LED1_PIN);
    gpio_init(PICOEDUB_LED2_PIN);
    gpio_init(PICOEDUB_LED3_PIN);
    
    gpio_set_dir(PICOEDUB_LED0_PIN, GPIO_OUT);
    gpio_set_dir(PICOEDUB_LED1_PIN, GPIO_OUT);
    gpio_set_dir(PICOEDUB_LED2_PIN, GPIO_OUT);
    gpio_set_dir(PICOEDUB_LED3_PIN, GPIO_OUT);
    
    //Initialize GPIO pins to switches
    gpio_init(PICOEDUB_ROW0_PIN);
    gpio_init(PICOEDUB_ROW1_PIN);
    gpio_init(PICOEDUB_ROW2_PIN);
    gpio_init(PICOEDUB_ROW3_PIN);
    
    gpio_set_dir(PICOEDUB_ROW0_PIN, GPIO_IN);
    gpio_set_dir(PICOEDUB_ROW1_PIN, GPIO_IN);
    gpio_set_dir(PICOEDUB_ROW2_PIN, GPIO_IN);
    gpio_set_dir(PICOEDUB_ROW3_PIN, GPIO_IN);

    gpio_init(PICOEDUB_COL0_PIN);
    gpio_init(PICOEDUB_COL1_PIN);
    gpio_init(PICOEDUB_COL2_PIN);
    gpio_init(PICOEDUB_COL3_PIN);
    
    gpio_set_dir(PICOEDUB_COL0_PIN, GPIO_IN);
    gpio_set_dir(PICOEDUB_COL1_PIN, GPIO_IN);
    gpio_set_dir(PICOEDUB_COL2_PIN, GPIO_IN);
    gpio_set_dir(PICOEDUB_COL3_PIN, GPIO_IN);   
}

// Turn the LED on or off
void pico_set_led(bool led_on) {
#if defined(PICO_DEFAULT_LED_PIN)
    // Just set the GPIO on or off
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
#endif
}

/*
    Function Name: eduboard_set_led0()
    Purpose: sets the state of led 0.
    Attributes: None
    Returns: None
*/
void eduboard_set_led0(bool led_on) {
#if defined(PICOEDUB_LED0_PIN)
    // Just set the GPIO on or off
    gpio_put(PICOEDUB_LED0_PIN, led_on);
#endif
}

/*
    Function Name: eduboard_set_led1()
    Purpose: sets the state of led 1.
    Attributes: None
    Returns: None
*/
void eduboard_set_led1(bool led_on) {
#if defined(PICOEDUB_LED1_PIN)
    // Just set the GPIO on or off
    gpio_put(PICOEDUB_LED1_PIN, led_on);
#endif
}

/*
    Function Name: eduboard_set_led2()
    Purpose: sets the state of led 2.
    Attributes: None
    Returns: None
*/
void eduboard_set_led2(bool led_on) {
#if defined(PICOEDUB_LED2_PIN)
    // Just set the GPIO on or off
    gpio_put(PICOEDUB_LED2_PIN, led_on);
#endif
}

/*
    Function Name: eduboard_set_led3()
    Purpose: sets the state of led 3.
    Attributes: None
    Returns: None
*/
void eduboard_set_led3(bool led_on) {
#if defined(PICOEDUB_LED3_PIN)
    // Just set the GPIO on or off
    gpio_put(PICOEDUB_LED3_PIN, led_on);
#endif
}

/*
    Function Name: eduboard_reset_sw_row0()
    Purpose: reset row 0 to fix 'gpio remain high' hardware bug.
    Attributes: None
    Returns: None
*/
void eduboard_reset_row0() {
    gpio_set_dir(PICOEDUB_ROW0_PIN, GPIO_OUT);
    gpio_put(PICOEDUB_ROW0_PIN, false);
    gpio_set_dir(PICOEDUB_ROW0_PIN, GPIO_IN);
}

/*
    Function Name: eduboard_reset_sw_row1()
    Purpose: reset row 1 to fix 'gpio remain high' hardware bug.
    Attributes: None
    Returns: None
*/
void eduboard_reset_row1() {
    gpio_set_dir(PICOEDUB_ROW1_PIN, GPIO_OUT);
    gpio_put(PICOEDUB_ROW1_PIN, false);
    gpio_set_dir(PICOEDUB_ROW1_PIN, GPIO_IN);
}

/*
    Function Name: eduboard_reset_sw_row2()
    Purpose: reset row 2 to fix 'gpio remain high' hardware bug.
    Attributes: None
    Returns: None
*/
void eduboard_reset_row2() {
    gpio_set_dir(PICOEDUB_ROW2_PIN, GPIO_OUT);
    gpio_put(PICOEDUB_ROW2_PIN, false);
    gpio_set_dir(PICOEDUB_ROW2_PIN, GPIO_IN);
}

/*
    Function Name: eduboard_reset_sw_row3()
    Purpose: reset row 3 to fix 'gpio remain high' hardware bug.
    Attributes: None
    Returns: None
*/
void eduboard_reset_row3() {
    gpio_set_dir(PICOEDUB_ROW3_PIN, GPIO_OUT);
    gpio_put(PICOEDUB_ROW3_PIN, false);
    gpio_set_dir(PICOEDUB_ROW3_PIN, GPIO_IN);
}

/*
    Function Name: eduboard_reset_sw_col0()
    Purpose: reset column 0 to fix 'gpio remain high' hardware bug.
    Attributes: None
    Returns: None
*/
void eduboard_reset_col0() {
    gpio_set_dir(PICOEDUB_COL0_PIN, GPIO_OUT);
    gpio_put(PICOEDUB_COL0_PIN, false);
    gpio_set_dir(PICOEDUB_COL0_PIN, GPIO_IN);
}

/*
    Function Name: eduboard_reset_sw_col1()
    Purpose: reset column 1 to fix 'gpio remain high' hardware bug.
    Attributes: None
    Returns: None
*/
void eduboard_reset_col1() {
    gpio_set_dir(PICOEDUB_COL1_PIN, GPIO_OUT);
    gpio_put(PICOEDUB_COL1_PIN, false);
    gpio_set_dir(PICOEDUB_COL1_PIN, GPIO_IN);
}

/*
    Function Name: eduboard_reset_sw_col2()
    Purpose: reset column 2 to fix 'gpio remain high' hardware bug.
    Attributes: None
    Returns: None
*/
void eduboard_reset_col2() {
    gpio_set_dir(PICOEDUB_COL2_PIN, GPIO_OUT);
    gpio_put(PICOEDUB_COL2_PIN, false);
    gpio_set_dir(PICOEDUB_COL2_PIN, GPIO_IN);
}

/*
    Function Name: eduboard_reset_sw_col3()
    Purpose: reset column 3 to fix 'gpio remain high' hardware bug.
    Attributes: None
    Returns: None
*/
void eduboard_reset_col3() {
    gpio_set_dir(PICOEDUB_COL3_PIN, GPIO_OUT);
    gpio_put(PICOEDUB_COL3_PIN, false);
    gpio_set_dir(PICOEDUB_COL3_PIN, GPIO_IN);
}

/*
    Function Name: eduboard_reset_sw_row()
    Purpose: reset rows to fix 'gpio remain high' hardware bug.
    Attributes: None
    Returns: None
*/
void eduboard_reset_sw_row() {
    eduboard_reset_row0();
    eduboard_reset_row1();
    eduboard_reset_row2();
    eduboard_reset_row3();   
}


/*
    Function Name: eduboard_reset_sw_col()
    Purpose: reset columns to fix 'gpio remain high' hardware bug.
    Attributes: None
    Returns: None
*/
void eduboard_reset_sw_col() {
    eduboard_reset_col0();
    eduboard_reset_col1();
    eduboard_reset_col2();
    eduboard_reset_col3();
}

/*
    Function Name: SW_blink_all()
    Purpose: Serves as the initial state of the board upon boot
    Attributes: boolean based on current LED state
    Returns: None
*/
void SW_blink_all(bool led_on)
{
    if(led_on)
    {
        eduboard_set_led0(true);
        eduboard_set_led1(true);
        eduboard_set_led2(true);
        eduboard_set_led3(true);
    }else{
        eduboard_set_led0(false); 
        eduboard_set_led1(false);
        eduboard_set_led2(false); 
        eduboard_set_led3(false); 
    }

}

/*
    Function Name: SW_blink()
    Purpose: reflect the current state of row presses displayed on the LEDs
    Attributes: boolean based on current LED state
    Returns: None
*/
void SW_blink(bool led_on)
{    
    bool LED0 = gpio_get(PICOEDUB_COL3_PIN);
    bool LED1 = gpio_get(PICOEDUB_COL2_PIN);
    bool LED2 = gpio_get(PICOEDUB_COL1_PIN);
    bool LED3 = gpio_get(PICOEDUB_COL0_PIN);

    //check columns on current row
    //if corresponding switch pressed, toggle LED
    //else, turn LED off
    if(LED0){
        if(led_on)
        {
            eduboard_set_led0(true);
        }else{
            eduboard_set_led0(false); 
        }
    }else{
        eduboard_set_led0(false);
    }

    if(LED1){
        if(led_on)
        {
            eduboard_set_led1(true);
        }else{
            eduboard_set_led1(false); 
        }
    }else{
        eduboard_set_led1(false);
    }

    if(LED2){
        if(led_on)
        {
            eduboard_set_led2(true);
        }else{
            eduboard_set_led2(false); 
        }
    }else{
        eduboard_set_led2(false);
    }

    if(LED3){
        if(led_on)
        {
            eduboard_set_led3(true);
        }else{
            eduboard_set_led3(false); 
        }
    }else{
        eduboard_set_led3(false);
    }

    eduboard_reset_sw_col();
}

/*
    Function Name: program_SW()
    Purpose: detect which switch has been pressed on the eduboard
    Attributes: boolean based on current LED state
    Returns: None
*/
void program_SW(bool led_on)
{    
    bool SW_2 = gpio_get(PICOEDUB_ROW3_PIN);
    bool SW_3 = gpio_get(PICOEDUB_ROW2_PIN);
    bool SW_4 = gpio_get(PICOEDUB_ROW1_PIN);
    bool SW_5 = gpio_get(PICOEDUB_ROW0_PIN);

    if(SW_2 && !SW_3 && !SW_4 && !SW_5) {
        SW_blink(led_on);
    }else if(SW_3 && !SW_2 && !SW_4 && !SW_5) {
        SW_blink(led_on);
    }else if(SW_4 && !SW_3 && !SW_2 && !SW_5) {
        SW_blink(led_on);
    }else if(SW_5 && !SW_3 && !SW_4 && !SW_2) {
        SW_blink(led_on);
    }else{   
        SW_blink_all(led_on);
    }    

    eduboard_reset_sw_row();
}

/*
    Function Name: set_char()
    Purpose: converts decimal to hexadecimal character
    Attributes: integer which is the number to be converted
    Returns: character as hexadecimal.
*/
char set_char(int string)
{
    if(string == 0)
    {
        return '0';
    }else if(string == 1)
    {
        return '1';
    }else if(string == 2)
    {
        return '2';
    }else if(string == 3)
    {
        return '3';
    }else if(string == 4)
    {
        return '4';
    }else if(string == 5)
    {
        return '5';
    }else if(string == 6)
    {
        return '6';
    }else if(string == 7)
    {
        return '7';
    }else if(string == 8)
    {
        return '8';
    }else if(string == 9)
    {
        return '9';
    }else if(string == 10)
    {
        return 'A';
    }else if(string == 11)
    {
        return 'B';
    }else if(string == 12)
    {
        return 'C';
    }else if(string == 13)
    {
        return 'D';
    }else if(string == 14)
    {
        return 'E';
    }else if(string == 15)
    {
        return 'F';
    }else{
        return '0';
    }
}

/*
    Function Name: send_serial_code()
    Purpose: send button combinations as a 4-bit hexadecimal code to serial output
    Attributes: integer pointer to int array
    Returns: None
*/
void send_serial_code(int* digit)
{
    bool ROW3 = gpio_get(PICOEDUB_ROW3_PIN);
    bool ROW2 = gpio_get(PICOEDUB_ROW2_PIN);
    bool ROW1 = gpio_get(PICOEDUB_ROW1_PIN);
    bool ROW0 = gpio_get(PICOEDUB_ROW0_PIN);
    bool COL3 = gpio_get(PICOEDUB_COL3_PIN);
    bool COL2 = gpio_get(PICOEDUB_COL2_PIN);
    bool COL1 = gpio_get(PICOEDUB_COL1_PIN);
    bool COL0 = gpio_get(PICOEDUB_COL0_PIN);

    int count[4] = {0,0,0,0}; //rolling count

    //update whenever row/col combination is pressed
    if(COL3)
    {  
        if(COL3 && ROW3)
        {
            count[0] += 1;
        }
        if(COL3 && ROW2)
        {
            count[1] += 1;
        }
        if(COL3 && ROW1)
        {
            count[2] += 1;
        }
        if(COL3 && ROW0)
        {
            count[3] += 1;
        }
    }
    if(COL2)
    {
        if(COL2 && ROW3)
        {
            count[0] += 2;
        }
        if(COL2 && ROW2)
        {
            count[1] += 2;
        }
        if(COL2 && ROW1)
        {
            count[2] += 2;
        }
        if(COL2 && ROW0)
        {
            count[3] += 2;
        }
    }
    if(COL1)
    {
        if(COL1 && ROW3)
        {
            count[0] += 4;
        }
        if(COL1 && ROW2)
        {
            count[1] += 4;
        }
        if(COL1 && ROW1)
        {
            count[2] += 4;
        }
        if(COL1 && ROW0)
        {
            count[3] += 4;
        }
    }
    if(COL0)
    {
        if(COL0 && ROW3)
        {
            count[0] += 8;
        }
        if(COL0 && ROW2)
        {
            count[1] += 8;
        }
        if(COL0 && ROW1)
        {
            count[2] += 8;
        }
        if(COL0 && ROW0)
        {
            count[3] += 8;
        }
    }

    //send code to serial port
    char code[4];
    code[0] = set_char(count[0]);
    code[1] = set_char(count[1]);
    code[2] = set_char(count[2]);
    code[3] = set_char(count[3]);
    printf(code);
    digit = count;

}

int main() {
    pico_led_init();
    edub_init();
    stdio_init_all();
    int digit[4] = {0,0,0,0};
    while (true) {
        pico_set_led(true);
        program_SW(false);
        send_serial_code(digit);
        sleep_ms(LED_DELAY_MS);
        pico_set_led(false);
        program_SW(true);
        send_serial_code(digit);
        sleep_ms(LED_DELAY_MS);       
    }
}
