section .text
	global _ft_strcpy
;char	*ft_strcpy(char *dst, char *src)
;rdi == dst, rsi == src

_ft_strcpy:
	mov		rax, 0					;rax = 0
	jmp		.copy					;.inc 건너뛰고 바로 .copy로

	.inc:
		inc		rax					;++rax

	.copy:
		mov		dl, BYTE[rsi + rax]	;dl = *(rsi + rax)
		mov		byte[rdi + rax], dl	;*(rdi + rax) = dl
		cmp		dl, 0				;dl과 0 비교(문자열이 끝났는지 확인)
		jne		.inc				;아니면 .inc로

	mov		rax, rdi				;rax = rdi(return값 설정)

	ret