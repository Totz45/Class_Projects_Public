/* USER CODE BEGIN Header */
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
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
unsigned int state;
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

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

void EXTI_PA5_Init(void); 
void Init_LED0(void);
void SysTick_Initialize (uint32_t ticks);

int main(void)
{ 
	 char* line1;
	 line1 ="Welcome to Lab9"; /*line 1 string */
	
		 char* line2; /* line 2 string*/
	 line2 =" ";
	
	
	
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
	EXTI_PA5_Init(); 
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */
	Init_LED0();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  
	/*SystemCoreClockUpdate();*/
	
	    		
			/*PB5 MOSI, PA11 /CS_7 latch , PB_3 shift clock */  
			
		
	


  LCD_Init();
	
	Keypad_Init();
	
	Write_String_LCD(line1); /*writes first line */	
	
	unsigned int status = 1; /*checks if the display is on or off*/
	unsigned int cursor = 1; /*checks if the cursor is on the first or second line*/
	state = 1;
	unsigned int clear=16; /*conditional*/
	
	/*You must press a button to clear the screen before keypad inputs are registered*/
	while(clear == 16)
	{
		clear = Read_Keypad();
		if(clear>=0 && clear<=15)
		{
			Write_Instr_LCD(0x01);
		}
	}
	
	while (1)
  {
		uint8_t	temp; /*stores keypad input*/
		temp = Read_Keypad();	
		if(temp>=1 && temp<=9) /*output corresponding number*/
		Write_Char_LCD(temp+0x30);	
		else if(temp==0) /*output 0 if temp = 0*/
		Write_Char_LCD(0x30);
    else	if (temp ==14) /*pressing '*' turns on and off display*/
		{ 
			/*if on, turn off*/
			if (status == 1)
			{
				Write_Instr_LCD(0x08);
				status = 0;
			} 
			/*if off, turn on*/
			else if (status ==0)
			{
				Write_Instr_LCD(0x0E);
				status = 1;
			}
		}
		else if(temp==10) /*pressing 'A' clears display*/
		{
			Write_Instr_LCD(0x01);
		}
		else if(temp==15) /*pressing '#' moves cursor left*/
		{
			Write_Instr_LCD(0x10);
		}
		else if(temp==13) /*pressing 'D' moves cursor left*/
		{
			Write_Instr_LCD(0x14);
		} else if(temp==11) /*pressing 'B' moves to beginning of other line*/
		{
			/*if on first line, move to second*/
			if(cursor==1)
			{
				Write_Instr_LCD(0xC0);
				cursor = 2;
			} 
			/*if on second line, move to first*/
			else if(cursor==2)
			{
				Write_Instr_LCD(0x80);
				cursor = 1;
			}
		}
		else /*pressing 'C' deletes a character*/
		{
			Write_Instr_LCD(0x10);
			Write_Char_LCD(0x20);
			Write_Instr_LCD(0x10);
		}
					

  }
  /* USER CODE END 3 */
}

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
	
	Delay(25);	/*debouncing*/

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

	Delay(25);	/*debouncing*/
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
	Write_Instr_LCD(0x0E); /* ;turn on display, turn on cursor , turn off blinking 		*/	
	Write_Instr_LCD(0x01); /* clear display screen and return to home position	*/		
	Write_Instr_LCD(0x06); /* ;move cursor to right (entry mode set instruction) 		*/	
	
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
void SysTick_Initialize (uint32_t ticks) {

  SysTick->LOAD = ticks - 1;    // Set reload register
	SysTick->VAL = 0;             // Reset the SysTick counter value
	
// Select processor clock to internal: 1 = processor clock; 0 = external clock
    SysTick->CTRL |= 0x04;  //SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;   

// Enable counting of SysTick
    SysTick->CTRL |= 0x1; //SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	
// Enables SysTick interrupt, 1 = Enable, 0 = Disable
    SysTick->CTRL |= 0x1<<1; //SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
}
void SysTick_Handler(void) { // SysTick interrupt service routine 

	GPIOA->ODR^=(1<<12); //toggle LED0

} 	
void EXTI4_15_IRQHandler(void) {  

if(state == 1) //if in state 1, enable interupt and trigger interupts every half second
{
	SysTick_Initialize(1039999); 
	state = state + 1;
} else if (state == 2) //if in state 2, enable interupt and trigger interupts every second
{
	SysTick_Initialize(2079999); 
	state = state + 1;
}else if(state == 3) //if in state 3, enable interupt and trigger interupts every two seconds
{
	SysTick_Initialize(4159999); 
	state = state + 1;
} else if (state == 4) //if in state 4, disable interupt
{
	SysTick->CTRL &= 0x1<<0;
	GPIOA->ODR &= ~(1<<12); 
	state = state + 1;
}if(state == 5) //reset to state 1 after state 4
{
	state = 1;
}

// Cleared flag by writing 1   
EXTI->PR |= (1<<5);  //EXTI->PR |= EXTI_PR_PIF5;

	
// debouncing code	
Delay(10);	
while((GPIOA->IDR&(1<<5))!=0)
{} // wait until the button is released
Delay(10);		

}
	void EXTI_PA5_Init(void)
{
	uint32_t temp;
	
//===== (1) Configure PA5 input  

RCC->IOPENR|=0x00000001;  /* enable GPIOA clock */	

//Configure PA5 pin input 
	     temp = GPIOA->MODER;
			 temp &= ~(0x03<<(2*5));
			 GPIOA->MODER = temp; 
	
	temp=GPIOA->OTYPER;
	temp &=~(0x01<<5);
	GPIOA->OTYPER=temp;
	
  // Add Pull down resistance 
  //  Pull-up (01), Pull-down (10), Reserved (11)
  temp=GPIOA->PUPDR;
	temp&=~(0x03<<(2*5));
	temp|=(0x02<<(2*5));
	GPIOA->PUPDR=temp;  // Pull down

//============================================
	
// ===== (2) Connect External Line to the GPI

//enable the clock of SYSCFG
RCC->APB2ENR |= 0x00000001; //  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

//clear the 4 bits of the EXIT5
SYSCFG->EXTICR[1] &= ~(0x00F0);  //SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI5; 

//select port A	
SYSCFG->EXTICR[1] |= 0x0000;  //SYSCFG->EXTICR[1] |=  SYSCFG_EXTICR2_EXTI5_PA; 
//===============================


// ===== (3) Rising trigger selection
  // 0 = trigger disabled, 1 = trigger enabled
   EXTI->RTSR |= (1<<5);  //EXTI->RTSR |= EXTI_RTSR_RT5;  
//==========================	


// ===== (4) Enable interrupt
		
// 4.1 NVIC enable bit		
NVIC->ISER[0U] = 1<<7;  //OR NVIC_EnableIRQ(EXTI4_15_IRQn); 

//4.2 Peripheral enable bit
  // 0 = marked, 1 = not masked (enabled)
  EXTI->IMR |= (1<<5);  //EXTI->IMR |= EXTI_IMR_IM5;     
		
}
void Init_LED0()
	{
		uint32_t temp;
		RCC->IOPENR|=0x00000001;  /* enable GPIOA clock */    /* equivalent to     *((uint32_t *) 0x4002102C) |= 0x00000001;    */
	  		
			 temp = GPIOA->MODER;      /*equivalent to temp = *((uint32_t *) 0x50000000) ;*/		 
			 temp &= ~(0x03<<(2*12));
			 temp|=(0x01<<(2*12));
			 GPIOA->MODER = temp; 
		
			 
			 temp=GPIOA->OTYPER; /*equivalent to temp = *((uint32_t *) 0x50000004) ;*/		 
	     temp &=~(0x01<<12);
	     GPIOA->OTYPER=temp;
		   
	
	     temp=GPIOA->PUPDR;    /*equivalent to temp = *((uint32_t *) 0x5000000C) ;*/		 
		temp&=~(0x03<<(2*12));
	     GPIOA->PUPDR=temp;
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