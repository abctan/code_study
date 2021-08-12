	.section	.rodata
	.align	2
.LC0:
	.ascii	"val : %#x\n\000"
	.text
	.align	2
	.global	func
	.type	func, %function
func:
	@stmfd	sp!, {fp, lr}
	@add	fp, sp, #4
	@ 保存环境
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4

	@ 0x1000 2000 3000 => ddr
	sub sp, #20	@表示申请20个字节内存空间

	ldr r1, =0x1000 @表示源
	mov r0, sp		@表示目标
	str r1, [r0]	@表示把源给目标(申请栈空间)
	
	ldr r1, =0x2000
	add r0, #4		@表示偏移
	str r1, [r0]

	ldr r1, =0x3000
	add r0, #4
	str r1, [r0]

	ldr r1, =0x4000
	add r0, #4
	str r1, [r0]

	ldr r1, =0x0
	add r0, #4
	str r1, [r0]


	mov r4, sp
	loop:
	ldr r1, [r4]
	cmp r1, #0
	beq out
	ldr r0, .L2
	bl printf

	add r4, #4
	b loop
	
	out:
	@恢复环境
	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr
	@ldmfd	sp!, {fp, pc}
.L3:
	.align	2
.L2:
	.word	.LC0
	.size	func, .-func
	.align	2
	.global	main
	.type	main, %function
main:
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4

	bl	func
	mov	r3, #0
	mov	r0, r3

	ldmfd	sp!, {fp, pc}
	.size	main, .-main
