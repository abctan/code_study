#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.14
//#define R	3
#define AREA(R) PI * R * R

//函数
float area(int r)
{
	return PI * r * r;
}

int main(void)
{
	int r = 2;
	float f = 3.44

	printf("please input r : ");
	scanf("%d", &r);

	printf("area : %.2f\n", area(r));
	printf("AREA : %.2f\n", AREA(r));
    /*
	 *printf("PI = %.2f\n", PI);
	 *printf("area : %.2f\n", PI * r * r);
	 *printf("AREA : %.2f\n", AREA);
     */
	return 0;
}
