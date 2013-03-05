#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINE 10
#define MAXHDR 1
#define MAXBTM 2
#define MAXWORD 20

void fprt(FILE *fp){
	int lineno = 1;
	int pageno = 1;
	char line[MAXWORD];
	while(NULL != (fgets(line,MAXWORD,fp))){
		
		fputs(line,stdout);
		if(lineno++ >= (MAXLINE - MAXBTM)){
			lineno = 1;
			fputs("\f",stdout);	
		}
		
	}

}

main(int argc,char *argv[]){
	FILE *fp;
	if(2 != argc){
		printf("Usage: -filename\n");
	}
	else{
		if(NULL == (fp = fopen(*++argv,"r"))){
			printf("open file %s error\n",*argv);
		}else{
			fprt(fp);
		}
	}
}

