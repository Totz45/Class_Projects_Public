/**************************************************************
 * FileName:         m3.c
 * Dependencies:     see INCLUDE section below 
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Purpose:
 * This program will be sent to be interpretted by the raspberry 
 * pi pico 2. This program will utilize the UART RX and TX
 * interrupts to send characters to a circular buffer which will
 * be encrypted if switch 5 on the eduboard is not pressed. Upon 
 * pressing switch 5 would decrypt the entire message. 
 *
 * In addition, a timer interrupt will be used to toggle the state
 * of LED 3 to blink at a rate of once per second upon Power On 
 * Reset (POR), a flash period of 0.2s on decryption, and able to
 * change when passed in the '!!!Snnnn' command where nnnn is a
 * four digit integer. 
 *
 * If the command '!!!L' is passed through the uart, the command
 * is replaced with the flash period of LED 3 during decryption.
 * The current state of this program outputs messages only on 
 * decryption. You will not see what you type until switch 5 is
 * pressed.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author            Date
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Tate Finley       11/14/2024 
 **************************************************************/

/* INCLUDE section*/
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "picoedub.h"
#include "circular_buffer.h"
#include "hardware/pll.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include "hardware/structs/pll.h"
#include "hardware/structs/clocks.h"
#include "hardware/uart.h"
#include "hardware/irq.h"

/* MACRO constant definitions */
#define UART_ID uart0

#ifndef BAUD_RATE
#define BAUD_RATE 57600 
#endif

#define UART_TX_PIN 0
#define UART_RX_PIN 1

#ifndef PRIVATE_KEY
#define PRIVATE_KEY "BOLDFEARLESSCONFIDENT"
#endif

/* MACRO function definitions */
#define ISLOWER(x)		(((x)>='a') && ((x)<='z'))
#define ISUPPER(x)		(((x)>='A') && ((x)<='Z'))
#define ISNUMERIC(x)	(((x)>='0') && ((x)<='9'))
#define TOLOWER(x)		((x)-'A'+'a')
#define TOUPPER(x)		((x)-'a'+'A')
#define COMMAND_L_SIZE    4
#define COMMAND_S_SIZE    8

/* Global variable initialization */
CIRCULAR_BUFFER CB_rxBuffer = {{0},0,0,0}; //buffer to service rx interrupts
CIRCULAR_BUFFER CB_txBuffer = {{0},0,0,0}; //buffer to service tx interrupts

uint8_t u8_index = 0;   // current indice of encrypted word
int8_t i8_LEDlight = 0; // 0 off, 1 on

/*****************************************************************
 * Function: void init_edub(void)
 * 
 * PreCondition: None
 * 
 * Input: None
 * 
 * Output: None
 * 
 * Side Effects: None
 * 
 * Overview: This routine initializes GPIO pins to the eduboard.
 *****************************************************************/
void init_edub() {
    gpio_init(PICOEDUB_LED3_PIN);
    gpio_set_dir(PICOEDUB_LED3_PIN, GPIO_OUT);
    
    /* The following lines initialize switch 5*/
    gpio_init(PICOEDUB_ROW0_PIN);
    gpio_set_dir(PICOEDUB_ROW0_PIN, GPIO_IN);
}

/*****************************************************************
 * Function: void set_eduboard_led3(bool)
 * 
 * PreCondition: init_edub() is called before
 * 
 * Input: Boolean
 * 
 * Output: None
 * 
 * Side Effects: None
 * 
 * Overview: This routine sets the state of LED 3 on the eduboard.
 *****************************************************************/
void set_eduboard_led3(bool b_LedState) {
#if defined(PICOEDUB_LED3_PIN)
    /* Set the GPIO on or off depending on parameter state*/
    gpio_put(PICOEDUB_LED3_PIN, b_LedState);
#endif
}

/*****************************************************************
 * Function: void eduboard_reset_row0(void)
 * 
 * PreCondition: init_edub() is called before
 * 
 * Input: None
 * 
 * Output: None
 * 
 * Side Effects: None
 * 
 * Overview: This routine resets row 0 on the eduboard to fix 
 *           the 'gpio remain high' hardware bug.
 *****************************************************************/
void reset_eduboard_row0() {
    gpio_set_dir(PICOEDUB_ROW0_PIN, GPIO_OUT);
    gpio_put(PICOEDUB_ROW0_PIN, false);
    gpio_set_dir(PICOEDUB_ROW0_PIN, GPIO_IN);
}

/*****************************************************************
 * Function: void blink_led3(int8_t)
 * 
 * PreCondition: init_edub() is called before
 * 
 * Input: 8-bit integer
 * 
 * Output: None
 * 
 * Side Effects: None
 * 
 * Overview: This routine toggles the state of LED3
 *****************************************************************/
void blink_led3(int8_t i8_LedState)
{
    if(i8_LedState == 1){
        set_eduboard_led3(true);
    }else{
        set_eduboard_led3(false); 
    }
}  


/*****************************************************************
 * Function: bool repeating_timer_callback(__unused struct repeating_timer)
 * 
 * PreCondition: struct repeating_timer is created
 * 
 * Input: __unused pointer to repeating_timer struct
 * 
 * Output: Boolean
 * 
 * Side Effects: None noted
 * 
 * Overview: This routine services the timer interupt by changing
 *           LED3's state.
 *****************************************************************/
bool repeating_timer_callback(__unused struct repeating_timer *t)
{
    i8_LEDlight = 1 - i8_LEDlight;
    blink_led3(i8_LEDlight);
    return true;
}


/*****************************************************************
 * Function: void encrypt_text(char *,char *,char *)
 * 
 * PreCondition: None
 * 
 * Input: three character pointers (one for message, one for key,
 *        one for encrypted message)
 * 
 * Output: None
 * 
 * Side Effects: Does not encrypt numbers in order to implement !!!L command.
 * 
 * Overview: This routine encrypts a message based on the vigenere cipher.
 *****************************************************************/
void encrypt_text(char *pc_plaintext, char *pc_Key, char *pc_vigeneretext) {
    int8_t i8_charEncrypted; /*Indice of character going to be encrypted*/
    int8_t i8_KeyIndex = 0;
    int32_t i32_KeyLength = strlen(pc_Key);
    for(i8_charEncrypted = 0; pc_plaintext[i8_charEncrypted] != '\0'; i8_charEncrypted++)
    {
        if(ISNUMERIC(pc_plaintext[i8_charEncrypted]))
        {
            pc_vigeneretext[i8_charEncrypted] = pc_plaintext[i8_charEncrypted];
        }else{
            pc_vigeneretext[i8_charEncrypted] = ((pc_plaintext[i8_charEncrypted] - 'A') + (pc_Key[i8_KeyIndex] - 'A')) % 26 + 'A';
            i8_KeyIndex = (i8_KeyIndex + 1) % i32_KeyLength;  
        }
        
    }
    /*Append null character to end of encrypted message*/
    i8_charEncrypted++;
    pc_vigeneretext[i8_charEncrypted] = '\0';    
}

/*****************************************************************
 * Function: void decrypt_text(char *,char *,char *)
 * 
 * PreCondition: None
 * 
 * Input: three character pointers (one for encrypted message, one 
 *        for key, one for message).
 * 
 * Output: None
 * 
 * Side Effects: Assumes number are not encrypted in order to implement 
 *               !!!L command.
 * 
 * Overview: This routine decrypts a message based on the vigenere cipher.
 *****************************************************************/
void decrypt_text(char *pc_vigeneretext, char *pc_Key, char *pc_plaintext) {
    int8_t i8_charDecrypted; /*Indice of character going to be decrypted*/
    int8_t i8_KeyIndex = 0;
    int32_t i32_KeyLength = strlen(pc_Key);
    for (i8_charDecrypted = 0; pc_vigeneretext[i8_charDecrypted] != '\0'; i8_charDecrypted++)
    {
        if(ISNUMERIC(pc_vigeneretext[i8_charDecrypted]))
        {
            pc_plaintext[i8_charDecrypted] = pc_vigeneretext[i8_charDecrypted];
        }else{
            pc_plaintext[i8_charDecrypted] = ((pc_vigeneretext[i8_charDecrypted] - 'A') - (pc_Key[i8_KeyIndex] - 'A') + 26) % 26 + 'A';
            i8_KeyIndex = (i8_KeyIndex + 1) % i32_KeyLength;
        }
        
    }
    /*Append null character to end of decrypted message*/
    i8_charDecrypted++;
    pc_plaintext[i8_charDecrypted] = '\0';   
}

/*****************************************************************
 * Function: void on_uart_rx(void)
 * 
 * PreCondition: uart_rx interrupt enabled
 * 
 * Input: None
 * 
 * Output: None
 * 
 * Side Effects: None noted.
 * 
 * Overview: This routine handles the rx interrupt from the raspberry
 *           pi pico 2 which passes the character into a circular buffer.
 *****************************************************************/
void on_uart_rx(){
    while(uart_is_readable(UART_ID)) {
        uint8_t u8_ch = uart_getc(UART_ID);
        push_circular_buffer(&CB_rxBuffer, u8_ch);
    }
}

/*****************************************************************
 * Function: void on_uart_tx(void)
 * 
 * PreCondition: uart_rx interrupt enabled
 * 
 * Input: None
 * 
 * Output: None
 * 
 * Side Effects: None noted.
 * 
 * Overview: This routine mimics the tx interrupt from the raspberry
 *           pi pico 2 which passes the character from a circular buffer
 *           to the terminal.
 *****************************************************************/
void on_uart_tx(){
    uint8_t u8_ch;
    if (uart_is_writable(UART_ID)){
        while (pop_circular_buffer(&CB_txBuffer, &u8_ch) != '\0') {
            uart_putc(UART_ID, u8_ch);
        }  
    }
    uart_set_irq_enables(UART_ID, true, false);
}

int main() {
    init_edub();
    stdio_init_all();
    
    /*Configure clock for 80 MHz*/
    clock_configure(clk_sys, CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLK_REF,0, 12 * MHZ, 12 * MHZ);
    pll_init(pll_sys, 2, 900000000, 3, 2); //150MHz
    clock_configure(clk_sys,CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX,
                CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, 150 * MHZ, 80 * MHZ);
    stdio_init_all(); 

    /*Configure uart with interrupts*/
    uart_init(UART_ID, (BAUD_RATE*150/80));
    gpio_set_function(UART_TX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_TX_PIN));
    gpio_set_function(UART_RX_PIN, UART_FUNCSEL_NUM(UART_ID, UART_RX_PIN));
    irq_set_exclusive_handler(UART0_IRQ, on_uart_rx);
    irq_set_enabled(UART0_IRQ, true);
    uart_set_irq_enables(UART_ID, true, false);
    
    uint8_t u8_ch; //character placeholder
    int32_t i32_toDigit = 0; //replaces the text from the !!!L command to i32_LEDperiod
    bool b_SW5;  //pushbutton state
    bool b_LED3 = true; //LED state
    bool b_digitValid; //verify nnnn inputs from !!!Snnnn command
    int32_t i32_LEDperiod = 1000; //flash period for LED3
    
    struct repeating_timer timer; //timer used for timing interrupt
    add_repeating_timer_ms((i32_LEDperiod/2), repeating_timer_callback, NULL, &timer);
    
    char ca_convertFrequency[COMMAND_L_SIZE] = {0}; //placeholder for i32_LEDperiod to char[] conversion
    char ca_checkLCommand[COMMAND_L_SIZE] = {0}; //check for !!!L command
    char ca_checkSCommand[COMMAND_S_SIZE] = {0}; //check for !!!Snnnn command
    char ca_plaintext[BUFFER_SIZE]; //decrypted text string
    char ca_vigeneretext[BUFFER_SIZE]; //encrypted text string
    
    CIRCULAR_BUFFER CB_DecryptedBuffer; //decrypted message in circular buffer form
    CIRCULAR_BUFFER CB_EncryptedBuffer; //encrypted message in circular buffer form
    init_circular_buffer(&CB_DecryptedBuffer);
    init_circular_buffer(&CB_EncryptedBuffer);
    
    while (true) {
        b_SW5 = gpio_get(PICOEDUB_ROW0_PIN);
        if(strncmp(&ca_checkSCommand[0],"!!!S",COMMAND_L_SIZE) == 0)
        {
            /*Convert char from terminal to 32-bit integer for i32_LEDperiod*/
            b_digitValid = true;
            for(int i = (COMMAND_S_SIZE-4); i < COMMAND_S_SIZE; i++)
            {
                if(ISNUMERIC(ca_checkSCommand[i]))
                {
                    i32_toDigit = (i32_toDigit * 10) + (ca_checkSCommand[i] - '0');
                }else{
                    b_digitValid = false;
                    break;
                }
            }
            /*Check Boundaries, Replace flash period if valid*/
            if((!b_digitValid) || (i32_toDigit <= 0))
            {
                i32_LEDperiod = i32_LEDperiod;
                i32_toDigit = 0;
            }else{
                i32_LEDperiod = i32_toDigit;
                cancel_repeating_timer(&timer);
                add_repeating_timer_ms(i32_LEDperiod, repeating_timer_callback, NULL, &timer);
                i32_toDigit = 0;
            }

            /*Reset Command for next call*/
            for(int i = 0; i < COMMAND_S_SIZE; i++)
            {
                ca_checkSCommand[i] = 0;
            }
        }else{ 
    
            if(b_SW5){
                /*Decryption flash period is 0.2s*/
                if(i32_LEDperiod != 200)
                {
                    cancel_repeating_timer(&timer);
                    i32_LEDperiod = 200;
                    add_repeating_timer_ms(i32_LEDperiod, repeating_timer_callback, NULL, &timer);
                }
                
                /*If switch 5 is pressed, the message is decrypted using the vigenere cipher*/
                char ca_EncryptText[BUFFER_SIZE]; //encrypted text string
                char ca_DecryptText[BUFFER_SIZE]; //decrypted text string
                int8_t i8_getEncryptedChar = 0;
                while(pop_circular_buffer(&CB_EncryptedBuffer, (uint8_t *)&ca_EncryptText[i8_getEncryptedChar]) != '\0')
                {
                    i8_getEncryptedChar++;
                }
                ca_EncryptText[i8_getEncryptedChar] = '\0';
                decrypt_text(ca_EncryptText, PRIVATE_KEY, ca_DecryptText);
                for(int i = 0; ca_DecryptText[i] != '\0'; i++)
                {
                    push_circular_buffer(&CB_DecryptedBuffer, ca_DecryptText[i]);
                    push_circular_buffer(&CB_txBuffer, ca_DecryptText[i]);
                }
            
                /*Call interrupt and get ready for new message*/
                on_uart_tx();
                u8_index = 0;
                for(int16_t i16_resetWord = 0; i16_resetWord < BUFFER_SIZE; i16_resetWord++)
                {
                    ca_EncryptText[i16_resetWord] = 0;
                    ca_DecryptText[i16_resetWord] = 0;
                }  

            }else{
                /*If switch 5 is not pressed encrypt message character by character*/
                if(pop_circular_buffer(&CB_rxBuffer, &u8_ch) != '\0')
                {
                    /*Check for commands*/
                    for(int8_t i = 1; i < COMMAND_L_SIZE; i++)
                    {
                        ca_checkLCommand[(i-1)] = ca_checkLCommand[i];
                    }
                    for(int8_t i = 1; i < COMMAND_S_SIZE; i++)
                    {
                        ca_checkSCommand[(i-1)] = ca_checkSCommand[i];
                    }
                    ca_checkLCommand[(COMMAND_L_SIZE - 1)] = u8_ch;
                    ca_checkSCommand[(COMMAND_S_SIZE - 1)] = u8_ch;

                    /*Encrypt message for no command found*/
                    if((strncmp(&ca_checkLCommand[0],"!!!L",COMMAND_L_SIZE) != 0) &&
                        (strncmp(&ca_checkSCommand[4],"!!!S",COMMAND_L_SIZE) != 0))
                    {
                        if((ISLOWER(u8_ch)) || (ISUPPER(u8_ch)))
                        {
                            if(ISLOWER(u8_ch))
                            {
                                u8_ch = TOUPPER(u8_ch);
                            }
                            if(u8_index == BUFFER_SIZE)
                            {
                                ca_plaintext[u8_index] = '\0';
                            }else{
                                ca_plaintext[u8_index] = u8_ch;
                                ca_plaintext[(u8_index+1)] = '\0';
                            }
                            encrypt_text(ca_plaintext, PRIVATE_KEY, ca_vigeneretext);
                            push_circular_buffer(&CB_EncryptedBuffer, ca_vigeneretext[u8_index]);
                            u8_index++;
                        }
                    }else{
                        /* Skip Encryption for commands */
                        if(strncmp(&ca_checkLCommand[0],"!!!L",COMMAND_L_SIZE) == 0){
                            /*Replace !!!L command for i32_LEDperiod flash period*/
                            if((i32_LEDperiod > 0) && (i32_LEDperiod < 10000))
                            {
                                sprintf(ca_convertFrequency,"%d",i32_LEDperiod); 
                                for(int i = 0; i < COMMAND_L_SIZE; i++)
                                {
                                    if(u8_index == BUFFER_SIZE)
                                    {
                                        ca_plaintext[u8_index] = '\0';
                                    }else{
                                        ca_plaintext[u8_index] = ca_convertFrequency[i];
                                        ca_plaintext[(u8_index+1)] = '\0';
                                    }
                                    if(ca_plaintext[u8_index] != '\0')
                                    {
                                        encrypt_text(ca_plaintext, PRIVATE_KEY, ca_vigeneretext);
                                        push_circular_buffer(&CB_EncryptedBuffer, ca_vigeneretext[u8_index]);
                                        u8_index++;
                                        ca_convertFrequency[i] = 0;
                                        ca_checkLCommand[i] = 0;
                                    }
                                }
                            }                            
                        }else{
                            /* !!!Snnnn command serviced elsewhere */
                        }
                    }        
                }
            }
            
        }
        reset_eduboard_row0();      
    }
}
