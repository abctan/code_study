
#define PRI 0xc3e293b0

.global _start
_start:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4
	@保存环境
	
	ldr r1, =PRI
	ldr r0, =.STR
	mov lr, pc
	mov pc, r1

	@恢复环境
	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr

.STR:
	.string "this is uboot test ...\n"
	.align 2
