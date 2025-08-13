/*
    File name: m2b.c
    Author: Tate F.
    Class: ECE 4140
    Purpose: Encrypt and Decrypt a message sent by the computer to the pico board and back. 
             Use the LED to display which state the message is in.
*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "circular_buffer.h"


#ifndef PRIVATE_KEY
#define PRIVATE_KEY "BOLDFEARLESSCONFIDENT"
#endif

CIRCULAR_BUFFER CB_rxBuffer = {{0},0,0,0}; //buffers for interupts
CIRCULAR_BUFFER CB_txBuffer = {{0},0,0,0}; //buffers for interupts

/*
    Function Name: encrypt_text()
    Purpose: encrypts a message based on the vigenere cipher.
    Attributes: two circular buffer objects indicating the decyrpted and encrypted message respectively,
                a pointer to a char array which is the encryption key, and an integer which is the length 
                of the message.
    Returns: None
*/
void encrypt_text(char *pc_plaintext, char *pc_Key, char *pc_vigeneretext) {
    int8_t i8_charEncrypted = 0;
    int8_t i8_findNullChar = 0;
    int32_t i32_KeyLength = strlen(pc_Key);
    for (i8_charEncrypted = 0; pc_plaintext[i8_charEncrypted] != '\0'; i8_charEncrypted++)
    {
        pc_vigeneretext[i8_charEncrypted] = ((pc_plaintext[i8_charEncrypted] - 'A') + (pc_Key[i8_findNullChar] - 'A')) % 26 + 'A';
        i8_findNullChar = (i8_findNullChar + 1) % i32_KeyLength;
    }
    pc_vigeneretext[i8_charEncrypted] = '\0';    
}

/*
    Function Name: decrypt_text()
    Purpose: decrypts a message based on the vigenere cipher.
    Attributes: two circular buffer objects indicating the encyrpted and decrypted message respectively,
                a pointer to a char array which is the encryption key, and an integer which is the length 
                of the message.
    Returns: None
*/
void decrypt_text(char *pc_plaintext, char *pc_Key, char *pc_vigeneretext) {
    int8_t i8_charEncrypted = 0;
    int8_t i8_findNullChar = 0;
    int32_t i32_KeyLength = strlen(pc_Key);
    for (i8_charEncrypted = 0; pc_vigeneretext[i8_charEncrypted] != '\0'; i8_charEncrypted++)
    {
        pc_plaintext[i8_charEncrypted] = ((pc_vigeneretext[i8_charEncrypted] - 'A') - (pc_Key[i8_findNullChar] - 'A') + 26) % 26 + 'A';
        i8_findNullChar = (i8_findNullChar + 1) % i32_KeyLength;
    }
    pc_plaintext[i8_charEncrypted] = '\0';   
}


int main() {
    bool b_SW5;  //pushbutton state
    bool b_LED3 = true; //LED state
    char ca_plaintext[BUFFER_SIZE]; //encrypted text string
    char ca_vigeneretext[BUFFER_SIZE]; //encrypted text string
    CIRCULAR_BUFFER CB_DecryptedBuffer; //decrypted message
    CIRCULAR_BUFFER CB_EncryptedBuffer; //encrypted message
    init_circular_buffer(&CB_DecryptedBuffer);
    init_circular_buffer(&CB_EncryptedBuffer);
    while (true) {
            
            
            encrypt_text(ca_plaintext, PRIVATE_KEY, ca_vigeneretext);
            for (int i = 0; ca_vigeneretext[i] != '\0'; i++) 
            { 
                push_circular_buffer(&CB_EncryptedBuffer, ca_vigeneretext[i]);
            }

            //If SW5 is pressed, the message is decrypted using the vigenere cipher
            char ca_EncryptText[BUFFER_SIZE]; //encrypted text string
            char ca_DecryptText[BUFFER_SIZE]; //encrypted text string
            int8_t i8_getEncryptedChar = 0;
            while(pop_circular_buffer(&CB_EncryptedBuffer, (uint8_t *)&ca_EncryptText[i8_getEncryptedChar]))
            {
                i8_getEncryptedChar++;
            }
            ca_EncryptText[i8_getEncryptedChar] = '\0';
            decrypt_text(ca_EncryptText, PRIVATE_KEY, ca_DecryptText);
            for(int i8_getEncryptedChar = 0; ca_DecryptText[i8_getEncryptedChar] != '\0'; i8_getEncryptedChar++)
            {
                push_circular_buffer(&CB_DecryptedBuffer, ca_DecryptText[i8_getEncryptedChar]);
            }  
    }
}
