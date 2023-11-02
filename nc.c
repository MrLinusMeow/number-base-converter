#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* string, char baseIn, char baseOut){
	long n = 1;
	long counter = 0;
	char valid = 1;
	char r = 0;
	char output[256] = {};
	char temp;
	if(baseIn == baseOut) return string;
	
	for(short i = strlen(string)-1; i >= 0; --i){
		if(string[i] >= 'A' && string[i] <= 'Z') string[i] += 0x20;
		
		if(string[i] >= '0' && string[i] <= '9'){
			if(string[i]-0x30 < baseIn) counter += n*(string[i]-0x30);
			else{
				valid = 0;
				fprintf(stderr, "\e[1;31m[ERROR]\e[0m Number: \'%c\' is not in base: %i.\n", string[i], baseIn);
			}
		}else if(string[i] >= 'a' && string[i] <= 'z'){
			if(string[i]-0x57 < baseIn) counter += n*(string[i]-0x57);
			else{
				valid = 0;
				fprintf(stderr, "\e[1;31m[ERROR]\e[0m Letter: \'%c\' is not in base: %i.\n", string[i], baseIn);
			}
		}else {
			valid = 0;
			fprintf(stderr, "\e[1;31m[ERROR]\e[0m Invalid character \'%c\'.\n\e[1;36m[HINT]\e[0m Valid characters are: 0-9, A-Z, a-z.", string[i]);
		}
		n *= baseIn;
	} if(!valid) return "no output";
	for(short j = 0;; ++j){
		(char)r = counter % baseOut;
		if(r < 10){
			output[j] = r+0x30;
		}else{
			output[j] = r+0x57;
		}
		counter -= r;
		counter /= baseOut;
		if (counter == 0) {r = j; break;}
	}
	for(short x = 0, y = r; x != r; ++x, --y){
		temp = output[x];
		output[x] = output[y];
		output[y] = temp;
	}
	return output;
};

int main(int argc, char **argv, char **envp){
	char inputBase = 10;
	char outputBase = 16;
	if(argv[1] == '\0'){ 
		printf("No argument\n");
		return -1;
	}
	for(int i = 1; argv[i] != '\0'; ++i) {
		printf("%s\n", convert(argv[i], inputBase, outputBase));
	} return 0;
}
