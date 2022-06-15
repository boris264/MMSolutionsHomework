	.file	"car.c"
	.text
	.globl	sortByModelASC
	.type	sortByModelASC, @function
sortByModelASC:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	sortByModelASC, .-sortByModelASC
	.globl	sortByModelDESC
	.type	sortByModelDESC, @function
sortByModelDESC:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	sortByModelDESC, .-sortByModelDESC
	.globl	sortBySpeedASC
	.type	sortBySpeedASC, @function
sortBySpeedASC:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movzwl	20(%rax), %eax
	movzwl	%ax, %edx
	movq	-8(%rbp), %rax
	movzwl	20(%rax), %eax
	movzwl	%ax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	sortBySpeedASC, .-sortBySpeedASC
	.globl	sortBySpeedDESC
	.type	sortBySpeedDESC, @function
sortBySpeedDESC:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movzwl	20(%rax), %eax
	movzwl	%ax, %edx
	movq	-16(%rbp), %rax
	movzwl	20(%rax), %eax
	movzwl	%ax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	sortBySpeedDESC, .-sortBySpeedDESC
	.globl	sortByPriceASC
	.type	sortByPriceASC, @function
sortByPriceASC:
.LFB4:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movsd	24(%rax), %xmm0
	movq	-8(%rbp), %rax
	movsd	24(%rax), %xmm2
	movapd	%xmm0, %xmm1
	subsd	%xmm2, %xmm1
	movsd	.LC0(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L14
	movl	$0, %eax
	jmp	.L12
.L14:
	movl	$1, %eax
.L12:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	sortByPriceASC, .-sortByPriceASC
	.globl	sortByPriceDESC
	.type	sortByPriceDESC, @function
sortByPriceDESC:
.LFB5:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movsd	24(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	24(%rax), %xmm2
	movapd	%xmm0, %xmm1
	subsd	%xmm2, %xmm1
	movsd	.LC0(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L20
	movl	$0, %eax
	jmp	.L18
.L20:
	movl	$1, %eax
.L18:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	sortByPriceDESC, .-sortByPriceDESC
	.section	.rodata
	.align 8
.LC1:
	.string	"Function with index %d not found!\n"
	.text
	.globl	getComparator
	.type	getComparator, @function
getComparator:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -68(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	sortByModelASC(%rip), %rax
	movq	%rax, -64(%rbp)
	leaq	sortByModelDESC(%rip), %rax
	movq	%rax, -56(%rbp)
	leaq	sortBySpeedASC(%rip), %rax
	movq	%rax, -48(%rbp)
	leaq	sortBySpeedDESC(%rip), %rax
	movq	%rax, -40(%rbp)
	leaq	sortByPriceASC(%rip), %rax
	movq	%rax, -32(%rbp)
	leaq	sortByPriceDESC(%rip), %rax
	movq	%rax, -24(%rbp)
	cmpl	$0, -68(%rbp)
	jle	.L22
	cmpl	$6, -68(%rbp)
	jg	.L22
	movl	-68(%rbp), %eax
	subl	$1, %eax
	cltq
	movq	-64(%rbp,%rax,8), %rax
	jmp	.L24
.L22:
	movq	stderr(%rip), %rax
	movl	-68(%rbp), %edx
	leaq	.LC1(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$0, %eax
.L24:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L25
	call	__stack_chk_fail@PLT
.L25:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	getComparator, .-getComparator
	.section	.rodata
	.align 8
.LC0:
	.long	-755914244
	.long	1062232653
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
