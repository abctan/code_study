#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//4G
void stack(void)
{
	static int count = 0;
	char buf[1024] = {};//1K

	printf("count : %d\n", count++);
	stack();
}

int main(void)
{
	int arr[1024 * 1024 * 2];

	printf("arr[1024 * 1024 * 4] = %d\n", arr[1024 * 1024 * 2 - 1]);
	/*stack();*/
	return 0;
}
