#include<stdio.h>
#include<ctype.h>

#define MAXPOS 100
#define OCTLEN 6

int getpos(int pos,int n){
	if(pos + n > MAXPOS){
		putchar('\n');
		return n;
	}else{
		return pos + n;
	}

}
main(){
	char * s = "hello,world";
	/**
	printf("%s\n",s);
	printf("%20s\n\n",s);

	printf("%.8s\n",s);
	printf("%-10s\n\n",s);

	printf("%.15s\n",s);
	printf("%-15s\n\n",s);

	printf("%35.10s\n",s);
	printf("%-15.10s\n",s);	
	*/
	int c,pos;
	while(EOF != (c=getchar())){
		if(iscntrl(c) || c == ' '){
			pos = getpos(pos,OCTLEN);
			printf("\\%03o",c);
			if('\n' == c){
				putchar('\n');
				pos = 0;
			}
		}else{
			putchar(c);
			pos = getpos(pos,1);
		}
	}
}
