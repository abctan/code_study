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

	ldr r4, .L5
	loop:
	#ldr r1, [r4, #4]!
	ldr r1, [r4], #4
	ldr r0, .L4
	cmp r1, #0x0
	beq out
	bl	printf


	b loop

	out:

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
	.word	0x0
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
