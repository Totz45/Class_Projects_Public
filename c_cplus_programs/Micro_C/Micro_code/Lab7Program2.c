void Delay(unsigned int); 
void Init_LED0(void);
int main(void)
{
/* Reset of all peripherals, Initializes the Flash interface and the Systick. */ HAL_Init();
/* Configure the system clock */ 
SystemClock_Config();

Init_LED0();

while (1)
{
/* Approach 1	Using set and reset */ 
	GPIOB->ODR|=(1<<1);
Delay(4000);
GPIOB->ODR&=~(1<<1);
Delay(1000);
}
}void Init_LED0()
{												
uint32_t temp;
RCC->IOPENR|=0x00000002;	/* enable GPIOB clock */

temp = GPIOB->MODER;
temp &= ~(0x03<<(2*1)); 
temp|=(0x01<<(2*1)); 
GPIOB->MODER = temp;
temp=GPIOB->OTYPER;
temp &=~(0x01<<1); 
GPIOB->OTYPER=temp;

temp=GPIOB->PUPDR;
temp&=~(0x03<<(2*1));
GPIOB->PUPDR=temp;
}