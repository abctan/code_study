@led register address
#define GPJ2CON	0xE0200280
#define GPJ2DAT 0xE0200284


.global _start
_start:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4
	@保存环境

	@ config con as output mode
	ldr r0, =GPJ2CON
	ldr r1, [r0]
	ldr r2, =0xFFFF
	bic r1, r1, r2
	ldr r2, =0x1111
	orr r1, r1, r2
	str r1, [r0]

	LED:
	@ confif led on
	ldr r0, =GPJ2DAT
	ldr r1, [r0]
	ldr r2, =0xf
	bic r1, r2
	str r1, [r0]

	@delay
	ldr r4, =0xffffff
	loop:
		sub r4, #1
		cmp r4, #0
	bgt loop

	@config led off
	ldr r0, =GPJ2DAT
	ldr r1, [r0]
	ldr r2, =0xf
	orr r1, r2
	str r1, [r0]

	@delay
	ldr r4, =0xfffffff
	loop1:
		sub r4, #1
		cmp r4, #0
	bgt loop1
	b LED
	@恢复环境
	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr
