section .text
	global _ft_list_sort
;typedef struct		s_list
;{
;	void 			*data;
;	struct s_list	*next;
;}					t_list;
;void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
;rdi == begin_list, rsi == cmp

;스택 메모리 맵
;type		|name			|size		|from	|to		|prt		|
;===========|===============|===========|=======|=======|===========|
;t_list **	|begin_list		|8byte		|0		|8		|rbp - 8	|1
;int (*)()	|cmp			|8byte		|8		|16		|rbp - 16	|2
;t_list *	|tmp			|8byte		|16		|24		|rbp - 24	|3
;t_list *	|tmp2			|8byte		|24		|32		|rbp - 32	|4
;t_list *	|find			|8byte		|32		|40		|rbp - 40	|5

_ft_list_sort:
	cmp		rdi, 0						;
	je		.end						;
	cmp		QWORD[rdi], 0				;
	je		.end						;

	push	rbp							;rbp 저장
	mov		rbp, rsp					;rbp는 이제부터 메모리 접근용
	sub		rsp, 48						;메모리 48바이트 할당
	mov		QWORD[rbp - 8], rdi			;1 저장
	mov		QWORD[rbp - 16], rsi		;2 저장
	mov		rax, QWORD[rdi]				;rax = *begin_list
	mov		QWORD[rbp - 24], rax		;tmp = rax (*begin_list)
	jmp		.loop_d1

	.loop_d1_inc:
		mov		rax, QWORD[rbp - 24]		;
		mov		rax, QWORD[rax + 8]			;
		mov		QWORD[rbp - 24], rax		;
	.loop_d1:
		cmp		QWORD[rax + 8], 0			;cmp tmp->next, 0
		je		.restore					;뒤에 더 없으면 while문 탈출
		mov		rdi, QWORD[rax]				;rdi = tmp->data
		mov		rax, QWORD[rax + 8]			;rax = tmp->next
		mov		rsi, QWORD[rax]				;rsi = tmp->next->data
		mov		rcx, QWORD[rbp - 16]		;rcx = cmp
		call	rcx							;eax = (*cmp)(tmp->data, tmp->next->data)
		cmp		eax, 0						;eax 값이 0
		jle		.loop_d1_inc				; 이하이면 continue

		mov		rax, QWORD[rbp - 24]		;rax = tmp
		mov		rcx, QWORD[rax + 8]			;rcx = tmp->next
		mov		QWORD[rbp - 32], rcx		;tmp2 = tmp->next
		mov		rdx, QWORD[rcx + 8] 		;rdx = tmp->next->next
		mov		QWORD[rax + 8], rdx			;tmp->next = tmp->next->next
		mov		rax, QWORD[rbp - 8]			;rax = begin_list
		mov		rax, QWORD[rax]				;rax = *begin_list
		mov		rdi, QWORD[rax]				;rdi = (*begin_list)->data
		mov		rsi, QWORD[rcx]				;rsi = tmp2->data
		mov		rcx, QWORD[rbp - 16]		;rcx = cmp
		call	rcx							;eax = (*cmp)((*begin_list)->data, tmp2->data)
		mov		rcx, QWORD[rbp - 8]			;rcx = begin_list
		mov		rdx, QWORD[rcx]				;rdx = *begin_list
		cmp		eax, 0						;eax 값이 0
		jle		.else_loop					; 이하이면 .else로

		mov		rax, QWORD[rbp - 32]		;rax = tmp2
		mov		QWORD[rax + 8], rdx			;tmp2->next = *begin_list
		mov		QWORD[rcx], rax				;*begin_list = tmp2
		mov		rax, QWORD[rbp - 24]		;rax = tmp
		jmp		.loop_d1					;continue

	.else_loop_inc:
		mov		rax, QWORD[rbp - 40]		;rax = find
		mov		rdx, QWORD[rax + 8]			;rdx = find->next
	.else_loop:
		mov		QWORD[rbp - 40], rdx		;find = *begin_list || find = find->next
		mov		rax, QWORD[rbp - 32]		;rax = tmp2
		mov		rdi, QWORD[rax]				;rdi = tmp2->data
		mov		rax, QWORD[rdx + 8]			;rax = find->next
		mov		rsi, QWORD[rax]				;rsi = find->next->data
		mov		rcx, QWORD[rbp - 16]		;rcx = cmp
		call	rcx							;eax = (*cmp)(tmp2->data, find->next->data)
		cmp		eax, 0						;eax 값이 0
		jg		.else_loop_inc				; 초과이면 .else_loop_inc로

		mov		rax, QWORD[rbp - 40]		;rax = find
		mov		rcx, QWORD[rax + 8]			;rcx = find->next
		mov		rdx, QWORD[rbp - 32]		;rdx = tmp2
		mov		QWORD[rdx + 8], rcx			;tmp2->next = find->next
		mov		QWORD[rax + 8], rdx			;find->next = tmp2;
		mov		rax, QWORD[rbp - 24]		;rax = tmp
		jmp		.loop_d1					;continue

	.restore:							;메모리와 rdi, rsi, rsp, rbp 정리
		mov		rdi, QWORD[rbp - 8]		;
		mov		rsi, QWORD[rbp - 16]	;
		add		rsp, 48					;
		pop		rbp						;

	.end:
		ret
