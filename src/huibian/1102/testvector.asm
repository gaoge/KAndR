assume cs:code

code segment
start:	;设置中断向量
	mov ax,0
	mov es,ax
	mov word ptr es:[0*4],0200h
	mov word ptr es:[0*4+2],0h

	mov ax,4c00h
	int 21h
code ends

end start
