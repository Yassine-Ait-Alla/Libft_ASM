section .text
	global _ft_bzero

_ft_bzero:
	mov		rbx, rdi
	mov		rcx, 0

loop:
	cmp		rcx, rsi
	jz		end
	mov 	byte[rbx], 0x0
	inc		rbx
	inc		rcx
	jmp		loop

end:
	ret
