#include<stdio.h>
#include<ctype.h>
#include<string.h>

main(int argc,char* argv[]){

	int c;
	printf("argv[1] is:%s\n",argv[1]);
	if(0 == strcmp(argv[1],"low")){
		while( (c=getchar()) !=EOF  ){
			putchar(tolower(c));
		}
	}
	else{
		while( (c=getchar()) !=EOF  ){
                        putchar(toupper(c));
                }
	}
	return 0;

}
