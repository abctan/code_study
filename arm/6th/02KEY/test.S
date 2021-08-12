@led register address
#define GPJ2CON	0xE0200280
#define GPJ2DAT 0xE0200284
@key register address
@k1 - k4
#define GPH2CON 0xE0200C40
#define GPH2DAT 0xE0200C44
@k5 - k8
#define GPH3CON 0xE0200C60
#define GPH3DAT 0xE0200C64

#define PRI 0xc3e293b0


.global _start
_start:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4
	@保存环境
	bl configure_led
	bl configure_key

	
	loop:
		bl led_off

		key_loop:
		ldr r4, =GPH2DAT
		ldr r1, [r4]
		bic r1, #0xf0
		cmp r1, #0xf
		beq key_loop

		bl led_on
		@ldr r2, =PRI
		@ldr r0, =.STR
		@mov lr, pc
		@mov pc, r2
		
		bl delay
	b loop
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
	delay_loop:
		sub r4, #1
		cmp r4, #0
	bgt delay_loop

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

@===============key===========

.global configure_key
configure_key:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4
	@保存环境

	ldr r0, =GPH2CON
	ldr r1, [r0]
	ldr r2, =0xffff
	bic r1, r2
	str r1, [r0]

	@恢复环境
	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr
