assume cs:code
stack segment

	db 128 dup(0)
stack ends
code segment
start:
	mov ax,stack
	mov ss,ax
	mov sp,128

	;安装int9中断例程
	mov ax,code
	mov ds,ax
	mov si,offset prog_start

	mov ax,0
	mov es,ax
	mov di,204h

	mov cx,offset prog_end - prog_start
	cld
	rep movsb

	;保存原int9中断程序入口
	push es:[9*4]
	pop es:[200h]
	push es:[9*4+2]
	pop es:[202h]

	;设置新的int9中断例程入口
	cli
	mov word ptr es:[9*4],204h
	mov word ptr es:[9*4+2],0
	sti

	mov ax,4c00h
	int 21h
	



prog_start:
	push ax
	push bx
	push es	
	push cx

	mov ax,0
	mov es,ax

	in al,60h

	pushf
	call dword ptr es:[200h]
	cmp al,9eh
	jne ok
	mov ax,0b800h
	mov es,ax
	mov bx,0
	mov cx,2000
s1:
	mov byte ptr es:[bx],'A'
	add bx,2
	loop s1
	

ok:	
	pop cx
	pop es	
	pop bx
	pop ax

	iret
prog_end:
	nop
code ends

end start

