@led register address
#define GPJ2CON	0xE0200280
#define GPJ2DAT 0xE0200284

@buzzer register address
#define GPD0CON 0xE02000A0
#define GPD0DAT 0xE02000A4


.global _start
_start:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4
	@保存环境

	@ config con as output mode
	bl configure_led
	bl configure_buzzer

	LED:
		bl led_on
		bl buzzer_on

		bl delay
		bl led_off
		bl buzzer_off

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

@===============buzzer====
.global configure_buzzer
configure_buzzer:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4
	
	ldr r0, =GPD0CON
	ldr r1, [r0]
	bic r1, r1, #0xf
	orr r1, r1, #0x1
	str r1, [r0]

	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr

.global buzzer_on
buzzer_on:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4
	
	ldr r0, =GPD0DAT
	ldr r1, [r0]
	orr r1, r1, #1
	str r1, [r0]

	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr

.global buzzer_off
buzzer_off:
	mov ip, sp
	stmfd sp!, {fp, ip, lr, pc}
	sub fp, ip, #4
	
	ldr r0, =GPD0DAT
	ldr r1, [r0]
	bic r1, r1, #1
	str r1, [r0]
	sub sp, fp, #12
	ldmfd sp, {fp, sp, lr}
	bx lr
