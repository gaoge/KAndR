assume cs:code

data segment
	db 'welcome to masm!'; 77 65 6c 63 6f 6d 65 20 74 6f 20 6d 61 73 6d 21
data ends

;13 行开始偏移地址是780H，
;13行32列的偏移地址3e ,780h + 3eH = 7BeH
;显示缓冲区B8000H~BFFFFH,所以13行32列的地址就是B87BeH
;绿色02H,绿底红色：24H，白底蓝色71H
code segment
start:	
	mov ax,data
	mov ds,ax
	mov si,0
	mov ax,0B800H
	mov es,ax
	mov di,07BeH
	mov cx,16

s:	mov al,ds:[si]
	mov es:[di],al
	;mov byte ptr es:[di+1],00000010b
	inc si
	;inc di
	add di,2
	loop s

	mov di,07bfH
	mov cx,16

s1:	mov byte ptr es:[di],71H
	add di,2
	loop s1
	
		
	mov ax,4c00h
	int 21h
code ends

end start
