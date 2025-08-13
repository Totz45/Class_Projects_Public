/*
    File name: m2b.c
    Author: Tate F.
    Class: ECE 4140
    Purpose: Encrypt and Decrypt a message sent by the computer to the pico board and back. 
             Use the LED to display which state the message is in.
*/
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "picoedub.h"
#include "circular_buffer.h"
#include "hardware/pll.h"
#include "hardware/clocks.h"
#include "hardware/structs/pll.h"
#include "hardware/structs/clocks.h"

//Actual BAUD RATE implemented, 0% ERROR.
#ifndef BAUD_RATE
#define BAUD_RATE 57600 
#endif

#ifndef DATA_BITS
#define DATA_BITS 8
#endif

#ifndef START_BIT
#define START_BIT 1
#endif

#ifndef STOP_BIT
#define STOP_BIT 1
#endif

#ifndef PRIVATE_KEY
#define PRIVATE_KEY "BOLDFEARLESSCONFIDENT"
#endif

/*
    Function Name: edub_init()
    Purpose: initialize GPIO pins to board.
    Attributes: None
    Returns: None
*/
void edub_init() {
    gpio_init(PICOEDUB_LED3_PIN);
    
    gpio_set_dir(PICOEDUB_LED3_PIN, GPIO_OUT);
    
    gpio_init(PICOEDUB_ROW0_PIN);//SW_5
    
    gpio_set_dir(PICOEDUB_ROW0_PIN, GPIO_IN);
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
void eduboard_reset_sw5() {
    gpio_set_dir(PICOEDUB_ROW0_PIN, GPIO_OUT);
    gpio_put(PICOEDUB_ROW0_PIN, false);
    gpio_set_dir(PICOEDUB_ROW0_PIN, GPIO_IN);
}

/*
    Function Name: SW_blink_all()
    Purpose: Serves as the initial state of the board upon boot
    Attributes: boolean based on current LED state
    Returns: None
*/
void SW_blink(bool led_on)
{
    if(led_on){
        eduboard_set_led3(true);
    }else{
        eduboard_set_led3(false); 
    }
}  

/*
    Function Name: encrypt_text()
    Purpose: encrypts a message based on the vigenere cipher.
    Attributes: two circular buffer objects indicating the decyrpted and encrypted message respectively,
                a pointer to a char array which is the encryption key, and an integer which is the length 
                of the message.
    Returns: None
*/
void encrypt_text(CIRCULAR_BUFFER *CB_Input, CIRCULAR_BUFFER *CB_Output, const char *pc_key, int32_t i32_offsetKeyIndex) {
    int32_t i32_keyLength = strlen(pc_key);
    int32_t i32_keyIndex = i32_offsetKeyIndex % i32_keyLength;
    char c_data;

    while (pop_circular_buffer(CB_Input, &c_data) == 0) {
        char c_encrypt = ((c_data - 'A') + (pc_key[i32_keyIndex] - 'A')) % 26 + 'A';
        push_circular_buffer(CB_Output, c_encrypt);
        i32_keyIndex = (i32_keyIndex + 1) % i32_keyLength;
    }
}

/*
    Function Name: decrypt_text()
    Purpose: decrypts a message based on the vigenere cipher.
    Attributes: two circular buffer objects indicating the encyrpted and decrypted message respectively,
                a pointer to a char array which is the encryption key, and an integer which is the length 
                of the message.
    Returns: None
*/
void decrypt_text(CIRCULAR_BUFFER *CB_Input, CIRCULAR_BUFFER *CB_Output, const char *pc_key) {
    int32_t i32_keyLength = strlen(pc_key);
    int32_t i32_keyIndex = 0;
    char c_data;

    while (pop_circular_buffer(CB_Input, &c_data) == 0) {
        char c_decrypt = ((c_data - 'A') - (pc_key[i32_keyIndex] - 'A') + 26) % 26 + 'A';
        push_circular_buffer(CB_Output, c_decrypt);
        i32_keyIndex = (i32_keyIndex + 1) % i32_keyLength;
    }
}

int main() {
    edub_init();
    stdio_init_all();
    clock_configure(clk_sys, CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLK_REF,0, 12 * MHZ, 12 * MHZ);
    pll_init(pll_sys, 2, 900000000, 3, 2); //150MHz
    clock_configure(clk_sys,CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX,
                CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, 150 * MHZ, 50 * MHZ);
    bool b_SW5;  //pushbutton state
    bool b_LED3 = true; //LED state
    char c_EncryptText[BUFFER_SIZE]; //encrypted text string
    char c_insertChar[1]; //placeholder to convert int to char
    int32_t i32_encryptLength = 0; //length of message
    CIRCULAR_BUFFER CB_in; //decrypted message
    CIRCULAR_BUFFER CB_out; //encrypted message
    init_circular_buffer(&CB_in);
    init_circular_buffer(&CB_out);
    while (true) {
        int c_plaintext = getchar_timeout_us(0);
        b_SW5 = gpio_get(PICOEDUB_ROW0_PIN);
        if(b_SW5){
            //If SW5 is pressed, the message is decrypted using the vigenere cipher
            if(c_plaintext != PICO_ERROR_TIMEOUT)
            {
                decrypt_text(&CB_out, &CB_in, PRIVATE_KEY);
                
                while(pop_circular_buffer(&CB_in, &c_EncryptText[i32_encryptLength]) == 0)
                {    
                    printf("%c",c_EncryptText[i32_encryptLength]);
                    i32_encryptLength++;
                }
                printf("\n");
                i32_encryptLength = 0;
            }
            sleep_ms(200);
            b_LED3 = !b_LED3;
            SW_blink(b_LED3);
        }else{
            //If SW5 is not pressed, the message is encrypted with the vigenere cipher
            if(c_plaintext != PICO_ERROR_TIMEOUT)
            {
                sprintf(c_insertChar,"%c",c_plaintext);
                c_EncryptText[i32_encryptLength] = c_insertChar[0];
                printf("Received: %c\n", c_EncryptText[i32_encryptLength]);
                if(c_EncryptText[i32_encryptLength] >= 'A' && c_EncryptText[i32_encryptLength] <= 'Z')
                {   
                    push_circular_buffer(&CB_in, c_EncryptText[i32_encryptLength]);
                    
                    encrypt_text(&CB_in, &CB_out, PRIVATE_KEY, i32_encryptLength);
                    
                    peek_circular_buffer(&CB_out, &c_EncryptText[i32_encryptLength]);

                    printf("Encrypted: %c\n", c_EncryptText[i32_encryptLength]);
                    i32_encryptLength++;

                }else{
                    printf("Unable to encrypt: %c\n", c_EncryptText[i32_encryptLength]);
                }
            }
            sleep_ms(500);
            b_LED3 = !b_LED3;
            SW_blink(b_LED3);
        }
        eduboard_reset_sw5();      
    }
}
