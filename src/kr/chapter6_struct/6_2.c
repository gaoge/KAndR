#include<stdio.h>
#include<stdlib.h>

#define MAXWORD 100
#define YES 1
#define NO 0

struct tnode{
	char *word;
	int match;
	struct tnode *left;
	struct tnode *right;
};

struct tnode * addtreex(struct tnode *p,char *w,int num,int *found);
void print(struct tnode * p);

main(int args,char *argv[]){
	struct tnode *root;
	char word[MAXWORD];
	int found = NO;

	int num = 3;
	root = NULL;

	while( 'x' != getword(word,MAXWORD) ){
		root = addtreex(root,word,num,&found);
		found = NO;
	}
	print(root);
}

void print(struct tnode * p){
	if(NULL != p){
		printf("p is not null,p->word %s\n",p->word);
		print(p->left);
		if(p->match){
			printf("%s\n",p->word);
		}
		print(p->right);
	}
	else{
		printf("p is null \n");
	}

}

struct tnode * talloc(){
	return (struct tnode*) malloc(sizeof(struct tnode) );

}

int compare(struct tnode*p,char *s,int num,int *found){
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

struct tnode *  addtreex(struct tnode *p,char *w,int num,int *found){
	int cond;
	if(NULL == p){
		p = talloc();
		p->word = w;
		p->match= *found;
		p->left = p->right = NULL;
	}
	else if( (cond = compare(p,w,num,found)) < 0 ){
		p->left = addtreex(p->left,w,num,found);		
	}else if(cond > 0){
		p->right = addtreex(p->right,w,num,found);
	}
	return p;
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

