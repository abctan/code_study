#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ADD(a, b) a + b
#define MUL(a, b) ((a) * (b))

int main(void)
{
	printf("mul : %d\n", MUL(3 + 2, 3));

	// char => short => int => long => double <= float
	printf("ADD : %d\n", ADD(1, 2));
	printf("ADD : %d\n", (int)(ADD(1.11, 2.22)));
	printf("ADD : %d\n", ADD('A', 'B'));
	return 0;
}
