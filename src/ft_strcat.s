section .text
	global _ft_strcat

_ft_strcat:
	mov		rax, rdi

begin_loop:
	cmp		byte[rdi], 0
	jz		copy
	inc		rdi
	jmp		begin_loop

copy:
	cmp		byte[rsi], 0
	jz		finish
	movsb
	jmp		copy

finish:
	mov		byte[rdi], 0x0
	ret
