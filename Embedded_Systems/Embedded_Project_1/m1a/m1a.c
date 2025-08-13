/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
    File Name: m1a.c
    Author: Tate Finley
    Class: ECE 4140
    Purpose: Alternate flashing between pico led and all four board leds.
*/

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
    gpio_init(PICOEDUB_LED0_PIN);
    gpio_init(PICOEDUB_LED1_PIN);
    gpio_init(PICOEDUB_LED2_PIN);
    gpio_init(PICOEDUB_LED3_PIN);

    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_set_dir(PICOEDUB_LED0_PIN, GPIO_OUT);
    gpio_set_dir(PICOEDUB_LED1_PIN, GPIO_OUT);
    gpio_set_dir(PICOEDUB_LED2_PIN, GPIO_OUT);
    gpio_set_dir(PICOEDUB_LED3_PIN, GPIO_OUT);
#endif
}

// Turn the LED on or off
void pico_set_led(bool led_on) {
#if defined(PICO_DEFAULT_LED_PIN)
    // Just set the GPIO on or off
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
#endif
}

void board_set_led(bool led_on) {
#if defined(PICO_DEFAULT_LED_PIN)
    // Just set the GPIO on or off
    gpio_put(PICOEDUB_LED0_PIN, led_on);
    gpio_put(PICOEDUB_LED1_PIN, led_on);
    gpio_put(PICOEDUB_LED2_PIN, led_on);
    gpio_put(PICOEDUB_LED3_PIN, led_on);
#endif   
}

int main() {
    pico_led_init();
    while (true) {
        pico_set_led(true);
        board_set_led(false);
        sleep_ms(LED_DELAY_MS);
        pico_set_led(false);
        board_set_led(true);
        sleep_ms(LED_DELAY_MS);
    }
}
