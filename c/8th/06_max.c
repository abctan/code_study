#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX(a, b) (((a) > (b)) ? (a) : (b))

/*
 *#define MAX(a, b) 	if (a > b)					\
 *                        printf("max : %d\n", a);	\
 *                    else						\
 *                        printf("max : %d\n", b);
 */
//如果宏需要返回值，且是多了语句，则要使用({})
/*
 *#define MAX(a, b) 	({int max;		\
 *                    if (a > b)		\
 *                        max = a;	\
 *                    else			\
 *                        max = b;	\
 *                    max;			\
 *                    })
 */

//表示多条语句且无返回值格式
#define SWAP(a, b) 	do{int tmp;	\
						tmp = a;	\
						a = b;		\
						b = tmp;	\
					}while(0)
int main(void)
{
	int a = 30, b = 20;	
	printf("max : %d\n", MAX(10, 20));

	printf("a : %d b : %d\n", a, b);
	SWAP(a, b);
	printf("a : %d b : %d\n", a, b);
	return 0;
}
