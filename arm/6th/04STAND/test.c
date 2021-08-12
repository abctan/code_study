
int (*printf)(const char *format, ...) = (void *)0xc3e293b0;

int _start(void)
{
	printf("this is uboot test!\n");
	return 0;
}
