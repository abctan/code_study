#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>

//数组指针：
//指针数组：
int main(int argc, char *argv[])
{
	char name[10][10] = {"tom", "jim", "mary"};
	char (*p)[10] = NULL;//数组指针
	char *q[10] = {"tom", "jim", "mary"};//指针数组
	char **v = NULL;
	
	/*v = name;*/
	/*v = q;*/
	v = p;
	/*p = name;*/
	/*q = name;*/
/*
 *    int arr[2][3][4] = {1,2,3,4,5,6};
 *    int (*p)[3][4] = NULL;
 *
 *    p = arr;
 *    printf("sizeof(p) : %d\n", sizeof(p));
 */
/*
 *    p[0] = arr[0]
 *    p[1] = arr[1]
 *    p = arr;
 *
 *    printf("&p : %p &p + 1 : %p\n", &p, &p + 1);
 *    printf("**arr : %d\n", **arr);
 */
	// &p p *p **p
	//&arr arr arr[0] arr[0][0]
	//&brr 		12*4
	//brr 		6
	//brr[0] 	2
	//brr[0][0] 1
	

	//&arr :	address	表示整个数组地址 +1偏移整个数组大小
	//arr  :	address 表示行的首地址 +1偏移行大小
	//arr[0] :  value   表示列的首地址 +1偏移一列大小
	//arr[0][0] : value
/*
 *    int i;
 *
 *    printf("&arr : %lu &arr + 1 : %lu\n", &arr, &arr + 1);
 *    printf("arr : %lu arr + 1 : %lu\n", arr, arr + 1);
 *    printf("arr[0] : %lu arr[0] + 1 : %lu\n", arr[0], arr[0] + 1);
 *    printf("arr[0][0] : %d\n", arr[0][0]);
 *    for (i = 0; i < 6; i++)
 *    {
 *        [>printf("%d ", *(arr[0] + i));<]
 *        printf("%d ", arr[0][i]);
 *    }
 *    printf("\n");
 */

/*
 *    //char
 *    char (*p)[5];//数组指针
 *    char *q[5];//指针数组
 *
 *    printf("sizeof(p) : %d\n", sizeof(p));
 *    printf("sizeof(q) : %d\n", sizeof(q));
 */
	return 0;
}
