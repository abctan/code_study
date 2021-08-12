#include <stdio.h>

int main(void)
{
	int i, j;

	int arr[2][3];
	int **p;

	/*p = arr;*/
	p = test(2, 3);

	for(i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			p[i][j] = rand() % 100;
		}
	}
	for(i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d\n", p[i][j]);
		}
	}


	return 0;
}
