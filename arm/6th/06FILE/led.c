#include "device.h"


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

