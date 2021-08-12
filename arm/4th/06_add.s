	.section	.rodata
	.align	2
.LC0:
	.ascii	"add : %d + %d = %d\n\000"
.LC1:
	.ascii	"sub : %d - %d = %d\n\000"
.LC2:
	.ascii	"mul : %d * %d = %d\n\000"



	.text
	.align	2
	.global	func
	.type	func, %function
func:
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	@ 保存环境

	mov r1, #10
	mov r2, #20
	add r3, r1, r2
	ldr	r0, .L2
	bl	printf

	mov r1, #10
	mov r2, #20
	sub r3, r1, r2
	ldr	r0, .L4
	bl	printf

	mov r1, #10
	mov r2, #20
	mul r3, r1, r2
	ldr	r0, .L5
	bl	printf
	@恢复环境
	ldmfd	sp!, {fp, pc}
.L3:
	.align	2
.L2:
	.word	.LC0
.L4:
	.word	.LC1
.L5:
	.word	.LC2


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
