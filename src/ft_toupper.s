section .text
	extern _ft_islower
	global _ft_toupper

_ft_toupper:
	call	_ft_islower
	cmp		rax, 1
	je		set
	mov		rax, rdi
	ret

set:
	sub		edi, 32
	mov		rax, rdi
	ret
