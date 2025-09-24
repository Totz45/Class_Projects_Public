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
	

void Delay(unsigned int);	
void Init_buzzer(void);		 
void EXTI_PA5_Init(void);	
void EXTI_PA6_Init(void);
void EXTI_PA4_Init(void);
void EXTI_PA3_Init(void);
void Keypad_Init(void);
uint8_t Read_Keypad_Input(void);
int main(void)
{
	int status=0;
	int status2=0;
	int status3=0;
	int status4=0;
	int i;
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

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  
	/*SystemCoreClockUpdate();*/
	Keypad_Init();
	EXTI_PA5_Init();
  EXTI_PA6_Init();
  EXTI_PA4_Init();
  EXTI_PA3_Init();	
  Init_buzzer();		 
	
	while (1)
  {
		uint8_t temp;
		temp = Read_Keypad_Input();
	}	
  /* USER CODE END 3 */
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
void EXTI_PA6_Init(void)
{
	uint32_t temp;
	
//===== (1) Configure PA5 input  

RCC->IOPENR|=0x00000001;  /* enable GPIOA clock */	

//Configure PA5 pin input 
	     temp = GPIOA->MODER;
			 temp &= ~(0x03<<(2*6));
			 GPIOA->MODER = temp; 
	
	temp=GPIOA->OTYPER;
	temp &=~(0x01<<6);
	GPIOA->OTYPER=temp;
	
  // Add Pull down resistance 
  //  Pull-up (01), Pull-down (10), Reserved (11)
  temp=GPIOA->PUPDR;
	temp&=~(0x03<<(2*6));
	temp|=(0x02<<(2*6));
	GPIOA->PUPDR=temp;  // Pull down

//============================================
	
// ===== (2) Connect External Line to the GPI

//enable the clock of SYSCFG
RCC->APB2ENR |= 0x00000001; //  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

//clear the 4 bits of the EXIT6
SYSCFG->EXTICR[1] &= ~(0x0F00);  //SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI5; 

//select port A	
SYSCFG->EXTICR[1] |= 0x0000;  //SYSCFG->EXTICR[1] |=  SYSCFG_EXTICR2_EXTI6_PA; 
//===============================


// ===== (3) Rising trigger selection
  // 0 = trigger disabled, 1 = trigger enabled
   EXTI->RTSR |= (1<<6);  //EXTI->RTSR |= EXTI_RTSR_RT5;  
//==========================	


// ===== (4) Enable interrupt
		
// 4.1 NVIC enable bit		
	NVIC->ISER[0U] = 1<<7;  //OR NVIC_EnableIRQ(EXTI4_15_IRQn); 

//4.2 Peripheral enable bit
  // 0 = marked, 1 = not masked (enabled)
  EXTI->IMR |= (1<<6);  //EXTI->IMR |= EXTI_IMR_IM5;     
		
}
void EXTI_PA4_Init(void)
{
	uint32_t temp;
	
//===== (1) Configure PA5 input  

RCC->IOPENR|=0x00000001;  /* enable GPIOA clock */	

//Configure PA5 pin input 
	     temp = GPIOA->MODER;
			 temp &= ~(0x03<<(2*4));
			 GPIOA->MODER = temp; 
	
	temp=GPIOA->OTYPER;
	temp &=~(0x01<<4);
	GPIOA->OTYPER=temp;
	
  // Add Pull down resistance 
  //  Pull-up (01), Pull-down (10), Reserved (11)
  temp=GPIOA->PUPDR;
	temp&=~(0x03<<(2*4));
	temp|=(0x02<<(2*4));
	GPIOA->PUPDR=temp;  // Pull down

//============================================
	
// ===== (2) Connect External Line to the GPI

//enable the clock of SYSCFG
RCC->APB2ENR |= 0x00000001; //  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

//clear the 4 bits of the EXIT4
SYSCFG->EXTICR[1] &= ~(0x000F);  //SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI5; 

//select port A	
SYSCFG->EXTICR[1] |= 0x0000;  //SYSCFG->EXTICR[1] |=  SYSCFG_EXTICR2_EXTI5_PA; 
//===============================


// ===== (3) Rising trigger selection
  // 0 = trigger disabled, 1 = trigger enabled
   EXTI->RTSR |= (1<<4);  //EXTI->RTSR |= EXTI_RTSR_RT5;  
//==========================	


// ===== (4) Enable interrupt
		
// 4.1 NVIC enable bit		
	NVIC->ISER[0U] = 1<<7;  //OR NVIC_EnableIRQ(EXTI4_15_IRQn); 

//4.2 Peripheral enable bit
  // 0 = marked, 1 = not masked (enabled)
  EXTI->IMR |= (1<<4);  //EXTI->IMR |= EXTI_IMR_IM5;     
		
}
void EXTI_PA3_Init(void)
{
	uint32_t temp;
	
//===== (1) Configure PA5 input  

RCC->IOPENR|=0x00000001;  /* enable GPIOA clock */	

//Configure PA5 pin input 
	     temp = GPIOA->MODER;
			 temp &= ~(0x03<<(2*3));
			 GPIOA->MODER = temp; 
	
	temp=GPIOA->OTYPER;
	temp &=~(0x01<<3);
	GPIOA->OTYPER=temp;
	
  // Add Pull down resistance 
  //  Pull-up (01), Pull-down (10), Reserved (11)
  temp=GPIOA->PUPDR;
	temp&=~(0x03<<(2*3));
	temp|=(0x02<<(2*3));
	GPIOA->PUPDR=temp;  // Pull down

//============================================
	
// ===== (2) Connect External Line to the GPI

//enable the clock of SYSCFG
RCC->APB2ENR |= 0x00000001; //  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

//clear the 4 bits of the EXIT3
SYSCFG->EXTICR[0] &= ~(0xF000);  //SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI5; 

//select port A	
SYSCFG->EXTICR[0] |= 0x0000;  //SYSCFG->EXTICR[1] |=  SYSCFG_EXTICR2_EXTI6_PA; 
//===============================


// ===== (3) Rising trigger selection
  // 0 = trigger disabled, 1 = trigger enabled
   EXTI->RTSR |= (1<<3);  //EXTI->RTSR |= EXTI_RTSR_RT5;  
//==========================	


// ===== (4) Enable interrupt
		
// 4.1 NVIC enable bit		
	NVIC->ISER[0U] = 1<<6;  //OR NVIC_EnableIRQ(EXTI4_15_IRQn); 

//4.2 Peripheral enable bit
  // 0 = marked, 1 = not masked (enabled)
  EXTI->IMR |= (1<<3);  //EXTI->IMR |= EXTI_IMR_IM5;     
		
}



void Init_buzzer()		 
{			
	uint32_t temp;
	    RCC->IOPENR|=0x00000001;  /* enable GPIOA clock */
			     
			 temp = GPIOA->MODER;
			 temp &= ~(0x03<<(2*8));
			 temp|=(0x01<<(2*8));
			 GPIOA->MODER = temp;
		 
			temp=GPIOA->OTYPER;
			temp &=~(0x01<<8);
			GPIOA->OTYPER=temp;
	
			temp=GPIOA->PUPDR;
			temp&=~(0x03<<(2*8));
			GPIOA->PUPDR=temp;
}

uint8_t Read_Keypad_Input()
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
	{a=0;
	break;}
 if((GPIOA->IDR &(0x1<<5))!=0)
	 {a=4;
	break;}
	if((GPIOA->IDR &(0x1<<4))!=0) 
		{a=8;
	break;}
	if((GPIOA->IDR &(0x1<<3))!=0)
		{a=12;
	break;}


	
/* Scan Col 1 */ /* All colomns are zeros col0  PA0  - col1  PA9 - col2 PA10   col3  PB4*/	

	GPIOA->ODR&=~(1<<0);
Delay(2);		
GPIOA->ODR|=(1<<9);
Delay(2);	
	
	if((GPIOA->IDR &(0x1<<6))!=0)
	{a=1;
	break;}
 if((GPIOA->IDR &(0x1<<5))!=0)
	 {a=5;
	break;}
	if((GPIOA->IDR &(0x1<<4))!=0) 
		{a=9;
	break;}
	if((GPIOA->IDR &(0x1<<3))!=0)
		{a=13;
	break;}



/* Scan Col 2 */ /* All colomns are zeros col0  PA0  - col1  PA9 - col2 PA10   col3  PB4*/	

GPIOA->ODR&=~(1<<9);
Delay(2);		
GPIOA->ODR|=(1<<10);
Delay(2);		

	if((GPIOA->IDR &(0x1<<6))!=0)
	{a=2;
	break;}
 if((GPIOA->IDR &(0x1<<5))!=0)
	 {a=6;
	break;}
	if((GPIOA->IDR &(0x1<<4))!=0) 
		{a=10;
	break;}
	if((GPIOA->IDR &(0x1<<3))!=0)
		{a=14;
	break;}

	
/* Scan Col 3 */ /* All colomns are zeros col0  PA0  - col1  PA9 - col2 PA10   col3  PB4*/	

GPIOA->ODR&=~(1<<10);
Delay(2);		
GPIOB->ODR|=(1<<4);
Delay(2);		

	if((GPIOA->IDR &(0x1<<6))!=0)
	{a=3;
	break;}
 if((GPIOA->IDR &(0x1<<5))!=0)
	 {a=7;
	break;}
	if((GPIOA->IDR &(0x1<<4))!=0) 
		{a=11;
	break;}
	if((GPIOA->IDR &(0x1<<3))!=0)
		{a=15;
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


void Delay(unsigned int n)
{
	int i;
    for (; n > 0; n--)
        for (i = 0; i < 136; i++) ;
	}
void EXTI4_15_IRQHandler(void) {  
// Cleared flag by writing 1   
EXTI->PR |= (1<<5);  //EXTI->PR |= EXTI_PR_PIF5;
uint8_t temp;
temp = Read_Keypad_Input();
int status=0;
int i;
if(temp == 0)   /*check if SW5 is pressed*/
{
	status=1;
}
if(temp == 1)   /*check if SW5 is pressed*/
{
	 status=2;
}
if(temp == 2)   /*check if SW5 is pressed*/
{
	status=3;
}
if(temp == 3)   /*check if SW5 is pressed*/
{
	 status=4;
}
if(temp == 4)   /*check if SW5 is pressed*/
{
	status=5;
}
if(temp == 5)   /*check if SW5 is pressed*/
{
	 status=6;
}
if(temp == 6)   /*check if SW5 is pressed*/
{
	status=7;
}
if(temp == 7)   /*check if SW5 is pressed*/
{
	 status=8;
}
if(temp == 8)   /*check if SW5 is pressed*/
{
	status=9;
}
if(temp == 9)   /*check if SW5 is pressed*/
{
	 status=10;
}
if(temp == 10)   /*check if SW5 is pressed*/
{
	status=11;
}
if(temp == 11)   /*check if SW5 is pressed*/
{
	 status=12;
}
if(status == 1)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <250; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(1);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(1);
			status = 0;
		}			
} else if(status == 2)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <125; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(2);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(2);
			status = 0;
		}			
} else if(status == 3)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <83; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(3);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(3);
			status = 0;
		}			
} else if(status == 4)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <63; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(4);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(4);
			status = 0;
		}			
} else if(status == 5)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <50; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(5);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(5);
			status = 0;
		}			
} else if(status == 6)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <42; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(6);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(6);
			status = 0;
		}			
} else if(status == 7)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <38; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(7);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(7);
			status = 0;
		}			
} else if(status == 8)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <31; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(8);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(8);
			status = 0;
		}			
} else if(status == 9)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <28; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(9);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(9);
			status = 0;
		}			
} else if(status == 10)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <25; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(10);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(10);
			status = 0;
		}			
} else if(status == 11)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <23; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(11);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(11);
			status = 0;
		}			
} else if(status == 12)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <21; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(12);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(12);
			status = 0;
		}			
}
	
// debouncing code	
Delay(10);	
while((GPIOA->IDR&(1<<5))!=0)
{} 
while((GPIOA->IDR&(1<<6))!=0)
{} 
while((GPIOA->IDR&(1<<4))!=0)
{} 	
	// wait until the button is released
Delay(10);		

}
void EXTI2_3_IRQHandler(void) {  
// Cleared flag by writing 1   
EXTI->PR |= (1<<5);  //EXTI->PR |= EXTI_PR_PIF5;
uint8_t temp;
temp = Read_Keypad_Input();
int status=0;
int i;
if(temp == 12)   /*check if SW5 is pressed*/
{
	status=1;
}
if(temp == 13)   /*check if SW5 is pressed*/
{
	 status=2;
}
if(temp == 14)   /*check if SW5 is pressed*/
{
	status=3;
}
if(temp == 15)   /*check if SW5 is pressed*/
{
	 status=4;
}
if(status == 1)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <25; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(13);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(13);
			status = 0;
		}			
} else if(status == 2)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <22; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(14);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(14);
			status = 0;
		}			
} else if(status == 3)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <19; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(15);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(15);
			status = 0;
		}			
} else if(status == 4)
{
		/*Run tone 2 for 0.5 second */
		for (i = 0; i <16; i++) 
		{
			GPIOA->ODR|=(1<<8);
			Delay(16);
		
			GPIOA->ODR&=~(1<<8);		
			Delay(16);
			status = 0;
		}			
}
	
// debouncing code	
Delay(10);	
while((GPIOA->IDR&(1<<3))!=0)
{} 
	
	// wait until the button is released
Delay(10);		

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