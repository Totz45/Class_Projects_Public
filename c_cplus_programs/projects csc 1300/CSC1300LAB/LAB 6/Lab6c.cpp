/* 
 *        Lab #: 6
 *   Lab Title: Lab6c.cpp
 * Author(s): Tate Finley
 *         Date: 3/2/22
 *   Purpose: This program will output which switches are pressed.
 *            In addition, each switch, if turned on, corresponds to
 *            an LED on the EDUBASE board which reset before the program
 *            ends.
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
    
    //prints out ready in quotation marks
    lcd.printf("Ready");
    
    //waits one second for each output
    wait_ms(1000);
    lcd.printf("\n3 ");
    wait_ms(1000);
    lcd.printf("2 ");
    wait_ms(1000);
    lcd.printf("1 ");
    wait_ms(1000);
    
    //clears statement, now would be the time to press the switches
    lcd.cls();
    lcd.printf("Reading Switches");
    wait_ms(1000);

    /*if-else statements outputing what switches were pressed. 
      sw4 turns on led1, sw5 turns on led0 when pressed at this 
      point */
    if (sw4 && sw5) {
        lcd.printf("Both Pressed!");
        led0 = true;
        led1 = true;
    } else if (sw4) {
        lcd.printf("sw4 pressed!");
        led1 = true;
    } else if (sw5) {
        lcd.printf("sw5 pressed!");
        led0 = true;
    } else {
        lcd.printf("No input!");
    }
    wait_ms(5000);
    
    //clears the LCD and turns off LED's if active
    lcd.cls();
    led0 = false;
    led1 = false;

    //prints Goodbye... and ends program
    lcd.printf("Goodbye...");
    wait_ms(1000);
    lcd.cls();
    return 0;
}