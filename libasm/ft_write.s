section .text
	global _ft_write
	extern ___error
;int	*___error(void) call 하면 rax에 errno를 가르키는 주소 저장
;man 2 write 보면 syscall 로 부른 wrtie 에서 알아서 errno 설정하고 -1 뱉는다는데...
;syscall 에 관해서는 아래 링크 참고
;https://opensource.apple.com/source/xnu/xnu-1504.3.12/bsd/kern/syscalls.master

_ft_write:
	mov		rax, 0x2000004		;syscall로 write 준비
	syscall						;
	jnc		.end				;return된 값 음수인지(에러가 났는지) 확인후 아니면 .end로

	push	rax					;rax에 저장된 errno값 스택에 저장 하면서 스택 8바이트로
	call	___error			;rax = &errno
	pop		rdx					;스택에 저장된 errno값 rdx로
	mov		DWORD [rax], edx	;*rax = edx (int형으로 크기 맞춰서 4바이트 복사)
	mov		rax, -1				;return 값 -1로 저장

	.end:
		ret