/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
	/*Code Contributors
	Tate Finley: Bugfixing, Algorithm for digits and sums, and addition/subtraction menu
	Nathen Rosasco: Iterative program, # and A-D functions.
	Jesse Munoz: Multiplication and Division menu and functions    */
#include "main.h"
void SystemClock_Config(void);
/**
  * @brief  The application entry point.
  * @retval int
  */
     

void Write_String_LCD(char*);
void Write_Char_LCD(uint8_t);
void Write_Instr_LCD(uint8_t);
void LCD_nibble_write(uint8_t, uint8_t);
void Write_SR_LCD(uint8_t);
void Delay(unsigned int);

void LCD_Init(void);

void Keypad_Init(void);
uint8_t Read_Keypad(void);

int main(void)
{
       char* line1;
       line1 =" Select "; /*line 1 string */
     
             char* line2; /* line 2 string*/
       line2 ="Operation ";

  HAL_Init();
  SystemClock_Config();

  LCD_Init();
     
      Keypad_Init();
      /*Write prompt*/
      Write_String_LCD(line1); 
      Write_Instr_LCD(0xC0);
      Write_String_LCD(line2);
      Delay(1000);
      Write_Instr_LCD(0x01);
     
      unsigned int cursor = 1; /*checks if the cursor is on the first or second line*/

      unsigned int enter=0; /*operation to perform*/
      unsigned int operation=0; /*Select the operation from menu*/
      /*You must press a button to clear the screen before keypad inputs are registered*/
			/*digits of the first value*/
      uint8_t digit1;
      uint8_t digit2;
      uint8_t digit3;
      uint8_t digit4;
      uint8_t digit5;
			/*digits of the second value*/
      uint8_t sdigit1;
      uint8_t sdigit2;
      uint8_t sdigit3;
      uint8_t sdigit4;
      uint8_t sdigit5;
      int sum; /*Number for first value to calculate*/
      sum = 0;
      int sum2; /*Number for second value to calculate*/
      sum2 = 0;
      int answer; /*answer from given responses*/
      answer = 0;
			int divideZero;/*divide by zero error flag*/
			/*negative number flags*/
			int neg1;
			int neg2;
			neg2 = 0;
			neg1 = 0;
			int r;
			r = 0;
			divideZero = 0;
			/*initialized to 10 because digits can't consist of 2 numbers*/
      digit1 = 10;
      digit2 = 10;
      digit3 = 10;
      digit4 = 10;
      digit5 = 10;
      sdigit1= 10;
      sdigit2= 10;
      sdigit3= 10;
      sdigit4= 10;
      sdigit5= 10;
      while(enter == 0)//beginning of selection
      {
            while(/*operation != 15 && */enter == 0)
            {
              /*write first page of operations*/
							Write_Instr_LCD(0x01);    
							Write_Instr_LCD(0x80);
                  Write_String_LCD("1. ADD   3. ->");     
                  Write_Instr_LCD(0xC0);
                  Write_String_LCD("2. SUBTRACT");
                 
                  operation = Read_Keypad();
									/*Runs when addition*/
                  if(operation==1)
                  {
                        Write_Instr_LCD(0x01);
                        Write_Instr_LCD(0x80);
                        Write_String_LCD("YOU CHOSE");
                        Write_Instr_LCD(0xC0);
                        Write_String_LCD("ADDITION");
                        Delay(1000);
                        Write_Instr_LCD(0x01);
                        enter = 1;
                  }
									/*Runs when subtraction*/
									else if(operation==2)
                  {
                        Write_Instr_LCD(0x01);                                                                    
                        Write_Instr_LCD(0x80);
                        Write_String_LCD("YOU CHOSE");
                        Write_Instr_LCD(0xC0);
                        Write_String_LCD("SUBTRACTION");
                        Delay(1000);
                        Write_Instr_LCD(0x01);
                        enter = 2;
                  }
									/*Runs when operation to perform is on next page*/
									else if(operation == 3)
                  {
                        Write_Instr_LCD(0x01);
                        Write_Instr_LCD(0x80);
                        Write_String_LCD("1. MULTIPLY ");
                        Write_Instr_LCD(0xC0);
                        Write_String_LCD("2. Divide 3. <-");
                        operation = Read_Keypad();
                  }
									/*Runs when multiplication*/
                  if(operation == 1 && enter == 0)
                  {
                        Write_Instr_LCD(0x01);
                        Write_Instr_LCD(0x80);
                        Write_String_LCD("YOU CHOSE");
                        Write_Instr_LCD(0xC0);
                        Write_String_LCD("MULTIPLICATION");
                        Delay(1000);
                        Write_Instr_LCD(0x01);
                        enter = 3;
                  }
									/*Runs when division*/
                  else if(operation == 2 && enter == 0)
                  {
                        Write_Instr_LCD(0x01);
                        Write_Instr_LCD(0x80);
                        Write_String_LCD("YOU CHOSE");
                        Write_Instr_LCD(0xC0);
                        Write_String_LCD("DIVISION");
                        Delay(1000);
                        Write_Instr_LCD(0x01);
                        enter = 4;
                  }                       
            }  
      while (1)
      {
                  
        while(enter == 0)//operation selection iterative version
				{
          /*Go to line 93 of code for explanations. This iterative version is the exact same code
					  used above except in continuous while loop*/  
					while(/*operation != 15 && */enter == 0)
            {
								Write_Instr_LCD(0x01);    
								Write_Instr_LCD(0x80);
                  Write_String_LCD("1. ADD   3. ->"); /*writes first line */    
                  Write_Instr_LCD(0xC0);
                  Write_String_LCD("2. SUBTRACT");
                 
                  operation = Read_Keypad();
                  if(operation==1)
                  {
                        Write_Instr_LCD(0x01);
                        Write_Instr_LCD(0x80);
                        Write_String_LCD("YOU CHOSE");
                        Write_Instr_LCD(0xC0);
                        Write_String_LCD("ADDITION");
                        Delay(1000);
                        Write_Instr_LCD(0x01);
                        enter = 1;
                  }else if(operation==2)
                  {
                        Write_Instr_LCD(0x01);                                                                    
                        Write_Instr_LCD(0x80);
                        Write_String_LCD("YOU CHOSE");
                        Write_Instr_LCD(0xC0);
                        Write_String_LCD("SUBTRACTION");
                        Delay(1000);
                        Write_Instr_LCD(0x01);
                        enter = 2;
                  }else if(operation == 3)
                  {
                        Write_Instr_LCD(0x01);
                        Write_Instr_LCD(0x80);
                        Write_String_LCD("1. MULTIPLY ");
                        Write_Instr_LCD(0xC0);
                        Write_String_LCD("2. Divide 3. <-");
                        operation = Read_Keypad();
                  }
                  if(operation == 1 && enter == 0)
                  {
                        Write_Instr_LCD(0x01);
                        Write_Instr_LCD(0x80);
                        Write_String_LCD("YOU CHOSE");
                        Write_Instr_LCD(0xC0);
                        Write_String_LCD("MULTIPLICATION");
                        Delay(1000);
                        Write_Instr_LCD(0x01);
                        enter = 3;
                  } else if(operation == 2 && enter == 0)
                  {
                        Write_Instr_LCD(0x01);
                        Write_Instr_LCD(0x80);
                        Write_String_LCD("YOU CHOSE");
                        Write_Instr_LCD(0xC0);
                        Write_String_LCD("DIVISION");
                        Delay(1000);
                        Write_Instr_LCD(0x01);
                        enter = 4;
									}                       
            } 
				}
				/*Read input*/
						uint8_t  temp; /*stores keypad input*/
						temp = Read_Keypad();
            
            if(temp<=9) /*output corresponding number on LCD*/
            {
                  Write_Char_LCD(temp+0x30);
                  /*Algorithm for assigning digits for first value set at max of 5*/                        
									if(cursor == 1){
                        if(digit5 != 10)
                        {
                       
                        }else if(digit4 != 10)
                        {
                              digit5 = temp;
                        }else if(digit3 != 10)
                        {
                              digit4 = temp;
                        }else if(digit2 != 10)
                        {
                              digit3 = temp;
                        }else if(digit1 != 10)
                        {
                              digit2 = temp;
                        }else
                        {
                              digit1 = temp;
                        }
                       
                  }
									/*Algorithm for assigning digits for second value set at max of 5*/
                  if(cursor == 2)
                  {
                        if(sdigit5 != 10)
                        {
                       
                        }     else if(sdigit4 != 10)
                        {
                              sdigit5 = temp;
                        }else if(sdigit3 != 10)
                        {
                              sdigit4 = temp;
                        }else if(sdigit2 != 10)
                        {
                              sdigit3 = temp;
                        }     else if(sdigit1 != 10)
                        {
                              sdigit2 = temp;
                        }     else
                        {
                              sdigit1 = temp;
                        }  
                  }
            }
            else if(temp>=10 && temp<=12) /*pressing 'A-D' clears display and reseting values*/
            {
                  Write_Instr_LCD(0x01);
                  digit1= 10;
                  digit2= 10;
                  digit3= 10;
                  digit4= 10;
                  digit5= 10;
                  sdigit1= 10;
                  sdigit2= 10;
                  sdigit3= 10;
                  sdigit4= 10;
                  sdigit5= 10;
									neg1 = 0;
									neg2 = 0;
            }else if(temp==13)/*If 'D' is selected, add negative only for first number*/
						{
							if(cursor == 1)
							{
								if(neg1 == 0 && digit1 == 10)
								{
									Write_Char_LCD('-');
									neg1 = 1;
								}
						
							}
							if(cursor == 2)
							{
								if(neg2 == 0 && sdigit1 == 10)
								{
									Write_Char_LCD('-');
									neg2 = 1;
								}
							}
						}
             else if(temp==14) /*pressing '*' moves to beginning of other line*/
            {
                  /*if on first line, move to second*/
                  if(cursor==1)
                  {
                        Write_Instr_LCD(0xC0);
                        cursor = 2;
                  }
									/*After second line compute output*/
                  else if(cursor==2)
                  {
                     /*Algorithm for assigning digits to calculate display value*/   
												if(digit5 == 10)
                        {
                              if(digit4 == 10)
                              {
                                    if(digit3 == 10)
                                    {
                                          if(digit2 == 10)
                                          {
                                                if(digit1 == 10)
                                                {
                                                      sum = 0;
                                                }else{
                                                      sum = digit1;
                                                }
                                          }else{
                                                sum = digit1 * 10;
                                                sum += digit2;
                                          }
                                    }else{
                                          sum = digit1 * 100;
                                          sum += digit2 * 10;
                                          sum += digit3;
                                    }
                              }else{
                                    sum = digit1 * 1000;
                                    sum += digit2 * 100;
                                    sum += digit3 * 10;
                                    sum += digit4;
                              }
                        }else{
                              sum = digit1 * 10000;
                              sum += digit2 * 1000;
                              sum += digit3 * 100;
                              sum += digit4 * 10;
                              sum += digit5;
                        }
                        if(sdigit5 == 10)
                        {
                              if(sdigit4 == 10)
                              {
                                    if(sdigit3 == 10)
                                    {
                                          if(sdigit2 == 10)
                                          {
                                                if(sdigit1 == 10)
                                                {
                                                      sum2 = 0;
                                                }else{
                                                      sum2 = sdigit1;
                                                }
                                          }else{
                                                sum2 = sdigit1 * 10;
                                                sum2 += sdigit2;
                                          }
                                    }else{
                                          sum2 = sdigit1 * 100;
                                          sum2 += sdigit2 * 10;
                                          sum2 += sdigit3;
                                    }
                              }else{
                                    sum2 = sdigit1 * 1000;
                                    sum2 += sdigit2 * 100;
                                    sum2 += sdigit3 * 10;
                                    sum2 += sdigit4;
                              }
                        }else{
                              sum2 = sdigit1 * 10000;
                              sum2 += sdigit2 * 1000;
                              sum2 += sdigit3 * 100;
                              sum2 += sdigit4 * 10;
                              sum2 += sdigit5;
                        }
												/*Check if negative numbers are present*/
												if(neg1 == 1)
												{
													sum = -sum;
												}
												if(neg2 == 1)
												{
													sum2 = -sum2;
												}
												/*End algorithm*/
												/*Compute appropriate operation*/
                        if(enter == 1)
                        {
                              answer = sum + sum2;
                        }else if(enter == 2)
                        {
                            answer = sum - sum2;
                        }else if(enter == 3)
                        {
                            answer = sum * sum2;
                        }else if(enter == 4)
                        {
                            answer = sum / sum2;
													  
													if(sum2 == 0)
													{
														divideZero = 1;
														Write_Instr_LCD(0x01);
														Write_Instr_LCD(0x80);
														Write_String_LCD("Error");
														Write_Instr_LCD(0xC0);
														Write_String_LCD("Divide by zero");
														Delay(2000);
													}else
													{
														/*calculate remainder if positive number*/
														if(neg1 == 0 && neg2 == 0)
														{
															r = sum % sum2;
														}else if(neg1 == 1 && neg2 == 1)
														{
															sum = -sum;
															sum2 = -sum2;
															r = sum % sum2;
														}
													}
													
                        }
												/*check conditions*/
												if(divideZero == 1)
												{
													divideZero = 0;
													cursor = 1;
													enter = 0;
													operation  = 0; 
													digit1= 10;
													digit2= 10;
													digit3= 10;
													digit4= 10;
													digit5= 10;
													sdigit1= 10;
													sdigit2= 10;
													sdigit3= 10;
													sdigit4= 10;
													sdigit5= 10;
													neg1 = 0;
													neg2 = 0;
												}else if(r != 0)
												{
													Write_Instr_LCD(0x01);
													char divisionRemainder[16];
													sprintf(divisionRemainder, "%d", answer);
													Write_Instr_LCD(0x80);
													Write_String_LCD(divisionRemainder);
													Write_String_LCD(" r ");
													sprintf(divisionRemainder, "%d", r);
													Write_Instr_LCD(0xC0);
													Write_String_LCD(divisionRemainder);
													Delay(2000);
													neg1 = 0;
													neg2 = 0;
													r = 0;
													cursor = 1;
													enter = 0;
													operation  = 0; 
													digit1= 10;
													digit2= 10;
													digit3= 10;
													digit4= 10;
													digit5= 10;
													sdigit1= 10;
													sdigit2= 10;
													sdigit3= 10;
													sdigit4= 10;
													sdigit5= 10;
												}
												else{
												/*Write Answer*/
                        Write_Instr_LCD(0x01);
                        char answerInString[16];
                        sprintf(answerInString, "%d", answer);
                        Write_Instr_LCD(0x80);
                        Write_String_LCD(answerInString);
												Delay(2000);
												/*Reset values for next cycle*/
                        cursor = 1;
                        enter = 0;
                        operation  = 0; 
												digit1= 10;
												digit2= 10;
												digit3= 10;
												digit4= 10;
												digit5= 10;
												sdigit1= 10;
												sdigit2= 10;
												sdigit3= 10;
												sdigit4= 10;
												sdigit5= 10;
												neg1 = 0;
												neg2 = 0;
											}
                  }
            }
            else if(temp == 15) /*pressing '#' deletes a character*/
            {
                  Write_Instr_LCD(0x10);
                  Write_Char_LCD(0x20);
                  Write_Instr_LCD(0x10);
                  /*Algorithm for finding which digit to reset for deletion*/                                                                        
                  if(cursor == 1){
                        if(digit5 != 10)
                        {
                          digit5 = 10;
                        }else if(digit4 != 10)
                        {
                          digit4 = 10;
                        }else if(digit3 != 10)
                        {
                          digit3 = 10;
                        }else if(digit2 != 10)
                        {
                          digit2 = 10;
                        }else if(digit1 != 10)
                        {
                          digit1 = 10;
                        }else if(neg1 == 1)
												{
													neg1 = 0;
												}
                        else
                        {
                          Write_Instr_LCD(0x80);
                        }
                  }
                  if(cursor == 2)
                  {
                        if(sdigit5 != 10)
                        {
                           sdigit5 = 10;
                        } else if(sdigit4 != 10)
                        {
                              sdigit4 = 10;
                        }else if(sdigit3 != 10)
                        {
                              sdigit3 = 10;
                        }else if(sdigit2 != 10)
                        {
                              sdigit2 = 10;
                        }else if(sdigit1 != 10)
                        {
                              sdigit1 = 10;
                        }else if(neg2 == 1)
												{
													neg2 = 0;
												}else
                        {
                              Write_Instr_LCD(0xC0);
                        }
                  }
									/*End algorithm*/
            }
                             

  }
}}

uint8_t Read_Keypad()
{

/* All colomns are zeros col0  PA0  - col1  PA9 - col2 PA10   col3  PB4*/    

uint8_t a;  
     

/*set all colomns high and wait until a putton is pressed*/

GPIOB->ODR|=(1<<4);
Delay(2);        
GPIOA->ODR|=(1<<0);
Delay(2);        
GPIOA->ODR|=(1<<9);
Delay(2);        
GPIOA->ODR|=(1<<10);
Delay(2);  

while((GPIOA->IDR &(0x1<<6))==0 && (GPIOA->IDR &(0x1<<5))==0 && (GPIOA->IDR &(0x1<<4))==0 &&  (GPIOA->IDR &(0x1<<3))==0)
{    
}          
     
      Delay(25);  /*debouncing*/

/*scanning */

while(1)
{    
     
GPIOB->ODR&=~(1<<4);
      Delay(2);  
GPIOA->ODR&=~(1<<0);
Delay(2);        
GPIOA->ODR&=~(1<<9);
Delay(2);  
GPIOA->ODR&=~(1<<10);
Delay(2);  
     
     
     
      /* Scan Col 0 */
      /* All colomns are zeros col0  PA0  - col1  PA9 - col2 PA10   col3  PB4*/    
GPIOA->ODR|=(1<<0);
Delay(2);

     
      /* check rows row0 PA6   - row1 PA5 - row2  PA4  row3  PA3  all of them output */  
     
      if((GPIOA->IDR &(0x1<<6))!=0)
      {a=1;
      break;}
 if((GPIOA->IDR &(0x1<<5))!=0)
       {a=4;
      break;}
      if((GPIOA->IDR &(0x1<<4))!=0)
            {a=7;
      break;}
      if((GPIOA->IDR &(0x1<<3))!=0)
            {a=14;
      break;}


     
/* Scan Col 1 */ /* All colomns are zeros col0  PA0  - col1  PA9 - col2 PA10   col3  PB4*/      

      GPIOA->ODR&=~(1<<0);
Delay(2);        
GPIOA->ODR|=(1<<9);
Delay(2);  
     
      if((GPIOA->IDR &(0x1<<6))!=0)
      {a=2;
      break;}
 if((GPIOA->IDR &(0x1<<5))!=0)
       {a=5;
      break;}
      if((GPIOA->IDR &(0x1<<4))!=0)
            {a=8;
      break;}
      if((GPIOA->IDR &(0x1<<3))!=0)
            {a=0;
      break;}



/* Scan Col 2 */ /* All colomns are zeros col0  PA0  - col1  PA9 - col2 PA10   col3  PB4*/      

GPIOA->ODR&=~(1<<9);
Delay(2);        
GPIOA->ODR|=(1<<10);
Delay(2);        

      if((GPIOA->IDR &(0x1<<6))!=0)
      {a=3;
      break;}
 if((GPIOA->IDR &(0x1<<5))!=0)
       {a=6;
      break;}
      if((GPIOA->IDR &(0x1<<4))!=0)
            {a=9;
      break;}
      if((GPIOA->IDR &(0x1<<3))!=0)
            {a=15;
      break;}

     
/* Scan Col 3 */ /* All colomns are zeros col0  PA0  - col1  PA9 - col2 PA10   col3  PB4*/      

GPIOA->ODR&=~(1<<10);
Delay(2);        
GPIOB->ODR|=(1<<4);
Delay(2);        

      if((GPIOA->IDR &(0x1<<6))!=0)
      {a=10;
      break;}
 if((GPIOA->IDR &(0x1<<5))!=0)
       {a=11;
      break;}
      if((GPIOA->IDR &(0x1<<4))!=0)
            {a=12;
      break;}
      if((GPIOA->IDR &(0x1<<3))!=0)
            {a=13;
      break;}

}

/*wait until button is released*/

GPIOB->ODR|=(1<<4);
Delay(2);  
GPIOA->ODR|=(1<<0);
Delay(2);
GPIOA->ODR|=(1<<9);
Delay(2);  
GPIOA->ODR|=(1<<10);
Delay(2);  

while(!(    ((GPIOA->IDR &(0x1<<6))==0) && ((GPIOA->IDR &(0x1<<5))==0) && ((GPIOA->IDR &(0x1<<4))==0)  &&  ((GPIOA->IDR &(0x1<<3))==0) ))
{
     
}    

      Delay(25);  /*debouncing*/
return(a);
}
     



void Keypad_Init()
      {
      uint32_t temp;
      RCC->IOPENR|=0x00000001;  /* enable GPIOA clock */
      RCC->IOPENR|=0x00000002;  /* enable GPIOB clock */
                 
/* row0 PA6   -  row1 PA5 - row2  PA4 - row3  PA3  all of them are input pins */
               temp = GPIOA->MODER;
                   temp &= ~(0x03<<(2*6));
                   temp &= ~(0x03<<(2*5));
               temp &= ~(0x03<<(2*3));
                   temp &= ~(0x03<<(2*4));
                   GPIOA->MODER = temp;
                 
            temp=GPIOA->OTYPER;
            temp &=~(0x01<<3);
            temp &=~(0x01<<4);
            temp &=~(0x01<<5);
            temp &=~(0x01<<6);      
            GPIOA->OTYPER=temp;
     
            temp=GPIOA->PUPDR;
            temp&=~(0x03<<(2*3));
            temp&=~(0x03<<(2*4));
            temp&=~(0x03<<(2*5));
            temp&=~(0x03<<(2*6));
            GPIOA->PUPDR=temp;


/* col0  PA0  - col1  PA9 - col2 PA10   col3  PB4  all of them are output*/

                   temp = GPIOA->MODER;
                   temp &= ~(0x03<<(2*0));
                   temp|=(0x01<<(2*0));
                   temp &= ~(0x03<<(2*9));
                   temp|=(0x01<<(2*9));
                   temp &= ~(0x03<<(2*10));
                   temp|=(0x01<<(2*10));
                   GPIOA->MODER = temp;
                 
                   temp = GPIOB->MODER;
                   temp &= ~(0x03<<(2*4));
                   temp|=(0x01<<(2*4));
                   GPIOB->MODER = temp;
                 
                   temp=GPIOA->OTYPER;
               temp &=~(0x01<<0);
                   temp &=~(0x01<<9);
                   temp &=~(0x01<<10);
                   GPIOA->OTYPER=temp;
     
           temp=GPIOB->OTYPER;
               temp &=~(0x01<<4);
                   GPIOB->OTYPER=temp;
     
                  temp=GPIOA->PUPDR;
                  temp&=~(0x03<<(2*0));
                  temp&=~(0x03<<(2*9));
                  temp&=~(0x03<<(2*10));
                  GPIOA->PUPDR=temp;


                  temp=GPIOB->PUPDR;
                  temp&=~(0x03<<(2*4));
                  GPIOB->PUPDR=temp;
}

void LCD_Init()
      {
            uint32_t temp;
           
          RCC->IOPENR|=0x00000001;  /* enable GPIOA clock */
                  RCC->IOPENR|=0x00000002;  /* enable GPIOB clock */
                 
                   temp = GPIOA->MODER;
                   temp &= ~(0x03<<(2*11));
                   temp|=(0x01<<(2*11));
                   GPIOA->MODER = temp;
                 
                   temp=GPIOA->OTYPER;
                   temp &=~(0x01<<11);
           GPIOA->OTYPER=temp;
     
                   temp=GPIOA->PUPDR;
           temp&=~(0x03<<(2*11));
           GPIOA->PUPDR=temp;

                   temp = GPIOB->MODER;
                   temp &= ~(0x03<<(2*5));
                   temp|=(0x01<<(2*5));
                   temp &= ~(0x03<<(2*3));
                   temp|=(0x01<<(2*3));
                   GPIOB->MODER = temp;
                 
                   temp=GPIOB->OTYPER;
                   temp &=~(0x01<<5);
           temp &=~(0x01<<3);
           GPIOB->OTYPER=temp;
     
               temp=GPIOB->PUPDR;
           temp&=~(0x03<<(2*5));
                   temp&=~(0x03<<(2*3));
           GPIOB->PUPDR=temp;
           
           
      /* LCD controller reset sequence */
      Delay(20);
      LCD_nibble_write(0x30,0);
      Delay(5);
      LCD_nibble_write(0x30,0);
      Delay(1);
      LCD_nibble_write(0x30,0);
      Delay(1);
      LCD_nibble_write(0x20,0);
      Delay(1);
     
           
      Write_Instr_LCD(0x28); /* set 4 bit data LCD - two line display - 5x8 font*/
      Write_Instr_LCD(0x0E); /* ;turn on display, turn on cursor , turn off blinking            */    
      Write_Instr_LCD(0x01); /* clear display screen and return to home position    */          
      Write_Instr_LCD(0x06); /* ;move cursor to right (entry mode set instruction)        */    
     
      }    
     
     
void LCD_nibble_write(uint8_t temp, uint8_t s)
{
if (s==0) /*writing instruction*/
{
      temp=temp&0xF0;
      temp=temp|0x02; /*RS=1 (bit 0) for data EN=high (bit1)*/
      Write_SR_LCD(temp);
      temp=temp&0xFD; /*RS=1 (bit 0) for data EN=high (bit1)*/
      Write_SR_LCD(temp);
}

else if (s==1) /*writing data*/
{
  temp=temp&0xF0;
      temp=temp|0x03; /*RS=1 (bit 0) for data EN=high (bit1)*/
      Write_SR_LCD(temp);
      temp=temp&0xFD; /*RS=1 (bit 0) for data EN=high (bit1)*/
      Write_SR_LCD(temp);
}
     
}    
     
     

void Write_String_LCD(char *temp)
{
int i=0;
while(temp[i]!=0)
{
      Write_Char_LCD(temp[i]);
      i=i+1;
}    
}



void Write_Instr_LCD(uint8_t code)
{
      LCD_nibble_write(code&0xF0,0);
     
      code=code<<4;
      LCD_nibble_write(code,0);
}


void Write_Char_LCD(uint8_t code)
{
     
      LCD_nibble_write(code&0xF0,1);
     
      code=code<<4;
      LCD_nibble_write(code,1);
     
}


void Write_SR_LCD(uint8_t temp)
{
int i;
uint8_t mask=0b10000000;
     
for(i=0; i<8; i++)      
{
      if((temp&mask)==0)
            GPIOB->ODR&=~(1<<5);
            else
            GPIOB->ODR|=(1<<5);
     
      /*  Sclck */
      GPIOB->ODR&=~(1<<3);
      GPIOB->ODR|=(1<<3);    
      Delay(1);
           
 mask=mask>>1;    
}    
     

     
/*Latch*/
      GPIOA->ODR|=(1<<11);
      GPIOA->ODR&=~(1<<11);  

}    
           
           
           

void Delay(unsigned int n)
{
      int i;
      if(n!=0)
      {
    for (; n > 0; n--)
        for (i = 0; i < 136; i++) ;
}
      }

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_5;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */