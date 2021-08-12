//led register address
#define GPJ2CON *(unsigned int *)0xE0200280
#define GPJ2DAT *(unsigned char *)0xE0200284


void configure_led(void);
void led_on(void);
void led_off(void);
void delay(void);


int _start(void)
{

	configure_led();

	while(1)
	{
		led_on();
		delay();
		led_off();
		delay();
	}
	return 0;
}

void configure_led(void)
{
	GPJ2CON &= ~0xFFFF;
	GPJ2CON |= 0x1111;

	led_off();
}

void led_on(void)
{
	GPJ2DAT &= ~0xF;
}
void led_off(void)
{
	GPJ2DAT |= 0xF;
}

void delay(void)
{
	unsigned int val = 0x7fffff;

	while(val--)
		;
}

