	.section	.rodata
	.align	2
.LC0:
	.ascii	"\n\000"
.LC1:
	.ascii	"%d * %d = %2d  \000"

	.text
	.align	2
	.global	func
	.type	func, %function
func:
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	@ 保存环境

	mov r4, #1
	I:
	
	@===============
	mov r5, #1
		J:
	
		mov r1, r5
		mov r2, r4
		mul r3, r4, r5
		ldr	r0, .L4
		bl	printf

		add r5, #1
		cmp r5, r4
		ble J

	@===============

	ldr	r0, .L2
	bl	printf

	add r4, #1

	cmp r4, #9
	ble I



	@恢复环境
	ldmfd	sp!, {fp, pc}
.L3:
	.align	2
.L2:
	.word	.LC0
.L4:
	.word	.LC1
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
