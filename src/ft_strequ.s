section .text
	global _ft_strequ

_ft_strequ:
	cmp		dil, sil
	jne		notequ
	cmp		dil, 0
	je		isequ
	inc		dil
	inc		sil
	jmp		_ft_strequ

isequ:
	mov		rax, 1
	ret

notequ:
	mov		rax, 0
	ret
