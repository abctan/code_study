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

	#mov r1, #123
	@ 0x55 => 0101 0101 => 0010 1010 => 0x2a
	#mov r2, #0x55
	@ => 1000 0101 0000 0000 ... 0000
	@ => 1100 0010 1000 0000 ... 0000 => 0xc2800000
	mov r2, #0x85000000
	asr r1, r2, #33
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
