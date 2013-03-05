#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 100
#define YES 1
#define NO 0

struct tnode{
	char *word;
	int match;
	struct tnode *left;
	struct tnode *right;
};

void  addtreex(tnode *&p,char *w,int num,int *found);
void print( tnode * p);
struct tnode * talloc();
int compare( tnode*p,char *s,int num,int *found);
int getword(char *word,int lim);
int shu = 0;

main(int args,char *argv[]){
	struct tnode *root;
	char word[MAXWORD];
	int found = NO;

	int num = 3;
	root = NULL;

	while( 'x' != getword(word,MAXWORD) ){
		 addtreex(root,word,num,&found);
		found = NO;
	}
	print(root);
}

char *strdup(char *s){

	char *p;
	p = (char*) malloc(strlen(s) + 1);
	if(NULL != p) strcpy(p,s);
	return p;
}

void  addtreex( tnode *&p,char *w,int num,int *found){
        int cond;
        if(NULL == p){ 
                p = talloc();
                p->word = strdup(w);
                p->match= *found;
                p->left = p->right = NULL;
        }   
        else if( (cond = compare(p,w,num,found)) < 0 ){
                 addtreex(p->left,w,num,found);    
        }else if(cond > 0){
                 addtreex(p->right,w,num,found);
        }   
}

void print( tnode * p){
	if(NULL != p){
	//	printf("p is not null,p->word %s\n",p->word);
		print(p->left);
		if(p->match){
			printf("%s\n",p->word);
		}
		print(p->right);
	}
	else{
	//	printf("p is null \n");
	}

}

void printTree(tnode *p){
	if(p->left != NULL) printTree(p->left);
	printf("node word is: %s",p->word );
	if(p->right != NULL) printTree(p->right);
}

struct tnode * talloc(){
	return (struct tnode*) malloc(sizeof(struct tnode) );

}

int compare(tnode*p,char *s,int num,int *found){
	char * t = p->word;
	int i =0;
	for(;*t == *s;i++,s++,t++){
		if('\0' == *s )
			return 0;

	}
	if(i >= num){
		p->match = YES;
		*found = YES;
	}
	return *s - *t;

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

