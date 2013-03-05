assume cs:code
data segment
	db "welcome,gaoge,i love you",0
data ends

code segment
start:	
	mov ax,code
	mov ds,ax
	mov si,offset program

	mov ax,0	
	mov es,ax
	mov di,200h

	mov cx,offset program_end - offset program
	cld
	rep movsb
	
	mov ax,0
	mov es,ax
	mov word ptr es:[7ch*4+0],200h
	mov word ptr es:[7ch*4+2],0

	mov ax,0b800h
	mov es,ax

	mov di,160*12
	mov bx,offset s - offset se

	mov ax,data
	mov ds,ax
	mov si,0

s:	cmp byte ptr [si],0
	je ok
	mov al,[si]
	mov byte ptr es:[di],al
	add di,2
	inc si
	int 7ch

se:	nop   

program:
	push bp
	mov bp,sp
	add [bp+2],bx
	pop bp
	iret

program_end:
	nop

ok:	mov ax,4c00h
	int 21h
code ends

end start
