section .text
	global _ft_isascii

_ft_isascii:
	cmp		edi, 0
	jl		false
	cmp		edi, 127
	jg		false
	mov		rax, 1
	ret

false:
	mov		rax, 0
	ret
