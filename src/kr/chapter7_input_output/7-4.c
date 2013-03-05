#include<stdio.h>
#include<ctype.h>
#include<stdarg.h>

#define NUM 100

void minscanf(char *fmt,...){

	va_list ap;
        char *p,*sval;
        int ival;

        char localfmt[NUM];
        va_start(ap,fmt);
        for(p = fmt;*p;p++){
                if('%' !=  *p){
        //                putchar(*p);
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
			scanf(localfmt,ival);
                        break;
                case 's':
                        //for(sval = va_arg(ap,char *);*sval;sval++)
                        //      putchar(*sval);
                        sval = va_arg(ap,char*);
                        scanf(localfmt,sval);
                        break;
                default:
                        break;
                }
        }
        va_end(ap);


}

main(){

	int n1,n2,n3;
	minscanf("%d %d %d",&n1,&n2,&n3);
		printf("\tn1:%d n2:%d,n3:%d\n",n1,n2,n3);

	return 0;

}
