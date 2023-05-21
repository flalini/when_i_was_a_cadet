section .text
	global _ft_list_push_front
	extern _malloc
;typedef struct		s_list
;{
;	void 			*data;
;	struct s_list	*next;
;}					t_list;
;void	ft_list_push_front(t_list **begin_list, void *data)
;rdi == begin_list, rsi == data

_ft_list_push_front:
	cmp		rdi, 0				;NULL check
	je		.end				;
	push	rdi					;rdi 저장하면서 스택 8바이트로
	push	rsi					;
	push	rsi					;
	mov		rdi, 16				;
	call	_malloc				;rax = _malloc(16)
	pop		rsi					;
	pop		rsi					;
	pop		rdi					;
	cmp		rax, 0				;malloc NULL check
	je		.end				;
	mov		QWORD[rax], rsi		;rax->data = rsi (rax->data = data)
	mov		rdx, QWORD[rdi]		;rdx = *rdi (rdx = *begin_list)
	mov		QWORD[rax + 8], rdx	;rax->next = rdx (rax->next = *begin_list)
	mov		QWORD[rdi], rax		;*rdi = rax (*begin_list = rax)

	.end:
		ret
