#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <share.h>

//strlen strcpy strncpy strcat  strncat strcmp  strncmp strchr strrchr strstr  strstr

int my_strlen(char *s)
{
	int i = 0;

	while(*s != '\0')
	{
		i++;
		s++;
	}

	return i;
}
char *my_strcpy(char *dest, const char *src)
{
	char *tmp = dest;

#if 0
	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	/*dest = src;*/
#else
	while((*dest++ = *src++) != '\0')
	{
		;
	}
#endif
	return tmp;
}

char *my_strcat(char *dest, const char *src)
{
	char *tmp = dest;

	while(*dest != '\0')
		dest++;
	
	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return tmp;
}
int my_strcmp(const char *s1, const char *s2)
{
	while(*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}

	return *s1 - *s2;
}

char *my_strchr(const char *s, int c)
{
	while(*s != '\0')
	{
		if (*s == c)
		{
			return (char *)s;
		}
		s++;
	}
	return NULL;
}


char *my_strstr(const char *haystack, const char *needle)
{
	while(*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			if (strncmp(haystack, needle, strlen(needle)) == 0)
			{
				return (char *)haystack;
			}
		}
		haystack++;
	}
	return NULL;
}
int main(void)
{
	char dest[64] = "kkkkkkkkkkkkkkk";
	char src[64] = "hello";

	printf("dest : %s\n", dest);
	my_strcat(dest, src);
	/*strcpy(dest, src);*/
	/*printf("ret : %s\n", my_strcpy(dest + 1, src + 2));*/
	/*printf("ret : %s\n", strcpy(dest, src));*/
	printf("dest : %s\n", dest);

	printf("my_strcmp(make, mask) = %d\n", my_strcmp("make", "mask"));
	printf("my_strcmp(mask, make) = %d\n", my_strcmp("mask", "make"));
	printf("my_strcmp(mask, mask) = %d\n", my_strcmp("mask", "mask"));

	printf("my_strchr(hello, l) = %s\n", my_strchr("hello", 'l'));
	printf("my_strchr(hello, L) = %s\n", my_strchr("hello", 'L'));
	printf("my_strstr(hello, ll) = %s\n", my_strstr("hello", "Ll"));
/*
 *    char buf[64];
 *
 *    GETLINES("please input string : ", buf);
 *
 *    printf("buf : %s\n", buf);
 *
 */
	
	/*printf("strlen(buf) : %d\n", strlen(buf));*/
	/*printf("my_strlen(buf) : %d\n", my_strlen(buf));*/
	return 0;
}
