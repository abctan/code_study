#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char s[64];

	printf("please input string : ");
	fgets(s, sizeof(s), stdin);
	if (s[strlen(s) - 1] == '\n')	
		s[strlen(s) - 1] = '\0';
	/*scanf("%s", s);*/
	/*gets(s);*/

	printf("s : %s\n", s);
	return 0;
}
