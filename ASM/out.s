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
## TAC_BIG
	movl	_a(%rip), %edx
	movl	_b(%rip), %eax
	cmpl	%eax,%edx
	setg	%al
	movzbl	%al,%eax
	movl	%eax, _sPeRWeiRDfCk_Temp0(%rip)
## TAC_JFALSE
	movl	_sPeRWeiRDfCk_Temp0(%rip), %eax
	testl	%eax, %eax
	je	.sPeRWeiRDfCk_Label0
## TAC_ASSIGN
	movl	_5(%rip), %eax
	movl	%eax, _a(%rip)
## TAC_PRINT
	movl	_a(%rip), %esi
	leaq	printintstr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT
## TAC_JMP
	jmp	.sPeRWeiRDfCk_Label1
## TAC_LABEL
.sPeRWeiRDfCk_Label0:
## TAC_ASSIGN
	movl	_7(%rip), %eax
	movl	%eax, _b(%rip)
## TAC_PRINT
	movl	_b(%rip), %esi
	leaq	printintstr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT
## TAC_LABEL
.sPeRWeiRDfCk_Label1:
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
_2:	.long	2
_5:	.long	5
_7:	.long	7
_a:	.long	2
_b:	.long	777
_c:	.long	111
_111:	.long	111
_sPeRWeiRDfCk_Label0:	.long	0
_sPeRWeiRDfCk_Temp0:	.long	0
_sPeRWeiRDfCk_Label1:	.long	0
_777:	.long	777
