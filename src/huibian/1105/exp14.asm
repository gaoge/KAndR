assume cs:code

code segment
start:
	;年
	mov al,9
	out 70h,al
	in al,71h
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	add ah,30h
	add al,30h

	mov bx,0b800h
	mov es,bx
	mov byte ptr es:[160*12+40*2],ah
	mov byte ptr es:[160*12+41*2],al

	mov byte ptr es:[160*12+42*2],2fh

	;月
	mov al,8
	out 70h,al
	in al,71h
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	add ah,30h
	add al,30h

	mov bx,0b800h
	mov es,bx
	mov byte ptr es:[160*12+43*2],ah
	mov byte ptr es:[160*12+44*2],al

	mov byte ptr es:[160*12+45*2],2fh

	;日
	mov al,7
	out 70h,al
	in al,71h
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	add ah,30h
	add al,30h

	mov bx,0b800h
	mov es,bx
	mov byte ptr es:[160*12+46*2],ah
	mov byte ptr es:[160*12+47*2],al

	mov byte ptr es:[160*12+48*2],2fh

	mov byte ptr es:[160*12+49*2],20h

	;时
	mov al,4
	out 70h,al
	in al,71h
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	add ah,30h
	add al,30h

	mov bx,0b800h
	mov es,bx
	mov byte ptr es:[160*12+50*2],ah
	mov byte ptr es:[160*12+51*2],al

	mov byte ptr es:[160*12+52*2],3ah

	;分
	mov al,2
	out 70h,al
	in al,71h
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	add ah,30h
	add al,30h

	mov bx,0b800h
	mov es,bx
	mov byte ptr es:[160*12+53*2],ah
	mov byte ptr es:[160*12+54*2],al

	mov byte ptr es:[160*12+55*2],3ah

	;秒
	mov al,0
	out 70h,al
	in al,71h
	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111b
	add ah,30h
	add al,30h

	mov bx,0b800h
	mov es,bx
	mov byte ptr es:[160*12+56*2],ah
	mov byte ptr es:[160*12+57*2],al


	mov ax,4c00h
	int 21h

code ends

end start
