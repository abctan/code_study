CC=gcc
OBJECTS=hello.o main.o world.o
TARGET=hello
CP=cp
RM=rm

${TARGET}:${OBJECTS}
	${CC} $^ -o $@
install:
	${CP} ${TARGET} /bin
uninstall:
	${RM} /bin/${TARGET} -rf

.PHONY:clean
clean:
	${RM} *.o ${TARGET} /bin/${TARGET} -rf

#hello.o:hello.c
#	gcc -c $< -o $@
#main.o:main.c
#	gcc -c $< -o $@

#%.o:%.c
#	gcc -c $< -o $@

