CROSS_COMPILE=arm-linux-
CC=gcc
OBJECTS=led.o buzzer.o test.o
TARGET=test
FLAG=-fno-builtin
LINKADDRESS=-Ttext=0x20008000
LINKTEXT=test.lds
RM=rm

${TARGET}.bin:${TARGET}
	${CROSS_COMPILE}objcopy -O binary $^ $@
${TARGET}:${OBJECTS}
	${CROSS_COMPILE}ld -T${LINKTEXT} $^ -o $@
%.o:%.c
	${CROSS_COMPILE}${CC} -c $^ -o $@ ${FLAG}

clean:
	${RM} ${TARGET} ${OBJECTS} ${TARGET}.bin -rf




