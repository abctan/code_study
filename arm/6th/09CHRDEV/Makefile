#表示项目名
obj-m=test.o

#表示内核存放路径
KERN=/tools/armpdf/linux-2.6.35.7

#编译方法
all:
	make -C ${KERN} M=`pwd` modules

#清除方法
clean:
	make -C ${KERN} M=`pwd` modules clean
