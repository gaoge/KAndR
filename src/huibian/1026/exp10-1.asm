assume cs:code 

data segment
	db 'Welcome to masm!',0
data ends

stack segment
	dw 0,0,0,0,0,0,0,0
stack ends

;13 行开始偏移地址是780H(160(A0)*12(C))，
;13行32列的偏移地址3e ,780h + 3eH = 7BeH
;显示缓冲区B8000H~BFFFFH,所以13行32列的地址就是B87BeH
;绿色02H,绿底红色：24H，白底蓝色71H

code segment
start:	mov dh,12
	mov dl,31
	mov cl,2
	mov ax,data
	mov ds,ax
	mov ax,stack
	mov ss,ax
	mov sp,16
	mov si,0

	call show_str
	
	mov ax,4c00h
	int 21h

show_str:
	push ax
	push es
	push si
	push bx

	mov ax,0B800H
	mov es,ax
	
	;bx中先加上行的偏移地址
	mov al,dh
	mov cl,0A0H
	mul cl
	mov bx,ax

	;bx再加上列的偏移地址
	mov al,dl
	mov cl,2
	mul cl
	add bx,ax
	
	;显示字符串的值
s:	mov cl,ds:[si]
	mov ch,0
	jcxz ok

	mov es:[bx],cl
	inc si
	inc bx
	mov byte ptr es:[bx],71H
	inc bx
	loop s

	

ok:	pop bx
	pop si
	pop es
	pop ax
	
	ret

code ends
end start
