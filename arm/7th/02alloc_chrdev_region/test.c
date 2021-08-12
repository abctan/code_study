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
//字符设备头文件
#include <linux/cdev.h>
//错误信息头文件
#include <linux/err.h>
//错误序号值
#include <asm-generic/errno-base.h>//基础错误
#include <asm-generic/errno.h>//中级错误
#include <linux/errno.h>//高级错误


//定义主设备号和驱动名
//#define iMAJOR	200
#define iBASEMINOR	5
#define iMINORCNT	5
#define iNAME	"kitty"

//定义一个主设备号和次设备整合体
dev_t device;
struct cdev *cdevice = NULL;
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

	//1 动态注册字符设备驱动 创建第一张HASH
	ret = alloc_chrdev_region(&device, iBASEMINOR, iMINORCNT, iNAME);
	if (ret < 0)
	{
		printk("alloc_chrdev_region false!\n");
		goto ERR1;
	}
	printk("major : %d\n", MAJOR(device));

	// 2 申请cdev
	cdevice = cdev_alloc();
	if (IS_ERR(cdevice))
	{
		ret = -ENOMEM;
		goto ERR2;
	}

	//3 初始化
	cdev_init(cdevice, &fops);

	//4 添加  
	ret = cdev_add(cdevice, device, iMINORCNT);
	if (ret < 0)
	{
		printk("cdev_add false!\n");
		goto ERR2;
	}
	printk("hello world!\n");
	return 0;

ERR2:
	unregister_chrdev_region(device, iMINORCNT);
ERR1:
	return ret;
}

//出口函数
static void __exit test_exit(void)
{
	cdev_del(cdevice);
	unregister_chrdev_region(device, iMINORCNT);
	printk("goodbye!\n");
}

//告诉kernel驱动入口和出口函数
module_init(test_init);
module_exit(test_exit);

//遵循的开源协议
MODULE_LICENSE("GPL");
