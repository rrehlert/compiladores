##FIXED INIT
printintstr:	.asciz	"%d\n"
printstringst:  .asciz "%s\n"

.text
## TAC_BEGIN_FUN
	.globl	_main
	.type	_main, @function
_main:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	_sPeRWeiRDfCk_Temp0(%rip), %esi
	leaq	printintstr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT
## TAC_END_FUN:
	popq	%rbp
	ret
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 12.1.1 20220730"
	.section	.note.GNU-stack,"",@progbits
## DATA SECTION
	.section	.rodata

_sPeRWeiRDfCk_Temp0:	.long	0
_sPeRWeiRDfCk_Temp1:	.long	0
