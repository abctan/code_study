//#include <stdio.h>


//int printf(const char *format, ...);

//int (*p)(const char *format, ...) = printf;
int (*p)(const char *format, ...) = (void *)0x0023de50;

int main(void)
{
	p("hello world!\n");
	return 0;
}
