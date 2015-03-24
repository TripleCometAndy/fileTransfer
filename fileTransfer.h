#include <stdio.h>
#include <stdlib.h>



void trimF(char * str){

	char * p = str;
	
	while(*p != 0){
		
		p++;
	
	}
	p--;
	*p = 0;

}

int validChar(char * str){

	char * p = str;

	while(*p != 0){

		if(*p == 0x2F || *p == 0x5C || *p == 0x3F || *p == 0x25 || *p == 0x2A || *p == 0x3A || *p == 0x7C || *p == 0x22 || *p == 0x3C || *p == 0x3E || *p == 0x2E || *p == 0x20){

			return 0;
		}
		p++;

	}
	return 1;

}

void clearBuffer(){

	char c;
	fseek(stdin, 0, SEEK_END); 
	ungetc('\n', stdin);
	fseek(stdin, 0, SEEK_SET);
	while((c = getchar()) != '\n' && c != EOF);

}
