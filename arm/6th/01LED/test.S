@led register address
#define GPJ2CON	0xE0200280
#define GPJ2DAT 0xE0200284

#define PRI 0xc3e293b0


.global _start
_start:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4
	@保存环境

	@ config con as output mode
	bl configure_led
	
	mov r5, #0
	LED:
		bl led_off

		ldr r0, =GPJ2DAT
		ldr r1, [r0]
		mov r2, #1
		lsl r2, r5
		mvn r3, r2
		
		@ldr r2, =PRI
		@mov r1, r3
		@ldr r0, =.STR
		@mov lr, pc
		@mov pc, r2

		and r1, r3
		str r1, [r0]

		add r5, #1
		cmp r5, #4
		moveq r5, #0

		bl delay
	b LED
	@恢复环境
	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr
@==============led===========

.global configure_led
configure_led:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4

	ldr r0, =GPJ2CON
	ldr r1, [r0]
	ldr r2, =0xFFFF
	bic r1, r1, r2
	ldr r2, =0x1111
	orr r1, r1, r2
	str r1, [r0]

	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr
.global led_on
led_on:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4

	ldr r0, =GPJ2DAT
	ldr r1, [r0]
	ldr r2, =0xf
	bic r1, r2
	str r1, [r0]

	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr

.global led_off
led_off:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4

	ldr r0, =GPJ2DAT
	ldr r1, [r0]
	ldr r2, =0xf
	orr r1, r2
	str r1, [r0]

	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr
.global delay
delay:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4

	ldr r4, =0x7ffffff
	loop:
		sub r4, #1
		cmp r4, #0
	bgt loop

	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr

.global print
print:
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
	.string "this is uboot test ...%#x\n"
	.align 2

