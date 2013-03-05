assume cs:code
data segment
	db "welcome",0
data ends

code segment
start:	
	mov ax,code
	mov ds,ax
	mov si,offset prog_start

	mov ax,0	
	mov es,ax
	mov di,200h

	mov cx,offset prog_end - offset prog_start
	cld
	rep movsb
	
	mov word ptr es:[7ch*4+0],200h
	mov word ptr es:[7ch*4+2],0

	mov dh,10
	mov dl,10
	mov cl,2
	mov ax,data
	mov ds,ax
	mov si,0
	int 7ch

	mov ax,4c00h
	int 21h

prog_start:
	push ax
	push dx
	push di

	mov ax,0b800h
	mov es,ax
	mov al,160
	mul dh
	mov di,ax
	
	mov al,2
	mul dl

	add di,ax
s1:
	mov cl,[si]
	jcxz ok
	mov es:[di],cl
	add di,2
	inc si
	jmp short s1
	
ok:
	pop di
	pop dx
	pop ax
	
	iret	
	
prog_end:nop

	
code ends

end start
