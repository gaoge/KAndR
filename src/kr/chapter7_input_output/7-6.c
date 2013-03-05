#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 500

void filecmp(FILE *f1,FILE *f2){
	char line1[MAXLINE],line2[MAXLINE];
	
	char *l1,*l2;

	do{
		l1 = fgets(line1,MAXLINE,f1);
		l2 = fgets(line2,MAXLINE,f2);
		
		if(l1 != line1 && l2 == line2){
			printf("end of first file at line: %s\n",line1);
		}else if(l1 == line1 && l2 != line2){
			printf("end of second file at line: %s\n",line2);
		}
		else if(l1 == line1 && l2 == line2){
			if(strcmp(l1,l2) != 0){
				printf("first different file,file1 line: %s, file2 line: %s\n",l1,l2);
				l1 = l2 = NULL;
			}
		}
	}while(l1 == line1 && l2 == line2);

}
main(int argc,char *argv[]){

	FILE *f1,*f2;
	if(3 != argc){
		fprintf(stderr,"need two file2 to compare\n");
	}else{
		if( NULL == (f1 = fopen(*++argv,"r"))){
			fprintf(stderr,"can't open first file");
			exit(1);
		}
		else if(NULL == (f2 = fopen(*++argv,"r"))){
			fprintf(stderr,"can't open second file");
			exit(1);
		}else{
			filecmp(f1,f2);
			fclose(f1);
			fclose(f2);
			exit(0);
		}
	}

}
