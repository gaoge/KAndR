#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXWORD 100
struct key{
	char *word;
	int count;
}keytab[] = {
	"auto",0,
	"break",0,
	"case",0,
	"char",0,
	"const",0,
	"default",0,
	"void",0,
	"while",0
	
};


main(int args,char *argv[]){
	char word[MAXWORD];
	int index;
	int n;
	
	char c = getchar();
	printf("char c : %c \n",c);

	while( 'x' != getword(word,MAXWORD)){
		printf("word is: %s\n",word);
		if((index = binsearch(word,keytab,8)) >=0 ){

			keytab[index].count++;
		}
	}
	printf("\nafter while loop\n");
	for( n=0;n<8;n++)
	{
		printf("%s %d\n",keytab[n].word,keytab[n].count);
	}
	return 0;

}

int getword(char *word,int lim){
	char *w = word;
	int c;
	while(isspace( c = getchar()))
		;
	if(c != EOF)
		*w++ = c;
	if(!isalpha(c)){
		*w = '\0';
		return c;
	}
	for(;--lim>0;w++){
		if(!isalnum( *w=getchar())){	
			putchar(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
	
}

int binsearch(char *word,struct key tab[],int n){
	int cond;
	int low = 0;
	int high = n-1;
	int mid ;
	
	while(low <= high)
	{
		mid = (low+high) / 2;
		if( (cond = strcmp(word,tab[mid].word)) < 0)
			high = mid -1;
		else if(cond > 0)
			low = mid + 1;
		else return mid;
	}
	return -1;

}


