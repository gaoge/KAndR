assume cs:code

code segment
start:	
	mov ax,code
	mov ds,ax
	mov si,offset show_data

	mov ax,0	
	mov es,ax
	mov di,200h

	mov cx,offset show_end - offset show_data
	cld
	rep movsb

	mov ax,0
	mov es,ax
	mov word ptr es:[7ch*4+0],200h
	mov word ptr es:[7ch*4+2],0

	int 7ch

	mov ax,4c00h	
	int 21h
	
show_data:
	jmp short show_str
	db "welcome"

show_str:
	mov ax,0
	mov ds,ax
	mov si,202h

	mov ax,0b800h
	mov es,ax
	mov di,160*12+36*2
	mov cx,7
s1:	
	mov al,ds:[si]
	mov es:[di],al
	inc di
	mov byte ptr es:[di],02h
	inc di
	inc si
	loop s1

	iret

show_end:nop

code ends

end start
