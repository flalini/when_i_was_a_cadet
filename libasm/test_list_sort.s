	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_ft_list_sort           ## -- Begin function ft_list_sort
	.p2align	4, 0x90
_ft_list_sort:                          ## @ft_list_sort
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	je	LBB0_2
## %bb.1:
	movq	-8(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB0_3
LBB0_2:
	jmp	LBB0_14
LBB0_3:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
LBB0_4:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_9 Depth 2
	movq	-24(%rbp), %rax
	cmpq	$0, 8(%rax)
	je	LBB0_14
## %bb.5:                               ##   in Loop: Header=BB0_4 Depth=1
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	(%rcx), %rdi
	movq	-24(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	(%rcx), %rsi
	movq	%rax, -48(%rbp)         ## 8-byte Spill
	movb	$0, %al
	movq	-48(%rbp), %rcx         ## 8-byte Reload
	callq	*%rcx
	cmpl	$0, %eax
	jle	LBB0_13
## %bb.6:                               ##   in Loop: Header=BB0_4 Depth=1
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	(%rcx), %rdi
	movq	-32(%rbp), %rcx
	movq	(%rcx), %rsi
	movq	%rax, -56(%rbp)         ## 8-byte Spill
	movb	$0, %al
	movq	-56(%rbp), %rcx         ## 8-byte Reload
	callq	*%rcx
	cmpl	$0, %eax
	jle	LBB0_8
## %bb.7:                               ##   in Loop: Header=BB0_4 Depth=1
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	-32(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-32(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, (%rcx)
	jmp	LBB0_12
LBB0_8:                                 ##   in Loop: Header=BB0_4 Depth=1
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -40(%rbp)
LBB0_9:                                 ##   Parent Loop BB0_4 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-16(%rbp), %rax
	movq	-32(%rbp), %rcx
	movq	(%rcx), %rdi
	movq	-40(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	(%rcx), %rsi
	movq	%rax, -64(%rbp)         ## 8-byte Spill
	movb	$0, %al
	movq	-64(%rbp), %rcx         ## 8-byte Reload
	callq	*%rcx
	cmpl	$0, %eax
	jle	LBB0_11
## %bb.10:                              ##   in Loop: Header=BB0_9 Depth=2
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
	jmp	LBB0_9
LBB0_11:                                ##   in Loop: Header=BB0_4 Depth=1
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	-32(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-32(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	%rax, 8(%rcx)
LBB0_12:                                ##   in Loop: Header=BB0_4 Depth=1
	jmp	LBB0_13
LBB0_13:                                ##   in Loop: Header=BB0_4 Depth=1
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	jmp	LBB0_4
LBB0_14:
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
