#include <unistd.h>
#include<stdio.h>
#include<fcntl.h>

#define BUFSIZE 50

void filecopy(int fd1,int fd2){
	char buf[BUFSIZE];
	int n;
	while((n=read(fd1,buf,BUFSIZE)) > 0){
		if(n != (write(fd2,buf,n))){
			printf("cp,write error on file %d\n",fd2);
		}
	}

}

main(int argc,char *argv[]){
	int fd1 = 0;
	if(1 == argc){
		filecopy(0,1);
	}else{
		if(--argc > 0){
			if((fd1 = open(*++argv,O_RDONLY,0)) == -1){
				printf("error,can't open %s\n",*argv);
			}else{
				filecopy(fd1,1);
				close(fd1);
			}

		}
	}
	return 0;
}


