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

	mov r2, #0x95    @1001 0101 => 0000 1001 0101
	mov r3, #0x85	 @1000 0101 => 0010 0001 0100	
	@bic r1, r2, r3 @0000 1111
	@1110 0001 1100 0010 0001 0001 0000 0011
	@e1c21103
	@e1c21103
	bic r1, r2, r3, lsl #2 @ => 0000 1001 0101 => 95
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
