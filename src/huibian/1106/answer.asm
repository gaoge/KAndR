assume cs:code,ss:stack

stack segment

        db 128 dup(0)

stack ends

 

code segment

start:

        mov ax,stack

        mov ss,ax

        mov sp,128

        mov ax,cs

        mov ds,ax

        mov ax,0

        mov es,ax

        mov si,offset int9

        mov di,204h

        mov cx,offset int9end-offset int9

        cld

        rep movsb               ;安装自定义的int9中断例程

       

       

        push es:[9*4]

        pop es:[200h]

        push es:[9*4+2]

        pop es:[202h]            ;保存原中断向量

        cli

        mov word ptr es:[9*4],204h

        mov word ptr es:[9*4+2],0     ;设置自定义的中断向量

        sti

 

        mov cx,120

lp:     mov ah,0    ;进行120次读取BIOS键盘缓冲区的操作，

        int 16h     ;以辅助读者在程序运行时方便进行相关的按键操作。

        loop lp

       

        mov ax,4c00h

        int 21h

 

int9:   ;自定义的int9中断例程

        push ax

        push bx

        push cx

        push es

       

        in al,60h

       

        pushf

        call dword ptr cs:[200h]

 

        cmp al,9eh                  ;A键的断码为9eh

        jne int9ret

 

        mov ax,0b800h

        mov es,ax

        mov bx,0

        mov cx,2000

s:      mov byte ptr es:[bx],'A'

        add bx,2

        loop s

int9ret:        pop es

                pop cx

                pop bx

                pop ax

        iret

int9end:        nop

 

code ends

end start
