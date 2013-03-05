assume cs:code

data segment
	db "welcome",0
data ends


code segment
start:
	mov ax,data
	mov ds,ax
	mov si,0
	mov ax,[si]

	mov ax,4c00h
	int 21h

code ends

end start
