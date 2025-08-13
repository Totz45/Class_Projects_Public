/* 
 *        Lab #: 5
 *   Lab Title: Lab5.cpp
 * Author(s): Tate Finley
 *         Date: 2/25/22
 *   Purpose: This program will output a series of messages to 
              The Edubase_V2 board.
 */ 
 
#include "mbed.h" 
#include "TTU_X031.h" 
#include "SevenSegmentLED.h" 
#include "TextLCD.h" 
  
TextLCD lcd(TextLCD::LCD_CURSOR_ON_BLINKING_ON);
 
int main() 
{ 
    //clears the led display for next use
    lcd.cls(); 
    /*prints out sentence in quotation marks 
      Newline exists because the led can display
      only sixteen characters on the same line*/
    lcd.printf("Hello! My name \nis Tate Finley");
    //waits three seconds for next output
    wait_ms(3000);
    lcd.cls();
    //outputs sentence surrounded by quotation marks
    lcd.printf("My major is \nComputer Engr.");
    //waits three seconds
    wait_ms(3000);
    lcd.cls();
    //outputs goodbye on led display
    lcd.printf("Goodbye!\n");
    return 0;
}