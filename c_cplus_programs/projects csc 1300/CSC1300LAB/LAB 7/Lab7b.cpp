/* 
 *        Lab #: 7
 *   Lab Title: Lab7b.cpp
 * Author(s): Tate Finley
 *         Date: 3/9/22
 *   Purpose: This program will use the potentiometer to read out
 *            and intepret values that will set a delay time for the
 *            speaker which continuously buzz if sw4 is pressed and 
 *            discretely buzzes if sw5 is pressed.
 */ 
 
#include "mbed.h" 
#include "TTU_X031.h" 
#include "SevenSegmentLED.h" 
#include "TextLCD.h" 
  
TextLCD lcd(TextLCD::LCD_CURSOR_ON_BLINKING_ON);
 
int main() 
{ 
    float f_value = pot.read(); //reads data from potentiometer
    int delay; //variable for wait time
    bool restart = false; //allows do-while loop to execute at least once before exiting
    
    //clears the led display for next use
    lcd.cls(); 

    //executes at least once 
    do {
        //loops until sw4 or sw5 are pressed
        while(!sw4 && !sw5) {
            lcd.printf("4: Con. 5: Dis.  Both to quit");
            wait_ms(100);
            lcd.cls();
        }
        //if both sw4 and sw5 are pressed, prints goodbye and exits do-while loop
        if (sw4 && sw5) {
            lcd.cls(); 
            lcd.printf("Goodbye");
            wait_ms(3000);
            lcd.cls();
            restart = false;
        } 
        //otherwise if only sw4 is pressed, a continuous buzz is heard
        else if (sw4 && !sw5) {
            wait_ms(500);
            lcd.cls();
            lcd.printf("Continuous Buzz\nSW4 to stop");
            
            //prevents do-while loop until after sw4 is released
            do {
                speaker = false;
            } while(sw4);
            
            //buzz is heard until sw4 is pressed again
            do {
                f_value = pot.read(); //reads from potentiometer
                delay = (f_value * 955) + 956; //delay depends solely on f_value
                speaker = true;  //click the buzzer 
                wait_us(delay);  //delay is an integer value (number of microseconds to wait) 
                speaker = false; //turn the buzzer off 
                wait_us(delay); //wait again
            } while(!sw4);
            
            //if sw4 is pressed again, loops to main menu
            if(sw4){
                wait_ms(500);
                restart = true;
            } 
        } 
        //if only sw5 is pressed, a discrete buzz is heard
        else if (sw5 && !sw4) {
            wait_ms(500);
            lcd.cls();
            lcd.printf("Discrete Buzz!\nSW5 to stop");
            
            /*this section of code will prevent the buzz from being heard until after
              the user releases the first sw5 press */
            do {
                speaker = false;
            } while(sw5);
            
            //buzzing sound is heard until second sw5 press
            do {
                f_value = pot.read();//reads value from potentiometer
                
                //assigned delay based on the potentiometer value in increment of 1/13
                if (f_value < 1/13.0) {
                    delay = 956;
                } else if (f_value < 2/13.0) {
                    delay = 1012;
                } else if (f_value < 3/13.0) {
                    delay = 1073;
                } else if (f_value < 4/13.0) {
                    delay = 1136;
                } else if (f_value < 5/13.0) {
                    delay = 1204;
                } else if (f_value < 6/13.0) {
                    delay = 1276;
                } else if (f_value < 7/13.0) {
                    delay = 1351;
                } else if (f_value < 8/13.0) {
                    delay = 1432;
                } else if (f_value < 9/13.0) {
                    delay = 1517;
                } else if (f_value < 10/13.0) {
                    delay = 1607;
                } else if (f_value < 11/13.0) {
                    delay = 1703;
                } else if (f_value < 12/13.0) {
                    delay = 1804;
                } else {
                    delay = 1911;
                }
                
                speaker = true;  //click the buzzer 
                wait_us(delay);  /* delay is assigned based on the if statements above.
                                    By tightining or loosing the screw a different buzz
                                    sound should be heard.*/ 
                speaker = false; //turn the buzzer off 
                wait_us(delay); //waits again
            } while(!sw5);
            
            //occurs if user presses sw5 a second time
            if(sw5){
                wait_ms(500);
                restart = true; //brings user to menu 
            } 
        }
    } while(restart); //loops over until both sw4 and sw5 are pressed
    
    return 0;
}