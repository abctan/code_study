	.section	.rodata
	.align	2
@8460	
.LC0:
	.ascii	"val : %#x\n\000"
	.text
	.align	2
	.global	func
	.type	func, %function
func:
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	@ 保存环境

	ldr r2, .L5
	ldr r1, [r2]
	ldr r0, .L4
	bl	printf

	ldr r2, .L5
	add r2, #4
	ldr r1, [r2]
	ldr r0, .L4
	bl	printf

	ldr r2, .L5
	add r2, #8
	ldr r1, [r2]
	ldr r0, .L4
	bl	printf
	
	ldr r2, .L5
	add r2, #12
	ldr r1, [r2]
	ldr r0, .L4
	bl	printf
	@恢复环境
	ldmfd	sp!, {fp, pc}
.L3:
	.align	2
.L5:
	.word	.L2
.L2: @83cc
	.word	0x1000
	.word	0x2000
	.word	0x3000
	.word	0x4000
.L4:
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
