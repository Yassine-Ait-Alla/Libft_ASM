section .text
	global _ft_strchr

_ft_strchr:
	mov		rax, rdi

loop:
	cmp		byte[rdi], 0
	jz		_ft_null
	cmp		byte[rdi], sil
	jz		match
	inc		rdi
	jmp		loop

match:
	mov		rax, rdi
	ret

_ft_null:
	cmp		sil, 0
	jz		match
	mov		rax, 0
	ret
