##FIXED INIT
    printintstr:	.asciz	"%d\n"
    printstringst:  .asciz "%s\n"
	.text

## TAC_BEGIN_FUN
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp

## TAC_PRINT
	movl	a(%rip), %esi
	leaq	printintstr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT

## TAC_ADD
	movl	c(%rip), %edx
	movl	b(%rip), %eax
	addl	%eax, %edx
	movl	%edx, a(%rip)

## TAC_SUB
	movl	c(%rip), %edx
	movl	b(%rip), %eax
	subl	%eax, %edx
	movl	%edx, a(%rip)

## TAC_MULT
	movl	a(%rip), %edx
	movl	c(%rip), %eax
	imull	%edx, %eax
	movl	%eax, a(%rip)

## TAC_DIV
	movl	a(%rip), %eax
	movl	c(%rip), %ecx
	cltd
	idivl	%ecx
	movl	%eax, a(%rip)

## TAC_LESS
	movl	a(%rip), %edx
	movl	c(%rip), %eax
	cmpl	%eax, %edx
	setl	%al
	movzbl	%al, %eax
	movl	%eax, a(%rip)

## TAC_BIG
	movl	a(%rip), %edx
	movl	c(%rip), %eax
	cmpl	%eax, %edx
	setg	%al
	movzbl	%al, %eax
	movl	%eax, a(%rip)

## TAC_END_FUN
	popq	%rbp
	ret


## JUMP TRUE
	movl	a(%rip), %eax
	testl	%eax, %eax
	je	.L2

## JUMP FALSE
	movl	a(%rip), %eax
	testl	%eax, %eax
	jne	.L2

.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 12.1.1 20220730"
	.section	.note.GNU-stack,"",@progbits

## DATA SECTION
	.section	.rodata

a:  .long	4

