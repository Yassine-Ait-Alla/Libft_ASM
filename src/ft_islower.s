section .text
	global _ft_islower

_ft_islower:
	cmp		edi, 97
	jl		false
	cmp		edi, 122
	jg		false
	mov		rax, 1
	ret

false:
	mov		rax, 0
	ret
