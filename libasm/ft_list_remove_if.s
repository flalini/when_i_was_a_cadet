section .text
	global _ft_list_remove_if
	extern _free
;typedef struct		s_list
;{
;	void 			*data;
;	struct s_list	*next;
;}					t_list;
;void	ft_list_sort(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *))
;rdi == begin_list, rsi == dara_ref, rdx == cmp, rcx == free_fct

;스택 메모리 맵
;type				|name			|size		|from	|to		|prt		|
;===================|===============|===========|=======|=======|===========|
;t_list **			|begin_list		|8byte		|0		|8		|rbp - 8	|1
;void *				|data_ref		|8byte		|8		|16		|rbp - 16	|3
;int (*)()			|cmp			|8byte		|16		|24		|rbp - 24	|3
;void (*)()			|free_fct		|8byte		|24		|32		|rbp - 32	|4
;t_list *			|current		|8byte		|32		|40		|rbp - 40	|5
;t_list *, void *	|tmp, remove	|8byte		|40		|48		|rbp - 48	|6

_ft_list_remove_if:
	cmp		rdi, 0						;
	je		.end						;
	mov		rax, rdi					;
	cmp		QWORD[rax], 0				;
	je		.end						;

	push	rbp							;rbp 저장
	mov		rbp, rsp					;rbp는 이제부터 메모리 접근용
	sub		rsp, 64						;메모리 64바이트 할당
	mov		QWORD[rbp - 8], rdi			;1 저장
	mov		QWORD[rbp - 16], rsi		;2 저장
	mov		QWORD[rbp - 24], rdx		;3 저장
	mov		QWORD[rbp - 32], rcx		;4 저장
	mov		rcx, QWORD[rbp - 8]			;rcx = begin_list
	mov		rcx, QWORD[rcx]				;rcx = *begin_list
	mov		QWORD[rbp - 40], rcx		;current = *begin_list

	.loop_D1_con:						;loop Depth=1
		cmp		rcx, 0					;0과 current 비교
		je		.loop_D1_end			;같으면(조건 불만족) while(D1) 끝

	.loop_D2_con:						;loop Depth=2
		mov		rcx, QWORD[rcx + 8]		;rcx = current->next
		cmp		rcx, 0					;0과 current->next 비교
		je		.loop_D2_end			;같으면(조건 불만족) while(D2) 끝
		mov		rdi, QWORD[rcx]			;rdi = current->next->data
		mov		rsi, QWORD[rbp - 16]	;rsi = data_ref
		mov		rax, QWORD[rbp - 24]	;rax = cmp
		call	rax						;eax = (*cmp)(current->next->data, data_ref)
		cmp		eax, 0					;결과를 0과 비교
		jne		.loop_D2_end			;같지 않으면(조건 불만족) while(D2) 끝
;D2_con_end
		mov		rcx, QWORD[rbp - 40]	;rcx = current
		mov		rdx, QWORD[rcx + 8]		;rdx = current->next 여기서부터 current->next를 임시로 tmp
		mov		rax, QWORD[rdx + 8]		;rax = tmp->next
		mov		QWORD[rcx + 8], rax		;current->next = tmp->next
		mov		rdi, rdx				;rdi = tmp
		mov		rdx, QWORD[rdx]			;rdx = tmp->data
		mov		QWORD[rbp - 48], rdx	;remove = tmp->data
		call	_free					;free(tmp)

		mov		rdi, QWORD[rbp - 48]	;rdi = remove (tmp->data)
		mov		rax, QWORD[rbp - 32]	;rax = free_fct
		call	rax						;(*free_fct)(tmp->data)
		mov		rcx, QWORD[rbp - 40]	;while(D2) 사전준비 rcx = current
		jmp		.loop_D2_con			;while(D2) 다시

	.loop_D2_end:
		mov		rcx, QWORD[rbp - 40]	;rcx = current
		mov		rcx, QWORD[rcx + 8]		;rcx = current->next
		mov		QWORD[rbp - 40], rcx	;current = current->next
		jmp		.loop_D1_con			;while(D1) 다시

	.loop_D1_end:
		mov		rdx, QWORD[rbp - 8]		;rdx = begin_list
		mov		rdx, QWORD[rdx]			;rdx = *begin_list
		mov		rdi, QWORD[rdx]			;rdi = (*begin_list)->data
		mov		rsi, QWORD[rbp - 16]	;rsi = data_ref
		mov		rax, QWORD[rbp - 24]	;rax = cmp
		call	rax						;eax = (*cmp)((*begin_list)->data, data_ref)
		cmp		eax, 0					;결과를 0과 비교
		jne		.restore				;아니면(조건 불만족) 건너뛰기

		mov		rdx, QWORD[rbp - 8]		;rdx = begin_list
		mov		rcx, QWORD[rdx]			;rcx = *begin_list
		mov		QWORD[rbp - 48], rcx	;tmp = *begin_list
		mov		rax, QWORD[rcx + 8]		;rax = tmp->next
		mov		QWORD[rdx], rax			;*begin_list = tmp->next
		mov		rdi, QWORD[rcx]			;rdi = tmp->data
		mov		rax, QWORD[rbp - 32]	;rax = free_fct
		call	rax						;(*free_fct)(tmp->data)
		mov		rdi, QWORD[rbp - 48]	;rdi = tmp
		call	_free					;free(tmp);

	.restore:							;메모리와 rdi, rsi, rsp, rbp 정리
		mov		rdi, QWORD[rbp - 8]		;
		mov		rsi, QWORD[rbp - 16]	;
		add		rsp, 64					;
		pop		rbp						;

	.end:
		ret
