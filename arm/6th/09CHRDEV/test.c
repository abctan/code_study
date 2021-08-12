//驱动模块头文件
#include <linux/module.h>
//初始化头文件
#include <linux/init.h>
//内核态映射头文件
#include <asm/io.h>
//常量大小头文件
#include <asm/sizes.h>
//文件头文件
#include <linux/fs.h>

//定义主设备号和驱动名
#define iMAJOR	200
#define iNAME	"kitty"


//=====================================
//app 应用层
//=====================================
//kernel 文件访问层
int my_open(struct inode *mynode, struct file *fp)
{
	printk("this is my open ...\n");
	return 0;
}
int my_close(struct inode *mynode, struct file *fp)
{
	printk("this is my close ...\n");
	return 0;
}

ssize_t my_read(struct file *fp, char __user *buf, size_t size, loff_t *loff)
{
	printk("this is my read ...\n");
	return 0;
}

ssize_t my_write(struct file *fp, const char __user *buf, size_t size, loff_t *loff)
{
	printk("this is my write ...\n");
	return 0;
}
struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = my_open,
	.release = my_close,
	.read = my_read,
	.write = my_write,
};
//=====================================
//硬件操作层

//======================================
//实现设备驱动入口和出口
//入口函数
static int __init test_init(void)
{
	int ret;

	// 1 注册一个字符设备驱动
	ret = register_chrdev(iMAJOR, iNAME, &fops);
	if (ret < 0)
	{
		printk("register_chrdev false!\n");
		goto ERR1;
	}

	printk("hello world!\n");
	return 0;
ERR1:
	return -1;
}

//出口函数
static void __exit test_exit(void)
{
	printk("goodbye!\n");
	// 销毁
	unregister_chrdev(iMAJOR, iNAME);
}

//告诉kernel驱动入口和出口函数
module_init(test_init);
module_exit(test_exit);

//遵循的开源协议
MODULE_LICENSE("GPL");
