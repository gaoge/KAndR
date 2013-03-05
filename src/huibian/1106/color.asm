assume cs:code
data segment

	db 128 dup(0)
data ends
code segment
start:
	;安装int9中断例程
	mov ax,code
	mov ds,ax
	mov si,offset prog_start

	mov ax,0
	mov es,ax
	mov di,200h

	mov cx,offset prog_end - prog_start
	cld
	rep movsb

	;保存原int9中断程序入口
	mov ax,data
	mov ds,ax
	push es:[9*4]
	pop ds:[0]
	push es:[9*4+2]
	pop ds:[2]

	;设置新的int9中断例程入口
	cli
	mov word ptr es:[9*4],200h
	mov word ptr es:[9*4+2],0
	sti

	mov ax,4c00h
	int 21h
	



prog_start:
	push ax
	push bx
	push es	
	push cx

	in al,60h

	pushf
	call dword ptr ds:[0]
	cmp al,3bh
	jne ok
	mov ax,0b800h
	mov es,ax
	mov bx,1
	mov cx,2000
s1:
	inc byte ptr es:[bx]
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

