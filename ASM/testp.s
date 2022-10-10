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

## TAC_END_FUN
	popq	%rbp
	ret


.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 12.1.1 20220730"
	.section	.note.GNU-stack,"",@progbits

## DATA SECTION
	.section	.rodata

a:  .long	4

