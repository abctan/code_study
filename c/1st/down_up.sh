#!/bin/bash

IP=192.168.0.254
SHAREDIR=/ken
SHAREWORK=/homework

#1 检测网络
if ! ping $IP -c 1 > /dev/null
then
	echo "no link"
	exit 0
fi	


#2 检测nfs服务是否配置
if ! showmount -e $IP &> /dev/null
then
	echo "nfs false"
	exit 0
fi

umount -l /mnt &> /dev/null

#3下载可见还是上传作业
if [ $1 == down ]
then
	#表示挂在
	mount $IP:$SHAREDIR /mnt
	cp /mnt/* /zhangsan -rf
	umount /mnt
elif [ $1 == up ]
then
	mount $IP:$SHAREWORK /mnt
	cp /254_张三 /mnt -rf
	umount /mnt
else
	echo "option err"
fi












