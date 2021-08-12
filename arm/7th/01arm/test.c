//驱动模块头文件
#include <linux/module.h>
//初始化头文件
#include <linux/init.h>


//实现设备驱动入口和出口
//入口函数
static int __init test_init(void)
{
	printk("hello world!\n");
	return 0;
}

//出口函数
static void __exit test_exit(void)
{
	printk("goodbye!\n");
}

//告诉kernel驱动入口和出口函数
module_init(test_init);
module_exit(test_exit);

//遵循的开源协议
MODULE_LICENSE("GPL");
//开发者
MODULE_AUTHOR("zhangsan");
//描述性信息
MODULE_DESCRIPTION("this is test program!");
//其他信息
MODULE_INFO(qq, "317297515");
MODULE_INFO(E_mail, "317297515@qq.com");

