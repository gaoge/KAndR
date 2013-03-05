assume cs:code

code segment
start:	mov ax,0b800h
	mov es,ax

	mov ax,0
	mov es,ax
	mov word ptr es:[7ch*4+0],200h
	mov word ptr es:[7ch*4+2],0

	mov ax,code
	mov ds,ax
	mov si,offset program

	mov ax,0	
	mov es,ax
	mov di,200h

	mov cx,offset program_end - offset program
	cld
	rep movsb


	mov di,160*12
	mov bx,offset s - offset se
	mov cx,5

	

s:	mov byte ptr es:[di],'!'
	inc di
	mov byte ptr es:[di+1],02h
	inc di
	int 7ch

se:	nop

program:
	push bp
	mov bp,sp
	dec cx
	jcxz end_loop
	add [bp+2],bx
end_loop:
	pop bp
	iret
	
	
program_end:
	nop

	mov ax,4c00h
	int 21h
code ends

end start
