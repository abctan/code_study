//驱动模块头文件
#include <linux/module.h>
//初始化头文件
#include <linux/init.h>
//内核态映射头文件
#include <asm/io.h>
//常量大小头文件
#include <asm/sizes.h>

//led register address
#define GPJ2CON 0xE0200280
#define GPJ2DAT 0xE0200284
//寄存器地址kernel不可以直接访问， 则需要映射到kernel
//ioremap(address size) => void __iomem *
//__iomem : 表示内核态空间地址 

//定义一个内核态空间地址
static int __iomem *conf_led = NULL;


//=====================================
//app 应用层
//=====================================
//kernel 文件访问层

//=====================================
//硬件操作层
//3 硬件初始化
void led_on(void)
{
	unsigned int val;
	val = ioread32(conf_led + 1);
	val &= ~0xF;
	iowrite32(val, conf_led + 1);
}

void led_off(void)
{
	unsigned int val;
	val = ioread32(conf_led + 1);
	val |= 0xF;
	iowrite32(val, conf_led + 1);
}

void configure_led(void)
{
	unsigned int val;
	//取出映射内核态空间地址数据
	val = ioread32(conf_led);
	val &= ~0xFFFF;
	val |= 0x1111;
	iowrite32(val, conf_led);
	
	led_off();
}
//1 对硬件初始化
static void Hardware_Init(void)
{
	//表示映射用户空间地址到kernel空间地址
	conf_led = ioremap(GPJ2CON, SZ_1K);	

	configure_led();
}



//2 硬件退出
static void Hardware_Exit(void)
{
	//解映射
	led_off();
	iounmap(conf_led);
}


//======================================
//实现设备驱动入口和出口
//入口函数
static int __init test_init(void)
{
	printk("hello world!\n");
	//硬件初始化
	Hardware_Init();
	//开灯
	led_on();
	return 0;
}

//出口函数
static void __exit test_exit(void)
{
	//关灯
	led_off();
	//硬件销毁
	Hardware_Exit();
	printk("goodbye!\n");
}

//告诉kernel驱动入口和出口函数
module_init(test_init);
module_exit(test_exit);

//遵循的开源协议
MODULE_LICENSE("GPL");
