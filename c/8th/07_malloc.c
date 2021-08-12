#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERRP(con, string, ret)	do{				\
						if (con)				\
						{						\
							printf(string"\n");		\
							ret;				\
						}						\
					}while(0)

int main(void)
{
	int ***p = NULL;//无地址
	// &p， p

	printf("&p : %p\n", &p);
	p = (int ***)malloc(sizeof(int **));
	/*p = NULL;*/
	ERRP(p == NULL, "malloc p false", goto ERR1);
    /*
	 *if (p == NULL)
	 *{
	 *    printf("malloc p false!\n");
	 *    return -1;
	 *}
	 *printf("p : %p\n", p);
     */

	ERRP((*p = (int **)malloc(sizeof(int *))) == NULL, "malloc *p false", goto ERR2);

    /*
	 *if (*p == NULL)
	 *{
	 *    printf("malloc *p false!\n");
	 *    free(p);
	 *    return -1;
	 *}
	 *printf("*p : %p\n", *p);
     */
	**p = (int *)malloc(sizeof(int));
	**p = NULL;
	ERRP(**p == NULL, "malloc **p false", goto ERR3);
    /*
	 *if (**p == NULL)
	 *{
	 *    
	 *    printf("malloc **p false!\n");
	 *    free(*p);
	 *    free(p);
	 *    return -1;
	 *}
     */
	//&p : 四级指针
	//p 三级指针变量名
	//*p : 二级指针
	//**p : 一级指针
	//***p : 变量的值
	/*p = (int ***)malloc(sizeof(int **));*/

	***p = 123;
	printf("***p : %d\n", ***p);


	free(**p);
	free(*p);
	free(p);
	return 0;
ERR3:
	free(*p);
ERR2:
	free(p);
ERR1:
	return -1;
}
