	.section	.rodata
	.align	2
.LC0:
	.ascii	"val : %d\n\000"
	.text
	.align	2
	.global	func
	.type	func, %function
func:
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	@ 保存环境

	mov r4, #0
	loop:
	
	mov r1, r5
	ldr	r0, .L2
	bl	printf

	add r4, r4, #1	
	add r5, r4
	mov r1, r5
	@ldr	r0, .L2
	@bl	printf

	cmp r4, #100
	bgt out

	b loop
	
	out:
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
