#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXWORD 100


main(int args,char *argv[]){
	char word[MAXWORD];

	while( 'x'!= getword(word,5)){

		printf("word is: %s\n",word);
	}
}

int getword(char *word,int lim){
	char *w = word;
	int c;
	while(isspace( c = getchar()))
		;
	if(c != EOF)
		*w++ = c;
	for(;--lim>0;w++){
		if(!isalnum( *w=getchar())){	
	//		ungetchar(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
	
}
