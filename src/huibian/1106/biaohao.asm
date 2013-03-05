assume ds:data,cs:code
data segment 
	a db 1,2,3,4,5,6,7,8
	c dw a
	b dw 3e2fh
	d dw b
data ends

code segment
start:
	mov ax,data
	mov ds,ax

	mov ax,4c00h
	int 21h
code ends

end start
