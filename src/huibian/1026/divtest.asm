assume cs:code 

code segment

start:	
	mov ax,4240H
	mov dx,000FH
	mov bx,0AH
	div bx	
	mov ax,4c00h
	int 21h
code ends

end start
