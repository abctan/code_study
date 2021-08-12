	.section	.rodata
	.align	2
.LC0:
	.ascii	"hello test world\n\000" @src
	.text
	.align	2
	.global	func
	.type	func, %function
func:
	@ 保存环境
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4


	@目标
	sub sp, #30

	ldr r4, .L2 @src
	mov r5, sp  @dest
	
	loop:
		
		ldr r1, [r4], #1
		cmp r1, #0
		beq out
		str r1, [r5], #1

	b loop

	out:

	mov r0, sp
	bl printf

	@恢复环境
	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr

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
