#include <stdio.h>
#include <stdlib.h>
#include "fileTransfer.h"


/*TODO

The trimF function currently doesnt account for when there is more than one newline character. Fix This!!! Instead, have the function cycle through string, counting the non-newline characters. Then, define a string that is this size. Then, pass all non newline characters into this new string. Finally, return a pointer to the beginning of this string.
*/

int main(){

	/*take in input from one text file. input it in another with the a 
	name of user's choice*/
	char * fileOut = malloc(260);
	char * fileIn = malloc(260);
	char * p;
	FILE * fpOut;
	FILE * fpIn;
	char key = 0;
	char c;
	long int size;	

	while(key == 0){

		printf("What file would you like to open?\n");
		
		fgets(fileOut, 260, stdin);
		
		/*
		freopen(NULL, "rb", stdin);
		fseek(stdin, 0, SEEK_END);
		
		size = ftell(stdin);
		fseek(stdin, 0, SEEK_SET);
		printf("%d\n", size);
		*/
		trimF(fileOut);
		fpOut = fopen(fileOut, "r");
		
		if(fpOut == 0){

			printf("File does not exist\n");
		}
		else{	
			while(key == 0){
				printf("What is the name of the file you would like to copy to?\n");
				fgets(fileIn, 260, stdin);
				trimF(fileIn);
				if(validChar(fileIn)){
					fpIn = fopen(fileIn, "w");
					while((c = fgetc(fpOut)) != -1){
				
						fprintf(fpIn, "%c", c);
					}

					fclose(fpOut);
					fclose(fpIn);
					key = 1;
				}
				else{
		
					printf("Invalid character in file name\n");
				}
			}
		}

		clearBuffer();
	}
}
