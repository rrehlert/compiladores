	.file	"test1.c"
	.text
	.comm	a,4,4
	.globl	b
	.data
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	1075419546
	.globl	c
	.align 4
	.type	c, @object
	.size	c, 4
c:
	.long	777
	.globl	d
	.align 16
	.type	d, @object
	.size	d, 16
d:
	.long	1
	.long	2
	.long	3
	.long	4
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	a(%rip), %eax
	testl	%eax, %eax
	jne	.L2
	movl	$3, a(%rip)
	jmp	.L3
.L2:
	movl	$4, a(%rip)
.L3:
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
