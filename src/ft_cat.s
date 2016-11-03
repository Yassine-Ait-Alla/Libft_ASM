%define SYSCALL(x) 0x2000000 | x
%define WRITE 0x4
%define READ  0x3

global _ft_cat

section .bss
	buff:	 resb 0x200

section .text

_ft_cat:
	lea rsi, [rel buff]
	mov rdx, 0x200
	mov rax, SYSCALL(READ)
	syscall
	jc end
	cmp rax, 0
	jle end
	push rdi
	mov rdi, 1
	mov rdx, rax
	mov rax, SYSCALL(WRITE)
	syscall
	pop rdi
	jmp _ft_cat

end:
	mov rax, 0
	ret
