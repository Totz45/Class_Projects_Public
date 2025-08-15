#include "main.h"

void Delay(unsigned int); 
void Init_LED0(void);
int main(void)
{
/* Reset of all peripherals, Initializes the Flash interface and the Systick. */ HAL_Init();
/* Configure the system clock */ 
/* SystemClock_Config(); */

Init_LED0();

while (1)
{
/* Approach 1	Using set and reset */ 
	unsigned int period = 5000;
	unsigned int ton = period * 0.2;
	
	GPIOA->ODR|=(1<<12);
Delay(ton);
GPIOA->ODR&=~(1<<12);
Delay(period - ton);
}
}
void Init_LED0()
{											
uint32_t temp;
RCC->IOPENR|=0x00000001;	/* enable GPIOA clock */

temp = GPIOA->MODER;
temp &=~(0x03<<(2*12)); 
temp|=(0x01<<(2*12)); 
GPIOA->MODER = temp;
temp=GPIOA->OTYPER;
temp &=~(0x01<<12); 
GPIOA->OTYPER=temp;

temp=GPIOA->PUPDR;
temp&=~(0x03<<(2*12));
GPIOA->PUPDR=temp;
}
void Delay(unsigned int n){
	int i;
	for (; n > 0; n--)
	for (i = 0; i < 136; i++)
	; /*1ms */
}