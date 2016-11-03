section .text
	global _ft_isprint

_ft_isprint:
	cmp		edi, 32
	jl		false
	cmp		edi, 126
	jg		false
	mov		rax, 1
	ret

false:
	mov		rax, 0
	ret
