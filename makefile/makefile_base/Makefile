#头文件相对路径，以MakeFile所在文件为根目录
#这个变量留给用户去配置，后面会将INC_DIRS转换成绝对路径，因为编译器只能识别到绝对路径，
#之所以填入相对路径，是因为这样对用户来说更加简洁明了。
#谨记：将丑陋留给自己，把复杂藏在内部
INC_DIRS := inc

#源文件相对路径，以MakeFile所在文件为根目录
#同上
SRC_DIRS := src  \
            main \

#静态/动态库路径
LIB_DIRS := lib


#.o文件输出目录，以MakeFile所在文件为根目录
#同上，以根目录下的output为.o文件输出目录
OUTPUT_COBJS := output

CFLAGS += -Wall -Os -g
CLIBS += -lpthread

#将INC_DIRS、SRC_DIRS、OUTPUT_COBJS 转换为绝对路径
CUR_DIRS = $(shell pwd)
INC_DIRS := $(patsubst %, $(CUR_DIRS)/%, $(INC_DIRS))
SRC_DIRS := $(patsubst %, $(CUR_DIRS)/%, $(SRC_DIRS))
LIB_DIRS := $(patsubst %, $(CUR_DIRS)/%, $(LIB_DIRS))

OUTPUT_COBJS := $(patsubst %, $(CUR_DIRS)/%, $(OUTPUT_COBJS))

#VPATH是Makefile的内置变量，依赖项如果在根目录找不到的话就从VPATH目录中查找.
VPATH := $(SRC_DIRS)

#指定编译器工具名称前缀
#CROSS_COMPILE ?= arm-linux-gnueabihf-
CROSS_COMPILE ?=
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
AS = $(CROSS_COMPILE)as
NM = $(CROSS_COMPILE)nm
STRIP = strip

#CFLAGS用于C编译器的编译选项。
CFLAGS += $(patsubst %,-I%,$(INC_DIRS))
#CFLAGS += $(patsubst %,-L%,$(LIB_DIRS))
###############


CFILES := $(foreach n, $(SRC_DIRS), $(wildcard $(n)/*.c))
CFILES_NO_DIE := $(notdir $(CFILES))
OBJS=$(CFILES:.c=.o)
OUTPUT_OBJS := $(patsubst %,$(OUTPUT_COBJS)/%,$(notdir $(OBJS)))



all: $(OUTPUT_OBJS)
	@gcc $^ -o demo
	@echo "LD  $^"

$(OUTPUT_COBJS)/%.o: %.c
	@gcc -c $(CFLAGS) $^ -o $@
	@echo "CC  $^"

clean:
	rm -rf *.o $(OBJS) $(OUTPUT_COBJS)/* demo

test:
	@echo "${INC_DIRS}"
	@echo "${SRC_DIRS}"
	@echo "${LIB_DIRS}"
	@echo "${OUTPUT_COBJS}"
	@echo "${SRCS}"
	@echo "${OBJS}"
	@echo "${CFILES_NO_DIE}"
	@echo "${OUTPUT_OBJS}"