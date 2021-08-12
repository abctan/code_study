
	@arm汇编代码 => .c => -S  定长指令集 
	@ 注释
	# 注释

	.file	"01_hello.c" @表示文件名 可有可无
	.section	.rodata	 @#表示只读段
	.align	2 @表示对齐方式 2^n => 4
.LC0: @表示标签 代表就是一个地址
	.ascii	"hello world!\n\000" @表示ascii码值
	@ \ 表示转义字符 第一个0 表示八进制 00 表示尾零
	.text @表示代码段
	.align	2 @表示代码段对齐 4个字节
	.global	func @表示全局func
	.type	func, %function @表示func是一个函数
func:@表示标签 地址
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr} @取指 译码 执行
	add	fp, sp, #4
	@保存环境变量
	
	@ r0 ~ r15
	@r0 ~ r12 : 普通寄存器
	@r13 ~ r15 : 特殊寄存器
	@r0 ~ r3 : 临时寄存器 用于函数传参 r0 表示第一个参数
	ldr	r0, .L2
	bl	puts @printf @bl调用
	
	@恢复环境变量
	ldmfd	sp!, {fp, pc}
.L3:
	.align	2 @表示对齐
.L2: @表示标签 内存
	.word	.LC0 @.word => 2 表示4个字节对齐

	.size	func, .-func @表示函数大小
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4

	bl	func
	@mov	r3, #0
	mov	r0, #0


	ldmfd	sp!, {fp, pc}
	.size	main, .-main
	.ident	"GCC: (ctng-1.8.1-FA) 4.5.1"
	.section	.note.GNU-stack,"",%progbits
