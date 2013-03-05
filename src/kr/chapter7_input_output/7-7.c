#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 500

void fpat(FILE *fp,char *pattern,int exclude,int num){

	char line[MAXLINE];
	int lineno = 0;
	while (NULL !=  fgets(line,MAXLINE,fp)){
		if( (NULL == strstr(line,pattern)) == exclude){
			if(num){
				printf("%d:\t",++lineno);
			}
			printf("%s\n",line);
		}
	}
}

//Usage:find -x -n "pattern" file1
main(int argc,char *argv[]){
	int c;
	int exclude=0,num;
	char pattern[MAXLINE];
	FILE *fp;
	while(--argc >0   &&   (*++argv)[0] == '-'){
		c = *++argv[0];
		switch(c){
		case 'x':
			exclude = 1;	
			break;
		case 'n':
			num = 1;
			break;
		default:
			printf("Unknown option\n");
		}
	}

	if(argc >=1){
		strcpy(pattern,*argv);
	}else{
		printf("Usage:find -x -n pattern file\n");	
	}
	
	if(--argc < 0){
		fpat(stdin,pattern,exclude,num);
	}else{
		if( NULL == (fp = fopen(*++argv,"r")) ){
			printf("error open file:%s\n",*argv);
		}else{
			fpat(fp,pattern,exclude,num);	
		}
		
	}

	
	
}
