	.file	"main.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Enter an option to sort the array: \n1)By model ascending\n2)By model descending\n3)By speed ascending\n4)By speed descending\n5)By price ascending\n6)By price descending"
.LC1:
	.string	"%d"
	.align 8
.LC4:
	.string	"Model: %s\nMax speed: %d\nPrice: %lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$352, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	-348(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$0, -344(%rbp)
	jmp	.L2
.L3:
	leaq	-336(%rbp), %rdx
	movl	-344(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rdx, %rax
	movq	%rax, %rdi
	call	randomName
	movl	$300, %esi
	movl	$100, %edi
	call	randint
	movl	%eax, %edx
	movl	-344(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$316, %rax
	movw	%dx, (%rax)
	movsd	.LC2(%rip), %xmm0
	movq	.LC3(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	randReal
	movq	%xmm0, %rax
	movl	-344(%rbp), %edx
	movslq	%edx, %rdx
	salq	$5, %rdx
	addq	%rbp, %rdx
	subq	$312, %rdx
	movq	%rax, (%rdx)
	addl	$1, -344(%rbp)
.L2:
	cmpl	$9, -344(%rbp)
	jle	.L3
	movl	-348(%rbp), %eax
	movl	%eax, %edi
	call	getComparator@PLT
	movq	%rax, %rdx
	leaq	-336(%rbp), %rax
	movq	%rdx, %rcx
	movl	$32, %edx
	movl	$10, %esi
	movq	%rax, %rdi
	call	qsort@PLT
	movl	$0, -340(%rbp)
	jmp	.L4
.L5:
	movl	-340(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$312, %rax
	movq	(%rax), %rdx
	movl	-340(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$316, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	leaq	-336(%rbp), %rsi
	movl	-340(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$5, %rcx
	addq	%rsi, %rcx
	movq	%rdx, %xmm0
	movl	%eax, %edx
	movq	%rcx, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -340(%rbp)
.L4:
	cmpl	$9, -340(%rbp)
	jle	.L5
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.globl	randint
	.type	randint, @function
randint:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	call	rand@PLT
	movl	-8(%rbp), %edx
	subl	-4(%rbp), %edx
	leal	1(%rdx), %ecx
	cltd
	idivl	%ecx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	randint, .-randint
	.globl	randReal
	.type	randReal, @function
randReal:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movsd	%xmm0, -8(%rbp)
	movsd	%xmm1, -16(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC5(%rip), %xmm2
	movapd	%xmm0, %xmm1
	divsd	%xmm2, %xmm1
	movsd	-16(%rbp), %xmm0
	subsd	-8(%rbp), %xmm0
	mulsd	%xmm1, %xmm0
	addsd	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	randReal, .-randReal
	.globl	randomName
	.type	randomName, @function
randomName:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -12(%rbp)
	movl	$90, %esi
	movl	$65, %edi
	call	randint
	movl	%eax, %ecx
	movl	-12(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -12(%rbp)
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	movl	$10, %esi
	movl	$4, %edi
	call	randint
	movl	%eax, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L13
.L14:
	movl	$122, %esi
	movl	$97, %edi
	call	randint
	movl	%eax, %ecx
	movl	-12(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -12(%rbp)
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	%ecx, %edx
	movb	%dl, (%rax)
	addl	$1, -8(%rbp)
.L13:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jl	.L14
	movl	-12(%rbp), %edx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movq	-24(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	randomName, .-randomName
	.section	.rodata
	.align 8
.LC2:
	.long	0
	.long	1090021888
	.align 8
.LC3:
	.long	0
	.long	1083129856
	.align 8
.LC5:
	.long	-4194304
	.long	1105199103
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
