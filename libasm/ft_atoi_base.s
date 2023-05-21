section .text
	global _ft_atoi_base
;int	ft_atoi_base(char *str, char *base)
;rdi == str, rsi == base

_ft_atoi_base:
	mov		rax, rsi				;rax = rsi (rax = base)
	jmp		.checkerrorbase			;

	.incbase:
		inc		rax					;
	.checkerrorbase:
		mov		dl, BYTE[rax]		;
		cmp		dl, 0				;base 끝났는지 확인
		je		.checklen			;
		cmp		dl, 0x09			;'\t' 확인
		jb		.checkdup			;dl < '\t' 일 경우 .checkdup으로
		cmp		dl, 0x0D			;'\r' 확인
		jbe		.errorbase			;dl <= '\r' 일 경우 .errorbase로
		cmp		dl, 0x2b			;'+' 확인
		je		.errorbase			;같으면 .errorbase로
		cmp		dl, 0x2d			;'-' 확인
		je		.errorbase			;같으면 .errorbase로
		cmp		dl, 0x20			;' ' 확인
		je		.errorbase			;같으면 .errorbase로

	.checkdup:
		mov		rcx, rax			;
	.checkduploop:
		inc		rcx					;
		mov		dh, BYTE[rcx]		;
		cmp		dh, 0				;
		je		.incbase			;
		cmp		dh, dl				;
		je		.errorbase			;
		jmp		.checkduploop		;

	.checklen:
		sub		rax, rsi			;
		cmp		rax, 1				;
		ja		.setstr				;

	.errorbase:
		mov		rax, 0				;
		ret
;base 확인 끝

	.setstr:
		push	rax					;base 길이 스택으로
		mov		rax, rdi			;
		mov		rdx, 0				;
		jmp		.checkspace			;

	.skipspace:
		inc		rax					;
	.checkspace:
		mov		cl, BYTE[rax]		;
		cmp		cl, 0x09			;
		jb		.startatoi			;
		cmp		cl, 0x0D			;
		jbe		.skipspace			;
		cmp		cl, 0x20			;
		je		.skipspace			;
		jmp		.checksign			;

	.skipsign:
		inc		rax					;
	.checksign:
		mov		cl, BYTE[rax]		;
		cmp		cl, 0x2b			;
		je		.skipsign			;
		cmp		cl, 0x2d			;
		jne		.startatoi			;
		inc		rdx					;
		jmp		.skipsign			;


	.startatoi:						;
		pop		rcx					;스택에 저장된 base 길이 rcx로
		push	rdx					;스택에 rdx(음수 확인용) 저장
		mov		rdx, rdi			;
		push	rdx					;스택에 rdi(str 포인터) 저장
		push	rbx					;rbx 보존
;The general register EBX, ESI, EDI, EBP, DS, ES, and SS,
;must be preserved by the called function.
;If you use them, you must save them first and restore them afterwards.
;https://wiki.osdev.org/Calling_Conventions 의 Registers 에서
;64bit 에서는 RBX, RSI, RDI, RBP 등을 save 했다가 쓰고 돌려놓으면 되지 않을까?
;현재 스택 상황 (음수 계산용 8바이트 정보)(rdi의 원래 포인터)(원래 rbx)
		mov		rdi, rax			;rdi에 atoi 시작 위치 설정
		mov		rax, 0				;
;현재 레지스터 상황 rax == 0, rcx == base len, rdi == str의 atoi 시작위치, rsi == base
		jmp		.calloop

	.calloop:
		mov		dl, BYTE[rdi]		;
		cmp		dl, 0				;
		je		.endatoi			;
		mov		rbx, 0				;
		jmp		.cmpbase			;

	.nextbase:
		inc		rbx					;
		cmp		rbx, rcx			;rbx와 rcx(base len)비교
		je		.endatoi			;같으면(문자열이 끝났으면, base에서 못찾았으면) .endatoi로
	.cmpbase:
		cmp		dl, BYTE[rsi + rbx]	;
		jne		.nextbase			;

	.calbase:
		mul		ecx					;eax *= base 상위 32비트는 edx로
		add		rax, rbx			;rax += rbx
		inc		rdi					;++rdi
		jmp		.calloop			;

	.endatoi:
		pop		rbx					;스택에서 꺼내서 rbx 원래대로
		pop		rdi					;스택에서 꺼내서 rdi 원래대로
		pop		rdx					;rdx로 음수 계산 준비
		and		rdx, 1				;rdx & 1 홀수인지(음수인지) 확인
		jz		.end				;결과가 0이면(짝수면, 양수면) .end로
		mov		rcx, -1				;음수로 만들 준비
		imul	rcx					;rax *= rcx(-1) 상위 64비트는 rdx로
	.end:
		ret