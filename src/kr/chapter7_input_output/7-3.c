#include<stdio.h>
#include<stdarg.h>
#include<ctype.h>
#define NUM 100

void minprintf(char *fmt,...){
	va_list ap;
	char *p,*sval;
	int ival;

	char localfmt[NUM];
	va_start(ap,fmt);
	for(p = fmt;*p;p++){
		if('%' !=  *p){
			putchar(*p);
			continue;
		}
	int i = 0;
	localfmt[i++] = *p;
	while(*(p+1) &&  !isalpha(*(p+1) ) ){
		localfmt[i++] = *++p;
	}
	localfmt[i++] = *(p+1);
	localfmt[i] = '\0';
	switch(*++p){
		case 'd':
			ival = va_arg(ap,int);
			printf(localfmt,ival);
			break;
		case 's':
			//for(sval = va_arg(ap,char *);*sval;sval++)
			//	putchar(*sval);
			sval = va_arg(ap,char*);
			printf(localfmt,sval);			
			break;
		default:
			break;
		}
	}
	va_end(ap);

}
main(){

	minprintf("int is:%d,str is:%.10s\n",3,"hello world");
	
//	minprintf("int is:%d,str is:%s\n",3,"hello world");

}
