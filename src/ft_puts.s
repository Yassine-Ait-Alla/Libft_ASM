global _ft_puts
extern _ft_strlen

section .data
data:
.null:		db	"(null)"

section .text

_ft_puts:
lea		rsi, [rel rdi] ;adresse pointeur
call	_ft_strlen
cmp		rdi, 0
je		ft_null
mov		rdi, 1
mov		rdx, rax
mov		rax, 0x2000004 ; write
syscall
jmp		newline

ft_null:
lea		rsi, [rel data.null]
mov 	rax, 0x2000004
mov		rdi, 1
mov		rdx, 6
syscall

newline:
push	10
mov		rsi, rsp
mov		rax, 0x2000004
mov		rdi, 1
mov		rdx, 1
syscall
pop		rax
ret
