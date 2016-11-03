section .text
	extern _ft_isdigit
	extern _ft_isalpha
	global _ft_isalnum

_ft_isalnum:
	call	_ft_isdigit
	cmp		rax, 1
	je		true
	call	_ft_isalpha
	cmp		rax, 1
	je		true
	mov		rax, 0
	ret

true:
	mov		rax, 1
	ret
