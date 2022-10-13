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
	movl	_a(%rip), %esi
	leaq	printintstr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT
## TAC_ASSIGN
	movl	_3(%rip), %eax
	movl	%eax, _b(%rip)
## TAC_PRINT
	movl	_b(%rip), %esi
	leaq	printintstr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT
## TAC_LABEL
.sPeRWeiRDfCk_Label1:
## TAC_LESS
	movl	_a(%rip), %edx
	movl	_b(%rip), %eax
	cmpl	%eax,%edx
	setl	%al
	movzbl	%al,%eax
	movl	%eax, _sPeRWeiRDfCk_Temp0(%rip)
## TAC_JFALSE
	movl	_sPeRWeiRDfCk_Temp0(%rip), %eax
	testl	%eax, %eax
	je	.sPeRWeiRDfCk_Label0
## TAC_ADD
	movl	_a(%rip), %edx
	movl	_1(%rip), %eax
	addl	%edx, %eax
	movl	%eax, _sPeRWeiRDfCk_Temp1(%rip)
## TAC_ASSIGN
	movl	_sPeRWeiRDfCk_Temp1(%rip), %eax
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
## TAC_BIG
	movl	_2(%rip), %edx
	movl	_3(%rip), %eax
	cmpl	%eax,%edx
	setg	%al
	movzbl	%al,%eax
	movl	%eax, _sPeRWeiRDfCk_Temp2(%rip)
## TAC_JFALSE
	movl	_sPeRWeiRDfCk_Temp2(%rip), %eax
	testl	%eax, %eax
	je	.sPeRWeiRDfCk_Label2
## TAC_ASSIGN
	movl	_5(%rip), %eax
	movl	%eax, _a(%rip)
## TAC_PRINT
	movl	_a(%rip), %esi
	leaq	printintstr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT
## TAC_JMP
	jmp	.sPeRWeiRDfCk_Label3
## TAC_LABEL
.sPeRWeiRDfCk_Label2:
## TAC_ASSIGN
	movl	_7(%rip), %eax
	movl	%eax, _b(%rip)
## TAC_PRINT
	movl	_b(%rip), %esi
	leaq	printintstr(%rip), %rax
	movq	%rax, %rdi
	call	printf@PLT
## TAC_LABEL
.sPeRWeiRDfCk_Label3:
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
_1:	.long	1
_2:	.long	2
_3:	.long	3
_5:	.long	5
_7:	.long	7
_sPeRWeiRDfCk_Label2:	.long	0
_a:	.long	2
_b:	.long	777
_c:	.long	111
_sPeRWeiRDfCk_Temp2:	.long	0
_sPeRWeiRDfCk_Label3:	.long	0
_111:	.long	111
_sPeRWeiRDfCk_Label0:	.long	0
_sPeRWeiRDfCk_Temp0:	.long	0
_sPeRWeiRDfCk_Label1:	.long	0
_777:	.long	777
_sPeRWeiRDfCk_Temp1:	.long	0
