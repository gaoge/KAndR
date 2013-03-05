assume cs:code

code segment
start:	
	mov ax,code
	mov ds,ax
	mov si,offset squr

	mov ax,0	
	mov es,ax
	mov di,200h

	mov cx,offset squr_end - offset squr
	cld
	rep movsb

	mov ax,0
	mov es,ax
	mov word ptr es:[7ch*4+0],200h
	mov word ptr es:[7ch*4+2],0

	mov ax,16
	int 7ch

	mov ax,4c00h	
	int 21h

squr:	mul ax
	iret

squr_end:nop

code ends

end start
