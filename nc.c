#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long convert(char* string, char base){
	long n = 1;
	long counter = 0;
	for(short i = strlen(string)-1; i >= 0; --i){
		if(string[i] >= 'A' && string[i] <= 'Z') string[i] += 0x20;
		
		if(string[i] >= '0' && string[i] <= '9'){
			if(string[i]-0x30 < base) counter += n*(string[i]-0x30); 
			else {printf("number: \'%c\' is not in base %i.\n", string[i], base); return -1;}
		}
		else if(string[i] >= 'a' && string[i] <= 'z'){
			if(string[i]-0x57 < base) counter += n*(string[i]-0x57);
			else{ printf("number: \'%c\' is not in base %i.\n", string[i], base); return -1;}
		}
		else return -1;
		n *= base;
	} return counter;
};

int main(int argc, char **argv, char **envp){
	char base = 16;

	if(argv[1] == '\0'){ 
		printf("No argument");
		return -1;
	}
	for(int i = 1; argv[i] != '\0'; ++i) {
		printf("%b\n", convert(argv[i], base));
	} return 0;
}
