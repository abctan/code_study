#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	int a[5] = {1,2,3,4,5};
	int b[5];

	memcpy(b, a, 5 * sizeof(int));

	for (i = 0; i < 5; i++)
	{
		printf("%d ", b[i]);
	}
	putchar(10);
/*
 *    for (i = 0; i < 5; i++)
 *    {
 *        b[i] = a[i]
 *    }
 *
 *    b = a;//strcpy(dest, src) test(a, b) memcpy
 */

	return 0;
}
