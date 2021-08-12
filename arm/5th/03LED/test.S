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
	bl configure_led
	
	LED:
		bl led_on
		bl delay
		bl led_off
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

	ldr r4, =0xffffff
	loop:
		sub r4, #1
		cmp r4, #0
	bgt loop

	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr
