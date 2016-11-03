section .text
	extern _ft_strlen
	global _ft_strcpy

_ft_strcpy:
	push	rdi
	call	get_lenght
	pop		rdi
	mov		rax, rdi
	mov		rcx, r9
	cld
	rep 	movsb
	ret

get_lenght:
	mov		rdi, rsi
	call	_ft_strlen
	mov		r9, rax
	inc		r9
	ret

