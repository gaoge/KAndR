assume cs:codesg

datasg segment
	db "Beginner's All-purpose Symbolic Instruction Code.",0
datasg ends

codesg segment
begin:	mov ax,datasg
	mov ds,ax
	mov si,0
	call letterc

	mov ax,4c00h
	int 21h

letterc:
	push ax
s1:	mov al,[si]
	cmp al,0
	je ok
	cmp al,97
	jb next
	cmp al,122
	ja next
	sub al,32
	mov [si],al
	jmp s1

next:	inc si
	jmp s1

ok:	pop ax
	ret

codesg ends
end begin
