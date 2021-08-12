#include "device.h"


void configure_buzzer(void)
{
	GPD0CON &= ~0xF;
	GPD0CON |= 0x1;

	buzzer_off();
}

void buzzer_on(void)
{
	GPD0DAT |= 0x1;
}
void buzzer_off(void)
{
	GPD0DAT &= ~0x1;
}
