section .text
	global _ft_strcmp
;int	ft_strcmp(char *s1, char *s2)
;rdi == s1, rsi == s2

_ft_strcmp:
	mov		rax, 0					;rax = 0
	mov		rdx, 0					;
	mov		rcx, 0					;
	jmp		.loop					;.inc 건너뛰고 바로 .loop로

	.inc:
		inc		rdx					;++rdx

	.loop:
		mov		al, BYTE[rdi + rdx]	;al = *(rdi + rdx)
		cmp		al, 0				;al과 0 비교(문자열이 끝났는지 확인)
		je		.end				;같으면(끝났으면) .end로
		cmp		al, BYTE[rsi + rdx]	;al과 *(rsi + rdx) 비교
		je		.inc				;같으면(더 비교해야되면) .inc로

	.end:
		mov		cl, BYTE[rsi + rdx]	;cl = *(rsi + rdx)
		sub		rax, rcx			;rax -= rcx

	ret