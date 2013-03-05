assume cs:code

code segment
start:	
	mov al,0A0H
	mov dl,8
	mul dl

	mov ax,4c00h
	int 21h
code ends

end start
