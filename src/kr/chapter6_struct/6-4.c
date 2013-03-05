#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 100
#define YES 1
#define NO 0a



struct linenode{
	int line;
	linenode * next;
};

struct tnode{
	char *word;
	int count;
	tnode *left;
	tnode *right;
};

void  addtreex(tnode *&p,char *w);
void printTree( tnode * p);
struct tnode * talloc();
struct linenode *linealloc();
void addCount(tnode *&p);
int getword(char *word,int lim);
void addTreeToList(tnode *node);
void sortNodeList();
void printInOrder();

int shu = 0;
const int MAXNODE = 1000;
struct tnode* nodelist[MAXNODE];
int cnt;

main(int args,char *argv[]){
	struct tnode *root;
	char word[MAXWORD];

	int num = 3;
	root = NULL;

	while( EOF != getword(word,MAXWORD) ){
		
		//printf("word[0]: %c\n",word[0]);
		if(isalpha(word[0])){
			 addtreex(root,word);
		}

	}
	addTreeToList(root);
	sortNodeList();
	//printTree(root);
	printInOrder();
}

void addTreeToList(tnode * node){
	if(NULL != node){
		if(NULL != node->left) addTreeToList(node->left);
		nodelist[cnt++] = node;
		if(NULL != node->right) addTreeToList(node->right);
	}	
}
void printInOrder(){
	for(int i=0;i<cnt;i++){
		printf("%s ,%d\n",nodelist[i]->word,nodelist[i]->count);
	}

}

void sortNodeList(){
	printf("sortNodeList######################### \n");
	int DataLength = cnt/2;
	int Pointer;
	tnode* tmp;

	while(0 != DataLength){
		for(int i=DataLength;i<cnt;i++){
			Pointer = i - DataLength;
			tmp = nodelist[i];
			while(Pointer >= 0 && (nodelist[Pointer]->count >  tmp->count )){
				nodelist[Pointer+DataLength] = nodelist[Pointer];
				Pointer -= DataLength;
			}
			nodelist[Pointer+DataLength] = tmp;
		}
		DataLength /= 2;
	}
}

char *strdup(char *s){

	char *p;
	p = (char*) malloc(strlen(s) + 1);
	if(NULL != p) strcpy(p,s);
	return p;
}

void  addtreex( tnode *&p,char *w){
        int cond;
        if(NULL == p){ 
                p = talloc();
                p->word = strdup(w);
		p->count = 1;
                p->left = p->right = NULL;
	}
	else if( (cond = strcmp(w,p->word)) == 0){
		addCount(p);
	}   
        else if( cond < 0 ){
                 addtreex(p->left,w);    
        }else{
                 addtreex(p->right,w);
        }   
}

void addCount(tnode *&p){
	if(NULL != p) p->count++;
}

void printTree(tnode *p){
	if(p->left != NULL) printTree(p->left);
	printf(" %s: %d\n",p->word,p->count );
	if(p->right != NULL) printTree(p->right);
}

struct tnode * talloc(){
	return (struct tnode*) malloc(sizeof(struct tnode) );

}

struct linenode * linealloc(){
	return (struct linenode*) malloc(sizeof(struct linenode));
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

