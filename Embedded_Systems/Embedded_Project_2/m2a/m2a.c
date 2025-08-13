/*
    File Name: m2a.c
    Author: Tate Finley
    Class: ECE 4140
    Purpose: Flash LED 0 at four different clocking frequencies.
*/

#include "pico/stdlib.h"
#include "picoedub.h"
#include "hardware/pll.h"
#include "hardware/clocks.h"
#include "hardware/structs/pll.h"
#include "hardware/structs/clocks.h"
#include <stdio.h>


#ifndef SOMENUMBER
#define SOMENUMBER 4166666
#endif

// Initialize the GPIO for the LED
void init_pico_led(void) {
    // A device like Pico that uses a GPIO for the LED will define PICO_DEFAULT_LED_PIN
    // so we can use normal GPIO functionality to turn the led on and off
    //gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_init(PICOEDUB_LED0_PIN);

    gpio_set_dir(PICOEDUB_LED0_PIN, GPIO_OUT);
}


void set_board_led(bool led_on) {
    // Just set the GPIO on or off
    gpio_put(PICOEDUB_LED0_PIN, led_on);
}

int main() {
    init_pico_led();
    clock_configure(clk_sys, CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLK_REF,0, 12 * MHZ, 12 * MHZ);
    pll_init(pll_sys, 2, 900000000, 3, 2); //150MHz
    clock_configure(clk_sys,CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX,
                    CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, 150 * MHZ, 25 * MHZ);
    //clock_configure(clk_sys,CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX,
    //                CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, 150 * MHZ, 50 * MHZ);
    //clock_configure(clk_sys,CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX,
    //                CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, 150 * MHZ, 100 * MHZ);
    //clock_configure(clk_sys,CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX,
    //                CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, 150 * MHZ, 150 * MHZ);
    bool b_LedState = true;
    while (true) {  
        //SOMENUMBER can be derived from the amount of time to run the assembly code for the for loop
        //assuming worst case scenario (3) plus the amount of state changes to complete one cycle (2)
        //divided by 25 MHz.
        for(int i = 0;i < SOMENUMBER; i++)
        {}
        b_LedState = !b_LedState;
        set_board_led(b_LedState);
    }
}
