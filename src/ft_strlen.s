section .text
	global _ft_strlen

_ft_strlen:
	cmp		rdi, 0
	je		ft_null
	mov		rcx, -1
	mov		al, 0
	cld
	repnz	scasb
	mov		rax, rcx
	neg		rax
	sub		rax, 2
	ret

ft_null:
	mov		rax, 0
	ret
