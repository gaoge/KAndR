assume cs:code 

stack segment
	db 8 dup(0)
stack ends

code segment
start:	
	mov ax,stack
	mov ss,ax
	mov sp,8

	mov ax,4240H
	mov dx,000FH
	mov cx,0AH
	call divdw
	
	mov ax,4c00h
	int 21h
divdw:
	mov bx,ax
	mov ax,dx
	mov dx,0
	
	div cx
	push ax
	
	mov ax,bx
	div cx
	
	
	mov cx,dx
	pop dx

	ret
code ends

end start
