#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>

#define MAXWORD 100
#define HASHSIZE 101


struct nlist{

	nlist * next;
	char * name;
	char *defn;

};

static nlist* hashtab[HASHSIZE];

unsigned hash(char *s){
	unsigned hashval;
	for(hashval =0;*s != '\0';s++){
		hashval = *s + 31 * hashval;
	}
	return hashval % HASHSIZE;

}

struct nlist * lookup(char *s){

	struct nlist * np;
	for(np=hashtab[hash(s)];np->next != NULL;np = np->next){
		if(strcmp(np->name,s) == 0 )
			return np;
	}
	return NULL;
}
char *strdup(char *s){
	char * p;
	p = (char*) malloc(sizeof(strlen(s) + 1));
	if(NULL != p)
		strcpy(p,s);
	return p;
	
}
struct nlist* install(char *name,char *defn){
	struct nlist *np;
	
	unsigned hashval;
	if((np = lookup(name))== NULL){
		np = (struct nlist*) malloc(sizeof(*np));
		if(NULL == np || NULL == strdup(name)){
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}else{
		free((void *)np->defn);
	
	}
	if((np->defn = strdup(defn)) == NULL) return NULL;
	return np;
}

void undef(char *s){
	unsigned hashval;
	nlist * prev,*np;
	hashval = hash(s);
	for(np = hashtab[hashval];np!= NULL; np =np->next){
		if(strcmp(s,np->name) == 0)
			break;
		prev = np;
	}
	if(NULL != np){
		if(NULL == prev){
			hashtab[hashval] = np->next;
		}
		else{
			prev->next = np->next;
			free((void*)np->name);
			free((void*)np->defn);
			free((void*)np);
		}
	}
}
int getword(char *word,int lim){
        char *w = word;
        int c;
        while(isspace( c = getchar()))
                ;
        if(c != EOF){
                *w++ = c;
		printf("getword(),ch is: %c\n",c);
	}
        if(!isalpha(c)){
                *w = '\0';
               return c;
        }
        for(;--lim>0;w++){
                if(!isalnum( *w=getchar())){
                        putchar(*w);
                        break;
               
        }
        *w = '\0';
        return word[0];

}
void skipblanks(){
	int c;
	while((c=getchar()) == ' ' || '\t' == c)
		;
	putchar(c);
	
}
void error(int c,char *s){
	printf("error:%s\n",s);
	while(EOF != c && '\n' != c){
		c = getchar();
	}
}
void getdef(){

	int i;
	skipblanks();
	char name[MAXWORD],def[MAXWORD],dir[MAXWORD];
	int c = getword(dir,MAXWORD);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>> the dir is: %s\n",dir);
	if(!isalpha(c)){
		error(dir[0],"error after #,not alpha");
	}
	else if(0 == strcmp("define",dir)){
		skipblanks();
		if(!isalpha(getword(name,MAXWORD))){
			error(name[0],"error name");
		}else{
			skipblanks();
			for(i=0;i<MAXWORD-1;i++){
				if('\n' ==  (def[i] = getchar()) || (EOF == def[i]))
					break;
			}		
			def[i] = '\0';	
			if(i <= 0)
				error('\n',"incomplete define");
			else
				install(name,def);
		}
	}else if(0 == strcmp("undef",dir)){
		skipblanks();
		if(!isalpha(getword(name,MAXWORD))){
			error(name[0],"non alpha after undef");
		}else{
			undef(name);
		}
	}
	else{
		error(dir[0],"error directive after #");
	}
	
	
}


main(){
	char w[MAXWORD];
	nlist *p;
	while(getword(w,MAXWORD) != EOF){
		if(strcmp(w,"#") == 0) getdef();
		else if(!isalpha(w[0])) printf("%s\n",w);
		else if((p=lookup(w)) == NULL) printf("%s\n,w");
		else ;
	}
	return 0;

}
