#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


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
main(){


}
