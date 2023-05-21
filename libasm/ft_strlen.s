section .text
	global _ft_strlen
;size_t	ft_strlen(const char *s)
;rdi == s;

_ft_strlen:
	mov		rax, rdi			;rax = rdi 주소값을 넣어준다.
	jmp		.count				;inc 건너뛰고 바로 .count부터

	.inc:
		inc		rax				;++rax

	.count:
		cmp		BYTE[rax], 0	;*rax와 0비교(문자열이 끝났는지 확인)
		jne		.inc			;아니면 .inc로

	.end:
		sub		rax, rdi		;rax -= rdi 주소값의 차이(문자열의 길이)만큼 설정됨
	
	ret