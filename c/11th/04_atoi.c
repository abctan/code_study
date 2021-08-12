#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//123 => 1
int my_atoi(char *s)
{
	int result = 0;

	while(*s != '\0')
	{
		if (*s < '0' || *s > '9')
		{
			return result;
		}
		result *= 10;
		result += *s - 48;
		s++;
	}
	return result;
}
int main(void)
{
	
	printf("atoi : %d\n", my_atoi("A123A456"));
	return 0;
}
