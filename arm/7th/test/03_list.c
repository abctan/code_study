#include <stdio.h>

#define GETADDRESS(type, address, number)	(type *)((char *)(address) - (unsigned int)(&(((type *)0)->number)))

#define container_of(ptr, type, member) ({          \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	    (type *)( (char *)__mptr - offsetof(type,member) );})

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

struct node_t{
	struct node_t *next;
	struct node_t *prev;
};

struct cls_t{
	char name[128];
	int age;
	char sex;
	struct node_t sel;
};

struct tea_t{
	char name[64];
	int level;
	struct node_t sel;
};

struct cor_t{
	struct node_t sel;
	char name[16];
	float result;
};

void insert(struct node_t *head, struct node_t *new)
{
	//链表插入尾插
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	
}

void travel(struct node_t *head)
{
	struct cls_t *cp = NULL;

	/*cp = (struct cls_t *)((char *)head->next - (unsigned int)(&(((struct cls_t *)0)->sel)));*/
	/*cp = GETADDRESS(struct cls_t, head->next, sel);*/
	cp = container_of(head->next, struct cls_t, sel);
	
	printf("name : %s age : %d sex : %c\n", cp->name, cp->age, cp->sex);

	struct tea_t *tp = NULL;
	/*tp = (struct tea_t *)((char *)head->next->next - (unsigned int)(&(((struct tea_t *)0)->sel)));*/
	tp = GETADDRESS(struct tea_t, head->next->next, sel);
	printf("name : %s level : %d\n", tp->name, tp->level);

	struct cor_t *kp = NULL;
	kp = (struct cor_t *)((char *)head->next->next->next - (unsigned int)(&(((struct cor_t *)0)->sel)));

	printf("name : %s result : %.2f\n", kp->name, kp->result);
}
int main(void)
{
	struct node_t head = {&head, &head};//头节点
	struct cls_t cls = {.name = "tom", .age = 18, .sex = 'F'};
	struct tea_t tea = {.name = "laozhang", .level = 2};
	struct cor_t cor = {.name = "arm", .result = 88.88};

	insert(&head, &cls.sel);
	insert(&head, &tea.sel);
	insert(&head, &cor.sel);

	travel(&head);

	return 0;
}
