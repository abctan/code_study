all:
	arm-linux-gcc -c test.c -o test.o -fno-builtin
	arm-linux-ld -Ttext=0x20008000 test.o -o test
	arm-linux-objcopy -O binary test test.bin
clean:
	rm test test.o test.bin -rf




