assume cs:codesg

data segment
 	db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
	db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
	db '1993','1994','1995'
 
 	dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
	dd 345980,590872,803530,1183000,1843000,2749000,3753000,4649000,5937000

	dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4307,5635,8226
	dw 11542,14430,15275,17800
data ends

table segment
	db 21 dup('year summ ne ?? ')
table ends

stacksg segment
	db 0,0,0,0
stacksg ends

codesg segment
start:	
	mov ax,data
	mov ds,ax
	mov ax,table
	mov es,ax
	mov ax,stacksg
	mov ss,ax
	mov sp,4
	mov si,0

	;拷贝年份开始
	mov cx,21
	mov bx,0
	

s0:	push cx	
	mov di,0
	mov cx,2

s1:	mov ax,ds:[si]
	mov es:[bx+di],ax
	add si,2
	add di,2
	loop s1
	
	pop cx
	add bx,16
	loop s0
	;拷贝年份结束
	
	;拷贝营业额开始
	mov bx,0
	mov cx,21
	
s2:	push cx
	mov di,5
	mov cx,2

s3:	mov ax,ds:[si]
	mov es:[bx+di],ax
	add si,2
	add di,2
	loop s3

	pop cx;
	add bx,16
	loop s2
	
	;拷贝营业额结束
	
	;拷贝员工数量开始
	mov bx,0
	mov cx,21
	mov di,10

s4:	push cx
	mov ax,ds:[si]
	mov es:[bx+di],ax
	add si,2
	add bx,16

	pop cx
	loop s4

	;拷贝员工数量结束

	;人均收入开始
	mov bx,0
	mov cx,21

s5:	push cx
	mov ax,es:[bx+5]
	mov dx,es:[bx+7]

	div word ptr es:[bx+10]
	mov es:[bx+13],ax
	add bx,16
	pop cx
	loop s5
	;人均收入结束

	mov ax,4c00h
	int 21h

codesg ends

end start
