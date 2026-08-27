section .multiboot align=4

[BITS 32]
dd 0x1BADB002
dd 0x00000043
dd -(0x1BADB002+0x00000043)

section .bss align=16
stk_btm:
resb 16384
stk_top:

extern main
section .text
global _start:function
_start:
    mov esp,stk_top
    push ebx
    push eax 
    call main
    jmp $
