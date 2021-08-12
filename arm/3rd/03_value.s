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

	@1110 0011 1010 0000 0001 0000 0111 1011
	@e3a0107b
	@e3a0107b

	@256 => 0001 0000 0000
	@	 => 0100 0000 => right 1 left 15 => 140 f40
	@	 => 0001 0000 => right 2 left 14 => 210 e10
	@	 => 0000 0100 => right 3 left 13 => 304 d04
	@	 => 0000 0001 => right 4 left 12 => 401 c01
	
	mov r2, #4000
	@efa 
	@1110 0001 1010 0000 0001 0000 0000 0010
	@e1a01002
	@e1a01002
	mov r1, r2
	@ 3E8 => 0011 1110 1000 => 1111 1010 => ffa
	@const  => left 最低位确保是有效的
	ldr	r0, .L2
	bl	printf
	@printf("val : %d\n", val);

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
