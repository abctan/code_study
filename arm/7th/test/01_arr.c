#include <stdio.h>


#define __must_be_array(a) \
  BUILD_BUG_ON_ZERO(__builtin_types_compatible_p(typeof(a), typeof(&a[0])))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))

/*
 *struct op_t{
 *    int a:-;
 *};
 */

#define BUILD_BUG_ON_ZERO(e) (sizeof(struct { int:-!!(e); }))
void test(int arr[])
{
	printf("sizeof(struct {int :-0}) = %d\n", sizeof(struct {int : -0;}));
	//&arr arr
	/*printf("test : len : %d\n", ARRAY_SIZE(arr));*/
	printf("test : sizeof(arr) / sizeof(arr[0]) = %d\n", sizeof(arr) / sizeof(arr[0]));
}

int main(void)
{
	int a;
	typeof(a) b;

	int arr[10];

	//&arr arr
	test(arr);

	printf("main : len : %d\n", ARRAY_SIZE(arr));
	printf("main : sizeof(arr) / sizeof(arr[0]) = %d\n", sizeof(arr) / sizeof(arr[0]));
}
