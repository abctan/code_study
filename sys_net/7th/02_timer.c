#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>
#include <pwd.h>
#include <grp.h>
#include <shadow.h>
#include <time.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <signal.h>

//抽象定时器类型 链表
struct timer_t{
	struct timer_t *next;//指向下一个节点地址
	struct timer_t *prev;//指想上一个节点地址
	int timer;//表示定时器时间
	int t;//累加器 累加机器时间 1sencond
	void (*func)(void *data);//函数指针
	void *data;//表示打印数据
	int flag;//表示是否循环打印
};

//定义一个全局有头双向循环链表
struct timer_t head = {.next = &head, .prev = &head};


//执行函数
void action_timer(int sig)
{
	struct timer_t *tail = NULL, *new = NULL;

	//遍历链表
	for (tail = head.next; tail != &head; tail = new)
	{
		new = tail->next;
		tail->t++;
		if (tail->t == tail->timer)
		{
			tail->func(tail->data);
			tail->t = 0;

			if (tail->flag == 0)
			{
				tail->next->prev = tail->prev;
				tail->prev->next = tail->next;
				free(tail);
			}
		}	
	}

}


//初始化定时器
void init_timer(void)
{
	struct itimerval it;

	//闹钟执行函数
	ERRP(signal(SIGALRM, action_timer), signal, goto ERR1);

	//循环时间
	it.it_interval.tv_sec = 1;
	it.it_interval.tv_usec = 0;
	//第一次执行时间
	it.it_value.tv_sec = 2;
	it.it_value.tv_usec = 0;

	//设定定时器
	ERRP(setitimer(ITIMER_REAL, &it, NULL) == -1, setitimer, goto ERR1);

	return ;
ERR1:
	return ;
}

//实现定时器打印函数
void func(void *data)
{
	printf("%d => %d\n", (int *)data, time(NULL));
}

//实现定时器任务函数
int add_timer(int t, void (*hello)(void *), void *data, int flag)
{
	struct timer_t *new = NULL;

	//申请新的空间地址
	new = (struct timer_t *)malloc(sizeof(struct timer_t));
	ERRP(new == NULL, malloc, goto ERR1);
	
	//初始化
	new->next = NULL;
	new->prev = NULL;
	new->timer = t;
	new->t = 0;//累加器
	new->func = hello;
	new->data = data;
	new->flag = flag;//是否循环执行

	//连接节点到链表中 end
	new->next = &head;
	new->prev = head.prev;
	head.prev->next = new;
	head.prev = new;


	
	return 0;
ERR1:
	return -1;
}
int main(int argc, char *argv[])
{
	//初始化定时器
	init_timer();

	//添加定时器任务
	add_timer(1, func, (void *)1111, 0);
	add_timer(2, func, (void *)2222, 0);
	add_timer(3, func, (void *)3333, 1);
	add_timer(6, func, (void *)6666, 1);
	add_timer(7, func, (void *)7777, 0);
	add_timer(9, func, (void *)9999, 1);
	add_timer(5, func, (void *)5555, 0);
	add_timer(4, func, (void *)4444, 1);

	getchar();
	return 0;
}











