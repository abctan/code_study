#include "darr.h"

struct cls_t{
	char name[64];
	int age;
	int id;
	char sex;
	float cn;
	float en;
	float result;
};


#define MAX 10


void ls(void *data)
{
	struct cls_t *new = (struct cls_t *)data;

		printf("name : %6s age : %d id : %d sex : %c cn : %.2f en : %.2f result : %.2f\n",
			new->name, new->age, new->id, new->sex, new->cn, new->en, new->result);

}

int cmp_name(void *d1, void *d2)
{
	return strcmp((char *)d1, ((struct cls_t *)d2)->name);
}
int sort_name(void *d1, void *d2)
{
	return strcmp(((struct cls_t *)d1)->name, ((struct cls_t *)d2)->name);
}
int cmp_age(void *d1, void *d2)
{
	return *(int *)d1 - ((struct cls_t *)d2)->age;
}
int cmp_sex(void *d1, void *d2)
{
	return *(char *)d1 - ((struct cls_t *)d2)->sex;
}

int sort_result(void *d1, void *d2)
{
	return ((struct cls_t *)d1)->result - ((struct cls_t *)d2)->result;
}


/*int main(int argc, char *argv[])*/
int main(void)
{
	int i;
	DARR *handle = NULL;

	handle = darr_load("./stu.db");
	if (handle == NULL)
	{
		printf("darr load false!\n");
		return -1;
	}

	darr_travel(handle, ls);
	return 0;
}
