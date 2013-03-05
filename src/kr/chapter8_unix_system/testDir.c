#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#include<syscall.h>
#include<dirent.h>
#include<sys/dir.h>

#define MAX_PATH 1024

void dirwalk(char *,void (*fcn)(char*));

void fsize(char *name){
	struct stat stbuf;
	
	if( -1 == stat(name,&stbuf)){
		fprintf(stderr,"fsize:can't access %s\n",name);
		return;
	}
	if((stbuf.st_mode & S_IFMT) == S_IFDIR){
		dirwalk(name,fsize);
	}
	printf("%81d %s\n",stbuf.st_size,name);
}

void dirwalk(char *dir,void (*fcn)(char*)){
	char name[MAX_PATH];
	DIR *dfd;
	dirent *dp;

	if( (dfd = opendir(dir)) == NULL){
		fprintf(stderr,"dirwalk:can't open %s\n",dir);
		return;
	}
	while((dp = readdir(dfd)) != NULL){
		if( strcmp(dp->d_name,".") == 0 || strcmp(dp->d_name,"..") == 0) continue;
		if(strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
			fprintf(stderr,"dirwalk:name %s/%s too long\n",dir,dp->d_name);
		else{
			sprintf(name,"%s/%s",dir,dp->d_name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}

main(int argc,char* argv[])
{
	if(1 == argc )
		fsize(".");
	else{
		while(--argc > 0)
			fsize(*++argv);
	}
	return 0;

}
