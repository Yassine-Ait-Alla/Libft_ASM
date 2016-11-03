section .text
	extern _ft_islower
	extern _ft_isupper
	global _ft_isalpha

_ft_isalpha:
	call	_ft_isupper
	cmp		rax, 1
	je		true
	call	_ft_islower
	cmp		rax, 1
	je		true
	mov		rax, 0
	ret

true:
	mov		rax, 1
	ret
