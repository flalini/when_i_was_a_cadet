section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
;char	*ft_strdup(const char *s1)
;rdi == s1

_ft_strdup:
	push	rbx				;스택 8바이트로
	push	rsi				;rsi 스택에 저장
	push	rdi				;rdi 스택에 저장
;현재 스택 24바이트 call로 돌아올 주소 더하면 32바이트로 16바이트로 정렬됨
	call	_ft_strlen		;rax = _ft_strlen(rdi) (rdi == s1)
	inc		rax				;++rax
	mov		rdi, rax		;rdi = rax
	call	_malloc			;rax = _malloc(rdi) (rdi == _ft_strlen(s1) + 1)
	cmp		rax, 0			;malloc 실패했는지(NULL을 반환했는지) 확인
	je		.restore		;맞으면 .restore로

	pop		rsi				;rsi = s1
	push	rsi				;s1 스택에 저장
	mov		rdi, rax		;rdi = rax (rax == malloc 된 주소)
	call	_ft_strcpy		;rax = _ft_strcpy(rdi, rsi) (copy 되고 rax = rdi)

	.restore:				;스택과 바뀐 값들 정리
		pop		rdi			;
		pop		rsi			;
		pop		rbx			;
	
	ret
