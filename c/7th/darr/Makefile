CC=gcc
OBJECTS=main.o darr.o
TARGET=darr

all:${OBJECTS}
	${CC} $^ -o ${TARGET}	
load:
	gcc darr.c load.c -o load
clean:
	rm  ${OBJECTS} ${TARGET} load
