section .text
	global _ft_isupper

_ft_isupper:
	cmp		edi, 65
	jl		false
	cmp		edi, 90
	jg		false
	mov		rax, 1
	ret

false:
	mov		rax, 0
	ret
