assume cs:code

data segment
	db 'overflow!'
data ends


code segment
start:
	

	mov ax,cs
	mov ds,ax
	mov si,offset show_data
		
	mov ax,0h
	mov es,ax
	mov di,0200h
	mov cx,offset show_end - offset show_data
	cld
	rep movsb
	
	;设置中断向量
	mov ax,0
	mov es,ax
	mov word ptr es:[0*4],0200h
	mov word ptr es:[0*4+2],0h
	

	mov ax,4c00h
	int 21h

show_data:
	jmp short show_overflow
	db "overflow!"

show_overflow:
	;因为是中段程序，cpu会自动压栈，出栈，所以不用再在程序里执行下列操作
	mov ax,cs
	mov ds,ax
	mov si,0
	

	mov ax,0B800H
	mov es,ax

	mov di,12*160+36*2
	mov cx,9
	;显示字符串的值
s:	mov al,ds:[si]
	mov es:[di],al
	inc si
	inc di
	mov byte ptr es:[di],71H
	inc di
	loop s

	mov ax,4c00h
	int 21h

show_end:nop



code ends

end start
