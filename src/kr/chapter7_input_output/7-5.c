#include<stdio.h>
#include<ctype.h>

#define NUMBER '0'

main(){


}

int getOp(char s[]){

	int rc,c;
	float f;
	while( (rc = scanf("%c",c)) != EOF)
		if((s[0] = c) != ' ' || c != '\t')
			break;

        s[1] = '\0';

	if(rc == EOF)
		return EOF;
	
	else if(!isdigit(c) && c != '.')
		return c;
	
	ungetc(c,stdin);

	scanf("%f",&f);

	sprintf(s,"%f",f);

	return NUMBER;

}
