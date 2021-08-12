#include "res.h"
#include "device.h"


int _start(void)
{

	configure_led();
	configure_buzzer();

	while(1)
	{
		led_on();
		buzzer_on();
		delay();
		led_off();
		buzzer_off();
		delay();
	}
	return 0;
}
