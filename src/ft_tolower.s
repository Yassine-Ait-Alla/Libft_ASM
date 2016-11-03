section .text
	extern _ft_isupper
	global _ft_tolower

_ft_tolower:
	call	_ft_isupper
	cmp		rax, 1
	je		set
	mov		rax, rdi
	ret

set:
	add		edi, 32
	mov		rax, rdi
	ret
