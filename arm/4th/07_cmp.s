	.section	.rodata
	.align	2
.LC0:
	.ascii	"max : %d\n\000"
	.text
	.align	2
	.global	func
	.type	func, %function
func:
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	@ 保存环境

	mov r3, #456
	mov r2, #456
	cmp r2, r3

	movge r1, r2
	movlt r1, r3

	ldr	r0, .L2
	bl	printf

	@恢复环境
	ldmfd	sp!, {fp, pc}
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
