section .text
	global _ft_list_size
	extern _malloc
;typedef struct		s_list
;{
;	void 			*data;
;	struct s_list	*next;
;}					t_list;
;int	ft_list_size(t_list *begin_list)
;rdi == begin_list

_ft_list_size:
	mov		rax, 0					;
	cmp		rdi, 0					;
	je		.end					;
	mov		rdx, rdi				;rdx = rdi

	.count:
		mov		rdx, QWORD[rdx + 8]	;rdx = rdx->next
		inc		rax					;
		cmp		rdx, 0				;
		jne		.count				;

	.end:
		ret