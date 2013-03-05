assume cs:code
code segment
start:mov ax,cs
      mov ds,ax
      mov si,offset istr
      mov ax,0
      mov es,ax
      mov di,200h
      mov cx,offset iend-offset istr
      cld
      rep movsb

      mov ax,0
      mov es,ax
      mov word ptr es:[7ch*4],0200h
      mov word ptr es:[7ch*4+2],0

      mov ax,0b800h
      mov es,ax
      mov di,160*12
      mov bx,offset s-offset se
      mov cx,80
    s:mov byte ptr es:[di],'!' ;0036
      add di,2
      int 7ch
   se:nop ;003f


   mov ax,4c00h
   int 21h


istr:push bp
     mov bp,sp
     dec cx
     jcxz ok
     add [bp+2],bx
ok:pop bp
     iret
iend:nop

code ends
end start
