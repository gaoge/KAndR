assume cs:code
data segment
	db 128 dup(0)
data ends

code segment
start:
	;save the old int9 address
	mov ax,data
	mov ds,ax
	push es:[9*4+0]
	pop ds:[0]
	push es:[9*4+2]
	pop ds:[2]

	;set the new int9 address
	mov ax,0	
	mov es,ax
	mov word ptr es:[9*4+2],code
	mov word ptr es:[9*4+0],offset myint9
	

	;show chracters
	mov ax,0b800h
	mov es,ax
	
	
	mov al,'a'

s1:	mov es:[160*12+40*2],al
	inc al
	call delay
	cmp al,'z'
	jna s1

	mov ax,4c00h
	int 21h

;delay function
delay:
	push dx
	push ax

	mov dx,1000h
	mov ax,0

s2:	sub ax,1
	cmp ax,0
	jne s2
	sub dx,1
	cmp dx,0
	jne s2

	pop ax
	pop dx

	ret

myint9:
	push ax
	push es

	pushf
	
	pushf 
	pop ax
	and ax,11111100B
	push ax
	popf

	;invoke the old int9h program ,to let the system hide some details of hardware operation
	call word ptr ds:[0] 

	in al,60h
	cmp al,01
	jne notesc

	mov ax,0b800h
	mov es,ax
	inc byte ptr es:[160*12+40*2 + 1]
	

notesc:
	pop es
	pop ax

	iret 
	

code ends

end start
