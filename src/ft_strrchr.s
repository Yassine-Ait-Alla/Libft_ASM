section .text
	extern _ft_strchr
	global _ft_strrchr

_ft_strrchr:
	xor		r10, r10

loop:
	cmp		byte[rdi], 0
	jz		_ft_null
	cmp		byte[rdi], sil
	jz		match
	inc		rdi
	jmp		loop

match:
	mov		r10, rdi
	inc		rdi
	jmp		loop

_ft_null:
	cmp		sil, 0
	jz		end
	cmp		r10, 0
	jnz		exit
	mov		rax, 0
	ret

end:
	mov		rax, rdi
	ret

exit:
	mov		rax, r10
	ret
