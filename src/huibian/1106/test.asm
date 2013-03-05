assume cs:code 
data segment
	db 128 dup(0)
data ends

code segment
start:
	

	mov ax,0	
	mov es,ax
	mov word ptr es:[9*4+2],0
	mov word ptr es:[9*4],200h

	mov ax,4c00h
	int 21h
	
code ends

end start
