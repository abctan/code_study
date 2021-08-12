CROSS_COMPILE=arm-linux-
CC=gcc
OBJECTS=test.o
TARGET=test
FLAG=-fno-builtin
LINKADDRESS=-Ttext=0x20008000
RM=rm

${TARGET}.bin:${TARGET}
	${CROSS_COMPILE}objcopy -O binary $^ $@
${TARGET}:${OBJECTS}
	${CROSS_COMPILE}ld ${LINKADDRESS} $^ -o $@
%.o:%.c
	${CROSS_COMPILE}${CC} -c $^ -o $@ ${FLAG}

clean:
	${RM} ${TARGET} ${OBJECTS} ${TARGET}.bin -rf




