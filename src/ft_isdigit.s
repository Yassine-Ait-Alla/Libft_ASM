section .text
	global _ft_isdigit

_ft_isdigit:
	cmp		edi, 48
	jl		false
	cmp		edi, 57
	jg		false
	mov		rax, 1
	ret

false:
	mov		rax, 0
	ret
