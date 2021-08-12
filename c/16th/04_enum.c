#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//定义枚举类型 0 1 2 3 4 5 6  枚举常量
	enum weekday {sun, mon = 3, tue, wed, thu, fri, sat};
	
	//定义枚举变量 
	enum weekday a;

	/*a.sun = 1;*/
	
	printf("sizeof(weekdaya) = %d\n", sizeof(enum weekday));

	/*a = sun;*/
	a = (enum weekday)1;

	/*a = tue;*/

	printf("a : %d\n", a);
	
	return 0;
}
