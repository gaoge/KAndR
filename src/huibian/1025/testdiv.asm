assume cs:code

data segment
	db '1975 '
	dd 16
	db ' '
	dw 3
	dw ' '
data ends

code segment

start:	
	mov ax,data
	mov ds,ax
	mov bx,0
	mov ax,ds:[bx+5]
	mov dx,ds:[bx+7]
	div word ptr ds:[bx+10]
	mov ds:[bx+13],ax
	
	mov ax,4c00h
	int 21h
code ends

end start
