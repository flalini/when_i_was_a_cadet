	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_ft_list_remove_if      ## -- Begin function ft_list_remove_if
	.p2align	4, 0x90
_ft_list_remove_if:                     ## @ft_list_remove_if
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
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	cmpq	$0, -8(%rbp)
	je	LBB0_2
## %bb.1:
	movq	-8(%rbp), %rax
	cmpq	$0, (%rax)
	jne	LBB0_3
LBB0_2:
	jmp	LBB0_13
LBB0_3:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -40(%rbp)
LBB0_4:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_6 Depth 2
	cmpq	$0, -40(%rbp)
	je	LBB0_11
## %bb.5:                               ##   in Loop: Header=BB0_4 Depth=1
	jmp	LBB0_6
LBB0_6:                                 ##   Parent Loop BB0_4 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	movq	-40(%rbp), %rcx
	cmpq	$0, 8(%rcx)
	movb	%al, -49(%rbp)          ## 1-byte Spill
	je	LBB0_8
## %bb.7:                               ##   in Loop: Header=BB0_6 Depth=2
	movq	-24(%rbp), %rax
	movq	-40(%rbp), %rcx
	movq	8(%rcx), %rcx
	movq	(%rcx), %rdi
	movq	-16(%rbp), %rsi
	callq	*%rax
	cmpl	$0, %eax
	sete	%dl
	movb	%dl, -49(%rbp)          ## 1-byte Spill
LBB0_8:                                 ##   in Loop: Header=BB0_6 Depth=2
	movb	-49(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB0_9
	jmp	LBB0_10
LBB0_9:                                 ##   in Loop: Header=BB0_6 Depth=2
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	8(%rax), %rax
	movq	-40(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-32(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	(%rcx), %rdi
	callq	*%rax
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	callq	_free
	jmp	LBB0_6
LBB0_10:                                ##   in Loop: Header=BB0_4 Depth=1
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
	jmp	LBB0_4
LBB0_11:
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	(%rcx), %rcx
	movq	(%rcx), %rdi
	movq	-16(%rbp), %rsi
	callq	*%rax
	cmpl	$0, %eax
	jne	LBB0_13
## %bb.12:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	8(%rax), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-32(%rbp), %rax
	movq	-48(%rbp), %rcx
	movq	(%rcx), %rdi
	callq	*%rax
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	callq	_free
LBB0_13:
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
