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
## TAC_SUB
	movl	$5, %edx
	movl	$2, %eax
	subl	%eax, %edx
	movl	%edx, _sPeRWeiRDfCk_Temp0(%rip)
## TAC_ASSIGN
	movl	_sPeRWeiRDfCk_Temp0(%rip), %eax
	movl	%eax, _a(%rip)

	## TAC_PRINT
	movl	_a(%rip), %esi
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

	.data
_a:	.long	0
_b:	.long	0
_c:	.long	0
_sPeRWeiRDfCk_Temp0:	.long	0
