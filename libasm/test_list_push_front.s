	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_ft_list_push_front     ## -- Begin function ft_list_push_front
	.p2align	4, 0x90
_ft_list_push_front:                    ## @ft_list_push_front
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	jne	LBB0_2
## %bb.1:
	jmp	LBB0_5
LBB0_2:
	movl	$16, %edi
	callq	_malloc
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	LBB0_4
## %bb.3:
	jmp	LBB0_5
LBB0_4:
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, 8(%rcx)
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rcx
	movq	%rax, (%rcx)
LBB0_5:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
