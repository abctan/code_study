	.section	.rodata
	.align	2
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

	#mov r2, #0x89  @1000 1001
	mov r2, #0x89000000  @1000 1001
	@44 => 0100 0100
	@c48 => 1100 0100 1000 0000
	asr r1, r2, #12
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
