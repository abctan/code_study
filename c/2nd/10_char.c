#include <stdio.h>

int main(void)
{
	int a;
	char ch;

	printf("please input number : ");
	scanf("%d", &a);

	printf("a : %d\n", a);

	getchar();

	printf("please input char : ");
	scanf("%c", &ch);

	printf("ch : %c\n", ch);

	return 0;
}
